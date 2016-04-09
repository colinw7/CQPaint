#ifndef CQPOINT3D_EDIT_H
#define CQPOINT3D_EDIT_H

#include <QLineEdit>
#include <QHBoxLayout>
#include <CPoint3D.h>

class CQPoint3DEdit : public QWidget {
  Q_OBJECT

 private:
  CPoint3D     point_;
  QLineEdit   *x_edit_;
  QLineEdit   *y_edit_;
  QLineEdit   *z_edit_;
  QHBoxLayout *layout_;

 public:
  CQPoint3DEdit(const QString &name, const CPoint3D &value);

  virtual ~CQPoint3DEdit() { }

  void setValue(const CPoint3D &point);

  const CPoint3D &getValue() const;

 private slots:
  void editingFinishedI();

 signals:
  void editingFinished();

 private:
  void pointToWidget();
  void widgetToPoint();
};

#endif
