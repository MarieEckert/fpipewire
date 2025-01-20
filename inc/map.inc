    Type
    Ppw_map  = ^pw_map;
    Ppw_map_item  = ^pw_map_item;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_MAP_H}
{$define PIPEWIRE_MAP_H}  
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

    function pw_map_item_is_free(item : longint) : longint;    

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_map_id_is_free(m,id : longint) : longint;  

  {* \return true if the id fits within the current map size  }
  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_map_check_id(m,id : longint) : longint;  

  {* \return true if there is a valid item at \a id   }
  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_map_has_item(m,id : longint) : longint;  

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_map_lookup_unchecked(m,id : longint) : longint;  

  {* Convert an id to a pointer that can be inserted into the map  }
  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function PW_MAP_ID_TO_PTR(id : longint) : longint;  

  {* Convert a pointer to an id that can be retrieved from the map  }
  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function PW_MAP_PTR_TO_ID(p : longint) : longint;  

  {* Initialize a map
   * \param map the map to initialize
   * \param size the initial size of the map
   * \param extend the amount to bytes to grow the map with when needed
    }
(* error 
static inline void pw_map_init(struct pw_map *map, size_t size, size_t extend)
(* error 
static inline void pw_map_init(struct pw_map *map, size_t size, size_t extend)
(* error 
static inline void pw_map_init(struct pw_map *map, size_t size, size_t extend)
 in declarator_list *)
 in declarator_list *)
 in declarator_list *)
(* error 
	pw_array_init(&map->items, extend * sizeof(union pw_map_item));
(* error 
	pw_array_init(&map->items, extend * sizeof(union pw_map_item));
 in declarator_list *)
 in declarator_list *)
(* error 
	pw_array_ensure_size(&map->items, size * sizeof(union pw_map_item));
(* error 
	pw_array_ensure_size(&map->items, size * sizeof(union pw_map_item));
 in declarator_list *)
 in declarator_list *)
(* error 
	map->free_list = SPA_ID_INVALID;
(* error 
	map->free_list = SPA_ID_INVALID;
 in declarator_list *)
(* error 
}
  {* Clear a map and free the data storage. All previously returned ids
   * must be treated as invalid.
    }
in declaration at line 108 *)
(* error 
}
    {* Reset a map but keep previously allocated storage. All previously
     * returned ids must be treated as invalid.
      }
in declaration at line 116 *)
(* error 
	map->free_list = SPA_ID_INVALID;
(* error 
	map->free_list = SPA_ID_INVALID;
 in declarator_list *)
(* error 
}
    {* Insert data in the map. This function causes the map to grow if required.
     * \param map the map to insert into
     * \param data the item to add
     * \return the id where the item was inserted or SPA_ID_INVALID when the
     *	item can not be inserted.
      }
in declaration at line 128 *)

      var
        id : uint32_t;cvar;public;
(* error 
	if (map->free_list != SPA_ID_INVALID) {
 in declarator_list *)
(* error 
		start = (union pw_map_item *) map->items.data;
 in declarator_list *)
(* error 
		item = &start[map->free_list >> 1]; /* lsb always 1, see pw_map_remove */
in declaration at line 133 *)
    { lsb always 1, see pw_map_remove  }
(* error 
		map->free_list = item->next;
(* error 
		map->free_list = item->next;
 in declarator_list *)
(* error 
	} else {
in declaration at line 136 *)
(* error 
		if (item == NULL)
 in declarator_list *)
(* error 
		start = (union pw_map_item *) map->items.data;
in declaration at line 139 *)
(* error 
	}
in declaration at line 141 *)
(* error 
	id = (item - start);
in declaration at line 142 *)
        id : return;cvar;public;
(* error 
}
    {* Replace the data in the map at an index.
     *
     * \param map the map to insert into
     * \param id the index to insert at, must be less or equal to pw_map_get_size()
     * \param data the data to insert
     * \return 0 on success, -ENOSPC value when the index is invalid or a negative errno
      }
in declaration at line 155 *)
(* error 
	union pw_map_item *item;
in declaration at line 156 *)
(* error 
	if (id > size)
 in declarator_list *)
