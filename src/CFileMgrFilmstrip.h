#ifndef CFILE_MGR_FILMSTRIP_H
#define CFILE_MGR_FILMSTRIP_H

#include <CFile.h>

class CFileMgr;
class CPixelRenderer;
class CFileMgrFile;

class CFileMgrFilmstrip {
 private:
  CFileMgr       *file_mgr_;
  CPixelRenderer *image_renderer_;
  CPixelRenderer *icons_renderer_;
  CISize2D        size_;

 public:
  CFileMgrFilmstrip(CFileMgr *file_mgr);

 ~CFileMgrFilmstrip();

  CFileMgr *getFileMgr() const { return file_mgr_; }

  void setRenderers(CPixelRenderer *image_renderer,
                    CPixelRenderer *icons_renderer);

  void setImageRenderer(CPixelRenderer *renderer);
  void setIconsRenderer(CPixelRenderer *renderer);

  CPixelRenderer *getImageRenderer() const { return image_renderer_; }
  CPixelRenderer *getIconsRenderer() const { return icons_renderer_; }

  int getWidth () const { return size_.width; }
  int getHeight() const { return size_.height; }

  void redraw();

  void draw();

  void drawImage();
  void drawIcons();

  void keyPress  (const CKeyEvent &event);
  void keyRelease(const CKeyEvent &event);

 private:
  void stepPosition(int *x);
};

#endif
