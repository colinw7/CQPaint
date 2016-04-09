// TODO: allow control of scale to allow R,G,B,H,S,V
// Square for R,G,B : Circle H,S,V

#include <CColorWheel.h>
#include <CMathMacros.h>
#include <CMathGen.h>
#include <cmath>

CColorWheel::
CColorWheel(int radius, COrientation orientation, bool show_swatches) :
 orientation_  (orientation),
 show_swatches_(show_swatches),
 control_type_ (CONTROL_RED),
 mode_         (MODE_FOREGROUND),
 radius_       (radius),
 tradius_      (radius),
 xc_           (0),
 bg_rgb_       (0,0,0),
 fg_rgb_       (1,1,1),
 bg_hsv_       (0,0,0),
 fg_hsv_       (0,0,1)
{
}

CColorWheel::
~CColorWheel()
{
}

void
CColorWheel::
draw(int w, int h)
{
  int margin = 4;

  // calc coordinates

  ws_ = w/10;

  if (show_swatches_)
    ss_ = std::min(w, h)/6;
  else
    ss_ = 0;

  int wc = w - ws_ - 3*margin;
  int hc = h - 2*margin;

  if (show_swatches_) {
    if (orientation_ == CORIENTATION_VERTICAL)
      hc -= ss_ + margin;
    else
      wc -= ss_ + margin;
  }

  tradius_ = radius_;

  if (tradius_ == 0)
    tradius_ = std::min(wc/2, hc/2);

  // draw color wheel

  CRGBA rgb;

  xc_ = wc/2 + margin;
  yc_ = hc/2 + margin;

  CIPoint2D pos, spos;

  for (pos.y = yc_ - tradius_; pos.y < yc_ + tradius_; ++pos.y) {
    for (pos.x = xc_ - tradius_; pos.x < xc_ + tradius_; ++pos.x) {
      if (! posToRGB(pos, rgb))
        continue;

      setForeground(rgb);

      drawPoint(pos);
    }
  }

  // draw cross

  rgbToPos(getRGB(), pos, spos);

  setForeground(CRGBA(0,0,0));

  drawLine(CIPoint2D(pos.x - 2, pos.y), CIPoint2D(pos.x + 2, pos.y));
  drawLine(CIPoint2D(pos.x, pos.y - 2), CIPoint2D(pos.x, pos.y + 2));

  // draw value scale

  xs_ = xc_ + tradius_ + margin;

  for (int y = yc_ - tradius_, y1 = 0; y < yc_ + tradius_; ++y, ++y1) {
    double v = 1.0 - (0.5*y1)/tradius_;

    if      (control_type_ == CONTROL_RED)
      rgb = CRGBA(v, 0, 0);
    else if (control_type_ == CONTROL_GREEN)
      rgb = CRGBA(0, v, 0);
    else if (control_type_ == CONTROL_BLUE)
      rgb = CRGBA(0, 0, v);
    else if (control_type_ == CONTROL_HUE) {
      CHSV hsv = CHSV(360*v, 1, 1);

      rgb = hsv.toRGB();
    }
    else if (control_type_ == CONTROL_SATURATION)
      rgb = CRGBA(v, v, v);
    else if (control_type_ == CONTROL_VALUE)
      rgb = CRGBA(v, v, v);

    setForeground(rgb);

    drawLine(CIPoint2D(xs_, y), CIPoint2D(xs_ + ws_, y));
  }

  // draw current value on scale

  double v = 0.0;

  if      (control_type_ == CONTROL_RED)
    v  = getRGB().getRed();
  else if (control_type_ == CONTROL_GREEN)
    v  = getRGB().getGreen();
  else if (control_type_ == CONTROL_BLUE)
    v  = getRGB().getBlue();
  else if (control_type_ == CONTROL_HUE)
    v  = getHSV().getHue()/360.0;
  else if (control_type_ == CONTROL_SATURATION)
    v  = getHSV().getSaturation();
  else if (control_type_ == CONTROL_VALUE)
    v  = getHSV().getValue();

  int y = int(yc_ + (1 - 2*v)*tradius_);

  if (control_type_ == CONTROL_VALUE)
    setForeground(CRGBA(0,0,1));
  else
    setForeground(CRGBA(1,1,1));

  drawLine(CIPoint2D(xs_, y), CIPoint2D(xs_ + ws_, y));

  // draw swatches

  if (show_swatches_) {
    if (orientation_ == CORIENTATION_VERTICAL) {
      xs1_ = margin;
      ys1_ = h - ss_ - margin - 1;

      xs2_ = xs1_ + ss_ + margin;
      ys2_ = ys1_;
    }
    else {
      xs1_ = xs_ + ws_ + margin;
      ys1_ = yc_ - tradius_;

      xs2_ = xs1_;
      ys2_ = ys1_ + ss_ + margin;
    }

    setForeground(CRGBA(1,1,1));

    if (mode_ == MODE_BACKGROUND)
      fillRectangle(CIBBox2D(xs1_ - 2, ys1_ - 2, xs1_ + ss_ + 1, ys1_ + ss_ + 1));
    else
      fillRectangle(CIBBox2D(xs2_ - 2, ys2_ - 2, xs2_ + ss_ + 1, ys2_ + ss_ + 1));

    setForeground(CRGBA(0,0,0));

    if (mode_ == MODE_BACKGROUND)
      fillRectangle(CIBBox2D(xs1_ - 1, ys1_ - 1, xs1_ + ss_ + 0, ys1_ + ss_ + 0));
    else
      fillRectangle(CIBBox2D(xs2_ - 1, ys2_ - 1, xs2_ + ss_ + 0, ys2_ + ss_ + 0));

    setForeground(bg_rgb_);

    fillRectangle(CIBBox2D(xs1_, ys1_, xs1_ + ss_ - 1, ys1_ + ss_ - 1));

    setForeground(fg_rgb_);

    fillRectangle(CIBBox2D(xs2_, ys2_, xs2_ + ss_ - 1, ys2_ + ss_ - 1));
  }
  else {
    xs1_ = 0;
    ys1_ = 0;

    xs2_ = 0;
    ys2_ = 0;
  }
}

