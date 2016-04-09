#include <CQPoint3DEdit.h>
#include <CStrUtil.h>
#include <QDoubleValidator>

CQPoint3DEdit::
CQPoint3DEdit(const QString &name, const CPoint3D &value)
{
  QValidator *validator = new QDoubleValidator(this);

  setObjectName(name);

  x_edit_ = new QLineEdit("x");
  y_edit_ = new QLineEdit("y");
  z_edit_ = new QLineEdit("z");

  x_edit_->setMinimumSize(QSize(60,0));
  x_edit_->setMaximumSize(QSize(60,22));
  y_edit_->setMinimumSize(QSize(60,0));
  y_edit_->setMaximumSize(QSize(60,22));
  z_edit_->setMinimumSize(QSize(60,0));
  z_edit_->setMaximumSize(QSize(60,22));

  x_edit_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  y_edit_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  z_edit_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

  x_edit_->setValidator(validator);
  y_edit_->setValidator(validator);
  z_edit_->setValidator(validator);

  connect(x_edit_, SIGNAL(editingFinished()),
          this, SLOT(editingFinishedI()));
  connect(y_edit_, SIGNAL(editingFinished()),
          this, SLOT(editingFinishedI()));
  connect(z_edit_, SIGNAL(editingFinished()),
          this, SLOT(editingFinishedI()));

  layout_ = new QHBoxLayout(this);

  layout_->setMargin(2); layout_->setSpacing(2);

  layout_->addWidget(x_edit_);
  layout_->addWidget(y_edit_);
  layout_->addWidget(z_edit_);

  setValue(value);
}

void
CQPoint3DEdit::
setValue(const CPoint3D &point)
{
  point_ = point;

  pointToWidget();
}

const CPoint3D &
CQPoint3DEdit::
getValue() const
{
  return point_;
}

void
CQPoint3DEdit::
editingFinishedI()
{
  widgetToPoint();

  emit editingFinished();
}

void
CQPoint3DEdit::
pointToWidget()
{
  x_edit_->setText(CStrUtil::toString(point_.getX()).c_str());
  y_edit_->setText(CStrUtil::toString(point_.getY()).c_str());
  z_edit_->setText(CStrUtil::toString(point_.getZ()).c_str());
}

void
CQPoint3DEdit::
widgetToPoint()
{
  point_.setX(CStrUtil::toReal(x_edit_->text().toStdString()));
  point_.setY(CStrUtil::toReal(y_edit_->text().toStdString()));
  point_.setZ(CStrUtil::toReal(z_edit_->text().toStdString()));
}
