/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 27. May 00:04:08 2013
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
    QSlider *velocityMinSliderFire;
    QLabel *label_23;
    QLabel *velocityMaxFireValue;
    QLabel *label_24;
    QLabel *velocityMinFireValue;
    QSlider *velocityMaxSliderFire;
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
    QLabel *centerSmokeValue;
    QSpinBox *centerXSmokeSpinbox;
    QLabel *nbItemSmokeValue;
    QGroupBox *VelocitySmokeFrame;
    QSlider *velocityMinSliderSmoke;
    QLabel *label_35;
    QLabel *velocityMaxSmokeValue;
    QLabel *label_36;
    QLabel *velocityMinSmokeValue;
    QSlider *velocityMaxSliderSmoke;
    QSlider *frameTimeSliderSmoke;
    QSlider *radiusSliderSmoke;
    QFrame *lineSmoke;
    QGroupBox *SizeSmokeFrame;
    QSlider *coefSizeSliderSmoke;
    QLabel *coefSizeSmokeLabel;
    QLabel *coefSizeSmokeValue;
    QLabel *radiusSmokeValue;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *frameTimeSmokeValue;
    QSpinBox *centerZSmokeSpinbox;
    QLabel *label_9;
    QSlider *nbItemSliderFire_2;
    QLabel *label_10;
    QPushButton *setValuesButtonSmoke;
    QSpinBox *centerYSmokeSpinbox;
    QGroupBox *lifetimeSmoke;
    QSlider *lifetimeMinSliderSmoke;
    QLabel *label_37;
    QLabel *lifetimeMaxSmokeValue;
    QLabel *label_38;
    QLabel *lifetimeMinSmokeValue;
    QSlider *lifetimeMaxSliderSmoke;
    QGroupBox *ItemPerFrameGB;
    QSlider *nbMaxItemPerFrameSliderSmoke;
    QLabel *label_8;
    QLabel *nbMaxItemPerFrameSmoke;
    QLabel *nbMinItemPerFrameSmoke;
    QSlider *nbMinItemPerFrameSliderSmoke;
    QLabel *label_11;
    QLabel *label_12;
    QSlider *genTimerSliderSmoke;
    QLabel *genTimerSmokeValue;
    QWidget *fountainTab;
<<<<<<< .mine
    QLabel *centerFountainValue;
    QSpinBox *centerXFountainSpinbox;
    QLabel *nbItemFountainValue;
    QLabel *nbItemPerFrameFountainValue;
    QGroupBox *Velocity_2;
    QSlider *velocityMinSliderFountain;
    QLabel *label_39;
    QLabel *velocityMaxFountainValue;
    QLabel *label_40;
    QLabel *velocityMinFountainValue;
    QSlider *velocityMaxSliderFountain;
    QSlider *frameTimeSliderFountain;
    QSlider *radiusSliderFountain;
    QFrame *line_2;
    QGroupBox *Size_2;
    QSlider *sizeMinSliderFountain;
    QLabel *label_19;
    QLabel *sizeMaxFountainValue;
    QLabel *label_20;
    QLabel *sizeMinFountainValue;
    QSlider *sizeMaxSliderFountain;
    QSlider *nbItemPerFrameSliderFountain;
    QLabel *radiusFountainValue;
    QLabel *label_41;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *frameTimeFountainValue;
    QSpinBox *centerZFountainSpinbox;
    QLabel *label_44;
    QSlider *nbItemSliderFountain;
    QLabel *label_45;
    QPushButton *setValuesButtonFountain;
    QSpinBox *centerYFountainSpinbox;
    QGroupBox *lifetime_2;
    QSlider *lifetimeMinSliderFountain;
    QLabel *label_48;
    QLabel *lifetimeMaxFountainValue;
    QLabel *label_49;
    QLabel *lifetimeMinFountainValue;
    QSlider *lifetimeMaxSliderFountain;
    QLabel *label_46;
    QSpinBox *directionXFountainSpinbox;
    QSpinBox *directionZFountainSpinbox;
    QSpinBox *directionYFountainSpinbox;
=======
    QLabel *fpsValue;
    QLabel *label_6;










































