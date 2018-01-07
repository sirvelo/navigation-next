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

    @file     data_poi_events_config.c
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
#include "data_poi_events_config.h"

NB_Error
data_poi_events_config_init(data_util_state* pds, data_poi_events_config* ppec)
{
    NB_Error err = NE_OK;

    ppec->priority = 0;

    return err;
}

void
data_poi_events_config_free(data_util_state* pds, data_poi_events_config* ppec)
{
    /* nothing to free */
}

NB_Error
data_poi_events_config_from_tps(data_util_state* pds, data_poi_events_config* ppec, tpselt te)
{
    NB_Error err = NE_OK;

    if (te == NULL) {
        err = NE_INVAL;
        goto errexit;
    }

    data_poi_events_config_free(pds, ppec);

    err = data_poi_events_config_init(pds, ppec);

    if (err != NE_OK)
        return err;

    ppec->priority = te_getattru(te, "priority");

errexit:
    if (err != NE_OK)
        data_poi_events_config_free(pds, ppec);
    return err;
}

boolean
data_poi_events_config_equal(data_util_state* pds, data_poi_events_config* ppec1, data_poi_events_config* ppec2)
{
    return (boolean) (ppec1->priority == ppec2->priority);
}

NB_Error
data_poi_events_config_copy(data_util_state* pds, data_poi_events_config* ppec_dest, data_poi_events_config* ppec_src)
{
    NB_Error err = NE_OK;

    DATA_REINIT(pds, err, ppec_dest, data_poi_events_config);

    ppec_dest->priority = ppec_src->priority;

    return err;
}

/*! @} */

