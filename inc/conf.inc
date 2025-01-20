  Type
  Ppw_properties  = ^pw_properties;
  Pspa_dict  = Pointer; {$WARNING ^spa_dict}
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2021 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_CONF_H}
{$define PIPEWIRE_CONF_H}  

  {* \defgroup pw_conf Configuration
   * Loading/saving properties from/to configuration files.
    }
  {*
   * \addtogroup pw_conf
   * \
    }

  function pw_conf_load_conf_for_context(props:Ppw_properties; conf:Ppw_properties):cint;cdecl;external;



  function pw_conf_load_conf(prefix:pcchar; name:pcchar; conf:Ppw_properties):cint;cdecl;external;



  function pw_conf_load_state(prefix:pcchar; name:pcchar; conf:Ppw_properties):cint;cdecl;external;




  function pw_conf_save_state(prefix:pcchar; name:pcchar; conf:Ppw_properties):cint;cdecl;external;



  function pw_conf_section_update_props(conf:Pspa_dict; section:pcchar; props:Ppw_properties):cint;cdecl;external;




  function pw_conf_section_update_props_rules(conf:Pspa_dict; context:Pspa_dict; section:pcchar; props:Ppw_properties):cint;cdecl;external;






  function pw_conf_section_for_each(conf:Pspa_dict; section:pcchar; callback:function (data:pointer; location:pcchar; section:pcchar; str:pcchar; len:size_t):cint; data:pointer):cint;cdecl;external;







  function pw_conf_match_rules(str:pcchar; len:size_t; location:pcchar; props:Pspa_dict; callback:function (data:pointer; location:pcchar; action:pcchar; str:pcchar; len:size_t):cint; 
             data:pointer):cint;cdecl;external;







  function pw_conf_section_match_rules(conf:Pspa_dict; section:pcchar; props:Pspa_dict; callback:function (data:pointer; location:pcchar; action:pcchar; str:pcchar; len:size_t):cint; data:pointer):cint;cdecl;external;

  {*
   * \
    }
{$endif}
  { PIPEWIRE_CONF_H  }

