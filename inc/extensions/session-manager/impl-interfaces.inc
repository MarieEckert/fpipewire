    Type
    Ppw_client_endpoint  = ^pw_client_endpoint;
    Ppw_client_endpoint_events  = ^pw_client_endpoint_events;
    Ppw_client_endpoint_methods  = ^pw_client_endpoint_methods;
    Ppw_client_session  = ^pw_client_session;
    Ppw_client_session_events  = ^pw_client_session_events;
    Ppw_client_session_methods  = ^pw_client_session_methods;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2019 Collabora Ltd.  }
  {                         @author George Kiagiadakis <george.kiagiadakis@collabora.com>  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_EXT_SESSION_MANAGER_IMPL_INTERFACES_H}
{$define PIPEWIRE_EXT_SESSION_MANAGER_IMPL_INTERFACES_H}  




{ C++ extern C conditionnal removed }
  {*
   * \addtogroup pw_session_manager
   * \
    }
(* error 
#define PW_TYPE_INTERFACE_ClientEndpoint	PW_TYPE_INFO_INTERFACE_BASE "ClientEndpoint"
in define line 24 *)

    const
      PW_VERSION_CLIENT_ENDPOINT = 0;      

    type
      Ppw_client_endpoint = ^pw_client_endpoint;
      pw_client_endpoint = record
          {undefined structure}
        end;


    const
      PW_CLIENT_ENDPOINT_EVENT_SET_SESSION_ID = 0;      
      PW_CLIENT_ENDPOINT_EVENT_SET_PARAM = 1;      
      PW_CLIENT_ENDPOINT_EVENT_STREAM_SET_PARAM = 2;      
      PW_CLIENT_ENDPOINT_EVENT_CREATE_LINK = 3;      
      PW_CLIENT_ENDPOINT_EVENT_NUM = 4;      
(* error 
#define PW_VERSION_CLIENT_ENDPOINT_EVENTS		0
    {*< version of this structure  }
    {*
    	 * Sets the session id of the \a endpoint.
    	 *
    	 * On endpoints that are not session masters, this method notifies
    	 * the implementation that it has been associated with a session.
    	 * The implementation is obliged to set this id in the
    	 * #struct pw_endpoint_info \a session_id field.
    	 *
    	 * \param endpoint a #pw_endpoint
    	 * \param id the session id associated with this endpoint
    	 *
    	 * \return 0 on success
    	 *         -EINVAL when the session id has already been set
    	 *         -ENOTSUP when the endpoint is a session master
    	  }
    {*
    	 * Set the configurable parameter in \a endpoint.
    	 *
    	 * Usually, \a param will be obtained from enum_params and then
    	 * modified but it is also possible to set another spa_pod
    	 * as long as its keys and types match a supported object.
    	 *
    	 * Objects with property keys that are not known are ignored.
    	 *
    	 * This function must be called from the main thread.
    	 *
    	 * \param endpoint a #struct pw_endpoint
    	 * \param id the parameter id to configure
    	 * \param flags additional flags
    	 * \param param the parameter to configure
    	 *
    	 * \return 0 on success
    	 *         -EINVAL when \a endpoint is NULL
    	 *         -ENOTSUP when there are no parameters implemented on \a endpoint
    	 *         -ENOENT the parameter is unknown
    	  }
    {*
    	 * Set a parameter on \a stream_id of \a endpoint.
    	 *
    	 * When \a param is NULL, the parameter will be unset.
    	 *
    	 * This function must be called from the main thread.
    	 *
    	 * \param endpoint a #struct pw_endpoint
    	 * \param stream_id the stream to configure
    	 * \param id the parameter id to set
    	 * \param flags optional flags
    	 * \param param a #struct spa_pod with the parameter to set
    	 * \return 0 on success
    	 *         1 on success, the value of \a param might have been
    	 *                changed depending on \a flags and the final value can
    	 *                be found by doing stream_enum_params.
    	 *         -EINVAL when \a endpoint is NULL or invalid arguments are given
    	 *         -ESRCH when the type or size of a property is not correct.
    	 *         -ENOENT when the param id is not found
    	  }
 in member_list *)

    type
      Ppw_client_endpoint_events = ^pw_client_endpoint_events;
      pw_client_endpoint_events = record
        end;


    const
      PW_CLIENT_ENDPOINT_METHOD_ADD_LISTENER = 0;      
      PW_CLIENT_ENDPOINT_METHOD_UPDATE = 1;      
      PW_CLIENT_ENDPOINT_METHOD_STREAM_UPDATE = 2;      
      PW_CLIENT_ENDPOINT_METHOD_NUM = 3;      
(* error 
#define PW_VERSION_CLIENT_ENDPOINT_METHODS	0
    {*< version of this structure  }
    {* Update endpoint information  }
    {* Update stream information  }
 in member_list *)

    type
      Ppw_client_endpoint_methods = ^pw_client_endpoint_methods;
      pw_client_endpoint_methods = record
        end;

