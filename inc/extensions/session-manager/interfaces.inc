    Type
    Ppw_endpoint  = ^pw_endpoint;
    Ppw_endpoint_events  = ^pw_endpoint_events;
    Ppw_endpoint_link  = ^pw_endpoint_link;
    Ppw_endpoint_link_events  = ^pw_endpoint_link_events;
    Ppw_endpoint_link_methods  = ^pw_endpoint_link_methods;
    Ppw_endpoint_methods  = ^pw_endpoint_methods;
    Ppw_endpoint_stream  = ^pw_endpoint_stream;
    Ppw_endpoint_stream_events  = ^pw_endpoint_stream_events;
    Ppw_endpoint_stream_methods  = ^pw_endpoint_stream_methods;
    Ppw_session  = ^pw_session;
    Ppw_session_events  = ^pw_session_events;
    Ppw_session_methods  = ^pw_session_methods;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2019 Collabora Ltd.  }
  {                         @author George Kiagiadakis <george.kiagiadakis@collabora.com>  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_EXT_SESSION_MANAGER_INTERFACES_H}
{$define PIPEWIRE_EXT_SESSION_MANAGER_INTERFACES_H}  



{ C++ extern C conditionnal removed }
  {*
   * \addtogroup pw_session_manager
   * \
    }
(* error 
#define PW_TYPE_INTERFACE_Session		PW_TYPE_INFO_INTERFACE_BASE "Session"
in define line 23 *)

    const
      PW_SESSION_PERM_MASK = PW_PERM_RWX;      
      PW_VERSION_SESSION = 0;      

    type
      Ppw_session = ^pw_session;
      pw_session = record
          {undefined structure}
        end;

(* error 
#define PW_TYPE_INTERFACE_Endpoint		PW_TYPE_INFO_INTERFACE_BASE "Endpoint"
in define line 28 *)

    const
      PW_ENDPOINT_PERM_MASK = PW_PERM_RWX;      
      PW_VERSION_ENDPOINT = 0;      

    type
      Ppw_endpoint = ^pw_endpoint;
      pw_endpoint = record
          {undefined structure}
        end;

(* error 
#define PW_TYPE_INTERFACE_EndpointStream	PW_TYPE_INFO_INTERFACE_BASE "EndpointStream"
in define line 33 *)

    const
      PW_ENDPOINT_STREAM_PERM_MASK = PW_PERM_RWX;      
      PW_VERSION_ENDPOINT_STREAM = 0;      

    type
      Ppw_endpoint_stream = ^pw_endpoint_stream;
      pw_endpoint_stream = record
          {undefined structure}
        end;

(* error 
#define PW_TYPE_INTERFACE_EndpointLink		PW_TYPE_INFO_INTERFACE_BASE "EndpointLink"
in define line 38 *)

    const
      PW_ENDPOINT_LINK_PERM_MASK = PW_PERM_RWX;      
      PW_VERSION_ENDPOINT_LINK = 0;      

    type
      Ppw_endpoint_link = ^pw_endpoint_link;
      pw_endpoint_link = record
          {undefined structure}
        end;

    { Session  }

    const
      PW_SESSION_EVENT_INFO = 0;      
      PW_SESSION_EVENT_PARAM = 1;      
      PW_SESSION_EVENT_NUM = 2;      
(* error 
#define PW_VERSION_SESSION_EVENTS		0
    {*< version of this structure  }
    {*
    	 * Notify session info
    	 *
    	 * \param info info about the session
    	  }
    {*
    	 * Notify a session param
    	 *
    	 * Event emitted as a result of the enum_params method.
    	 *
    	 * \param seq the sequence number of the request
    	 * \param id the param id
    	 * \param index the param index
    	 * \param next the param index of the next param
    	 * \param param the parameter
    	  }
 in member_list *)

    type
      Ppw_session_events = ^pw_session_events;
      pw_session_events = record
        end;


    const
      PW_SESSION_METHOD_ADD_LISTENER = 0;      
      PW_SESSION_METHOD_SUBSCRIBE_PARAMS = 1;      
      PW_SESSION_METHOD_ENUM_PARAMS = 2;      
      PW_SESSION_METHOD_SET_PARAM = 3;      
      PW_SESSION_METHOD_CREATE_LINK = 4;      
      PW_SESSION_METHOD_NUM = 5;      
