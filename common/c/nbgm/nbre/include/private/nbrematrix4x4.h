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

    @file nbrematrix4.h
*/
/*
    (C) Copyright 2012 by Networks In Motion, Inc.

    The information contained herein is confidential, proprietary
    to Networks In Motion, Inc., and considered a trade secret as
    defined in section 499C of the penal code of the State of
    California. Use of this information by anyone other than
    authorized employees of Networks In Motion is granted only
    under a written non-disclosure agreement, expressly
    prescribing the scope and manner of such use.

---------------------------------------------------------------------------*/

#ifndef _NBRE_MATRIX4X4_H_
#define _NBRE_MATRIX4X4_H_

#include "paltypes.h"
#include "nbrevector3.h"
#include "nbrevector4.h"
#include "nbresharedptr.h"

/** \addtogroup NBRE_Core
*  @{
*/
//! 4 x 4 matrix
/** 
*/
template <typename Real>
class NBRE_Matrix4x4
{
public:

    NBRE_Matrix4x4();
    NBRE_Matrix4x4(
                Real m00, Real m01, Real m02, Real m03,
                Real m10, Real m11, Real m12, Real m13,
                Real m20, Real m21, Real m22, Real m23,
                Real m30, Real m31, Real m32, Real m33);

    NBRE_Matrix4x4(const Real* m, nb_boolean isRowMajor);
    NBRE_Matrix4x4(const Real m[4][4]);
    NBRE_Matrix4x4(const NBRE_Matrix4x4<Real>& m);

    ~NBRE_Matrix4x4();

public:
    NBRE_Matrix4x4<Real>& operator = (const NBRE_Matrix4x4<Real>& m1);
    nb_boolean operator == (const NBRE_Matrix4x4<Real>& m1) const;

    NBRE_Matrix4x4<Real> operator + (const NBRE_Matrix4x4<Real>& m1) const;
    NBRE_Matrix4x4<Real>& operator += (const NBRE_Matrix4x4<Real>& m1);

    NBRE_Matrix4x4<Real> operator - (const NBRE_Matrix4x4<Real>& m1) const;
    NBRE_Matrix4x4<Real>& operator -= (const NBRE_Matrix4x4<Real>& m1);
    NBRE_Matrix4x4<Real>& operator - ();

    NBRE_Matrix4x4<Real> operator * (const NBRE_Matrix4x4<Real>& m1) const;
    NBRE_Matrix4x4<Real>& operator *= (const NBRE_Matrix4x4<Real>& m1);

    const Real* operator [] (uint8 row) const;
    Real* operator [] (uint8 row);

    NBRE_Vector3<Real> operator * (const NBRE_Vector3<Real>& vector) const;
    NBRE_Vector4<Real> operator * (const NBRE_Vector4<Real>& vector) const;

    void LoadFrom(const Real* buffer, nb_boolean isRowMajor);
    void CopyTo(Real* buffer, nb_boolean isRowMajor) const;
    void Identity();
    void Zero();
    void Transpose();
    NBRE_Matrix4x4<Real> Inverse() const;

    void Reverse();

private:
    Real mBuffer[4][4];
};

#include "nbrematrix4x4.inl"

typedef NBRE_Matrix4x4<float> NBRE_Matrix4x4f;
typedef NBRE_Matrix4x4<double> NBRE_Matrix4x4d;

typedef shared_ptr<NBRE_Matrix4x4f> NBRE_Matrix4x4fPtr;

/** @} */

#endif
