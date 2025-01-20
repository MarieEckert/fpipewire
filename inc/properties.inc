    Type
    Pspa_error_location  = Pointer; {$WARNING ^spa_error_location}
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_PROPERTIES_H}
{$define PIPEWIRE_PROPERTIES_H}  
{ C++ extern C conditionnal removed }




  {* \defgroup pw_properties Properties
   *
   * Properties are used to pass around arbitrary key/value pairs.
   * Both keys and values are strings which keeps things simple.
   * Encoding of arbitrary values should be done by using a string
   * serialization such as base64 for binary blobs.
    }
  {*
   * \addtogroup pw_properties
   * \
    }
  {*< dictionary of key/values  }
  {*< extra flags  }

  type
    Ppw_properties = ^pw_properties;
    pw_properties = record
        dict : spa_dict;
        flags : uint32_t;
      end;

(* error 
struct pw_properties *
in declaration at line 36 *)
(* error 
struct pw_properties *
in declaration at line 39 *)
(* error 
struct pw_properties *
in declaration at line 42 *)
(* error 
struct pw_properties *
in declaration at line 46 *)
(* error 
struct pw_properties *
in declaration at line 49 *)


(* Const before declarator ignored *)

    function pw_properties_update_keys(props:Ppw_properties; dict:Pspa_dict; keys:Ppcchar):cint;cdecl;external External_library name 'pw_properties_update_keys';



(* Const before declarator ignored *)
    function pw_properties_update_ignore(props:Ppw_properties; dict:Pspa_dict; ignore:Ppcchar):cint;cdecl;external External_library name 'pw_properties_update_ignore';

    { Update props with all key/value pairs from dict  }

    function pw_properties_update(props:Ppw_properties; dict:Pspa_dict):cint;cdecl;external External_library name 'pw_properties_update';

    { Update props with all key/value pairs from str  }

    function pw_properties_update_string(props:Ppw_properties; str:pcchar; size:size_t):cint;cdecl;external External_library name 'pw_properties_update_string';


    function pw_properties_update_string_checked(props:Ppw_properties; str:pcchar; size:size_t; loc:Pspa_error_location):cint;cdecl;external External_library name 'pw_properties_update_string_checked';


    function pw_properties_add(oldprops:Ppw_properties; dict:Pspa_dict):cint;cdecl;external External_library name 'pw_properties_add';



(* Const before declarator ignored *)
    function pw_properties_add_keys(oldprops:Ppw_properties; dict:Pspa_dict; keys:Ppcchar):cint;cdecl;external External_library name 'pw_properties_add_keys';

    procedure pw_properties_clear(properties:Ppw_properties);cdecl;external External_library name 'pw_properties_clear';

    procedure pw_properties_free(properties:Ppw_properties);cdecl;external External_library name 'pw_properties_free';



    function pw_properties_set(properties:Ppw_properties; key:pcchar; value:pcchar):cint;cdecl;external External_library name 'pw_properties_set';



(* error 
		   const char *key, const char *format, ...) SPA_PRINTF_FUNC(3, 4);
(* error 
		   const char *key, const char *format, ...) SPA_PRINTF_FUNC(3, 4);
 in declarator_list *)
 in declarator_list *)


(* error 
		   const char *key, const char *format, va_list args) SPA_PRINTF_FUNC(3,0);
(* error 
		   const char *key, const char *format, va_list args) SPA_PRINTF_FUNC(3,0);
 in declarator_list *)
 in declarator_list *)



    function pw_properties_get(properties:Ppw_properties; key:pcchar):pcchar;cdecl;external External_library name 'pw_properties_get';



    function pw_properties_fetch_uint32(properties:Ppw_properties; key:pcchar; value:Puint32_t):cint;cdecl;external External_library name 'pw_properties_fetch_uint32';



    function pw_properties_fetch_int32(properties:Ppw_properties; key:pcchar; value:Pint32_t):cint;cdecl;external External_library name 'pw_properties_fetch_int32';



    function pw_properties_fetch_uint64(properties:Ppw_properties; key:pcchar; value:Puint64_t):cint;cdecl;external External_library name 'pw_properties_fetch_uint64';



    function pw_properties_fetch_int64(properties:Ppw_properties; key:pcchar; value:Pint64_t):cint;cdecl;external External_library name 'pw_properties_fetch_int64';



    function pw_properties_fetch_bool(properties:Ppw_properties; key:pcchar; value:Pbool):cint;cdecl;external External_library name 'pw_properties_fetch_bool';

    const
      PW_PROPERTIES_FLAG_NL = 1 shl 0;      
      PW_PROPERTIES_FLAG_RECURSE = 1 shl 1;      
      PW_PROPERTIES_FLAG_ENCLOSE = 1 shl 2;      
      PW_PROPERTIES_FLAG_ARRAY = 1 shl 3;      
      PW_PROPERTIES_FLAG_COLORS = 1 shl 4;      


    function pw_properties_serialize_dict(f:PFILE; dict:Pspa_dict; flags:uint32_t):cint;cdecl;external External_library name 'pw_properties_serialize_dict';

{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_PROPERTIES_H  }

