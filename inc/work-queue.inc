    Type
    Ppw_work_queue  = ^pw_work_queue;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_WORK_QUEUE_H}
{$define PIPEWIRE_WORK_QUEUE_H}  
{ C++ extern C conditionnal removed }
  {* \defgroup pw_work_queue Work Queue
   * Queued processing of work items.
    }
  {*
   * \addtogroup pw_work_queue
   * \
    }

  type
    Ppw_work_queue = ^pw_work_queue;
    pw_work_queue = record
        {undefined structure}
      end;



  type

    pw_work_func_t = procedure (obj:pointer; data:pointer; res:cint; id:uint32_t);cdecl;
(* error 
struct pw_work_queue *
in declaration at line 27 *)

    procedure pw_work_queue_destroy(queue:Ppw_work_queue);cdecl;external External_library name 'pw_work_queue_destroy';

    function pw_work_queue_add(queue:Ppw_work_queue; obj:pointer; res:cint; func:pw_work_func_t; data:pointer):uint32_t;cdecl;external External_library name 'pw_work_queue_add';

    function pw_work_queue_cancel(queue:Ppw_work_queue; obj:pointer; id:uint32_t):cint;cdecl;external External_library name 'pw_work_queue_cancel';

    function pw_work_queue_complete(queue:Ppw_work_queue; obj:pointer; seq:uint32_t; res:cint):cint;cdecl;external External_library name 'pw_work_queue_complete';

    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_WORK_QUEUE_H  }

