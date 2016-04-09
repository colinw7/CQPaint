#include <QDialog>

class CQHRadioButtons;
class QCheckBox;
class CQIntegerEdit;

class CQResizeImageDlg : public QDialog {
  Q_OBJECT

 public:
  CQResizeImageDlg(QWidget *parent=0);

 public slots:
  void accept();

 signals:
  void resize(int width, int height, bool scale, bool aspect);

 private:
  CQHRadioButtons *buttons_;
  QCheckBox       *aspect_;
  int              width_;
  int              height_;
};
