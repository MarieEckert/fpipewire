    Type
    Ppw_device  = ^pw_device;
    Ppw_device_events  = ^pw_device_events;
    Ppw_device_info  = ^pw_device_info;
    Ppw_device_methods  = ^pw_device_methods;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_DEVICE_H}
{$define PIPEWIRE_DEVICE_H}  
{ C++ extern C conditionnal removed }



  {* \defgroup pw_device Device
   * Device interface
    }
  {*
   * \addtogroup pw_device
   * \
    }
(* error 
#define PW_TYPE_INTERFACE_Device	PW_TYPE_INFO_INTERFACE_BASE "Device"
in define line 26 *)

    const
      PW_DEVICE_PERM_MASK = PW_PERM_RWXM;      
      PW_VERSION_DEVICE = 3;      

    type
      Ppw_device = ^pw_device;
      pw_device = record
          {undefined structure}
        end;

    {* The device information. Extra information can be added in later versions  }
    {*< id of the global  }
(* error 
#define PW_DEVICE_CHANGE_MASK_PROPS	(1 << 0)
    {*< bitfield of changed fields since last call  }
    {*< extra properties  }
    {*< parameters  }
    {*< number of items in \a params  }
 in member_list *)
      Ppw_device_info = ^pw_device_info;
      pw_device_info = record
        end;

    {* Update and existing \ref pw_device_info with \a update and reset  }
(* error 
struct pw_device_info *
in declaration at line 48 *)
    {* Merge and existing \ref pw_device_info with \a update  }
(* error 
struct pw_device_info *
in declaration at line 52 *)
    {* Free a \ref pw_device_info  }

    procedure pw_device_info_free(info:Ppw_device_info);cdecl;external;

    const
      PW_DEVICE_EVENT_INFO = 0;      
      PW_DEVICE_EVENT_PARAM = 1;      
      PW_DEVICE_EVENT_NUM = 2;      
    {* Device events  }
(* error 
#define PW_VERSION_DEVICE_EVENTS	0
    {*
    	 * Notify device info
    	 *
    	 * \param info info about the device
    	  }
    {*
    	 * Notify a device param
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
      Ppw_device_events = ^pw_device_events;
      pw_device_events = record
        end;


    const
      PW_DEVICE_METHOD_ADD_LISTENER = 0;      
      PW_DEVICE_METHOD_SUBSCRIBE_PARAMS = 1;      
      PW_DEVICE_METHOD_ENUM_PARAMS = 2;      
      PW_DEVICE_METHOD_SET_PARAM = 3;      
      PW_DEVICE_METHOD_NUM = 4;      
    {* Device methods  }
(* error 
#define PW_VERSION_DEVICE_METHODS	0
    {*
    	 * Subscribe to parameter changes
    	 *
    	 * Automatically emit param events for the given ids when
    	 * they are changed.
    	 *
    	 * \param ids an array of param ids
    	 * \param n_ids the number of ids in \a ids
    	 *
    	 * This requires X permissions on the device.
    	  }
    {*
    	 * Enumerate device parameters
    	 *
    	 * Start enumeration of device parameters. For each param, a
    	 * param event will be emitted.
    	 *
    	 * \param seq a sequence number to place in the reply
    	 * \param id the parameter id to enum or PW_ID_ANY for all
    	 * \param start the start index or 0 for the first param
    	 * \param num the maximum number of params to retrieve
    	 * \param filter a param filter or NULL
    	 *
    	 * This requires X permissions on the device.
    	  }
    {*
    	 * Set a parameter on the device
    	 *
    	 * \param id the parameter id to set
    	 * \param flags extra parameter flags
    	 * \param param the parameter to set
    	 *
    	 * This requires W and X permissions on the device.
    	  }
 in member_list *)

    type
      Ppw_device_methods = ^pw_device_methods;
      pw_device_methods = record
        end;

(* error 
#define pw_device_method(o,method,version,...)				\
in declaration at line 146 *)
(* error 
	int _res = -ENOTSUP;						\
(* error 
	spa_interface_call_res((struct spa_interface*)o,		\
in declaration at line 149 *)
(* error 
			method, version, ##__VA_ARGS__);		\
(* error 
	_res;								\
in declaration at line 150 *)
(* error 
	_res;								\
(* error 
})
in define line 153 *)
(* error 
#define pw_device_subscribe_params(c,...)	pw_device_method(c,subscribe_params,0,__VA_ARGS__)
in define line 154 *)
(* error 
#define pw_device_enum_params(c,...)		pw_device_method(c,enum_params,0,__VA_ARGS__)
in define line 155 *)
(* error 
#define pw_device_set_param(c,...)		pw_device_method(c,set_param,0,__VA_ARGS__)
in define line 156 *)
    {*
     * \
      }
{$endif}
    { PIPEWIRE_DEVICE_H  }

