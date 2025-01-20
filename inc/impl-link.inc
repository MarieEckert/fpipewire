    Type
    Ppw_impl_link  = ^pw_impl_link;
    Ppw_impl_link_events  = ^pw_impl_link_events;
    Ppw_impl_port  = ^pw_impl_port;
    Ppw_link_info  = ^pw_link_info;
    Ppw_properties  = ^pw_properties;
    Pspa_hook  = Pointer; {$WARNING ^spa_hook}
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{$ifndef PIPEWIRE_IMPL_LINK_H}
{$define PIPEWIRE_IMPL_LINK_H}  
{ C++ extern C conditionnal removed }
  {* \defgroup pw_impl_link Link Impl
   *
   * \brief PipeWire link object.
    }
  {*
   * \addtogroup pw_impl_link
   * \
    }

  type
    Ppw_impl_link = ^pw_impl_link;
    pw_impl_link = record
        {undefined structure}
      end;

    Ppw_impl_port = ^pw_impl_port;
    pw_impl_port = record
        {undefined structure}
      end;


  {* link events added with \ref pw_impl_link_add_listener  }
(* error 
#define PW_VERSION_IMPL_LINK_EVENTS	0
  {* A link is destroyed  }
  {* A link is freed  }
  {* a Link is initialized  }
  {* The info changed on a link  }
  {* The link state changed, \a error is only valid when the state is
  	  * in error.  }
  {* A port is unlinked  }
 in member_list *)

  type
    Ppw_impl_link_events = ^pw_impl_link_events;
    pw_impl_link_events = record
      end;

  {* Make a new link between two ports
   * \return a newly allocated link  }
(* error 
struct pw_impl_link *
  {*< the context object  }
  {*< an output port  }
  {*< an input port  }
  {*< an optional format filter  }
  {*< extra properties  }  {*< extra user data size  }in declaration at line 61 *)
    {* Destroy a link  }

    procedure pw_impl_link_destroy(link:Ppw_impl_link);cdecl;external;

    {* Add an event listener to \a link  }

    procedure pw_impl_link_add_listener(link:Ppw_impl_link; listener:Pspa_hook; events:Ppw_impl_link_events; data:pointer);cdecl;external;

    {* Finish link configuration and register  }
    {*< the link to register  }
    {*< extra properties  }    function pw_impl_link_register(link:Ppw_impl_link; properties:Ppw_properties):cint;cdecl;external;

    {* Get the context of a link  }
(* error 
struct pw_context *pw_impl_link_get_context(struct pw_impl_link *link);
in declaration at line 77 *)
    {* Get the user_data of a link, the size of the memory is given when
      * constructing the link  }
    function pw_impl_link_get_user_data(link:Ppw_impl_link):pointer;cdecl;external;

    {* Get the link info  }

    function pw_impl_link_get_info(link:Ppw_impl_link):Ppw_link_info;cdecl;external;

    {* Get the global of the link  }
(* error 
struct pw_global *pw_impl_link_get_global(struct pw_impl_link *link);
in declaration at line 87 *)
    {* Get the output port of the link  }
(* error 
struct pw_impl_port *pw_impl_link_get_output(struct pw_impl_link *link);
in declaration at line 90 *)
    {* Get the input port of the link  }
(* error 
struct pw_impl_port *pw_impl_link_get_input(struct pw_impl_link *link);
in declaration at line 93 *)
    {* Find the link between 2 ports  }
(* error 
struct pw_impl_link *pw_impl_link_find(struct pw_impl_port *output, struct pw_impl_port *input);
in declaration at line 96 *)
    {*
     * \
      }
{ C++ end of extern C conditionnal removed }
{$endif}
    { PIPEWIRE_IMPL_LINK_H  }

