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

/*
 * (C) Copyright 2014 by TeleCommunication Systems, Inc.
 *
 * The information contained herein is confidential, proprietary
 * to TeleCommunication Systems, Inc., and considered a trade secret
 * as defined in section 499C of the penal code of the State of
 * California. Use of this information by anyone other than
 * authorized employees of TeleCommunication Systems is granted only
 * under a written non-disclosure agreement, expressly prescribing
 * the scope and manner of such use.
 *
 */

#ifndef _MBGM_ANDROID_EGL_H_
#define _MBGM_ANDROID_EGL_H_

#include "palgl.h"
#include <EGL/egl.h>
#include <android/native_window.h>
#include "pallock.h"
#include "nbgmrenderconfig.h"

class NBGMAndroidEGL
{
public:
	NBGMAndroidEGL(ANativeWindow* window, PAL_Instance *pal, const NBGM_RenderConfig &config);
	~NBGMAndroidEGL();

	/* Create OpenGL context */
	bool Initilize(int renderSystem);

	/* Create GL surface */
	bool CreateSurface(ANativeWindow* window);

	/* Destroy GL surface */
	void DestroySurface();

	bool MakeCurrent();
	/* Swap buffer */
	bool Swap();

	/* Destroy context*/
	void Finish();

    /* Update the surface*/
    void UpdateSurface(ANativeWindow* window);

    /* Reset the surface*/
    void ResetSurface();

    /* Clean GL surface */
    void CleanSurface();

private:
    ANativeWindow* m_window;
    EGLConfig  m_config;
    EGLDisplay m_display;
    EGLSurface m_surface;
    EGLContext m_context;
    EGLSurface m_newSurface;
    EGLint m_format;
    bool m_hasSurface;
    bool m_needResetSurface;
    PAL_Lock *m_lock;
    NBGM_RenderConfig m_renderConfig;
};

#endif //_MBGM_ANDROID_EGL_H_
