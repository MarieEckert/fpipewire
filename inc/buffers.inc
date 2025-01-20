  Type
  Ppw_buffers  = ^pw_buffers;
  Ppw_context  = ^pw_context;
  Ppw_memblock  = ^pw_memblock;
  Pspa_buffer  = Pointer; {$WARNING ^spa_buffer}
  Pspa_node  = Pointer; {$WARNING ^spa_node}
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2019 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_BUFFERS_H}
{$define PIPEWIRE_BUFFERS_H}  



{ C++ extern C conditionnal removed }
  {* \defgroup pw_buffers Buffers
   * Buffer handling
    }
  {*
   * \addtogroup pw_buffers
   * \
    }

  const
    PW_BUFFERS_FLAG_NONE = 0;    
  {*< don't allocate buffer memory  }
    PW_BUFFERS_FLAG_NO_MEM = 1 shl 0;    
  {*< buffers can be shared  }
    PW_BUFFERS_FLAG_SHARED = 1 shl 1;    
  {*< buffers have dynamic data  }
    PW_BUFFERS_FLAG_DYNAMIC = 1 shl 2;    
  {*< buffers need shared memory  }
    PW_BUFFERS_FLAG_SHARED_MEM = 1 shl 3;    
  {*< input parameters have priority  }
    PW_BUFFERS_FLAG_IN_PRIORITY = 1 shl 4;    
  {*< one of the nodes is async  }
    PW_BUFFERS_FLAG_ASYNC = 1 shl 5;    
  {*< allocated buffer memory  }
  {*< port buffers  }
  {*< number of port buffers  }
  {*< flags  }

  type
    Ppw_buffers = ^pw_buffers;
    pw_buffers = record
        mem : Ppw_memblock;
        buffers : ^Pspa_buffer;
        n_buffers : uint32_t;
        flags : uint32_t;
      end;


  function pw_buffers_negotiate(context:Ppw_context; flags:uint32_t; outnode:Pspa_node; out_port_id:uint32_t; innode:Pspa_node; 
             in_port_id:uint32_t; result:Ppw_buffers):cint;cdecl;external;

  procedure pw_buffers_clear(buffers:Ppw_buffers);cdecl;external;

  {*
   * \
    }
{ C++ end of extern C conditionnal removed }
{$endif}
  { PIPEWIRE_BUFFERS_H  }

