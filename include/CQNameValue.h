#ifndef CQNAME_VALUE_H
#define CQNAME_VALUE_H

#include <QObject>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QHBoxLayout>

extern "C" {
#include <stdarg.h>
}

#include <string>

#include <CQPoint3DEdit.h>
#include <CQPoint2DEdit.h>
#include <CQRGBAEdit.h>
#include <CQRealEdit.h>
#include <CQIntegerEdit.h>

//---------------------------

class CQNameValueChoice {
 public:
  typedef std::vector<std::string> NameList;
  typedef std::vector<int>         ValueList;

 private:
  NameList  names_;
  ValueList values_;
  uint      ind_;

 public:
  CQNameValueChoice() :
   ind_(0) {
  }

  CQNameValueChoice &operator=(const std::string &name) {
    setName(name);

    return *this;
  }

  void setNames(const char *name, ...) {
    va_list vargs;

    va_start(vargs, name);

    names_ .clear();
    values_.clear();

    int value = 0;

    while (name != NULL) {
      names_ .push_back(name);
      values_.push_back(value);

      name = va_arg(vargs, char *);

      ++value;
    }

    va_end(vargs);
  }

  void setValues(int value, ...) {
    va_list vargs;

    va_start(vargs, value);

    auto num_names = names_.size();

    for (uint i = 0; i < num_names; ++i) {
      values_[i] = value;

      value = va_arg(vargs, int);
    }

    va_end(vargs);
  }

  const NameList &getNames() const {
    return names_;
  }

  uint getInd() const {
    return ind_;
  }

  std::string getName() const {
    if (ind_ > 0 && ind_ < names_.size())
      return names_[ind_];
    else
      return "";
  }

  int getValue() const {
    if (ind_ > 0 && ind_ < values_.size())
      return values_[ind_];
    else
      return 0;
  }

  void setName(const std::string &name) {
    auto num_names = names_.size();

    for (uint i = 0; i < num_names; ++i) {
      if (names_[i] == name) {
        ind_ = i;
        return;
      }
    }
  }
};

//---------------------------

template<typename T>
class CQNameValueEditor {
 public:
  virtual ~CQNameValueEditor() { }

  virtual T getValue() const = 0;

  virtual void updateWidget(const T &value);

  virtual QWidget *getWidget() const = 0;
};

// Integer Value Editor
template<>
class CQNameValueEditor <int> {
 private:
  CQIntegerEdit *widget_;

 public:
  CQNameValueEditor(QObject *parent, int *value) {
    widget_ = new CQIntegerEdit;

    updateWidget(*value);

    QObject::connect(widget_, SIGNAL(valueChanged()),
                     parent, SLOT(valueEditingFinished()));
  }

  int getValue() const {
    int value = widget_->getValue();

    return value;
  }

  void updateWidget(const int &value) {
    widget_->setValue(value);
  }

  QWidget *getWidget() const { return widget_; }
};

// Real Value Editor
template<>
class CQNameValueEditor <double> {
 private:
  CQRealEdit *widget_;

 public:
  CQNameValueEditor(QObject *parent, double *value) {
    widget_ = new CQRealEdit;

    updateWidget(*value);

    QObject::connect(widget_, SIGNAL(valueChanged(double)),
                     parent, SLOT(valueEditingFinished()));
  }

  double getValue() const {
    double value = widget_->getValue();

    return value;
  }

  void updateWidget(const double &value) {
    widget_->setValue(value);
  }

  QWidget *getWidget() const { return widget_; }
};

// String Value Editor
template<>
class CQNameValueEditor <std::string> {
 private:
  QLineEdit *widget_;

 public:
  CQNameValueEditor(QObject *parent, std::string *value) {
    widget_ = new QLineEdit("edit");

    updateWidget(*value);

    QObject::connect(widget_, SIGNAL(editingFinished()),
                     parent, SLOT(valueEditingFinished()));
  }

  std::string getValue() const {
    QString text = widget_->text();

    return text.toStdString();
  }

  void updateWidget(const std::string &value) {
    widget_->setText(QString(value.c_str()));
  }

  QWidget *getWidget() const { return widget_; }
};

// Choice Value Editor
template<>
class CQNameValueEditor <CQNameValueChoice> {
 private:
  QComboBox *widget_;

 public:
  CQNameValueEditor(QObject *parent, CQNameValueChoice *value) {
    widget_ = new QComboBox();

    widget_->setObjectName("edit");

    CQNameValueChoice::NameList names = value->getNames();

    for (uint i = 0; i < names.size(); ++i)
      widget_->addItem(QString(names[i].c_str()));

    updateWidget(*value);

    QObject::connect(widget_, SIGNAL(currentIndexChanged(int)),
                     parent, SLOT(valueEditingFinished()));
  }

  std::string getValue() const {
    QString text = widget_->currentText();

    return text.toStdString();
  }

  void updateWidget(const CQNameValueChoice &value) {
    widget_->setCurrentIndex(int(value.getInd()));
  }

  QWidget *getWidget() const { return widget_; }
};

// Point (3D) Value Editor
template<>
class CQNameValueEditor <CPoint3D> {
 private:
  CQPoint3DEdit *widget_;

 public:
  CQNameValueEditor(QObject *parent, CPoint3D *value) {
    widget_ = new CQPoint3DEdit("edit", *value);

    updateWidget(*value);

    QObject::connect(widget_, SIGNAL(editingFinished()),
                     parent, SLOT(valueEditingFinished()));
  }

