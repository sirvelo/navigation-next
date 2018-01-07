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

    @file     threadqt.h
    @date     08/25/2011
    @defgroup PAL_TASKQUEUE PAL task queue component

    @brief    POSIX class for thread.

    POSIX definition for PAL thread.
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

#ifndef _RENDERTHREADQT_H_
#define _RENDERTHREADQT_H_

#include "threadqt.h"
#include <QThread>
#include <QtCore/QMutex>
#include <QtCore/QThread>

#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLFramebufferObject>
#include <QtGui/QGuiApplication>
#include <QtGui/QOffscreenSurface>

#include <QtQuick/QQuickWindow>
#include <qsgsimpletexturenode.h>

/*
 * The render thread shares a context with the scene graph and will
 * render into two separate FBOs, one to use for display and one
 * to use for rendering
 */
class RenderThreadQt : public ThreadQt
{
    Q_OBJECT
public:
    RenderThreadQt(PAL_Instance* pal, nimpal::taskqueue::TaskQueue* taskQueue, nimpal::taskqueue::ThreadStateListener* listener, const char* name);
    PAL_Error StartThread(void);

    QOffscreenSurface *surface;
    QOpenGLContext *context;

    void makeCurrent();
    void swapBuffers();
    int displayRenderTargetId();
    void setSize(int width, int height);


public slots:
    void renderNext();
    void shutDown();

signals:
    void textureReady(int id, const QSize &size);

private:
    QOpenGLFramebufferObject *m_renderFbo;
    QOpenGLFramebufferObject *m_displayFbo;
    QOpenGLFramebufferObject *m_msaaFbo;
//    LogoRenderer *m_logoRenderer;
    QSize m_size;
    QList<QOpenGLFramebufferObject*> m_fbosToDelete;
};

#endif //_RENDERTHREADQT_H_
