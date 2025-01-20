
    { Pointers to basic pascal types, inserted by h2pas conversion program.}
    Type
      PLongint  = ^Longint;
      PSmallInt = ^SmallInt;
      PByte     = ^Byte;
      PWord     = ^Word;
      PDWord    = ^DWord;
      PDouble   = ^Double;

    Type
    Ppw_impl_metadata  = ^pw_impl_metadata;
    Ppw_impl_metadata_events  = ^pw_impl_metadata_events;
    Ppw_metadata  = ^pw_metadata;
    Ppw_properties  = ^pw_properties;
    Pspa_hook  = ^spa_hook;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2021 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_IMPL_METADATA_H}
{$define PIPEWIRE_IMPL_METADATA_H}  
{ C++ extern C conditionnal removed }
  {* \defgroup pw_impl_metadata Metadata Impl
   *
   * The metadata is used to store key/type/value pairs per object id.
    }
  {*
   * \addtogroup pw_impl_metadata
   * \
    }

  type
    Ppw_impl_metadata = ^pw_impl_metadata;
    pw_impl_metadata = record
        {undefined structure}
      end;

{$include <pipewire/context.h>}
{$include <pipewire/impl-client.h>}
{$include <pipewire/global.h>}
{$include <pipewire/properties.h>}
{$include <pipewire/resource.h>}
{$include "pipewire/extensions/metadata.h"}
  {* Metadata events, listen to them with \ref pw_impl_metadata_add_listener  }
(* error 
#define PW_VERSION_IMPL_METADATA_EVENTS	0
  {* the metadata is destroyed  }
  {* the metadata is freed  }
  {* a property changed  }
 in member_list *)

  type
    Ppw_impl_metadata_events = ^pw_impl_metadata_events;
    pw_impl_metadata_events = record
      end;

(* error 
struct pw_impl_metadata *pw_context_create_metadata(struct pw_context *context,
in declaration at line 51 *)
    {* Get the metadata properties  }
(* Const before type ignored *)

    function pw_impl_metadata_get_properties(metadata:Ppw_impl_metadata):Ppw_properties;cdecl;external;

    function pw_impl_metadata_register(metadata:Ppw_impl_metadata; properties:Ppw_properties):cint;cdecl;external;

    procedure pw_impl_metadata_destroy(metadata:Ppw_impl_metadata);cdecl;external;

    function pw_impl_metadata_get_user_data(metadata:Ppw_impl_metadata):pointer;cdecl;external;

    function pw_impl_metadata_set_implementation(metadata:Ppw_impl_metadata; impl:Ppw_metadata):cint;cdecl;external;

(* error 
struct pw_metadata *pw_impl_metadata_get_implementation(struct pw_impl_metadata *metadata);
in declaration at line 66 *)
    {* Get the global of this metadata  }
(* error 
struct pw_global *pw_impl_metadata_get_global(struct pw_impl_metadata *metadata);
in declaration at line 69 *)
    {* Add an event listener  }
(* Const before type ignored *)
    procedure pw_impl_metadata_add_listener(metadata:Ppw_impl_metadata; listener:Pspa_hook; events:Ppw_impl_metadata_events; data:pointer);cdecl;external;

    {* Set a property  }
(* Const before type ignored *)
(* Const before type ignored *)
(* Const before type ignored *)
    function pw_impl_metadata_set_property(metadata:Ppw_impl_metadata; subject:uint32_t; key:pcchar; _type:pcchar; value:pcchar):cint;cdecl;external;

(* Const before type ignored *)
(* Const before type ignored *)
(* Const before type ignored *)
(* error 
			const char *fmt, ...) SPA_PRINTF_FUNC(5,6);
(* error 
			const char *fmt, ...) SPA_PRINTF_FUNC(5,6);
 in declarator_list *)
 in declarator_list *)
    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_IMPL_METADATA_H  }

