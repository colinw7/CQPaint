TEMPLATE = lib

QT += widgets

TARGET = CQPaint

DEPENDPATH += .

QMAKE_CXXFLAGS += -std=c++11

CONFIG += staticlib

MOC_DIR = .moc
UI_DIR = .moc

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
CQDirView.cpp \
CQDirBar.cpp \
CQDirPlaces.cpp \
CDirView.cpp \
\
CQFileMgr.cpp \
CQFileMgrDetails.cpp \
CQFileMgrFilmstripIcons.cpp \
CQFileMgrFilmstripImage.cpp \
CQFileMgrIcons.cpp \
CQFileMgrInfo.cpp \
CQFileMgrToolbar.cpp \
CFileMgr.cpp \
CFileMgrDetails.cpp \
CFileMgrDir.cpp \
CFileMgrFile.cpp \
CFileMgrFilmstrip.cpp \
CFileMgrIcons.cpp \
\
CQPixelRendererCanvas.cpp \
CQPixelRendererScrolledCanvas.cpp \
\
CQColorWheel.cpp \
CQColorWheelCanvas.cpp \
CQNameValue.cpp \
CQPoint3DEdit.cpp \
CQRadioButtons.cpp \
CQRGBAEdit.cpp \
CQWinWidget.cpp \
CQWorkspace.cpp \
CQZoomCursor.cpp \
CQImageButton.cpp \
CQFloatEdit.cpp \
CQAutoHide.cpp \
\
CColorWheel.cpp \
CMime.cpp \
CFileIcon.cpp \
CFileNotify.cpp \
CDirFilesMgr.cpp \
CDirFiles.cpp \
CImageThumbnail.cpp \
CEncode64.cpp \
CMathGeom2D.cpp \
CArcToBezier.cpp \

HEADERS += \
../include/CQPaint.h \
../include/CQPaintGaussianBlur.h \
../include/CQPaintTurbulence.h \
../include/CQImageCanvas.h \
../include/CQDirView.h \
../include/CQWorkspace.h \
\
CQColorWheel.h \
CQColorWheelCanvas.h \
CQDirBar.h \
CQDirPlaces.h \
CQFileMgrDetails.h \
CQFileMgrFilmstripIcons.h \
CQFileMgrFilmstripImage.h \
CQFileMgr.h \
CQFileMgrIcons.h \
CQFileMgrInfo.h \
CQFileMgrToolbar.h \
\
CQPixelRendererCanvas.h \
CQPixelRendererScrolledCanvas.h \
CQPixelRendererSubCanvas.h \
\
CQImageButton.h \
CQNameValue.h \
CQPaintTools.h \
CQPoint3DEdit.h \
CQRadioButtons.h \
CQResizeImageDlg.h \
CQRGBAEdit.h \
CQWinWidget.h \
CQZoomCursor.h \
CQFloatEdit.h \
CQAutoHide.h \

FORMS += \
CQPaintGaussianBlur.ui \
CQPaintTurbulence.ui \

OBJECTS_DIR = ../obj
DESTDIR     = ../lib

INCLUDEPATH += \
. \
../include \
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
