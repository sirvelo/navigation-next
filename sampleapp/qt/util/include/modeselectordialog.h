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

    @file     modeSelectorDialog.h
    @date     3/10/2015
    @defgroup MAINWINDOW_H

    linear and angle interpolator definition
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
#ifndef MODESELECTOR_H
#define MODESELECTOR_H

#include <QDialog>
#include <QStringList>
#include "place.h"

namespace Ui {
class ModeSelectorDialog;
}

enum ModeSelectorDialogItems
{
  MSD_NavMode = 1,
  MSD_GpsSelector = 1<<1,
  MSD_Destination = 1<<2
};

struct RunMode
{
    QString gpsFile;
    bool    enableOnboard;
    bool    enableRTS;
    locationtoolkit::Place dest;
    locationtoolkit::Place orig;
    QString dataFile;
};

class ModeSelectorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModeSelectorDialog(RunMode& mode, int items, QWidget *parent = 0);
    ~ModeSelectorDialog();

    void SetGPSFileList(const QStringList &GPSFiles, const QString defaultGPS);

private slots:
    void on_GPSComboBox_currentIndexChanged(const QString &arg1);
    void accept();
    void reject();

    void on_ModeSelector_accepted();
    void OnPathButtonclicked();

    void OnTimer();

private:
    Ui::ModeSelectorDialog *ui;
    QString     mSelectedGPS;
    RunMode&    mMode;
    int         mItems;
};

#endif // MODESELECTOR_H
/*! @} */
