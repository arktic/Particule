/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 26. May 17:46:10 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>
#include "App.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *layoutHoriz;
    App *app;
    QTabWidget *controlSelector;
    QWidget *fireTab;
    QGroupBox *Size;
    QSlider *sizeMinSliderFire;
    QLabel *label_13;
    QLabel *sizeMaxFireValue;
    QLabel *label_14;
    QLabel *sizeMinFireValue;
    QSlider *sizeMaxSliderFire;
    QSpinBox *centerXFireSpinbox;
    QLabel *centerFireValue;
    QSpinBox *centerYFireSpinbox;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *nbItemFireValue;
    QLabel *radiusFireValue;
    QLabel *label_5;
    QGroupBox *lifetime;
    QSlider *lifetimeMinSliderFire_4;
    QLabel *label_21;
    QLabel *lifetimeMaxFireValue_4;
    QLabel *label_22;
    QLabel *lifetimeMinFireValue_4;
    QSlider *lifetimeMaxSliderFire_4;
    QSpinBox *centerZFireSpinbox;
    QLabel *nbItemPerFrameFireValue;
    QSlider *nbItemSliderFire;
    QLabel *label;
    QSlider *radiusSliderFire;
    QSlider *frameTimeSliderFire;
    QLabel *label_4;
    QLabel *frameTimeFireValue;
    QSlider *nbItemPerFrameSliderFire;
    QGroupBox *Velocity;
    QSlider *velocityMinSliderFire_4;
    QLabel *label_23;
    QLabel *velocityMaxFireValue_4;
    QLabel *label_24;
    QLabel *velocityMinFireValue_4;
    QSlider *velocityMaxSliderFire_4;
    QFrame *line;
    QGroupBox *ageAttenuation;
    QSlider *ageAttenuationFactorSliderFire;
    QLabel *label_27;
    QLabel *ageAttenuationLimitFireValue;
    QLabel *label_28;
    QLabel *ageAttenuationFactorFireValue;
    QSlider *ageAttenuationLimitSliderFire;
    QPushButton *setValuesButton;
    QWidget *smokeTab;
    QWidget *fountainTab;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1036, 630);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMouseTracking(false);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 571, 701));
        layoutHoriz = new QHBoxLayout(horizontalLayoutWidget);
        layoutHoriz->setObjectName(QString::fromUtf8("layoutHoriz"));
        layoutHoriz->setContentsMargins(0, 0, 0, 0);
        app = new App(horizontalLayoutWidget);
        app->setObjectName(QString::fromUtf8("app"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(app->sizePolicy().hasHeightForWidth());
        app->setSizePolicy(sizePolicy);

        layoutHoriz->addWidget(app);

        controlSelector = new QTabWidget(centralwidget);
        controlSelector->setObjectName(QString::fromUtf8("controlSelector"));
        controlSelector->setGeometry(QRect(580, 0, 461, 701));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(controlSelector->sizePolicy().hasHeightForWidth());
        controlSelector->setSizePolicy(sizePolicy1);
        fireTab = new QWidget();
        fireTab->setObjectName(QString::fromUtf8("fireTab"));
        fireTab->setMouseTracking(false);
        Size = new QGroupBox(fireTab);
        Size->setObjectName(QString::fromUtf8("Size"));
        Size->setGeometry(QRect(240, 10, 211, 131));
        sizeMinSliderFire = new QSlider(Size);
        sizeMinSliderFire->setObjectName(QString::fromUtf8("sizeMinSliderFire"));
        sizeMinSliderFire->setGeometry(QRect(10, 50, 191, 22));
        sizeMinSliderFire->setMinimum(1);
        sizeMinSliderFire->setMaximum(15);
        sizeMinSliderFire->setOrientation(Qt::Horizontal);
        label_13 = new QLabel(Size);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(120, 20, 21, 21));
        sizeMaxFireValue = new QLabel(Size);
        sizeMaxFireValue->setObjectName(QString::fromUtf8("sizeMaxFireValue"));
        sizeMaxFireValue->setGeometry(QRect(150, 20, 46, 13));
        label_14 = new QLabel(Size);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(30, 20, 21, 21));
        sizeMinFireValue = new QLabel(Size);
        sizeMinFireValue->setObjectName(QString::fromUtf8("sizeMinFireValue"));
        sizeMinFireValue->setGeometry(QRect(60, 20, 46, 13));
        sizeMaxSliderFire = new QSlider(Size);
        sizeMaxSliderFire->setObjectName(QString::fromUtf8("sizeMaxSliderFire"));
        sizeMaxSliderFire->setGeometry(QRect(10, 80, 191, 22));
        sizeMaxSliderFire->setMinimum(1);
        sizeMaxSliderFire->setMaximum(15);
        sizeMaxSliderFire->setOrientation(Qt::Horizontal);
        centerXFireSpinbox = new QSpinBox(fireTab);
        centerXFireSpinbox->setObjectName(QString::fromUtf8("centerXFireSpinbox"));
        centerXFireSpinbox->setGeometry(QRect(40, 260, 42, 22));
        centerXFireSpinbox->setMinimum(-1000);
        centerXFireSpinbox->setMaximum(1000);
        centerXFireSpinbox->setSingleStep(1);
        centerFireValue = new QLabel(fireTab);
        centerFireValue->setObjectName(QString::fromUtf8("centerFireValue"));
        centerFireValue->setGeometry(QRect(60, 240, 46, 13));
        centerFireValue->setAcceptDrops(true);
        centerYFireSpinbox = new QSpinBox(fireTab);
        centerYFireSpinbox->setObjectName(QString::fromUtf8("centerYFireSpinbox"));
        centerYFireSpinbox->setGeometry(QRect(90, 260, 42, 22));
        centerYFireSpinbox->setMinimum(-1000);
        centerYFireSpinbox->setMaximum(1000);
        centerYFireSpinbox->setSingleStep(1);
        label_3 = new QLabel(fireTab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 120, 81, 20));
        label_2 = new QLabel(fireTab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 61, 20));
        nbItemFireValue = new QLabel(fireTab);
        nbItemFireValue->setObjectName(QString::fromUtf8("nbItemFireValue"));
        nbItemFireValue->setGeometry(QRect(90, 60, 46, 13));
        radiusFireValue = new QLabel(fireTab);
        radiusFireValue->setObjectName(QString::fromUtf8("radiusFireValue"));
        radiusFireValue->setGeometry(QRect(80, 10, 46, 13));
        label_5 = new QLabel(fireTab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(15, 240, 51, 20));
        lifetime = new QGroupBox(fireTab);
        lifetime->setObjectName(QString::fromUtf8("lifetime"));
        lifetime->setGeometry(QRect(10, 300, 211, 131));
        lifetimeMinSliderFire_4 = new QSlider(lifetime);
        lifetimeMinSliderFire_4->setObjectName(QString::fromUtf8("lifetimeMinSliderFire_4"));
        lifetimeMinSliderFire_4->setGeometry(QRect(10, 50, 191, 22));
        lifetimeMinSliderFire_4->setMinimum(200);
        lifetimeMinSliderFire_4->setMaximum(5000);
        lifetimeMinSliderFire_4->setSingleStep(100);
        lifetimeMinSliderFire_4->setPageStep(100);
        lifetimeMinSliderFire_4->setValue(1000);
        lifetimeMinSliderFire_4->setOrientation(Qt::Horizontal);
        label_21 = new QLabel(lifetime);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(120, 20, 21, 21));
        lifetimeMaxFireValue_4 = new QLabel(lifetime);
        lifetimeMaxFireValue_4->setObjectName(QString::fromUtf8("lifetimeMaxFireValue_4"));
        lifetimeMaxFireValue_4->setGeometry(QRect(150, 20, 46, 13));
        label_22 = new QLabel(lifetime);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(30, 20, 21, 21));
        lifetimeMinFireValue_4 = new QLabel(lifetime);
        lifetimeMinFireValue_4->setObjectName(QString::fromUtf8("lifetimeMinFireValue_4"));
        lifetimeMinFireValue_4->setGeometry(QRect(60, 20, 46, 13));
        lifetimeMaxSliderFire_4 = new QSlider(lifetime);
        lifetimeMaxSliderFire_4->setObjectName(QString::fromUtf8("lifetimeMaxSliderFire_4"));
        lifetimeMaxSliderFire_4->setGeometry(QRect(10, 80, 191, 22));
        lifetimeMaxSliderFire_4->setMinimum(200);
        lifetimeMaxSliderFire_4->setMaximum(5000);
        lifetimeMaxSliderFire_4->setSingleStep(100);
        lifetimeMaxSliderFire_4->setPageStep(100);
        lifetimeMaxSliderFire_4->setValue(3000);
        lifetimeMaxSliderFire_4->setOrientation(Qt::Horizontal);
        centerZFireSpinbox = new QSpinBox(fireTab);
        centerZFireSpinbox->setObjectName(QString::fromUtf8("centerZFireSpinbox"));
        centerZFireSpinbox->setGeometry(QRect(140, 260, 42, 22));
        centerZFireSpinbox->setMinimum(-1000);
        centerZFireSpinbox->setMaximum(1000);
        centerZFireSpinbox->setSingleStep(1);
        nbItemPerFrameFireValue = new QLabel(fireTab);
        nbItemPerFrameFireValue->setObjectName(QString::fromUtf8("nbItemPerFrameFireValue"));
        nbItemPerFrameFireValue->setGeometry(QRect(110, 120, 46, 13));
        nbItemSliderFire = new QSlider(fireTab);
        nbItemSliderFire->setObjectName(QString::fromUtf8("nbItemSliderFire"));
        nbItemSliderFire->setEnabled(false);
        nbItemSliderFire->setGeometry(QRect(10, 80, 211, 22));
        nbItemSliderFire->setMinimum(1000);
        nbItemSliderFire->setMaximum(60000);
        nbItemSliderFire->setSingleStep(1000);
        nbItemSliderFire->setValue(10000);
        nbItemSliderFire->setOrientation(Qt::Horizontal);
        label = new QLabel(fireTab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 46, 13));
        radiusSliderFire = new QSlider(fireTab);
        radiusSliderFire->setObjectName(QString::fromUtf8("radiusSliderFire"));
        radiusSliderFire->setGeometry(QRect(10, 30, 211, 22));
        radiusSliderFire->setMinimum(1);
        radiusSliderFire->setValue(4);
        radiusSliderFire->setOrientation(Qt::Horizontal);
        frameTimeSliderFire = new QSlider(fireTab);
        frameTimeSliderFire->setObjectName(QString::fromUtf8("frameTimeSliderFire"));
        frameTimeSliderFire->setGeometry(QRect(10, 200, 211, 22));
        frameTimeSliderFire->setMinimum(10);
        frameTimeSliderFire->setMaximum(100);
        frameTimeSliderFire->setValue(33);
        frameTimeSliderFire->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(fireTab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(15, 180, 81, 20));
        frameTimeFireValue = new QLabel(fireTab);
        frameTimeFireValue->setObjectName(QString::fromUtf8("frameTimeFireValue"));
        frameTimeFireValue->setGeometry(QRect(100, 180, 46, 13));
        nbItemPerFrameSliderFire = new QSlider(fireTab);
        nbItemPerFrameSliderFire->setObjectName(QString::fromUtf8("nbItemPerFrameSliderFire"));
        nbItemPerFrameSliderFire->setGeometry(QRect(10, 140, 211, 22));
        nbItemPerFrameSliderFire->setMinimum(100);
        nbItemPerFrameSliderFire->setMaximum(3000);
        nbItemPerFrameSliderFire->setSingleStep(100);
        nbItemPerFrameSliderFire->setPageStep(100);
        nbItemPerFrameSliderFire->setValue(300);
        nbItemPerFrameSliderFire->setOrientation(Qt::Horizontal);
        Velocity = new QGroupBox(fireTab);
        Velocity->setObjectName(QString::fromUtf8("Velocity"));
        Velocity->setGeometry(QRect(10, 430, 211, 131));
        velocityMinSliderFire_4 = new QSlider(Velocity);
        velocityMinSliderFire_4->setObjectName(QString::fromUtf8("velocityMinSliderFire_4"));
        velocityMinSliderFire_4->setGeometry(QRect(10, 50, 191, 22));
        velocityMinSliderFire_4->setMinimum(1);
        velocityMinSliderFire_4->setMaximum(20);
        velocityMinSliderFire_4->setPageStep(11);
        velocityMinSliderFire_4->setOrientation(Qt::Horizontal);
        label_23 = new QLabel(Velocity);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(120, 20, 21, 21));
        velocityMaxFireValue_4 = new QLabel(Velocity);
        velocityMaxFireValue_4->setObjectName(QString::fromUtf8("velocityMaxFireValue_4"));
        velocityMaxFireValue_4->setGeometry(QRect(150, 20, 46, 13));
        label_24 = new QLabel(Velocity);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(30, 20, 21, 21));
        velocityMinFireValue_4 = new QLabel(Velocity);
        velocityMinFireValue_4->setObjectName(QString::fromUtf8("velocityMinFireValue_4"));
        velocityMinFireValue_4->setGeometry(QRect(60, 20, 46, 13));
        velocityMaxSliderFire_4 = new QSlider(Velocity);
        velocityMaxSliderFire_4->setObjectName(QString::fromUtf8("velocityMaxSliderFire_4"));
        velocityMaxSliderFire_4->setGeometry(QRect(10, 80, 191, 22));
        velocityMaxSliderFire_4->setMinimum(1);
        velocityMaxSliderFire_4->setMaximum(20);
        velocityMaxSliderFire_4->setValue(4);
        velocityMaxSliderFire_4->setOrientation(Qt::Horizontal);
        line = new QFrame(fireTab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(220, 0, 20, 681));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        ageAttenuation = new QGroupBox(fireTab);
        ageAttenuation->setObjectName(QString::fromUtf8("ageAttenuation"));
        ageAttenuation->setGeometry(QRect(240, 160, 211, 131));
        ageAttenuationFactorSliderFire = new QSlider(ageAttenuation);
        ageAttenuationFactorSliderFire->setObjectName(QString::fromUtf8("ageAttenuationFactorSliderFire"));
        ageAttenuationFactorSliderFire->setGeometry(QRect(10, 50, 191, 22));
        ageAttenuationFactorSliderFire->setOrientation(Qt::Horizontal);
        label_27 = new QLabel(ageAttenuation);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(120, 20, 21, 21));
        ageAttenuationLimitFireValue = new QLabel(ageAttenuation);
        ageAttenuationLimitFireValue->setObjectName(QString::fromUtf8("ageAttenuationLimitFireValue"));
        ageAttenuationLimitFireValue->setGeometry(QRect(150, 20, 46, 13));
        label_28 = new QLabel(ageAttenuation);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(20, 20, 31, 21));
        ageAttenuationFactorFireValue = new QLabel(ageAttenuation);
        ageAttenuationFactorFireValue->setObjectName(QString::fromUtf8("ageAttenuationFactorFireValue"));
        ageAttenuationFactorFireValue->setGeometry(QRect(60, 20, 46, 13));
        ageAttenuationLimitSliderFire = new QSlider(ageAttenuation);
        ageAttenuationLimitSliderFire->setObjectName(QString::fromUtf8("ageAttenuationLimitSliderFire"));
        ageAttenuationLimitSliderFire->setGeometry(QRect(10, 80, 191, 22));
        ageAttenuationLimitSliderFire->setOrientation(Qt::Horizontal);
        setValuesButton = new QPushButton(fireTab);
        setValuesButton->setObjectName(QString::fromUtf8("setValuesButton"));
        setValuesButton->setGeometry(QRect(270, 360, 141, 101));
        controlSelector->addTab(fireTab, QString());
        smokeTab = new QWidget();
        smokeTab->setObjectName(QString::fromUtf8("smokeTab"));
        controlSelector->addTab(smokeTab, QString());
        fountainTab = new QWidget();
        fountainTab->setObjectName(QString::fromUtf8("fountainTab"));
        controlSelector->addTab(fountainTab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1036, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(radiusSliderFire, SIGNAL(valueChanged(int)), radiusFireValue, SLOT(setNum(int)));
        QObject::connect(nbItemSliderFire, SIGNAL(valueChanged(int)), nbItemFireValue, SLOT(setNum(int)));
        QObject::connect(nbItemPerFrameSliderFire, SIGNAL(valueChanged(int)), nbItemPerFrameFireValue, SLOT(setNum(int)));
        QObject::connect(frameTimeSliderFire, SIGNAL(valueChanged(int)), frameTimeFireValue, SLOT(setNum(int)));

        controlSelector->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        Size->setTitle(QApplication::translate("MainWindow", "Size", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "max", 0, QApplication::UnicodeUTF8));
        sizeMaxFireValue->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "min", 0, QApplication::UnicodeUTF8));
        sizeMinFireValue->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        centerFireValue->setText(QApplication::translate("MainWindow", "(0,0,0)", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "NbItemPerFrame", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Nb particles", 0, QApplication::UnicodeUTF8));
        nbItemFireValue->setText(QApplication::translate("MainWindow", "10000", 0, QApplication::UnicodeUTF8));
        radiusFireValue->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Center", 0, QApplication::UnicodeUTF8));
        lifetime->setTitle(QApplication::translate("MainWindow", "Lifetime (ms)", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "max", 0, QApplication::UnicodeUTF8));
        lifetimeMaxFireValue_4->setText(QApplication::translate("MainWindow", "3000", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "min", 0, QApplication::UnicodeUTF8));
        lifetimeMinFireValue_4->setText(QApplication::translate("MainWindow", "1000", 0, QApplication::UnicodeUTF8));
        nbItemPerFrameFireValue->setText(QApplication::translate("MainWindow", "300", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Radius", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "FrameTime (ms)", 0, QApplication::UnicodeUTF8));
        frameTimeFireValue->setText(QApplication::translate("MainWindow", "33", 0, QApplication::UnicodeUTF8));
        Velocity->setTitle(QApplication::translate("MainWindow", "Velocity", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "max", 0, QApplication::UnicodeUTF8));
        velocityMaxFireValue_4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "min", 0, QApplication::UnicodeUTF8));
        velocityMinFireValue_4->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        ageAttenuation->setTitle(QApplication::translate("MainWindow", "Age Attenuation", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "limit", 0, QApplication::UnicodeUTF8));
        ageAttenuationLimitFireValue->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "factor", 0, QApplication::UnicodeUTF8));
        ageAttenuationFactorFireValue->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        setValuesButton->setText(QApplication::translate("MainWindow", "Set up values", 0, QApplication::UnicodeUTF8));
        controlSelector->setTabText(controlSelector->indexOf(fireTab), QApplication::translate("MainWindow", "Fire", 0, QApplication::UnicodeUTF8));
        controlSelector->setTabText(controlSelector->indexOf(smokeTab), QApplication::translate("MainWindow", "Smoke", 0, QApplication::UnicodeUTF8));
        controlSelector->setTabText(controlSelector->indexOf(fountainTab), QApplication::translate("MainWindow", "Fountain", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
