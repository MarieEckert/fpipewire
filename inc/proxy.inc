    Type
    Ppw_protocol_marshal  = ^pw_protocol_marshal;
    Ppw_proxy  = ^pw_proxy;
    Ppw_proxy_events  = ^pw_proxy_events;
    Pspa_hook  = Pointer; {$WARNING ^spa_hook}
    Puint32_t  = ^uint32_t;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_PROXY_H}
{$define PIPEWIRE_PROXY_H}  
{ C++ extern C conditionnal removed }

  {* \page page_proxy Proxy
   *
   * \see \ref pw_proxy
   *
   * \section sec_page_proxy_overview Overview
   *
   * The proxy object is a client side representation of a resource
   * that lives on a remote PipeWire instance.
   *
   * It is used to communicate with the remote object.
   *
   * \section sec_page_proxy_core Core proxy
   *
   * A proxy for a remote core object can be obtained by making
   * a remote connection with \ref pw_context_connect.
   * See \ref pw_proxy
   *
   * Some methods on proxy object allow creation of more proxy objects or
   * create a binding between a local proxy and global resource.
   *
   * \section sec_page_proxy_create Create
   *
   * A client first creates a new proxy object with pw_proxy_new(). A
   * type must be provided for this object.
   *
   * The protocol of the context will usually install an interface to
   * translate method calls and events to the wire format.
   *
   * The creator of the proxy will usually also install an event
   * implementation of the particular object type.
   *
   * \section sec_page_proxy_bind Bind
   *
   * To actually use the proxy object, one needs to create a server
   * side resource for it. This can be done by, for example, binding
   * to a global object or by calling a method that creates and binds
   * to a new remote object. In all cases, the local id is passed to
   * the server and is used to create a resource with the same id.
   *
   * \section sec_page_proxy_methods Methods
   *
   * To call a method on the proxy use the interface methods. Calling
   * any interface method will result in a request to the server to
   * perform the requested action on the corresponding resource.
   *
   * \section sec_page_proxy_events Events
   *
   * Events send from the server to the proxy will be demarshalled by
   * the protocol and will then result in a call to the installed
   * implementation of the proxy.
   *
   * \section sec_page_proxy_destroy Destroy
   *
   * Use pw_proxy_destroy() to destroy the client side object. This
   * is usually done automatically when the server removes the resource
   * associated to the proxy.
    }
  {* \defgroup pw_proxy Proxy
   *
   * \brief Represents an object on the client side.
   *
   * A pw_proxy acts as a client side proxy to an object existing in a remote
   * pipewire instance. The proxy is responsible for converting interface functions
   * invoked by the client to PipeWire messages. Events will call the handlers
   * set in listener.
   *
   * \see \ref page_proxy
    }
  {*
   * \addtogroup pw_proxy
   * \
    }

  type
    Ppw_proxy = ^pw_proxy;
    pw_proxy = record
        {undefined structure}
      end;


  {* Proxy events, use \ref pw_proxy_add_listener  }
(* error 
#define PW_VERSION_PROXY_EVENTS		1
  {* The proxy is destroyed  }
  {* a proxy is bound to a global id  }
  {* a proxy is removed from the server. Use pw_proxy_destroy to
  	 * free the proxy.  }
  {* a reply to a sync method completed  }
  {* an error occurred on the proxy  }
 in member_list *)

  type
    Ppw_proxy_events = ^pw_proxy_events;
    pw_proxy_events = record
      end;

  { Make a new proxy object. The id can be used to bind to a remote object and
   * can be retrieved with \ref pw_proxy_get_id .  }
