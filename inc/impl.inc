
  { Pointers to basic pascal types, inserted by h2pas conversion program.}
  Type
    PLongint  = ^Longint;
    PSmallInt = ^SmallInt;
    PByte     = ^Byte;
    PWord     = ^Word;
    PDWord    = ^DWord;
    PDouble   = ^Double;

  Type
  Ppw_global  = ^pw_global;
  Ppw_impl_client  = ^pw_impl_client;
  Ppw_impl_module  = ^pw_impl_module;
  Ppw_impl_port  = ^pw_impl_port;
  Ppw_node  = ^pw_node;
  Ppw_resource  = ^pw_resource;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2019 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_IMPL_H}
{$define PIPEWIRE_IMPL_H}  
{ C++ extern C conditionnal removed }
  {*
   * \addtogroup api_pw_impl
    }

  type
    Ppw_impl_client = ^pw_impl_client;
    pw_impl_client = record
        {undefined structure}
      end;

    Ppw_impl_module = ^pw_impl_module;
    pw_impl_module = record
        {undefined structure}
      end;

    Ppw_global = ^pw_global;
    pw_global = record
        {undefined structure}
      end;

    Ppw_node = ^pw_node;
    pw_node = record
        {undefined structure}
      end;

    Ppw_impl_port = ^pw_impl_port;
    pw_impl_port = record
        {undefined structure}
      end;

    Ppw_resource = ^pw_resource;
    pw_resource = record
        {undefined structure}
      end;

{$include <pipewire/pipewire.h>}
{$include <pipewire/control.h>}
{$include <pipewire/impl-core.h>}
{$include <pipewire/impl-client.h>}
{$include <pipewire/impl-device.h>}
{$include <pipewire/impl-factory.h>}
{$include <pipewire/global.h>}
{$include <pipewire/impl-link.h>}
{$include <pipewire/impl-metadata.h>}
{$include <pipewire/impl-module.h>}
{$include <pipewire/impl-node.h>}
{$include <pipewire/impl-port.h>}
{$include <pipewire/resource.h>}
{$include <pipewire/work-queue.h>}
{ C++ end of extern C conditionnal removed }
{$endif}
  { PIPEWIRE_IMPL_H  }

