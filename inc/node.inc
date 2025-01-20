    Type
    Ppw_node  = ^pw_node;
    Ppw_node_events  = ^pw_node_events;
    Ppw_node_info  = ^pw_node_info;
    Ppw_node_methods  = ^pw_node_methods;
    Ppw_node_state  = ^pw_node_state;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_NODE_H}
{$define PIPEWIRE_NODE_H}  
{ C++ extern C conditionnal removed }







  {* \defgroup pw_node Node
   * Node interface
    }
  {*
   * \addtogroup pw_node
   * \
    }
(* error 
#define PW_TYPE_INTERFACE_Node	PW_TYPE_INFO_INTERFACE_BASE "Node"
in define line 30 *)

    const
      PW_NODE_PERM_MASK = PW_PERM_RWXML;      
      PW_VERSION_NODE = 3;      

    type
      Ppw_node = ^pw_node;
      pw_node = record
          {undefined structure}
        end;

    {* \enum pw_node_state The different node states  }
    {*< error state  }
    {*< the node is being created  }
    {*< the node is suspended, the device might
    					 *   be closed  }
    {*< the node is running but there is no active
    					 *   port  }
    {*< the node is running  }
      pw_node_state = (PW_NODE_STATE_ERROR := -(1),PW_NODE_STATE_CREATING := 0,
        PW_NODE_STATE_SUSPENDED := 1,PW_NODE_STATE_IDLE := 2,
        PW_NODE_STATE_RUNNING := 3);

    {* Convert a \ref pw_node_state to a readable string  }


    function pw_node_state_as_string(state:pw_node_state):pcchar;cdecl;external;

    {* The node information. Extra information can be added in later versions  }
    {*< id of the global  }
    {*< maximum number of inputs  }
    {*< maximum number of outputs  }
(* error 
#define PW_NODE_CHANGE_MASK_INPUT_PORTS		(1 << 0)
    {*< bitfield of changed fields since last call  }
    {*< number of inputs  }
    {*< number of outputs  }
    {*< the current state of the node  }
    {*< an error reason if \a state is error  }
    {*< the properties of the node  }
    {*< parameters  }
    {*< number of items in \a params  }
 in member_list *)

    type
      Ppw_node_info = ^pw_node_info;
      pw_node_info = record
        end;

(* error 
struct pw_node_info *
in declaration at line 74 *)
(* error 
struct pw_node_info *
in declaration at line 78 *)

    procedure pw_node_info_free(info:Ppw_node_info);cdecl;external;

    const
      PW_NODE_EVENT_INFO = 0;      
      PW_NODE_EVENT_PARAM = 1;      
      PW_NODE_EVENT_NUM = 2;      
    {* Node events  }
(* error 
#define PW_VERSION_NODE_EVENTS	0
    {*
    	 * Notify node info
    	 *
    	 * \param info info about the node
    	  }
    {*
    	 * Notify a node param
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
      Ppw_node_events = ^pw_node_events;
      pw_node_events = record
        end;


    const
      PW_NODE_METHOD_ADD_LISTENER = 0;      
      PW_NODE_METHOD_SUBSCRIBE_PARAMS = 1;      
      PW_NODE_METHOD_ENUM_PARAMS = 2;      
      PW_NODE_METHOD_SET_PARAM = 3;      
      PW_NODE_METHOD_SEND_COMMAND = 4;      
      PW_NODE_METHOD_NUM = 5;      
    {* Node methods  }
(* error 
#define PW_VERSION_NODE_METHODS		0
    {*
    	 * Subscribe to parameter changes
    	 *
    	 * Automatically emit param events for the given ids when
    	 * they are changed.
    	 *
    	 * \param ids an array of param ids
    	 * \param n_ids the number of ids in \a ids
    	 *
    	 * This requires X permissions on the node.
    	  }
    {*
    	 * Enumerate node parameters
    	 *
    	 * Start enumeration of node parameters. For each param, a
    	 * param event will be emitted.
    	 *
    	 * \param seq a sequence number to place in the reply
    	 * \param id the parameter id to enum or PW_ID_ANY for all
    	 * \param start the start index or 0 for the first param
    	 * \param num the maximum number of params to retrieve
    	 * \param filter a param filter or NULL
    	 *
    	 * This requires X permissions on the node.
    	  }
    {*
    	 * Set a parameter on the node
    	 *
    	 * \param id the parameter id to set
    	 * \param flags extra parameter flags
    	 * \param param the parameter to set
    	 *
    	 * This requires X and W permissions on the node.
    	  }
    {*
    	 * Send a command to the node
    	 *
    	 * \param command the command to send
    	 *
    	 * This requires X and W permissions on the node.
    	  }
 in member_list *)

    type
      Ppw_node_methods = ^pw_node_methods;
      pw_node_methods = record
        end;

(* error 
#define pw_node_method(o,method,version,...)				\
in declaration at line 184 *)
(* error 
	int _res = -ENOTSUP;						\
(* error 
	spa_interface_call_res((struct spa_interface*)o,		\
in declaration at line 187 *)
(* error 
			method, version, ##__VA_ARGS__);		\
(* error 
	_res;								\
in declaration at line 188 *)
(* error 
	_res;								\
(* error 
})
    {* Node  }
in define line 192 *)
(* error 
#define pw_node_subscribe_params(c,...)	pw_node_method(c,subscribe_params,0,__VA_ARGS__)
in define line 193 *)
(* error 
#define pw_node_enum_params(c,...)	pw_node_method(c,enum_params,0,__VA_ARGS__)
in define line 194 *)
(* error 
#define pw_node_set_param(c,...)	pw_node_method(c,set_param,0,__VA_ARGS__)
in define line 195 *)
(* error 
#define pw_node_send_command(c,...)	pw_node_method(c,send_command,0,__VA_ARGS__)
in define line 196 *)
    {*
     * \
      }
{$endif}
    { PIPEWIRE_NODE_H  }

