TEMPLATE = lib

QT += widgets

TARGET = CQPaint

DEPENDPATH += .

QMAKE_CXXFLAGS += -std=c++11

CONFIG += staticlib

MOC_DIR = .moc
UI_DIR = .ui

# Input
SOURCES += \
CQPaint.cpp \
CQPaintGaussianBlur.cpp \
CQPaintTurbulence.cpp \
CQPaintTools.cpp \
\
CQImageCanvas.cpp \
CQResizeImageDlg.cpp \
\
CQPixelRendererCanvas.cpp \
CQPixelRendererScrolledCanvas.cpp \
\
CQNameValue.cpp \
CQPoint3DEdit.cpp \
CQRGBAEdit.cpp \
CQZoomCursor.cpp \

HEADERS += \
../include/CQPaint.h \
../include/CQPaintGaussianBlur.h \
../include/CQPaintTurbulence.h \
CQPaintTools.h \
\
../include/CQImageCanvas.h \
CQResizeImageDlg.h \
\
CQPixelRendererCanvas.h \
CQPixelRendererScrolledCanvas.h \
CQPixelRendererSubCanvas.h \
\
CQNameValue.h \
CQPoint3DEdit.h \
CQRGBAEdit.h \
CQZoomCursor.h \

FORMS += \
CQPaintGaussianBlur.ui \
CQPaintTurbulence.ui \

OBJECTS_DIR = ../obj
DESTDIR     = ../lib

INCLUDEPATH += \
. \
../include \
../../CFileMgr/qinclude \
../../CFileMgr/include \
../../CColorWheel/qinclude \
../../CColorWheel/include \
../../CQUtil/include \
../../CRenderer/include \
../../CRenderer/qinclude \
../../CImageLib/include \
../../CCommand/include \
../../CConfig/include \
../../CFont/include \
../../CFileUtil/include \
../../CFile/include \
../../CMath/include \
../../CStrUtil/include \
../../CUtil/include \
../../COS/include \
/usr/include/freetype2 \
