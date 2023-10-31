#ifndef CQRGBA_EDIT_H
#define CQRGBA_EDIT_H

#include <QHBoxLayout>
#include <CRGBA.h>
#include <CQRealEdit.h>

class CQRGBAEdit : public QWidget {
  Q_OBJECT

 public:
  CQRGBAEdit(const QString &name, QWidget *parent=nullptr);
  CQRGBAEdit(QWidget *parent=nullptr, const QString &name="");

  virtual ~CQRGBAEdit() { }

  void setValue(const CRGBA &rgba);

  const CRGBA &getValue() const;

 private slots:
  void editingFinishedI();

 signals:
  void editingFinished();

 private:
  void init();

  void rgbaToWidget();
  void widgetToRGBA();

 private:
  CRGBA        rgba_;
  CQRealEdit  *r_edit_;
  CQRealEdit  *g_edit_;
  CQRealEdit  *b_edit_;
  QHBoxLayout *layout_;
};

#endif
