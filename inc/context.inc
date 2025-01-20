    Type
    Ppw_context  = ^pw_context;
    Ppw_context_events  = ^pw_context_events;
    Ppw_core  = ^pw_core;
    Ppw_export_type  = ^pw_export_type;
    Ppw_global  = ^pw_global;
    Ppw_impl_client  = ^pw_impl_client;
    Ppw_impl_node  = ^pw_impl_node;
    Ppw_loop  = ^pw_loop;
    Ppw_properties  = ^pw_properties;
    Ppw_proxy  = ^pw_proxy;
    Pspa_dict  = Pointer; {$WARNING ^spa_dict}
    Pspa_hook  = Pointer; {$WARNING ^spa_hook}
    Pspa_support  = Pointer; {$WARNING ^spa_support}
    Puint32_t  = ^uint32_t;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_CONTEXT_H}
{$define PIPEWIRE_CONTEXT_H}  
{ C++ extern C conditionnal removed }


  {* \defgroup pw_context Context
   *
   * \brief The PipeWire context object manages all locally available
   * resources. It is used by both clients and servers.
   *
   * The context is used to:
   *
   *  - Load modules and extend the functionality. This includes
   *    extending the protocol with new object types or creating
   *    any of the available objects.
   *
   *  - Create implementations of various objects like nodes,
   *    devices, factories, modules, etc.. This will usually also
   *    create pw_global objects that can then be shared with
   *    clients.
   *
   *  - Connect to another PipeWire instance (the main daemon, for
   *    example) and interact with it (See \ref page_core_api).
   *
   *  - Export a local implementation of an object to another
   *    instance.
    }
  {*
   * \addtogroup pw_context
   * @
    }

  type
    Ppw_context = ^pw_context;
    pw_context = record
        {undefined structure}
      end;

    Ppw_global = ^pw_global;
    pw_global = record
        {undefined structure}
      end;

    Ppw_impl_client = ^pw_impl_client;
    pw_impl_client = record
        {undefined structure}
      end;

    Ppw_impl_node = ^pw_impl_node;
    pw_impl_node = record
        {undefined structure}
      end;




  {* context events emitted by the context object added with \ref pw_context_add_listener  }
(* error 
#define PW_VERSION_CONTEXT_EVENTS	1
  {* The context is being destroyed  }
  {* The context is being freed  }
  {* a new client object is added  }
  {* a new global object was added  }
  {* a global object was removed  }
  {* a driver was added, since 0.3.75 version:1  }
  {* a driver was removed, since 0.3.75 version:1  }
 in member_list *)

  type
    Ppw_context_events = ^pw_context_events;
    pw_context_events = record
      end;

  {* Make a new context object for a given main_loop. Ownership of the properties is taken, even
   * if the function returns NULL.
   *
   * \param main_loop A main loop to run in. This must stay alive unil pw_context_destroy() is called.
   * \param props extra properties
   * \param user_data_size extra user data size
   * \return The context object on success, or NULL on failure, in which case errno is set.
   *  }
