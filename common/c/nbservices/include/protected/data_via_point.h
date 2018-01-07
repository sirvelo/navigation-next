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

#ifndef DATA_VIA_POINT_H
#define DATA_VIA_POINT_H

#include "datautil.h"
#include "data_address.h"
#include "data_point.h"
#include "data_box.h"
#include "nbexp.h"

typedef struct data_via_point_ {

    data_address	address;
    data_point		point;
    boolean         passed;
    boolean         isStopPoint;
} data_via_point;

NB_DEC NB_Error	data_via_point_init(data_util_state* pds, data_via_point* point);
NB_DEC void		data_via_point_free(data_util_state* pds, data_via_point* point);

NB_DEC tpselt	data_via_point_to_tps(data_util_state* pds, data_via_point* point);
NB_DEC NB_Error	data_via_point_from_tps(data_util_state* pds, data_via_point* point, tpselt te);

NB_DEC NB_Error	data_via_point_from_nimlocation(data_util_state* pds, data_via_point* point, const NB_Location* pLocation);
NB_Error data_via_point_to_nimlocation(data_util_state* state, data_via_point* point, NB_Location* nbLocation);
NB_DEF NB_Error
data_via_point_copy(data_util_state* pds, data_via_point* via_dest, data_via_point* via_src);

#endif

