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

    @file     mainwindow.h
    @date     12/09/2014
    @defgroup navigationuikit sample
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

/*! @{ */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "navigationuikit.h"
#include "navigationuimapcontroller.h"
#include "util.h"
#include "routeoptionwidget.h"
#include "interpolator.h"
#include "layeroptionwidget.h"
#include "ltkhybridmanager.h"

using namespace locationtoolkit;

namespace Ui {
class MainWindow;
}

class NavigationUIMapImpl;
class PositionInputDialog;
class MainWindow : public QMainWindow,
                   public LocationListener
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public Q_SLOTS:
    void OnRouteOptions();
    void OnNavigationEnd();
    void OnNewAvoidOptions( quint32 options );
    void OnNavigationStarted();

protected:
    void contextMenuEvent( QContextMenuEvent * event );

private slots:
    void on_actionStart_triggered();
    void on_actionRouteOption_triggered();
    void on_actionExit_triggered();
    void OnMapCreated();
    void OnLayersCreated();
    void OnTimer();
    void on_actionAbout_triggered();
    void on_actionGPS_Select_triggered();
    void OnLayerOptionButtonClicked();
    void on_actionDebug_View_triggered();
    void OnMapLongClick(const locationtoolkit::Coordinates& coordinate);
    void OnMapUnlocked();

private:
    int InitializeNavigationuikit(const Place& destination, bool enableRts);
    void StartFollowMe();
    void StopFollowMe();
    void StartNavigation(double latitude, double longitude, bool enableRTS);
    void ShowModeSelector();

    // from LocationListener
    virtual void LocationUpdated( const locationtoolkit::Location& location );
    virtual void ProviderStateChanged( LocationProviderState state );
    virtual void OnLocationError(int errorCode);

private:
    Ui::MainWindow*       ui;
    QMenu*                mMenu;
    NavigationUIKit*      mNavigtionUIKit;
    LTKContext*           mLTKContext;
    LTKHybridManager*     mHybridManager;
    NavigationUIMapImpl*  mNavigationUIMapImpl;

    MapWidget*            mLTKMapKit;
    LocationConfiguration mLTKLocationConfiguration;
    NavigationUIMapController* mNavigationUIMapController;
    RouteOptionWidget*    mRouteOptionWidget;
    LayerOptionWidget*    mLayerOptionWidget;
    NavUIRouteOptions     mNavUIRouteOptions;
    QString               mGPSFilePath;
    QString               mGPSFile;
    bool                  mIsDebugViewShown;
    bool                  mIsNavigationStarted;
    bool                  mEnableRTS;

    QTime                 mInterpolatorTime;
    QTimer                mInterpolatorTimer;
    Location              mLastLocation;
    Interpolator          mLatInterpolator;
    Interpolator          mLonInterpolator;
    Interpolator          mHeadingInterpolator;

    Place                 mPlaceOrig;
    Place                 mPlaceDest;
};

#endif // MAINWINDOW_H

/*! @} */
