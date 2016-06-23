/********************************************************************************
** Form generated from reading UI file 'CQPaintTurbulence.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CQPAINTTURBULENCE_H
#define UI_CQPAINTTURBULENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            CQPaintTurbulenceUi->setObjectName(QStringLiteral("CQPaintTurbulenceUi"));
        CQPaintTurbulenceUi->resize(222, 232);
        vboxLayout = new QVBoxLayout(CQPaintTurbulenceUi);
        vboxLayout->setSpacing(6);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        vboxLayout->setContentsMargins(9, 9, 9, 9);
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        fractal = new QCheckBox(CQPaintTurbulenceUi);
        fractal->setObjectName(QStringLiteral("fractal"));

        vboxLayout1->addWidget(fractal);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        frequencyLabel = new QLabel(CQPaintTurbulenceUi);
        frequencyLabel->setObjectName(QStringLiteral("frequencyLabel"));
        frequencyLabel->setMinimumSize(QSize(70, 0));

        hboxLayout->addWidget(frequencyLabel);

        frequency = new QLineEdit(CQPaintTurbulenceUi);
        frequency->setObjectName(QStringLiteral("frequency"));
        frequency->setMinimumSize(QSize(80, 0));

        hboxLayout->addWidget(frequency);


        vboxLayout1->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        octavesLabel = new QLabel(CQPaintTurbulenceUi);
        octavesLabel->setObjectName(QStringLiteral("octavesLabel"));
        octavesLabel->setMinimumSize(QSize(70, 0));

        hboxLayout1->addWidget(octavesLabel);

        octaves = new QLineEdit(CQPaintTurbulenceUi);
        octaves->setObjectName(QStringLiteral("octaves"));
        octaves->setMinimumSize(QSize(80, 0));

        hboxLayout1->addWidget(octaves);


        vboxLayout1->addLayout(hboxLayout1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QStringLiteral("hboxLayout2"));
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        seedLabel = new QLabel(CQPaintTurbulenceUi);
        seedLabel->setObjectName(QStringLiteral("seedLabel"));
        seedLabel->setMinimumSize(QSize(70, 0));

        hboxLayout2->addWidget(seedLabel);

        seed = new QLineEdit(CQPaintTurbulenceUi);
        seed->setObjectName(QStringLiteral("seed"));
        seed->setMinimumSize(QSize(80, 0));

        hboxLayout2->addWidget(seed);


        vboxLayout1->addLayout(hboxLayout2);


        vboxLayout->addLayout(vboxLayout1);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setObjectName(QStringLiteral("hboxLayout3"));
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacerItem);

        okButton = new QPushButton(CQPaintTurbulenceUi);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout3->addWidget(okButton);

        cancelButton = new QPushButton(CQPaintTurbulenceUi);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout3->addWidget(cancelButton);


        vboxLayout->addLayout(hboxLayout3);

#ifndef QT_NO_SHORTCUT
        frequencyLabel->setBuddy(frequency);
        octavesLabel->setBuddy(octaves);
        seedLabel->setBuddy(seed);
#endif // QT_NO_SHORTCUT

        retranslateUi(CQPaintTurbulenceUi);
        QObject::connect(okButton, SIGNAL(pressed()), CQPaintTurbulenceUi, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(pressed()), CQPaintTurbulenceUi, SLOT(reject()));

        QMetaObject::connectSlotsByName(CQPaintTurbulenceUi);
    } // setupUi

    void retranslateUi(QDialog *CQPaintTurbulenceUi)
    {
        CQPaintTurbulenceUi->setWindowTitle(QApplication::translate("CQPaintTurbulenceUi", "Turbulence", 0));
        fractal->setText(QApplication::translate("CQPaintTurbulenceUi", "Fractal", 0));
        frequencyLabel->setText(QApplication::translate("CQPaintTurbulenceUi", "Frequency", 0));
        frequency->setText(QApplication::translate("CQPaintTurbulenceUi", "0.01", 0));
        octavesLabel->setText(QApplication::translate("CQPaintTurbulenceUi", "Octaves", 0));
        octaves->setText(QApplication::translate("CQPaintTurbulenceUi", "1", 0));
        seedLabel->setText(QApplication::translate("CQPaintTurbulenceUi", "Seed", 0));
        seed->setText(QApplication::translate("CQPaintTurbulenceUi", "0", 0));
        okButton->setText(QApplication::translate("CQPaintTurbulenceUi", "OK", 0));
        cancelButton->setText(QApplication::translate("CQPaintTurbulenceUi", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CQPaintTurbulenceUi: public Ui_CQPaintTurbulenceUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CQPAINTTURBULENCE_H
