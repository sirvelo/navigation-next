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

    @file nbred3d11vertexdeclaration.h
*/
/*
    (C) Copyright 2010 by Networks In Motion, Inc.

    The information contained herein is confidential, proprietary
    to Networks In Motion, Inc., and considered a trade secret as
    defined in section 499C of the penal code of the State of
    California. Use of this information by anyone other than
    authorized employees of Networks In Motion is granted only
    under a written non-disclosure agreement, expressly
    prescribing the scope and manner of such use.

---------------------------------------------------------------------------*/
#ifndef _NBRE_D3D11_VERTEX_DECLARATION_H_
#define _NBRE_D3D11_VERTEX_DECLARATION_H_
#include "nbrevertexindexdata.h"
#include "nbred3d11common.h"

class NBRE_D3D11GPUPorgram;
class NBRE_D3D11RenderPal;

/*! \addtogroup NBRE_RenderPal
*  @{
*/
/*! \addtogroup NBRE_D3D11RenderPal
*  @{
*/

enum NBRE_VertexInputFormat
{
    NBRE_VSIF_POSITION = 0,
    NBRE_VSIF_COLOR    = 0x1<<0,
    NBRE_VSIF_NORMAL   = 0x1<<1,
    NBRE_VSIF_TEXCORD0 = 0x1<<2,
    NBRE_VSIF_TEXCORD1 = 0x1<<3
};

/** Specialization of VertexDeclaration for Direct3D 11 */
class NBRE_D3D11VertexDeclaration:public NBRE_VertexDeclaration
{
public:
    NBRE_D3D11VertexDeclaration(NBRE_D3D11RenderPal *pal);
    virtual ~NBRE_D3D11VertexDeclaration();

public:
    D3D11_INPUT_ELEMENT_DESC* GetD3D11Declaration()const;
    ID3D11InputLayout* GetInputLayoutByShader(NBRE_D3D11GPUPorgram *program)const;
    uint32 GetVertexInputFormat()const;

private:
    DISABLE_COPY_AND_ASSIGN(NBRE_D3D11VertexDeclaration);

private:
    typedef NBRE_Map<NBRE_D3D11GPUPorgram*, ID3D11InputLayout*> ShaderToILayoutMap;
    typedef ShaderToILayoutMap::iterator ShaderToILayoutMapIterator;
    NBRE_D3D11RenderPal *mPal;
    mutable D3D11_INPUT_ELEMENT_DESC *mD3delems;
    mutable ShaderToILayoutMap mLayoutMap;
    mutable uint32 mVertexInputFormat;
};

/*! @} */
/*! @} */
#endif
