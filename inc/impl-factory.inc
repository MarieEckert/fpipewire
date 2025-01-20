    Type
    Ppw_factory_info  = ^pw_factory_info;
    Ppw_impl_factory  = ^pw_impl_factory;
    Ppw_impl_factory_events  = ^pw_impl_factory_events;
    Ppw_impl_factory_implementation  = ^pw_impl_factory_implementation;
    Ppw_properties  = ^pw_properties;
    Ppw_resource  = ^pw_resource;
    Pspa_dict  = Pointer; {$WARNING ^spa_dict}
    Pspa_hook  = Pointer; {$WARNING ^spa_hook}
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_IMPL_FACTORY_H}
{$define PIPEWIRE_IMPL_FACTORY_H}  
{ C++ extern C conditionnal removed }
  {* \defgroup pw_impl_factory Factory Impl
   *
   * The factory is used to make objects on demand.
    }
  {*
   * \addtogroup pw_impl_factory
   * \
    }

  type
    Ppw_impl_factory = ^pw_impl_factory;
    pw_impl_factory = record
        {undefined structure}
      end;






  {* Factory events, listen to them with \ref pw_impl_factory_add_listener  }
(* error 
#define PW_VERSION_IMPL_FACTORY_EVENTS	0
  {* the factory is destroyed  }
  {* the factory is freed  }
  {* the factory is initialized  }
 in member_list *)

  type
    Ppw_impl_factory_events = ^pw_impl_factory_events;
    pw_impl_factory_events = record
      end;

(* error 
#define PW_VERSION_IMPL_FACTORY_IMPLEMENTATION	0
  {* The function to create an object from this factory  }
 in member_list *)
    Ppw_impl_factory_implementation = ^pw_impl_factory_implementation;
    pw_impl_factory_implementation = record
      end;

(* error 
struct pw_impl_factory *pw_context_create_factory(struct pw_context *context,
in declaration at line 60 *)
    {* Get the factory properties  }


    function pw_impl_factory_get_properties(factory:Ppw_impl_factory):Ppw_properties;cdecl;external External_library name 'pw_impl_factory_get_properties';

    {* Get the factory info  }

    function pw_impl_factory_get_info(factory:Ppw_impl_factory):Ppw_factory_info;cdecl;external External_library name 'pw_impl_factory_get_info';

    {* Update the factory properties  }

    function pw_impl_factory_update_properties(factory:Ppw_impl_factory; dict:Pspa_dict):cint;cdecl;external External_library name 'pw_impl_factory_update_properties';

    function pw_impl_factory_register(factory:Ppw_impl_factory; properties:Ppw_properties):cint;cdecl;external External_library name 'pw_impl_factory_register';

    procedure pw_impl_factory_destroy(factory:Ppw_impl_factory);cdecl;external External_library name 'pw_impl_factory_destroy';

    function pw_impl_factory_get_user_data(factory:Ppw_impl_factory):pointer;cdecl;external External_library name 'pw_impl_factory_get_user_data';

    {* Get the global of this factory  }
(* error 
struct pw_global *pw_impl_factory_get_global(struct pw_impl_factory *factory);
in declaration at line 79 *)
    {* Add an event listener  }

    procedure pw_impl_factory_add_listener(factory:Ppw_impl_factory; listener:Pspa_hook; events:Ppw_impl_factory_events; data:pointer);cdecl;external External_library name 'pw_impl_factory_add_listener';


    procedure pw_impl_factory_set_implementation(factory:Ppw_impl_factory; implementation:Ppw_impl_factory_implementation; data:pointer);cdecl;external External_library name 'pw_impl_factory_set_implementation';


    function pw_impl_factory_create_object(factory:Ppw_impl_factory; resource:Ppw_resource; _type:pcchar; version:uint32_t; properties:Ppw_properties; 
               new_id:uint32_t):pointer;cdecl;external External_library name 'pw_impl_factory_create_object';

    {* Find a factory by name  }
(* error 
struct pw_impl_factory *
    {*< the context  }    {*< the factory name  }in declaration at line 101 *)
    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_IMPL_FACTORY_H  }

