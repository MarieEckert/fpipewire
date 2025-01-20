    Type
    Ppw_main_loop  = ^pw_main_loop;
    Ppw_main_loop_events  = ^pw_main_loop_events;
    Pspa_hook  = Pointer; {$WARNING ^spa_hook}
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_MAIN_LOOP_H}
{$define PIPEWIRE_MAIN_LOOP_H}  
{ C++ extern C conditionnal removed }
  {* \defgroup pw_main_loop Main Loop
   *
   * A main loop object
    }
  {*
   * \addtogroup pw_main_loop
   * \
    }
  {* A main loop object  }

  type
    Ppw_main_loop = ^pw_main_loop;
    pw_main_loop = record
        {undefined structure}
      end;


  {* Events of the main loop  }
(* error 
#define PW_VERSION_MAIN_LOOP_EVENTS	0
  {* Emitted when the main loop is destroyed  }
 in member_list *)

  type
    Ppw_main_loop_events = ^pw_main_loop_events;
    pw_main_loop_events = record
      end;

  {* Create a new main loop.  }
(* error 
struct pw_main_loop *
in declaration at line 38 *)
    {* Add an event listener  }


    procedure pw_main_loop_add_listener(loop:Ppw_main_loop; listener:Pspa_hook; events:Ppw_main_loop_events; data:pointer);cdecl;external External_library name 'pw_main_loop_add_listener';

    {* Get the loop implementation  }
(* error 
struct pw_loop * pw_main_loop_get_loop(struct pw_main_loop *loop);
in declaration at line 47 *)
    {* Destroy a loop  }
    procedure pw_main_loop_destroy(loop:Ppw_main_loop);cdecl;external External_library name 'pw_main_loop_destroy';

    {* Run a main loop. This blocks until \ref pw_main_loop_quit is called.
     *
     * @return 0 on success, otherwise a negative number.
      }
    function pw_main_loop_run(loop:Ppw_main_loop):cint;cdecl;external External_library name 'pw_main_loop_run';

    {* Quit a main loop  }
    function pw_main_loop_quit(loop:Ppw_main_loop):cint;cdecl;external External_library name 'pw_main_loop_quit';

    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_MAIN_LOOP_H  }

