#include <CQColorWheelCanvas.h>
#include <CQColorWheel.h>
#include <CQUtil.h>
#include <QPainter>
#include <QMouseEvent>

CQColorWheelCanvas::
CQColorWheelCanvas(CQColorWheel *wheel, int radius, COrientation orientation, bool show_swatches) :
 QWidget(0), CColorWheel(radius, orientation, show_swatches), wheel_(wheel)
{
  setObjectName("canvas");

  setFocusPolicy(Qt::StrongFocus);
}

CQColorWheelCanvas::
~CQColorWheelCanvas()
{
}

void
CQColorWheelCanvas::
paintEvent(QPaintEvent *)
{
  QPainter painter(this);

  CRGBA rgba(0.93,0.93,0.93);

  painter.fillRect(rect(), QBrush(CQUtil::rgbaToColor(rgba)));

  painter_ = &painter;

  CColorWheel::draw(width(), height());
}

void
CQColorWheelCanvas::
mousePressEvent(QMouseEvent *e)
{
  CColorWheel::select(CQUtil::fromQPoint(e->pos()));

  wheel_->setRGB(getRGB());
}

void
CQColorWheelCanvas::
mouseMoveEvent(QMouseEvent *e)
{
  CColorWheel::select(CQUtil::fromQPoint(e->pos()));

  wheel_->setRGB(getRGB());
}

void
CQColorWheelCanvas::
mouseReleaseEvent(QMouseEvent *)
{
}

void
CQColorWheelCanvas::
setForeground(const CRGBA &fg)
{
  fg_ = fg;

  painter_->setPen(CQUtil::rgbaToColor(fg));
}

void
CQColorWheelCanvas::
drawPoint(const CIPoint2D &p)
{
  painter_->drawPoint(p.x, p.y);
}

void
CQColorWheelCanvas::
drawLine(const CIPoint2D &p1, const CIPoint2D &p2)
{
  painter_->drawLine(p1.x, p1.y, p2.x, p2.y);
}

void
CQColorWheelCanvas::
fillRectangle(const CIBBox2D &rect)
{
  QRect r(rect.getXMin(), rect.getYMin(), rect.getWidth(), rect.getHeight());

  painter_->fillRect(r, QBrush(CQUtil::rgbaToColor(fg_)));
}
