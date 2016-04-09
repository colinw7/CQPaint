#include <CQPaint.h>
#include <CQPaintGaussianBlur.h>
#include <CQPaintTurbulence.h>
#include <CQPaintTools.h>
#include <CQResizeImageDlg.h>
#include <CQPixmapCache.h>

#include <CQImageCanvas.h>
#include <CQColorWheel.h>
#include <CQFileMgr.h>
#include <COSFile.h>
#include <QtGui>
#include <QFileDialog>
#include <QMessageBox>
#include <QStatusBar>

#include <svg/new_svg.h>
#include <svg/load_svg.h>
#include <svg/save_svg.h>
#include <svg/save_as_svg.h>
#include <svg/invert_svg.h>
#include <svg/greyscale_svg.h>
#include <svg/sepia_svg.h>
#include <svg/rotate_svg.h>
#include <svg/scroll_svg.h>

CQPaint::
CQPaint() :
 CQMainWindow("CQPaint"),
 mode_       (MODE_SELECT)
{
}

void
CQPaint::
setMode(Mode mode)
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window)
    window->setMode((CQImageCanvas::Mode) mode);

  mode_ = mode;
}

void
CQPaint::
newImage()
{
  CQImageCanvas *window = workspace_->addWindow("New");

  window->doResize(400, 400, false, false);

  connect(window, SIGNAL(penBgChanged()), this, SLOT(canvasPenBgChanged()));
  connect(window, SIGNAL(penFgChanged()), this, SLOT(canvasPenFgChanged()));
}

void
CQPaint::
load()
{
  QString title  = "Choose a file";
  QString cwd    = QString(COSFile::getCurrentDir().c_str());
  QString filter = "Images (*.gif *.iff *.jpg *.png *.xbm *.xpm *.xwd)";

  QStringList filenames = QFileDialog::getOpenFileNames(this, title, cwd, filter);

  if (filenames.size() == 0)
    return;

  QStringListIterator fi(filenames);

  while (fi.hasNext())
    load(fi.next());
}

void
CQPaint::
load(const std::string &fileName)
{
  load(QString(fileName.c_str()));
}

void
CQPaint::
load(const QString &fileName)
{
  CQImageCanvas *window = workspace_->addWindow(fileName);

  window->updateImage(fileName.toStdString());

  dynamic_cast<QWidget*>(window)->
    resize(window->getImageWidth(), window->getImageHeight());

  connect(window, SIGNAL(penBgChanged()), this, SLOT(canvasPenBgChanged()));
  connect(window, SIGNAL(penFgChanged()), this, SLOT(canvasPenFgChanged()));

  connect(window, SIGNAL(keyPressed(const CKeyEvent &)),
          this, SLOT(canvasKeyPressed(const CKeyEvent &)));
}

void
CQPaint::
save()
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window == 0)
    return;

  std::cerr << "Save " << std::endl;
}

void
CQPaint::
saveAs()
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window == 0)
    return;

  QString title  = "Choose a file";
  QString cwd    = QString(COSFile::getCurrentDir().c_str());
  QString filter = "Images (*.gif *.iff *.jpg *.png *.xbm *.xpm *.xwd)";

  QString filename = QFileDialog::getSaveFileName(this, title, cwd, filter);

  if (filename.isNull())
    return;

  std::cerr << "Save As " << filename.toStdString() << std::endl;
}

void
CQPaint::
fillScreen(bool flag)
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0)
    window->setFillScreen(flag);
}

void
CQPaint::
keepAspect(bool flag)
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0)
    window->setKeepAspect(flag);
}

void
CQPaint::
zoomCursor(bool flag)
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0) window->setZoomCursor(flag);
}

void
CQPaint::
selectAll()
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0)
    window->selectAll();
}

void
CQPaint::
selectNone()
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0)
    window->selectNone();
}

void
CQPaint::
clear()
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0)
    window->clear();
}

void
CQPaint::
invert()
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0)
    window->invert();
}

void
CQPaint::
grayscale()
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0)
    window->grayscale();
}

void
CQPaint::
sepia()
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0)
    window->sepia();
}

