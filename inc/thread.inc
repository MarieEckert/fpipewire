    Type
    Pspa_dict  = Pointer; {$WARNING ^spa_dict}
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2021 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_THREAD_H}
{$define PIPEWIRE_THREAD_H}  
{ C++ extern C conditionnal removed }



  {* \defgroup pw_thread Thread
   *
   * \brief functions to manipulate threads
    }
  {*
   * \addtogroup pw_thread
   * \
    }
(* error 
void pw_thread_utils_set(struct spa_thread_utils *impl);
in declaration at line 28 *)
(* error 
struct spa_thread_utils *pw_thread_utils_get(void);
in declaration at line 29 *)


    function pw_thread_fill_attr(props:Pspa_dict; attr:pointer):pointer;cdecl;external External_library name 'pw_thread_fill_attr';

(* error 
#define pw_thread_utils_create(...)		spa_thread_utils_create(pw_thread_utils_get(), ##__VA_ARGS__)
in define line 32 *)
(* error 
#define pw_thread_utils_join(...)		spa_thread_utils_join(pw_thread_utils_get(), ##__VA_ARGS__)
in define line 33 *)
(* error 
#define pw_thread_utils_get_rt_range(...)	spa_thread_utils_get_rt_range(pw_thread_utils_get(), ##__VA_ARGS__)
in define line 34 *)
(* error 
#define pw_thread_utils_acquire_rt(...)		spa_thread_utils_acquire_rt(pw_thread_utils_get(), ##__VA_ARGS__)
in define line 35 *)
(* error 
#define pw_thread_utils_drop_rt(...)		spa_thread_utils_drop_rt(pw_thread_utils_get(), ##__VA_ARGS__)
in define line 36 *)
    {*
     * \
      }
{$endif}
    { PIPEWIRE_THREAD_H  }

