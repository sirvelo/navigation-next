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
 * (C) Copyright 2012 by TeleCommunication Systems, Inc.
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

#pragma once

#include "NBGMTestView.h"
#include "nbrerenderengine.h"
#include "pal.h"
#include "nbretypes.h"
#include "resource.h"
#include "nbgm.h"

class NBRE_Entity;
class NBRE_RenderEngine;
class NBRE_MapMaterialManager;
class CCameraController;

class CTest3DBuildingLoad: public CNBGMUITestSuit
{
public:
    CTest3DBuildingLoad();
    ~CTest3DBuildingLoad();

public:
    CString GetWindowName()  { return _T("Test 3D building load"); }
    int GetResourceID()      { return IDR_TEST_GL_RENDER_PAL;   }

private:
    void LoadMapData();

private:
    virtual void OnRender();
    virtual int OnCreate();
    virtual void OnSize(UINT nType, int cx, int cy);
    virtual void OnKeyDown(UINT /*nChar*/, UINT /*nRepCnt*/, UINT /*nFlags*/);

private:
    int m_ScreenHeight;
    int m_ScreenWidth;

    NBRE_RenderEngine*  mRenderEngine;
    NBRE_MapMaterialManager* mMapMaterialManager;
    NBRE_CameraPtr mCamera;
    CCameraController* mCameraController;
    NBRE_SceneManagerPtr mSceneManager;
    NBGM_Instance* m_nbgm; 
};

