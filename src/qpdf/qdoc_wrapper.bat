@echo off
SetLocal EnableDelayedExpansion
(set QT_VERSION=5.15.2)
(set QT_VER=5.15)
(set QT_VERSION_TAG=5152)
(set QT_INSTALL_DOCS=C:/Local/Qt/Docs/Qt-5.15.2)
(set BUILDDIR=C:/Users/kizi/Downloads/qtpdf/src/qpdf)
C:\Local\Qt\5.15.2\msvc2019_64\bin\qdoc.exe %*
EndLocal
