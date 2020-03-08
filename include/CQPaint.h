#ifndef CQPAINT_H
#define CQPAINT_H

#include <CQMainWindow.h>
#include <CQMenu.h>
#include <CQToolBar.h>
#include <CQDockWidget.h>
#include <CQWorkspace.h>
#include <CQImageCanvas.h>

class CQColorWheel;
class CQFileMgr;
class CQPaintTools;

class CQPaint : public CQMainWindow {
  Q_OBJECT

 public:
  enum class Mode {
    SELECT  = (int) CQImageCanvas::Mode::SELECT,
    PEN     = (int) CQImageCanvas::Mode::PEN,
    DROPPER = (int) CQImageCanvas::Mode::DROPPER,
    FILL    = (int) CQImageCanvas::Mode::FILL,
    ROTATE  = 1001,
    FLIP    = 1002,
    SCROLL  = 1003
  };

  CQPaint();

  void setMode(Mode mode);

  void load(const std::string &fileName);

 private slots:
  void newImage();
  void load();
  void load(const QString &fileName);
  void save();
  void saveAs();

  void fillScreen(bool flag);
  void keepAspect(bool flag);
  void zoomCursor(bool flag);

  void clear();
  void invert();
  void grayscale();
  void sepia();
  void gaussianBlur();
  void gaussianBlurAccept(double xBlur, double yBlur, int xSize, int ySize);
  void turbulence();
  void turbulenceAccept(bool fractal, double freq, int octaves, int seed);
  void unsharpMask();
  void rotateMode();
  void flipMode();
  void scrollMode();
  void resize();
  void resizeAccept(int width, int height, bool scale, bool aspect);

  void selectAll();
  void selectNone();

  void zoomIncrease();
  void zoomDecrease();

  void about();

  void colorBgChanged();
  void colorFgChanged();

  void canvasPenBgChanged();
  void canvasPenFgChanged();

  void canvasKeyPressed(const CKeyEvent &event);

  void setSelectMode();
  void setPenMode();
  void setDropperMode();
  void setFillMode();
  void setRotateMode();
  void setFlipMode();
  void setScrollMode();

  void activeWidgetChanged(QWidget *);

 private:
  void createWorkspace();
  void createMenus();
  void createToolBars();
  void createStatusBar();
  void createDockWindows();

 private:
  CQWorkspace<CQImageCanvas> *workspace_;
  Mode                        mode_;

  // File Menu
  CQMenu *fileMenu;

  CQMenuItem *newItem;
  CQMenuItem *loadItem;
  CQMenuItem *saveItem;
  CQMenuItem *saveAsItem;
  CQMenuItem *quitItem;

  // Edit Menu
  CQMenu *editMenu;

  CQMenuItem *resizeItem;
  CQMenuItem *fillScreenItem;
  CQMenuItem *keepAspectItem;
  CQMenuItem *zoomCursorItem;

  // Process Menu
  CQMenu *processMenu;

  CQMenuItem *clearItem;
  CQMenuItem *invertItem;
  CQMenuItem *grayScaleItem;
  CQMenuItem *sepiaItem;
  CQMenuItem *gaussianBlurItem;
  CQMenuItem *turbulenceItem;
  CQMenuItem *unsharpMaskItem;
  CQMenuItem *rotateItem;
  CQMenuItem *flipItem;
  CQMenuItem *scrollItem;

  // Selection Menu

  CQMenu *selectionMenu;

  CQMenuItem *selectAllItem;
  CQMenuItem *selectNoneItem;

  // Zoom Menu
  CQMenu *zoomMenu;

  CQMenuItem *zoomIncreaseItem;
  CQMenuItem *zoomDecreaseItem;

  // Tools + Windows Menu (MDI + Dock)
  CQMenu *toolsMenu;
  CQMenu *windowsMenu;

  // Help Menu
  CQMenu *helpMenu;

  CQMenuItem *aboutItem;
  CQMenuItem *aboutQtItem;

  CQToolBar *fileToolBar;
  CQToolBar *editToolBar;
  CQToolBar *processToolBar;

  CQColorWheel *color_wheel_;
  CQFileMgr    *file_mgr_;
  CQPaintTools *paint_tools_;
};

#endif
