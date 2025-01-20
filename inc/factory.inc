    Type
    Ppw_factory  = ^pw_factory;
    Ppw_factory_events  = ^pw_factory_events;
    Ppw_factory_info  = ^pw_factory_info;
    Ppw_factory_methods  = ^pw_factory_methods;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_FACTORY_H}
{$define PIPEWIRE_FACTORY_H}  
{ C++ extern C conditionnal removed }





  {* \defgroup pw_factory Factory
   * Factory interface
    }
  {*
   * \addtogroup pw_factory
   * \
    }
(* error 
#define PW_TYPE_INTERFACE_Factory	PW_TYPE_INFO_INTERFACE_BASE "Factory"
in define line 28 *)
(* error 
#define PW_FACTORY_PERM_MASK		PW_PERM_R|PW_PERM_M
in define line 30 *)

    const
      PW_VERSION_FACTORY = 3;      

    type
      Ppw_factory = ^pw_factory;
      pw_factory = record
          {undefined structure}
        end;

    {* The factory information. Extra information can be added in later versions  }
    {*< id of the global  }

    {*< name the factory  }

    {*< type of the objects created by this factory  }
    {*< version of the objects  }
(* error 
#define PW_FACTORY_CHANGE_MASK_PROPS	(1 << 0)
    {*< bitfield of changed fields since last call  }
    {*< the properties of the factory  }
 in member_list *)
      Ppw_factory_info = ^pw_factory_info;
      pw_factory_info = record
        end;

(* error 
struct pw_factory_info *
in declaration at line 49 *)
(* error 
struct pw_factory_info *
in declaration at line 52 *)

    procedure pw_factory_info_free(info:Ppw_factory_info);cdecl;external External_library name 'pw_factory_info_free';

    const
      PW_FACTORY_EVENT_INFO = 0;      
      PW_FACTORY_EVENT_NUM = 1;      
    {* Factory events  }
(* error 
#define PW_VERSION_FACTORY_EVENTS	0
    {*
    	 * Notify factory info
    	 *
    	 * \param info info about the factory
    	  }
 in member_list *)

    type
      Ppw_factory_events = ^pw_factory_events;
      pw_factory_events = record
        end;


    const
      PW_FACTORY_METHOD_ADD_LISTENER = 0;      
      PW_FACTORY_METHOD_NUM = 1;      
    {* Factory methods  }
(* error 
#define PW_VERSION_FACTORY_METHODS	0
 in member_list *)

    type
      Ppw_factory_methods = ^pw_factory_methods;
      pw_factory_methods = record
        end;

(* error 
#define pw_factory_method(o,method,version,...)				\
in declaration at line 88 *)
(* error 
	int _res = -ENOTSUP;						\
(* error 
	spa_interface_call_res((struct spa_interface*)o,		\
in declaration at line 91 *)
(* error 
			method, version, ##__VA_ARGS__);		\
(* error 
	_res;								\
in declaration at line 92 *)
(* error 
	_res;								\
(* error 
})
in define line 95 *)
    {*
     * \
      }
{$endif}
    { PIPEWIRE_FACTORY_H  }

