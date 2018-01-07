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
/* (C) Copyright 2008 by Networks In Motion, Inc.                */
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

#include "data_retrieve_confirmed.h"

NB_DEF NB_Error
data_retrieve_confirmed_init(data_util_state* pds, data_retrieve_confirmed* prc)
{
	NB_Error err = NE_OK;

	err = err ? err : data_string_init(pds, &prc->type);

	return err;
}

NB_DEF void		
data_retrieve_confirmed_free(data_util_state* pds, data_retrieve_confirmed* prc)
{
	data_string_free(pds, &prc->type);
}

NB_DEF tpselt		
data_retrieve_confirmed_to_tps(data_util_state* pds, data_retrieve_confirmed* prc)
{
	tpselt te;

	te = te_new("retrieve-confirmed");
	
	if (te == NULL) {
		goto errexit;
	}

	if (!te_setattrc(te, "type", prc->type)) {
		goto errexit;
	}

	return te;

errexit:
	te_dealloc(te);
	return NULL;
}

NB_DEF boolean		
data_retrieve_confirmed_equal(data_util_state* pds, data_retrieve_confirmed* prc1, data_retrieve_confirmed* prc2)
{
	return (boolean)data_string_equal(pds, &prc1->type, &prc2->type);
}

NB_DEF NB_Error	
data_retrieve_confirmed_copy(data_util_state* pds, data_retrieve_confirmed* prc_dest, data_retrieve_confirmed* prc_src)
{
	NB_Error err = NE_OK;

	data_retrieve_confirmed_free(pds, prc_dest);

	err = err ? err : data_retrieve_confirmed_init(pds, prc_dest);

	err = err ? err : data_string_copy(pds, &prc_dest->type, &prc_src->type);

	return err;
}
