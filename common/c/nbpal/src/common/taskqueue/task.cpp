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
    @file     task.cpp

    @date     08/23/2011
    @defgroup PAL_TASKQUEUE PAL task queue component
    @brief    Class for task.
    Common implementation for PAL task.
*/
/*
    (C) Copyright 2011 by Telecommunication Systems, Inc.

    The information contained herein is confidential, proprietary
    to Telecommunication Systems, Inc., and considered a trade secret as
    defined in section 499C of the penal code of the State of
    California. Use of this information by anyone other than
    authorized employees of Telecommunication Systems is granted only
    under a written non-disclosure agreement, expressly
    prescribing the scope and manner of such use.
---------------------------------------------------------------------------*/

#include "task.h"
#include "palstdlib.h"
#include "palatomic.h"

namespace nimpal
{
    namespace taskqueue
    {
        volatile TaskId Task::m_nextId = 0;
        Task::Task(PAL_Instance* pal, PAL_TaskQueueCallback userCallback, void* userData, TaskPriority priority)
            : m_pal(pal),
              m_taskId(0),
              m_priority(priority),
              m_completed(0),
              m_userCallback(userCallback),
              m_userData(userData)
        {
            m_taskId = PAL_AtomicIncrement(reinterpret_cast<volatile int32*>(&m_nextId));
        }

        Task::~Task(void)
        {
        }

        PAL_Error Task::Execute(void)
        {
            if (m_userCallback == NULL || m_pal == NULL)
            {
                return PAL_Failed;
            }
            m_userCallback(m_pal, m_userData);
            return PAL_Ok;
        }

        PAL_Error Task::Cancel(void)
        {
            // TODO: figure out what to do
            return PAL_Ok;
        }

        uint32 Task::GetPercentageComplete(void) const
        {
            int32 completed = 0;
            PAL_AtomicExchange(&completed, m_completed);
            return completed;
        }

        void Task::UpdatePercentageComplete(uint32 completed)
        {
            completed = completed > 100 ? 100 : completed;
            PAL_AtomicExchange(reinterpret_cast<volatile int32*>(&m_completed), completed);
        }
    }
}
