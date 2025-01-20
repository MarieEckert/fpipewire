
    { Pointers to basic pascal types, inserted by h2pas conversion program.}
    Type
      PLongint  = ^Longint;
      PSmallInt = ^SmallInt;
      PByte     = ^Byte;
      PWord     = ^Word;
      PDWord    = ^DWord;
      PDouble   = ^Double;

    Type
    Ppw_buffer  = ^pw_buffer;
    Ppw_filter  = ^pw_filter;
    Ppw_filter_events  = ^pw_filter_events;
    Ppw_filter_flags  = ^pw_filter_flags;
    Ppw_filter_port_flags  = ^pw_filter_port_flags;
    Ppw_filter_state  = ^pw_filter_state;
    Ppw_properties  = ^pw_properties;
    Pspa_buffer  = ^spa_buffer;
    Pspa_dict  = ^spa_dict;
    Pspa_hook  = ^spa_hook;
    Pspa_pod  = ^spa_pod;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2019 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_FILTER_H}
{$define PIPEWIRE_FILTER_H}  
{ C++ extern C conditionnal removed }
  {* \defgroup pw_filter Filter
   *
   * \brief PipeWire filter object class
   *
   * The filter object provides a convenient way to implement
   * processing filters.
   *
   * See also \ref api_pw_core
    }
  {*
   * \addtogroup pw_filter
   * \
    }

  type
    Ppw_filter = ^pw_filter;
    pw_filter = record
        {undefined structure}
      end;

{$include <spa/buffer/buffer.h>}
{$include <spa/node/io.h>}
{$include <spa/param/param.h>}
{$include <spa/pod/command.h>}
{$include <pipewire/core.h>}
{$include <pipewire/stream.h>}
  {* \enum pw_filter_state The state of a filter   }
  {*< the stream is in error  }
  {*< unconnected  }
  {*< connection is in progress  }
  {*< filter is connected and paused  }
  {*< filter is streaming  }

  type
    pw_filter_state = (PW_FILTER_STATE_ERROR := -(1),PW_FILTER_STATE_UNCONNECTED := 0,
      PW_FILTER_STATE_CONNECTING := 1,PW_FILTER_STATE_PAUSED := 2,
      PW_FILTER_STATE_STREAMING := 3);

{$if 0}
  {*< the spa buffer  }
  {*< user data attached to the buffer  }
  {*< For input ports, this field is set by pw_filter
  					  *  with the duration of the buffer in ticks.
  					  *  For output ports, this field is set by the user.
  					  *  This field is added for all queued buffers and
  					  *  returned in the time info.  }

  type
    Ppw_buffer = ^pw_buffer;
    pw_buffer = record
        buffer : Pspa_buffer;
        user_data : pointer;
        size : uint64_t;
      end;

{$endif}
  {* Events for a filter. These events are always called from the mainloop
   * unless explicitly documented otherwise.  }
(* error 
#define PW_VERSION_FILTER_EVENTS	1
  {* when the filter state changes  }
  {* when io changed on a port of the filter (when port_data is NULL).  }
  {* when a parameter changed on a port of the filter (when port_data is NULL).  }
  {* when a new buffer was created for a port  }
  {* when a buffer was destroyed for a port  }
  {* do processing. This is normally called from the
  	 *  mainloop but can also be called directly from the realtime data
  	 *  thread if the user is prepared to deal with this.  }
  {* The filter is drained  }
  {* A command notify, Since 0.3.39:1  }
 in member_list *)

  type
    Ppw_filter_events = ^pw_filter_events;
    pw_filter_events = record
      end;

  {* Convert a filter state to a readable string   }
