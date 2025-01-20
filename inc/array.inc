{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { PipeWire  }
  { SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans  }
  { SPDX-License-Identifier: MIT  }
{ C++ extern C conditionnal removed }


  {* \defgroup pw_array Array
   *
   * \brief An array object
   *
   * The array is a dynamically resizable data structure that can
   * hold items of the same size.
    }
  {*
   * \addtogroup pw_array
   * \
    }
  {*< pointer to array data  }
  {*< length of array in bytes  }
  {*< number of allocated memory in \a data  }
  {*< number of bytes to extend with, 0 when the
  				  *  data should not expand  }

  type
    Ppw_array = ^pw_array;
    pw_array = record
        data : pointer;
        size : size_t;
        alloc : size_t;
        extend : size_t;
      end;

