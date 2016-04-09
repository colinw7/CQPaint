#ifndef CQFILEMGR_TOOLBAR_H
#define CQFILEMGR_TOOLBAR_H

#include <QWidget>

class CQFileMgr;
class CQImageButton;

class CQFileMgrToolbar : public QWidget {
  Q_OBJECT

 public:
  enum IconType {
    ADD_PLACE_BUTTON
  };

 private:
  CQFileMgr     *mgr_;
  CQImageButton *add_button_;

 public:
  CQFileMgrToolbar(CQFileMgr *mgr);
 ~CQFileMgrToolbar();

  void showIcon(IconType type, bool show);

 private:
  void init();
};

#endif
