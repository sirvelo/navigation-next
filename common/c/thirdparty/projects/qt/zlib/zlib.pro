######################################################################
# Automatically generated by qmake (2.01a) Thu Oct 4 19:01:12 2007
######################################################################
TEMPLATE             = lib
TARGET               = zlib
CONFIG               += staticlib
CONFIG               += debug_and_release debug_and_release_target
PROJ_ROOT            = ../../../zlib
INCLUDEPATH          += $$PROJ_ROOT
SOURCES              += $$PROJ_ROOT/*.c



BRANCH = $$dirname(PWD)
BRANCH = $$dirname(BRANCH)
BRANCH = $$dirname(BRANCH)
BRANCH = $$basename(BRANCH)
CCC_ROOT             = ../../../../..

debug:DESTDIR = $$CCC_ROOT/build/$$BRANCH/output/lib/qt/debug/
release:DESTDIR = $$CCC_ROOT/build/$$BRANCH/output/lib/qt/release/
