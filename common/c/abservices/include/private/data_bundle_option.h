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

    @file     data_bundle_option.h
    @defgroup authentication

*/
/*
    (C) Copyright 2014 by TeleCommunication Systems, Inc.

    The information contained herein is confidential, proprietary
    to TeleCommunication Systems, Inc., and considered a trade secret as
    defined in section 499C of the penal code of the State of
    California. Use of this information by anyone other than
    authorized employees of TeleCommunication Systems is granted only
    under a written non-disclosure agreement, expressly
    prescribing the scope and manner of such use.
---------------------------------------------------------------------------*/

#ifndef DATA_BUNDLE_OPTION_H
#define DATA_BUNDLE_OPTION_H

/*! @{ */

#include "datautil.h"
#include "data_string.h"
#include "data_price_list.h"
#include "data_feature_list.h"
#include "data_formatted_text.h"

typedef struct _data_bundle_option_
{
    /* Child Elements */
    data_price_list     price_list;
    data_feature_list   feature_list;
    data_formatted_text	formatted_text;

    /* Attributes */
    data_string         title;
    data_string         description;
    data_string         name;
    data_string         region;         //regions supported in the bundle
    uint32              token_id;          //token id in the bundle
}data_bundle_option;

NB_Error    data_bundle_option_init(data_util_state* pds, data_bundle_option* pdbo);
void        data_bundle_option_free(data_util_state* pds, data_bundle_option* pdbo);
NB_Error    data_bundle_option_from_tps(data_util_state* pds, data_bundle_option* pdbo, tpselt te);
NB_Error    data_bundle_option_copy(data_util_state* pds, data_bundle_option* pdbo_dest, data_bundle_option* pdbo_src);

/*! @} */

#endif //DATAFEATURE_H