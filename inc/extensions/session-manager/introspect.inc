  Type
  Ppw_endpoint_info  = ^pw_endpoint_info;
  Ppw_endpoint_link_info  = ^pw_endpoint_link_info;
  Ppw_endpoint_link_state  = ^pw_endpoint_link_state;
  Ppw_endpoint_stream_info  = ^pw_endpoint_stream_info;
  Ppw_session_info  = ^pw_session_info;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2019 Collabora Ltd.  }
  {                         @author George Kiagiadakis <george.kiagiadakis@collabora.com>  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_EXT_SESSION_MANAGER_INTROSPECT_H}
{$define PIPEWIRE_EXT_SESSION_MANAGER_INTROSPECT_H}  



{ C++ extern C conditionnal removed }
  {*
   * \addtogroup pw_session_manager
   * \
    }

  type
    pw_endpoint_link_state = (PW_ENDPOINT_LINK_STATE_ERROR := -(1),PW_ENDPOINT_LINK_STATE_PREPARING,
      PW_ENDPOINT_LINK_STATE_INACTIVE,PW_ENDPOINT_LINK_STATE_ACTIVE
      );

(* error 
#define PW_VERSION_SESSION_INFO			0
  {*< version of this structure  }
  {*< the session id (global)  }
  {*< bitfield of changed fields since last call  }
  {*< extra properties  }
  {*< parameters  }
  {*< number of items in \a params  }
 in member_list *)
    Ppw_session_info = ^pw_session_info;
    pw_session_info = record
      end;

(* error 
#define PW_VERSION_ENDPOINT_INFO		0
  {*< version of this structure  }
  {*< the endpoint id (global)  }
  {*< name of the endpoint  }
  {*< media class of the endpoint  }
  {*< direction of the endpoint  }
  {*< additional flags  }
  {*< bitfield of changed fields since last call  }
  {*< number of streams available  }
  {*< the id of the controlling session  }
  {*< extra properties  }
  {*< parameters  }
  {*< number of items in \a params  }
 in member_list *)
    Ppw_endpoint_info = ^pw_endpoint_info;
    pw_endpoint_info = record
      end;

(* error 
#define PW_VERSION_ENDPOINT_STREAM_INFO		0
  {*< version of this structure  }
  {*< the stream id (local or global)  }
  {*< the endpoint id (global)  }
  {*< name of the stream  }
  {*< bitfield of changed fields since last call  }
  {*< information for linking this stream  }
  {*< extra properties  }
  {*< parameters  }
  {*< number of items in \a params  }
 in member_list *)
    Ppw_endpoint_stream_info = ^pw_endpoint_stream_info;
    pw_endpoint_stream_info = record
      end;

(* error 
#define PW_VERSION_ENDPOINT_LINK_INFO		0
  {*< version of this structure  }
  {*< the link id (global)  }
  {*< the session id (global)  }
  {*< the output endpoint id (global)  }
  {*< the output stream id (local or global)  }
  {*< the input endpoint id (global)  }
  {*< the input stream id (local or global)  }
  {*< bitfield of changed fields since last call  }
  {*< the state of the link  }
  {*< error string if state == ERROR  }
  {*< extra properties  }
  {*< parameters  }
  {*< number of items in \a params  }
 in member_list *)
    Ppw_endpoint_link_info = ^pw_endpoint_link_info;
    pw_endpoint_link_info = record
      end;

  {*
   * \
    }
{$endif}
  { PIPEWIRE_EXT_SESSION_MANAGER_INTROSPECT_H  }

