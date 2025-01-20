
    { Pointers to basic pascal types, inserted by h2pas conversion program.}
    Type
      PLongint  = ^Longint;
      PSmallInt = ^SmallInt;
      PByte     = ^Byte;
      PWord     = ^Word;
      PDWord    = ^DWord;
      PDouble   = ^Double;

    Type
    Ppw_permission  = ^pw_permission;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_PERMISSION_H}
{$define PIPEWIRE_PERMISSION_H}  
{ C++ extern C conditionnal removed }

  {* \defgroup pw_permission Permission
   *
   * Permissions are kept for a client and describe what the client is
   * allowed to do with an object.
   *
   * See \ref page_core_api
    }
  {*
   * \addtogroup pw_permission
   * \
    }
  {*< object can be seen and events can be received  }

  const
    PW_PERM_R = 0400;    
  {*< methods can be called that modify the object  }
    PW_PERM_W = 0200;    
  {*< methods can be called on the object. The W flag must be
  				  *  present in order to call methods that modify the object.  }
    PW_PERM_X = 0100;    
  {*< metadata can be set on object, Since 0.3.9  }
    PW_PERM_M = 0010;    
  {*< a link can be made between a node that doesn't have
  				  *  permission to see the other node, Since 0.3.77  }
    PW_PERM_L = 0020;    
    PW_PERM_RW = PW_PERM_R or PW_PERM_W;    
    PW_PERM_RWX = PW_PERM_RW or PW_PERM_X;    
    PW_PERM_RWXM = PW_PERM_RWX or PW_PERM_M;    
    PW_PERM_RWXML = PW_PERM_RWXM or PW_PERM_L;    
  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   

  function PW_PERM_IS_R(p : longint) : longint;  

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function PW_PERM_IS_W(p : longint) : longint;  

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function PW_PERM_IS_X(p : longint) : longint;  

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function PW_PERM_IS_M(p : longint) : longint;  

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function PW_PERM_IS_L(p : longint) : longint;  

  const
    PW_PERM_ALL = PW_PERM_RWXM;    

  { was #define dname def_expr }
  function PW_PERM_INVALID : uint32_t;    

  {*< id of object, PW_ID_ANY for default permission  }
  {*< bitmask of above permissions  }

  type
    Ppw_permission = ^pw_permission;
    pw_permission = record
        id : uint32_t;
        permissions : uint32_t;
      end;

(* error 
#define PW_PERMISSION_INIT(id,p) ((struct pw_permission){ (id), (p) })
in define line 54 *)

    const
      PW_PERMISSION_FORMAT = '%c%c%c%c%c';      
(* error 
	(permission) & PW_PERM_R ? 'r' : '-',	\
in define line 62 *)
    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_PERMISSION_H  }
  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function PW_PERM_IS_R(p : longint) : longint;
  begin
    PW_PERM_IS_R:=(p(@(PW_PERM_R)))=PW_PERM_R;
  end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function PW_PERM_IS_W(p : longint) : longint;
  begin
    PW_PERM_IS_W:=(p(@(PW_PERM_W)))=PW_PERM_W;
  end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function PW_PERM_IS_X(p : longint) : longint;
  begin
    PW_PERM_IS_X:=(p(@(PW_PERM_X)))=PW_PERM_X;
  end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function PW_PERM_IS_M(p : longint) : longint;
  begin
    PW_PERM_IS_M:=(p(@(PW_PERM_M)))=PW_PERM_M;
  end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function PW_PERM_IS_L(p : longint) : longint;
  begin
    PW_PERM_IS_L:=(p(@(PW_PERM_L)))=PW_PERM_L;
  end;

  { was #define dname def_expr }
  function PW_PERM_INVALID : uint32_t;
    begin
      PW_PERM_INVALID:=uint32_t($ffffffff);
    end;


