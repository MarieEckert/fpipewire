    Type
    Ppw_impl_module  = ^pw_impl_module;
    Ppw_impl_module_events  = ^pw_impl_module_events;
    Ppw_module_info  = ^pw_module_info;
    Ppw_properties  = ^pw_properties;
    Pspa_dict  = Pointer; {$WARNING ^spa_dict}
    Pspa_hook  = Pointer; {$WARNING ^spa_hook}
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2016 Axis Communications <dev-gstreamer@axis.com>  }
  {                         @author Linus Svensson <linus.svensson@axis.com>  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_IMPL_MODULE_H}
{$define PIPEWIRE_IMPL_MODULE_H}  
{ C++ extern C conditionnal removed }



  const
    PIPEWIRE_SYMBOL_MODULE_INIT = 'pipewire__module_init';    
    PIPEWIRE_MODULE_PREFIX = 'libpipewire-';    
  {* \defgroup pw_impl_module Module Impl
   *
   * A dynamically loadable module
    }
  {*
   * \addtogroup pw_impl_module
   * \
    }

  type
    Ppw_impl_module = ^pw_impl_module;
    pw_impl_module = record
        {undefined structure}
      end;

  {* Module init function signature
   *
   * \param module A \ref pw_impl_module
   * \param args Arguments to the module
   * \return 0 on success, < 0 otherwise with an errno style error
   *
   * A module should provide an init function with this signature. This function
   * will be called when a module is loaded.
    }


    pw_impl_module_init_func_t = function (module:Ppw_impl_module; args:pcchar):cint;cdecl;
  {* Module events added with \ref pw_impl_module_add_listener  }
(* error 
#define PW_VERSION_IMPL_MODULE_EVENTS	0
  {* The module is destroyed. This is the time to unregister and
  	 * destroy any objects created by the module.  }
  {* The module is freed. This will be called after destroy() returns.  }
  {* The module is initialized  }
  {* The module is registered. This is a good time to register
  	 * objects created from the module.  }
 in member_list *)
    Ppw_impl_module_events = ^pw_impl_module_events;
    pw_impl_module_events = record
      end;

(* error 
struct pw_impl_module *
in declaration at line 65 *)
    {* Get the context of a module  }
(* error 
struct pw_context * pw_impl_module_get_context(struct pw_impl_module *module);
in declaration at line 68 *)
    {* Get the global of a module  }
(* error 
struct pw_global * pw_impl_module_get_global(struct pw_impl_module *module);
in declaration at line 71 *)
    {* Get the module properties  }


    function pw_impl_module_get_properties(module:Ppw_impl_module):Ppw_properties;cdecl;external;

    {* Update the module properties  }

    function pw_impl_module_update_properties(module:Ppw_impl_module; dict:Pspa_dict):cint;cdecl;external;

    {* Get the module info  }

    function pw_impl_module_get_info(module:Ppw_impl_module):Ppw_module_info;cdecl;external;

    {* Add an event listener to a module  }

    procedure pw_impl_module_add_listener(module:Ppw_impl_module; listener:Pspa_hook; events:Ppw_impl_module_events; data:pointer);cdecl;external;

    {* Destroy a module  }
    procedure pw_impl_module_destroy(module:Ppw_impl_module);cdecl;external;

    {* Schedule a destroy later on the main thread  }
    procedure pw_impl_module_schedule_destroy(module:Ppw_impl_module);cdecl;external;

    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_IMPL_MODULE_H  }

