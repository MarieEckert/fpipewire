{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_GLOBAL_H}
{$define PIPEWIRE_GLOBAL_H}  
{ C++ extern C conditionnal removed }
  {* \defgroup pw_global Global
   *
   * \brief A global object visible to remote clients
   *
   * A global object is visible to remote clients and represents a resource
   * that can be used or inspected.
   *
   * Global objects represent resources that are available on the PipeWire
   * context and are accessible to remote clients.
   * Globals come and go when devices or other resources become available for
   * clients.
   *
   * Remote clients receives a list of globals when it binds to the registry
   * object. See \ref pw_registry.
   *
   * A client can bind to a global to send methods or receive events from
   * the global.
   *
   * See \ref page_proxy
    }
  {*
   * \addtogroup pw_global
   * \
    }

  type
 	TCB_pw_global_for_each_resource = function (data:pointer; resource:Ppw_resource):cint;

  {*< global object, see \ref pw_global_new  }
  {*< client that binds  }
  {*< permissions for the bind  }
  {*< client interface version  }
  {*< client proxy id  }

    pw_global_bind_func_t = function (_object:pointer; client:Ppw_impl_client; permissions:uint32_t; version:uint32_t; id:uint32_t):cint;cdecl;
  {* Global events, use \ref pw_global_add_listener  }
(* error 
#define PW_VERSION_GLOBAL_EVENTS 0
  {* The global is destroyed  }
  {* The global is freed  }
  {* The permissions changed for a client  }
 in member_list *)
    Ppw_global_events = ^pw_global_events;
    pw_global_events = record
      end;

  {* Create a new global object  }
(* error 
struct pw_global *
  {*< the context  }
  {*< the interface type of the global  }
  {*< the interface version of the global  }
  {*< mask of valid permissions  }
  {*< extra properties  }
  {*< function to bind  }
  {*< global object  }in declaration at line 71 *)
    {* Register a global object to the context registry  }

    function pw_global_register(global:Ppw_global):cint;cdecl;external External_library name 'pw_global_register';

    {* Add an event listener on the global  }

    procedure pw_global_add_listener(global:Ppw_global; listener:Pspa_hook; events:Ppw_global_events; data:pointer);cdecl;external External_library name 'pw_global_add_listener';

    {* Get the permissions of the global for a given client  }
    function pw_global_get_permissions(global:Ppw_global; client:Ppw_impl_client):uint32_t;cdecl;external External_library name 'pw_global_get_permissions';

    {* Get the context object of this global  }
(* error 
struct pw_context *pw_global_get_context(struct pw_global *global);
in declaration at line 86 *)
    {* Get the global type  }

    function pw_global_get_type(global:Ppw_global):pcchar;cdecl;external External_library name 'pw_global_get_type';

    {* Check a global type  }

    function pw_global_is_type(global:Ppw_global; _type:pcchar):bool;cdecl;external External_library name 'pw_global_is_type';

    {* Get the global version  }
    function pw_global_get_version(global:Ppw_global):uint32_t;cdecl;external External_library name 'pw_global_get_version';

    {* Get the global properties  }

    function pw_global_get_properties(global:Ppw_global):Ppw_properties;cdecl;external External_library name 'pw_global_get_properties';

    {* Update the global properties, must be done when unregistered  }


(* Const before declarator ignored *)
    function pw_global_update_keys(global:Ppw_global; dict:Pspa_dict; keys:Ppcchar):cint;cdecl;external External_library name 'pw_global_update_keys';

    {* Get the object associated with the global. This depends on the type of the
      * global  }
    function pw_global_get_object(global:Ppw_global):pointer;cdecl;external External_library name 'pw_global_get_object';

    {* Get the unique id of the global  }
    function pw_global_get_id(global:Ppw_global):uint32_t;cdecl;external External_library name 'pw_global_get_id';

    {* Get the serial number of the global  }
    function pw_global_get_serial(global:Ppw_global):uint64_t;cdecl;external External_library name 'pw_global_get_serial';

    {* Add a resource to a global  }
    function pw_global_add_resource(global:Ppw_global; resource:Ppw_resource):cint;cdecl;external External_library name 'pw_global_add_resource';

    {* Iterate all resources added to the global The callback should return
     * 0 to fetch the next item, any other value stops the iteration and returns
     * the value. When all callbacks return 0, this function returns 0 when all
     * items are iterated.  }
    function pw_global_for_each_resource(global:Ppw_global; callback: TCB_pw_global_for_each_resource; data:pointer):cint;cdecl;external External_library name 'pw_global_for_each_resource';

    {* Let a client bind to a global  }
    function pw_global_bind(global:Ppw_global; client:Ppw_impl_client; permissions:uint32_t; version:uint32_t; id:uint32_t):cint;cdecl;external External_library name 'pw_global_bind';

    function pw_global_update_permissions(global:Ppw_global; client:Ppw_impl_client; old_permissions:uint32_t; new_permissions:uint32_t):cint;cdecl;external External_library name 'pw_global_update_permissions';

    {* Destroy a global  }
    procedure pw_global_destroy(global:Ppw_global);cdecl;external External_library name 'pw_global_destroy';

    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_GLOBAL_H  }

