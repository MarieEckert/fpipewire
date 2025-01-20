    Type
    Ppw_client_node  = ^pw_client_node;
    Ppw_client_node_buffer  = ^pw_client_node_buffer;
    Ppw_client_node_events  = ^pw_client_node_events;
    Ppw_client_node_methods  = ^pw_client_node_methods;
    Pspa_buffer  = Pointer; {$WARNING ^spa_buffer}
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_EXT_CLIENT_NODE_H}
{$define PIPEWIRE_EXT_CLIENT_NODE_H}  
{ C++ extern C conditionnal removed }


  {* \defgroup pw_client_node Client Node
   * Client node interface
    }
  {*
   * \addtogroup pw_client_node
   * \
    }
(* error 
#define PW_TYPE_INTERFACE_ClientNode		PW_TYPE_INFO_INTERFACE_BASE "ClientNode"
in define line 23 *)
    {
     * version 4: new port_set_mix_info event added
     * version 5: driver nodes are scheduled on the client
     * version 6: client needs to set activation INACTIVE -> FINISHED
      }

    const
      PW_VERSION_CLIENT_NODE = 6;      

    type
      Ppw_client_node = ^pw_client_node;
      pw_client_node = record
          {undefined structure}
        end;

(* error 
#define PW_EXTENSION_MODULE_CLIENT_NODE		PIPEWIRE_MODULE_PREFIX "module-client-node"
in define line 33 *)
    {* information about a buffer  }
    {*< the memory id for the metadata  }
    {*< offset in memory  }
    {*< size in memory  }
    {*< buffer describing metadata and buffer memory  }
      Ppw_client_node_buffer = ^pw_client_node_buffer;
      pw_client_node_buffer = record
          mem_id : uint32_t;
          offset : uint32_t;
          size : uint32_t;
          buffer : Pspa_buffer;
        end;


    const
      PW_CLIENT_NODE_EVENT_TRANSPORT = 0;      
      PW_CLIENT_NODE_EVENT_SET_PARAM = 1;      
      PW_CLIENT_NODE_EVENT_SET_IO = 2;      
      PW_CLIENT_NODE_EVENT_EVENT = 3;      
      PW_CLIENT_NODE_EVENT_COMMAND = 4;      
      PW_CLIENT_NODE_EVENT_ADD_PORT = 5;      
      PW_CLIENT_NODE_EVENT_REMOVE_PORT = 6;      
      PW_CLIENT_NODE_EVENT_PORT_SET_PARAM = 7;      
      PW_CLIENT_NODE_EVENT_PORT_USE_BUFFERS = 8;      
      PW_CLIENT_NODE_EVENT_PORT_SET_IO = 9;      
      PW_CLIENT_NODE_EVENT_SET_ACTIVATION = 10;      
      PW_CLIENT_NODE_EVENT_PORT_SET_MIX_INFO = 11;      
      PW_CLIENT_NODE_EVENT_NUM = 12;      
    {* \ref pw_client_node events  }
(* error 
#define PW_VERSION_CLIENT_NODE_EVENTS		1
    {*
    	 * Notify of a new transport area
    	 *
    	 * The transport area is used to signal the client and the server.
    	 *
    	 * \param readfd fd for signal data can be read
    	 * \param writefd fd for signal data can be written
    	 * \param mem_id id for activation memory
    	 * \param offset offset of activation memory
    	 * \param size size of activation memory
    	  }
    {*
    	 * Notify of a property change
    	 *
    	 * When the server configures the properties on the node
    	 * this event is sent
    	 *
    	 * \param id the id of the parameter
    	 * \param flags parameter flags
    	 * \param param the param to set
    	  }
    {*
    	 * Configure an IO area for the client
    	 *
    	 * IO areas are identified with an id and are used to
    	 * exchange state between client and server
    	 *
    	 * \param id the id of the io area
    	 * \param mem_id the id of the memory to use
    	 * \param offset offset of io area in memory
    	 * \param size size of the io area
    	  }
    {*
    	 * Receive an event from the client node
    	 * \param event the received event  }
    {*
    	 * Notify of a new node command
    	 *
    	 * \param command the command
    	  }
    {*
    	 * A new port was added to the node
    	 *
    	 * The server can at any time add a port to the node when there
    	 * are free ports available.
    	 *
    	 * \param direction the direction of the port
    	 * \param port_id the new port id
    	 * \param props extra properties
    	  }
    {*
    	 * A port was removed from the node
    	 *
    	 * \param direction a port direction
    	 * \param port_id the remove port id
    	  }
    {*
    	 * A parameter was configured on the port
    	 *
    	 * \param direction a port direction
    	 * \param port_id the port id
    	 * \param id the id of the parameter
    	 * \param flags flags used when setting the param
    	 * \param param the new param
    	  }
    {*
    	 * Notify the port of buffers
    	 *
    	 * \param direction a port direction
    	 * \param port_id the port id
    	 * \param mix_id the mixer port id
    	 * \param n_buffer the number of buffers
    	 * \param buffers and array of buffer descriptions
    	  }
    {*
    	 * Configure the io area with \a id of \a port_id.
    	 *
    	 * \param direction the direction of the port
    	 * \param port_id the port id
    	 * \param mix_id the mixer port id
    	 * \param id the id of the io area to set
    	 * \param mem_id the id of the memory to use
    	 * \param offset offset of io area in memory
    	 * \param size size of the io area
    	  }
    {*
    	 * Notify the activation record of the next
    	 * node to trigger
    	 *
    	 * \param node_id the peer node id
    	 * \param signalfd the fd to wake up the peer
    	 * \param mem_id the mem id of the memory
    	 * \param the offset in \a mem_id to map
    	 * \param the size of \a mem_id to map
    	  }
    {*
    	 * Notify about the peer of mix_id
    	 *
    	 * \param direction the direction of the port
    	 * \param port_id the port id
    	 * \param mix_id the mix id
    	 * \param peer_id the id of the peer port
    	 * \param props extra properties
    	 *
    	 * Since version 4:1
    	  }
 in member_list *)

    type
      Ppw_client_node_events = ^pw_client_node_events;
      pw_client_node_events = record
        end;


    const
      PW_CLIENT_NODE_METHOD_ADD_LISTENER = 0;      
      PW_CLIENT_NODE_METHOD_GET_NODE = 1;      
      PW_CLIENT_NODE_METHOD_UPDATE = 2;      
      PW_CLIENT_NODE_METHOD_PORT_UPDATE = 3;      
      PW_CLIENT_NODE_METHOD_SET_ACTIVE = 4;      
      PW_CLIENT_NODE_METHOD_EVENT = 5;      
      PW_CLIENT_NODE_METHOD_PORT_BUFFERS = 6;      
      PW_CLIENT_NODE_METHOD_NUM = 7;      
    {* \ref pw_client_node methods  }
