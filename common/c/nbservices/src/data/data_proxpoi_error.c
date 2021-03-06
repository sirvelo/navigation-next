/*
Copyright (c) 2018, TeleCommunication Systems, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
   * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the TeleCommunication Systems, Inc., nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ARE
DISCLAIMED. IN NO EVENT SHALL TELECOMMUNICATION SYSTEMS, INC.BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!--------------------------------------------------------------------------

    @file     data_proxpoi_error.c
*/
/*
    See file description in header file.

    (C) Copyright 2014 by TeleCommunication Systems, Inc.

    The information contained herein is confidential, proprietary
    to TeleCommunication Systems, Inc., and considered a trade secret as
    defined in section 499C of the penal code of the State of
    California. Use of this information by anyone other than
    authorized employees of TeleCommunication Systems is granted only
    under a written non-disclosure agreement, expressly
    prescribing the scope and manner of such use.
---------------------------------------------------------------------------*/

/*! @{ */

#include "data_proxpoi_error.h"

NB_Error data_proxpoi_error_init(data_util_state* pds, data_proxpoi_error* ppe)
{
    ppe->code = 0;
    return NE_OK;
}

void data_proxpoi_error_free(data_util_state* pds, data_proxpoi_error* ppe)
{
    data_proxpoi_error_init(pds, ppe);
}

NB_Error data_proxpoi_error_from_tps(data_util_state* pds, data_proxpoi_error* ppe, tpselt te)
{
    NB_Error err = NE_OK;

    DATA_REINIT(pds, err, ppe, data_proxpoi_error);

    err = err ? err : te_getattru(te, "code");

    if (err)
    {
        DATA_REINIT(pds, err, ppe, data_proxpoi_error);
    }

    return err;
}
NB_Error data_proxpoi_error_copy(data_util_state* pds, data_proxpoi_error* ppe_dest, data_proxpoi_error* ppe_src)
{
    NB_Error err = NE_OK;

    DATA_REINIT(pds, err, ppe_dest, data_proxpoi_error);

    ppe_dest->code = ppe_src->code;

    return err;
}


boolean data_proxpoi_error_equal(data_util_state* pds, data_proxpoi_error* ppe1, data_proxpoi_error* ppe2)
{
    return (boolean) (ppe1->code == ppe2->code);
}

/*! @} */

