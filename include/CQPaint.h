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
  CQWorkspace<CQImageCanvas>* workspace_ { nullptr };

  Mode mode_ { Mode::SELECT };

  // File Menu
  CQMenu *fileMenu { nullptr };

  CQMenuItem *newItem { nullptr };
  CQMenuItem *loadItem { nullptr };
  CQMenuItem *saveItem { nullptr };
  CQMenuItem *saveAsItem { nullptr };
  CQMenuItem *quitItem { nullptr };

  // Edit Menu
  CQMenu *editMenu { nullptr };

  CQMenuItem *resizeItem { nullptr };
  CQMenuItem *fillScreenItem { nullptr };
  CQMenuItem *keepAspectItem { nullptr };
  CQMenuItem *zoomCursorItem { nullptr };

  // Process Menu
  CQMenu *processMenu { nullptr };

  CQMenuItem *clearItem        { nullptr };
  CQMenuItem *invertItem       { nullptr };
  CQMenuItem *grayScaleItem    { nullptr };
  CQMenuItem *sepiaItem        { nullptr };
  CQMenuItem *gaussianBlurItem { nullptr };
  CQMenuItem *turbulenceItem   { nullptr };
  CQMenuItem *unsharpMaskItem  { nullptr };
  CQMenuItem *rotateItem       { nullptr };
  CQMenuItem *flipItem         { nullptr };
  CQMenuItem *scrollItem       { nullptr };

  // Selection Menu

  CQMenu *selectionMenu { nullptr };

  CQMenuItem *selectAllItem  { nullptr };
  CQMenuItem *selectNoneItem { nullptr };

  // Zoom Menu
  CQMenu *zoomMenu { nullptr };

  CQMenuItem *zoomIncreaseItem { nullptr };
  CQMenuItem *zoomDecreaseItem { nullptr };

  // Tools + Windows Menu (MDI + Dock)
  CQMenu *toolsMenu   { nullptr };
  CQMenu *windowsMenu { nullptr };

  // Help Menu
  CQMenu *helpMenu { nullptr };

  CQMenuItem *aboutItem   { nullptr };
  CQMenuItem *aboutQtItem { nullptr };

  CQToolBar *fileToolBar    { nullptr };
  CQToolBar *editToolBar    { nullptr };
  CQToolBar *processToolBar { nullptr };

  CQColorWheel *color_wheel_ { nullptr };
  CQFileMgr    *file_mgr_    { nullptr };
  CQPaintTools *paint_tools_ { nullptr };
};

#endif