(* error 
#define PW_VERSION_CLIENT_NODE_METHODS		0
    {* get the node object
    	  }
    {*
    	 * Update the node ports and properties
    	 *
    	 * Update the maximum number of ports and the params of the
    	 * client node.
    	 * \param change_mask bitfield with changed parameters
    	 * \param max_input_ports new max input ports
    	 * \param max_output_ports new max output ports
    	 * \param params new params
    	  }
    {*
    	 * Update a node port
    	 *
    	 * Update the information of one port of a node.
    	 * \param direction the direction of the port
    	 * \param port_id the port id to update
    	 * \param change_mask a bitfield of changed items
    	 * \param n_params number of port parameters
    	 * \param params array of port parameters
    	 * \param info port information
    	  }
    {*
    	 * Activate or deactivate the node
    	  }
    {*
    	 * Send an event to the node
    	 * \param event the event to send
    	  }
    {*
    	 * Send allocated buffers
    	  }
 in member_list *)

    type
      Ppw_client_node_methods = ^pw_client_node_methods;
      pw_client_node_methods = record
        end;

(* error 
#define pw_client_node_method(o,method,version,...)			\
in declaration at line 309 *)
(* error 
	int _res = -ENOTSUP;						\
(* error 
	spa_interface_call_res((struct spa_interface*)o,		\
in declaration at line 312 *)
(* error 
			method, version, ##__VA_ARGS__);		\
(* error 
	_res;								\
in declaration at line 313 *)
(* error 
	_res;								\
(* error 
})
in define line 316 *)
(* error 
static inline struct pw_node *
(* error 
pw_client_node_get_node(struct pw_client_node *p, uint32_t version, size_t user_data_size)
(* error 
pw_client_node_get_node(struct pw_client_node *p, uint32_t version, size_t user_data_size)
 in declarator_list *)
 in declarator_list *)
 in declarator_list *)
(* error 
	struct pw_node *res = NULL;
 in declarator_list *)
(* error 
	spa_interface_call_res((struct spa_interface*)p,
(* error 
			struct pw_client_node_methods, res,
 in declarator_list *)
 in declarator_list *)
(* error 
			get_node, 0, version, user_data_size);
 in declarator_list *)
(* error 
			get_node, 0, version, user_data_size);
 in declarator_list *)

      var
        res : return;cvar;public;
(* error 
}
in define line 328 *)
(* error 
#define pw_client_node_port_update(c,...)	pw_client_node_method(c,port_update,0,__VA_ARGS__)
in define line 329 *)
(* error 
#define pw_client_node_set_active(c,...)	pw_client_node_method(c,set_active,0,__VA_ARGS__)
in define line 330 *)
(* error 
#define pw_client_node_event(c,...)		pw_client_node_method(c,event,0,__VA_ARGS__)
in define line 331 *)
(* error 
#define pw_client_node_port_buffers(c,...)	pw_client_node_method(c,port_buffers,0,__VA_ARGS__)
in define line 332 *)
    {*
     * \
      }
{$endif}
    { PIPEWIRE_EXT_CLIENT_NODE_H  }

