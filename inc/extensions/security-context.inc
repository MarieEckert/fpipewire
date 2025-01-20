    Type
    Ppw_security_context  = ^pw_security_context;
    Ppw_security_context_events  = ^pw_security_context_events;
    Ppw_security_context_methods  = ^pw_security_context_methods;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2019 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_EXT_SECURITY_CONTEXT_H}
{$define PIPEWIRE_EXT_SECURITY_CONTEXT_H}  
{ C++ extern C conditionnal removed }

  {* \defgroup pw_security_context Security Context
   * Security Context interface
    }
  {*
   * \addtogroup pw_security_context
   * \
    }
(* error 
#define PW_TYPE_INTERFACE_SecurityContext		PW_TYPE_INFO_INTERFACE_BASE "SecurityContext"
in define line 22 *)

    const
      PW_SECURITY_CONTEXT_PERM_MASK = PW_PERM_RWX;      
      PW_VERSION_SECURITY_CONTEXT = 3;      

    type
      Ppw_security_context = ^pw_security_context;
      pw_security_context = record
          {undefined structure}
        end;

(* error 
#define PW_EXTENSION_MODULE_SECURITY_CONTEXT		PIPEWIRE_MODULE_PREFIX "module-security-context"
in define line 29 *)

    const
      PW_SECURITY_CONTEXT_EVENT_NUM = 0;      
    {* \ref pw_security_context events  }
(* error 
#define PW_VERSION_SECURITY_CONTEXT_EVENTS		0
 in member_list *)

    type
      Ppw_security_context_events = ^pw_security_context_events;
      pw_security_context_events = record
        end;


    const
      PW_SECURITY_CONTEXT_METHOD_ADD_LISTENER = 0;      
      PW_SECURITY_CONTEXT_METHOD_CREATE = 1;      
      PW_SECURITY_CONTEXT_METHOD_NUM = 2;      
    {* \ref pw_security_context methods  }
(* error 
#define PW_VERSION_SECURITY_CONTEXT_METHODS		0
    {*
    	 * Create a new security context
    	 *
    	 * Creates a new security context with a socket listening FD.
    	 * PipeWire will accept new client connections on listen_fd.
    	 *
    	 * listen_fd must be ready to accept new connections when this request is
    	 * sent by the client. In other words, the client must call bind(2) and
    	 * listen(2) before sending the FD.
    	 *
    	 * close_fd is a FD closed by the client when PipeWire should stop
    	 * accepting new connections on listen_fd.
    	 *
    	 * PipeWire must continue to accept connections on listen_fd when
    	 * the client which created the security context disconnects.
    	 *
    	 * After sending this request, closing listen_fd and close_fd remains the
    	 * only valid operation on them.
    	 *
    	 * \param listen_fd the fd to listen on for new connections
    	 * \param close_fd the fd used to stop listening
    	 * \param props extra properties. These will be copied on the client
    	 *     that connects through this context.
    	 *
    	 * Some properties to set:
    	 *
    	 *  - pipewire.sec.engine with the engine name.
    	 *  - pipewire.sec.app-id with the application id, this is an opaque,
    	 *      engine specific id for an application
    	 *  - pipewire.sec.instance-id with the instance id, this is an opaque,
    	 *      engine specific id for a running instance of an application.
    	 *
    	 * See https://gitlab.freedesktop.org/wayland/wayland-protocols/-/blob/main/staging/security-context/engines.md
    	 * For a list of engine names and the properties to set.
    	 *
    	 * This requires X and W permissions on the security_context.
    	  }
 in member_list *)

    type
      Ppw_security_context_methods = ^pw_security_context_methods;
      pw_security_context_methods = record
        end;

(* error 
#define pw_security_context_method(o,method,version,...)		\
in declaration at line 100 *)
(* error 
	int _res = -ENOTSUP;						\
(* error 
	spa_interface_call_res((struct spa_interface*)o,		\
in declaration at line 103 *)
(* error 
			method, version, ##__VA_ARGS__);		\
(* error 
	_res;								\
in declaration at line 104 *)
(* error 
	_res;								\
(* error 
})
in define line 107 *)
(* error 
#define pw_security_context_create(c,...)	pw_security_context_method(c,create,0,__VA_ARGS__)
in define line 108 *)
    {*
     * \
      }
{$endif}
    { PIPEWIRE_EXT_SECURITY_CONTEXT_H  }

