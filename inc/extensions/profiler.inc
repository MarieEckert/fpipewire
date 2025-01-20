    Type
    Ppw_profiler  = ^pw_profiler;
    Ppw_profiler_events  = ^pw_profiler_events;
    Ppw_profiler_methods  = ^pw_profiler_methods;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2020 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_EXT_PROFILER_H}
{$define PIPEWIRE_EXT_PROFILER_H}  
{ C++ extern C conditionnal removed }

  {* \defgroup pw_profiler Profiler
   * Profiler interface
    }
  {*
   * \addtogroup pw_profiler
   * \
    }
(* error 
#define PW_TYPE_INTERFACE_Profiler		PW_TYPE_INFO_INTERFACE_BASE "Profiler"
in define line 22 *)

    const
      PW_VERSION_PROFILER = 3;      

    type
      Ppw_profiler = ^pw_profiler;
      pw_profiler = record
          {undefined structure}
        end;

(* error 
#define PW_EXTENSION_MODULE_PROFILER		PIPEWIRE_MODULE_PREFIX "module-profiler"
in define line 27 *)

    const
      PW_PROFILER_PERM_MASK = PW_PERM_R;      
      PW_PROFILER_EVENT_PROFILE = 0;      
      PW_PROFILER_EVENT_NUM = 1;      
    {* \ref pw_profiler events  }
(* error 
#define PW_VERSION_PROFILER_EVENTS		0
 in member_list *)

    type
      Ppw_profiler_events = ^pw_profiler_events;
      pw_profiler_events = record
        end;


    const
      PW_PROFILER_METHOD_ADD_LISTENER = 0;      
      PW_PROFILER_METHOD_NUM = 1;      
    {* \ref pw_profiler methods  }
(* error 
#define PW_VERSION_PROFILER_METHODS		0
 in member_list *)

    type
      Ppw_profiler_methods = ^pw_profiler_methods;
      pw_profiler_methods = record
        end;

(* error 
#define pw_profiler_method(o,method,version,...)			\
in declaration at line 58 *)
(* error 
	int _res = -ENOTSUP;						\
(* error 
	spa_interface_call_res((struct spa_interface*)o,		\
in declaration at line 61 *)
(* error 
			method, version, ##__VA_ARGS__);		\
(* error 
	_res;								\
in declaration at line 62 *)
(* error 
	_res;								\
(* error 
})
in define line 65 *)

    const
      PW_KEY_PROFILER_NAME = 'profiler.name';      
    {*
     * \
      }
{$endif}
    { PIPEWIRE_EXT_PROFILER_H  }

