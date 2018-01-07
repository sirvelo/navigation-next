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
Copyright Rene Rivera 2008-2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef BOOST_PREDEF_COMPILER_METROWERKS_H
#define BOOST_PREDEF_COMPILER_METROWERKS_H

#include <boost/predef/version_number.h>
#include <boost/predef/make.h>

/*`
[heading `BOOST_COMP_MWERKS`]

[@http://en.wikipedia.org/wiki/CodeWarrior Metrowerks CodeWarrior] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__MWERKS__`] [__predef_detection__]]
    [[`__CWCC__`] [__predef_detection__]]

    [[`__CWCC__`] [V.R.P]]
    [[`__MWERKS__`] [V.R.P >= 4.2.0]]
    [[`__MWERKS__`] [9.R.0]]
    [[`__MWERKS__`] [8.R.0]]
    ]
 */

#define BOOST_COMP_MWERKS BOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__MWERKS__) || defined(__CWCC__)
#   if !defined(BOOST_COMP_MWERKS_DETECTION) && defined(__CWCC__)
#       define BOOST_COMP_MWERKS_DETECTION BOOST_PREDEF_MAKE_0X_VRPP(__CWCC__)
#   endif
#   if !defined(BOOST_COMP_MWERKS_DETECTION) && (__MWERKS__ >= 0x4200)
#       define BOOST_COMP_MWERKS_DETECTION BOOST_PREDEF_MAKE_0X_VRPP(__MWERKS__)
#   endif
#   if !defined(BOOST_COMP_MWERKS_DETECTION) && (__MWERKS__ >= 0x3204) // note the "skip": 04->9.3
#       define BOOST_COMP_MWERKS_DETECTION BOOST_VERSION_NUMBER(9,(__MWERKS__)%100-1,0)
#   endif
#   if !defined(BOOST_COMP_MWERKS_DETECTION) && (__MWERKS__ >= 0x3200)
#       define BOOST_COMP_MWERKS_DETECTION BOOST_VERSION_NUMBER(9,(__MWERKS__)%100,0)
#   endif
#   if !defined(BOOST_COMP_MWERKS_DETECTION) && (__MWERKS__ >= 0x3000)
#       define BOOST_COMP_MWERKS_DETECTION BOOST_VERSION_NUMBER(8,(__MWERKS__)%100,0)
#   endif
#   if !defined(BOOST_COMP_MWERKS_DETECTION)
#       define BOOST_COMP_MWERKS_DETECTION BOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef BOOST_COMP_MWERKS_DETECTION
#   if defined(BOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define BOOST_COMP_MWERKS_EMULATED BOOST_COMP_MWERKS_DETECTION
#   else
#       undef BOOST_COMP_MWERKS
#       define BOOST_COMP_MWERKS BOOST_COMP_MWERKS_DETECTION
#   endif
#   define BOOST_COMP_MWERKS_AVAILABLE
#   include <boost/predef/detail/comp_detected.h>
#endif

#define BOOST_COMP_MWERKS_NAME "Metrowerks CodeWarrior"

#include <boost/predef/detail/test.h>
BOOST_PREDEF_DECLARE_TEST(BOOST_COMP_MWERKS,BOOST_COMP_MWERKS_NAME)

#ifdef BOOST_COMP_MWERKS_EMULATED
#include <boost/predef/detail/test.h>
BOOST_PREDEF_DECLARE_TEST(BOOST_COMP_MWERKS_EMULATED,BOOST_COMP_MWERKS_NAME)
#endif


#endif
