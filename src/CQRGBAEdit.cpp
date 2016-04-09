#include <CQRGBAEdit.h>
#include <CStrUtil.h>
#include <QDoubleValidator>

CQRGBAEdit::
CQRGBAEdit(QWidget *parent, const QString &name) :
 QWidget(parent)
{
  setObjectName(name);

  init();
}

CQRGBAEdit::
CQRGBAEdit(const QString &name, QWidget *parent) :
 QWidget(parent)
{
  setObjectName(name);

  init();
}

void
CQRGBAEdit::
init()
{
  r_edit_ = new CQRealEdit;
  g_edit_ = new CQRealEdit;
  b_edit_ = new CQRealEdit;

  connect(r_edit_, SIGNAL(editingFinished()),
          this, SLOT(editingFinishedI()));
  connect(g_edit_, SIGNAL(editingFinished()),
          this, SLOT(editingFinishedI()));
  connect(b_edit_, SIGNAL(editingFinished()),
          this, SLOT(editingFinishedI()));

  layout_ = new QHBoxLayout();

  layout_->addWidget(r_edit_);
  layout_->addWidget(g_edit_);
  layout_->addWidget(b_edit_);

  setLayout(layout_);

  layout_->setMargin(1);
  layout_->setSpacing(1);

  rgbaToWidget();
}

void
CQRGBAEdit::
setValue(const CRGBA &rgba)
{
  rgba_ = rgba;

  rgbaToWidget();
}

const CRGBA &
CQRGBAEdit::
getValue() const
{
  return rgba_;
}

void
CQRGBAEdit::
editingFinishedI()
{
  widgetToRGBA();

  emit editingFinished();
}

void
CQRGBAEdit::
rgbaToWidget()
{
  r_edit_->setValue(rgba_.getRed  ());
  g_edit_->setValue(rgba_.getGreen());
  b_edit_->setValue(rgba_.getBlue ());
}

void
CQRGBAEdit::
widgetToRGBA()
{
  rgba_.setRed  (r_edit_->getValue());
  rgba_.setGreen(g_edit_->getValue());
  rgba_.setBlue (b_edit_->getValue());
}
