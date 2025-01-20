{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{ C++ extern C conditionnal removed }




  {* \defgroup pw_map Map
   *
   * \brief A map that holds pointers to objects indexed by id
   *
   * The map is a sparse version of the \ref pw_array "pw_array" that manages the
   * indices of elements for the caller. Adding items with
   * pw_map_insert_new() returns the assigned index for that item; if items
   * are removed the map re-uses indices to keep the array at the minimum
   * required size.
   *
   * \code.c
   * struct pw_map map = PW_MAP_INIT(4);
   *
   * idx1 = pw_map_insert_new(&map, ptr1);
   * idx2 = pw_map_insert_new(&map, ptr2);
   * // the map is now [ptr1, ptr2], size 2
   * pw_map_remove(&map, idx1);
   * // the map is now [<unused>, ptr2], size 2
   * pw_map_insert_new(&map, ptr3);
   * // the map is now [ptr3, ptr2], size 2
   * \endcode
    }
  {*
   * \addtogroup pw_map
   * \
    }
  {* \private
   * An entry in the map. This is used internally only. Each element in the
   * backing pw_array is a union pw_map_item. For real items, the data pointer
   * points to the item. If an element has been removed, pw_map->free_list
   * is the index of the most recently removed item. That item contains
   * the index of the next removed item until item->next is SPA_ID_INVALID.
   *
   * The free list is prepended only, the last item to be removed will be the
   * first item to get re-used on the next insert.
    }
  { next free index  }
  { data of this item, must be an even address  }

  type
    Ppw_map_item = ^pw_map_item;
    pw_map_item = record
        case longint of
          0 : ( next : uintptr_t );
          1 : ( data : pointer );
        end;

  {* A map. This struct should be treated as opaque by the caller.  }
  { an array with the map items  }
  { first free index  }
    Ppw_map = ^pw_map;
    pw_map = record
        items : pw_array;
        free_list : uint32_t;
      end;

  {* \param extend the amount of bytes to grow the map with when needed  }
(* error 
#define PW_MAP_INIT(extend) ((struct pw_map) { PW_ARRAY_INIT(extend), SPA_ID_INVALID })
in define line 68 *)
    {*
     * Get the number of currently allocated elements in the map.
     * \note pw_map_get_size() returns the currently allocated number of
     * elements in the map, not the number of actually set elements.
     * \return the number of available elements before the map needs to grow
      }
(* error 
#define pw_map_get_size(m)            pw_array_get_len(&(m)->items, union pw_map_item)
in define line 76 *)
(* error 
#define pw_map_get_item(m,id)         pw_array_get_unchecked(&(m)->items,id,union pw_map_item)
in define line 77 *)
    { was #define dname(params) para_def_expr }
    { argument types are unknown }
    { return type might be wrong }   