void
CQPaint::
resize()
{
  CQResizeImageDlg *dialog = new CQResizeImageDlg(this);

  connect(dialog, SIGNAL(resize(int, int, bool, bool)),
          this, SLOT(resizeAccept(int, int, bool, bool)));

  dialog->show();
}

void
CQPaint::
resizeAccept(int width, int height, bool scale, bool aspect)
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0)
    window->doResize(width, height, scale, aspect);
}

void
CQPaint::
gaussianBlur()
{
  CQPaintGaussianBlur *dialog = CQPaintGaussianBlurInst(this);

  connect(dialog, SIGNAL(gaussianBlur(double, double, int, int)),
          this, SLOT(gaussianBlurAccept(double, double, int, int)));

  dialog->show();
}

void
CQPaint::
gaussianBlurAccept(double xBlur, double yBlur, int xSize, int ySize)
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0)
    window->gaussianBlur(xBlur, yBlur, xSize, ySize);
}

void
CQPaint::
turbulence()
{
  CQPaintTurbulence *dialog = CQPaintTurbulenceInst(this);

  connect(dialog, SIGNAL(turbulence(bool, double, int, int)),
          this, SLOT(turbulenceAccept(bool, double, int, int)));

  dialog->show();
}

void
CQPaint::
turbulenceAccept(bool fractal, double freq, int octaves, int seed)
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0) {
    //window->getImage()->setWindow(window->getSelectionRect());

    window->getImage()->turbulence(fractal, freq, octaves, seed);

    window->getImage()->resetWindow();

    window->updateVImage(true);

    //window->turbulence(fractal, freq, octaves, seed);
  }
}

void
CQPaint::
unsharpMask()
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0) {
    CImagePtr mimage = window->getImage()->unsharpMask(4.0);

    window->updateImage(mimage);
  }
}

void
CQPaint::
rotateMode()
{
  if (rotateItem->getAction()->isChecked())
    setRotateMode();
  else
    setSelectMode();
}

void
CQPaint::
flipMode()
{
  if (flipItem->getAction()->isChecked())
    setFlipMode();
  else
    setSelectMode();
}

void
CQPaint::
scrollMode()
{
  if (scrollItem->getAction()->isChecked())
    setScrollMode();
  else
    setSelectMode();
}

void
CQPaint::
zoomIncrease()
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0) window->zoomIncrease();
}

void
CQPaint::
zoomDecrease()
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0) window->zoomDecrease();
}

void
CQPaint::
about()
{
  QMessageBox::about(this, "About", "Blah Blah Blah");
}

void
CQPaint::
colorBgChanged()
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0)
    window->setPenBackground(color_wheel_->getBgRGB());
}

void
CQPaint::
colorFgChanged()
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0)
    window->setPenForeground(color_wheel_->getFgRGB());
}


void
CQPaint::
canvasPenBgChanged()
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0)
    color_wheel_->setBgRGB(window->getPenBackground());
}

void
CQPaint::
canvasPenFgChanged()
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window != 0)
    color_wheel_->setFgRGB(window->getPenForeground());
}

void
CQPaint::
canvasKeyPressed(const CKeyEvent &event)
{
  CQImageCanvas *window = workspace_->activeWindow();

  if (window == 0) return;

  if      (mode_ == MODE_ROTATE) {
    CImagePtr rimage;

    if      (event.isType(CKEY_TYPE_Left))
      rimage = window->getImage()->rotate(90);
    else if (event.isType(CKEY_TYPE_Right))
      rimage = window->getImage()->rotate(-90);
    else
      return;

    window->updateImage(rimage);
  }
  else if (mode_ == MODE_FLIP) {
    if      (event.isType(CKEY_TYPE_Left) || event.isType(CKEY_TYPE_Right))
      window->getImage()->flipV();
    else if (event.isType(CKEY_TYPE_Up) || event.isType(CKEY_TYPE_Down))
      window->getImage()->flipH();
    else
      return;

    window->updateVImage(true);
  }
  else if (mode_ == MODE_SCROLL) {
    if      (event.isType(CKEY_TYPE_Up))
      window->getImage()->scrollY(1);
    else if (event.isType(CKEY_TYPE_Down))
      window->getImage()->scrollY(-1);
    else if (event.isType(CKEY_TYPE_Left))
      window->getImage()->scrollX(1);
    else if (event.isType(CKEY_TYPE_Right))
      window->getImage()->scrollX(-1);
    else
      return;

    window->updateVImage(true);
  }
}

