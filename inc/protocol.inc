    Type
    Ppw_core  = ^pw_core;
    Ppw_impl_core  = ^pw_impl_core;
    Ppw_protocol  = ^pw_protocol;
    Ppw_protocol_client  = ^pw_protocol_client;
    Ppw_protocol_events  = ^pw_protocol_events;
    Ppw_protocol_implementation  = ^pw_protocol_implementation;
    Ppw_protocol_marshal  = ^pw_protocol_marshal;
    Ppw_protocol_server  = ^pw_protocol_server;
    Pspa_dict  = Pointer; {$WARNING ^spa_dict}
    Pspa_hook  = Pointer; {$WARNING ^spa_hook}
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_PROTOCOL_H}
{$define PIPEWIRE_PROTOCOL_H}  
{ C++ extern C conditionnal removed }

  {* \defgroup pw_protocol Protocol
   *
   * \brief Manages protocols and their implementation
    }
  {*
   * \addtogroup pw_protocol
   * \
    }

  type
    Ppw_protocol = ^pw_protocol;
    pw_protocol = record
        {undefined structure}
      end;





  const
    PW_TYPE_INFO_Protocol = 'PipeWire:Protocol';    
(* error 
#define PW_TYPE_INFO_PROTOCOL_BASE	PW_TYPE_INFO_Protocol ":"
in define line 31 *)
    {*< link in protocol client_list  }
    {*< the owner protocol  }


    type
      Ppw_protocol_client = ^pw_protocol_client;
      pw_protocol_client = record
          link : spa_list;
          protocol : Ppw_protocol;
          core : Ppw_core;
          connect : function (client:Ppw_protocol_client; props:Pspa_dict; done_callback:procedure (data:pointer; result:cint); data:pointer):cint;cdecl;
          connect_fd : function (client:Ppw_protocol_client; fd:cint; close:bool):cint;cdecl;
          steal_fd : function (client:Ppw_protocol_client):cint;cdecl;
          disconnect : procedure (client:Ppw_protocol_client);cdecl;
          destroy : procedure (client:Ppw_protocol_client);cdecl;
          set_paused : function (client:Ppw_protocol_client; paused:bool):cint;cdecl;
        end;

    { was #define dname(params) para_def_expr }
    { argument types are unknown }
    { return type might be wrong }   

    function pw_protocol_client_connect(c,p,cb,d : longint) : longint;    

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_protocol_client_connect_fd(c,fd,cl : longint) : longint;  

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_protocol_client_steal_fd(c : longint) : longint;  

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_protocol_client_disconnect(c : longint) : longint;  

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_protocol_client_destroy(c : longint) : longint;  

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_protocol_client_set_paused(c,p : longint) : longint;  

  {*< link in protocol server_list  }
  {*< the owner protocol  }
  {*< list of clients of this protocol  }

  type
    Ppw_protocol_server = ^pw_protocol_server;
    pw_protocol_server = record
        link : spa_list;
        protocol : Ppw_protocol;
        core : Ppw_impl_core;
        client_list : spa_list;
        destroy : procedure (listen:Ppw_protocol_server);cdecl;
      end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   

  function pw_protocol_server_destroy(l : longint) : longint;  


  {*< interface type  }
  {*< version  }
(* error 
#define PW_PROTOCOL_MARSHAL_FLAG_IMPL	(1 << 0)	/**< marshal for implementations */
  {*< marshal for implementations  }
  {*< version  }
  {*< number of client methods  }
  {*< number of server methods  }
 in member_list *)

  type
    Ppw_protocol_marshal = ^pw_protocol_marshal;
    pw_protocol_marshal = record
      end;

(* error 
#define PW_VERSION_PROTOCOL_IMPLEMENTATION	1
 in member_list *)
    Ppw_protocol_implementation = ^pw_protocol_implementation;
    pw_protocol_implementation = record
      end;

(* error 
#define PW_VERSION_PROTOCOL_EVENTS		0
 in member_list *)
    Ppw_protocol_events = ^pw_protocol_events;
    pw_protocol_events = record
      end;

(* error 
#define pw_protocol_new_client(p,...)	(pw_protocol_get_implementation(p)->new_client(p,__VA_ARGS__))
in define line 106 *)
(* error 
#define pw_protocol_add_server(p,...)	(pw_protocol_get_implementation(p)->add_server(p,__VA_ARGS__))
in define line 107 *)
(* error 
#define pw_protocol_add_fd_server(p,...)	(pw_protocol_get_implementation(p)->add_fd_server(p,__VA_ARGS__))
in define line 108 *)
(* error 
#define pw_protocol_ext(p,type,method,...)	(((type*)pw_protocol_get_extension(p))->method( __VA_ARGS__))
in define line 109 *)
(* error 
struct pw_protocol *pw_protocol_new(struct pw_context *context, const char *name, size_t user_data_size);
in declaration at line 111 *)

    procedure pw_protocol_destroy(protocol:Ppw_protocol);cdecl;external;

(* error 
struct pw_context *pw_protocol_get_context(struct pw_protocol *protocol);
in declaration at line 115 *)
    function pw_protocol_get_user_data(protocol:Ppw_protocol):pointer;cdecl;external;


    function pw_protocol_get_implementation(protocol:Ppw_protocol):Ppw_protocol_implementation;cdecl;external;


    function pw_protocol_get_extension(protocol:Ppw_protocol):pointer;cdecl;external;


    procedure pw_protocol_add_listener(protocol:Ppw_protocol; listener:Pspa_hook; events:Ppw_protocol_events; data:pointer);cdecl;external;


    function pw_protocol_add_marshal(protocol:Ppw_protocol; marshal:Ppw_protocol_marshal):cint;cdecl;external;



    function pw_protocol_get_marshal(protocol:Ppw_protocol; _type:pcchar; version:uint32_t; flags:uint32_t):Ppw_protocol_marshal;cdecl;external;

(* error 
struct pw_protocol * pw_context_find_protocol(struct pw_context *context, const char *name);
in declaration at line 137 *)
    {*
     * \
      }
{$endif}
    { PIPEWIRE_PROTOCOL_H  }
    { was #define dname(params) para_def_expr }
    { argument types are unknown }
    { return type might be wrong }   
    function pw_protocol_client_connect(c,p,cb,d : longint) : longint;
    begin
      pw_protocol_client_connect:=c^.(connect(c,p,cb,d));
    end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_protocol_client_connect_fd(c,fd,cl : longint) : longint;
  begin
    pw_protocol_client_connect_fd:=c^.(connect_fd(c,fd,cl));
  end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_protocol_client_steal_fd(c : longint) : longint;
  begin
    pw_protocol_client_steal_fd:=c^.(steal_fd(c));
  end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_protocol_client_disconnect(c : longint) : longint;
  begin
    pw_protocol_client_disconnect:=c^.(disconnect(c));
  end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_protocol_client_destroy(c : longint) : longint;
  begin
    pw_protocol_client_destroy:=c^.(destroy(c));
  end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_protocol_client_set_paused(c,p : longint) : longint;
  begin
    pw_protocol_client_set_paused:=c^.(set_paused(c,p));
  end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_protocol_server_destroy(l : longint) : longint;
  begin
    pw_protocol_server_destroy:=l^.(destroy(l));
  end;


