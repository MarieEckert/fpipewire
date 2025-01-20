    Type
    Ppw_protocol_native_demarshal  = ^pw_protocol_native_demarshal;
    Ppw_protocol_native_ext  = ^pw_protocol_native_ext;
    Ppw_protocol_native_message  = ^pw_protocol_native_message;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_EXT_PROTOCOL_NATIVE_H}
{$define PIPEWIRE_EXT_PROTOCOL_NATIVE_H}  
{ C++ extern C conditionnal removed }



  {* \defgroup pw_protocol_native Native Protocol
   * PipeWire native protocol interface
    }
  {*
   * \addtogroup pw_protocol_native
   * \
    }
(* error 
#define PW_TYPE_INFO_PROTOCOL_Native		PW_TYPE_INFO_PROTOCOL_BASE "Native"
in define line 25 *)

    type
      Ppw_protocol_native_message = ^pw_protocol_native_message;
      pw_protocol_native_message = record
          id : uint32_t;
          opcode : uint32_t;
          data : pointer;
          size : uint32_t;
          n_fds : uint32_t;
          fds : pcint;
          seq : cint;
        end;


      Ppw_protocol_native_demarshal = ^pw_protocol_native_demarshal;
      pw_protocol_native_demarshal = record
          func : function (object:pointer; msg:Ppw_protocol_native_message):cint;cdecl;
          permissions : uint32_t;
          flags : uint32_t;
        end;

    {* \ref pw_protocol_native_ext methods  }
(* error 
#define PW_VERSION_PROTOCOL_NATIVE_EXT	0
 in member_list *)
      Ppw_protocol_native_ext = ^pw_protocol_native_ext;
      pw_protocol_native_ext = record
        end;

(* error 
#define pw_protocol_native_begin_proxy(p,...)		pw_protocol_ext(pw_proxy_get_protocol(p),struct pw_protocol_native_ext,begin_proxy,p,__VA_ARGS__)
in define line 67 *)
(* error 
#define pw_protocol_native_add_proxy_fd(p,...)		pw_protocol_ext(pw_proxy_get_protocol(p),struct pw_protocol_native_ext,add_proxy_fd,p,__VA_ARGS__)
in define line 68 *)
(* error 
#define pw_protocol_native_get_proxy_fd(p,...)		pw_protocol_ext(pw_proxy_get_protocol(p),struct pw_protocol_native_ext,get_proxy_fd,p,__VA_ARGS__)
in define line 69 *)
(* error 
#define pw_protocol_native_end_proxy(p,...)		pw_protocol_ext(pw_proxy_get_protocol(p),struct pw_protocol_native_ext,end_proxy,p,__VA_ARGS__)
in define line 70 *)
(* error 
#define pw_protocol_native_begin_resource(r,...)	pw_protocol_ext(pw_resource_get_protocol(r),struct pw_protocol_native_ext,begin_resource,r,__VA_ARGS__)
in define line 72 *)
(* error 
#define pw_protocol_native_add_resource_fd(r,...)	pw_protocol_ext(pw_resource_get_protocol(r),struct pw_protocol_native_ext,add_resource_fd,r,__VA_ARGS__)
in define line 73 *)
(* error 
#define pw_protocol_native_get_resource_fd(r,...)	pw_protocol_ext(pw_resource_get_protocol(r),struct pw_protocol_native_ext,get_resource_fd,r,__VA_ARGS__)
in define line 74 *)
(* error 
#define pw_protocol_native_end_resource(r,...)		pw_protocol_ext(pw_resource_get_protocol(r),struct pw_protocol_native_ext,end_resource,r,__VA_ARGS__)
in define line 75 *)
    {*
     * \
      }
{$endif}
    { PIPEWIRE_EXT_PROTOCOL_NATIVE_H  }

