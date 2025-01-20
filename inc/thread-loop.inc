    Type
    Ppw_thread_loop  = ^pw_thread_loop;
    Ppw_thread_loop_events  = ^pw_thread_loop_events;
    Pspa_hook  = Pointer; {$WARNING ^spa_hook}
    Ptimespec  = ^timespec;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_THREAD_LOOP_H}
{$define PIPEWIRE_THREAD_LOOP_H}  
{ C++ extern C conditionnal removed }

  {* \page page_thread_loop Thread Loop
   *
   * \see \ref pw_thread_loop
   *
   * \section sec_thread_loop_overview Overview
   *
   * The threaded loop implementation is a special wrapper around the
   * regular \ref pw_loop implementation.
   *
   * The added feature in the threaded loop is that it spawns a new thread
   * that runs the wrapped loop. This allows a synchronous application to use
   * the asynchronous API without risking to stall the PipeWire library.
   *
   * \section sec_thread_loop_create Creation
   *
   * A \ref pw_thread_loop object is created using pw_thread_loop_new().
   * The \ref pw_loop to wrap must be given as an argument along with the name
   * for the thread that will be spawned.
   *
   * After allocating the object, the thread must be started with
   * pw_thread_loop_start()
   *
   * \section sec_thread_loop_destruction Destruction
   *
   * When the PipeWire connection has been terminated, the thread must be
   * stopped and the resources freed. Stopping the thread is done using
   * pw_thread_loop_stop(), which must be called without the lock (see
   * below) held. When that function returns, the thread is stopped and the
   * \ref pw_thread_loop object can be freed using pw_thread_loop_destroy().
   *
   * \section sec_thread_loop_locking Locking
   *
   * Since the PipeWire API doesn't allow concurrent accesses to objects,
   * a locking scheme must be used to guarantee safe usage. The threaded
   * loop API provides such a scheme through the functions
   * pw_thread_loop_lock() and pw_thread_loop_unlock().
   *
   * The lock is recursive, so it's safe to use it multiple times from the same
   * thread. Just make sure you call pw_thread_loop_unlock() the same
   * number of times you called pw_thread_loop_lock().
   *
   * The lock needs to be held whenever you call any PipeWire function that
   * uses an object associated with this loop. Make sure you do not hold
   * on to the lock more than necessary though, as the threaded loop stops
   * while the lock is held.
   *
   * \section sec_thread_loop_events Events and Callbacks
   *
   * All events and callbacks are called with the thread lock held.
   *
    }
  {* \defgroup pw_thread_loop Thread Loop
   *
   * The threaded loop object runs a \ref pw_loop in a separate thread
   * and ensures proper locking is done.
   *
   * All of the loop callbacks will be executed with the loop
   * lock held.
   *
   * \see \ref page_thread_loop
    }
  {*
   * \addtogroup pw_thread_loop
   * \
    }

  type
    Ppw_thread_loop = ^pw_thread_loop;
    pw_thread_loop = record
        {undefined structure}
      end;

  {* Thread loop events  }
(* error 
#define PW_VERSION_THREAD_LOOP_EVENTS	0
  {* the loop is destroyed  }
 in member_list *)
    Ppw_thread_loop_events = ^pw_thread_loop_events;
    pw_thread_loop_events = record
      end;

  {* Make a new thread loop with the given name and optional properties.  }
(* error 
struct pw_thread_loop *
in declaration at line 93 *)
    {* Make a new thread loop with the given loop, name and optional properties.
     * When \a loop is NULL, a new loop will be created.  }
(* error 
struct pw_thread_loop *
in declaration at line 98 *)
    {* Destroy a thread loop  }

    procedure pw_thread_loop_destroy(loop:Ppw_thread_loop);cdecl;external;

    {* Add an event listener  }

    procedure pw_thread_loop_add_listener(loop:Ppw_thread_loop; listener:Pspa_hook; events:Ppw_thread_loop_events; data:pointer);cdecl;external;

    {* Get the loop implementation of the thread loop  }
(* error 
struct pw_loop * pw_thread_loop_get_loop(struct pw_thread_loop *loop);
in declaration at line 110 *)
    {* Start the thread loop  }
    function pw_thread_loop_start(loop:Ppw_thread_loop):cint;cdecl;external;

    {* Stop the thread loop  }
    procedure pw_thread_loop_stop(loop:Ppw_thread_loop);cdecl;external;

    {* Lock the loop. This ensures exclusive ownership of the loop  }
    procedure pw_thread_loop_lock(loop:Ppw_thread_loop);cdecl;external;

    {* Unlock the loop  }
    procedure pw_thread_loop_unlock(loop:Ppw_thread_loop);cdecl;external;

    {* Release the lock and wait until some thread calls \ref pw_thread_loop_signal  }
    procedure pw_thread_loop_wait(loop:Ppw_thread_loop);cdecl;external;

    {* Release the lock and wait a maximum of 'wait_max_sec' seconds
     *  until some thread calls \ref pw_thread_loop_signal or time out  }
    function pw_thread_loop_timed_wait(loop:Ppw_thread_loop; wait_max_sec:cint):cint;cdecl;external;

    {* Get a struct timespec suitable for \ref pw_thread_loop_timed_wait_full.
     * Since: 0.3.7  }
    function pw_thread_loop_get_time(loop:Ppw_thread_loop; abstime:Ptimespec; timeout:int64_t):cint;cdecl;external;

    {* Release the lock and wait up to \a abstime until some thread calls
     * \ref pw_thread_loop_signal. Use \ref pw_thread_loop_get_time to make a timeout.
     * Since: 0.3.7  }

    function pw_thread_loop_timed_wait_full(loop:Ppw_thread_loop; abstime:Ptimespec):cint;cdecl;external;

    {* Signal all threads waiting with \ref pw_thread_loop_wait  }
    procedure pw_thread_loop_signal(loop:Ppw_thread_loop; wait_for_accept:bool);cdecl;external;

    {* Signal all threads executing \ref pw_thread_loop_signal with wait_for_accept  }
    procedure pw_thread_loop_accept(loop:Ppw_thread_loop);cdecl;external;

    {* Check if inside the thread  }
    function pw_thread_loop_in_thread(loop:Ppw_thread_loop):bool;cdecl;external;

    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_THREAD_LOOP_H  }

