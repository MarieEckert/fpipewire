{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_VERSION_H}
{$define PIPEWIRE_VERSION_H}  
  { WARNING: Make sure to edit the real source file version.h.in!  }
{ C++ extern C conditionnal removed }

  {* Return the version of the header files. Keep in mind that this is
  a macro and not a function, so it is impossible to get the pointer of
  it.  }
  { was #define dname(params) para_def_expr }
  { return type might be wrong }   

  function pw_get_headers_version : longint;  

  {* Return the version of the library the current application is
   * linked to.  }

  function pw_get_library_version:pcchar;cdecl;external External_library name 'pw_get_library_version';

  {* Return TRUE if the currently linked PipeWire library version is equal
   * or newer than the specified version. Since 0.3.75  }
  function pw_check_library_version(major:cint; minor:cint; micro:cint):bool;cdecl;external External_library name 'pw_check_library_version';

  {* The current API version. Versions prior to 0.2.0 have
   * PW_API_VERSION undefined. Please note that this is only ever
   * increased on incompatible API changes!   }
  const
    PW_API_VERSION = '0.3';    
  {* The major version of PipeWire. \since 0.2.0  }
    PW_MAJOR = 1;    
  {* The minor version of PipeWire. \since 0.2.0  }
    PW_MINOR = 2;    
  {* The micro version of PipeWire. \since 0.2.0  }
    PW_MICRO = 7;    
  {* Evaluates to TRUE if the PipeWire library version is equal or
   * newer than the specified. \since 0.2.0  }
(* error 
    ((PW_MAJOR > (major)) ||                                            \
in define line 48 *)
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_VERSION_H  }
  { was #define dname(params) para_def_expr }
  { return type might be wrong }   
  function pw_get_headers_version : longint;
  begin
    pw_get_headers_version:='1.2.7';
  end;