  const CPoint3D &getValue() const {
    const CPoint3D &point = widget_->getValue();

    return point;
  }

  void updateWidget(const CPoint3D &value) {
    widget_->setValue(value);
  }

  QWidget *getWidget() const { return widget_; }
};

// Point (2D) Value Editor
template<>
class CQNameValueEditor <CPoint2D> {
 private:
  CQPoint2DEdit *widget_;

 public:
  CQNameValueEditor(QObject *parent, CPoint2D *value) {
    widget_ = new CQPoint2DEdit(*value);
    widget_->setObjectName("edit");

    updateWidget(*value);

    QObject::connect(widget_, SIGNAL(valueChanged()),
                     parent, SLOT(valueEditingFinished()));
  }

  const CPoint2D &getValue() const {
    const CPoint2D &point = widget_->getValue();

    return point;
  }

  void updateWidget(const CPoint2D &value) {
    widget_->setValue(value);
  }

  QWidget *getWidget() const { return widget_; }
};

// CRGBA Value Editor
template<>
class CQNameValueEditor <CRGBA> {
 private:
  CQRGBAEdit *widget_;

 public:
  CQNameValueEditor(QObject *parent, CRGBA *value) {
    widget_ = new CQRGBAEdit("edit");

    updateWidget(*value);

    QObject::connect(widget_, SIGNAL(editingFinished()),
                     parent, SLOT(valueEditingFinished()));
  }

  const CRGBA &getValue() const {
    const CRGBA &rgba = widget_->getValue();

    return rgba;
  }

  void updateWidget(const CRGBA &value) {
    widget_->setValue(value);
  }

  QWidget *getWidget() const { return widget_; }
};

//------------------

class CQNameValue;

class CQNameValueDataIFace {
 private:
  CQNameValue *widget_;

 public:
  CQNameValueDataIFace() : widget_(NULL) { }

  virtual ~CQNameValueDataIFace() { }

  virtual CQNameValueDataIFace *dup() const = 0;

  virtual QWidget *createEditor(QObject *parent) = 0;

  virtual void updateValue() = 0;

  void  setWidget(CQNameValue *widget) {
    widget_ = widget;
  }

  CQNameValue *getWidget() const { return widget_; }
};

template<typename T>
class CQNameValueData : public CQNameValueDataIFace {
 private:
  T                    *value_;
  CQNameValueEditor<T> *editor_;

 public:
  CQNameValueData(T *value) :
   value_(value), editor_(0) {
  }

  virtual ~CQNameValueData() { }

  CQNameValueDataIFace *dup() const {
    return new CQNameValueData<T>(value_);
  }

  QWidget *createEditor(QObject *parent) {
    editor_ = new CQNameValueEditor<T>(parent, value_);

    return editor_->getWidget();
  }

  void setValue(const T &value) {
    *value_ = value;

    if (editor_)
      editor_->updateWidget(*value_);
  }

  const T &getValue() const {
    return *value_;
  }

  void updateValue() {
    if (editor_)
      *value_ = editor_->getValue();
  }
};

class CQNameValue : public QWidget {
  Q_OBJECT

 private:
  QLabel               *label_;
  QWidget              *editor_;
  CQNameValueDataIFace *data_;

 public:
  CQNameValue(const QString &name, const CQNameValueDataIFace &data) :
   data_(data.dup()) {
    label_  = new QLabel(name);
    editor_ = data_->createEditor(this);

    QHBoxLayout *layout = new QHBoxLayout(this);

    layout->setMargin(2); layout->setSpacing(2);

    layout->addWidget(label_);
    layout->addWidget(editor_);

    layout->addStretch(1);

    data_->setWidget(this);
  }

  virtual ~CQNameValue() { }

  CQNameValueDataIFace *getData() const { return data_; }

 public slots:
  void valueEditingFinished() {
    data_->updateValue();

    emit valueChanged();
  }

 signals:
  void valueChanged();
};

template<typename T>
class CQNameValueWidget {
 private:
  T                   value_;
  CQNameValue        *widget_;
  CQNameValueData<T> *data_;

 public:
  CQNameValueWidget(const char *name, const T &value) :
   value_(value) {
    CQNameValueData<T> data(&value_);

    widget_ = new CQNameValue(name, data);

    data_ = dynamic_cast< CQNameValueData<T> *>(widget_->getData());
  }

  CQNameValue *getWidget() const { return widget_; }

  void setValue(const T &value) {
    data_->setValue(value);
  }

  const T &getValue() const {
    return data_->getValue();
  }
};

template<typename T>
CQNameValueWidget<T> *
CQCreateNameValueWidget(const char *name, const T &value)
{
  return new CQNameValueWidget<T>(name, value);
}

template<typename T>
class CQNameValuePWidget {
 private:
  CQNameValue        *widget_;
  CQNameValueData<T> *data_;

 public:
  CQNameValuePWidget(const char *name, T *value) {
    CQNameValueData<T> data(value);

    widget_ = new CQNameValue(name, data);

    data_ = dynamic_cast< CQNameValueData<T> *>(widget_->getData());
  }

  CQNameValue *getWidget() const { return widget_; }

  void setValue(const T &value) {
    data_->setValue(value);
  }

  const T &getValue() const {
    return data_->getValue();
  }
};

template<typename T>
CQNameValuePWidget<T> *
CQCreateNameValuePWidget(const char *name, T *value)
{
  return new CQNameValuePWidget<T>(name, value);
}

#endif
