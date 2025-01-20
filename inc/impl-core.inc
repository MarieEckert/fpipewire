    Type
    Ppw_core_info  = ^pw_core_info;
    Ppw_impl_core  = ^pw_impl_core;
    Ppw_impl_core_events  = ^pw_impl_core_events;
    Ppw_properties  = ^pw_properties;
    Pspa_dict  = Pointer; {$WARNING ^spa_dict}
    Pspa_hook  = Pointer; {$WARNING ^spa_hook}
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_IMPL_CORE_H}
{$define PIPEWIRE_IMPL_CORE_H}  
{ C++ extern C conditionnal removed }
  {* \defgroup pw_impl_core Core Impl
   *
   * \brief PipeWire core interface.
   *
   * The core is used to make objects on demand.
    }
  {*
   * \addtogroup pw_impl_core
   * \
    }

  type
    Ppw_impl_core = ^pw_impl_core;
    pw_impl_core = record
        {undefined structure}
      end;





  {* Factory events, listen to them with \ref pw_impl_core_add_listener  }
(* error 
#define PW_VERSION_IMPL_CORE_EVENTS	0
  {* the core is destroyed  }
  {* the core is freed  }
  {* the core is initialized  }
 in member_list *)

  type
    Ppw_impl_core_events = ^pw_impl_core_events;
    pw_impl_core_events = record
      end;

(* error 
struct pw_impl_core *pw_context_create_core(struct pw_context *context,
in declaration at line 46 *)
    { get the default core in a context  }
(* error 
struct pw_impl_core *pw_context_get_default_core(struct pw_context *context);
in declaration at line 49 *)
    {* Get the core properties  }


    function pw_impl_core_get_properties(core:Ppw_impl_core):Ppw_properties;cdecl;external;

    {* Get the core information  }

    function pw_impl_core_get_info(core:Ppw_impl_core):Ppw_core_info;cdecl;external;

    {* Update the core properties  }

    function pw_impl_core_update_properties(core:Ppw_impl_core; dict:Pspa_dict):cint;cdecl;external;

    function pw_impl_core_register(core:Ppw_impl_core; properties:Ppw_properties):cint;cdecl;external;

    procedure pw_impl_core_destroy(core:Ppw_impl_core);cdecl;external;

    function pw_impl_core_get_user_data(core:Ppw_impl_core):pointer;cdecl;external;

    {* Get the global of this core  }
(* error 
struct pw_global *pw_impl_core_get_global(struct pw_impl_core *core);
in declaration at line 68 *)
    {* Add an event listener  }

    procedure pw_impl_core_add_listener(core:Ppw_impl_core; listener:Pspa_hook; events:Ppw_impl_core_events; data:pointer);cdecl;external;

    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_IMPL_CORE_H  }

