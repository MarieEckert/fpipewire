
    { Pointers to basic pascal types, inserted by h2pas conversion program.}
    Type
      PLongint  = ^Longint;
      PSmallInt = ^SmallInt;
      PByte     = ^Byte;
      PWord     = ^Word;
      PDWord    = ^DWord;
      PDouble   = ^Double;

    Type
    Ppw_loop  = ^pw_loop;
    Pspa_loop  = ^spa_loop;
    Pspa_loop_control  = ^spa_loop_control;
    Pspa_loop_utils  = ^spa_loop_utils;
    Pspa_system  = ^spa_system;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_LOOP_H}
{$define PIPEWIRE_LOOP_H}  
{ C++ extern C conditionnal removed }


  {* \defgroup pw_loop Loop
   *
   * PipeWire loop object provides an implementation of
   * the spa loop interfaces. It can be used to implement various
   * event loops.
   *
   * The members of \ref pw_loop are read-only.
    }
  {*
   * \addtogroup pw_loop
   * \
    }
  {*< system utils  }
  {*< wrapped loop  }
  {*< loop control  }
  {*< loop utils  }
(* Const before type ignored *)

  type
    Ppw_loop = ^pw_loop;
    pw_loop = record
        system : Pspa_system;
        loop : Pspa_loop;
        control : Pspa_loop_control;
        utils : Pspa_loop_utils;
        name : pcchar;
      end;

(* error 
struct pw_loop *
in declaration at line 38 *)

    procedure pw_loop_destroy(loop:Ppw_loop);cdecl;external;

(* Const before type ignored *)
    function pw_loop_set_name(loop:Ppw_loop; name:pcchar):cint;cdecl;external;

(* error 
#define pw_loop_add_source(l,...)	spa_loop_add_source((l)->loop,__VA_ARGS__)
in define line 45 *)
(* error 
#define pw_loop_update_source(l,...)	spa_loop_update_source((l)->loop,__VA_ARGS__)
in define line 46 *)
(* error 
#define pw_loop_remove_source(l,...)	spa_loop_remove_source((l)->loop,__VA_ARGS__)
in define line 47 *)
(* error 
#define pw_loop_invoke(l,...)		spa_loop_invoke((l)->loop,__VA_ARGS__)
in define line 48 *)
    { was #define dname(params) para_def_expr }
    { argument types are unknown }
    { return type might be wrong }   
    function pw_loop_get_fd(l : longint) : longint;    

(* error 
#define pw_loop_add_hook(l,...)		spa_loop_control_add_hook((l)->control,__VA_ARGS__)
in define line 51 *)
    { was #define dname(params) para_def_expr }
    { argument types are unknown }
    { return type might be wrong }   
    function pw_loop_enter(l : longint) : longint;    

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_loop_leave(l : longint) : longint;  

(* error 
#define pw_loop_iterate(l,...)		spa_loop_control_iterate_fast((l)->control,__VA_ARGS__)
in define line 54 *)
(* error 
#define pw_loop_add_io(l,...)		spa_loop_utils_add_io((l)->utils,__VA_ARGS__)
in define line 56 *)
(* error 
#define pw_loop_update_io(l,...)	spa_loop_utils_update_io((l)->utils,__VA_ARGS__)
in define line 57 *)
(* error 
#define pw_loop_add_idle(l,...)		spa_loop_utils_add_idle((l)->utils,__VA_ARGS__)
in define line 58 *)
(* error 
#define pw_loop_enable_idle(l,...)	spa_loop_utils_enable_idle((l)->utils,__VA_ARGS__)
in define line 59 *)
(* error 
#define pw_loop_add_event(l,...)	spa_loop_utils_add_event((l)->utils,__VA_ARGS__)
in define line 60 *)
(* error 
#define pw_loop_signal_event(l,...)	spa_loop_utils_signal_event((l)->utils,__VA_ARGS__)
in define line 61 *)
(* error 
#define pw_loop_add_timer(l,...)	spa_loop_utils_add_timer((l)->utils,__VA_ARGS__)
in define line 62 *)
(* error 
#define pw_loop_update_timer(l,...)	spa_loop_utils_update_timer((l)->utils,__VA_ARGS__)
in define line 63 *)
(* error 
#define pw_loop_add_signal(l,...)	spa_loop_utils_add_signal((l)->utils,__VA_ARGS__)
in define line 64 *)
(* error 
#define pw_loop_destroy_source(l,...)	spa_loop_utils_destroy_source((l)->utils,__VA_ARGS__)
in define line 65 *)
    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_LOOP_H  }
    { was #define dname(params) para_def_expr }
    { argument types are unknown }
    { return type might be wrong }   
    function pw_loop_get_fd(l : longint) : longint;
    begin
      pw_loop_get_fd:=spa_loop_control_get_fd(l^.control);
    end;

    { was #define dname(params) para_def_expr }
    { argument types are unknown }
    { return type might be wrong }   
    function pw_loop_enter(l : longint) : longint;
    begin
      pw_loop_enter:=spa_loop_control_enter(l^.control);
    end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_loop_leave(l : longint) : longint;
  begin
    pw_loop_leave:=spa_loop_control_leave(l^.control);
  end;


