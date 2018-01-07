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
    @file currentroadimpl.cpp
    @date 10/20/2014
    @addtogroup navigationuikit
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
---------------------------------------------------------------------------*/

#include "currentroadimpl.h"
#include "navigationuikitwrapper.h"
#include <QVariant>
#include <QDir>
#include <QCoreApplication>
#include <QDebug>

using namespace locationtoolkit;

CurrentRoadImpl::CurrentRoadImpl()
    : mWidgetID(nkui::WGT_CURRENTROAD)
    , mPresenter(NULL)
    , mCurrentRoadViewer(NULL)
    , mCurrentRoadobject(NULL)
    , mCurrentRoad(NULL)
    , WidgetBase(nkui::WGT_CURRENTROAD)
{
}

CurrentRoadImpl::~CurrentRoadImpl()
{
    if(mCurrentRoadViewer != NULL)
    {
        delete mCurrentRoadViewer;
        mCurrentRoadViewer = NULL;
    }
}

void CurrentRoadImpl::Hide()
{
    if(mVisible)
    {
        GetNativeView()->hide();
        mVisible = false;
    }
}

nkui::WidgetID CurrentRoadImpl::GetWidgetID()
{
    return mWidgetID;
}

void CurrentRoadImpl::SetPresenter(nkui::NKUIPresenter *presenter)
{
    mPresenter = presenter;
}

void CurrentRoadImpl::Show()
{
    qDebug() << "widget ID:" << GetWidgetID();
    qDebug() << "SHOW widget IS VISIBALE:" << mVisible;
    if(!mVisible)
    {
        qDebug() << "widget SHOW";
        GetNativeView()->show();
        mVisible = true;
    }
}

void CurrentRoadImpl::UpdateCurrentRoad(const std::string &currentRoad)
{
    if (mCurrentRoad)
    {
        mCurrentRoad->setProperty("text", QVariant(QString(currentRoad.c_str())));
    }
}

QWidget *CurrentRoadImpl::GetNativeView()
{
    return mCurrentRoadViewer;
}

void CurrentRoadImpl::CreateNativeView(QWidget *parentView)
{
    QString qmlFilePath = NavigaitonUIKitWrapper::GetResourcePath() + "/qml/CurrentRoad.qml";

    mCurrentRoadViewer = new QDeclarativeView(parentView);
    mCurrentRoadViewer->setSource(QUrl::fromLocalFile(qmlFilePath));
    mCurrentRoadViewer->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    mCurrentRoadobject = (QObject* )mCurrentRoadViewer->rootObject();
    mCurrentRoad = mCurrentRoadobject->findChild<QObject*>("currentRoad");
}
