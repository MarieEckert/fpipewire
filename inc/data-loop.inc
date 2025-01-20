    Type
    Pspa_hook  = Pointer; {$WARNING ^spa_hook}
    Pspa_thread_utils  = Pointer; {$WARNING ^spa_thread_utils}
    spa_invoke_func_t = Pointer; {$WARNING spa_invoke_func_t}
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_DATA_LOOP_H}
{$define PIPEWIRE_DATA_LOOP_H}  
{ C++ extern C conditionnal removed }


  {* \defgroup pw_data_loop Data Loop
   *
   * \brief PipeWire rt-loop object
   *
   * This loop starts a new real-time thread that
   * is designed to run the processing graph.
    }
  {*
   * \addtogroup pw_data_loop
   * \
    }

  type
    Ppw_data_loop = ^pw_data_loop;
    pw_data_loop = record
        {undefined structure}
      end;



  {* Loop events, use \ref pw_data_loop_add_listener to add a listener  }
(* error 
#define PW_VERSION_DATA_LOOP_EVENTS		0
  {* The loop is destroyed  }
 in member_list *)

  type
    Ppw_data_loop_events = ^pw_data_loop_events;
    pw_data_loop_events = record
      end;

  {* Make a new loop.  }
(* error 
struct pw_data_loop *
in declaration at line 42 *)
    {* Add an event listener to loop  }


    procedure pw_data_loop_add_listener(loop:Ppw_data_loop; listener:Pspa_hook; events:Ppw_data_loop_events; data:pointer);cdecl;external External_library name 'pw_data_loop_add_listener';

    {* wait for activity on the loop up to \a timeout milliseconds.
     * Should be called from the loop function  }
    function pw_data_loop_wait(loop:Ppw_data_loop; timeout:cint):cint;cdecl;external External_library name 'pw_data_loop_wait';

    {* make sure the thread will exit. Can be called from a loop callback  }
    procedure pw_data_loop_exit(loop:Ppw_data_loop);cdecl;external External_library name 'pw_data_loop_exit';

    {* Get the loop implementation of this data loop  }
(* error 
struct pw_loop *
in declaration at line 59 *)
    {* Get the loop name. Since 1.1.0  }

    function pw_data_loop_get_name(loop:Ppw_data_loop):pcchar;cdecl;external External_library name 'pw_data_loop_get_name';

    {* Get the loop class. Since 1.1.0  }

    function pw_data_loop_get_class(loop:Ppw_data_loop):pcchar;cdecl;external External_library name 'pw_data_loop_get_class';

    {* Destroy the loop  }
    procedure pw_data_loop_destroy(loop:Ppw_data_loop);cdecl;external External_library name 'pw_data_loop_destroy';

    {* Start the processing thread  }
    function pw_data_loop_start(loop:Ppw_data_loop):cint;cdecl;external External_library name 'pw_data_loop_start';

    {* Stop the processing thread  }
    function pw_data_loop_stop(loop:Ppw_data_loop):cint;cdecl;external External_library name 'pw_data_loop_stop';

    {* Check if the current thread is the processing thread.
     * May be called from any thread.  }
    function pw_data_loop_in_thread(loop:Ppw_data_loop):bool;cdecl;external External_library name 'pw_data_loop_in_thread';

    {* Get the thread object  }
(* error 
struct spa_thread *pw_data_loop_get_thread(struct pw_data_loop *loop);
in declaration at line 79 *)
    {* invoke func in the context of the thread or in the caller thread when
     * the loop is not running. May be called from the loop's thread, but otherwise
     * can only be called by a single thread at a time.
     * If called from the loop's thread, all callbacks previously queued with
     * pw_data_loop_invoke() will be run synchronously, which might cause
     * unexpected reentrancy problems.
     *
     * \param[in] loop The loop to invoke func on.
     * \param func The function to be invoked.
     * \param seq A sequence number, opaque to PipeWire. This will be made
     *            available to func.
     * \param[in] data Data that will be copied into the internal ring buffer and made
     *             available to func. Because this data is copied, it is okay to
     *             pass a pointer to a local variable, but do not pass a pointer to
     *             an object that has identity.
     * \param size The size of data to copy.
     * \param block If \true, do not return until func has been called. Otherwise,
     *              returns immediately. Passing \true does not risk a deadlock because
     *              the data thread is never allowed to wait on any other thread.
     * \param user_data An opaque pointer passed to func.
     * \return `-EPIPE` if the internal ring buffer filled up,
     *         if block is \false, 0 is returned when seq is SPA_ID_INVALID or the
     *         sequence number with the ASYNC bit set otherwise. When block is \true,
     *         the return value of func is returned.
     *
     * Since 0.3.3  }

    function pw_data_loop_invoke(loop:Ppw_data_loop; func:spa_invoke_func_t; seq:uint32_t; data:pointer; size:size_t; 
               block:bool; user_data:pointer):cint;cdecl;external External_library name 'pw_data_loop_invoke';

    {* Set a custom spa_thread_utils for this loop. Setting NULL restores the
     * system default implementation. Since 0.3.50  }
    procedure pw_data_loop_set_thread_utils(loop:Ppw_data_loop; impl:Pspa_thread_utils);cdecl;external External_library name 'pw_data_loop_set_thread_utils';

    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_DATA_LOOP_H  }

