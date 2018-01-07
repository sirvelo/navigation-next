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

/*****************************************************************/
/*                                                               */
/* (C) Copyright 2004 by Networks In Motion, Inc.                */
/*                                                               */
/* The information contained herein is confidential, proprietary */
/* to Networks In Motion, Inc., and considered a trade secret as */
/* defined in section 499C of the penal code of the State of     */
/* California. Use of this information by anyone other than      */
/* authorized employees of Networks In Motion is granted only    */
/* under a written non-disclosure agreement, expressly           */
/* prescribing the scope and manner of such use.                 */
/*                                                               */
/*****************************************************************/

/*-
 * data_traffic_map_road.c: created 2005/01/02 by Mark Goddard.
 */

#include "data_traffic_map_road.h"
#include "nbspatial.h"

NB_Error
data_traffic_map_road_init(data_util_state* pds, data_traffic_map_road* pp)
{
    data_blob_init(pds, &pp->polylines);
    pp->color = 0;
    data_string_init(pds, &pp->label);

    return NE_OK;
}

void
data_traffic_map_road_free(data_util_state* pds, data_traffic_map_road* pp)
{
    data_string_free(pds, &pp->label);
    data_blob_free(pds, &pp->polylines);
}

NB_Error
data_traffic_map_road_from_tps(data_util_state* pds, data_traffic_map_road* pp, tpselt te)
{
    NB_Error err = NE_OK;

    data_traffic_map_road_free(pds, pp);
    err = data_traffic_map_road_init(pds, pp);
    if (err != NE_OK)
        goto errexit;
    pp->color = te_getattru(te, "color");
    err = err ? err : data_string_from_tps_attr(pds, &pp->label, te, "label");
    err = err ? err : data_blob_from_tps_attr(pds, &pp->polylines, te, "polyline");

    if (err == NE_INVAL)
        err = NE_OK;

errexit:
    if (err != NE_OK)
        data_traffic_map_road_free(pds, pp);
    return err;
}

NB_Error
data_traffic_map_road_copy(data_util_state* pds, data_traffic_map_road* pp_dest, data_traffic_map_road* pp_src)
{
    NB_Error err = NE_OK;

    return err;
}