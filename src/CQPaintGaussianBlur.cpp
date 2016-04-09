#include <CQPaintGaussianBlur.h>

#include "ui_CQPaintGaussianBlur.h"

#include <CStrUtil.h>

CQPaintGaussianBlur::
CQPaintGaussianBlur(QWidget *parent) :
 QDialog(parent)
{
  Ui::CQPaintGaussianBlurUi ui;

  ui.setupUi(this);

  xBlur_ = ui.xBlur;
  yBlur_ = ui.yBlur;
  xSize_ = ui.xSize;
  ySize_ = ui.ySize;
}

void
CQPaintGaussianBlur::
accept()
{
  double xBlur = CStrUtil::toReal   (xBlur_->text().toStdString());
  double yBlur = CStrUtil::toReal   (yBlur_->text().toStdString());
  int    xSize = CStrUtil::toInteger(xSize_->text().toStdString());
  int    ySize = CStrUtil::toInteger(ySize_->text().toStdString());

  emit gaussianBlur(xBlur, yBlur, xSize, ySize);

  hide();
}
