    Type
    Pspa_device  = Pointer; {$WARNING ^spa_device}
    Pspa_pod  = Pointer; {$WARNING ^spa_pod}
    TCB_pw_impl_device_for_each_param = function (data:pointer; seq:cint; id:uint32_t; index:uint32_t; next:uint32_t; 
                          param:Pspa_pod):cint;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_IMPL_DEVICE_H}
{$define PIPEWIRE_IMPL_DEVICE_H}  
{ C++ extern C conditionnal removed }
  {* \defgroup pw_impl_device Device Impl
   *
   * The device is an object that manages nodes. It typically
   * corresponds to a physical hardware device but it does not
   * have to be.
   *
   * The purpose of the device is to provide an interface to
   * dynamically create/remove/configure the nodes it manages.
    }
  {*
   * \addtogroup pw_impl_device
   * \
    }

  type
    Ppw_impl_device = ^pw_impl_device;
    pw_impl_device = record
        {undefined structure}
      end;






  {* Device events, listen to them with \ref pw_impl_device_add_listener  }
(* error 
#define PW_VERSION_IMPL_DEVICE_EVENTS	0
  {* the device is destroyed  }
  {* the device is freed  }
  {* the device is initialized  }
  {* the device info changed  }
 in member_list *)

  type
    Ppw_impl_device_events = ^pw_impl_device_events;
    pw_impl_device_events = record
      end;

(* error 
struct pw_impl_device *pw_context_create_device(struct pw_context *context,
in declaration at line 53 *)

    function pw_impl_device_register(device:Ppw_impl_device; properties:Ppw_properties):cint;cdecl;external External_library name 'pw_impl_device_register';

    procedure pw_impl_device_destroy(device:Ppw_impl_device);cdecl;external External_library name 'pw_impl_device_destroy';

    function pw_impl_device_get_user_data(device:Ppw_impl_device):pointer;cdecl;external External_library name 'pw_impl_device_get_user_data';

    {* Set the device implementation  }
    function pw_impl_device_set_implementation(device:Ppw_impl_device; spa_device:Pspa_device):cint;cdecl;external External_library name 'pw_impl_device_set_implementation';

    {* Get the device implementation  }
(* error 
struct spa_device *pw_impl_device_get_implementation(struct pw_impl_device *device);
in declaration at line 65 *)
    {* Get the global of this device  }
(* error 
struct pw_global *pw_impl_device_get_global(struct pw_impl_device *device);
in declaration at line 68 *)
    {* Add an event listener  }

    procedure pw_impl_device_add_listener(device:Ppw_impl_device; listener:Pspa_hook; events:Ppw_impl_device_events; data:pointer);cdecl;external External_library name 'pw_impl_device_add_listener';


    function pw_impl_device_update_properties(device:Ppw_impl_device; dict:Pspa_dict):cint;cdecl;external External_library name 'pw_impl_device_update_properties';


    function pw_impl_device_get_properties(device:Ppw_impl_device):Ppw_properties;cdecl;external External_library name 'pw_impl_device_get_properties';


    function pw_impl_device_for_each_param(device:Ppw_impl_device; seq:cint; param_id:uint32_t; index:uint32_t; max:uint32_t; 
               filter:Pspa_pod; callback: TCB_pw_impl_device_for_each_param; data:pointer):cint;cdecl;external External_library name 'pw_impl_device_for_each_param';

    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_IMPL_DEVICE_H  }

