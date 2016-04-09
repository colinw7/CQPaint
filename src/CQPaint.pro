TEMPLATE = lib

QT += widgets

TARGET = CQPaint

DEPENDPATH += .

QMAKE_CXXFLAGS += -std=c++11

CONFIG += staticlib

MOC_DIR = .moc

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
CQPixelRenderer.cpp \
CQPixelRendererScrolledCanvas.cpp \
CQWidgetPixelRenderer.cpp \
CImagePixelRenderer.cpp \
CPixelRenderer.cpp \
CPixelClip.cpp \
CSymbol2D.cpp \
\
CQColorWheel.cpp \
CQColorWheelCanvas.cpp \
CQNameValue.cpp \
CQIntegerEdit.cpp \
CQPoint2DEdit.cpp \
CQPoint3DEdit.cpp \
CQRadioButtons.cpp \
CQRealEdit.cpp \
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
CFreeType.cpp \
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
CQDrawUtil.h \
CQFileMgrDetails.h \
CQFileMgrFilmstripIcons.h \
CQFileMgrFilmstripImage.h \
CQFileMgr.h \
CQFileMgrIcons.h \
CQFileMgrInfo.h \
CQFileMgrToolbar.h \
\
CQPixelRendererCanvas.h \
CQPixelRenderer.h \
CQPixelRendererScrolledCanvas.h \
CQPixelRendererSubCanvas.h \
CQWidgetPixelRenderer.h \
\
CQImageButton.h \
CQIntegerEdit.h \
CQNameValue.h \
CQPaintTools.h \
CQPoint2DEdit.h \
CQPoint3DEdit.h \
CQRadioButtons.h \
CQRealEdit.h \
CQRealSpin.h \
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
../../CImageLib/include \
../../CCommand/include \
../../CConfig/include \
../../CFont/include \
../../CFile/include \
../../CMath/include \
../../CStrUtil/include \
../../CUtil/include \
../../COS/include \
/usr/include/freetype2 \
