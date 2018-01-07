@ECHO OFF

@set INTERFACE=%1
@set PLATFORM=%2

@set INC_DIR=%NIMNBRE_INC%

@set TOOLS_PATH=%CORETECH_ROOT%\tools\doxygen

python %TOOLS_PATH%\gen_doc.py %TOOLS_PATH% %INC_DIR% "NBGM " %INTERFACE% %PLATFORM%

@set INTERFACE=
@set PLATFORM=
@set INC_DIR=