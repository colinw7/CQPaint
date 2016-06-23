/********************************************************************************
** Form generated from reading UI file 'CQPaintGaussianBlur.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CQPAINTGAUSSIANBLUR_H
#define UI_CQPAINTGAUSSIANBLUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            CQPaintGaussianBlurUi->setObjectName(QStringLiteral("CQPaintGaussianBlurUi"));
        CQPaintGaussianBlurUi->resize(222, 237);
        verticalLayout = new QVBoxLayout(CQPaintGaussianBlurUi);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        xBlurLabel = new QLabel(CQPaintGaussianBlurUi);
        xBlurLabel->setObjectName(QStringLiteral("xBlurLabel"));
        xBlurLabel->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(xBlurLabel, 0, 0, 1, 1);

        xBlur = new QLineEdit(CQPaintGaussianBlurUi);
        xBlur->setObjectName(QStringLiteral("xBlur"));

        gridLayout->addWidget(xBlur, 0, 1, 1, 1);

        yBlurLabel = new QLabel(CQPaintGaussianBlurUi);
        yBlurLabel->setObjectName(QStringLiteral("yBlurLabel"));
        yBlurLabel->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(yBlurLabel, 1, 0, 1, 1);

        yBlur = new QLineEdit(CQPaintGaussianBlurUi);
        yBlur->setObjectName(QStringLiteral("yBlur"));
        yBlur->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(yBlur, 1, 1, 1, 1);

        xSizeLabel = new QLabel(CQPaintGaussianBlurUi);
        xSizeLabel->setObjectName(QStringLiteral("xSizeLabel"));
        xSizeLabel->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(xSizeLabel, 2, 0, 1, 1);

        xSize = new QLineEdit(CQPaintGaussianBlurUi);
        xSize->setObjectName(QStringLiteral("xSize"));
        xSize->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(xSize, 2, 1, 1, 1);

        ySizeLabel = new QLabel(CQPaintGaussianBlurUi);
        ySizeLabel->setObjectName(QStringLiteral("ySizeLabel"));
        ySizeLabel->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(ySizeLabel, 3, 0, 1, 1);

        ySize = new QLineEdit(CQPaintGaussianBlurUi);
        ySize->setObjectName(QStringLiteral("ySize"));
        ySize->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(ySize, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(CQPaintGaussianBlurUi);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(CQPaintGaussianBlurUi);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);


        verticalLayout->addLayout(hboxLayout);

#ifndef QT_NO_SHORTCUT
        yBlurLabel->setBuddy(yBlurLabel);
        xSizeLabel->setBuddy(xSize);
        ySizeLabel->setBuddy(ySize);
#endif // QT_NO_SHORTCUT

        retranslateUi(CQPaintGaussianBlurUi);
        QObject::connect(okButton, SIGNAL(pressed()), CQPaintGaussianBlurUi, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(pressed()), CQPaintGaussianBlurUi, SLOT(reject()));

        QMetaObject::connectSlotsByName(CQPaintGaussianBlurUi);
    } // setupUi

    void retranslateUi(QDialog *CQPaintGaussianBlurUi)
    {
        CQPaintGaussianBlurUi->setWindowTitle(QApplication::translate("CQPaintGaussianBlurUi", "Gaussian Blur", 0));
        xBlurLabel->setText(QApplication::translate("CQPaintGaussianBlurUi", "X Blur", 0));
        xBlur->setText(QApplication::translate("CQPaintGaussianBlurUi", "2.0", 0));
        yBlurLabel->setText(QApplication::translate("CQPaintGaussianBlurUi", "Y Blur", 0));
        yBlur->setText(QApplication::translate("CQPaintGaussianBlurUi", "2.0", 0));
        xSizeLabel->setText(QApplication::translate("CQPaintGaussianBlurUi", "X Size", 0));
        xSize->setText(QApplication::translate("CQPaintGaussianBlurUi", "4", 0));
        ySizeLabel->setText(QApplication::translate("CQPaintGaussianBlurUi", "Y Size", 0));
        ySize->setText(QApplication::translate("CQPaintGaussianBlurUi", "4", 0));
        okButton->setText(QApplication::translate("CQPaintGaussianBlurUi", "OK", 0));
        cancelButton->setText(QApplication::translate("CQPaintGaussianBlurUi", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CQPaintGaussianBlurUi: public Ui_CQPaintGaussianBlurUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CQPAINTGAUSSIANBLUR_H
