#ifndef CCOLOR_WHEEL_H
#define CCOLOR_WHEEL_H

#include <CRGBA.h>
#include <CHSV.h>
#include <COrientation.h>
#include <CIPoint2D.h>
#include <CIBBox2D.h>

class CColorWheel {
 public:
  enum ControlType {
    CONTROL_RED,
    CONTROL_GREEN,
    CONTROL_BLUE,
    CONTROL_HUE,
    CONTROL_SATURATION,
    CONTROL_VALUE
  };

  enum ModeType {
    MODE_BACKGROUND,
    MODE_FOREGROUND
  };

 public:
  CColorWheel(int radius=0, COrientation orientation=CORIENTATION_VERTICAL,
              bool show_swatches=true);

  virtual ~CColorWheel();

  ModeType getMode() const { return mode_; }

  void setMode(ModeType mode) { mode_ = mode; }

  void draw(int w, int h);

  void select(const CIPoint2D &pos);

  const CRGBA &getBgRGB() const { return bg_rgb_; }
  const CRGBA &getFgRGB() const { return fg_rgb_; }

  void setBgRGB(const CRGBA &rgb) { bg_rgb_ = rgb; }
  void setFgRGB(const CRGBA &rgb) { fg_rgb_ = rgb; }

  const CRGBA &getRGB() const {
    if (getMode() == MODE_FOREGROUND)
      return fg_rgb_;
    else
      return bg_rgb_;
  }

  void setRGB(const CRGBA &rgb);

  const CHSV &getHSV() const {
    if (getMode() == MODE_FOREGROUND)
      return fg_hsv_;
    else
      return bg_hsv_;
  }

  void setHSV(const CHSV &hsv);

  void setControlType(ControlType type);

 private:
  bool posToRGB(const CIPoint2D &pos, CRGBA &rgb) const;
  bool rgbToPos(const CRGBA &rgb, CIPoint2D &wpos, CIPoint2D &spos) const;

  bool insideWheel(const CIPoint2D &pos) {
    return (pos.x >= xc_ - tradius_ && pos.x < xc_ + tradius_ &&
            pos.y >= yc_ - tradius_ && pos.y < yc_ + tradius_);
  }

  bool insideSlider(const CIPoint2D &pos) {
    return (pos.x >= xs_ && pos.x < xs_ + ws_ && pos.y >= yc_ - tradius_ && pos.y < yc_ + tradius_);
  }

  bool insideBackground(const CIPoint2D &pos) {
    if (show_swatches_)
      return (pos.x >= xs1_ && pos.x < xs1_ + ss_ && pos.y >= ys1_ && pos.y < ys1_ + ss_);
    else
      return false;
  }

  bool insideForeground(const CIPoint2D &pos) {
    if (show_swatches_)
      return (pos.x >= xs2_ && pos.x < xs2_ + ss_ && pos.y >= ys2_ && pos.y < ys2_ + ss_);
    else
      return false;
  }

  virtual void setForeground(const CRGBA &rgba) = 0;

  virtual void drawPoint(const CIPoint2D &p) = 0;

  virtual void drawLine(const CIPoint2D &p1, const CIPoint2D &p2) = 0;

  virtual void fillRectangle(const CIBBox2D &rect) = 0;

 private:
  COrientation orientation_;
  bool         show_swatches_;
  ControlType  control_type_;
  ModeType     mode_;
  int          radius_;
  int          tradius_;
  int          xc_, yc_; // color wheel center
  int          xs_, ws_; // scale x and width
  int          xs1_, ys1_; // swatch 1 (x,y)
  int          xs2_, ys2_; // swatch 2 (x,y)
  int          ss_; // swatch size
  CRGBA        bg_rgb_, fg_rgb_;
  CHSV         bg_hsv_, fg_hsv_;
};

#endif