(* error 
#define pw_client_endpoint_method(o,method,version,...)		\
in declaration at line 145 *)
(* error 
	int _res = -ENOTSUP;						\
(* error 
	spa_interface_call_res((struct spa_interface*)o,		\
in declaration at line 148 *)
(* error 
			method, version, ##__VA_ARGS__);		\
(* error 
	_res;								\
in declaration at line 149 *)
(* error 
	_res;								\
(* error 
})
in define line 152 *)
(* error 
#define pw_client_endpoint_update(o,...)	pw_client_endpoint_method(o,update,0,__VA_ARGS__)
in define line 153 *)
(* error 
#define pw_client_endpoint_stream_update(o,...)	pw_client_endpoint_method(o,stream_update,0,__VA_ARGS__)
in define line 154 *)
(* error 
#define PW_TYPE_INTERFACE_ClientSession		PW_TYPE_INFO_INTERFACE_BASE "ClientSession"
in define line 156 *)

    const
      PW_VERSION_CLIENT_SESSION = 0;      

    type
      Ppw_client_session = ^pw_client_session;
      pw_client_session = record
          {undefined structure}
        end;


    const
      PW_CLIENT_SESSION_EVENT_SET_PARAM = 0;      
      PW_CLIENT_SESSION_EVENT_LINK_SET_PARAM = 1;      
      PW_CLIENT_SESSION_EVENT_LINK_REQUEST_STATE = 2;      
      PW_CLIENT_SESSION_EVENT_NUM = 3;      
(* error 
#define PW_VERSION_CLIENT_SESSION_EVENTS		0
    {*< version of this structure  }
    {*
    	 * Set the configurable parameter in \a session.
    	 *
    	 * Usually, \a param will be obtained from enum_params and then
    	 * modified but it is also possible to set another spa_pod
    	 * as long as its keys and types match a supported object.
    	 *
    	 * Objects with property keys that are not known are ignored.
    	 *
    	 * This function must be called from the main thread.
    	 *
    	 * \param session a #struct pw_session
    	 * \param id the parameter id to configure
    	 * \param flags additional flags
    	 * \param param the parameter to configure
    	 *
    	 * \return 0 on success
    	 *         -EINVAL when \a session is NULL
    	 *         -ENOTSUP when there are no parameters implemented on \a session
    	 *         -ENOENT the parameter is unknown
    	  }
    {*
    	 * Set a parameter on \a link_id of \a session.
    	 *
    	 * When \a param is NULL, the parameter will be unset.
    	 *
    	 * This function must be called from the main thread.
    	 *
    	 * \param session a #struct pw_session
    	 * \param link_id the link to configure
    	 * \param id the parameter id to set
    	 * \param flags optional flags
    	 * \param param a #struct spa_pod with the parameter to set
    	 * \return 0 on success
    	 *         1 on success, the value of \a param might have been
    	 *                changed depending on \a flags and the final value can
    	 *                be found by doing link_enum_params.
    	 *         -EINVAL when \a session is NULL or invalid arguments are given
    	 *         -ESRCH when the type or size of a property is not correct.
    	 *         -ENOENT when the param id is not found
    	  }
 in member_list *)

    type
      Ppw_client_session_events = ^pw_client_session_events;
      pw_client_session_events = record
        end;


    const
      PW_CLIENT_SESSION_METHOD_ADD_LISTENER = 0;      
      PW_CLIENT_SESSION_METHOD_UPDATE = 1;      
      PW_CLIENT_SESSION_METHOD_LINK_UPDATE = 2;      
      PW_CLIENT_SESSION_METHOD_NUM = 3;      
(* error 
#define PW_VERSION_CLIENT_SESSION_METHODS		0
    {*< version of this structure  }
    {* Update session information  }
    {* Update link information  }
 in member_list *)

    type
      Ppw_client_session_methods = ^pw_client_session_methods;
      pw_client_session_methods = record
        end;

(* error 
#define pw_client_session_method(o,method,version,...)			\
in declaration at line 259 *)
(* error 
	int _res = -ENOTSUP;						\
(* error 
	spa_interface_call_res((struct spa_interface*)o,		\
in declaration at line 262 *)
(* error 
			method, version, ##__VA_ARGS__);		\
(* error 
	_res;								\
in declaration at line 263 *)
(* error 
	_res;								\
(* error 
})
in define line 266 *)
(* error 
#define pw_client_session_update(o,...)		pw_client_session_method(o,update,0,__VA_ARGS__)
in define line 267 *)
(* error 
#define pw_client_session_link_update(o,...)	pw_client_session_method(o,link_update,0,__VA_ARGS__)
in define line 268 *)
    {*
     * \
      }
{$endif}
    { PIPEWIRE_EXT_SESSION_MANAGER_IMPL_INTERFACES_H  }

