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

/*--------------------------------------------------------------------------

(C) Copyright 2012 by Networks In Motion, Inc.                

The information contained herein is confidential, proprietary 
to Networks In Motion, Inc., and considered a trade secret as 
defined in section 499C of the penal code of the State of     
California. Use of this information by anyone other than      
authorized employees of Networks In Motion is granted only    
under a written non-disclosure agreement, expressly           
prescribing the scope and manner of such use.                 

---------------------------------------------------------------------------*/
#include "nbrecollisionaabb2d.h"
#include "nbreintersection.h"
#include "nbrecollisiontest.h"

NBRE_CollisionAABB2d::NBRE_CollisionAABB2d(const NBRE_AxisAlignedBox2d& aabb)
:mAABB(aabb)
{
    mAABB.GetCorners(mVertices);
}

NBRE_CollisionAABB2d::~NBRE_CollisionAABB2d()
{
}

nb_boolean
NBRE_CollisionAABB2d::HitTest(NBRE_ICollisionPrimitive2d* obj)
{
    nb_boolean result = FALSE;
    NBRE_CollisionPrimitiveType type = obj->GetType();
    
    switch (type)
    {
    case NBRE_CPT_AABB2:
        {
            NBRE_CollisionAABB2d* aabbObj = (NBRE_CollisionAABB2d*)obj;
            result = NBRE_Intersectiond::HitTest(mAABB, aabbObj->mAABB);
        }
        break;
    case NBRE_CPT_POLYGON2:
        {
            NBRE_CollisionPolygon2d* polygonObj = (NBRE_CollisionPolygon2d*)obj;
            result = NBRE_CollisionTest::HitTest(this, polygonObj);
        }
        break;
    case NBRE_CPT_LINESEGMENT2:
        {
            NBRE_CollisionCircle2d* segmentObj = (NBRE_CollisionCircle2d*)obj;
            result = NBRE_CollisionTest::HitTest(this, segmentObj);
        }
        break;
    case NBRE_CPT_CIRCLE2:
        {
            NBRE_CollisionCircle2d* circleObj = (NBRE_CollisionCircle2d*)obj;
            result = NBRE_CollisionTest::HitTest(this, circleObj);
        }
        break;
    default:
        NBRE_DebugLog(PAL_LogSeverityDebug, "NBRE_CollisionAABB::HitTest, unsupported type %d", type);
    }

    return result;
}