(* Const before type ignored *)

  function pw_filter_state_as_string(state:pw_filter_state):pcchar;cdecl;external;

  {* \enum pw_filter_flags Extra flags that can be used in \ref pw_filter_connect()   }
  {*< no flags  }
  {*< start the filter inactive,
  							  *  pw_filter_set_active() needs to be
  							  *  called explicitly  }
  {*< be a driver  }
  {*< call process from the realtime
  							  *  thread  }
  {*< don't call the default latency algorithm
  							  *  but emit the param_changed event for the
  							  *  ports when Latency params are received.  }
  {*< the filter will not be scheduled
  							  *  automatically but _trigger_process()
  							  *  needs to be called. This can be used
  							  *  when the filter depends on processing
  							  *  of other filters.  }
  {*< Buffers will not be dequeued/queued from
  							  *  the realtime process() function. This is
  							  *  assumed when RT_PROCESS is unset but can
  							  *  also be the case when the process() function
  							  *  does a trigger_process() that will then
  							  *  dequeue/queue a buffer from another process()
  							  *  function. since 0.3.73  }

  type
    pw_filter_flags = (PW_FILTER_FLAG_NONE := 0,PW_FILTER_FLAG_INACTIVE := 1 shl 0,
      PW_FILTER_FLAG_DRIVER := 1 shl 1,PW_FILTER_FLAG_RT_PROCESS := 1 shl 2,
      PW_FILTER_FLAG_CUSTOM_LATENCY := 1 shl 3,
      PW_FILTER_FLAG_TRIGGER := 1 shl 4,PW_FILTER_FLAG_ASYNC := 1 shl 5
      );

  {*< no flags  }
  {*< mmap the buffers except DmaBuf that is not
  								  *  explicitly marked as mappable.  }
  {*< the application will allocate buffer
  								  *  memory. In the add_buffer event, the
  								  *  data of the buffer should be set  }
    pw_filter_port_flags = (PW_FILTER_PORT_FLAG_NONE := 0,PW_FILTER_PORT_FLAG_MAP_BUFFERS := 1 shl 0,
      PW_FILTER_PORT_FLAG_ALLOC_BUFFERS := 1 shl 1
      );

  {* Create a new unconnected \ref pw_filter
   * \return a newly allocated \ref pw_filter  }
(* error 
struct pw_filter *
  {*< a \ref pw_core  }
  {*< a filter media name  }
  {*< filter properties, ownership is taken  }in declaration at line 135 *)
(* error 
struct pw_filter *
    {*< a \ref pw_loop to use  }
    {*< a filter media name  }
    {*< filter properties, ownership is taken  }
    {*< filter events  }
    {*< data passed to events  }in declaration at line 142 *)
    {* Destroy a filter   }

    procedure pw_filter_destroy(filter:Ppw_filter);cdecl;external;

(* Const before type ignored *)
    procedure pw_filter_add_listener(filter:Ppw_filter; listener:Pspa_hook; events:Ppw_filter_events; data:pointer);cdecl;external;

(* error 
enum pw_filter_state pw_filter_get_state(struct pw_filter *filter, const char **error);
in declaration at line 152 *)
(* Const before type ignored *)
    function pw_filter_get_name(filter:Ppw_filter):pcchar;cdecl;external;

(* error 
struct pw_core *pw_filter_get_core(struct pw_filter *filter);
in declaration at line 156 *)
    {* Connect a filter for processing.
     * \return 0 on success < 0 on error.
     *
     * You should connect to the process event and use pw_filter_dequeue_buffer()
     * to get the latest metadata and data.  }
    {*< a \ref pw_filter  }
    {*< filter flags  }
(* Const before type ignored *)
    {*< an array with params.  }
    {*< number of items in \a params  }    function pw_filter_connect(filter:Ppw_filter; flags:pw_filter_flags; params:PPspa_pod; n_params:uint32_t):cint;cdecl;external;

    {* Get the node ID of the filter.
     * \return node ID.  }
    function pw_filter_get_node_id(filter:Ppw_filter):uint32_t;cdecl;external;

    {* Disconnect \a filter   }
    function pw_filter_disconnect(filter:Ppw_filter):cint;cdecl;external;

    {* add a port to the filter, returns user data of port_data_size.  }
    {*< a \ref pw_filter  }
    {*< port direction  }
    {*< port flags  }
    {*< allocated and given to the user as port_data  }
    {*< port properties, ownership is taken  }
