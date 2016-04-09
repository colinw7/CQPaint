#include <QDialog>
#include <QCheckBox>
#include <QLineEdit>

#define CQPaintTurbulenceInst(p) CQPaintTurbulence::getInstance(p)

class CQPaintTurbulence : public QDialog {
  Q_OBJECT

 private:
  QCheckBox *fractal_;
  QLineEdit *frequency_;
  QLineEdit *octaves_;
  QLineEdit *seed_;

 public:
  static CQPaintTurbulence *getInstance(QWidget *parent) {
    static CQPaintTurbulence *instance;

    if (! instance)
      instance = new CQPaintTurbulence(parent);

    return instance;
  }

  void accept();

 protected:
  CQPaintTurbulence(QWidget *parent);

 signals:
  void turbulence(bool fractal, double freq, int octaves, int seed);
};
