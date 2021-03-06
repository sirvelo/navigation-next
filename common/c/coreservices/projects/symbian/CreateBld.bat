SET filename=bld.inf
SET file=%filename%

ECHO //>%file%
ECHO //>>%file%
ECHO.>>%file%
ECHO PRJ_PLATFORMS>>%file%
ECHO DEFAULT>>%file%
ECHO.>>%file%
ECHO PRJ_MMPFILES>>%file%
ECHO coreservices.mmp>>%file%
ECHO.>>%file%
ECHO PRJ_EXPORTS>>%file%

PUSHD ..\..\include
SET file=..\projects\symbian\%filename%
DIR /B /ON *.h > FileList.txt
FOR /F %%f IN (FileList.txt) DO ECHO ..\..\include\%%f			\Epoc32\include\NIM\CoreTech\nimcoreservices\%%f>>%file%
DEL FileList.txt
POPD

REM PUSHD ..\..\include\private
REM SET file=..\..\projects\symbian\%filename%
REM DIR /B /ON *.h > FileList.txt
REM ECHO.>>%file%
REM FOR /F %%f IN (FileList.txt) DO ECHO ..\..\include\private\%%f			\Epoc32\include\NIM\CoreTech\nimcoreservices\private\%%f>>%file%
REM DEL FileList.txt
REM POPD

PUSHD ..\..\include\protected
SET file=..\..\projects\symbian\%filename%
DIR /B /ON *.h > FileList.txt
ECHO.>>%file%
FOR /F %%f IN (FileList.txt) DO ECHO ..\..\include\protected\%%f		\Epoc32\include\NIM\CoreTech\nimcoreservices\protected\%%f>>%file%
DEL FileList.txt
POPD

PUSHD ..\..\include\symbian
SET file=..\..\projects\symbian\%filename%
DIR /B /ON *.h > FileList.txt
ECHO.>>%file%
FOR /F %%f IN (FileList.txt) DO ECHO ..\..\include\symbian\%%f			\Epoc32\include\NIM\CoreTech\nimcoreservices\symbian\%%f>>%file%
DEL FileList.txt
POPD