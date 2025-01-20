
    { Pointers to basic pascal types, inserted by h2pas conversion program.}
    Type
      PLongint  = ^Longint;
      PSmallInt = ^SmallInt;
      PByte     = ^Byte;
      PWord     = ^Word;
      PDWord    = ^DWord;
      PDouble   = ^Double;

    Type
    Pspa_handle  = ^spa_handle;
    Pspa_support  = ^spa_support;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_H}
{$define PIPEWIRE_H}  
{ C++ extern C conditionnal removed }






























  {* \defgroup pw_pipewire Initialization
   * Initializing PipeWire and loading SPA modules.
    }
  {*
   * \addtogroup pw_pipewire
   * \
    }

  procedure pw_init(argc:pcint; argv:PPpcchar);cdecl;external;

  procedure pw_deinit;cdecl;external;

(* Const before type ignored *)
  function pw_debug_is_category_enabled(name:pcchar):bool;cdecl;external;

(* Const before type ignored *)
  function pw_get_application_name:pcchar;cdecl;external;

(* Const before type ignored *)
  function pw_get_prgname:pcchar;cdecl;external;

(* Const before type ignored *)
  function pw_get_user_name:pcchar;cdecl;external;

(* Const before type ignored *)
  function pw_get_host_name:pcchar;cdecl;external;

(* Const before type ignored *)
  function pw_get_client_name:pcchar;cdecl;external;

(* Const before type ignored *)
(* Const before type ignored *)
  function pw_check_option(option:pcchar; value:pcchar):bool;cdecl;external;

(* error 
pw_direction_reverse(enum pw_direction direction);
in declaration at line 78 *)
(* Const before type ignored *)
    function pw_set_domain(domain:pcchar):cint;cdecl;external;

(* Const before type ignored *)
    function pw_get_domain:pcchar;cdecl;external;

    function pw_get_support(support:Pspa_support; max_support:uint32_t):uint32_t;cdecl;external;

(* error 
struct spa_handle *pw_load_spa_handle(const char *lib,
in declaration at line 89 *)
    function pw_unload_spa_handle(handle:Pspa_handle):cint;cdecl;external;

    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_H  }

