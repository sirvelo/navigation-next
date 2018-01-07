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
    @file     data_route_summary.cpp
*/
/*
    (C) Copyright 2013 by TeleCommunication Systems, Inc.

    The information contained herein is confidential, proprietary
    to TeleCommunication Systems, Inc., and considered a trade secret as
    defined in section 499C of the penal code of the State of
    California. Use of this information by anyone other than
    authorized employees of TeleCommunication Systems, is granted only
    under a written non-disclosure agreement, expressly
    prescribing the scope and manner of such use.

---------------------------------------------------------------------------*/
/*! @{ */
#include "data_route_summary.h"

NB_Error
data_route_summary_init(data_util_state* pds, data_route_summary* prs)
{
    if (!pds || !prs)
    {
        return NE_INVAL;
    }

    data_string_init(pds, &prs->via);
    return NE_OK;
}

void
data_route_summary_free(data_util_state* pds, data_route_summary* prs)
{
    data_string_free(pds, &prs->via);
}

NB_Error
data_route_summary_from_tps(data_util_state* pds, data_route_summary* prs, tpselt te)
{
    NB_Error err = NE_OK;

    if (!pds || !prs)
    {
        return NE_INVAL;
    }

    err = data_route_summary_init(pds, prs);

    if (te)
    {
        prs->distance = te_getattru(te, "distance");
        prs->travel_time = te_getattru(te, "travel-time");
        prs->delay_time = te_getattru(te, "delay-time");
        err = err ? err : data_string_from_tps_attr(pds, &prs->via, te, "via");
    }
    else
    {
        err = NE_INVAL;
    }

    if (err)
    {
        data_route_summary_free(pds, prs);
    }

    return err;
}

NB_Error
data_route_summary_copy(data_util_state* pds, data_route_summary* prs_dest, data_route_summary* prs_src)
{
    NB_Error err = NE_OK;

    if (!pds || !prs_dest || !prs_src)
    {
        return NE_INVAL;
    }

    err = data_route_summary_init(pds, prs_dest);
    prs_dest->distance = prs_src->distance;
    prs_dest->travel_time = prs_src->travel_time;
    prs_dest->delay_time = prs_src->delay_time;
    err = err ? err : data_string_copy(pds, &prs_dest->via, &prs_src->via);

    return err;
}

/*! @} */
