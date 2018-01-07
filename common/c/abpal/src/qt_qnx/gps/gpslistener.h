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

    @file     gpslistener.h
    @date     04/03/2012
    @defgroup GPSLISTENER_H Gps listener

    Gps listener
*/
/*
    (C) Copyright 2012 by TeleCommunication Systems, Inc.

    The information contained herein is confidential, proprietary
    to TeleCommunication Systems, Inc., and considered a trade secret as
    defined in section 499C of the penal code of the State of
    California. Use of this information by anyone other than
    authorized employees of TeleCommunication Systems is granted only
    under a written non-disclosure agreement, expressly
    prescribing the scope and manner of such use.

---------------------------------------------------------------------------*/

/*! @{ */

#ifndef GPSLISTENER_H
#define GPSLISTENER_H

#include "abpalgps.h"
#include "pallock.h"
#include "pal.h"
#include <list>
#include "paltaskqueue.h"

class GpsListener
{
    public:
        GpsListener(const ABPAL_GpsCriteria* criteria,
                    ABPAL_GpsLocationCallback* callBack,
                    void * data,
                    uint32 trackID,
                    PAL_Instance* pal);
        ~GpsListener();
        uint32 getTrackID();
        void deactivate();

        void Notify(PAL_Error error, const ABPAL_GpsLocation& location, bool isGpsFix);
        void Remove(int id);

    private:
        struct ListGpsEntry
        {
            ABPAL_GpsLocation          location;
            TaskId                     taskId;
            PAL_Error                  error;
            GpsListener*               pThis;
        };

        static void TaskQueue_GpsCallback(PAL_Instance* pal, void* userData);
        PAL_Instance* m_pPal;
        ABPAL_GpsLocationCallback* m_callBack;
        void* m_data;

        uint32 m_trackID;
        int32 volatile m_invalid;
        PAL_Lock* m_pLock;

        ABPAL_GpsCriteria m_gpsCriteria;
        std::list<ListGpsEntry*> m_list;
};

#endif  /* GPSLISTENER_H */

/*! @} */
