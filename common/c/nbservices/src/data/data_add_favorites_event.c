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

    @file     data_add_favorites_event.c
*/
/*
    See file description in header file.

    (C) Copyright 2004 - 2009 by Networks In Motion, Inc.

    The information contained herein is confidential, proprietary 
    to Networks In Motion, Inc., and considered a trade secret as 
    defined in section 499C of the penal code of the State of     
    California. Use of this information by anyone other than      
    authorized employees of Networks In Motion is granted only    
    under a written non-disclosure agreement, expressly           
    prescribing the scope and manner of such use.                 

---------------------------------------------------------------------------*/

/*! @{ */
#include "data_add_favorites_event.h"

NB_Error
data_add_favorites_event_init(data_util_state* pds,
        data_add_favorites_event* pafe)
{
    NB_Error err = NE_OK;

    DATA_INIT(pds, err, &pafe->analytics_event_place,
            data_analytics_event_place);

    return err;
}

void
data_add_favorites_event_free(data_util_state* pds,
        data_add_favorites_event* pafe)
{
    DATA_FREE(pds, &pafe->analytics_event_place, data_analytics_event_place);
}

tpselt
data_add_favorites_event_to_tps(data_util_state* pds,
        data_add_favorites_event* pafe)
{
    tpselt te = NULL;
    tpselt ce = NULL;

    te = te_new("add-favorites-event");

    if (te == NULL)
    {
        goto errexit;
    }

    ce = data_analytics_event_place_to_tps(pds, &pafe->analytics_event_place);
    if ((ce != NULL) && te_attach(te, ce))
    {
        ce = NULL;
    }
    else
    {
        goto errexit;
    }

    return te;

errexit:

    te_dealloc(te);
    return NULL;
}

boolean
data_add_favorites_event_equal(data_util_state* pds,
        data_add_favorites_event* pafe1, data_add_favorites_event* pafe2)
{
    return (boolean) data_analytics_event_place_equal(pds,
            &pafe1->analytics_event_place, &pafe2->analytics_event_place);
}

NB_Error
data_add_favorites_event_copy(data_util_state* pds,
        data_add_favorites_event* pafe_dest, data_add_favorites_event* pafe_src)
{
    NB_Error err = NE_OK;

    DATA_REINIT(pds, err, pafe_dest, data_add_favorites_event);

    DATA_COPY(pds, err, &pafe_dest->analytics_event_place,
            &pafe_src->analytics_event_place, data_analytics_event_place);

    return err;
}

uint32
data_add_favorites_event_get_tps_size(data_util_state* pds,
            data_add_favorites_event* pafe)
{
    return data_analytics_event_place_get_tps_size(pds,
            &pafe->analytics_event_place);
}

void
data_add_favorites_event_to_buf(data_util_state* pds,
            data_add_favorites_event* pafe,
            struct dynbuf* pdb)
{
    data_analytics_event_place_to_buf(pds, &pafe->analytics_event_place, pdb);
}

NB_Error
data_add_favorites_event_from_binary(data_util_state* pds,
            data_add_favorites_event* pafe,
            byte** pdata, size_t* pdatalen)
{
    return data_analytics_event_place_from_binary(pds,
            &pafe->analytics_event_place, pdata, pdatalen);
}

/*! @} */

