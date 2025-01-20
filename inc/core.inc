{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{ C++ extern C conditionnal removed }



  {* \defgroup pw_core Core
   *
   * \brief The core global object.
   *
   * This is a special singleton object. It is used for internal PipeWire
   * protocol features. Connecting to a PipeWire instance returns one core
   * object, the caller should then register event listeners
   * using \ref pw_core_add_listener.
   *
   * Updates to the core object are then provided through the \ref
   * pw_core_events interface. See \ref page_tutorial2 for an example.
    }
  {*
   * \addtogroup pw_core
   * \
    }
(* error 
#define PW_TYPE_INTERFACE_Core		PW_TYPE_INFO_INTERFACE_BASE "Core"
in define line 34 *)
(* error 
#define PW_TYPE_INTERFACE_Registry	PW_TYPE_INFO_INTERFACE_BASE "Registry"
in define line 35 *)
(* error 
#define PW_CORE_PERM_MASK		PW_PERM_R|PW_PERM_X|PW_PERM_M
in define line 37 *)

    const
      PW_VERSION_CORE = 4;      

    type
      Ppw_core = ^pw_core;
      pw_core = record
          {undefined structure}
        end;


    const
      PW_VERSION_REGISTRY = 3;      

    type
      Ppw_registry = ^pw_registry;
      pw_registry = record
          {undefined structure}
        end;

    {* The default remote name to connect to  }

    const
      PW_DEFAULT_REMOTE = 'pipewire-0';      
    {* default ID for the core object after connect  }
      PW_ID_CORE = 0;      
    { invalid ID that matches any object when used for permissions  }

    { was #define dname def_expr }
    function PW_ID_ANY : uint32_t;      

    {*  The core information. Extra information may be added in later versions,
     * clients must not assume a constant struct size  }
    {*< id of the global  }
    {*< a random cookie for identifying this instance of PipeWire  }

    {*< name of the user that started the core  }

    {*< name of the machine the core is running on  }

    {*< version of the core  }

    {*< name of the core  }
(* error 
#define PW_CORE_CHANGE_MASK_PROPS      (1 << 0)
    {*< bitfield of changed fields since last call  }
    {*< extra properties  }
 in member_list *)

    type
      Ppw_core_info = ^pw_core_info;
      pw_core_info = record
        end;




    {* Update an existing \ref pw_core_info with \a update with reset. When info is NULL,
     * a new one will be allocated. Returns NULL on failure.  }
(* error 
struct pw_core_info *
in declaration at line 76 *)
    {* Update an existing \ref pw_core_info with \a update. When info is NULL, a new one
     * will be allocated. Returns NULL on failure  }
(* error 
struct pw_core_info *
in declaration at line 81 *)
    {* Free a \ref pw_core_info   }

    procedure pw_core_info_free(info:Ppw_core_info);cdecl;external External_library name 'pw_core_info_free';

    {* Core  }
    const
      PW_CORE_EVENT_INFO = 0;      
      PW_CORE_EVENT_DONE = 1;      
      PW_CORE_EVENT_PING = 2;      
      PW_CORE_EVENT_ERROR = 3;      
      PW_CORE_EVENT_REMOVE_ID = 4;      
      PW_CORE_EVENT_BOUND_ID = 5;      
      PW_CORE_EVENT_ADD_MEM = 6;      
      PW_CORE_EVENT_REMOVE_MEM = 7;      
      PW_CORE_EVENT_BOUND_PROPS = 8;      
      PW_CORE_EVENT_NUM = 9;      
    {* \struct pw_core_events
     *  \brief Core events
      }
(* error 
#define PW_VERSION_CORE_EVENTS	1
    {*
    	 * Notify new core info
    	 *
    	 * This event is emitted when first bound to the core or when the
    	 * hello method is called.
    	 *
    	 * \param info new core info
    	  }
    {*
    	 * Emit a done event
    	 *
    	 * The done event is emitted as a result of a sync method with the
    	 * same seq number.
    	 *
    	 * \param seq the seq number passed to the sync method call
    	  }
    {* Emit a ping event
    	 *
    	 * The client should reply with a pong reply with the same seq
    	 * number.
    	  }
    {*
    	 * Fatal error event
             *
             * The error event is sent out when a fatal (non-recoverable)
             * error has occurred. The id argument is the proxy object where
             * the error occurred, most often in response to a request to that
             * object. The message is a brief description of the error,
             * for (debugging) convenience.
    	 *
    	 * This event is usually also emitted on the proxy object with
    	 * \a id.
    	 *
             * \param id object where the error occurred
             * \param seq the sequence number that generated the error
             * \param res error code
             * \param message error description
    	  }
    {*
    	 * Remove an object ID
             *
             * This event is used internally by the object ID management
             * logic. When a client deletes an object, the server will send
             * this event to acknowledge that it has seen the delete request.
             * When the client receives this event, it will know that it can
             * safely reuse the object ID.
    	 *
             * \param id deleted object ID
    	  }
    {*
    	 * Notify an object binding
    	 *
    	 * This event is emitted when a local object ID is bound to a
    	 * global ID. It is emitted before the global becomes visible in the
    	 * registry.
    	 *
    	 * The bound_props event is an enhanced version of this event that
    	 * also contains the extra global properties.
    	 *
    	 * \param id bound object ID
    	 * \param global_id the global id bound to
    	  }
    {*
    	 * Add memory for a client
    	 *
    	 * Memory is given to a client as \a fd of a certain
    	 * memory \a type.
    	 *
    	 * Further references to this fd will be made with the per memory
    	 * unique identifier \a id.
    	 *
    	 * \param id the unique id of the memory
    	 * \param type the memory type, one of enum spa_data_type
    	 * \param fd the file descriptor
    	 * \param flags extra flags
    	  }
    {*
    	 * Remove memory for a client
    	 *
    	 * \param id the memory id to remove
    	  }
    {*
    	 * Notify an object binding
    	 *
    	 * This event is emitted when a local object ID is bound to a
    	 * global ID. It is emitted before the global becomes visible in the
    	 * registry.
    	 *
    	 * This is an enhanced version of the bound_id event.
    	 *
    	 * \param id bound object ID
    	 * \param global_id the global id bound to
    	 * \param props The properties of the new global object.
    	 *
    	 * Since version 4:1
    	  }
 in member_list *)

    type
      Ppw_core_events = ^pw_core_events;
      pw_core_events = record
        end;


    const
      PW_CORE_METHOD_ADD_LISTENER = 0;      
      PW_CORE_METHOD_HELLO = 1;      
      PW_CORE_METHOD_SYNC = 2;      
      PW_CORE_METHOD_PONG = 3;      
      PW_CORE_METHOD_ERROR = 4;      
      PW_CORE_METHOD_GET_REGISTRY = 5;      
      PW_CORE_METHOD_CREATE_OBJECT = 6;      
      PW_CORE_METHOD_DESTROY = 7;      
      PW_CORE_METHOD_NUM = 8;      
    {*
     * \struct pw_core_methods
     * \brief Core methods
     *
     * The core global object. This is a singleton object used for
     * creating new objects in the remote PipeWire instance. It is
     * also used for internal features.
      }
(* error 
#define PW_VERSION_CORE_METHODS	0
    {*
    	 * Start a conversation with the server. This will send
    	 * the core info and will destroy all resources for the client
    	 * (except the core and client resource).
    	 *
    	 * This requires X permissions on the core.
    	  }
    {*
    	 * Do server roundtrip
    	 *
    	 * Ask the server to emit the 'done' event with \a seq.
    	 *
    	 * Since methods are handled in-order and events are delivered
    	 * in-order, this can be used as a barrier to ensure all previous
    	 * methods and the resulting events have been handled.
    	 *
    	 * \param seq the seq number passed to the done event
    	 *
    	 * This requires X permissions on the core.
    	  }
    {*
    	 * Reply to a server ping event.
    	 *
    	 * Reply to the server ping event with the same seq.
    	 *
    	 * \param seq the seq number received in the ping event
    	 *
    	 * This requires X permissions on the core.
    	  }
    {*
    	 * Fatal error event
             *
             * The error method is sent out when a fatal (non-recoverable)
             * error has occurred. The id argument is the proxy object where
             * the error occurred, most often in response to an event on that
             * object. The message is a brief description of the error,
             * for (debugging) convenience.
    	 *
    	 * This method is usually also emitted on the resource object with
    	 * \a id.
    	 *
             * \param id resource id where the error occurred
             * \param res error code
             * \param message error description
    	 *
    	 * This requires X permissions on the core.
    	  }
    {*
    	 * Get the registry object
    	 *
    	 * Create a registry object that allows the client to list and bind
    	 * the global objects available from the PipeWire server
    	 * \param version the client version
    	 * \param user_data_size extra size
    	 *
    	 * This requires X permissions on the core.
    	  }
    {*
    	 * Create a new object on the PipeWire server from a factory.
    	 *
    	 * \param factory_name the factory name to use
    	 * \param type the interface to bind to
    	 * \param version the version of the interface
    	 * \param props extra properties
    	 * \param user_data_size extra size
    	 *
    	 * This requires X permissions on the core.
    	  }
    {*
    	 * Destroy an resource
    	 *
    	 * Destroy the server resource for the given proxy.
    	 *
    	 * \param obj the proxy to destroy
    	 *
    	 * This requires X permissions on the core.
    	  }
 in member_list *)

    type
      Ppw_core_methods = ^pw_core_methods;
      pw_core_methods = record
        end;


    function pw_core_error(_para1:core; _para2:id; _para3:seq; _para4:res; _para5:buffer):return;cdecl;external External_library name 'pw_core_error';

    {*
     * \
      }
    {* \defgroup pw_registry Registry
     *
     * The registry object is a singleton object that keeps track of
     * global objects on the PipeWire instance. See also \ref pw_global.
     *
     * Global objects typically represent an actual object in PipeWire
     * (for example, a module or node) or they are singleton
     * objects such as the core.
     *
     * When a client creates a registry object, the registry object
     * will emit a global event for each global currently in the
     * registry.  Globals come and go as a result of device hotplugs or
     * reconfiguration or other events, and the registry will send out
     * global and global_remove events to keep the client up to date
     * with the changes.  To mark the end of the initial burst of
     * events, the client can use the pw_core.sync methosd immediately
     * after calling pw_core.get_registry.
     *
     * A client can bind to a global object by using the bind
     * request.  This creates a client-side proxy that lets the object
     * emit events to the client and lets the client invoke methods on
     * the object. See \ref page_proxy
     *
     * Clients can also change the permissions of the global objects that
     * it can see. This is interesting when you want to configure a
     * pipewire session before handing it to another application. You
     * can, for example, hide certain existing or new objects or limit
     * the access permissions on an object.
      }
    {*
     * \addtogroup pw_registry
     * \
      }

    const
      PW_REGISTRY_EVENT_GLOBAL = 0;      
      PW_REGISTRY_EVENT_GLOBAL_REMOVE = 1;      
      PW_REGISTRY_EVENT_NUM = 2;      
    {* Registry events  }
(* error 
#define PW_VERSION_REGISTRY_EVENTS	0
    {*
    	 * Notify of a new global object
    	 *
    	 * The registry emits this event when a new global object is
    	 * available.
    	 *
    	 * \param id the global object id
    	 * \param permissions the permissions of the object
    	 * \param type the type of the interface
    	 * \param version the version of the interface
    	 * \param props extra properties of the global
    	  }
    {*
    	 * Notify of a global object removal
    	 *
    	 * Emitted when a global object was removed from the registry.
    	 * If the client has any bindings to the global, it should destroy
    	 * those.
    	 *
    	 * \param id the id of the global that was removed
    	  }
 in member_list *)

    type
      Ppw_registry_events = ^pw_registry_events;
      pw_registry_events = record
        end;


    const
      PW_REGISTRY_METHOD_ADD_LISTENER = 0;      
      PW_REGISTRY_METHOD_BIND = 1;      
      PW_REGISTRY_METHOD_DESTROY = 2;      
      PW_REGISTRY_METHOD_NUM = 3;      
    {* Registry methods  }
(* error 
#define PW_VERSION_REGISTRY_METHODS	0
    {*
    	 * Bind to a global object
    	 *
    	 * Bind to the global object with \a id and use the client proxy
    	 * with new_id as the proxy. After this call, methods can be
    	 * send to the remote global object and events can be received
    	 *
    	 * \param id the global id to bind to
    	 * \param type the interface type to bind to
    	 * \param version the interface version to use
    	 * \returns the new object
    	  }
    {*
    	 * Attempt to destroy a global object
    	 *
    	 * Try to destroy the global object.
    	 *
    	 * \param id the global id to destroy. The client needs X permissions
    	 * on the global.
    	  }
 in member_list *)

    type
      Ppw_registry_methods = ^pw_registry_methods;
      pw_registry_methods = record
        end;

   {*
     * \addtogroup pw_core
     * \
      }
    {* Connect to a PipeWire instance
     *
     * \param context a \ref pw_context
     * \param properties optional properties, ownership of the properties is
     *	taken.
     * \param user_data_size extra user data size
     *
     * \return a \ref pw_core on success or NULL with errno set on error. The core
     * will have an id of \ref PW_ID_CORE (0)
      }
(* error 
struct pw_core *
in declaration at line 567 *)
    {* Connect to a PipeWire instance on the given socket
     *
     * \param context a \ref pw_context
     * \param fd the connected socket to use, the socket will be closed
     *	automatically on disconnect or error.
     * \param properties optional properties, ownership of the properties is
     *	taken.
     * \param user_data_size extra user data size
     *
     * \return a \ref pw_core on success or NULL with errno set on error  }
(* error 
struct pw_core *
in declaration at line 583 *)
    {* Connect to a given PipeWire instance
     *
     * \param context a \ref pw_context to connect to
     * \param properties optional properties, ownership of the properties is
     *	taken.
     * \param user_data_size extra user data size
     *
     * \return a \ref pw_core on success or NULL with errno set on error  }
(* error 
struct pw_core *
in declaration at line 596 *)
    {* Steal the fd of the core connection or < 0 on error. The core
      * will be disconnected after this call.  }

    function pw_core_steal_fd(core:Ppw_core):cint;cdecl;external External_library name 'pw_core_steal_fd';

    {* Pause or resume the core. When the core is paused, no new events
     *  will be dispatched until the core is resumed again.  }
    function pw_core_set_paused(core:Ppw_core; paused:bool):cint;cdecl;external External_library name 'pw_core_set_paused';

    {* disconnect and destroy a core  }
    function pw_core_disconnect(core:Ppw_core):cint;cdecl;external External_library name 'pw_core_disconnect';

    {* Get the user_data. It is of the size specified when this object was
     * constructed  }
    function pw_core_get_user_data(core:Ppw_core):pointer;cdecl;external External_library name 'pw_core_get_user_data';

    {* Get the client proxy of the connected core. This will have the id
     * of PW_ID_CLIENT (1)  }
(* error 
struct pw_client * pw_core_get_client(struct pw_core *core);
in declaration at line 615 *)
    {* Get the context object used to created this core  }
(* error 
struct pw_context * pw_core_get_context(struct pw_core *core);
in declaration at line 618 *)
    {* Get properties from the core  }

    function pw_core_get_properties(core:Ppw_core):Ppw_properties;cdecl;external External_library name 'pw_core_get_properties';

    {* Update the core properties. This updates the properties
     * of the associated client.
     * \return the number of properties that were updated  }

    function pw_core_update_properties(core:Ppw_core; dict:Pspa_dict):cint;cdecl;external External_library name 'pw_core_update_properties';

{ C++ end of extern C conditionnal removed }
    { PIPEWIRE_CORE_H  }
    { was #define dname def_expr }
    function PW_ID_ANY : uint32_t;
      begin
        PW_ID_ANY:=uint32_t($ffffffff);
      end;