void
CColorWheel::
select(const CIPoint2D &pos)
{
  if      (insideWheel(pos) || insideSlider(pos)) {
    CRGBA rgb;

    if (mode_ == MODE_BACKGROUND)
      posToRGB(pos, rgb);
    else
      posToRGB(pos, rgb);

    setRGB(rgb);
  }
  else if (insideBackground(pos))
    mode_ = MODE_BACKGROUND;
  else if (insideForeground(pos))
    mode_ = MODE_FOREGROUND;
}

bool
CColorWheel::
posToRGB(const CIPoint2D &pos, CRGBA &rgb) const
{
  if      (control_type_ == CONTROL_RED) {
    rgb = getRGB();

    if      (pos.x >= xc_ - tradius_ && pos.x < xc_ + tradius_ &&
             pos.y >= yc_ - tradius_ && pos.y < yc_ + tradius_) {
      double g =       (0.5*(pos.x - (xc_ - tradius_)))/tradius_;
      double b = 1.0 - (0.5*(pos.y - (yc_ - tradius_)))/tradius_;

      rgb.setGreen(g);
      rgb.setBlue (b);
    }
    else if (pos.x >= xs_            && pos.x < xs_ + ws_ &&
             pos.y >= yc_ - tradius_ && pos.y < yc_ + tradius_) {
      double v = 1.0 - (0.5*(pos.y - (yc_ - tradius_)))/tradius_;

      rgb.setRed(v);
    }
  }
  else if (control_type_ == CONTROL_GREEN) {
    rgb = getRGB();

    if      (pos.x >= xc_ - tradius_ && pos.x < xc_ + tradius_ &&
             pos.y >= yc_ - tradius_ && pos.y < yc_ + tradius_) {
      double r =       (0.5*(pos.x - (xc_ - tradius_)))/tradius_;
      double b = 1.0 - (0.5*(pos.y - (yc_ - tradius_)))/tradius_;

      rgb.setRed (r);
      rgb.setBlue(b);
    }
    else if (pos.x >= xs_            && pos.x < xs_ + ws_ &&
             pos.y >= yc_ - tradius_ && pos.y < yc_ + tradius_) {
      double v = 1.0 - (0.5*(pos.y - (yc_ - tradius_)))/tradius_;

      rgb.setGreen(v);
    }
  }
  else if (control_type_ == CONTROL_BLUE) {
    rgb = getRGB();

    if      (pos.x >= xc_ - tradius_ && pos.x < xc_ + tradius_ &&
             pos.y >= yc_ - tradius_ && pos.y < yc_ + tradius_) {
      double r =       (0.5*(pos.x - (xc_ - tradius_)))/tradius_;
      double g = 1.0 - (0.5*(pos.y - (yc_ - tradius_)))/tradius_;

      rgb.setRed  (r);
      rgb.setGreen(g);
    }
    else if (pos.x >= xs_            && pos.x < xs_ + ws_ &&
             pos.y >= yc_ - tradius_ && pos.y < yc_ + tradius_) {
      double v = 1.0 - (0.5*(pos.y - (yc_ - tradius_)))/tradius_;

      rgb.setBlue(v);
    }
  }
  else if (control_type_ == CONTROL_HUE) {
    CHSV hsv = getHSV();

    if      (pos.x >= xc_ - tradius_ && pos.x < xc_ + tradius_ &&
             pos.y >= yc_ - tradius_ && pos.y < yc_ + tradius_) {
      double s =       (0.5*(pos.x - (xc_ - tradius_)))/tradius_;
      double v = 1.0 - (0.5*(pos.y - (yc_ - tradius_)))/tradius_;

      hsv.setSaturation(s);
      hsv.setValue     (v);
    }
    else if (pos.x >= xs_            && pos.x < xs_ + ws_ &&
             pos.y >= yc_ - tradius_ && pos.y < yc_ + tradius_) {
      double v = 1.0 - (0.5*(pos.y - (yc_ - tradius_)))/tradius_;

      hsv.setHue(360*v);
    }

    rgb = hsv.toRGB();
  }
  else if (control_type_ == CONTROL_SATURATION) {
    CHSV hsv = getHSV();

    if      (pos.x >= xc_ - tradius_ && pos.x < xc_ + tradius_ &&
             pos.y >= yc_ - tradius_ && pos.y < yc_ + tradius_) {
      double h =       (0.5*(pos.x - (xc_ - tradius_)))/tradius_;
      double v = 1.0 - (0.5*(pos.y - (yc_ - tradius_)))/tradius_;

      hsv.setHue  (360*h);
      hsv.setValue(v);
    }
    else if (pos.x >= xs_            && pos.x < xs_ + ws_ &&
             pos.y >= yc_ - tradius_ && pos.y < yc_ + tradius_) {
      double v = 1.0 - (0.5*(pos.y - (yc_ - tradius_)))/tradius_;

      hsv.setSaturation(v);
    }

    rgb = hsv.toRGB();
  }
  else if (control_type_ == CONTROL_VALUE) {
    CHSV hsv = getHSV();

    if      (pos.x >= xc_ - tradius_ && pos.x < xc_ + tradius_ &&
             pos.y >= yc_ - tradius_ && pos.y < yc_ + tradius_) {
      rgb = CRGBA(0, 0, 0);

      double x1 = pos.x - xc_;
      double y1 = yc_ - pos.y;

      double hypot = sqrt(x1*x1 + y1*y1);

      if (hypot > tradius_)
        return false;

      double a = RAD_TO_DEG(CMathGen::atan2(x1, y1));

      a -= 90.0;

      if (a < 0)
        a += 360;

      hsv.setHue(a);

      hsv.setSaturation(hypot/tradius_);
    }
    else if (pos.x >= xs_            && pos.x < xs_ + ws_ &&
             pos.y >= yc_ - tradius_ && pos.y < yc_ + tradius_) {
      double v = 1.0 - (0.5*(pos.y - (yc_ - tradius_)))/tradius_;

      hsv.setValue(v);
    }

    rgb = hsv.toRGB();
  }

  return true;
}

