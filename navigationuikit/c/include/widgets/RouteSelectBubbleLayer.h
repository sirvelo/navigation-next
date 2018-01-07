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
    @file         RouteSelectBubbleLayer.h
    @defgroup     nkui
*/
/*
    (C) Copyright 2014 by TeleCommunications Systems, Inc.

    The information contained herein is confidential, proprietary to
    TeleCommunication Systems, Inc., and considered a trade secret as defined
    in section 499C of the penal code of the State of California. Use of this
    information by anyone other than authorized employees of TeleCommunication
    Systems is granted only under a written non-disclosure agreement, expressly
    prescribing the scope and manner of such use.
--------------------------------------------------------------------------
*/

/*! @{ */

#ifndef _NKUI_ROUTESELECTBUBBLELAYER_H_
#define _NKUI_ROUTESELECTBUBBLELAYER_H_

#include <vector>

#include "NKUIMapDataType.h"
#include "Widget.h"

namespace nkui
{

class RouteSelectBubble
{
public:
    /**
     *  Update bubble position
     *
     *  @param position: The new position
     */
    virtual void SetPosition(const ScreenPoint& position) = 0;

    /**
     *  Set bubble select status.
     *
     *  @param bSelected: TRUE if selected.
     */
    virtual void SetSelected(bool bSelected) = 0;

    /**
     *  Set the text shown on the bubble
     *
     *  @param text: The text string
     */
    virtual void SetText(const std::string& text) = 0;
};

/** Show RTS Bubbles
 **/
class RouteSelectBubbleLayer
{
public:
    /**
     *  Create new RTS bubble
     *
     *  @param text: The text shown on the bubble.
     *  @return: Returns the created bubble. NULL if failed.
     */
    virtual RouteSelectBubble* CreateBubble(const ScreenPoint& position) = 0;

    /**
     *  Destroy all created bubbles.
     */
    virtual void ClearBubbles() = 0;

    /**
     *  Update layout of all created bubbles
     */
    virtual void UpdateLayout(bool bRightNow) = 0;
};
}

#endif // NavigationUIKit_RouteSelectBubbleLayer_h

/*! @} */