>>>>>>> .theirs
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
        controlSelector->setGeometry(QRect(580, 30, 461, 671));
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
        velocityMinSliderFire = new QSlider(Velocity);
        velocityMinSliderFire->setObjectName(QString::fromUtf8("velocityMinSliderFire"));
        velocityMinSliderFire->setGeometry(QRect(10, 50, 191, 22));
        velocityMinSliderFire->setMinimum(1);
        velocityMinSliderFire->setMaximum(20);
        velocityMinSliderFire->setPageStep(11);
        velocityMinSliderFire->setOrientation(Qt::Horizontal);
        label_23 = new QLabel(Velocity);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(120, 20, 21, 21));
        velocityMaxFireValue = new QLabel(Velocity);
        velocityMaxFireValue->setObjectName(QString::fromUtf8("velocityMaxFireValue"));
        velocityMaxFireValue->setGeometry(QRect(150, 20, 46, 13));
        label_24 = new QLabel(Velocity);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(30, 20, 21, 21));
        velocityMinFireValue = new QLabel(Velocity);
        velocityMinFireValue->setObjectName(QString::fromUtf8("velocityMinFireValue"));
        velocityMinFireValue->setGeometry(QRect(60, 20, 46, 13));
        velocityMaxSliderFire = new QSlider(Velocity);
        velocityMaxSliderFire->setObjectName(QString::fromUtf8("velocityMaxSliderFire"));
        velocityMaxSliderFire->setGeometry(QRect(10, 80, 191, 22));
        velocityMaxSliderFire->setMinimum(1);
        velocityMaxSliderFire->setMaximum(20);
        velocityMaxSliderFire->setValue(4);
        velocityMaxSliderFire->setOrientation(Qt::Horizontal);
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
        centerSmokeValue = new QLabel(smokeTab);
        centerSmokeValue->setObjectName(QString::fromUtf8("centerSmokeValue"));
        centerSmokeValue->setGeometry(QRect(60, 240, 46, 13));
        centerSmokeValue->setAcceptDrops(true);
        centerXSmokeSpinbox = new QSpinBox(smokeTab);
        centerXSmokeSpinbox->setObjectName(QString::fromUtf8("centerXSmokeSpinbox"));
        centerXSmokeSpinbox->setGeometry(QRect(40, 260, 42, 22));
        centerXSmokeSpinbox->setMinimum(-1000);
        centerXSmokeSpinbox->setMaximum(1000);
        centerXSmokeSpinbox->setSingleStep(1);
        nbItemSmokeValue = new QLabel(smokeTab);
        nbItemSmokeValue->setObjectName(QString::fromUtf8("nbItemSmokeValue"));
        nbItemSmokeValue->setGeometry(QRect(90, 60, 46, 13));
        VelocitySmokeFrame = new QGroupBox(smokeTab);
        VelocitySmokeFrame->setObjectName(QString::fromUtf8("VelocitySmokeFrame"));
        VelocitySmokeFrame->setGeometry(QRect(10, 430, 211, 131));
        velocityMinSliderSmoke = new QSlider(VelocitySmokeFrame);
        velocityMinSliderSmoke->setObjectName(QString::fromUtf8("velocityMinSliderSmoke"));
        velocityMinSliderSmoke->setGeometry(QRect(10, 50, 191, 22));
        velocityMinSliderSmoke->setMinimum(1);
        velocityMinSliderSmoke->setMaximum(20);
        velocityMinSliderSmoke->setPageStep(11);
        velocityMinSliderSmoke->setOrientation(Qt::Horizontal);
        label_35 = new QLabel(VelocitySmokeFrame);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(120, 20, 21, 21));
        velocityMaxSmokeValue = new QLabel(VelocitySmokeFrame);
        velocityMaxSmokeValue->setObjectName(QString::fromUtf8("velocityMaxSmokeValue"));
        velocityMaxSmokeValue->setGeometry(QRect(150, 20, 46, 13));
        label_36 = new QLabel(VelocitySmokeFrame);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(30, 20, 21, 21));
        velocityMinSmokeValue = new QLabel(VelocitySmokeFrame);
        velocityMinSmokeValue->setObjectName(QString::fromUtf8("velocityMinSmokeValue"));
        velocityMinSmokeValue->setGeometry(QRect(60, 20, 46, 13));
        velocityMaxSliderSmoke = new QSlider(VelocitySmokeFrame);
        velocityMaxSliderSmoke->setObjectName(QString::fromUtf8("velocityMaxSliderSmoke"));
        velocityMaxSliderSmoke->setGeometry(QRect(10, 80, 191, 22));
        velocityMaxSliderSmoke->setMinimum(1);
        velocityMaxSliderSmoke->setMaximum(20);
        velocityMaxSliderSmoke->setValue(4);
        velocityMaxSliderSmoke->setOrientation(Qt::Horizontal);
        frameTimeSliderSmoke = new QSlider(smokeTab);
        frameTimeSliderSmoke->setObjectName(QString::fromUtf8("frameTimeSliderSmoke"));
        frameTimeSliderSmoke->setGeometry(QRect(10, 200, 211, 22));
        frameTimeSliderSmoke->setMinimum(10);
        frameTimeSliderSmoke->setMaximum(100);
        frameTimeSliderSmoke->setValue(33);
        frameTimeSliderSmoke->setOrientation(Qt::Horizontal);
        radiusSliderSmoke = new QSlider(smokeTab);
        radiusSliderSmoke->setObjectName(QString::fromUtf8("radiusSliderSmoke"));
        radiusSliderSmoke->setGeometry(QRect(10, 30, 211, 22));
        radiusSliderSmoke->setMinimum(1);
        radiusSliderSmoke->setValue(4);
        radiusSliderSmoke->setOrientation(Qt::Horizontal);
        lineSmoke = new QFrame(smokeTab);
        lineSmoke->setObjectName(QString::fromUtf8("lineSmoke"));
        lineSmoke->setGeometry(QRect(220, 0, 20, 681));
        lineSmoke->setFrameShape(QFrame::VLine);
        lineSmoke->setFrameShadow(QFrame::Sunken);
        SizeSmokeFrame = new QGroupBox(smokeTab);
        SizeSmokeFrame->setObjectName(QString::fromUtf8("SizeSmokeFrame"));
        SizeSmokeFrame->setGeometry(QRect(240, 10, 211, 81));
        coefSizeSliderSmoke = new QSlider(SizeSmokeFrame);
        coefSizeSliderSmoke->setObjectName(QString::fromUtf8("coefSizeSliderSmoke"));
        coefSizeSliderSmoke->setGeometry(QRect(10, 50, 191, 22));
        coefSizeSliderSmoke->setMinimum(1);
        coefSizeSliderSmoke->setMaximum(15);
        coefSizeSliderSmoke->setOrientation(Qt::Horizontal);
        coefSizeSmokeLabel = new QLabel(SizeSmokeFrame);
        coefSizeSmokeLabel->setObjectName(QString::fromUtf8("coefSizeSmokeLabel"));
        coefSizeSmokeLabel->setGeometry(QRect(30, 20, 21, 21));
        coefSizeSmokeValue = new QLabel(SizeSmokeFrame);
        coefSizeSmokeValue->setObjectName(QString::fromUtf8("coefSizeSmokeValue"));
        coefSizeSmokeValue->setGeometry(QRect(60, 20, 46, 13));
        radiusSmokeValue = new QLabel(smokeTab);
        radiusSmokeValue->setObjectName(QString::fromUtf8("radiusSmokeValue"));
        radiusSmokeValue->setGeometry(QRect(80, 10, 46, 13));
        label_6 = new QLabel(smokeTab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 60, 61, 20));
        label_7 = new QLabel(smokeTab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(15, 180, 81, 20));
        frameTimeSmokeValue = new QLabel(smokeTab);
        frameTimeSmokeValue->setObjectName(QString::fromUtf8("frameTimeSmokeValue"));
        frameTimeSmokeValue->setGeometry(QRect(100, 180, 46, 13));
        centerZSmokeSpinbox = new QSpinBox(smokeTab);
        centerZSmokeSpinbox->setObjectName(QString::fromUtf8("centerZSmokeSpinbox"));
        centerZSmokeSpinbox->setGeometry(QRect(140, 260, 42, 22));
        centerZSmokeSpinbox->setMinimum(-1000);
        centerZSmokeSpinbox->setMaximum(1000);
        centerZSmokeSpinbox->setSingleStep(1);
        label_9 = new QLabel(smokeTab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(15, 240, 51, 20));
        nbItemSliderFire_2 = new QSlider(smokeTab);
        nbItemSliderFire_2->setObjectName(QString::fromUtf8("nbItemSliderFire_2"));
        nbItemSliderFire_2->setEnabled(false);
        nbItemSliderFire_2->setGeometry(QRect(10, 80, 211, 22));
        nbItemSliderFire_2->setMinimum(1000);
        nbItemSliderFire_2->setMaximum(60000);
        nbItemSliderFire_2->setSingleStep(1000);
        nbItemSliderFire_2->setValue(10000);
        nbItemSliderFire_2->setOrientation(Qt::Horizontal);
        label_10 = new QLabel(smokeTab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 10, 46, 13));
        setValuesButtonSmoke = new QPushButton(smokeTab);
        setValuesButtonSmoke->setObjectName(QString::fromUtf8("setValuesButtonSmoke"));
        setValuesButtonSmoke->setGeometry(QRect(270, 360, 141, 101));
        centerYSmokeSpinbox = new QSpinBox(smokeTab);
        centerYSmokeSpinbox->setObjectName(QString::fromUtf8("centerYSmokeSpinbox"));
        centerYSmokeSpinbox->setGeometry(QRect(90, 260, 42, 22));
        centerYSmokeSpinbox->setMinimum(-1000);
        centerYSmokeSpinbox->setMaximum(1000);
        centerYSmokeSpinbox->setSingleStep(1);
        lifetimeSmoke = new QGroupBox(smokeTab);
        lifetimeSmoke->setObjectName(QString::fromUtf8("lifetimeSmoke"));
        lifetimeSmoke->setGeometry(QRect(10, 300, 211, 131));
        lifetimeMinSliderSmoke = new QSlider(lifetimeSmoke);
        lifetimeMinSliderSmoke->setObjectName(QString::fromUtf8("lifetimeMinSliderSmoke"));
        lifetimeMinSliderSmoke->setGeometry(QRect(10, 50, 191, 22));
        lifetimeMinSliderSmoke->setMinimum(200);
        lifetimeMinSliderSmoke->setMaximum(5000);
        lifetimeMinSliderSmoke->setSingleStep(100);
        lifetimeMinSliderSmoke->setPageStep(100);
        lifetimeMinSliderSmoke->setValue(1000);
        lifetimeMinSliderSmoke->setOrientation(Qt::Horizontal);
        label_37 = new QLabel(lifetimeSmoke);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(120, 20, 21, 21));
        lifetimeMaxSmokeValue = new QLabel(lifetimeSmoke);
        lifetimeMaxSmokeValue->setObjectName(QString::fromUtf8("lifetimeMaxSmokeValue"));
        lifetimeMaxSmokeValue->setGeometry(QRect(150, 20, 46, 13));
        label_38 = new QLabel(lifetimeSmoke);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(30, 20, 21, 21));
        lifetimeMinSmokeValue = new QLabel(lifetimeSmoke);
        lifetimeMinSmokeValue->setObjectName(QString::fromUtf8("lifetimeMinSmokeValue"));
        lifetimeMinSmokeValue->setGeometry(QRect(60, 20, 46, 13));
        lifetimeMaxSliderSmoke = new QSlider(lifetimeSmoke);
        lifetimeMaxSliderSmoke->setObjectName(QString::fromUtf8("lifetimeMaxSliderSmoke"));
        lifetimeMaxSliderSmoke->setGeometry(QRect(10, 80, 191, 22));
        lifetimeMaxSliderSmoke->setMinimum(200);
        lifetimeMaxSliderSmoke->setMaximum(5000);
        lifetimeMaxSliderSmoke->setSingleStep(100);
        lifetimeMaxSliderSmoke->setPageStep(100);
        lifetimeMaxSliderSmoke->setValue(3000);
        lifetimeMaxSliderSmoke->setOrientation(Qt::Horizontal);
        ItemPerFrameGB = new QGroupBox(smokeTab);
        ItemPerFrameGB->setObjectName(QString::fromUtf8("ItemPerFrameGB"));
        ItemPerFrameGB->setGeometry(QRect(240, 110, 211, 131));
        nbMaxItemPerFrameSliderSmoke = new QSlider(ItemPerFrameGB);
        nbMaxItemPerFrameSliderSmoke->setObjectName(QString::fromUtf8("nbMaxItemPerFrameSliderSmoke"));
        nbMaxItemPerFrameSliderSmoke->setGeometry(QRect(10, 40, 191, 22));
        nbMaxItemPerFrameSliderSmoke->setMinimum(0);
        nbMaxItemPerFrameSliderSmoke->setMaximum(600);
        nbMaxItemPerFrameSliderSmoke->setSingleStep(1);
        nbMaxItemPerFrameSliderSmoke->setPageStep(100);
        nbMaxItemPerFrameSliderSmoke->setValue(1);
        nbMaxItemPerFrameSliderSmoke->setOrientation(Qt::Horizontal);
        label_8 = new QLabel(ItemPerFrameGB);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 20, 111, 20));
        nbMaxItemPerFrameSmoke = new QLabel(ItemPerFrameGB);
        nbMaxItemPerFrameSmoke->setObjectName(QString::fromUtf8("nbMaxItemPerFrameSmoke"));
        nbMaxItemPerFrameSmoke->setGeometry(QRect(150, 20, 46, 13));
        nbMinItemPerFrameSmoke = new QLabel(ItemPerFrameGB);
        nbMinItemPerFrameSmoke->setObjectName(QString::fromUtf8("nbMinItemPerFrameSmoke"));
        nbMinItemPerFrameSmoke->setGeometry(QRect(150, 70, 46, 13));
        nbMinItemPerFrameSliderSmoke = new QSlider(ItemPerFrameGB);
        nbMinItemPerFrameSliderSmoke->setObjectName(QString::fromUtf8("nbMinItemPerFrameSliderSmoke"));
        nbMinItemPerFrameSliderSmoke->setGeometry(QRect(10, 90, 191, 22));
        nbMinItemPerFrameSliderSmoke->setMinimum(0);
        nbMinItemPerFrameSliderSmoke->setMaximum(600);
        nbMinItemPerFrameSliderSmoke->setSingleStep(1);
        nbMinItemPerFrameSliderSmoke->setPageStep(100);
        nbMinItemPerFrameSliderSmoke->setValue(1);
        nbMinItemPerFrameSliderSmoke->setOrientation(Qt::Horizontal);
        label_11 = new QLabel(ItemPerFrameGB);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 70, 111, 20));
        label_12 = new QLabel(smokeTab);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 120, 81, 20));
        genTimerSliderSmoke = new QSlider(smokeTab);
        genTimerSliderSmoke->setObjectName(QString::fromUtf8("genTimerSliderSmoke"));
        genTimerSliderSmoke->setGeometry(QRect(10, 140, 211, 22));
        genTimerSliderSmoke->setMinimum(1);
        genTimerSliderSmoke->setMaximum(3000);
        genTimerSliderSmoke->setValue(1);
        genTimerSliderSmoke->setOrientation(Qt::Horizontal);
        genTimerSmokeValue = new QLabel(smokeTab);
        genTimerSmokeValue->setObjectName(QString::fromUtf8("genTimerSmokeValue"));
        genTimerSmokeValue->setGeometry(QRect(130, 120, 46, 13));
        controlSelector->addTab(smokeTab, QString());
        fountainTab = new QWidget();
        fountainTab->setObjectName(QString::fromUtf8("fountainTab"));
        centerFountainValue = new QLabel(fountainTab);
        centerFountainValue->setObjectName(QString::fromUtf8("centerFountainValue"));
        centerFountainValue->setGeometry(QRect(60, 240, 46, 13));
        centerFountainValue->setAcceptDrops(true);
        centerXFountainSpinbox = new QSpinBox(fountainTab);
        centerXFountainSpinbox->setObjectName(QString::fromUtf8("centerXFountainSpinbox"));
        centerXFountainSpinbox->setGeometry(QRect(40, 260, 42, 22));
        centerXFountainSpinbox->setMinimum(-1000);
        centerXFountainSpinbox->setMaximum(1000);
        centerXFountainSpinbox->setSingleStep(1);
        nbItemFountainValue = new QLabel(fountainTab);
        nbItemFountainValue->setObjectName(QString::fromUtf8("nbItemFountainValue"));
        nbItemFountainValue->setGeometry(QRect(90, 60, 46, 13));
        nbItemPerFrameFountainValue = new QLabel(fountainTab);
        nbItemPerFrameFountainValue->setObjectName(QString::fromUtf8("nbItemPerFrameFountainValue"));
        nbItemPerFrameFountainValue->setGeometry(QRect(110, 120, 46, 13));
        Velocity_2 = new QGroupBox(fountainTab);
        Velocity_2->setObjectName(QString::fromUtf8("Velocity_2"));
        Velocity_2->setGeometry(QRect(10, 430, 211, 131));
        velocityMinSliderFountain = new QSlider(Velocity_2);
        velocityMinSliderFountain->setObjectName(QString::fromUtf8("velocityMinSliderFountain"));
        velocityMinSliderFountain->setGeometry(QRect(10, 50, 191, 22));
        velocityMinSliderFountain->setMinimum(1);
        velocityMinSliderFountain->setMaximum(20);
        velocityMinSliderFountain->setPageStep(11);
        velocityMinSliderFountain->setOrientation(Qt::Horizontal);
        label_39 = new QLabel(Velocity_2);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(120, 20, 21, 21));
        velocityMaxFountainValue = new QLabel(Velocity_2);
        velocityMaxFountainValue->setObjectName(QString::fromUtf8("velocityMaxFountainValue"));
        velocityMaxFountainValue->setGeometry(QRect(150, 20, 46, 13));
        label_40 = new QLabel(Velocity_2);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(30, 20, 21, 21));
        velocityMinFountainValue = new QLabel(Velocity_2);
        velocityMinFountainValue->setObjectName(QString::fromUtf8("velocityMinFountainValue"));
        velocityMinFountainValue->setGeometry(QRect(60, 20, 46, 13));
        velocityMaxSliderFountain = new QSlider(Velocity_2);
        velocityMaxSliderFountain->setObjectName(QString::fromUtf8("velocityMaxSliderFountain"));
        velocityMaxSliderFountain->setGeometry(QRect(10, 80, 191, 22));
        velocityMaxSliderFountain->setMinimum(1);
        velocityMaxSliderFountain->setMaximum(20);
        velocityMaxSliderFountain->setValue(4);
        velocityMaxSliderFountain->setOrientation(Qt::Horizontal);
        frameTimeSliderFountain = new QSlider(fountainTab);
        frameTimeSliderFountain->setObjectName(QString::fromUtf8("frameTimeSliderFountain"));
        frameTimeSliderFountain->setGeometry(QRect(10, 200, 211, 22));
        frameTimeSliderFountain->setMinimum(10);
        frameTimeSliderFountain->setMaximum(100);
        frameTimeSliderFountain->setValue(33);
        frameTimeSliderFountain->setOrientation(Qt::Horizontal);
        radiusSliderFountain = new QSlider(fountainTab);
        radiusSliderFountain->setObjectName(QString::fromUtf8("radiusSliderFountain"));
        radiusSliderFountain->setGeometry(QRect(10, 30, 211, 22));
        radiusSliderFountain->setMinimum(1);
        radiusSliderFountain->setValue(4);
        radiusSliderFountain->setOrientation(Qt::Horizontal);
        line_2 = new QFrame(fountainTab);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(220, 0, 20, 681));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        Size_2 = new QGroupBox(fountainTab);
        Size_2->setObjectName(QString::fromUtf8("Size_2"));
        Size_2->setGeometry(QRect(240, 10, 211, 131));
        sizeMinSliderFountain = new QSlider(Size_2);
        sizeMinSliderFountain->setObjectName(QString::fromUtf8("sizeMinSliderFountain"));
        sizeMinSliderFountain->setGeometry(QRect(10, 50, 191, 22));
        sizeMinSliderFountain->setMinimum(1);
        sizeMinSliderFountain->setMaximum(15);
        sizeMinSliderFountain->setOrientation(Qt::Horizontal);
        label_19 = new QLabel(Size_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(120, 20, 21, 21));
        sizeMaxFountainValue = new QLabel(Size_2);
        sizeMaxFountainValue->setObjectName(QString::fromUtf8("sizeMaxFountainValue"));
        sizeMaxFountainValue->setGeometry(QRect(150, 20, 46, 13));
        label_20 = new QLabel(Size_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(30, 20, 21, 21));
        sizeMinFountainValue = new QLabel(Size_2);
        sizeMinFountainValue->setObjectName(QString::fromUtf8("sizeMinFountainValue"));
        sizeMinFountainValue->setGeometry(QRect(60, 20, 46, 13));
        sizeMaxSliderFountain = new QSlider(Size_2);
        sizeMaxSliderFountain->setObjectName(QString::fromUtf8("sizeMaxSliderFountain"));
        sizeMaxSliderFountain->setGeometry(QRect(10, 80, 191, 22));
        sizeMaxSliderFountain->setMinimum(1);
        sizeMaxSliderFountain->setMaximum(15);
        sizeMaxSliderFountain->setOrientation(Qt::Horizontal);
        nbItemPerFrameSliderFountain = new QSlider(fountainTab);
        nbItemPerFrameSliderFountain->setObjectName(QString::fromUtf8("nbItemPerFrameSliderFountain"));
        nbItemPerFrameSliderFountain->setGeometry(QRect(10, 140, 211, 22));
        nbItemPerFrameSliderFountain->setMinimum(100);
        nbItemPerFrameSliderFountain->setMaximum(3000);
        nbItemPerFrameSliderFountain->setSingleStep(100);
        nbItemPerFrameSliderFountain->setPageStep(100);
        nbItemPerFrameSliderFountain->setValue(300);
        nbItemPerFrameSliderFountain->setOrientation(Qt::Horizontal);
        radiusFountainValue = new QLabel(fountainTab);
        radiusFountainValue->setObjectName(QString::fromUtf8("radiusFountainValue"));
        radiusFountainValue->setGeometry(QRect(80, 10, 46, 13));
        label_41 = new QLabel(fountainTab);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(20, 60, 61, 20));
        label_42 = new QLabel(fountainTab);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(15, 180, 81, 20));
        label_43 = new QLabel(fountainTab);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(20, 120, 81, 20));
        frameTimeFountainValue = new QLabel(fountainTab);
        frameTimeFountainValue->setObjectName(QString::fromUtf8("frameTimeFountainValue"));
        frameTimeFountainValue->setGeometry(QRect(100, 180, 46, 13));
        centerZFountainSpinbox = new QSpinBox(fountainTab);
        centerZFountainSpinbox->setObjectName(QString::fromUtf8("centerZFountainSpinbox"));
        centerZFountainSpinbox->setGeometry(QRect(140, 260, 42, 22));
        centerZFountainSpinbox->setMinimum(-1000);
        centerZFountainSpinbox->setMaximum(1000);
        centerZFountainSpinbox->setSingleStep(1);
        label_44 = new QLabel(fountainTab);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(15, 240, 51, 20));
        nbItemSliderFountain = new QSlider(fountainTab);
        nbItemSliderFountain->setObjectName(QString::fromUtf8("nbItemSliderFountain"));
        nbItemSliderFountain->setEnabled(false);
        nbItemSliderFountain->setGeometry(QRect(10, 80, 211, 22));
        nbItemSliderFountain->setMinimum(1000);
        nbItemSliderFountain->setMaximum(60000);
        nbItemSliderFountain->setSingleStep(1000);
        nbItemSliderFountain->setValue(10000);
        nbItemSliderFountain->setOrientation(Qt::Horizontal);
        label_45 = new QLabel(fountainTab);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(20, 10, 46, 13));
        setValuesButtonFountain = new QPushButton(fountainTab);
        setValuesButtonFountain->setObjectName(QString::fromUtf8("setValuesButtonFountain"));
        setValuesButtonFountain->setGeometry(QRect(270, 360, 141, 101));
        centerYFountainSpinbox = new QSpinBox(fountainTab);
        centerYFountainSpinbox->setObjectName(QString::fromUtf8("centerYFountainSpinbox"));
        centerYFountainSpinbox->setGeometry(QRect(90, 260, 42, 22));
        centerYFountainSpinbox->setMinimum(-1000);
        centerYFountainSpinbox->setMaximum(1000);
        centerYFountainSpinbox->setSingleStep(1);
        lifetime_2 = new QGroupBox(fountainTab);
        lifetime_2->setObjectName(QString::fromUtf8("lifetime_2"));
        lifetime_2->setGeometry(QRect(10, 300, 211, 131));
        lifetimeMinSliderFountain = new QSlider(lifetime_2);
        lifetimeMinSliderFountain->setObjectName(QString::fromUtf8("lifetimeMinSliderFountain"));
        lifetimeMinSliderFountain->setGeometry(QRect(10, 50, 191, 22));
        lifetimeMinSliderFountain->setMinimum(200);
        lifetimeMinSliderFountain->setMaximum(5000);
        lifetimeMinSliderFountain->setSingleStep(100);
        lifetimeMinSliderFountain->setPageStep(100);
        lifetimeMinSliderFountain->setValue(1000);
        lifetimeMinSliderFountain->setOrientation(Qt::Horizontal);
        label_48 = new QLabel(lifetime_2);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(120, 20, 21, 21));
        lifetimeMaxFountainValue = new QLabel(lifetime_2);
        lifetimeMaxFountainValue->setObjectName(QString::fromUtf8("lifetimeMaxFountainValue"));
        lifetimeMaxFountainValue->setGeometry(QRect(150, 20, 46, 13));
        label_49 = new QLabel(lifetime_2);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(30, 20, 21, 21));
        lifetimeMinFountainValue = new QLabel(lifetime_2);
        lifetimeMinFountainValue->setObjectName(QString::fromUtf8("lifetimeMinFountainValue"));
        lifetimeMinFountainValue->setGeometry(QRect(60, 20, 46, 13));
        lifetimeMaxSliderFountain = new QSlider(lifetime_2);
        lifetimeMaxSliderFountain->setObjectName(QString::fromUtf8("lifetimeMaxSliderFountain"));
        lifetimeMaxSliderFountain->setGeometry(QRect(10, 80, 191, 22));
        lifetimeMaxSliderFountain->setMinimum(200);
        lifetimeMaxSliderFountain->setMaximum(5000);
        lifetimeMaxSliderFountain->setSingleStep(100);
        lifetimeMaxSliderFountain->setPageStep(100);
        lifetimeMaxSliderFountain->setValue(3000);
        lifetimeMaxSliderFountain->setOrientation(Qt::Horizontal);
        label_46 = new QLabel(fountainTab);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(250, 160, 46, 13));
        directionXFountainSpinbox = new QSpinBox(fountainTab);
        directionXFountainSpinbox->setObjectName(QString::fromUtf8("directionXFountainSpinbox"));
        directionXFountainSpinbox->setGeometry(QRect(250, 180, 42, 22));
        directionXFountainSpinbox->setMinimum(-1000);
        directionXFountainSpinbox->setMaximum(1000);
        directionXFountainSpinbox->setSingleStep(1);
        directionZFountainSpinbox = new QSpinBox(fountainTab);
        directionZFountainSpinbox->setObjectName(QString::fromUtf8("directionZFountainSpinbox"));
        directionZFountainSpinbox->setGeometry(QRect(350, 180, 42, 22));
        directionZFountainSpinbox->setMinimum(-1000);
        directionZFountainSpinbox->setMaximum(1000);
        directionZFountainSpinbox->setSingleStep(1);
        directionYFountainSpinbox = new QSpinBox(fountainTab);
        directionYFountainSpinbox->setObjectName(QString::fromUtf8("directionYFountainSpinbox"));
        directionYFountainSpinbox->setGeometry(QRect(300, 180, 42, 22));
        directionYFountainSpinbox->setMinimum(-1000);
        directionYFountainSpinbox->setMaximum(1000);
        directionYFountainSpinbox->setSingleStep(1);
        controlSelector->addTab(fountainTab, QString());
        fpsValue = new QLabel(centralwidget);
        fpsValue->setObjectName(QString::fromUtf8("fpsValue"));
        fpsValue->setGeometry(QRect(680, 0, 51, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        fpsValue->setFont(font);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(640, 10, 31, 16));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        label_6->setFont(font1);
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
        QObject::connect(radiusSliderSmoke, SIGNAL(valueChanged(int)), radiusSmokeValue, SLOT(setNum(int)));
        QObject::connect(genTimerSliderSmoke, SIGNAL(valueChanged(int)), genTimerSmokeValue, SLOT(setNum(int)));
        QObject::connect(frameTimeSliderSmoke, SIGNAL(valueChanged(int)), frameTimeSmokeValue, SLOT(setNum(int)));
        QObject::connect(lifetimeMinSliderSmoke, SIGNAL(valueChanged(int)), lifetimeMinSmokeValue, SLOT(setNum(int)));
        QObject::connect(lifetimeMaxSliderSmoke, SIGNAL(valueChanged(int)), lifetimeMaxSmokeValue, SLOT(setNum(int)));
        QObject::connect(velocityMaxSliderSmoke, SIGNAL(valueChanged(int)), velocityMaxSmokeValue, SLOT(setNum(int)));
        QObject::connect(velocityMinSliderSmoke, SIGNAL(valueChanged(int)), velocityMinSmokeValue, SLOT(setNum(int)));
        QObject::connect(coefSizeSliderSmoke, SIGNAL(valueChanged(int)), coefSizeSmokeValue, SLOT(setNum(int)));
        QObject::connect(nbMaxItemPerFrameSliderSmoke, SIGNAL(valueChanged(int)), nbMaxItemPerFrameSmoke, SLOT(setNum(int)));
        QObject::connect(nbMinItemPerFrameSliderSmoke, SIGNAL(valueChanged(int)), nbMinItemPerFrameSmoke, SLOT(setNum(int)));
        QObject::connect(nbItemPerFrameSliderFountain, SIGNAL(valueChanged(int)), nbItemPerFrameFountainValue, SLOT(setNum(int)));
        QObject::connect(radiusSliderFountain, SIGNAL(valueChanged(int)), radiusFountainValue, SLOT(setNum(int)));
        QObject::connect(nbItemSliderFountain, SIGNAL(valueChanged(int)), nbItemFountainValue, SLOT(setNum(int)));
        QObject::connect(frameTimeSliderFountain, SIGNAL(valueChanged(int)), frameTimeFountainValue, SLOT(setNum(int)));
        QObject::connect(lifetimeMaxSliderFountain, SIGNAL(valueChanged(int)), lifetimeMaxFountainValue, SLOT(setNum(int)));
        QObject::connect(lifetimeMinSliderFountain, SIGNAL(valueChanged(int)), lifetimeMinFountainValue, SLOT(setNum(int)));
        QObject::connect(velocityMaxSliderFountain, SIGNAL(valueChanged(int)), velocityMaxFountainValue, SLOT(setNum(int)));
        QObject::connect(velocityMinSliderFountain, SIGNAL(valueChanged(int)), velocityMinFountainValue, SLOT(setNum(int)));
        QObject::connect(sizeMaxSliderFountain, SIGNAL(valueChanged(int)), sizeMaxFountainValue, SLOT(setNum(int)));

        controlSelector->setCurrentIndex(2);


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
        velocityMaxFireValue->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "min", 0, QApplication::UnicodeUTF8));
        velocityMinFireValue->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        ageAttenuation->setTitle(QApplication::translate("MainWindow", "Age Attenuation", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "limit", 0, QApplication::UnicodeUTF8));
        ageAttenuationLimitFireValue->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "factor", 0, QApplication::UnicodeUTF8));
        ageAttenuationFactorFireValue->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        setValuesButton->setText(QApplication::translate("MainWindow", "Set up values", 0, QApplication::UnicodeUTF8));
        controlSelector->setTabText(controlSelector->indexOf(fireTab), QApplication::translate("MainWindow", "Fire", 0, QApplication::UnicodeUTF8));
        centerSmokeValue->setText(QApplication::translate("MainWindow", "(0,0,0)", 0, QApplication::UnicodeUTF8));
        nbItemSmokeValue->setText(QApplication::translate("MainWindow", "10000", 0, QApplication::UnicodeUTF8));
        VelocitySmokeFrame->setTitle(QApplication::translate("MainWindow", "Velocity", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("MainWindow", "max", 0, QApplication::UnicodeUTF8));
        velocityMaxSmokeValue->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("MainWindow", "min", 0, QApplication::UnicodeUTF8));
        velocityMinSmokeValue->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        SizeSmokeFrame->setTitle(QApplication::translate("MainWindow", "Size", 0, QApplication::UnicodeUTF8));
        coefSizeSmokeLabel->setText(QApplication::translate("MainWindow", "coef", 0, QApplication::UnicodeUTF8));
        coefSizeSmokeValue->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        radiusSmokeValue->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Nb particles", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "FrameTime (ms)", 0, QApplication::UnicodeUTF8));
        frameTimeSmokeValue->setText(QApplication::translate("MainWindow", "33", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Center", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Radius", 0, QApplication::UnicodeUTF8));
        setValuesButtonSmoke->setText(QApplication::translate("MainWindow", "Set up values", 0, QApplication::UnicodeUTF8));
        lifetimeSmoke->setTitle(QApplication::translate("MainWindow", "Lifetime (ms)", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("MainWindow", "max", 0, QApplication::UnicodeUTF8));
        lifetimeMaxSmokeValue->setText(QApplication::translate("MainWindow", "3000", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("MainWindow", "min", 0, QApplication::UnicodeUTF8));
        lifetimeMinSmokeValue->setText(QApplication::translate("MainWindow", "1000", 0, QApplication::UnicodeUTF8));
        ItemPerFrameGB->setTitle(QApplication::translate("MainWindow", "ItemGeneration", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "NbItemPerFrameMax", 0, QApplication::UnicodeUTF8));
        nbMaxItemPerFrameSmoke->setText(QApplication::translate("MainWindow", "300", 0, QApplication::UnicodeUTF8));
        nbMinItemPerFrameSmoke->setText(QApplication::translate("MainWindow", "300", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "NbItemPerFrameMin", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "GenTimer (ms)", 0, QApplication::UnicodeUTF8));
        genTimerSmokeValue->setText(QApplication::translate("MainWindow", "33", 0, QApplication::UnicodeUTF8));
        controlSelector->setTabText(controlSelector->indexOf(smokeTab), QApplication::translate("MainWindow", "Smoke", 0, QApplication::UnicodeUTF8));
        centerFountainValue->setText(QApplication::translate("MainWindow", "(0,0,0)", 0, QApplication::UnicodeUTF8));
        nbItemFountainValue->setText(QApplication::translate("MainWindow", "10000", 0, QApplication::UnicodeUTF8));
        nbItemPerFrameFountainValue->setText(QApplication::translate("MainWindow", "300", 0, QApplication::UnicodeUTF8));
        Velocity_2->setTitle(QApplication::translate("MainWindow", "Velocity", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("MainWindow", "max", 0, QApplication::UnicodeUTF8));
        velocityMaxFountainValue->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("MainWindow", "min", 0, QApplication::UnicodeUTF8));
        velocityMinFountainValue->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        Size_2->setTitle(QApplication::translate("MainWindow", "Size", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "max", 0, QApplication::UnicodeUTF8));
        sizeMaxFountainValue->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "min", 0, QApplication::UnicodeUTF8));
        sizeMinFountainValue->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        radiusFountainValue->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("MainWindow", "Nb particles", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("MainWindow", "FrameTime (ms)", 0, QApplication::UnicodeUTF8));
        label_43->setText(QApplication::translate("MainWindow", "NbItemPerFrame", 0, QApplication::UnicodeUTF8));
        frameTimeFountainValue->setText(QApplication::translate("MainWindow", "33", 0, QApplication::UnicodeUTF8));
        label_44->setText(QApplication::translate("MainWindow", "Center", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("MainWindow", "Radius", 0, QApplication::UnicodeUTF8));
        setValuesButtonFountain->setText(QApplication::translate("MainWindow", "Set up values", 0, QApplication::UnicodeUTF8));
        lifetime_2->setTitle(QApplication::translate("MainWindow", "Lifetime (ms)", 0, QApplication::UnicodeUTF8));
        label_48->setText(QApplication::translate("MainWindow", "max", 0, QApplication::UnicodeUTF8));
        lifetimeMaxFountainValue->setText(QApplication::translate("MainWindow", "3000", 0, QApplication::UnicodeUTF8));
        label_49->setText(QApplication::translate("MainWindow", "min", 0, QApplication::UnicodeUTF8));
        lifetimeMinFountainValue->setText(QApplication::translate("MainWindow", "1000", 0, QApplication::UnicodeUTF8));
        label_46->setText(QApplication::translate("MainWindow", "Direction", 0, QApplication::UnicodeUTF8));
        controlSelector->setTabText(controlSelector->indexOf(fountainTab), QApplication::translate("MainWindow", "Fountain", 0, QApplication::UnicodeUTF8));
        fpsValue->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "FPS", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
