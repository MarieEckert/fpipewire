    Type
    Pspa_type_info  = Pointer; {$WARNING ^spa_type_info}
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_TYPE_H}
{$define PIPEWIRE_TYPE_H}  
{ C++ extern C conditionnal removed }

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


    function pw_type_info:Pspa_type_info;cdecl;external External_library name 'pw_type_info';

    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_TYPE_H  }

