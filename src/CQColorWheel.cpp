#include <CQColorWheel.h>
#include <CQColorWheelCanvas.h>
#include <CColorWheel.h>
#include <CQUtil.h>

#include <QVBoxLayout>
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QSlider>
#include <QGroupBox>
#include <QSpinBox>
#include <QPainter>
#include <QMouseEvent>

CQColorWheel::
CQColorWheel(QWidget *parent, Qt::Orientation orient, int size, bool show_swatches) :
 QWidget(parent)
{
  setObjectName("wheel");

  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  QBoxLayout *layout;

  if (orient == Qt::Vertical)
    layout = new QVBoxLayout(this);
  else
    layout = new QHBoxLayout(this);

  layout->setMargin(0); layout->setSpacing(0);

  QFrame *wheelCanvas = new QFrame;
  wheelCanvas->setObjectName("frame");

  int margin = 4;

  int ws = size/10;
  int ss = size/6;

  int w = size + 3*margin + ws;
  int h = size + 2*margin;

  if (show_swatches) {
    if (orient == Qt::Vertical)
      h += margin + ss;
    else
      w += margin + ss;
  }

  wheelCanvas->setMinimumSize(QSize(w, h));
  wheelCanvas->setMaximumSize(QSize(w, h));

  QVBoxLayout *wheelCanvasLayout = new QVBoxLayout(wheelCanvas);

  wheelCanvasLayout->setMargin(0); wheelCanvasLayout->setSpacing(0);

  layout->addWidget(wheelCanvas);

  QGroupBox *optionsGroup = new QGroupBox;
  optionsGroup->setObjectName("group");

  optionsGroup->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  layout->addWidget(optionsGroup);

  QVBoxLayout *optionsGroupLayout = new QVBoxLayout(optionsGroup);

  optionsGroupLayout->setMargin(0); optionsGroupLayout->setSpacing(0);

  QTabWidget *tabWidget = new QTabWidget;
  tabWidget->setObjectName("tab");

  optionsGroup->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  optionsGroupLayout->addWidget(tabWidget);

  QWidget *rgbTab = new QWidget; rgbTab->setObjectName("rgb");
  QWidget *hsvTab = new QWidget; hsvTab->setObjectName("hsv");
  QWidget *optTab = new QWidget; optTab->setObjectName("opt");

  rgbTab->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  hsvTab->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  optTab->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  tabWidget->addTab(rgbTab, "RGB");
  tabWidget->addTab(hsvTab, "HSV");
  tabWidget->addTab(optTab, "Options");

  QGridLayout *rgbLayout = new QGridLayout(rgbTab);

  rgbLayout->setMargin(2); rgbLayout->setSpacing(2);

  QLabel *redLabel   = new QLabel("R"); redLabel  ->setObjectName("label");
  QLabel *greenLabel = new QLabel("G"); greenLabel->setObjectName("label");
  QLabel *blueLabel  = new QLabel("B"); blueLabel ->setObjectName("label");

  redSlider   = new QSlider(Qt::Horizontal); redValue   = new QSpinBox();
  greenSlider = new QSlider(Qt::Horizontal); greenValue = new QSpinBox();
  blueSlider  = new QSlider(Qt::Horizontal); blueValue  = new QSpinBox();

  redSlider  ->setObjectName("slider"); redValue  ->setObjectName("spin");
  greenSlider->setObjectName("slider"); greenValue->setObjectName("spin");
  blueSlider ->setObjectName("slider"); blueValue ->setObjectName("spin");

  redSlider  ->setRange(0, 255); redValue  ->setRange(0, 255);
  greenSlider->setRange(0, 255); greenValue->setRange(0, 255);
  blueSlider ->setRange(0, 255); blueValue ->setRange(0, 255);

  rgbLayout->addWidget(redLabel   , 0, 0);
  rgbLayout->addWidget(redSlider  , 0, 1);
  rgbLayout->addWidget(redValue   , 0, 2);
  rgbLayout->addWidget(greenLabel , 1, 0);
  rgbLayout->addWidget(greenSlider, 1, 1);
  rgbLayout->addWidget(greenValue , 1, 2);
  rgbLayout->addWidget(blueLabel  , 2, 0);
  rgbLayout->addWidget(blueSlider , 2, 1);
  rgbLayout->addWidget(blueValue  , 2, 2);

  rgbLayout->setRowStretch(3, 1);

  QGridLayout *hsvLayout = new QGridLayout(hsvTab);

  hsvLayout->setMargin(2); hsvLayout->setSpacing(2);

  QLabel *hueLabel   = new QLabel("H");
  QLabel *satLabel   = new QLabel("S");
  QLabel *valueLabel = new QLabel("V");

  hueSlider   = new QSlider(Qt::Horizontal); hueValue   = new QSpinBox();
  satSlider   = new QSlider(Qt::Horizontal); satValue   = new QSpinBox();
  valueSlider = new QSlider(Qt::Horizontal); valueValue = new QSpinBox();

  hueSlider  ->setRange(0, 359); hueValue  ->setRange(0, 359);
  satSlider  ->setRange(0, 255); satValue  ->setRange(0, 255);
  valueSlider->setRange(0, 255); valueValue->setRange(0, 255);

  hueSlider  ->setObjectName("slider"); hueValue  ->setObjectName("spin");
  satSlider  ->setObjectName("slider"); satValue  ->setObjectName("spin");
  valueSlider->setObjectName("slider"); valueValue->setObjectName("spin");

  hsvLayout->addWidget(hueLabel   , 0, 0);
  hsvLayout->addWidget(hueSlider  , 0, 1);
  hsvLayout->addWidget(hueValue   , 0, 2);
  hsvLayout->addWidget(satLabel   , 1, 0);
  hsvLayout->addWidget(satSlider  , 1, 1);
  hsvLayout->addWidget(satValue   , 1, 2);
  hsvLayout->addWidget(valueLabel , 2, 0);
  hsvLayout->addWidget(valueSlider, 2, 1);
  hsvLayout->addWidget(valueValue , 2, 2);

  hsvLayout->setRowStretch(3, 1);

  QGridLayout *optLayout = new QGridLayout(optTab);

  optLayout->setMargin(2); optLayout->setSpacing(2);

  QLabel    *baseLabel = new QLabel("Base");
  QComboBox *baseCombo = new QComboBox;

  baseCombo->addItems(QStringList() << "Red" << "Green" << "Blue");

  optLayout->addWidget(baseLabel, 0, 0);
  optLayout->addWidget(baseCombo, 0, 1);

  optLayout->setRowStretch(1, 1);

  //----------

  COrientation orientation =
    (orient == Qt::Vertical ? CORIENTATION_VERTICAL : CORIENTATION_HORIZONTAL);

  canvas_ = new CQColorWheelCanvas(this, 0, orientation, show_swatches);

  wheelCanvasLayout->addWidget(canvas_);

  setFgRGB(CRGBA(0,0,0));
  setBgRGB(CRGBA(1,1,1));

  // RGB
  connect(redSlider  , SIGNAL(valueChanged(int)), this, SLOT(updateRGBFromSlider()));
  connect(greenSlider, SIGNAL(valueChanged(int)), this, SLOT(updateRGBFromSlider()));
  connect(blueSlider , SIGNAL(valueChanged(int)), this, SLOT(updateRGBFromSlider()));
  connect(redValue   , SIGNAL(valueChanged(int)), this, SLOT(updateRGBFromSpin()));
  connect(greenValue , SIGNAL(valueChanged(int)), this, SLOT(updateRGBFromSpin()));
  connect(blueValue  , SIGNAL(valueChanged(int)), this, SLOT(updateRGBFromSpin()));

  // HSV
  connect(hueSlider  , SIGNAL(valueChanged(int)), this, SLOT(updateHSVFromSlider()));
  connect(satSlider  , SIGNAL(valueChanged(int)), this, SLOT(updateHSVFromSlider()));
  connect(valueSlider, SIGNAL(valueChanged(int)), this, SLOT(updateHSVFromSlider()));
  connect(hueValue   , SIGNAL(valueChanged(int)), this, SLOT(updateHSVFromSpin()));
  connect(satValue   , SIGNAL(valueChanged(int)), this, SLOT(updateHSVFromSpin()));
  connect(valueValue , SIGNAL(valueChanged(int)), this, SLOT(updateHSVFromSpin()));

  // Base
  connect(baseCombo, SIGNAL(activated(const QString &)), this, SLOT(updateBase(const QString &)));
}

