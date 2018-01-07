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
Copyright Rene Rivera 2008-2013
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef BOOST_PREDEF_COMPILER_MINGW_H
#define BOOST_PREDEF_COMPILER_MINGW_H

#include <boost/predef/version_number.h>
#include <boost/predef/make.h>

/*`
[heading `BOOST_PLAT_MINGW`]

[@http://en.wikipedia.org/wiki/MinGW MinGW] platform.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__MINGW32__`] [__predef_detection__]]
    [[`__MINGW64__`] [__predef_detection__]]

    [[`__MINGW64_VERSION_MAJOR`, `__MINGW64_VERSION_MINOR`] [V.R.0]]
    [[`__MINGW32_VERSION_MAJOR`, `__MINGW32_VERSION_MINOR`] [V.R.0]]
    ]
 */

#define BOOST_PLAT_MINGW BOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__MINGW32__) || defined(__MINGW64__)
#   include <_mingw.h>
#   if !defined(BOOST_PLAT_MINGW_DETECTION) && (defined(__MINGW64_VERSION_MAJOR) && defined(__MINGW64_VERSION_MINOR))
#       define BOOST_PLAT_MINGW_DETECTION \
            BOOST_VERSION_NUMBER(__MINGW64_VERSION_MAJOR,__MINGW64_VERSION_MINOR,0)
#   endif
#   if !defined(BOOST_PLAT_MINGW_DETECTION) && (defined(__MINGW32_VERSION_MAJOR) && defined(__MINGW32_VERSION_MINOR))
#       define BOOST_PLAT_MINGW_DETECTION \
            BOOST_VERSION_NUMBER(__MINGW32_MAJOR_VERSION,__MINGW32_MINOR_VERSION,0)
#   endif
#   if !defined(BOOST_PLAT_MINGW_DETECTION)
#       define BOOST_PLAT_MINGW_DETECTION BOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef BOOST_PLAT_MINGW_DETECTION
#   define BOOST_PLAT_MINGW_AVAILABLE
#   if defined(BOOST_PREDEF_DETAIL_PLAT_DETECTED)
#       define BOOST_PLAT_MINGW_EMULATED BOOST_PLAT_MINGW_DETECTION
#   else
#       undef BOOST_PLAT_MINGW
#       define BOOST_PLAT_MINGW BOOST_PLAT_MINGW_DETECTION
#   endif
#   include <boost/predef/detail/platform_detected.h>
#endif

#define BOOST_PLAT_MINGW_NAME "MinGW"

#include <boost/predef/detail/test.h>
BOOST_PREDEF_DECLARE_TEST(BOOST_PLAT_MINGW,BOOST_PLAT_MINGW_NAME)

#ifdef BOOST_PLAT_MINGW_EMULATED
#include <boost/predef/detail/test.h>
BOOST_PREDEF_DECLARE_TEST(BOOST_PLAT_MINGW_EMULATED,BOOST_PLAT_MINGW_NAME)
#endif


#endif
