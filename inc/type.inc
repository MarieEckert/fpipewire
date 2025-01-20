
    { Pointers to basic pascal types, inserted by h2pas conversion program.}
    Type
      PLongint  = ^Longint;
      PSmallInt = ^SmallInt;
      PByte     = ^Byte;
      PWord     = ^Word;
      PDWord    = ^DWord;
      PDouble   = ^Double;

    Type
    Pspa_type_info  = ^spa_type_info;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_TYPE_H}
{$define PIPEWIRE_TYPE_H}  
{ C++ extern C conditionnal removed }
{$include <spa/utils/type.h>}
  {* \defgroup pw_type Type info
   * Type information
    }
  {*
   * \addtogroup pw_type
   * \
    }
(* error 
enum {
in declaration at line 25 *)

    const
      PW_TYPE_INFO_BASE = 'PipeWire:';      
(* error 
#define PW_TYPE_INFO_Object		PW_TYPE_INFO_BASE "Object"
in define line 29 *)
(* error 
#define PW_TYPE_INFO_OBJECT_BASE	PW_TYPE_INFO_Object ":"
in define line 30 *)
(* error 
#define PW_TYPE_INFO_Interface		PW_TYPE_INFO_BASE "Interface"
in define line 32 *)
(* error 
#define PW_TYPE_INFO_INTERFACE_BASE	PW_TYPE_INFO_Interface ":"
in define line 33 *)
(* Const before type ignored *)

    function pw_type_info:Pspa_type_info;cdecl;external;

    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_TYPE_H  }

