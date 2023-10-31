#include <CQResizeImageDlg.h>
#include <CQRadioButtons.h>
#include <CQNameValue.h>

#include <QPushButton>
#include <QVBoxLayout>
#include <QCheckBox>

CQResizeImageDlg::
CQResizeImageDlg(QWidget *parent) :
 QDialog(parent)
{
  width_  = 100;
  height_ = 100;

  QVBoxLayout *vlayout = new QVBoxLayout(this);

  vlayout->setMargin(2); vlayout->setSpacing(2);

  buttons_ = new CQHRadioButtons(nullptr, "Scale", "Resize", 0);

  //-----

  aspect_ = new QCheckBox("Keep Aspect");

  //-----

  CQNameValuePWidget<int> *width  = CQCreateNameValuePWidget("Width" , &width_ );
  CQNameValuePWidget<int> *height = CQCreateNameValuePWidget("Height", &height_);

  //-----

  QHBoxLayout *hlayout = new QHBoxLayout;

  QPushButton *ok     = new QPushButton("Ok");
  QPushButton *cancel = new QPushButton("Cancel");

  connect(ok    , SIGNAL(clicked()), this, SLOT(accept()));
  connect(cancel, SIGNAL(clicked()), this, SLOT(reject()));

  hlayout->addStretch();
  hlayout->addWidget(ok);
  hlayout->addWidget(cancel);

  vlayout->addWidget(buttons_);
  vlayout->addWidget(aspect_);
  vlayout->addWidget(width->getWidget());
  vlayout->addWidget(height->getWidget());
  vlayout->addLayout(hlayout);
}

void
CQResizeImageDlg::
accept()
{
  bool scale  = (buttons_->getCurrentName() == "Scale");
  bool aspect = aspect_->isChecked();

  emit resize(width_, height_, scale, aspect);

  reject();
}
