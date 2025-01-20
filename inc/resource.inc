
    { Pointers to basic pascal types, inserted by h2pas conversion program.}
    Type
      PLongint  = ^Longint;
      PSmallInt = ^SmallInt;
      PByte     = ^Byte;
      PWord     = ^Word;
      PDWord    = ^DWord;
      PDouble   = ^Double;

    Type
    Ppw_protocol_marshal  = ^pw_protocol_marshal;
    Ppw_resource  = ^pw_resource;
    Ppw_resource_events  = ^pw_resource_events;
    Pspa_hook  = ^spa_hook;
    Puint32_t  = ^uint32_t;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_RESOURCE_H}
{$define PIPEWIRE_RESOURCE_H}  
{ C++ extern C conditionnal removed }

  {* \defgroup pw_resource Resource
   *
   * \brief Client owned objects
   *
   * Resources represent objects owned by a \ref pw_impl_client. They are
   * the result of binding to a global resource or by calling API that
   * creates client owned objects.
   *
   * The client usually has a proxy object associated with the resource
   * that it can use to communicate with the resource. See \ref page_proxy.
   *
   * Resources are destroyed when the client or the bound object is
   * destroyed.
   *
    }
  {*
   * \addtogroup pw_resource
   * \
    }

  type
    Ppw_resource = ^pw_resource;
    pw_resource = record
        {undefined structure}
      end;


  {* Resource events  }
(* error 
#define PW_VERSION_RESOURCE_EVENTS	0
  {* The resource is destroyed  }
  {* a reply to a ping event completed  }
  {* an error occurred on the resource  }
 in member_list *)

  type
    Ppw_resource_events = ^pw_resource_events;
    pw_resource_events = record
      end;

  {* Make a new resource for client  }
(* error 
struct pw_resource *
  {*< the client owning the resource  }
  {*< the remote per client id  }
  {*< permissions on this resource  }
  {*< interface of the resource  }
  {*< requested interface version  }
  {*< extra user data size  }in declaration at line 61 *)
    {* Destroy a resource  }

    procedure pw_resource_destroy(resource:Ppw_resource);cdecl;external;

    {* Remove a resource, like pw_resource_destroy but without sending a
     * remove_id message to the client  }
    procedure pw_resource_remove(resource:Ppw_resource);cdecl;external;

    {* Get the client owning this resource  }
(* error 
struct pw_impl_client *pw_resource_get_client(struct pw_resource *resource);
in declaration at line 71 *)
    {* Get the unique id of this resource  }
    function pw_resource_get_id(resource:Ppw_resource):uint32_t;cdecl;external;

    {* Get the permissions of this resource  }
    function pw_resource_get_permissions(resource:Ppw_resource):uint32_t;cdecl;external;

    {* Get the type and optionally the version of this resource  }
(* Const before type ignored *)
    function pw_resource_get_type(resource:Ppw_resource; version:Puint32_t):pcchar;cdecl;external;

    {* Get the protocol used for this resource  }
(* error 
struct pw_protocol *pw_resource_get_protocol(struct pw_resource *resource);
in declaration at line 83 *)
    {* Get the user data for the resource, the size was given in \ref pw_resource_new  }
    function pw_resource_get_user_data(resource:Ppw_resource):pointer;cdecl;external;

    {* Add an event listener  }
(* Const before type ignored *)
    procedure pw_resource_add_listener(resource:Ppw_resource; listener:Pspa_hook; events:Ppw_resource_events; data:pointer);cdecl;external;

    {* Set the resource implementation.  }
(* Const before type ignored *)
    procedure pw_resource_add_object_listener(resource:Ppw_resource; listener:Pspa_hook; funcs:pointer; data:pointer);cdecl;external;

    {* Generate an ping event for a resource. This will generate a pong event
     * with the same \a sequence number in the return value.  }
    function pw_resource_ping(resource:Ppw_resource; seq:cint):cint;cdecl;external;

    {* ref/unref a resource, Since 0.3.52  }
    procedure pw_resource_ref(resource:Ppw_resource);cdecl;external;

    procedure pw_resource_unref(resource:Ppw_resource);cdecl;external;

    {* Notify global id this resource is bound to  }
    function pw_resource_set_bound_id(resource:Ppw_resource; global_id:uint32_t):cint;cdecl;external;

    {* Get the global id this resource is bound to or SPA_ID_INVALID when not bound  }
    function pw_resource_get_bound_id(resource:Ppw_resource):uint32_t;cdecl;external;

    {* Generate an error for a resource  }
(* Const before type ignored *)
    procedure pw_resource_error(resource:Ppw_resource; res:cint; error:pcchar);cdecl;external;

(* Const before type ignored *)
(* error 
void pw_resource_errorf(struct pw_resource *resource, int res, const char *error, ...) SPA_PRINTF_FUNC(3, 4);
(* error 
void pw_resource_errorf(struct pw_resource *resource, int res, const char *error, ...) SPA_PRINTF_FUNC(3, 4);
 in declarator_list *)
 in declarator_list *)
(* Const before type ignored *)
(* error 
void pw_resource_errorf_id(struct pw_resource *resource, uint32_t id, int res, const char *error, ...) SPA_PRINTF_FUNC(4, 5);
(* error 
void pw_resource_errorf_id(struct pw_resource *resource, uint32_t id, int res, const char *error, ...) SPA_PRINTF_FUNC(4, 5);
 in declarator_list *)
 in declarator_list *)
    {* Get the list of object listeners from a resource  }
(* error 
struct spa_hook_list *pw_resource_get_object_listeners(struct pw_resource *resource);
in declaration at line 120 *)
    {* Get the marshal functions for the resource  }
(* Const before type ignored *)
    function pw_resource_get_marshal(resource:Ppw_resource):Ppw_protocol_marshal;cdecl;external;

    {* install a marshal function on a resource  }
    function pw_resource_install_marshal(resource:Ppw_resource; implementor:bool):cint;cdecl;external;

(* error 
#define pw_resource_notify(r,type,event,version,...)			\
in define line 130 *)
(* error 
#define pw_resource_call(r,type,method,version,...)			\
in define line 134 *)
(* error 
#define pw_resource_call_res(r,type,method,version,...)			\
in declaration at line 138 *)
(* error 
	int _res = -ENOTSUP;						\
(* error 
	spa_interface_call_res((struct spa_interface*)r,		\
in declaration at line 140 *)
(* error 
			type, _res, method, version, ##__VA_ARGS__);	\
(* error 
	_res;								\
in declaration at line 141 *)
(* error 
	_res;								\
(* error 
})
    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_RESOURCE_H  }

