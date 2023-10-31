/********************************************************************************
** Form generated from reading UI file 'CQPaintGaussianBlur.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CQPAINTGAUSSIANBLUR_H
#define UI_CQPAINTGAUSSIANBLUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CQPaintGaussianBlurUi
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *xBlurLabel;
    QLineEdit *xBlur;
    QLabel *yBlurLabel;
    QLineEdit *yBlur;
    QLabel *xSizeLabel;
    QLineEdit *xSize;
    QLabel *ySizeLabel;
    QLineEdit *ySize;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *CQPaintGaussianBlurUi)
    {
        if (CQPaintGaussianBlurUi->objectName().isEmpty())
            CQPaintGaussianBlurUi->setObjectName(QString::fromUtf8("CQPaintGaussianBlurUi"));
        CQPaintGaussianBlurUi->resize(222, 237);
        verticalLayout = new QVBoxLayout(CQPaintGaussianBlurUi);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        xBlurLabel = new QLabel(CQPaintGaussianBlurUi);
        xBlurLabel->setObjectName(QString::fromUtf8("xBlurLabel"));
        xBlurLabel->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(xBlurLabel, 0, 0, 1, 1);

        xBlur = new QLineEdit(CQPaintGaussianBlurUi);
        xBlur->setObjectName(QString::fromUtf8("xBlur"));

        gridLayout->addWidget(xBlur, 0, 1, 1, 1);

        yBlurLabel = new QLabel(CQPaintGaussianBlurUi);
        yBlurLabel->setObjectName(QString::fromUtf8("yBlurLabel"));
        yBlurLabel->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(yBlurLabel, 1, 0, 1, 1);

        yBlur = new QLineEdit(CQPaintGaussianBlurUi);
        yBlur->setObjectName(QString::fromUtf8("yBlur"));
        yBlur->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(yBlur, 1, 1, 1, 1);

        xSizeLabel = new QLabel(CQPaintGaussianBlurUi);
        xSizeLabel->setObjectName(QString::fromUtf8("xSizeLabel"));
        xSizeLabel->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(xSizeLabel, 2, 0, 1, 1);

        xSize = new QLineEdit(CQPaintGaussianBlurUi);
        xSize->setObjectName(QString::fromUtf8("xSize"));
        xSize->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(xSize, 2, 1, 1, 1);

        ySizeLabel = new QLabel(CQPaintGaussianBlurUi);
        ySizeLabel->setObjectName(QString::fromUtf8("ySizeLabel"));
        ySizeLabel->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(ySizeLabel, 3, 0, 1, 1);

        ySize = new QLineEdit(CQPaintGaussianBlurUi);
        ySize->setObjectName(QString::fromUtf8("ySize"));
        ySize->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(ySize, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(CQPaintGaussianBlurUi);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(CQPaintGaussianBlurUi);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        hboxLayout->addWidget(cancelButton);


        verticalLayout->addLayout(hboxLayout);

#if QT_CONFIG(shortcut)
        yBlurLabel->setBuddy(yBlurLabel);
        xSizeLabel->setBuddy(xSize);
        ySizeLabel->setBuddy(ySize);
#endif // QT_CONFIG(shortcut)

        retranslateUi(CQPaintGaussianBlurUi);
        QObject::connect(okButton, SIGNAL(pressed()), CQPaintGaussianBlurUi, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(pressed()), CQPaintGaussianBlurUi, SLOT(reject()));

        QMetaObject::connectSlotsByName(CQPaintGaussianBlurUi);
    } // setupUi

    void retranslateUi(QDialog *CQPaintGaussianBlurUi)
    {
        CQPaintGaussianBlurUi->setWindowTitle(QCoreApplication::translate("CQPaintGaussianBlurUi", "Gaussian Blur", nullptr));
        xBlurLabel->setText(QCoreApplication::translate("CQPaintGaussianBlurUi", "X Blur", nullptr));
        xBlur->setText(QCoreApplication::translate("CQPaintGaussianBlurUi", "2.0", nullptr));
        yBlurLabel->setText(QCoreApplication::translate("CQPaintGaussianBlurUi", "Y Blur", nullptr));
        yBlur->setText(QCoreApplication::translate("CQPaintGaussianBlurUi", "2.0", nullptr));
        xSizeLabel->setText(QCoreApplication::translate("CQPaintGaussianBlurUi", "X Size", nullptr));
        xSize->setText(QCoreApplication::translate("CQPaintGaussianBlurUi", "4", nullptr));
        ySizeLabel->setText(QCoreApplication::translate("CQPaintGaussianBlurUi", "Y Size", nullptr));
        ySize->setText(QCoreApplication::translate("CQPaintGaussianBlurUi", "4", nullptr));
        okButton->setText(QCoreApplication::translate("CQPaintGaussianBlurUi", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("CQPaintGaussianBlurUi", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CQPaintGaussianBlurUi: public Ui_CQPaintGaussianBlurUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CQPAINTGAUSSIANBLUR_H
