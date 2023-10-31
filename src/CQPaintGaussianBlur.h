#include <QDialog>
#include <QLineEdit>

#define CQPaintGaussianBlurInst(p) CQPaintGaussianBlur::getInstance(p)

class CQPaintGaussianBlur : public QDialog {
  Q_OBJECT

 private:
  QLineEdit *xBlur_;
  QLineEdit *yBlur_;
  QLineEdit *xSize_;
  QLineEdit *ySize_;

 public:
  static CQPaintGaussianBlur *getInstance(QWidget *parent) {
    static CQPaintGaussianBlur *instance;

    if (! instance)
      instance = new CQPaintGaussianBlur(parent);

    return instance;
  }

  void accept() override;

 protected:
  CQPaintGaussianBlur(QWidget *parent);

 signals:
  void gaussianBlur(double xBlur, double yBlur, int xSize, int ySize);
};
