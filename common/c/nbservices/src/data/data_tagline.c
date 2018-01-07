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

    @file     data_tagline.c
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

#include "data_tagline.h"

NB_DEF NB_Error
data_tagline_init(data_util_state* pds, data_tagline* ptl)
{
    NB_Error err = NE_OK;

    err = data_string_init(pds, &ptl->text);

    return err;
}

NB_DEF void
data_tagline_free(data_util_state* pds, data_tagline* ptl)
{
    data_string_free(pds, &ptl->text);
}

NB_DEF NB_Error
data_tagline_from_tps(data_util_state* pds, data_tagline* ptl, tpselt te)
{
    NB_Error err = NE_OK;

    if (te == NULL)
    {
        err = NE_INVAL;
        return err;
    }

    data_tagline_free(pds, ptl);

    err = data_tagline_init(pds, ptl);

    if (err != NE_OK)
    {
        return err;
    }

    err = err ? err : data_string_from_tps_attr(pds, &ptl->text, te, "text");

    if (err != NE_OK)
    {
        data_tagline_free(pds, ptl);
    }

    return err;
}

NB_DEF boolean
data_tagline_equal(data_util_state* pds, data_tagline* ptl1, data_tagline* ptl2)
{
    return (boolean) (data_string_equal(pds, &ptl1->text, &ptl2->text));
}

NB_DEF NB_Error
data_tagline_copy(data_util_state* pds, data_tagline* ptl_dest, data_tagline* ptl_src)
{
    NB_Error err = NE_OK;

    data_tagline_free(pds, ptl_dest);

    err = data_tagline_init(pds, ptl_dest);
    err = err ? err : data_string_copy(pds, &ptl_dest->text, &ptl_src->text);

    return err;
}

/*! @} */
