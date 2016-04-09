#ifndef CQColorWheelCanvas_H
#define CQColorWheelCanvas_H

#include <QWidget>
#include <CColorWheel.h>

class CQColorWheel;

class CQColorWheelCanvas : public QWidget, public CColorWheel {
  Q_OBJECT

 public:
  CQColorWheelCanvas(CQColorWheel *wheel, int radius=0,
                     COrientation orientation=CORIENTATION_VERTICAL,
                     bool show_swatches=true);

 ~CQColorWheelCanvas();

  void paintEvent(QPaintEvent *e);

  void mousePressEvent  (QMouseEvent *event);
  void mouseMoveEvent   (QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);

  void setForeground(const CRGBA &rgba);

  void drawPoint(const CIPoint2D &p);
  void drawLine(const CIPoint2D &p1, const CIPoint2D &p2);
  void fillRectangle(const CIBBox2D &rect);

 private:
  CQColorWheel *wheel_;
  QPainter     *painter_;
  CRGBA         fg_;
};

#endif