(* Const before type ignored *)
    {*< an array of params. The params should
    							  *  ideally contain the supported formats  }
    {*< number of elements in \a params  }    function pw_filter_add_port(filter:Ppw_filter; direction:pw_direction; flags:pw_filter_port_flags; port_data_size:size_t; props:Ppw_properties; 
               params:PPspa_pod; n_params:uint32_t):pointer;cdecl;external;

    {* remove a port from the filter  }
    {*< data associated with port  }    function pw_filter_remove_port(port_data:pointer):cint;cdecl;external;

    {* get properties, port_data of NULL will give global properties  }
(* Const before type ignored *)
    function pw_filter_get_properties(filter:Ppw_filter; port_data:pointer):Ppw_properties;cdecl;external;

    {* Update properties, use NULL port_data for global filter properties  }
(* Const before type ignored *)
    function pw_filter_update_properties(filter:Ppw_filter; port_data:pointer; dict:Pspa_dict):cint;cdecl;external;

    {* Set the filter in error state  }
    {*< a \ref pw_filter  }
    {*< a result code  }
(* Const before type ignored *)
    {*< an error message  }
(* error 
			) SPA_PRINTF_FUNC(3, 4);
(* error 
			) SPA_PRINTF_FUNC(3, 4);
 in declarator_list *)
 in declarator_list *)
    {* Update params, use NULL port_data for global filter params  }
    {*< a \ref pw_filter  }
    {*< data associated with port  }
(* Const before type ignored *)
    {*< an array of params.  }
    {*< number of elements in \a params  }    function pw_filter_update_params(filter:Ppw_filter; port_data:pointer; params:PPspa_pod; n_params:uint32_t):cint;cdecl;external;

    {* Query the time on the filter, deprecated, use the spa_io_position in the
     * process() method for timing information.  }
(* error 
int pw_filter_get_time(struct pw_filter *filter, struct pw_time *time);
in declaration at line 216 *)
    {* Get the current time in nanoseconds. This value can be compared with
     * the nsec value in the spa_io_position. Since 1.1.0  }
    function pw_filter_get_nsec(filter:Ppw_filter):uint64_t;cdecl;external;

    {* Get the data loop that is doing the processing of this filter. This loop
     * is assigned after pw_filter_connect().  * Since 1.1.0  }
(* error 
struct pw_loop *pw_filter_get_data_loop(struct pw_filter *filter);
in declaration at line 224 *)
    {* Get a buffer that can be filled for output ports or consumed
     * for input ports.   }
(* error 
struct pw_buffer *pw_filter_dequeue_buffer(void *port_data);
in declaration at line 228 *)
    {* Submit a buffer for playback or recycle a buffer for capture.  }
    function pw_filter_queue_buffer(port_data:pointer; buffer:Ppw_buffer):cint;cdecl;external;

    {* Get a data pointer to the buffer data  }
    function pw_filter_get_dsp_buffer(port_data:pointer; n_samples:uint32_t):pointer;cdecl;external;

    {* Activate or deactivate the filter   }
    function pw_filter_set_active(filter:Ppw_filter; active:bool):cint;cdecl;external;

    {* Flush a filter. When \a drain is true, the drained callback will
     * be called when all data is played or recorded. The filter can be resumed
     * after the drain by setting it active again with
     * \ref pw_filter_set_active(). A flush without a drain is mostly useful afer
     * a state change to PAUSED, to flush any remaining data from the queues.  }
    function pw_filter_flush(filter:Ppw_filter; drain:bool):cint;cdecl;external;

    {* Check if the filter is driving. The filter needs to have the
     * PW_FILTER_FLAG_DRIVER set. When the filter is driving,
     * pw_filter_trigger_process() needs to be called when data is
     * available (output) or needed (input). Since 0.3.66  }
    function pw_filter_is_driving(filter:Ppw_filter):bool;cdecl;external;

    {* Check if the graph is using lazy scheduling.
     * Since 1.2.7  }
    function pw_filter_is_lazy(filter:Ppw_filter):bool;cdecl;external;

    {* Trigger a push/pull on the filter. One iteration of the graph will
     * be scheduled and process() will be called. Since 0.3.66  }
    function pw_filter_trigger_process(filter:Ppw_filter):cint;cdecl;external;

    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_FILTER_H  }

