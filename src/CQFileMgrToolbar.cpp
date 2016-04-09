#include <CQFileMgrToolbar.h>

#include <CConfig.h>
#include <CDir.h>
#include <CStrUtil.h>
#include <CQFileMgr.h>
#include <CQImageButton.h>

#include <QLineEdit>
#include <QMouseEvent>
#include <QMenu>
#include <QHBoxLayout>

#include <svg/back_svg.h>
#include <svg/details_svg.h>
#include <svg/forward_svg.h>
#include <svg/hidden_svg.h>
#include <svg/icons_svg.h>
#include <svg/image_svg.h>
#include <svg/refresh_svg.h>
#include <svg/strip_svg.h>
#include <svg/favorites_svg.h>
//#include <svg/up_svg.h>

CQFileMgrToolbar::
CQFileMgrToolbar(CQFileMgr *mgr) :
 QWidget(0), mgr_(mgr)
{
  setObjectName("fileMgrToolbar");

  init();
}

CQFileMgrToolbar::
~CQFileMgrToolbar()
{
}

void
CQFileMgrToolbar::
init()
{
  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->setMargin(0); layout->setSpacing(2);

  CQImageButton *back_button = new CQImageButton(CQPixmapCacheInst->getIcon("BACK"));
  back_button->setToolTip("Previous Dir");
  connect(back_button, SIGNAL(clicked()), mgr_, SLOT(undoDir()));

  CQImageButton *forward_button = new CQImageButton(CQPixmapCacheInst->getIcon("FORWARD"));
  forward_button->setToolTip("Next Dir");
  connect(forward_button, SIGNAL(clicked()), mgr_, SLOT(redoDir()));

  //CQImageButton *up_button = new CQImageButton(QPixmap((const char **) up_data));
  //connect(up_button, SIGNAL(clicked()), mgr_, SLOT(parentDir()));

  CQImageButton *icons_button   = new CQImageButton(CQPixmapCacheInst->getIcon("ICONS"));
  icons_button->setToolTip("Icons View");
  connect(icons_button, SIGNAL(clicked()), mgr_, SLOT(iconsView()));

  CQImageButton *details_button = new CQImageButton(CQPixmapCacheInst->getIcon("DETAILS"));
  details_button->setToolTip("Details View");
  connect(details_button, SIGNAL(clicked()), mgr_, SLOT(detailsView()));

  CQImageButton *strip_button   = new CQImageButton(CQPixmapCacheInst->getIcon("STRIP"));
  strip_button->setToolTip("Strip View");
  connect(strip_button, SIGNAL(clicked()), mgr_, SLOT(filmstripView()));

  CQImageButton *image_button  = new CQImageButton(CQPixmapCacheInst->getIcon("IMAGE"));
  image_button->setToolTip("Show Images");
  connect(image_button, SIGNAL(clicked()), mgr_, SLOT(toggleImages()));

  CQImageButton *hidden_button = new CQImageButton(CQPixmapCacheInst->getIcon("HIDDEN"));
  hidden_button->setToolTip("Show Hidden");
  connect(hidden_button, SIGNAL(clicked()), mgr_, SLOT(toggleHidden()));

  CQImageButton *refresh_button = new CQImageButton(CQPixmapCacheInst->getIcon("REFRESH"));
  refresh_button->setToolTip("Refresh View");
  connect(refresh_button, SIGNAL(clicked()), mgr_, SLOT(refresh()));

  add_button_ = new CQImageButton(CQPixmapCacheInst->getIcon("FAVORITES"));
  add_button_->setToolTip("Add to Favorties");
  connect(add_button_, SIGNAL(clicked()), mgr_, SLOT(addToPlaces()));

  layout->addWidget(back_button);
  layout->addWidget(forward_button);

  layout->addSpacing(8);

  //layout->addWidget(up_button);

  //layout->addSpacing(8);

  layout->addWidget(icons_button);
  layout->addWidget(details_button);
  layout->addWidget(strip_button);

  layout->addSpacing(8);

  layout->addWidget(image_button);
  layout->addWidget(hidden_button);

  layout->addSpacing(8);

  layout->addWidget(refresh_button);

  layout->addSpacing(8);

  layout->addWidget(add_button_);

  layout->addStretch();

  setFixedHeight(34);
}

void
CQFileMgrToolbar::
showIcon(IconType type, bool show)
{
  if (type == ADD_PLACE_BUTTON)
    add_button_->setVisible(show);
}
