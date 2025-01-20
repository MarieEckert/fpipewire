    Type
    Ppw_control  = ^pw_control;
    Ppw_control_events  = ^pw_control_events;
    Pspa_hook  = Pointer; {$WARNING ^spa_hook}
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_CONTROL_H}
{$define PIPEWIRE_CONTROL_H}  
{ C++ extern C conditionnal removed }

  {* \defgroup pw_control Control
   *
   * \brief A control can be used to control a port property.
    }
  {*
   * \addtogroup pw_control
   * \
    }

  type
    Ppw_control = ^pw_control;
    pw_control = record
        {undefined structure}
      end;


  {* Port events, use \ref pw_control_add_listener  }
(* error 
#define PW_VERSION_CONTROL_EVENTS 0
  {* The control is destroyed  }
  {* The control is freed  }
  {* control is linked to another control  }
  {* control is unlinked from another control  }
 in member_list *)

  type
    Ppw_control_events = ^pw_control_events;
    pw_control_events = record
      end;

  {* Get the control parent port or NULL when not set  }
(* error 
struct pw_impl_port *pw_control_get_port(struct pw_control *control);
in declaration at line 46 *)
    {* Add an event listener on the control. May be called multiple times.
     * Each listener must be removed, but they may be removed in any order.  }


    procedure pw_control_add_listener(control:Ppw_control; listener:Pspa_hook; events:Ppw_control_events; data:pointer);cdecl;external External_library name 'pw_control_add_listener';

    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_CONTROL_H  }

