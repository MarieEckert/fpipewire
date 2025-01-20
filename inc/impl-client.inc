    Type
    Ppw_client_info  = ^pw_client_info;
    Ppw_impl_client  = ^pw_impl_client;
    Ppw_impl_client_events  = ^pw_impl_client_events;
    Ppw_permission  = ^pw_permission;
    Ppw_properties  = ^pw_properties;
    Pspa_dict  = Pointer; {$WARNING ^spa_dict}
    Pspa_hook  = Pointer; {$WARNING ^spa_hook}
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_IMPL_CLIENT_H}
{$define PIPEWIRE_IMPL_CLIENT_H}  
{ C++ extern C conditionnal removed }

  {* \page page_client_impl Client Implementation
   *
   * \see \ref pw_impl_client
   *
   * \section sec_page_client_impl_overview Overview
   *
   * The \ref pw_impl_client object is created by a protocol implementation when
   * a new client connects.
   *
   * The client is used to keep track of all resources belonging to one
   * connection with the PipeWire server.
   *
   * \section sec_page_client_impl_credentials Credentials
   *
   * The client object will have its credentials filled in by the protocol.
   * This information is used to check if a resource or action is available
   * for this client.
   *
   * \section sec_page_client_impl_types Types
   *
   * The client and server maintain a mapping between the client and server
   * types. All type ids that are in messages exchanged between the client
   * and server will automatically be remapped.
   *
   * \section sec_page_client_impl_resources Resources
   *
   * When a client binds to context global object, a resource is made for this
   * binding and a unique id is assigned to the resources. The client and
   * server will use this id as the destination when exchanging messages.
   * See also \ref pw_resource
    }
  {* \defgroup pw_impl_client Client Impl
   *
   * \brief PipeWire client object class
   *
   * The client object represents a client connection with the PipeWire
   * server.
   *
   * Each client has its own list of resources it is bound to along with
   * a mapping between the client types and server types.
   *
   * \see \ref page_client_impl
    }
  {*
   * \addtogroup pw_impl_client
   * \
    }

  type
    Ppw_impl_client = ^pw_impl_client;
    pw_impl_client = record
        {undefined structure}
      end;






  {* The events that a client can emit  }
(* error 
#define PW_VERSION_IMPL_CLIENT_EVENTS	0
  {* emitted when the client is destroyed  }
  {* emitted right before the client is freed  }
  {* the client is initialized  }
  {* emitted when the client info changed  }
  {* emitted when a new resource is added for client  }
  {* emitted when a resource is removed  }
  {* emitted when the client becomes busy processing an asynchronous
  	 * message. In the busy state no messages should be processed.
  	 * Processing should resume when the client becomes not busy  }
 in member_list *)

  type
    Ppw_impl_client_events = ^pw_impl_client_events;
    pw_impl_client_events = record
      end;

  {* Create a new client. This is mainly used by protocols.  }
(* error 
struct pw_impl_client *
  {*< the core object  }
  {*< the client protocol  }
  {*< client properties  }
  {*< extra user data size  }in declaration at line 105 *)
    {* Destroy a previously created client  }

    procedure pw_impl_client_destroy(client:Ppw_impl_client);cdecl;external;

    {* Finish configuration and register a client  }
    {*< the client to register  }
    {*< extra properties  }    function pw_impl_client_register(client:Ppw_impl_client; properties:Ppw_properties):cint;cdecl;external;

    {* Get the client user data  }
    function pw_impl_client_get_user_data(client:Ppw_impl_client):pointer;cdecl;external;

    {* Get the client information  }

    function pw_impl_client_get_info(client:Ppw_impl_client):Ppw_client_info;cdecl;external;

    {* Update the client properties  }

    function pw_impl_client_update_properties(client:Ppw_impl_client; dict:Pspa_dict):cint;cdecl;external;

    {* Update the client permissions  }

    function pw_impl_client_update_permissions(client:Ppw_impl_client; n_permissions:uint32_t; permissions:Ppw_permission):cint;cdecl;external;

    {* check if a client has permissions for global_id, Since 0.3.9  }
    function pw_impl_client_check_permissions(client:Ppw_impl_client; global_id:uint32_t; permissions:uint32_t):cint;cdecl;external;

    {* Get the client properties  }

    function pw_impl_client_get_properties(client:Ppw_impl_client):Ppw_properties;cdecl;external;

    {* Get the context used to create this client  }
(* error 
struct pw_context *pw_impl_client_get_context(struct pw_impl_client *client);
in declaration at line 135 *)
    {* Get the protocol used to create this client  }
(* error 
struct pw_protocol *pw_impl_client_get_protocol(struct pw_impl_client *client);
in declaration at line 137 *)
    {* Get the client core resource  }
(* error 
struct pw_resource *pw_impl_client_get_core_resource(struct pw_impl_client *client);
in declaration at line 140 *)
    {* Get a resource with the given id  }
(* error 
struct pw_resource *pw_impl_client_find_resource(struct pw_impl_client *client, uint32_t id);
in declaration at line 143 *)
    {* Get the global associated with this client  }
(* error 
struct pw_global *pw_impl_client_get_global(struct pw_impl_client *client);
in declaration at line 146 *)
    {* Get the mempool associated with this client, Since 0.3.74  }
(* error 
struct pw_mempool *pw_impl_client_get_mempool(struct pw_impl_client *client);
in declaration at line 149 *)
    {* listen to events from this client  }

    procedure pw_impl_client_add_listener(client:Ppw_impl_client; listener:Pspa_hook; events:Ppw_impl_client_events; data:pointer);cdecl;external;

    {* Mark the client busy. This can be used when an asynchronous operation is
      * started and no further processing is allowed to happen for the client  }
    procedure pw_impl_client_set_busy(client:Ppw_impl_client; busy:bool);cdecl;external;

    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_IMPL_CLIENT_H  }