(* error 
struct pw_context * pw_context_new(struct pw_loop *main_loop,
in declaration at line 84 *)
    {* destroy a context object, all resources except the main_loop will be destroyed  }

    procedure pw_context_destroy(context:Ppw_context);cdecl;external;

    {* Get the context user data  }
    function pw_context_get_user_data(context:Ppw_context):pointer;cdecl;external;

    {* Add a new event listener to a context  }

    procedure pw_context_add_listener(context:Ppw_context; listener:Pspa_hook; events:Ppw_context_events; data:pointer);cdecl;external;

    {* Get the context properties  }

    function pw_context_get_properties(context:Ppw_context):Ppw_properties;cdecl;external;

    {* Update the context properties  }

    function pw_context_update_properties(context:Ppw_context; dict:Pspa_dict):cint;cdecl;external;

    {* Get a config section for this context. Since 0.3.22, deprecated,
     * use pw_context_conf_section_for_each().  }


    function pw_context_get_conf_section(context:Ppw_context; section:pcchar):pcchar;cdecl;external;

    {* Parse a standard config section for this context. Since 0.3.22  }

    function pw_context_parse_conf_section(context:Ppw_context; conf:Ppw_properties; section:pcchar):cint;cdecl;external;

    {* update properties from a section into props. Since 0.3.45  }

    function pw_context_conf_update_props(context:Ppw_context; section:pcchar; props:Ppw_properties):cint;cdecl;external;

    {* emit callback for all config sections. Since 0.3.45  }




    function pw_context_conf_section_for_each(context:Ppw_context; section:pcchar; callback:function (data:pointer; location:pcchar; section:pcchar; str:pcchar; len:size_t):cint; data:pointer):cint;cdecl;external;

    {* emit callback for all matched properties. Since 0.3.46  }





    function pw_context_conf_section_match_rules(context:Ppw_context; section:pcchar; props:Pspa_dict; callback:function (data:pointer; location:pcchar; action:pcchar; str:pcchar; len:size_t):cint; data:pointer):cint;cdecl;external;

    {* Get the context support objects  }

    function pw_context_get_support(context:Ppw_context; n_support:Puint32_t):Pspa_support;cdecl;external;

    {* Get the context main loop. Returns the value passed to pw_context_new().  }
(* error 
struct pw_loop *pw_context_get_main_loop(struct pw_context *context);
in declaration at line 130 *)
    {* Get the context data loop. This loop runs on the realtime thread. This
     * acquires a loop from the generic data.rt class. Use pw_context_acquire_loop() instead.
     * Since 0.3.56  }
(* error 
struct pw_data_loop *pw_context_get_data_loop(struct pw_context *context);
in declaration at line 135 *)
    {* Get a data-loop.
     * Since 1.1.0  }
(* error 
struct pw_loop *pw_context_acquire_loop(struct pw_context *context, const struct spa_dict *props);
in declaration at line 139 *)
    {* Release a data-loop.
     * Since 1.1.0  }
    procedure pw_context_release_loop(context:Ppw_context; loop:Ppw_loop);cdecl;external;

    {* Get the work queue from the context: Since 0.3.26  }
(* error 
struct pw_work_queue *pw_context_get_work_queue(struct pw_context *context);
in declaration at line 145 *)
    {* Get the memory pool from the context: Since 0.3.74  }
(* error 
struct pw_mempool *pw_context_get_mempool(struct pw_context *context);
in declaration at line 148 *)
    {* Iterate the globals of the context. The callback should return
     * 0 to fetch the next item, any other value stops the iteration and returns
     * the value. When all callbacks return 0, this function returns 0 when all
     * globals are iterated.  }
    function pw_context_for_each_global(context:Ppw_context; callback:function (data:pointer; global:Ppw_global):cint; data:pointer):cint;cdecl;external;

    {* Find a context global by id.
     *
     * \return The global on success, or NULL on failure. If id is \ref PW_ID_CORE,
     *         this function will always return a non-NULL value.  }
(* error 
struct pw_global *pw_context_find_global(struct pw_context *context,	/**< the context */
    {*< the context  }
    {*< the global id  }in declaration at line 163 *)
    {* add a spa library for the given factory_name regex  }


    function pw_context_add_spa_lib(context:Ppw_context; factory_regex:pcchar; lib:pcchar):cint;cdecl;external;

    {* find the library name for a spa factory  }


    function pw_context_find_spa_lib(context:Ppw_context; factory_name:pcchar):pcchar;cdecl;external;

    {* Load a SPA handle from a context. On failure returns NULL and sets errno.  }
(* error 
struct spa_handle *pw_context_load_spa_handle(struct pw_context *context,
in declaration at line 174 *)
    {* data for registering export functions  }




    type
      Ppw_export_type = ^pw_export_type;
      pw_export_type = record
          link : spa_list;cdecl;
          _type : pcchar;
          func : function (core:Ppw_core; _type:pcchar; props:Pspa_dict; object:pointer; user_data_size:size_t):Ppw_proxy;cdecl;
        end;

    {* register a type that can be exported on a context_proxy. This is usually used by
     * extension modules  }

    function pw_context_register_export_type(context:Ppw_context; _type:Ppw_export_type):cint;cdecl;external;

    {* find information about registered export type  }


    function pw_context_find_export_type(context:Ppw_context; _type:pcchar):Ppw_export_type;cdecl;external;

    {* add an object to the context
     *
     * \param context The context.
     * \param type The type of the object, usually a `TYPE_INTERFACE_` value.
     * \param value The object value. Must last as long as the context and must
     *              be of the type corresponding to the type.
     * \return A negative number on failure (out of memory).
     *  }

    function pw_context_set_object(context:Ppw_context; _type:pcchar; value:pointer):cint;cdecl;external;

    {* get an object from the context
     *
     * \param context The context.
     * \param type The string corresponding to the object's interface.
     * \return The object, or NULL if the object does not exist.
     *  }

    function pw_context_get_object(context:Ppw_context; _type:pcchar):pointer;cdecl;external;

    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_CONTEXT_H  }

