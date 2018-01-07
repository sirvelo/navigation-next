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

    @file     threadposix.cpp
    @date     08/25/2011
    @defgroup PAL_TASKQUEUE PAL task queue component

    @brief    Class for POSIX thread.

    POSIX implementation for PAL thread.
*/
/*
    (C) Copyright 2012 by Telecommunication Systems, Inc.

    The information contained herein is confidential, proprietary
    to Telecommunication Systems, Inc., and considered a trade secret as
    defined in section 499C of the penal code of the State of
    California. Use of this information by anyone other than
    authorized employees of Telecommunication Systems is granted only
    under a written non-disclosure agreement, expressly
    prescribing the scope and manner of such use.

---------------------------------------------------------------------------*/

#include "threadposix.h"
#include "palstdlib.h"
#include "taskqueue.h"
#include "task.h"
#include "pthread.h"

namespace nimpal
{
    namespace taskqueue
    {
        static void* StaticThreadMain(void* pThis);

        ThreadPosix::ThreadPosix(PAL_Instance* pal, TaskQueue* taskQueue, ThreadStateListener* listener, const char* name)
            : Thread(pal, taskQueue, listener),
              m_cbThreadId(0),
              m_threadStartedEvent(NULL),
              m_exit(false),
              m_NewTaskEvent(NULL)
        {
            nsl_memset(m_name, 0, MAX_THREAD_NAME_LENGTH * sizeof(char));
            if (name != NULL)
            {
                nsl_strlcpy(m_name, name, MAX_THREAD_NAME_LENGTH);
            }
        }

        ThreadPosix::~ThreadPosix(void)
        {
        	// Flag the thread to exit the loop
            m_exit = true;

            if (GetState() != Invalid)
            {
            	// Make sure the worker thread exits the wait condition
            	PAL_EventSet(m_NewTaskEvent);

            m_taskQueue->Clear();

                // Wait until the thread has terminated the loop
                if (!pthread_equal(m_cbThreadId, pthread_self()))
                {
                    pthread_join(m_cbThreadId, NULL);
                }
            }

            if (m_NewTaskEvent)
            {
                PAL_EventDestroy(m_NewTaskEvent);
            }
            if (m_threadStartedEvent != NULL)
            {
                PAL_EventDestroy(m_threadStartedEvent);
            }
        }

        void ThreadPosix::NewTaskNotify(void)
        {
            PAL_EventSet(m_NewTaskEvent);
        }

        void ThreadPosix::CancelRunningTaskNotify(void)
        {
            // Do nothing for this
        }

        PAL_Error ThreadPosix::StartThread(void)
        {
            PAL_Error err = PAL_Failed;

            if (GetState() != Invalid)
            {
                // Thread was already created and started
                return PAL_Ok;
            }

            if (m_pal == NULL)
            {
                return PAL_ErrNoInit;
            }

            if (PAL_EventCreate(m_pal, &m_threadStartedEvent) != PAL_Ok)
            {
            	return err;
            }
            if (PAL_EventCreate(m_pal, &m_NewTaskEvent) != PAL_Ok)
            {
                return err;
            }

            if (pthread_create(&m_cbThreadId, NULL, StaticThreadMain, (void *)this) == 0)
            {
                // Assign a meaningful name to the thread
                pthread_setname_np(m_cbThreadId, m_name);

                err = PAL_Ok;

                SetState(Created);

                // Wait until thread is actually started
                PAL_EventWaitForEvent(m_threadStartedEvent);
            }
            else
            {
                err = PAL_ErrQueueCannotStartNewThread;
            }
            return err;
        }

        nb_threadId ThreadPosix::ThreadId(void) const
        {
            return (nb_threadId)m_cbThreadId;
        }

        void ThreadPosix::ThreadMain(void)
        {
            SetState(Pending);
            PAL_EventSet(m_threadStartedEvent);

            // main thread loop
            while (!m_exit)
            {
                if (PAL_EventWaitForEvent(m_NewTaskEvent) == PAL_Ok)
                {
                	// double check before execute task
                    if (!m_exit)
                    {
                        ExecuteTasks();
                    }
                }
            }
        }


        void* StaticThreadMain(void* pThis)
        {
            if (pThis != NULL)
            {
                static_cast<ThreadPosix*>(pThis)->ThreadMain();
            }
            return NULL;
        }
    }
}
