#ifndef CQCOLOR_WHEEL_H
#define CQCOLOR_WHEEL_H

#include <QWidget>

#include <CRGBA.h>
#include <CHSV.h>
#include <CIPoint2D.h>

class CQColorWheelCanvas;
class CQColorWheelArea;
class QSlider;
class QSpinBox;

class CQColorWheel : public QWidget {
  Q_OBJECT

 public:
  CQColorWheel(QWidget *parent=0, Qt::Orientation orient=Qt::Vertical,
               int size=64, bool show_swatches=true);
 ~CQColorWheel();

  const CRGBA &getBgRGB() const;
  const CRGBA &getFgRGB() const;

  const CRGBA &getRGB() const;

  void setBgRGB(const CRGBA &rgb);
  void setFgRGB(const CRGBA &rgb);

  void setRGB(const CRGBA &rgb);

  void setHSV(const CHSV &hsv);

  const CHSV &getHSV() const;

 private:
  void updateRGB();

 private slots:
  void updateRGBFromSlider();
  void updateRGBFromSpin();

  void updateHSVFromSlider();
  void updateHSVFromSpin();

  void updateBase(const QString &str);

 signals:
  void colorBgChanged();
  void colorFgChanged();

 private:
  CQColorWheelCanvas *canvas_;
  CQColorWheelArea   *wheel_;
  QSlider            *redSlider;
  QSlider            *greenSlider;
  QSlider            *blueSlider;
  QSpinBox           *redValue;
  QSpinBox           *greenValue;
  QSpinBox           *blueValue;
  QSlider            *hueSlider;
  QSlider            *satSlider;
  QSlider            *valueSlider;
  QSpinBox           *hueValue;
  QSpinBox           *satValue;
  QSpinBox           *valueValue;
};

#endif
