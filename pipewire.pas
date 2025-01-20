{$mode fpc}
unit pipewire;

interface

uses ctypes;

{ Pointers to basic pascal types, inserted by h2pas conversion program.}
Type
  PLongint  = ^Longint;
  PSmallInt = ^SmallInt;
  PByte     = ^Byte;
  PWord     = ^Word;
  PDWord    = ^DWord;
  PDouble   = ^Double;
  uint8_t   = UInt8;
  uint16_t  = UInt16;
  uint32_t  = UInt32;
  int8_t    = Int8;
  int16_t   = Int16;
  int32_t   = Int32;
  size_t    = SizeUInt;
  ssize_t   = SizeInt;
  bool      = Boolean;

{$INCLUDE inc/data-loop.inc}
{$INCLUDE inc/map.inc}
{$INCLUDE inc/impl-device.inc}
{$INCLUDE inc/port.inc}
{$INCLUDE inc/global.inc}
{$INCLUDE inc/protocol.inc}
{$INCLUDE inc/i18n.inc}
{$INCLUDE inc/impl.inc}
{$INCLUDE inc/work-queue.inc}
{$INCLUDE inc/resource.inc}
{$INCLUDE inc/core.inc}
{$INCLUDE inc/node.inc}
{$INCLUDE inc/utils.inc}
{$INCLUDE inc/conf.inc}
{$INCLUDE inc/module.inc}
{$INCLUDE inc/log.inc}
{$INCLUDE inc/thread.inc}
{$INCLUDE inc/version.inc}
{$INCLUDE inc/mem.inc}
{$INCLUDE inc/type.inc}
{$INCLUDE inc/pipewire.inc}
{$INCLUDE inc/impl-factory.inc}
{$INCLUDE inc/device.inc}
{$INCLUDE inc/filter.inc}
{$INCLUDE inc/impl-node.inc}
{$INCLUDE inc/buffers.inc}
{$INCLUDE inc/client.inc}
{$INCLUDE inc/properties.inc}
{$INCLUDE inc/main-loop.inc}
{$INCLUDE inc/proxy.inc}
{$INCLUDE inc/stream.inc}
{$INCLUDE inc/factory.inc}
{$INCLUDE inc/impl-port.inc}
{$INCLUDE inc/impl-link.inc}
{$INCLUDE inc/impl-client.inc}
{$INCLUDE inc/loop.inc}
{$INCLUDE inc/impl-module.inc}
{$INCLUDE inc/thread-loop.inc}
{$INCLUDE inc/context.inc}
{$INCLUDE inc/impl-metadata.inc}
{$INCLUDE inc/impl-core.inc}
{$INCLUDE inc/permission.inc}
{$INCLUDE inc/control.inc}
{$INCLUDE inc/link.inc}
{$INCLUDE inc/keys.inc}
{$INCLUDE inc/extensions/security-context.inc}
{$INCLUDE inc/extensions/session-manager/introspect.inc}
{$INCLUDE inc/extensions/session-manager/interfaces.inc}
{$INCLUDE inc/extensions/session-manager/impl-interfaces.inc}
{$INCLUDE inc/extensions/session-manager/introspect-funcs.inc}
{$INCLUDE inc/extensions/session-manager/keys.inc}
{$INCLUDE inc/extensions/profiler.inc}
{$INCLUDE inc/extensions/session-manager.inc}
{$INCLUDE inc/extensions/protocol-native.inc}
{$INCLUDE inc/extensions/metadata.inc}
{$INCLUDE inc/extensions/client-node.inc}

implementation
end.
