/********************************************************************************
** Form generated from reading UI file 'CQPaintTurbulence.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CQPAINTTURBULENCE_H
#define UI_CQPAINTTURBULENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CQPaintTurbulenceUi
{
public:
    QVBoxLayout *vboxLayout;
    QVBoxLayout *vboxLayout1;
    QCheckBox *fractal;
    QHBoxLayout *hboxLayout;
    QLabel *frequencyLabel;
    QLineEdit *frequency;
    QHBoxLayout *hboxLayout1;
    QLabel *octavesLabel;
    QLineEdit *octaves;
    QHBoxLayout *hboxLayout2;
    QLabel *seedLabel;
    QLineEdit *seed;
    QHBoxLayout *hboxLayout3;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *CQPaintTurbulenceUi)
    {
        if (CQPaintTurbulenceUi->objectName().isEmpty())
            CQPaintTurbulenceUi->setObjectName(QString::fromUtf8("CQPaintTurbulenceUi"));
        CQPaintTurbulenceUi->resize(222, 232);
        vboxLayout = new QVBoxLayout(CQPaintTurbulenceUi);
        vboxLayout->setSpacing(6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(9, 9, 9, 9);
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        fractal = new QCheckBox(CQPaintTurbulenceUi);
        fractal->setObjectName(QString::fromUtf8("fractal"));

        vboxLayout1->addWidget(fractal);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        frequencyLabel = new QLabel(CQPaintTurbulenceUi);
        frequencyLabel->setObjectName(QString::fromUtf8("frequencyLabel"));
        frequencyLabel->setMinimumSize(QSize(70, 0));

        hboxLayout->addWidget(frequencyLabel);

        frequency = new QLineEdit(CQPaintTurbulenceUi);
        frequency->setObjectName(QString::fromUtf8("frequency"));
        frequency->setMinimumSize(QSize(80, 0));

        hboxLayout->addWidget(frequency);


        vboxLayout1->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        octavesLabel = new QLabel(CQPaintTurbulenceUi);
        octavesLabel->setObjectName(QString::fromUtf8("octavesLabel"));
        octavesLabel->setMinimumSize(QSize(70, 0));

        hboxLayout1->addWidget(octavesLabel);

        octaves = new QLineEdit(CQPaintTurbulenceUi);
        octaves->setObjectName(QString::fromUtf8("octaves"));
        octaves->setMinimumSize(QSize(80, 0));

        hboxLayout1->addWidget(octaves);


        vboxLayout1->addLayout(hboxLayout1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        seedLabel = new QLabel(CQPaintTurbulenceUi);
        seedLabel->setObjectName(QString::fromUtf8("seedLabel"));
        seedLabel->setMinimumSize(QSize(70, 0));

        hboxLayout2->addWidget(seedLabel);

        seed = new QLineEdit(CQPaintTurbulenceUi);
        seed->setObjectName(QString::fromUtf8("seed"));
        seed->setMinimumSize(QSize(80, 0));

        hboxLayout2->addWidget(seed);


        vboxLayout1->addLayout(hboxLayout2);


        vboxLayout->addLayout(vboxLayout1);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacerItem);

        okButton = new QPushButton(CQPaintTurbulenceUi);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        hboxLayout3->addWidget(okButton);

        cancelButton = new QPushButton(CQPaintTurbulenceUi);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        hboxLayout3->addWidget(cancelButton);


        vboxLayout->addLayout(hboxLayout3);

#if QT_CONFIG(shortcut)
        frequencyLabel->setBuddy(frequency);
        octavesLabel->setBuddy(octaves);
        seedLabel->setBuddy(seed);
#endif // QT_CONFIG(shortcut)

        retranslateUi(CQPaintTurbulenceUi);
        QObject::connect(okButton, SIGNAL(pressed()), CQPaintTurbulenceUi, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(pressed()), CQPaintTurbulenceUi, SLOT(reject()));

        QMetaObject::connectSlotsByName(CQPaintTurbulenceUi);
    } // setupUi

    void retranslateUi(QDialog *CQPaintTurbulenceUi)
    {
        CQPaintTurbulenceUi->setWindowTitle(QCoreApplication::translate("CQPaintTurbulenceUi", "Turbulence", nullptr));
        fractal->setText(QCoreApplication::translate("CQPaintTurbulenceUi", "Fractal", nullptr));
        frequencyLabel->setText(QCoreApplication::translate("CQPaintTurbulenceUi", "Frequency", nullptr));
        frequency->setText(QCoreApplication::translate("CQPaintTurbulenceUi", "0.01", nullptr));
        octavesLabel->setText(QCoreApplication::translate("CQPaintTurbulenceUi", "Octaves", nullptr));
        octaves->setText(QCoreApplication::translate("CQPaintTurbulenceUi", "1", nullptr));
        seedLabel->setText(QCoreApplication::translate("CQPaintTurbulenceUi", "Seed", nullptr));
        seed->setText(QCoreApplication::translate("CQPaintTurbulenceUi", "0", nullptr));
        okButton->setText(QCoreApplication::translate("CQPaintTurbulenceUi", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("CQPaintTurbulenceUi", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CQPaintTurbulenceUi: public Ui_CQPaintTurbulenceUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CQPAINTTURBULENCE_H
