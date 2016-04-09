#ifndef CQFILEMGR_H
#define CQFILEMGR_H

#include <QWidget>

#include <CIPoint2D.h>
#include <CIBBox2D.h>
#include <CFileMgrLib.h>

class CQFileMgrIcons;
class CQFileMgrFilmstripImage;
class CQFileMgrFilmstripIcons;
class CQFileMgrDetails;
class CQFileMgrToolbar;
class CQFileMgrInfo;
class CQDirBar;
class CQDirPlaces;
class QTreeWidget;

class CQFileMgr : public QWidget {
  Q_OBJECT

 public:
  CQFileMgr(QWidget *parent=0);

  virtual ~CQFileMgr();

  CFileMgr *getFileMgr() const { return filemgr_; }

  CQFileMgrDetails *getDetailsTable() const { return details_table_; }

  const std::string &getDirName() const;

  void setDirName(const std::string &dirName);

  void showPlaces(bool show);

  void resize();
  void changed();
  void expose();

  void keyPress  (const CKeyEvent &event);
  void keyRelease(const CKeyEvent &event);

  void draw();

  void drawIcons();
  void drawFilmstripImage();
  void drawFilmstripIcons();
  void drawDetails();

  int getCanvasWidth() const;
  int getCanvasHeight() const;

  int getContentsWidth() const;
  int getContentsHeight() const;

  void setIconsView();
  void setFilmstripView();
  void setDetailsView();

  bool getShowImages();
  bool getShowHidden();

  void setShowImages(bool show_images=true);
  void setSmallIcons(bool small_icons=true);
  void setShowHidden(bool show_hidden=true);

  void deselectAll();

  void selectInside(const CIBBox2D &bbox);

  void activate(const CIPoint2D &position);

  void activate(CFileMgrFile *file);

  virtual void activateFile(const std::string &filename);
  virtual void activateDir(const std::string &dirname);

  bool activateFileTypeFwd(const std::string &filename, CFileType type);

  virtual void activateFileType(const std::string &filename, CFileType type);

  virtual void changeDir(const std::string &dirName);

  void updateScrollbars();

  void scrolled();

  virtual void setTableColumns(const CFileMgrDetails::ColumnList &columns);
  virtual void deleteAllTableRows();
  virtual void addTableRow(CFileMgrFile *file, const std::vector<std::string> &values);

  void popupMenu(QWidget *widget, int x, int y);

 public slots:
  void undoDir();
  void redoDir();

  void parentDir();
  void setDir(const QString &dirName);

  void iconsView();
  void filmstripView();
  void detailsView();

  void toggleImages();
  void toggleHidden();

  void addToPlaces();

  void showImages(bool flag);
  void smallIcons(bool flag);
  void showHidden(bool flag);

  void showInfo();

  void refresh();

 signals:
  void fileActivated(const QString &filename);
  void dirActivated(const QString &dirname);

  void dirChanged(const QString &dirName);

 protected:
  CFileMgr                *filemgr_;
  CQFileMgrToolbar        *toolbar_;
  CQDirBar                *dirbar_;
  QWidget                 *places_frame_;
  CQDirPlaces             *places_;
  QWidget                 *icons_frame_;
  CQFileMgrIcons          *icons_canvas_;
  QWidget                 *filmstrip_frame_;
  CQFileMgrFilmstripImage *filmstrip_image_canvas_;
  CQFileMgrFilmstripIcons *filmstrip_icons_canvas_;
  QWidget                 *details_frame_;
  CQFileMgrDetails        *details_table_;
  CQFileMgrInfo           *info_;
  bool                     activated_;
};

#endif
