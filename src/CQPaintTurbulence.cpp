#include <CQPaintTurbulence.h>

#include "ui_CQPaintTurbulence.h"

#include <CStrUtil.h>

CQPaintTurbulence::
CQPaintTurbulence(QWidget *parent) :
 QDialog(parent)
{
  Ui::CQPaintTurbulenceUi ui;

  ui.setupUi(this);

  fractal_   = ui.fractal;
  frequency_ = ui.frequency;
  octaves_   = ui.octaves;
  seed_      = ui.seed;
}

void
CQPaintTurbulence::
accept()
{
  bool   fractal = (fractal_->checkState() == Qt::Checked);
  double freq    = CStrUtil::toReal   (frequency_->text().toStdString());
  int    octaves = CStrUtil::toInteger(octaves_  ->text().toStdString());
  int    seed    = CStrUtil::toInteger(seed_     ->text().toStdString());

  emit turbulence(fractal, freq, octaves, seed);

  hide();
}