(* error 
struct pw_proxy *
  { interface type  }
  { interface version  }
  { size of user data  }in declaration at line 122 *)
    {* Add an event listener to proxy  }


    procedure pw_proxy_add_listener(proxy:Ppw_proxy; listener:Pspa_hook; events:Ppw_proxy_events; data:pointer);cdecl;external External_library name 'pw_proxy_add_listener';

    {* Add a listener for the events received from the remote object. The
      * events depend on the type of the remote object type.  }
    {*< the proxy  }
    {*< listener  }

    {*< proxied functions  }
    {*< data passed to events  }    procedure pw_proxy_add_object_listener(proxy:Ppw_proxy; listener:Pspa_hook; funcs:pointer; data:pointer);cdecl;external External_library name 'pw_proxy_add_object_listener';

    {* destroy a proxy  }
    procedure pw_proxy_destroy(proxy:Ppw_proxy);cdecl;external External_library name 'pw_proxy_destroy';

    procedure pw_proxy_ref(proxy:Ppw_proxy);cdecl;external External_library name 'pw_proxy_ref';

    procedure pw_proxy_unref(proxy:Ppw_proxy);cdecl;external External_library name 'pw_proxy_unref';

    {* Get the user_data. The size was given in \ref pw_proxy_new  }
    function pw_proxy_get_user_data(proxy:Ppw_proxy):pointer;cdecl;external External_library name 'pw_proxy_get_user_data';

    {* Get the local id of the proxy  }
    function pw_proxy_get_id(proxy:Ppw_proxy):uint32_t;cdecl;external External_library name 'pw_proxy_get_id';

    {* Get the type and version of the proxy  }

    function pw_proxy_get_type(proxy:Ppw_proxy; version:Puint32_t):pcchar;cdecl;external External_library name 'pw_proxy_get_type';

    {* Get the protocol used for the proxy  }
(* error 
struct pw_protocol *pw_proxy_get_protocol(struct pw_proxy *proxy);
in declaration at line 153 *)
    {* Generate an sync method for a proxy. This will generate a done event
     * with the same seq number of the reply.  }
    function pw_proxy_sync(proxy:Ppw_proxy; seq:cint):cint;cdecl;external External_library name 'pw_proxy_sync';

    {* Set the global id this proxy is bound to. This is usually used internally
     * and will also emit the bound event  }
    function pw_proxy_set_bound_id(proxy:Ppw_proxy; global_id:uint32_t):cint;cdecl;external External_library name 'pw_proxy_set_bound_id';

    {* Get the global id bound to this proxy of SPA_ID_INVALID when not bound
     * to a global  }
    function pw_proxy_get_bound_id(proxy:Ppw_proxy):uint32_t;cdecl;external External_library name 'pw_proxy_get_bound_id';

    {* Generate an error for a proxy  }

    function pw_proxy_error(proxy:Ppw_proxy; res:cint; error:pcchar):cint;cdecl;external External_library name 'pw_proxy_error';


(* error 
int pw_proxy_errorf(struct pw_proxy *proxy, int res, const char *error, ...) SPA_PRINTF_FUNC(3, 4);
(* error 
int pw_proxy_errorf(struct pw_proxy *proxy, int res, const char *error, ...) SPA_PRINTF_FUNC(3, 4);
 in declarator_list *)
 in declarator_list *)
    {* Get the listener of proxy  }
(* error 
struct spa_hook_list *pw_proxy_get_object_listeners(struct pw_proxy *proxy);
in declaration at line 171 *)
    {* Get the marshal functions for the proxy  }

    function pw_proxy_get_marshal(proxy:Ppw_proxy):Ppw_protocol_marshal;cdecl;external External_library name 'pw_proxy_get_marshal';

    {* Install a marshal function on a proxy  }
    function pw_proxy_install_marshal(proxy:Ppw_proxy; implementor:bool):cint;cdecl;external External_library name 'pw_proxy_install_marshal';

(* error 
#define pw_proxy_notify(p,type,event,version,...)			\
in define line 181 *)
(* error 
#define pw_proxy_call(p,type,method,version,...)			\
in define line 185 *)
(* error 
#define pw_proxy_call_res(p,type,method,version,...)			\
in declaration at line 189 *)
(* error 
	int _res = -ENOTSUP;						\
(* error 
	spa_interface_call_res((struct spa_interface*)p,		\
in declaration at line 191 *)
(* error 
			type, _res, method, version, ##__VA_ARGS__);	\
(* error 
	_res;								\
in declaration at line 192 *)
(* error 
	_res;								\
(* error 
})
    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_PROXY_H  }

