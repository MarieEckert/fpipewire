    Type
    Ppw_module  = ^pw_module;
    Ppw_module_events  = ^pw_module_events;
    Ppw_module_info  = ^pw_module_info;
    Ppw_module_methods  = ^pw_module_methods;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_MODULE_H}
{$define PIPEWIRE_MODULE_H}  
{ C++ extern C conditionnal removed }



  {* \defgroup pw_module Module
   * Module interface
    }
  {*
   * \addtogroup pw_module
   * \
    }
(* error 
#define PW_TYPE_INTERFACE_Module	PW_TYPE_INFO_INTERFACE_BASE "Module"
in define line 25 *)
(* error 
#define PW_MODULE_PERM_MASK		PW_PERM_R|PW_PERM_M
in define line 27 *)

    const
      PW_VERSION_MODULE = 3;      

    type
      Ppw_module = ^pw_module;
      pw_module = record
          {undefined structure}
        end;

    {* The module information. Extra information can be added in later versions  }
    {*< id of the global  }

    {*< name of the module  }

    {*< filename of the module  }

    {*< arguments passed to the module  }
(* error 
#define PW_MODULE_CHANGE_MASK_PROPS	(1 << 0)
    {*< bitfield of changed fields since last call  }
    {*< extra properties  }
 in member_list *)
      Ppw_module_info = ^pw_module_info;
      pw_module_info = record
        end;

    {* Update and existing \ref pw_module_info with \a update with reset  }
(* error 
struct pw_module_info *
in declaration at line 47 *)
    {* Merge and existing \ref pw_module_info with \a update  }
(* error 
struct pw_module_info *
in declaration at line 51 *)
    {* Free a \ref pw_module_info  }

    procedure pw_module_info_free(info:Ppw_module_info);cdecl;external;

    const
      PW_MODULE_EVENT_INFO = 0;      
      PW_MODULE_EVENT_NUM = 1;      
    {* Module events  }
(* error 
#define PW_VERSION_MODULE_EVENTS	0
    {*
    	 * Notify module info
    	 *
    	 * \param info info about the module
    	  }
 in member_list *)

    type
      Ppw_module_events = ^pw_module_events;
      pw_module_events = record
        end;


    const
      PW_MODULE_METHOD_ADD_LISTENER = 0;      
      PW_MODULE_METHOD_NUM = 1;      
    {* Module methods  }
(* error 
#define PW_VERSION_MODULE_METHODS	0
 in member_list *)

    type
      Ppw_module_methods = ^pw_module_methods;
      pw_module_methods = record
        end;

(* error 
#define pw_module_method(o,method,version,...)				\
in declaration at line 86 *)
(* error 
	int _res = -ENOTSUP;						\
(* error 
	spa_interface_call_res((struct spa_interface*)o,		\
in declaration at line 89 *)
(* error 
			method, version, ##__VA_ARGS__);		\
(* error 
	_res;								\
in declaration at line 90 *)
(* error 
	_res;								\
(* error 
})
in define line 93 *)
    {*
     * \
      }
{$endif}
    { PIPEWIRE_MODULE_H  }