bool
CColorWheel::
rgbToPos(const CRGBA &rgb, CIPoint2D &wpos, CIPoint2D &spos) const
{
  spos.x = xs_;

  double r = rgb.getRed  ();
  double g = rgb.getGreen();
  double b = rgb.getBlue ();

  CHSV hsv = rgb.toHSV();

  double h = hsv.getHue()/360.0;
  double s = hsv.getSaturation();
  double v = hsv.getValue();

  if      (control_type_ == CONTROL_RED) {
    wpos.x = int(xc_ + (2*g - 1)*tradius_);
    wpos.y = int(yc_ + (1 - 2*b)*tradius_);

    spos.y = int(yc_ + (1 - 2*r)*tradius_);
  }
  else if (control_type_ == CONTROL_GREEN) {
    wpos.x = int(xc_ + (2*r - 1)*tradius_);
    wpos.y = int(yc_ + (1 - 2*b)*tradius_);

    spos.y = int(yc_ + (1 - 2*g)*tradius_);
  }
  else if (control_type_ == CONTROL_BLUE) {
    wpos.x = int(xc_ + (2*r - 1)*tradius_);
    wpos.y = int(yc_ + (1 - 2*g)*tradius_);

    spos.y = int(yc_ + (1 - 2*b)*tradius_);
  }
  else if (control_type_ == CONTROL_HUE) {
    wpos.x = int(xc_ + (2*s - 1)*tradius_);
    wpos.y = int(yc_ + (1 - 2*v)*tradius_);

    spos.y = int(yc_ + (1 - 2*h)*tradius_);
  }
  else if (control_type_ == CONTROL_SATURATION) {
    wpos.x = int(xc_ + (2*h - 1)*tradius_);
    wpos.y = int(yc_ + (1 - 2*v)*tradius_);

    spos.y = int(yc_ + (1 - 2*s)*tradius_);
  }
  else if (control_type_ == CONTROL_VALUE) {
    double h = hsv.getHue() + 90;

    if (h > 360)
      h -= 360;

    double r = tradius_*s;
    double a = DEG_TO_RAD(h);

    wpos.x = int(xc_ + r*cos(a));
    wpos.y = int(yc_ - r*sin(a));

    spos.y = int(yc_ + (1 - 2*v)*tradius_);
  }

  return true;
}

void
CColorWheel::
setRGB(const CRGBA &rgb)
{
  if (mode_ == MODE_FOREGROUND) {
    fg_rgb_ = rgb;
    fg_hsv_ = fg_rgb_.toHSV();
  }
  else {
    bg_rgb_ = rgb;
    bg_hsv_ = bg_rgb_.toHSV();
  }
}

void
CColorWheel::
setHSV(const CHSV &hsv)
{
  if (mode_ == MODE_FOREGROUND) {
    fg_hsv_ = hsv;
    fg_rgb_ = fg_hsv_.toRGB();
  }
  else {
    bg_hsv_ = hsv;
    bg_rgb_ = bg_hsv_.toRGB();
  }
}

void
CColorWheel::
setControlType(ControlType type)
{
  control_type_ = type;
}
