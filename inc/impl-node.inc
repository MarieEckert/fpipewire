    Type
    Ppw_impl_node  = ^pw_impl_node;
    Ppw_impl_node_events  = ^pw_impl_node_events;
    Ppw_impl_node_rt_events  = ^pw_impl_node_rt_events;
    Ppw_impl_port  = ^pw_impl_port;
    Ppw_node_info  = ^pw_node_info;
    Ppw_properties  = ^pw_properties;
    Pspa_command  = Pointer; {$WARNING ^spa_command}
    Pspa_dict  = Pointer; {$WARNING ^spa_dict}
    Pspa_hook  = Pointer; {$WARNING ^spa_hook}
    Pspa_node  = Pointer; {$WARNING ^spa_node}
    Pspa_pod  = Pointer; {$WARNING ^spa_pod}
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_IMPL_NODE_H}
{$define PIPEWIRE_IMPL_NODE_H}  
{ C++ extern C conditionnal removed }
  {* \defgroup pw_impl_node Node Impl
   *
   * The node object processes data. The node has a list of
   * input and output ports (\ref pw_impl_port) on which it
   * will receive and send out buffers respectively.
    }
  {*
   * \addtogroup pw_impl_node
   * \
    }

  type
    Ppw_impl_node = ^pw_impl_node;
    pw_impl_node = record
        {undefined structure}
      end;

    Ppw_impl_port = ^pw_impl_port;
    pw_impl_port = record
        {undefined structure}
      end;




  {* Node events, listen to them with \ref pw_impl_node_add_listener  }
(* error 
#define PW_VERSION_IMPL_NODE_EVENTS	0
  {* the node is destroyed  }
  {* the node is about to be freed  }
  {* the node is initialized  }
  {* a port is being initialized on the node  }
  {* a port was added  }
  {* a port was removed  }
  {* the node info changed  }
  {* a port on the node changed info  }
  {* the node active state changed  }
  {* a new state is requested on the node  }
  {* the state of the node changed  }
  {* a result was received  }
  {* an event is emitted  }
  {* the driver of the node changed  }
  {* a peer was added  }
  {* a peer was removed  }
 in member_list *)

  type
    Ppw_impl_node_events = ^pw_impl_node_events;
    pw_impl_node_events = record
      end;

(* error 
#define PW_VERSION_IMPL_NODE_RT_EVENTS	0
  {* the node is drained  }
  {* the node had an xrun  }
  {* the driver node starts processing  }
  {* the driver node completed processing  }
  {* the driver node did not complete processing  }
  {* the node had a timeout  }
 in member_list *)
    Ppw_impl_node_rt_events = ^pw_impl_node_rt_events;
    pw_impl_node_rt_events = record
      end;

  {* Create a new node  }
(* error 
struct pw_impl_node *
  {*< the context  }
  {*< extra properties  }
  {*< user data size  }in declaration at line 99 *)
    {* Complete initialization of the node and register  }
    {*< node to register  }
    {*< extra properties  }
    function pw_impl_node_register(node:Ppw_impl_node; properties:Ppw_properties):cint;cdecl;external;

    {* Destroy a node  }
    procedure pw_impl_node_destroy(node:Ppw_impl_node);cdecl;external;

    {* Get the node info  }

    function pw_impl_node_get_info(node:Ppw_impl_node):Ppw_node_info;cdecl;external;

    {* Get node user_data. The size of the memory was given in \ref pw_context_create_node  }
    function pw_impl_node_get_user_data(node:Ppw_impl_node):pointer;cdecl;external;

    {* Get the context of this node  }
(* error 
struct pw_context *pw_impl_node_get_context(struct pw_impl_node *node);
in declaration at line 115 *)
    {* Get the global of this node  }
(* error 
struct pw_global *pw_impl_node_get_global(struct pw_impl_node *node);
in declaration at line 118 *)
    {* Get the node properties  }

    function pw_impl_node_get_properties(node:Ppw_impl_node):Ppw_properties;cdecl;external;

    {* Update the node properties  }

    function pw_impl_node_update_properties(node:Ppw_impl_node; dict:Pspa_dict):cint;cdecl;external;

    {* Set the node implementation  }
    function pw_impl_node_set_implementation(node:Ppw_impl_node; spa_node:Pspa_node):cint;cdecl;external;

    {* Get the node implementation  }
(* error 
struct spa_node *pw_impl_node_get_implementation(struct pw_impl_node *node);
in declaration at line 130 *)
    {* Add an event listener  }

    procedure pw_impl_node_add_listener(node:Ppw_impl_node; listener:Pspa_hook; events:Ppw_impl_node_events; data:pointer);cdecl;external;

    {* Add an rt_event listener  }

    procedure pw_impl_node_add_rt_listener(node:Ppw_impl_node; listener:Pspa_hook; events:Ppw_impl_node_rt_events; data:pointer);cdecl;external;

    procedure pw_impl_node_remove_rt_listener(node:Ppw_impl_node; listener:Pspa_hook);cdecl;external;

    {* Iterate the ports in the given direction. The callback should return
     * 0 to fetch the next item, any other value stops the iteration and returns
     * the value. When all callbacks return 0, this function returns 0 when all
     * items are iterated.  }
    function pw_impl_node_for_each_port(node:Ppw_impl_node; direction:pw_direction; callback:function (data:pointer; port:Ppw_impl_port):cint; data:pointer):cint;cdecl;external;


    function pw_impl_node_for_each_param(node:Ppw_impl_node; seq:cint; param_id:uint32_t; index:uint32_t; max:uint32_t; 
               filter:Pspa_pod; callback:function (data:pointer; seq:cint; id:uint32_t; index:uint32_t; next:uint32_t; 
                          param:Pspa_pod):cint; data:pointer):cint;cdecl;external;

    {* Find the port with direction and port_id or NULL when not found. Passing
     * PW_ID_ANY for port_id will return any port, preferably an unlinked one.  }
(* error 
struct pw_impl_port *
in declaration at line 167 *)
    {* Get a free unused port_id from the node  }
    function pw_impl_node_get_free_port_id(node:Ppw_impl_node; direction:pw_direction):uint32_t;cdecl;external;

    function pw_impl_node_initialized(node:Ppw_impl_node):cint;cdecl;external;

    {* Set a node active. This will start negotiation with all linked active
      * nodes and start data transport  }
    function pw_impl_node_set_active(node:Ppw_impl_node; active:bool):cint;cdecl;external;

    {* Check if a node is active  }
    function pw_impl_node_is_active(node:Ppw_impl_node):bool;cdecl;external;

    {* Check if a node is active, Since 0.3.39  }

    function pw_impl_node_send_command(node:Ppw_impl_node; command:Pspa_command):cint;cdecl;external;

    {* Set a param on the node, Since 0.3.65  }

    function pw_impl_node_set_param(node:Ppw_impl_node; id:uint32_t; flags:uint32_t; param:Pspa_pod):cint;cdecl;external;

    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_IMPL_NODE_H  }