(* error 
#define PW_VERSION_SESSION_METHODS	0
    {*< version of this structure  }
    {*
    	 * Subscribe to parameter changes
    	 *
    	 * Automatically emit param events for the given ids when
    	 * they are changed.
    	 *
    	 * \param ids an array of param ids
    	 * \param n_ids the number of ids in \a ids
    	 *
    	 * This requires X permissions.
    	  }
    {*
    	 * Enumerate session parameters
    	 *
    	 * Start enumeration of session parameters. For each param, a
    	 * param event will be emitted.
    	 *
    	 * \param seq a sequence number returned in the reply
    	 * \param id the parameter id to enumerate
    	 * \param start the start index or 0 for the first param
    	 * \param num the maximum number of params to retrieve
    	 * \param filter a param filter or NULL
    	 *
    	 * This requires X permissions.
    	  }
    {*
    	 * Set a parameter on the session
    	 *
    	 * \param id the parameter id to set
    	 * \param flags extra parameter flags
    	 * \param param the parameter to set
    	 *
    	 * This requires X and W permissions.
    	  }
 in member_list *)

    type
      Ppw_session_methods = ^pw_session_methods;
      pw_session_methods = record
        end;

(* error 
#define pw_session_method(o,method,version,...)				\
in declaration at line 138 *)
(* error 
	int _res = -ENOTSUP;						\
(* error 
	spa_interface_call_res((struct spa_interface*)o,		\
in declaration at line 141 *)
(* error 
			method, version, ##__VA_ARGS__);		\
(* error 
	_res;								\
in declaration at line 142 *)
(* error 
	_res;								\
(* error 
})
in define line 145 *)
(* error 
#define pw_session_subscribe_params(c,...)	pw_session_method(c,subscribe_params,0,__VA_ARGS__)
in define line 146 *)
(* error 
#define pw_session_enum_params(c,...)		pw_session_method(c,enum_params,0,__VA_ARGS__)
in define line 147 *)
(* error 
#define pw_session_set_param(c,...)		pw_session_method(c,set_param,0,__VA_ARGS__)
in define line 148 *)
    { Endpoint  }

    const
      PW_ENDPOINT_EVENT_INFO = 0;      
      PW_ENDPOINT_EVENT_PARAM = 1;      
      PW_ENDPOINT_EVENT_NUM = 2;      
(* error 
#define PW_VERSION_ENDPOINT_EVENTS	0
    {*< version of this structure  }
    {*
    	 * Notify endpoint info
    	 *
    	 * \param info info about the endpoint
    	  }
    {*
    	 * Notify a endpoint param
    	 *
    	 * Event emitted as a result of the enum_params method.
    	 *
    	 * \param seq the sequence number of the request
    	 * \param id the param id
    	 * \param index the param index
    	 * \param next the param index of the next param
    	 * \param param the parameter
    	  }
 in member_list *)

    type
      Ppw_endpoint_events = ^pw_endpoint_events;
      pw_endpoint_events = record
        end;


    const
      PW_ENDPOINT_METHOD_ADD_LISTENER = 0;      
      PW_ENDPOINT_METHOD_SUBSCRIBE_PARAMS = 1;      
      PW_ENDPOINT_METHOD_ENUM_PARAMS = 2;      
      PW_ENDPOINT_METHOD_SET_PARAM = 3;      
      PW_ENDPOINT_METHOD_CREATE_LINK = 4;      
      PW_ENDPOINT_METHOD_NUM = 5;      
(* error 
#define PW_VERSION_ENDPOINT_METHODS	0
    {*< version of this structure  }
    {*
    	 * Subscribe to parameter changes
    	 *
    	 * Automatically emit param events for the given ids when
    	 * they are changed.
    	 *
    	 * \param ids an array of param ids
    	 * \param n_ids the number of ids in \a ids
    	 *
    	 * This requires X permissions.
    	  }
    {*
    	 * Enumerate endpoint parameters
    	 *
    	 * Start enumeration of endpoint parameters. For each param, a
    	 * param event will be emitted.
    	 *
    	 * \param seq a sequence number returned in the reply
    	 * \param id the parameter id to enumerate
    	 * \param start the start index or 0 for the first param
    	 * \param num the maximum number of params to retrieve
    	 * \param filter a param filter or NULL
    	 *
    	 * This requires X permissions.
    	  }
    {*
    	 * Set a parameter on the endpoint
    	 *
    	 * \param id the parameter id to set
    	 * \param flags extra parameter flags
    	 * \param param the parameter to set
    	 *
    	 * This requires X and W permissions.
    	  }
    {*
    	 * Create a link
    	 *
    	 * This requires X permissions.
    	  }
 in member_list *)

    type
      Ppw_endpoint_methods = ^pw_endpoint_methods;
      pw_endpoint_methods = record
        end;

(* error 
#define pw_endpoint_method(o,method,version,...)			\
in declaration at line 253 *)
(* error 
	int _res = -ENOTSUP;						\
(* error 
	spa_interface_call_res((struct spa_interface*)o,		\
in declaration at line 256 *)
(* error 
			method, version, ##__VA_ARGS__);		\
(* error 
	_res;								\
in declaration at line 257 *)
(* error 
	_res;								\
(* error 
})
in define line 260 *)
(* error 
#define pw_endpoint_subscribe_params(c,...)	pw_endpoint_method(c,subscribe_params,0,__VA_ARGS__)
in define line 261 *)
(* error 
#define pw_endpoint_enum_params(c,...)		pw_endpoint_method(c,enum_params,0,__VA_ARGS__)
in define line 262 *)
(* error 
#define pw_endpoint_set_param(c,...)		pw_endpoint_method(c,set_param,0,__VA_ARGS__)
in define line 263 *)
(* error 
#define pw_endpoint_create_link(c,...)		pw_endpoint_method(c,create_link,0,__VA_ARGS__)
in define line 264 *)
    { Endpoint Stream  }

    const
      PW_ENDPOINT_STREAM_EVENT_INFO = 0;      
      PW_ENDPOINT_STREAM_EVENT_PARAM = 1;      
      PW_ENDPOINT_STREAM_EVENT_NUM = 2;      
(* error 
#define PW_VERSION_ENDPOINT_STREAM_EVENTS	0
    {*< version of this structure  }
    {*
    	 * Notify endpoint stream info
    	 *
    	 * \param info info about the endpoint stream
    	  }
    {*
    	 * Notify a endpoint stream param
    	 *
    	 * Event emitted as a result of the enum_params method.
    	 *
    	 * \param seq the sequence number of the request
    	 * \param id the param id
    	 * \param index the param index
    	 * \param next the param index of the next param
    	 * \param param the parameter
    	  }
 in member_list *)

    type
      Ppw_endpoint_stream_events = ^pw_endpoint_stream_events;
      pw_endpoint_stream_events = record
        end;


    const
      PW_ENDPOINT_STREAM_METHOD_ADD_LISTENER = 0;      
      PW_ENDPOINT_STREAM_METHOD_SUBSCRIBE_PARAMS = 1;      
      PW_ENDPOINT_STREAM_METHOD_ENUM_PARAMS = 2;      
      PW_ENDPOINT_STREAM_METHOD_SET_PARAM = 3;      
      PW_ENDPOINT_STREAM_METHOD_NUM = 4;      
(* error 
#define PW_VERSION_ENDPOINT_STREAM_METHODS	0
    {*< version of this structure  }
    {*
    	 * Subscribe to parameter changes
    	 *
    	 * Automatically emit param events for the given ids when
    	 * they are changed.
    	 *
    	 * \param ids an array of param ids
    	 * \param n_ids the number of ids in \a ids
    	 *
    	 * This requires X permissions.
    	  }
    {*
    	 * Enumerate stream parameters
    	 *
    	 * Start enumeration of stream parameters. For each param, a
    	 * param event will be emitted.
    	 *
    	 * \param seq a sequence number returned in the reply
    	 * \param id the parameter id to enumerate
    	 * \param start the start index or 0 for the first param
    	 * \param num the maximum number of params to retrieve
    	 * \param filter a param filter or NULL
    	 *
    	 * This requires X permissions.
    	  }
    {*
    	 * Set a parameter on the stream
    	 *
    	 * \param id the parameter id to set
    	 * \param flags extra parameter flags
    	 * \param param the parameter to set
    	 *
    	 * This requires X and W permissions.
    	  }
 in member_list *)

    type
      Ppw_endpoint_stream_methods = ^pw_endpoint_stream_methods;
      pw_endpoint_stream_methods = record
        end;

(* error 
#define pw_endpoint_stream_method(o,method,version,...)		\
in declaration at line 360 *)
(* error 
	int _res = -ENOTSUP;						\
(* error 
	spa_interface_call_res((struct spa_interface*)o,		\
in declaration at line 363 *)
(* error 
			method, version, ##__VA_ARGS__);		\
(* error 
	_res;								\
in declaration at line 364 *)
(* error 
	_res;								\
(* error 
})
in define line 367 *)
(* error 
#define pw_endpoint_stream_subscribe_params(c,...)	pw_endpoint_stream_method(c,subscribe_params,0,__VA_ARGS__)
in define line 368 *)
(* error 
#define pw_endpoint_stream_enum_params(c,...)		pw_endpoint_stream_method(c,enum_params,0,__VA_ARGS__)
in define line 369 *)
(* error 
#define pw_endpoint_stream_set_param(c,...)		pw_endpoint_stream_method(c,set_param,0,__VA_ARGS__)
in define line 370 *)
    { Endpoint Link  }

    const
      PW_ENDPOINT_LINK_EVENT_INFO = 0;      
      PW_ENDPOINT_LINK_EVENT_PARAM = 1;      
      PW_ENDPOINT_LINK_EVENT_NUM = 2;      
(* error 
#define PW_VERSION_ENDPOINT_LINK_EVENTS	0
    {*< version of this structure  }
    {*
    	 * Notify endpoint link info
    	 *
    	 * \param info info about the endpoint link
    	  }
    {*
    	 * Notify a endpoint link param
    	 *
    	 * Event emitted as a result of the enum_params method.
    	 *
    	 * \param seq the sequence number of the request
    	 * \param id the param id
    	 * \param index the param index
    	 * \param next the param index of the next param
    	 * \param param the parameter
    	  }
 in member_list *)

    type
      Ppw_endpoint_link_events = ^pw_endpoint_link_events;
      pw_endpoint_link_events = record
        end;


    const
      PW_ENDPOINT_LINK_METHOD_ADD_LISTENER = 0;      
      PW_ENDPOINT_LINK_METHOD_SUBSCRIBE_PARAMS = 1;      
      PW_ENDPOINT_LINK_METHOD_ENUM_PARAMS = 2;      
      PW_ENDPOINT_LINK_METHOD_SET_PARAM = 3;      
      PW_ENDPOINT_LINK_METHOD_REQUEST_STATE = 4;      
      PW_ENDPOINT_LINK_METHOD_DESTROY = 5;      
      PW_ENDPOINT_LINK_METHOD_NUM = 6;      
(* error 
#define PW_VERSION_ENDPOINT_LINK_METHODS	0
    {*< version of this structure  }
    {*
    	 * Subscribe to parameter changes
    	 *
    	 * Automatically emit param events for the given ids when
    	 * they are changed.
    	 *
    	 * \param ids an array of param ids
    	 * \param n_ids the number of ids in \a ids
    	 *
    	 * This requires X permissions.
    	  }
    {*
    	 * Enumerate link parameters
    	 *
    	 * Start enumeration of link parameters. For each param, a
    	 * param event will be emitted.
    	 *
    	 * \param seq a sequence number returned in the reply
    	 * \param id the parameter id to enumerate
    	 * \param start the start index or 0 for the first param
    	 * \param num the maximum number of params to retrieve
    	 * \param filter a param filter or NULL
    	 *
    	 * This requires X permissions.
    	  }
    {*
    	 * Set a parameter on the link
    	 *
    	 * \param id the parameter id to set
    	 * \param flags extra parameter flags
    	 * \param param the parameter to set
    	 *
    	 * This requires X and W permissions.
    	  }
    {*
    	 * Request a state on the link.
    	 *
    	 * This requires X and W permissions.
    	  }
 in member_list *)

    type
      Ppw_endpoint_link_methods = ^pw_endpoint_link_methods;
      pw_endpoint_link_methods = record
        end;

(* error 
#define pw_endpoint_link_method(o,method,version,...)			\
in declaration at line 475 *)
(* error 
	int _res = -ENOTSUP;						\
(* error 
	spa_interface_call_res((struct spa_interface*)o,		\
in declaration at line 478 *)
(* error 
			method, version, ##__VA_ARGS__);		\
(* error 
	_res;								\
in declaration at line 479 *)
(* error 
	_res;								\
(* error 
})
in define line 482 *)
(* error 
#define pw_endpoint_link_subscribe_params(c,...)	pw_endpoint_link_method(c,subscribe_params,0,__VA_ARGS__)
in define line 483 *)
(* error 
#define pw_endpoint_link_enum_params(c,...)		pw_endpoint_link_method(c,enum_params,0,__VA_ARGS__)
in define line 484 *)
(* error 
#define pw_endpoint_link_set_param(c,...)		pw_endpoint_link_method(c,set_param,0,__VA_ARGS__)
in define line 485 *)
(* error 
#define pw_endpoint_link_request_state(c,...)		pw_endpoint_link_method(c,request_state,0,__VA_ARGS__)
in define line 486 *)
    {*
     * \
      }
{$endif}
    { PIPEWIRE_EXT_SESSION_MANAGER_INTERFACES_H  }