(* error 
	else if (id == size) {
 in declarator_list *)
(* error 
		item = (union pw_map_item *) pw_array_add(&map->items, sizeof(union pw_map_item));
(* error 
		item = (union pw_map_item *) pw_array_add(&map->items, sizeof(union pw_map_item));
 in declarator_list *)
 in declarator_list *)
 : else;
(* error 
		if (item == NULL)
 in declarator_list *)
(* error 
	} else {
in declaration at line 165 *)
(* error 
			return -EINVAL;
 in declarator_list *)
 : if;
(* error 
	}
in declaration at line 169 *)
(* error 
	return 0;
in declaration at line 170 *)
(* error 
}
    {* Remove an item at index. The id may get re-used in the future.
     *
     * \param map the map to remove from
     * \param id the index to remove
      }
in declaration at line 181 *)
(* error 
	pw_map_get_item(map, id)->next = map->free_list;
(* error 
	pw_map_get_item(map, id)->next = map->free_list;
 in declarator_list *)
 in declarator_list *)
(* error 
	map->free_list = (id << 1) | 1;
(* error 
	map->free_list = (id << 1) | 1;
 in declarator_list *)
(* error 
}
    {* Find an item in the map
     * \param map the map to use
     * \param id the index to look at
     * \return the item at \a id or NULL when no such item exists
      }
in declaration at line 195 *)
(* error 
		if (!pw_map_item_is_free(item))
 in declarator_list *)
(* error 
	}
in declaration at line 199 *)
(* error 
}
    {* Iterate all map items
     * \param map the map to iterate
     * \param func the function to call for each item, the item data and \a data is
     *		passed to the function. When \a func returns a non-zero result,
     *		iteration ends and the result is returned.
     * \param data data to pass to \a func
     * \return the result of the last call to \a func or 0 when all callbacks returned 0.
      }
in declaration at line 213 *)
(* error 
	int res = 0;
 in declarator_list *)
(* error 
	pw_array_for_each(item, &map->items) {
(* error 
	pw_array_for_each(item, &map->items) {
 in declarator_list *)
 in declarator_list *)
(* error 
			if ((res = func(item->data, data)) != 0)
(* error 
			if ((res = func(item->data, data)) != 0)
 in declarator_list *)
 in declarator_list *)
(* error 
	}
in declaration at line 221 *)
(* error 
}
    {*
     * \
      }
{$endif}
    { PIPEWIRE_MAP_H  }
    { was #define dname(params) para_def_expr }
    { argument types are unknown }
    { return type might be wrong }   
    function pw_map_item_is_free(item : longint) : longint;
    begin
      pw_map_item_is_free:=(item^.next) and $1;
    end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_map_id_is_free(m,id : longint) : longint;
  begin
    pw_map_id_is_free:=pw_map_item_is_free(pw_map_get_item(m,id));
  end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_map_check_id(m,id : longint) : longint;
  begin
    pw_map_check_id:=id<(pw_map_get_size(m));
  end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_map_has_item(m,id : longint) : longint;
  begin
    pw_map_has_item:=(pw_map_check_id(m,id)) and (@( not (pw_map_id_is_free(m,id))));
  end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function pw_map_lookup_unchecked(m,id : longint) : longint;
  begin
    pw_map_lookup_unchecked:=(pw_map_get_item(m,id))^.data;
  end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function PW_MAP_ID_TO_PTR(id : longint) : longint;
  begin
    PW_MAP_ID_TO_PTR:=SPA_UINT32_TO_PTR(id shl 1);
  end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function PW_MAP_PTR_TO_ID(p : longint) : longint;
  begin
    PW_MAP_PTR_TO_ID:=(SPA_PTR_TO_UINT32(p)) shr 1;
  end;


