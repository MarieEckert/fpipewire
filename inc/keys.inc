
  { Pointers to basic pascal types, inserted by h2pas conversion program.}
  Type
    PLongint  = ^Longint;
    PSmallInt = ^SmallInt;
    PByte     = ^Byte;
    PWord     = ^Word;
    PDWord    = ^DWord;
    PDouble   = ^Double;

{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2019 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_KEYS_H}
{$define PIPEWIRE_KEYS_H}  
{ C++ extern C conditionnal removed }

  {*
   * \defgroup pw_keys Key Names
   *
   * A collection of keys that are used to add extra information on objects.
   *
   * Keys that start with "pipewire." are in general set-once and then
   * read-only. They are usually used for security sensitive information that
   * needs to be fixed.
   *
   * Properties from other objects can also appear. This usually suggests some
   * sort of parent/child or owner/owned relationship.
   *
   * \addtogroup pw_keys
   * \
    }
  {*< protocol used for connection  }

  const
    PW_KEY_PROTOCOL = 'pipewire.protocol';    
  {*< how the client access is controlled  }
    PW_KEY_ACCESS = 'pipewire.access';    
  {*< how the client wants to be access
  								  *  controlled  }
    PW_KEY_CLIENT_ACCESS = 'pipewire.client.access';    
  {* Various keys related to the identity of a client process and its security.
   * Must be obtained from trusted sources by the protocol and placed as
   * read-only properties.  }
  {*< Client pid, set by protocol  }
    PW_KEY_SEC_PID = 'pipewire.sec.pid';    
  {*< Client uid, set by protocol }
    PW_KEY_SEC_UID = 'pipewire.sec.uid';    
  {*< client gid, set by protocol }
    PW_KEY_SEC_GID = 'pipewire.sec.gid';    
  {*< client security label, set by protocol }
    PW_KEY_SEC_LABEL = 'pipewire.sec.label';    
  {*< client socket name, set by protocol  }
    PW_KEY_SEC_SOCKET = 'pipewire.sec.socket';    
  {*< client secure context engine, set by protocol.
  								  *  This can also be set by a client when making a
  								  *  new security context.  }
    PW_KEY_SEC_ENGINE = 'pipewire.sec.engine';    
  {*< client secure application id  }
    PW_KEY_SEC_APP_ID = 'pipewire.sec.app-id';    
  {*< client secure instance id  }
    PW_KEY_SEC_INSTANCE_ID = 'pipewire.sec.instance-id';    
  {*< name of the system library to use  }
    PW_KEY_LIBRARY_NAME_SYSTEM = 'library.name.system';    
  {*< name of the loop library to use  }
    PW_KEY_LIBRARY_NAME_LOOP = 'library.name.loop';    
  {*< name of the dbus library to use  }
    PW_KEY_LIBRARY_NAME_DBUS = 'library.name.dbus';    
  {* object properties  }
  {*< unique path to construct the object  }
    PW_KEY_OBJECT_PATH = 'object.path';    
  {*< a global object id  }
    PW_KEY_OBJECT_ID = 'object.id';    
  {*< a 64 bit object serial number. This is a number
  								  *  incremented for each object that is created.
  								  *  The lower 32 bits are guaranteed to never be
  								  *  SPA_ID_INVALID.  }
    PW_KEY_OBJECT_SERIAL = 'object.serial';    
  {*< the object lives on even after the client
  								  *  that created it has been destroyed  }
    PW_KEY_OBJECT_LINGER = 'object.linger';    
  {*< If the object should be registered.  }
    PW_KEY_OBJECT_REGISTER = 'object.register';    
  {*< If the object should be exported,
  								  *  since 0.3.72  }
    PW_KEY_OBJECT_EXPORT = 'object.export';    
  { config  }
  {*< a config prefix directory  }
    PW_KEY_CONFIG_PREFIX = 'config.prefix';    
  {*< a config file name  }
    PW_KEY_CONFIG_NAME = 'config.name';    
  {*< a config override prefix directory  }
    PW_KEY_CONFIG_OVERRIDE_PREFIX = 'config.override.prefix';    
  {*< a config override file name  }
    PW_KEY_CONFIG_OVERRIDE_NAME = 'config.override.name';    
  { loop  }
  {*< the name of a loop  }
    PW_KEY_LOOP_NAME = 'loop.name';    
  {*< the classes this loop handles, array of strings  }
    PW_KEY_LOOP_CLASS = 'loop.class';    
  {*< realtime priority of the loop  }
    PW_KEY_LOOP_RT_PRIO = 'loop.rt-prio';    
  {*< if the loop can be canceled  }
    PW_KEY_LOOP_CANCEL = 'loop.cancel';    
  { context  }
  {*< a context profile for modules, deprecated  }
    PW_KEY_CONTEXT_PROFILE_MODULES = 'context.profile.modules';    
  {*< The user name that runs pipewire  }
    PW_KEY_USER_NAME = 'context.user-name';    
  {*< The host name of the machine  }
    PW_KEY_HOST_NAME = 'context.host-name';    
  { core  }
  {*< The name of the core. Default is
  								  *  `pipewire-<username>-<pid>`, overwritten
  								  *  by env(PIPEWIRE_CORE)  }
    PW_KEY_CORE_NAME = 'core.name';    
  {*< The version of the core.  }
    PW_KEY_CORE_VERSION = 'core.version';    
  {*< If the core is listening for connections.  }
    PW_KEY_CORE_DAEMON = 'core.daemon';    
  {*< the core id  }
    PW_KEY_CORE_ID = 'core.id';    
  {*< the apis monitored by core.  }
    PW_KEY_CORE_MONITORS = 'core.monitors';    
  { cpu  }
  {*< maximum alignment needed to support
  								  *  all CPU optimizations  }
    PW_KEY_CPU_MAX_ALIGN = 'cpu.max-align';    
  {*< number of cores  }
    PW_KEY_CPU_CORES = 'cpu.cores';    
  { priorities  }
  {*< priority in session manager  }
    PW_KEY_PRIORITY_SESSION = 'priority.session';    
  {*< priority to be a driver  }
    PW_KEY_PRIORITY_DRIVER = 'priority.driver';    
  { remote keys  }
  {*< The name of the remote to connect to,
  								  *  default pipewire-0, overwritten by
  								  *  env(PIPEWIRE_REMOTE). May also be
  								  *  a SPA-JSON array of sockets, to be tried
  								  *  in order.  }
    PW_KEY_REMOTE_NAME = 'remote.name';    
  {*< The intention of the remote connection,
  								  *  "generic", "screencast"  }
    PW_KEY_REMOTE_INTENTION = 'remote.intention';    
  {* application keys  }
  {*< application name. Ex: "Totem Music Player"  }
    PW_KEY_APP_NAME = 'application.name';    
  {*< a textual id for identifying an
  								  *  application logically. Ex: "org.gnome.Totem"  }
    PW_KEY_APP_ID = 'application.id';    
  {*< application version. Ex: "1.2.0"  }
    PW_KEY_APP_VERSION = 'application.version';    
  {*< aa base64 blob with PNG image data  }
    PW_KEY_APP_ICON = 'application.icon';    
  {*< an XDG icon name for the application.
  								  *  Ex: "totem"  }
    PW_KEY_APP_ICON_NAME = 'application.icon-name';    
  {*< application language if applicable, in
  								  *  standard POSIX format. Ex: "en_GB"  }
    PW_KEY_APP_LANGUAGE = 'application.language';    
  {*< process id  (pid) }
    PW_KEY_APP_PROCESS_ID = 'application.process.id';    
  {*< binary name  }
    PW_KEY_APP_PROCESS_BINARY = 'application.process.binary';    
  {*< user name  }
    PW_KEY_APP_PROCESS_USER = 'application.process.user';    
  {*< host name  }
    PW_KEY_APP_PROCESS_HOST = 'application.process.host';    
  {*< the D-Bus host id the
  									   *  application runs on  }
    PW_KEY_APP_PROCESS_MACHINE_ID = 'application.process.machine-id';    
  {*< login session of the
  									   *  application, on Unix the
  									   *  value of $XDG_SESSION_ID.  }
    PW_KEY_APP_PROCESS_SESSION_ID = 'application.process.session-id';    
  {* window system  }
  {*< the X11 display string. Ex. ":0.0"  }
    PW_KEY_WINDOW_X11_DISPLAY = 'window.x11.display';    
  {* Client properties  }
  {*< a client id  }
    PW_KEY_CLIENT_ID = 'client.id';    
  {*< the client name  }
    PW_KEY_CLIENT_NAME = 'client.name';    
  {*< the client api used to access
  								  *  PipeWire  }
    PW_KEY_CLIENT_API = 'client.api';    
  {* Node keys  }
  {*< node id  }
    PW_KEY_NODE_ID = 'node.id';    
  {*< node name  }
    PW_KEY_NODE_NAME = 'node.name';    
  {*< short node name  }
    PW_KEY_NODE_NICK = 'node.nick';    
  {*< localized human readable node one-line
  								  *  description. Ex. "Foobar USB Headset"  }
    PW_KEY_NODE_DESCRIPTION = 'node.description';    
  {*< when the node was created. As a uint64 in
  								  *  nanoseconds.  }
    PW_KEY_NODE_PLUGGED = 'node.plugged';    
  {*< the session id this node is part of  }
    PW_KEY_NODE_SESSION = 'node.session';    
  {*< the group id this node is part of. Nodes
  								  *  in the same group are always scheduled
  								  *  with the same driver. Can be an array of
  								  *  group names.  }
    PW_KEY_NODE_GROUP = 'node.group';    
  {*< the sync group this node is part of. Nodes
  								  *  in the same sync group are always scheduled
  								  *  together with the same driver when the sync
  								  *  is active. Can be an array of sync names.  }
    PW_KEY_NODE_SYNC_GROUP = 'node.sync-group';    
  {*< if the sync-group is active or not  }
    PW_KEY_NODE_SYNC = 'node.sync';    
  {*< if the transport is active or not  }
    PW_KEY_NODE_TRANSPORT = 'node.transport';    
  {*< node wants exclusive access to resources  }
    PW_KEY_NODE_EXCLUSIVE = 'node.exclusive';    
  {*< node wants to be automatically connected
  								  *  to a compatible node  }
    PW_KEY_NODE_AUTOCONNECT = 'node.autoconnect';    
  {*< the requested latency of the node as
  								  *  a fraction. Ex: 128/48000  }
    PW_KEY_NODE_LATENCY = 'node.latency';    
  {*< the maximum supported latency of the
  								  *  node as a fraction. Ex: 1024/48000  }
    PW_KEY_NODE_MAX_LATENCY = 'node.max-latency';    
  {*< don't change quantum when this node
  								  *  is active  }
    PW_KEY_NODE_LOCK_QUANTUM = 'node.lock-quantum';    
  {*< force a quantum while the node is
  								  *  active  }
    PW_KEY_NODE_FORCE_QUANTUM = 'node.force-quantum';    
  {*< the requested rate of the graph as
  								  *  a fraction. Ex: 1/48000  }
    PW_KEY_NODE_RATE = 'node.rate';    
  {*< don't change rate when this node
  								  *  is active  }
    PW_KEY_NODE_LOCK_RATE = 'node.lock-rate';    
  {*< force a rate while the node is
  								  *  active. A value of 0 takes the denominator
  								  *  of node.rate  }
    PW_KEY_NODE_FORCE_RATE = 'node.force-rate';    
  {*< don't reconnect this node. The node is
  								  *  initially linked to target.object or the
  								  *  default node. If the target is removed,
  								  *  the node is destroyed  }
    PW_KEY_NODE_DONT_RECONNECT = 'node.dont-reconnect';    
  {*< process even when unlinked  }
    PW_KEY_NODE_ALWAYS_PROCESS = 'node.always-process';    
  {*< the node wants to be grouped with a driver
  								  *  node in order to schedule the graph.  }
    PW_KEY_NODE_WANT_DRIVER = 'node.want-driver';    
  {*< pause the node when idle  }
    PW_KEY_NODE_PAUSE_ON_IDLE = 'node.pause-on-idle';    
  {*< suspend the node when idle  }
    PW_KEY_NODE_SUSPEND_ON_IDLE = 'node.suspend-on-idle';    
  {*< cache the node params  }
    PW_KEY_NODE_CACHE_PARAMS = 'node.cache-params';    
  {*< the node handles transport sync  }
    PW_KEY_NODE_TRANSPORT_SYNC = 'node.transport.sync';    
  {*< node can drive the graph. When the node is
  								  *  selected as the driver, it needs to start
  								  *  the graph periodically.  }
    PW_KEY_NODE_DRIVER = 'node.driver';    
  {*< the node can be a lazy driver. It will listen
  								  *  to RequestProcess commands and take them into
  								  *  account when deciding to start the graph.
  								  *  A value of 0 disables support, a value of > 0
  								  *  enables with increasing preference.  }
    PW_KEY_NODE_SUPPORTS_LAZY = 'node.supports-lazy';    
  {*< The node supports emiting RequestProcess events
  								  *  when it wants the graph to be scheduled.
  								  *  A value of 0 disables support, a value of > 0
  								  *  enables with increasing preference.  }
    PW_KEY_NODE_SUPPORTS_REQUEST = 'node.supports-request';    
  {*< the node id of the node assigned as driver
  								  *   for this node  }
    PW_KEY_NODE_DRIVER_ID = 'node.driver-id';    
  {*< the node wants async scheduling  }
    PW_KEY_NODE_ASYNC = 'node.async';    
  {*< the loop name fnmatch pattern to run in  }
    PW_KEY_NODE_LOOP_NAME = 'node.loop.name';    
  {*< the loop class fnmatch pattern to run in  }
    PW_KEY_NODE_LOOP_CLASS = 'node.loop.class';    
  {*< node is a stream, the server side should
  								  *  add a converter  }
    PW_KEY_NODE_STREAM = 'node.stream';    
  {*< the node is some sort of virtual
  								  *  object  }
    PW_KEY_NODE_VIRTUAL = 'node.virtual';    
  {*< indicate that a node wants passive links
  								  *  on output/input/all ports when the value is
  								  *  "out"/"in"/"true" respectively  }
    PW_KEY_NODE_PASSIVE = 'node.passive';    
  {*< the node is internally linked to
  								  *  nodes with the same link-group. Can be an
  								  *  array of group names.  }
    PW_KEY_NODE_LINK_GROUP = 'node.link-group';    
  {*< the node is on a network  }
    PW_KEY_NODE_NETWORK = 'node.network';    
  {*< the node is not scheduled automatically
  								  *   based on the dependencies in the graph
  								  *   but it will be triggered explicitly.  }
    PW_KEY_NODE_TRIGGER = 'node.trigger';    
  {*< names of node's
  								*   channels (unrelated to positions)  }
    PW_KEY_NODE_CHANNELNAMES = 'node.channel-names';    
  {*< override port name prefix for
  									  *  device ports, like capture and
  									  *  playback or disable the prefix
  									  *  completely if an empty string
  									  *  is provided  }
    PW_KEY_NODE_DEVICE_PORT_NAME_PREFIX = 'node.device-port-name-prefix';    
  {* Port keys  }
  {*< port id  }
    PW_KEY_PORT_ID = 'port.id';    
  {*< port name  }
    PW_KEY_PORT_NAME = 'port.name';    
  {*< the port direction, one of "in" or "out"
  								  *  or "control" and "notify" for control ports  }
    PW_KEY_PORT_DIRECTION = 'port.direction';    
  {*< port alias  }
    PW_KEY_PORT_ALIAS = 'port.alias';    
  {*< if this is a physical port  }
    PW_KEY_PORT_PHYSICAL = 'port.physical';    
  {*< if this port consumes the data  }
    PW_KEY_PORT_TERMINAL = 'port.terminal';    
  {*< if this port is a control port  }
    PW_KEY_PORT_CONTROL = 'port.control';    
  {*< if this port is a monitor port  }
    PW_KEY_PORT_MONITOR = 'port.monitor';    
  {*< cache the node port params  }
    PW_KEY_PORT_CACHE_PARAMS = 'port.cache-params';    
  {*< api specific extra port info, API name
  								  *  should be prefixed. "jack:flags:56"  }
    PW_KEY_PORT_EXTRA = 'port.extra';    
  {*< the ports wants passive links, since 0.3.67  }
    PW_KEY_PORT_PASSIVE = 'port.passive';    
  {*< latency ignored by peers, since 0.3.71  }
    PW_KEY_PORT_IGNORE_LATENCY = 'port.ignore-latency';    
  {*< the port group of the port 1.2.0  }
    PW_KEY_PORT_GROUP = 'port.group';    
  {* link properties  }
  {*< a link id  }
    PW_KEY_LINK_ID = 'link.id';    
  {*< input node id of a link  }
    PW_KEY_LINK_INPUT_NODE = 'link.input.node';    
  {*< input port id of a link  }
    PW_KEY_LINK_INPUT_PORT = 'link.input.port';    
  {*< output node id of a link  }
    PW_KEY_LINK_OUTPUT_NODE = 'link.output.node';    
  {*< output port id of a link  }
    PW_KEY_LINK_OUTPUT_PORT = 'link.output.port';    
  {*< indicate that a link is passive and
  								  *  does not cause the graph to be
  								  *  runnable.  }
    PW_KEY_LINK_PASSIVE = 'link.passive';    
  {*< indicate that a link is a feedback
  								  *  link and the target will receive data
  								  *  in the next cycle  }
    PW_KEY_LINK_FEEDBACK = 'link.feedback';    
  {*< the link is using async io  }
    PW_KEY_LINK_ASYNC = 'link.async';    
  {* device properties  }
  {*< device id  }
    PW_KEY_DEVICE_ID = 'device.id';    
  {*< device name  }
    PW_KEY_DEVICE_NAME = 'device.name';    
  {*< when the device was created. As a uint64 in
  								  *  nanoseconds.  }
    PW_KEY_DEVICE_PLUGGED = 'device.plugged';    
  {*< a short device nickname  }
    PW_KEY_DEVICE_NICK = 'device.nick';    
  {*< device string in the underlying layer's
  								  *  format. Ex. "surround51:0"  }
    PW_KEY_DEVICE_STRING = 'device.string';    
  {*< API this device is accessed with.
  								  *  Ex. "alsa", "v4l2"  }
    PW_KEY_DEVICE_API = 'device.api';    
  {*< localized human readable device one-line
  								  *  description. Ex. "Foobar USB Headset"  }
    PW_KEY_DEVICE_DESCRIPTION = 'device.description';    
  {*< bus path to the device in the OS'
  								  *  format. Ex. "pci-0000:00:14.0-usb-0:3.2:1.0"  }
    PW_KEY_DEVICE_BUS_PATH = 'device.bus-path';    
  {*< Serial number if applicable  }
    PW_KEY_DEVICE_SERIAL = 'device.serial';    
  {*< vendor ID if applicable  }
    PW_KEY_DEVICE_VENDOR_ID = 'device.vendor.id';    
  {*< vendor name if applicable  }
    PW_KEY_DEVICE_VENDOR_NAME = 'device.vendor.name';    
  {*< product ID if applicable  }
    PW_KEY_DEVICE_PRODUCT_ID = 'device.product.id';    
  {*< product name if applicable  }
    PW_KEY_DEVICE_PRODUCT_NAME = 'device.product.name';    
  {*< device class  }
    PW_KEY_DEVICE_CLASS = 'device.class';    
  {*< form factor if applicable. One of
  								  *  "internal", "speaker", "handset", "tv",
  								  *  "webcam", "microphone", "headset",
  								  *  "headphone", "hands-free", "car", "hifi",
  								  *  "computer", "portable"  }
    PW_KEY_DEVICE_FORM_FACTOR = 'device.form-factor';    
  {*< bus of the device if applicable. One of
  								  *  "isa", "pci", "usb", "firewire",
  								  *  "bluetooth"  }
    PW_KEY_DEVICE_BUS = 'device.bus';    
  {*< device subsystem  }
    PW_KEY_DEVICE_SUBSYSTEM = 'device.subsystem';    
  {*< device sysfs path  }
    PW_KEY_DEVICE_SYSFS_PATH = 'device.sysfs.path';    
  {*< icon for the device. A base64 blob
  								  *  containing PNG image data  }
    PW_KEY_DEVICE_ICON = 'device.icon';    
  {*< an XDG icon name for the device.
  								  *  Ex. "sound-card-speakers-usb"  }
    PW_KEY_DEVICE_ICON_NAME = 'device.icon-name';    
  {*< intended use. A space separated list of
  								  *  roles (see PW_KEY_MEDIA_ROLE) this device
  								  *  is particularly well suited for, due to
  								  *  latency, quality or form factor.  }
    PW_KEY_DEVICE_INTENDED_ROLES = 'device.intended-roles';    
  {*< cache the device spa params  }
    PW_KEY_DEVICE_CACHE_PARAMS = 'device.cache-params';    
  {* module properties  }
  {*< the module id  }
    PW_KEY_MODULE_ID = 'module.id';    
  {*< the name of the module  }
    PW_KEY_MODULE_NAME = 'module.name';    
  {*< the author's name  }
    PW_KEY_MODULE_AUTHOR = 'module.author';    
  {*< a human readable one-line description
  								  *  of the module's purpose. }
    PW_KEY_MODULE_DESCRIPTION = 'module.description';    
  {*< a human readable usage description of
  								  *  the module's arguments.  }
    PW_KEY_MODULE_USAGE = 'module.usage';    
  {*< a version string for the module.  }
    PW_KEY_MODULE_VERSION = 'module.version';    
  {*< the module is deprecated with this message  }
    PW_KEY_MODULE_DEPRECATED = 'module.deprecated';    
  {* Factory properties  }
  {*< the factory id  }
    PW_KEY_FACTORY_ID = 'factory.id';    
  {*< the name of the factory  }
    PW_KEY_FACTORY_NAME = 'factory.name';    
  {*< the usage of the factory  }
    PW_KEY_FACTORY_USAGE = 'factory.usage';    
  {*< the name of the type created by a factory  }
    PW_KEY_FACTORY_TYPE_NAME = 'factory.type.name';    
  {*< the version of the type created by a factory  }
    PW_KEY_FACTORY_TYPE_VERSION = 'factory.type.version';    
  {* Stream properties  }
  {*< Indicates that the stream is live.  }
    PW_KEY_STREAM_IS_LIVE = 'stream.is-live';    
  {*< The minimum latency of the stream.  }
    PW_KEY_STREAM_LATENCY_MIN = 'stream.latency.min';    
  {*< The maximum latency of the stream  }
    PW_KEY_STREAM_LATENCY_MAX = 'stream.latency.max';    
  {*< Indicates that the stream is monitoring
  								  *  and might select a less accurate but faster
  								  *  conversion algorithm. Monitor streams are also
  								  *  ignored when calculating the latency of their peer
  								  *  ports (since 0.3.71).
  								   }
    PW_KEY_STREAM_MONITOR = 'stream.monitor';    
  {*< don't remix channels  }
    PW_KEY_STREAM_DONT_REMIX = 'stream.dont-remix';    
  {*< Try to capture the sink output instead of
  								  *  source output  }
    PW_KEY_STREAM_CAPTURE_SINK = 'stream.capture.sink';    
  {* Media  }
  {*< Media type, one of
  								  *  Audio, Video, Midi  }
    PW_KEY_MEDIA_TYPE = 'media.type';    
  {*< Media Category:
  								  *  Playback, Capture, Duplex, Monitor, Manager  }
    PW_KEY_MEDIA_CATEGORY = 'media.category';    
  {*< Role: Movie, Music, Camera,
  								  *  Screen, Communication, Game,
  								  *  Notification, DSP, Production,
  								  *  Accessibility, Test  }
    PW_KEY_MEDIA_ROLE = 'media.role';    
  {*< class Ex: "Video/Source"  }
    PW_KEY_MEDIA_CLASS = 'media.class';    
  {*< media name. Ex: "Pink Floyd: Time"  }
    PW_KEY_MEDIA_NAME = 'media.name';    
  {*< title. Ex: "Time"  }
    PW_KEY_MEDIA_TITLE = 'media.title';    
  {*< artist. Ex: "Pink Floyd"  }
    PW_KEY_MEDIA_ARTIST = 'media.artist';    
  {*< album. Ex: "Dark Side of the Moon"  }
    PW_KEY_MEDIA_ALBUM = 'media.album';    
  {*< copyright string  }
    PW_KEY_MEDIA_COPYRIGHT = 'media.copyright';    
  {*< generator software  }
    PW_KEY_MEDIA_SOFTWARE = 'media.software';    
  {*< language in POSIX format. Ex: en_GB  }
    PW_KEY_MEDIA_LANGUAGE = 'media.language';    
  {*< filename  }
    PW_KEY_MEDIA_FILENAME = 'media.filename';    
  {*< icon for the media, a base64 blob with
  								  *  PNG image data  }
    PW_KEY_MEDIA_ICON = 'media.icon';    
  {*< an XDG icon name for the media.
  								  *  Ex: "audio-x-mp3"  }
    PW_KEY_MEDIA_ICON_NAME = 'media.icon-name';    
  {*< extra comment  }
    PW_KEY_MEDIA_COMMENT = 'media.comment';    
  {*< date of the media  }
    PW_KEY_MEDIA_DATE = 'media.date';    
  {*< format of the media  }
    PW_KEY_MEDIA_FORMAT = 'media.format';    
  {* format related properties  }
  {*< a dsp format.
  								  *  Ex: "32 bit float mono audio"  }
    PW_KEY_FORMAT_DSP = 'format.dsp';    
  {* audio related properties  }
  {*< an audio channel. Ex: "FL"  }
    PW_KEY_AUDIO_CHANNEL = 'audio.channel';    
  {*< an audio samplerate  }
    PW_KEY_AUDIO_RATE = 'audio.rate';    
  {*< number of audio channels  }
    PW_KEY_AUDIO_CHANNELS = 'audio.channels';    
  {*< an audio format. Ex: "S16LE"  }
    PW_KEY_AUDIO_FORMAT = 'audio.format';    
  {*< a list of allowed samplerates
  								  *  ex. "[ 44100 48000 ]"  }
    PW_KEY_AUDIO_ALLOWED_RATES = 'audio.allowed-rates';    
  {* video related properties  }
  {*< a video framerate  }
    PW_KEY_VIDEO_RATE = 'video.framerate';    
  {*< a video format  }
    PW_KEY_VIDEO_FORMAT = 'video.format';    
  {*< a video size as "<width>x<height"  }
    PW_KEY_VIDEO_SIZE = 'video.size';    
  {*< a target object to link to. This can be
  								  * and object name or object.serial  }
    PW_KEY_TARGET_OBJECT = 'target.object';    
{$ifndef PW_REMOVE_DEPRECATED}
{$ifdef PW_ENABLE_DEPRECATED}
  {*< deprecated, use priority.driver  }

  const
    PW_KEY_PRIORITY_MASTER = 'priority.master';    
  {*< deprecated since 0.3.64, use target.object.  }
    PW_KEY_NODE_TARGET = 'node.target';    
  {*< deprecated since 1.3.0  }
    PW_KEY_LOOP_RETRY_TIMEOUT = 'loop.retry-timeout';    
{$else}

  { was #define dname def_expr }
  function PW_KEY_PRIORITY_MASTER : longint; { return type might be wrong }

  { was #define dname def_expr }
  function PW_KEY_NODE_TARGET : longint; { return type might be wrong }

  { was #define dname def_expr }
  function PW_KEY_LOOP_RETRY_TIMEOUT : longint; { return type might be wrong }

{$endif}
  { PW_ENABLE_DEPRECATED  }
{$endif}
  { PW_REMOVE_DEPRECATED  }
  {* \
    }
{ C++ end of extern C conditionnal removed }
{$endif}
  { PIPEWIRE_KEYS_H  }
  { was #define dname def_expr }
  function PW_KEY_PRIORITY_MASTER : longint; { return type might be wrong }
    begin
      PW_KEY_PRIORITY_MASTER:=PW_DEPRECATED('priority.master');
    end;

  { was #define dname def_expr }
  function PW_KEY_NODE_TARGET : longint; { return type might be wrong }
    begin
      PW_KEY_NODE_TARGET:=PW_DEPRECATED('node.target');
    end;

  { was #define dname def_expr }
  function PW_KEY_LOOP_RETRY_TIMEOUT : longint; { return type might be wrong }
    begin
      PW_KEY_LOOP_RETRY_TIMEOUT:=PW_DEPRECATED('loop.retry-timeout');
    end;


