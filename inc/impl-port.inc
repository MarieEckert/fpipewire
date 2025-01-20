    Type
    Ppw_control  = ^pw_control;
    Ppw_impl_link  = ^pw_impl_link;
    Ppw_impl_node  = ^pw_impl_node;
    Ppw_impl_port  = ^pw_impl_port;
    Ppw_impl_port_events  = ^pw_impl_port_events;
    Ppw_impl_port_state  = ^pw_impl_port_state;
    Ppw_port_info  = ^pw_port_info;
    Ppw_properties  = ^pw_properties;
    Pspa_dict  = Pointer; {$WARNING ^spa_dict}
    Pspa_hook  = Pointer; {$WARNING ^spa_hook}
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_IMPL_PORT_H}
{$define PIPEWIRE_IMPL_PORT_H}  
{ C++ extern C conditionnal removed }

  {* \defgroup pw_impl_port Port Impl
   *
   * \brief A port can be used to link two nodes.
    }
  {*
   * \addtogroup pw_impl_port
   * \
    }

  type
    Ppw_impl_port = ^pw_impl_port;
    pw_impl_port = record
        {undefined structure}
      end;

    Ppw_impl_link = ^pw_impl_link;
    pw_impl_link = record
        {undefined structure}
      end;

    Ppw_control = ^pw_control;
    pw_control = record
        {undefined structure}
      end;


  {*< the port is in error  }
  {*< the port is being created  }
  {*< the port is ready for format negotiation  }
  {*< the port is ready for buffer allocation  }
  {*< the port is paused  }

  type
    pw_impl_port_state = (PW_IMPL_PORT_STATE_ERROR := -(1),PW_IMPL_PORT_STATE_INIT := 0,
      PW_IMPL_PORT_STATE_CONFIGURE := 1,PW_IMPL_PORT_STATE_READY := 2,
      PW_IMPL_PORT_STATE_PAUSED := 3);

  {* Port events, use \ref pw_impl_port_add_listener  }
(* error 
#define PW_VERSION_IMPL_PORT_EVENTS 3
  {* The port is destroyed  }
  {* The port is freed  }
  {* The port is initialized  }
  {* the port info changed  }
  {* a new link is added on this port  }
  {* a link is removed from this port  }
  {* the state of the port changed  }
  {* a control was added to the port  }
  {* a control was removed from the port  }
  {* a parameter changed, since version 1  }
  {* latency changed. Since version 2  }
  {* tag changed. Since version 3  }
 in member_list *)
    Ppw_impl_port_events = ^pw_impl_port_events;
    pw_impl_port_events = record
      end;

  {* Create a new port
   * \return a newly allocated port  }
(* error 
struct pw_impl_port *
in declaration at line 86 *)
    {* Get the port direction  }
(* error 
enum pw_direction pw_impl_port_get_direction(struct pw_impl_port *port);
in declaration at line 89 *)
    {* Get the port properties  }


    function pw_impl_port_get_properties(port:Ppw_impl_port):Ppw_properties;cdecl;external External_library name 'pw_impl_port_get_properties';

    {* Update the port properties  }

    function pw_impl_port_update_properties(port:Ppw_impl_port; dict:Pspa_dict):cint;cdecl;external External_library name 'pw_impl_port_update_properties';

    {* Get the port info  }

    function pw_impl_port_get_info(port:Ppw_impl_port):Ppw_port_info;cdecl;external External_library name 'pw_impl_port_get_info';

    {* Get the port id  }
    function pw_impl_port_get_id(port:Ppw_impl_port):uint32_t;cdecl;external External_library name 'pw_impl_port_get_id';

    {* Get the port state as a string  }

    function pw_impl_port_state_as_string(state:pw_impl_port_state):pcchar;cdecl;external External_library name 'pw_impl_port_state_as_string';

    {* Get the port parent node or NULL when not yet set  }
(* error 
struct pw_impl_node *pw_impl_port_get_node(struct pw_impl_port *port);
in declaration at line 107 *)
    {* check is a port has links, return 0 if not, 1 if it is linked  }
    function pw_impl_port_is_linked(port:Ppw_impl_port):cint;cdecl;external External_library name 'pw_impl_port_is_linked';

    {* Add a port to a node  }
    function pw_impl_port_add(port:Ppw_impl_port; node:Ppw_impl_node):cint;cdecl;external External_library name 'pw_impl_port_add';

    {* Add an event listener on the port  }

    procedure pw_impl_port_add_listener(port:Ppw_impl_port; listener:Pspa_hook; events:Ppw_impl_port_events; data:pointer);cdecl;external External_library name 'pw_impl_port_add_listener';

    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_IMPL_PORT_H  }

