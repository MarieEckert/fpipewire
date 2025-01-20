    Type
    Ppw_metadata  = ^pw_metadata;
    Ppw_metadata_events  = ^pw_metadata_events;
    Ppw_metadata_methods  = ^pw_metadata_methods;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2019 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_EXT_METADATA_H}
{$define PIPEWIRE_EXT_METADATA_H}  
{ C++ extern C conditionnal removed }

  {* \defgroup pw_metadata Metadata
   * Metadata interface
    }
  {*
   * \addtogroup pw_metadata
   * \
    }
(* error 
#define PW_TYPE_INTERFACE_Metadata		PW_TYPE_INFO_INTERFACE_BASE "Metadata"
in define line 22 *)

    const
      PW_METADATA_PERM_MASK = PW_PERM_RWX;      
      PW_VERSION_METADATA = 3;      

    type
      Ppw_metadata = ^pw_metadata;
      pw_metadata = record
          {undefined structure}
        end;

(* error 
#define PW_EXTENSION_MODULE_METADATA		PIPEWIRE_MODULE_PREFIX "module-metadata"
in define line 29 *)

    const
      PW_METADATA_EVENT_PROPERTY = 0;      
      PW_METADATA_EVENT_NUM = 1;      
    {* \ref pw_metadata events  }
(* error 
#define PW_VERSION_METADATA_EVENTS		0
 in member_list *)

    type
      Ppw_metadata_events = ^pw_metadata_events;
      pw_metadata_events = record
        end;


    const
      PW_METADATA_METHOD_ADD_LISTENER = 0;      
      PW_METADATA_METHOD_SET_PROPERTY = 1;      
      PW_METADATA_METHOD_CLEAR = 2;      
      PW_METADATA_METHOD_NUM = 3;      
    {* \ref pw_metadata methods  }
(* error 
#define PW_VERSION_METADATA_METHODS		0
    {*
    	 * Set a metadata property
    	 *
    	 * Automatically emit property events for the subject and key
    	 * when they are changed.
    	 *
    	 * \param subject the id of the global to associate the metadata
    	 *                with.
    	 * \param key the key of the metadata, NULL clears all metadata for
    	 *                the subject.
    	 * \param type the type of the metadata, this can be blank
    	 * \param value the metadata value. NULL clears the metadata.
    	 *
    	 * This requires X and W permissions on the metadata. It also
    	 * requires M permissions on the subject global.
    	  }
    {*
    	 * Clear all metadata
    	 *
    	 * This requires X and W permissions on the metadata.
    	  }
 in member_list *)

    type
      Ppw_metadata_methods = ^pw_metadata_methods;
      pw_metadata_methods = record
        end;

(* error 
#define pw_metadata_method(o,method,version,...)			\
in declaration at line 95 *)
(* error 
	int _res = -ENOTSUP;						\
(* error 
	spa_interface_call_res((struct spa_interface*)o,		\
in declaration at line 98 *)
(* error 
			method, version, ##__VA_ARGS__);		\
(* error 
	_res;								\
in declaration at line 99 *)
(* error 
	_res;								\
(* error 
})
in define line 102 *)
(* error 
#define pw_metadata_set_property(c,...)		pw_metadata_method(c,set_property,0,__VA_ARGS__)
in define line 103 *)
    { was #define dname(params) para_def_expr }
    { argument types are unknown }
    { return type might be wrong }   

    function pw_metadata_clear(c : longint) : longint;    

    const
      PW_KEY_METADATA_NAME = 'metadata.name';      
      PW_KEY_METADATA_VALUES = 'metadata.values';      
    {*
     * \
      }
{$endif}
    { PIPEWIRE_EXT_METADATA_H  }
    { was #define dname(params) para_def_expr }
    { argument types are unknown }
    { return type might be wrong }   
    function pw_metadata_clear(c : longint) : longint;
    begin
      pw_metadata_clear:=pw_metadata_method(c,clear,0);
    end;