CQColorWheel::
~CQColorWheel()
{
  delete canvas_;
}

void
CQColorWheel::
updateRGBFromSlider()
{
  CRGBA rgb(redSlider->value()/255.0, greenSlider->value()/255.0, blueSlider->value()/255.0);

  setRGB(rgb);
}

void
CQColorWheel::
updateRGBFromSpin()
{
  CRGBA rgb(redValue->value()/255.0, greenValue->value()/255.0, blueValue->value()/255.0);

  setRGB(rgb);
}

void
CQColorWheel::
updateHSVFromSlider()
{
  CHSV hsv(hueSlider->value(), satSlider->value()/255.0, valueSlider->value()/255.0);

  setHSV(hsv);
}

void
CQColorWheel::
updateHSVFromSpin()
{
  CHSV hsv(hueValue->value(), satValue->value()/255.0, valueValue->value()/255.0);

  setHSV(hsv);
}

void
CQColorWheel::
updateBase(const QString &str)
{
  if      (str == "Red")
    canvas_->setControlType(CColorWheel::CONTROL_RED);
  else if (str == "Green")
    canvas_->setControlType(CColorWheel::CONTROL_GREEN);
  else if (str == "Blue")
    canvas_->setControlType(CColorWheel::CONTROL_BLUE);
  else if (str == "Hue")
    canvas_->setControlType(CColorWheel::CONTROL_HUE);
  else if (str == "Saturation")
    canvas_->setControlType(CColorWheel::CONTROL_SATURATION);
  else if (str == "Value")
    canvas_->setControlType(CColorWheel::CONTROL_VALUE);

  canvas_->update();
}

