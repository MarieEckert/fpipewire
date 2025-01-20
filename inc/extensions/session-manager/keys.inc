{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2019 Collabora Ltd.  }
  {                         @author George Kiagiadakis <george.kiagiadakis@collabora.com>  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_EXT_SESSION_MANAGER_KEYS_H}
{$define PIPEWIRE_EXT_SESSION_MANAGER_KEYS_H}  
{ C++ extern C conditionnal removed }
  {*
   * \addtogroup pw_session_manager
   * \
    }
  {*< id of a session manager  }

  const
    PW_KEY_SESSION_ID = 'session.id';    
  {*< id of an endpoint  }
    PW_KEY_ENDPOINT_ID = 'endpoint.id';    
  {*< the name of an endpoint  }
    PW_KEY_ENDPOINT_NAME = 'endpoint.name';    
  {*< endpoint is monitor of given endpoint  }
    PW_KEY_ENDPOINT_MONITOR = 'endpoint.monitor';    
  {*< client of the endpoint  }
    PW_KEY_ENDPOINT_CLIENT_ID = 'endpoint.client.id';    
  {*< an XDG icon name for the device.
  								  *  Ex. "sound-card-speakers-usb"  }
    PW_KEY_ENDPOINT_ICON_NAME = 'endpoint.icon-name';    
  {*< try to automatically connect this
  								  *  endpoint.  }
    PW_KEY_ENDPOINT_AUTOCONNECT = 'endpoint.autoconnect';    
  {*< the suggested target to connect to  }
    PW_KEY_ENDPOINT_TARGET = 'endpoint.target';    
  {*< id of a stream  }
    PW_KEY_ENDPOINT_STREAM_ID = 'endpoint-stream.id';    
  {*< unique name of a stream  }
    PW_KEY_ENDPOINT_STREAM_NAME = 'endpoint-stream.name';    
  {*< description of a stream  }
    PW_KEY_ENDPOINT_STREAM_DESCRIPTION = 'endpoint-stream.description';    
  {*< output endpoint of link  }
    PW_KEY_ENDPOINT_LINK_OUTPUT_ENDPOINT = 'endpoint-link.output.endpoint';    
  {*< output stream of link  }
    PW_KEY_ENDPOINT_LINK_OUTPUT_STREAM = 'endpoint-link.output.stream';    
  {*< input endpoint of link  }
    PW_KEY_ENDPOINT_LINK_INPUT_ENDPOINT = 'endpoint-link.input.endpoint';    
  {*< input stream of link  }
    PW_KEY_ENDPOINT_LINK_INPUT_STREAM = 'endpoint-link.input.stream';    
  {*
   * \
    }
{ C++ end of extern C conditionnal removed }
{$endif}
  { PIPEWIRE_EXT_SESSION_MANAGER_KEYS_H  }

