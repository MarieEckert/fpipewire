    Type
    Ppw_client  = ^pw_client;
    Ppw_client_events  = ^pw_client_events;
    Ppw_client_info  = ^pw_client_info;
    Ppw_client_methods  = ^pw_client_methods;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_CLIENT_H}
{$define PIPEWIRE_CLIENT_H}  
{ C++ extern C conditionnal removed }




  {* \defgroup pw_client Client
   * Client interface
    }
  {*
   * \addtogroup pw_client
   * \
    }
(* error 
#define PW_TYPE_INTERFACE_Client	PW_TYPE_INFO_INTERFACE_BASE "Client"
in define line 26 *)

    const
      PW_CLIENT_PERM_MASK = PW_PERM_RWXM;      
      PW_VERSION_CLIENT = 3;      

    type
      Ppw_client = ^pw_client;
      pw_client = record
          {undefined structure}
        end;

    { default ID of the current client after connect  }

    const
      PW_ID_CLIENT = 1;      
    {* The client information. Extra information can be added in later versions  }
    {*< id of the global  }
(* error 
#define PW_CLIENT_CHANGE_MASK_PROPS	(1 << 0)
    {*< bitfield of changed fields since last call  }
    {*< extra properties  }
 in member_list *)

    type
      Ppw_client_info = ^pw_client_info;
      pw_client_info = record
        end;

    {* Update an existing \ref pw_client_info with \a update with reset  }
(* error 
struct pw_client_info *
in declaration at line 48 *)
    {* Merge an existing \ref pw_client_info with \a update  }
(* error 
struct pw_client_info *
in declaration at line 52 *)
    {* Free a \ref pw_client_info  }

    procedure pw_client_info_free(info:Ppw_client_info);cdecl;external;

    const
      PW_CLIENT_EVENT_INFO = 0;      
      PW_CLIENT_EVENT_PERMISSIONS = 1;      
      PW_CLIENT_EVENT_NUM = 2;      
    {* Client events  }
(* error 
#define PW_VERSION_CLIENT_EVENTS	0
    {*
    	 * Notify client info
    	 *
    	 * \param info info about the client
    	  }
    {*
    	 * Notify a client permission
    	 *
    	 * Event emitted as a result of the get_permissions method.
    	 *
    	 * \param default_permissions the default permissions
    	 * \param index the index of the first permission entry
    	 * \param n_permissions the number of permissions
    	 * \param permissions the permissions
    	  }
 in member_list *)

    type
      Ppw_client_events = ^pw_client_events;
      pw_client_events = record
        end;


    const
      PW_CLIENT_METHOD_ADD_LISTENER = 0;      
      PW_CLIENT_METHOD_ERROR = 1;      
      PW_CLIENT_METHOD_UPDATE_PROPERTIES = 2;      
      PW_CLIENT_METHOD_GET_PERMISSIONS = 3;      
      PW_CLIENT_METHOD_UPDATE_PERMISSIONS = 4;      
      PW_CLIENT_METHOD_NUM = 5;      
    {* Client methods  }
(* error 
#define PW_VERSION_CLIENT_METHODS	0
    {*
    	 * Send an error to a client
    	 *
    	 * \param id the global id to report the error on
    	 * \param res an errno style error code
    	 * \param message an error string
    	 *
    	 * This requires W and X permissions on the client.
    	  }
    {*
    	 * Update client properties
    	 *
    	 * \param props new properties
    	 *
    	 * This requires W and X permissions on the client.
    	  }
    {*
    	 * Get client permissions
    	 *
    	 * A permissions event will be emitted with the permissions.
    	 *
    	 * \param index the first index to query, 0 for first
    	 * \param num the maximum number of items to get
    	 *
    	 * This requires W and X permissions on the client.
    	  }
    {*
    	 * Manage the permissions of the global objects for this
    	 * client
    	 *
    	 * Update the permissions of the global objects using the
    	 * provided array with permissions
    	 *
    	 * Globals can use the default permissions or can have specific
    	 * permissions assigned to them.
    	 *
    	 * \param n_permissions number of permissions
    	 * \param permissions array of permissions
    	 *
    	 * This requires W and X permissions on the client.
    	  }
 in member_list *)

    type
      Ppw_client_methods = ^pw_client_methods;
      pw_client_methods = record
        end;

(* error 
#define pw_client_method(o,method,version,...)				\
in declaration at line 155 *)
(* error 
	int _res = -ENOTSUP;						\
(* error 
	spa_interface_call_res((struct spa_interface*)o,		\
in declaration at line 158 *)
(* error 
			method, version, ##__VA_ARGS__);		\
(* error 
	_res;								\
in declaration at line 159 *)
(* error 
	_res;								\
(* error 
})
in define line 162 *)
(* error 
#define pw_client_error(c,...)			pw_client_method(c,error,0,__VA_ARGS__)
in define line 163 *)
(* error 
#define pw_client_update_properties(c,...)	pw_client_method(c,update_properties,0,__VA_ARGS__)
in define line 164 *)
(* error 
#define pw_client_get_permissions(c,...)	pw_client_method(c,get_permissions,0,__VA_ARGS__)
in define line 165 *)
(* error 
#define pw_client_update_permissions(c,...)	pw_client_method(c,update_permissions,0,__VA_ARGS__)
in define line 166 *)
    {*
     * \
      }
{$endif}
    { PIPEWIRE_CLIENT_H  }

