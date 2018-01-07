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

    @file     data_category_list_request.c
*/
/*
    (C) Copyright 2011 by TeleCommunication Systems, Inc.             

    The information contained herein is confidential, proprietary 
    to TeleCommunication Systems, Inc., and considered a trade secret as 
    defined in section 499C of the penal code of the State of     
    California. Use of this information by anyone other than      
    authorized employees of TeleCommunication Systems is granted only    
    under a written non-disclosure agreement, expressly           
    prescribing the scope and manner of such use.                 

---------------------------------------------------------------------------*/

/*! @{ */

#include "data_category_list_request.h"

NB_Error
data_category_list_request_init(data_util_state* state, data_category_list_request* request)
{
    NB_Error err = NE_OK;
    DATA_MEM_ZERO(request, data_category_list_request);

    err = err ? err : data_position_init(state, &request->position);
    err = err ? err : data_string_init(state, &request->broad_category_name);
    err = err ? err : data_string_init(state, &request->category_name);

    return err;
}

void
data_category_list_request_free(data_util_state* state, data_category_list_request* request)
{
    data_position_free(state, &request->position);

    data_string_free(state, &request->broad_category_name);
    data_string_free(state, &request->category_name);
}

tpselt
data_category_list_request_to_tps(data_util_state* state, data_category_list_request* request)
{
    tpselt tpsElement = te_new("category-list-request");

    if (tpsElement == NULL)
    {
        goto errexit;
    }

    if (request->position.boxValid == TRUE || request->position.variant != NULL)
    {
        DATA_TO_TPS(state, errexit, tpsElement, &request->position, data_position);
    }

    if (!te_setattrc(tpsElement, "broad-category-name", data_string_get(state, &request->broad_category_name)))
    {
        goto errexit;
    }

    if (!te_setattrc(tpsElement, "category-name", data_string_get(state, &request->category_name)))
    {
        goto errexit;
    }

    return tpsElement;

errexit:

    te_dealloc(tpsElement);
    return NULL;
}

NB_Error
data_category_list_request_copy(data_util_state* state, data_category_list_request* dest, data_category_list_request* src)
{
    NB_Error err = NE_OK;

    data_category_list_request_free(state, dest);
    err = err ? err : data_category_list_request_init(state, dest);

    err = err ? err : data_position_copy(state, &dest->position, &src->position);

    err = err ? err : data_string_copy(state, &dest->broad_category_name, &src->broad_category_name);
    err = err ? err : data_string_copy(state, &dest->category_name, &src->category_name);


    return err;
}

/*! @} */
