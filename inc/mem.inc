    Type
    Ppw_map_range  = ^pw_map_range;
    Ppw_memblock  = ^pw_memblock;
    Ppw_memblock_flags  = ^pw_memblock_flags;
    Ppw_memchunk  = ^pw_memchunk;
    Ppw_memmap  = ^pw_memmap;
    Ppw_memmap_flags  = ^pw_memmap_flags;
    Ppw_mempool  = ^pw_mempool;
    Ppw_mempool_events  = ^pw_mempool_events;
    Ppw_properties  = ^pw_properties;
    Pspa_hook  = Pointer; {$WARNING ^spa_hook}
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_MEM_H}
{$define PIPEWIRE_MEM_H}  

{ C++ extern C conditionnal removed }
  {* \defgroup pw_memblock Memory Blocks
   * Memory allocation and pools.
    }
  {*
   * \addtogroup pw_memblock
   * \
    }
  {* Flags passed to \ref pw_mempool_alloc()  }
  {*< memory is readable  }
  {*< memory is writable  }
  {*< seal the fd  }
  {*< mmap the fd  }
  {*< don't close fd  }
  {*< don't notify events  }
  {*< the fd can not be mmapped  }

  type
    pw_memblock_flags = (PW_MEMBLOCK_FLAG_NONE := 0,PW_MEMBLOCK_FLAG_READABLE := 1 shl 0,
      PW_MEMBLOCK_FLAG_WRITABLE := 1 shl 1,PW_MEMBLOCK_FLAG_SEAL := 1 shl 2,
      PW_MEMBLOCK_FLAG_MAP := 1 shl 3,PW_MEMBLOCK_FLAG_DONT_CLOSE := 1 shl 4,
      PW_MEMBLOCK_FLAG_DONT_NOTIFY := 1 shl 5,PW_MEMBLOCK_FLAG_UNMAPPABLE := 1 shl 6,
      PW_MEMBLOCK_FLAG_READWRITE := PW_MEMBLOCK_FLAG_READABLE or PW_MEMBLOCK_FLAG_WRITABLE);

  {*< map in read mode  }
  {*< map in write mode  }
  {*< map the same area twice after each other,
  							  *  creating a circular ringbuffer  }
  {*< writes will be private  }
  {*< lock the memory into RAM  }
    pw_memmap_flags = (PW_MEMMAP_FLAG_NONE := 0,PW_MEMMAP_FLAG_READ := 1 shl 0,
      PW_MEMMAP_FLAG_WRITE := 1 shl 1,PW_MEMMAP_FLAG_TWICE := 1 shl 2,
      PW_MEMMAP_FLAG_PRIVATE := 1 shl 3,PW_MEMMAP_FLAG_LOCKED := 1 shl 4,
      PW_MEMMAP_FLAG_READWRITE := PW_MEMMAP_FLAG_READ or PW_MEMMAP_FLAG_WRITE);

    Ppw_memchunk = ^pw_memchunk;
    pw_memchunk = record
        {undefined structure}
      end;

  {*
   *
   * A memory pool is a collection of pw_memblocks  }
    Ppw_mempool = ^pw_mempool;
    pw_mempool = record
        props : Ppw_properties;
      end;

  {*
   * Memory block structure  }
  {*< owner pool  }
  {*< unique id  }
  {*< refcount  }
  {*< flags for the memory block on of enum pw_memblock_flags  }
  {*< type of the fd, one of enum spa_data_type  }
  {*< fd  }
  {*< size of memory  }
  {*< optional map when PW_MEMBLOCK_FLAG_MAP was given  }
    Ppw_memblock = ^pw_memblock;
    pw_memblock = record
        pool : Ppw_mempool;
        id : uint32_t;
        ref : cint;
        flags : uint32_t;
        _type : uint32_t;
        fd : cint;
        size : uint32_t;
        map : Ppw_memmap;
      end;

  {* a mapped region of a pw_memblock  }
  {*< owner memblock  }
  {*< mapped pointer  }
  {*< flags for the mapping on of enum pw_memmap_flags  }
  {*< offset in memblock  }
  {*< size in memblock  }
  {*< user tag  }
    Ppw_memmap = ^pw_memmap;
    pw_memmap = record
        block : Ppw_memblock;
        ptr : pointer;
        flags : uint32_t;
        offset : uint32_t;
        size : uint32_t;
        tag : array[0..4] of uint32_t;
      end;

(* error 
#define PW_VERSION_MEMPOOL_EVENTS	0
  {* the pool is destroyed  }
  {* a new memory block is added to the pool  }
  {* a memory block is removed from the pool  }
 in member_list *)
    Ppw_mempool_events = ^pw_mempool_events;
    pw_mempool_events = record
      end;

  {* Create a new memory pool  }
(* error 
struct pw_mempool *pw_mempool_new(struct pw_properties *props);
in declaration at line 95 *)
    {* Listen for events  }


    procedure pw_mempool_add_listener(pool:Ppw_mempool; listener:Pspa_hook; events:Ppw_mempool_events; data:pointer);cdecl;external;

    {* Clear a pool  }
    procedure pw_mempool_clear(pool:Ppw_mempool);cdecl;external;

    {* Clear and destroy a pool  }
    procedure pw_mempool_destroy(pool:Ppw_mempool);cdecl;external;

    {* Allocate a memory block from the pool  }
(* error 
struct pw_memblock * pw_mempool_alloc(struct pw_mempool *pool,
in declaration at line 112 *)
    {* Import a block from another pool  }
(* error 
struct pw_memblock * pw_mempool_import_block(struct pw_mempool *pool,
in declaration at line 116 *)
    {* Import an fd into the pool  }
(* error 
struct pw_memblock * pw_mempool_import(struct pw_mempool *pool,
in declaration at line 120 *)
    {* Free a memblock regardless of the refcount and destroy all mappings  }
    procedure pw_memblock_free(mem:Ppw_memblock);cdecl;external;

    {* Unref a memblock  }
(* error 
static inline void pw_memblock_unref(struct pw_memblock *mem)
 in declarator_list *)
(* error 
	if (--mem->ref == 0)
 in declarator_list *)
(* error 
}
    {* Remove a memblock for given \a id  }
in declaration at line 133 *)
    {* Find memblock for given \a ptr  }
(* error 
struct pw_memblock * pw_mempool_find_ptr(struct pw_mempool *pool, const void *ptr);
in declaration at line 136 *)
    {* Find memblock for given \a id  }
(* error 
struct pw_memblock * pw_mempool_find_id(struct pw_mempool *pool, uint32_t id);
in declaration at line 139 *)
    {* Find memblock for given \a fd  }
(* error 
struct pw_memblock * pw_mempool_find_fd(struct pw_mempool *pool, int fd);
in declaration at line 142 *)
    {* Map a region of a memory block  }
(* error 
struct pw_memmap * pw_memblock_map(struct pw_memblock *block,
in declaration at line 148 *)
    {* Map a region of a memory block with \a id  }
(* error 
struct pw_memmap * pw_mempool_map_id(struct pw_mempool *pool, uint32_t id,
in declaration at line 153 *)
(* error 
struct pw_memmap * pw_mempool_import_map(struct pw_mempool *pool,
in declaration at line 156 *)
    {* find a map with the given tag  }
(* error 
struct pw_memmap * pw_mempool_find_tag(struct pw_mempool *pool, uint32_t tag[5], size_t size);
in declaration at line 159 *)
    {* Unmap a region  }
    function pw_memmap_free(map:Ppw_memmap):cint;cdecl;external;

    {* parameters to map a memory range  }
    {* offset in first page with start of data  }
    {* page aligned offset to map  }
    {* size to map  }

    type
      Ppw_map_range = ^pw_map_range;
      pw_map_range = record
          start : uint32_t;
          offset : uint32_t;
          size : uint32_t;
        end;

(* error 
#define PW_MAP_RANGE_INIT (struct pw_map_range){ 0, }
in define line 172 *)
    {* Calculate parameters to mmap() memory into \a range so that
     * \a size bytes at \a offset can be mapped with mmap().   }
(* error 
static inline void pw_map_range_init(struct pw_map_range *range,
(* error 
				     uint32_t offset, uint32_t size,
(* error 
				     uint32_t offset, uint32_t size,
(* error 
				     uint32_t page_size)
 in declarator_list *)
 in declarator_list *)
 in declarator_list *)
 in declarator_list *)
(* error 
	range->offset = SPA_ROUND_DOWN_N(offset, page_size);
(* error 
	range->offset = SPA_ROUND_DOWN_N(offset, page_size);
 in declarator_list *)
 in declarator_list *)
(* error 
	range->start = offset - range->offset;
(* error 
	range->start = offset - range->offset;
 in declarator_list *)
(* error 
	range->size = SPA_ROUND_UP_N(range->start + size, page_size);
(* error 
	range->size = SPA_ROUND_UP_N(range->start + size, page_size);
(* error 
	range->size = SPA_ROUND_UP_N(range->start + size, page_size);
 in declarator_list *)
 in declarator_list *)
(* error 
}
    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_MEM_H  }

