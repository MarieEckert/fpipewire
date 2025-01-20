{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{ C++ extern C conditionnal removed }






  {* \defgroup pw_port Port
   * Port interface
    }
  {*
   * \addtogroup pw_port
   * \
    }
(* error
#define PW_TYPE_INTERFACE_Port	PW_TYPE_INFO_INTERFACE_BASE "Port"
in define line 30 *)
(* error
#define PW_PORT_PERM_MASK	PW_PERM_R|PW_PERM_X|PW_PERM_M
in define line 32 *)

    const
      PW_VERSION_PORT = 3;

    type
      Ppw_port = ^pw_port;
      pw_port = record
          {undefined structure}
        end;
      pw_direction = spa_direction;

    {* The direction of a port  }

    const
      PW_DIRECTION_INPUT = SPA_DIRECTION_INPUT;
      PW_DIRECTION_OUTPUT = SPA_DIRECTION_OUTPUT;
    {* Convert a \ref pw_direction to a readable string  }


    function pw_direction_as_string(direction:pw_direction):pcchar;cdecl;external External_library name 'pw_direction_as_string';

    {*< id of the global  }
    {*< port direction  }
(* error
#define PW_PORT_CHANGE_MASK_PROPS		(1 << 0)
    {*< bitfield of changed fields since last call  }
    {*< the properties of the port  }
    {*< parameters  }
    {*< number of items in \a params  }
 in member_list *)

    type
      Ppw_port_info = ^pw_port_info;
      pw_port_info = record
        end;

(* error
struct pw_port_info *
in declaration at line 59 *)
(* error
struct pw_port_info *
in declaration at line 63 *)

    procedure pw_port_info_free(info:Ppw_port_info);cdecl;external External_library name 'pw_port_info_free';

    const
      PW_PORT_EVENT_INFO = 0;
      PW_PORT_EVENT_PARAM = 1;
      PW_PORT_EVENT_NUM = 2;
    {* Port events  }
(* error
#define PW_VERSION_PORT_EVENTS	0
    {*
    	 * Notify port info
    	 *
    	 * \param info info about the port
    	  }
    {*
    	 * Notify a port param
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
      Ppw_port_events = ^pw_port_events;
      pw_port_events = record
        end;


    const
      PW_PORT_METHOD_ADD_LISTENER = 0;
      PW_PORT_METHOD_SUBSCRIBE_PARAMS = 1;
      PW_PORT_METHOD_ENUM_PARAMS = 2;
      PW_PORT_METHOD_NUM = 3;
    {* Port methods  }
(* error
#define PW_VERSION_PORT_METHODS		0
    {*
    	 * Subscribe to parameter changes
    	 *
    	 * Automatically emit param events for the given ids when
    	 * they are changed.
    	 *
    	 * \param ids an array of param ids
    	 * \param n_ids the number of ids in \a ids
    	 *
    	 * This requires X permissions on the port.
    	  }
    {*
    	 * Enumerate port parameters
    	 *
    	 * Start enumeration of port parameters. For each param, a
    	 * param event will be emitted.
    	 *
    	 * \param seq a sequence number returned in the reply
    	 * \param id the parameter id to enumerate
    	 * \param start the start index or 0 for the first param
    	 * \param num the maximum number of params to retrieve
    	 * \param filter a param filter or NULL
    	 *
    	 * This requires X permissions on the port.
    	  }
 in member_list *)

    type
      Ppw_port_methods = ^pw_port_methods;
      pw_port_methods = record
        end;