void
CQPaint::
createWorkspace()
{
  workspace_ = new CQWorkspace<CQImageCanvas>(this, "workspace");

  connect(workspace_->getWorkspace(), SIGNAL(widgetActivated(QWidget *)),
          this, SLOT(activeWidgetChanged(QWidget *)));
}

void
CQPaint::
createMenus()
{
  fileMenu = new CQMenu(this, "&File");

  //----

  newItem = new CQMenuItem(fileMenu, "&New");

  newItem->setShortcut("Ctrl+N");
  newItem->setStatusTip("Create new image");
  newItem->setIcon(CQPixmapCacheInst->getIcon("NEW"));

  newItem->connect(SIGNAL(triggered()), this, SLOT(newImage()));

  //----

  loadItem = new CQMenuItem(fileMenu, "&Load");

  loadItem->setShortcut("Ctrl+L");
  loadItem->setStatusTip("Load new image");
  loadItem->setIcon(CQPixmapCacheInst->getIcon("LOAD"));

  connect(loadItem->getAction(), SIGNAL(triggered()), this, SLOT(load()));

  //----

  saveItem = new CQMenuItem(fileMenu, "&Save");

  saveItem->setShortcut("Ctrl+S");
  saveItem->setStatusTip("Save current image");
  saveItem->setIcon(CQPixmapCacheInst->getIcon("SAVE"));

  connect(saveItem->getAction(), SIGNAL(triggered()), this, SLOT(save()));

  //----

  saveAsItem = new CQMenuItem(fileMenu, "Save &As...");

  saveAsItem->setShortcut("Ctrl+A");
  saveAsItem->setStatusTip("Save current images as new file");
  saveAsItem->setIcon(CQPixmapCacheInst->getIcon("SAVE_AS"));

  connect(saveAsItem->getAction(), SIGNAL(triggered()), this, SLOT(saveAs()));

  //----

  fileMenu->addSeparator();

  //----

  quitItem = new CQMenuItem(fileMenu, "&Quit");

  quitItem->setShortcut("Ctrl+Q");
  quitItem->setStatusTip("Quit the application");

  connect(quitItem->getAction(), SIGNAL(triggered()), this, SLOT(close()));

  //--------

  editMenu = new CQMenu(this, "&Edit");

  //----

  resizeItem = new CQMenuItem(editMenu, "&Resize ...");

  resizeItem->setStatusTip("Resize Image");

  connect(resizeItem->getAction(), SIGNAL(triggered()), this, SLOT(resize()));

  //----

  fillScreenItem = new CQMenuItem(editMenu, "&Fill Screen");

  fillScreenItem->setStatusTip("Fill Screen");

  connect(fillScreenItem->getAction(), SIGNAL(triggered(bool)), this, SLOT(fillScreen(bool)));

  //----

  keepAspectItem = new CQMenuItem(editMenu, "&Keep Aspect", CQMenuItem::CHECKABLE);

  keepAspectItem->setStatusTip("Keep Aspect Ratio");

  connect(keepAspectItem->getAction(), SIGNAL(triggered(bool)), this, SLOT(keepAspect(bool)));

  //----

  zoomCursorItem = new CQMenuItem(editMenu, "&Zoom Cursor", CQMenuItem::CHECKABLE);

  zoomCursorItem->setStatusTip("Zoom Image ar Cursor");

  connect(zoomCursorItem->getAction(), SIGNAL(triggered(bool)), this, SLOT(zoomCursor(bool)));

  //--------

  processMenu = new CQMenu(this, "&Process");

  //----

  clearItem = new CQMenuItem(processMenu, "&Clear");

  clearItem->setStatusTip("Clear Image or Selection");

  connect(clearItem->getAction(), SIGNAL(triggered()), this, SLOT(clear()));

  //----

  invertItem = new CQMenuItem(processMenu, "&Invert");

  invertItem->setStatusTip("Invert Image or Selection");
  invertItem->setIcon(CQPixmapCacheInst->getIcon("INVERT"));

  connect(invertItem->getAction(), SIGNAL(triggered()), this, SLOT(invert()));

  //----

  grayScaleItem = new CQMenuItem(processMenu, "&Grey Scale");

  grayScaleItem->setStatusTip("Gray Scale Image or Selection");
  grayScaleItem->setIcon(CQPixmapCacheInst->getIcon("GREYSCALE"));

  connect(grayScaleItem->getAction(), SIGNAL(triggered()), this, SLOT(grayscale()));

  //----

  sepiaItem = new CQMenuItem(processMenu, "&Sepia");

  sepiaItem->setStatusTip("Sepia Image or Selection");
  sepiaItem->setIcon(CQPixmapCacheInst->getIcon("SEPIA"));

  connect(sepiaItem->getAction(), SIGNAL(triggered()), this, SLOT(sepia()));

  //----

  gaussianBlurItem = new CQMenuItem(processMenu, "&Gaussian Blur ...");

  gaussianBlurItem->setStatusTip("Gaussian Blur Image or Selection");

  connect(gaussianBlurItem->getAction(), SIGNAL(triggered()), this, SLOT(gaussianBlur()));

  //----

  turbulenceItem = new CQMenuItem(processMenu, "&Turbulence ...");

  turbulenceItem->setStatusTip("Create Turbulence for Image or Selection");

  connect(turbulenceItem->getAction(), SIGNAL(triggered()), this, SLOT(turbulence()));

  //----

  unsharpMaskItem = new CQMenuItem(processMenu, "&Unsharp Mask ...");

  unsharpMaskItem->setStatusTip("Create Unsharp Mask for Image or Selection");

  connect(unsharpMaskItem->getAction(), SIGNAL(triggered()), this, SLOT(unsharpMask()));

  //----

  rotateItem = new CQMenuItem(processMenu, "&Rotate", CQMenuItem::CHECKABLE);

  rotateItem->setStatusTip("Rotate Image");
  rotateItem->setIcon(CQPixmapCacheInst->getIcon("ROTATE"));

  connect(rotateItem->getAction(), SIGNAL(triggered()), this, SLOT(rotateMode()));

  //----

  flipItem = new CQMenuItem(processMenu, "&Flip", CQMenuItem::CHECKABLE);

  flipItem->setStatusTip("Flip Image");

  connect(flipItem->getAction(), SIGNAL(triggered()), this, SLOT(flipMode()));

  //----

  scrollItem = new CQMenuItem(processMenu, "&Scroll", CQMenuItem::CHECKABLE);

  scrollItem->setStatusTip("Scroll Image");
  scrollItem->setIcon(CQPixmapCacheInst->getIcon("SCROLL"));

  connect(scrollItem->getAction(), SIGNAL(triggered()), this, SLOT(scrollMode()));

  //--------

  selectionMenu = new CQMenu(this, "&Selection");

  //----

  selectAllItem = new CQMenuItem(selectionMenu, "Select &All");

  selectAllItem->setStatusTip("Select Whole Image");

  connect(selectAllItem->getAction(), SIGNAL(triggered()), this, SLOT(selectAll()));

  //----

  selectNoneItem = new CQMenuItem(selectionMenu, "Select &None");

  selectNoneItem->setStatusTip("Deselect Whole Image");

  connect(selectNoneItem->getAction(), SIGNAL(triggered()), this, SLOT(selectNone()));

  //--------

  zoomMenu = new CQMenu(this, "&Zoom");

  //----

  zoomIncreaseItem = new CQMenuItem(zoomMenu, "&Increase");

  zoomIncreaseItem->setStatusTip("Increase Zoom by 1 Step");

  connect(zoomIncreaseItem->getAction(), SIGNAL(triggered()), this, SLOT(zoomIncrease()));

  //----

  zoomDecreaseItem = new CQMenuItem(zoomMenu, "&Decrease");

  zoomDecreaseItem->setStatusTip("Decrease Zoom by 1 Step");

  connect(zoomDecreaseItem->getAction(), SIGNAL(triggered()), this, SLOT(zoomDecrease()));

  //--------

  toolsMenu = CQDockMgrInst->addToolsMenu(this);

  //----

  windowsMenu = workspace_->addWindowsMenu();

  //--------

  new CQMenu(this, "|");

  //--------

  helpMenu = new CQMenu(this, "&Help");

  //----

  aboutItem = new CQMenuItem(helpMenu, "&About");

  aboutItem->setStatusTip("Show the application's About box");

  connect(aboutItem->getAction(), SIGNAL(triggered()), this, SLOT(about()));

  //----

//aboutQtItem = new CQMenuItem(helpMenu, "About &Qt");

//aboutQtItem->setStatusTip("Show the Qt library's About box");

//connect(aboutQtItem->getAction(), SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void
CQPaint::
createToolBars()
{
  fileToolBar = new CQToolBar(this, "File");

  fileToolBar->addItem(loadItem);
  fileToolBar->addItem(saveItem);
  fileToolBar->addItem(saveAsItem);

  editToolBar = new CQToolBar(this, "Edit");

  editToolBar->addItem(resizeItem);
  editToolBar->addItem(zoomCursorItem);

  processToolBar = new CQToolBar(this, "Process");

  processToolBar->addItem(invertItem);
  processToolBar->addItem(grayScaleItem);
  processToolBar->addItem(sepiaItem);
  processToolBar->addItem(gaussianBlurItem);
  processToolBar->addItem(turbulenceItem);
  processToolBar->addItem(unsharpMaskItem);
  processToolBar->addItem(rotateItem);
  processToolBar->addItem(flipItem);
  processToolBar->addItem(scrollItem);
}

void
CQPaint::
createStatusBar()
{
  statusBar()->showMessage("Ready");
}

void
CQPaint::
createDockWindows()
{
  color_wheel_ = new CQColorWheel;

  CQDockWidget *dock1 = new CQDockWidget(this, "Color Wheel", color_wheel_);

  dock1->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

  connect(color_wheel_, SIGNAL(colorBgChanged()), this, SLOT(colorBgChanged()));
  connect(color_wheel_, SIGNAL(colorFgChanged()), this, SLOT(colorFgChanged()));

  //------

  file_mgr_ = new CQFileMgr;

  CQDockWidget *dock2 = new CQDockWidget(this, "File Mgr", file_mgr_);

  dock2->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

  connect(file_mgr_, SIGNAL(fileActivated(const QString &)), this, SLOT(load(const QString &)));

  //------

  paint_tools_ = new CQPaintTools;

  CQDockWidget *dock3 = new CQDockWidget(this, "Tools", paint_tools_, Qt::LeftDockWidgetArea);

  dock3->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

  connect(paint_tools_, SIGNAL(select ()), this, SLOT(setSelectMode()));
  connect(paint_tools_, SIGNAL(pen    ()), this, SLOT(setPenMode()));
  connect(paint_tools_, SIGNAL(dropper()), this, SLOT(setDropperMode()));
  connect(paint_tools_, SIGNAL(fill   ()), this, SLOT(setFillMode()));
}

void
CQPaint::
setSelectMode()
{
  setMode(CQPaint::MODE_SELECT);
}

void
CQPaint::
setPenMode()
{
  setMode(CQPaint::MODE_PEN);
}

void
CQPaint::
setDropperMode()
{
  setMode(CQPaint::MODE_DROPPER);
}

void
CQPaint::
setFillMode()
{
  setMode(CQPaint::MODE_FILL);
}

void
CQPaint::
setRotateMode()
{
  setMode(CQPaint::MODE_ROTATE);
}

void
CQPaint::
setFlipMode()
{
  setMode(CQPaint::MODE_FLIP);
}

void
CQPaint::
setScrollMode()
{
  setMode(CQPaint::MODE_SCROLL);
}

void
CQPaint::
activeWidgetChanged(QWidget *)
{
}
