{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2021 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_I18N_H}
{$define PIPEWIRE_I18N_H}  
{ C++ extern C conditionnal removed }
  {* \defgroup pw_gettext Internationalization
   * Gettext interface
    }
  {*
   * \addtogroup pw_gettext
   * \
    }

(* error 
SPA_FORMAT_ARG_FUNC(1) const char *pw_gettext(const char *msgid);
 in declarator_list *)
(* error 
SPA_FORMAT_ARG_FUNC(1) const char *pw_ngettext(const char *msgid, const char *msgid_plural, unsigned long int n);
(* error 
SPA_FORMAT_ARG_FUNC(1) const char *pw_ngettext(const char *msgid, const char *msgid_plural, unsigned long int n);
(* error 
SPA_FORMAT_ARG_FUNC(1) const char *pw_ngettext(const char *msgid, const char *msgid_plural, unsigned long int n);
 in declarator_list *)
 in declarator_list *)
 in declarator_list *)
  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   

  function _(_String : longint) : longint;  

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function N_(_String : longint) : longint;  

  {*
   * \
    }
{ C++ end of extern C conditionnal removed }
{$endif}
  { PIPEWIRE_I18N_H  }
  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function _(_String : longint) : longint;
  begin
    _:=pw_gettext(_String);
  end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function N_(_String : longint) : longint;
  begin
    N_:=_String;
  end;


