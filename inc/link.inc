
    { Pointers to basic pascal types, inserted by h2pas conversion program.}
    Type
      PLongint  = ^Longint;
      PSmallInt = ^SmallInt;
      PByte     = ^Byte;
      PWord     = ^Word;
      PDWord    = ^DWord;
      PDouble   = ^Double;

    Type
    Ppw_link  = ^pw_link;
    Ppw_link_events  = ^pw_link_events;
    Ppw_link_info  = ^pw_link_info;
    Ppw_link_methods  = ^pw_link_methods;
    Ppw_link_state  = ^pw_link_state;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_LINK_H}
{$define PIPEWIRE_LINK_H}  
{ C++ extern C conditionnal removed }



  {* \defgroup pw_link Link
   *
   * A link is the connection between 2 nodes (\ref pw_node). Nodes are
   * linked together on ports.
   *
   * The link is responsible for negotiating the format and buffers for
   * the nodes.
   *
    }
  {*
   * \addtogroup pw_link
   * \
    }
(* error 
#define PW_TYPE_INTERFACE_Link	PW_TYPE_INFO_INTERFACE_BASE "Link"
in define line 32 *)
(* error 
#define PW_LINK_PERM_MASK	PW_PERM_R | PW_PERM_X
in define line 34 *)

    const
      PW_VERSION_LINK = 3;      

    type
      Ppw_link = ^pw_link;
      pw_link = record
          {undefined structure}
        end;

    {* \enum pw_link_state The different link states  }
    {*< the link is in error  }
    {*< the link is unlinked  }
    {*< the link is initialized  }
    {*< the link is negotiating formats  }
    {*< the link is allocating buffers  }
    {*< the link is paused  }
    {*< the link is active  }
      pw_link_state = (PW_LINK_STATE_ERROR := -(2),PW_LINK_STATE_UNLINKED := -(1),
        PW_LINK_STATE_INIT := 0,PW_LINK_STATE_NEGOTIATING := 1,
        PW_LINK_STATE_ALLOCATING := 2,PW_LINK_STATE_PAUSED := 3,
        PW_LINK_STATE_ACTIVE := 4);

    {* Convert a \ref pw_link_state to a readable string  }
(* Const before type ignored *)

    function pw_link_state_as_string(state:pw_link_state):pcchar;cdecl;external;

    {* The link information. Extra information can be added in later versions  }
    {*< id of the global  }
    {*< server side output node id  }
    {*< output port id  }
    {*< server side input node id  }
    {*< input port id  }
(* error 
#define PW_LINK_CHANGE_MASK_STATE	(1 << 0)
    {*< bitfield of changed fields since last call  }
    {*< the current state of the link  }
    {*< an error reason if \a state is error  }
    {*< format over link  }
    {*< the properties of the link  }
 in member_list *)

    type
      Ppw_link_info = ^pw_link_info;
      pw_link_info = record
        end;

(* error 
struct pw_link_info *
in declaration at line 72 *)
(* error 
struct pw_link_info *
in declaration at line 76 *)

    procedure pw_link_info_free(info:Ppw_link_info);cdecl;external;

    const
      PW_LINK_EVENT_INFO = 0;      
      PW_LINK_EVENT_NUM = 1;      
    {* Link events  }
(* error 
#define PW_VERSION_LINK_EVENTS	0
    {*
    	 * Notify link info
    	 *
    	 * \param info info about the link
    	  }
 in member_list *)

    type
      Ppw_link_events = ^pw_link_events;
      pw_link_events = record
        end;


    const
      PW_LINK_METHOD_ADD_LISTENER = 0;      
      PW_LINK_METHOD_NUM = 1;      
    {* Link methods  }
(* error 
#define PW_VERSION_LINK_METHODS		0
 in member_list *)

    type
      Ppw_link_methods = ^pw_link_methods;
      pw_link_methods = record
        end;

(* error 
#define pw_link_method(o,method,version,...)				\
in declaration at line 113 *)
(* error 
	int _res = -ENOTSUP;						\
(* error 
	spa_interface_call_res((struct spa_interface*)o,		\
in declaration at line 116 *)
(* error 
			method, version, ##__VA_ARGS__);		\
(* error 
	_res;								\
in declaration at line 117 *)
(* error 
	_res;								\
(* error 
})
in define line 120 *)
    {*
     * \
      }
{$endif}
    { PIPEWIRE_LINK_H  }