void
CQColorWheel::
setBgRGB(const CRGBA &rgb)
{
  canvas_->setBgRGB(rgb);

  updateRGB();
}

void
CQColorWheel::
setFgRGB(const CRGBA &rgb)
{
  canvas_->setFgRGB(rgb);

  updateRGB();
}

void
CQColorWheel::
setRGB(const CRGBA &rgb)
{
  canvas_->setRGB(rgb);

  updateRGB();
}

void
CQColorWheel::
updateRGB()
{
  static bool active;

  if (active) return;

  CRGBA rgb = getRGB();

  active = true;

  redSlider  ->setValue(int(rgb.getRed  ()*255));
  greenSlider->setValue(int(rgb.getGreen()*255));
  blueSlider ->setValue(int(rgb.getBlue ()*255));

  redValue  ->setValue(int(rgb.getRed  ()*255));
  greenValue->setValue(int(rgb.getGreen()*255));
  blueValue ->setValue(int(rgb.getBlue ()*255));

  CHSV hsv = canvas_->getHSV();

  setHSV(hsv);

  canvas_->update();

  active = false;

  if (canvas_->getMode() == CColorWheel::MODE_BACKGROUND)
    emit colorBgChanged();
  else
    emit colorFgChanged();
}

const CRGBA &
CQColorWheel::
getBgRGB() const
{
  return canvas_->getBgRGB();
}

const CRGBA &
CQColorWheel::
getFgRGB() const
{
  return canvas_->getFgRGB();
}

const CRGBA &
CQColorWheel::
getRGB() const
{
  return canvas_->getRGB();
}

void
CQColorWheel::
setHSV(const CHSV &hsv)
{
  static bool active;

  if (active) return;

  active = true;

  hueSlider  ->setValue(int(hsv.getHue       ()));
  satSlider  ->setValue(int(hsv.getSaturation()*255));
  valueSlider->setValue(int(hsv.getValue     ()*255));

  hueValue  ->setValue(int(hsv.getHue       ()));
  satValue  ->setValue(int(hsv.getSaturation()*255));
  valueValue->setValue(int(hsv.getValue     ()*255));

  canvas_->setHSV(hsv);

  CRGBA rgb = canvas_->getRGB();

  setRGB(rgb);

  canvas_->update();

  active = false;
}

const CHSV &
CQColorWheel::
getHSV() const
{
  return canvas_->getHSV();
}
