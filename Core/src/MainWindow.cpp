
#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "App.h"
#include "fire.h"
#include "Vectors.h"

#include <QSpinBox>
#include <QLabel>
#include <iostream>

using namespace std;

void MainWindow::keyPressEvent(QKeyEvent * event) {
    /* just redirect event to app */
    if(ui->app!=NULL) {
        ui->app->keyPressEvent(event);
    }
}





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* radius */
    connect(ui->radiusSliderFire, SIGNAL(valueChanged(int)), this,SLOT(onRadiusChanged(int)));
    connect(ui->radiusSliderSmoke, SIGNAL(valueChanged(int)), this,SLOT(onRadiusChanged(int)));

    /* nbitem & nbitemperframe */
    connect(ui->nbItemSliderFire, SIGNAL(valueChanged(int)), this,SLOT(onNbItemChanged(int)));
    connect(ui->nbItemPerFrameSliderFire, SIGNAL(valueChanged(int)), this,SLOT(onNbItemPerFrameChanged(int)));

    connect(ui->nbMaxItemPerFrameSliderSmoke, SIGNAL(valueChanged(int)), this,SLOT(onNbMaxItemPerFrameChanged(int)));
    connect(ui->nbMinItemPerFrameSliderSmoke, SIGNAL(valueChanged(int)), this,SLOT(onNbMinItemPerFrameChanged(int)));
    connect(ui->genTimerSliderSmoke, SIGNAL(valueChanged(int)), this,SLOT(onUpdateTimerChanged(int)));

    /* frametime */
    connect(ui->frameTimeSliderFire, SIGNAL(valueChanged(int)), this,SLOT(onFrametimeChanged(int)));
    connect(ui->frameTimeSliderSmoke, SIGNAL(valueChanged(int)), this,SLOT(onFrametimeChanged(int)));

    /* factor age attenuation */
    connect(ui->ageAttenuationFactorSliderFire, SIGNAL(valueChanged(int)), this,SLOT(ageAttenuationFactorChanged(int)));
    connect(ui->ageAttenuationLimitSliderFire, SIGNAL(valueChanged(int)), this,SLOT(ageAttenuationLimitChanged(int)));

    /* center */
    connect(ui->centerXFireSpinbox, SIGNAL(valueChanged(int)), this,SLOT(onCenterChanged(int)));
    connect(ui->centerXSmokeSpinbox, SIGNAL(valueChanged(int)), this,SLOT(onCenterChanged(int)));

    connect(ui->centerYFireSpinbox, SIGNAL(valueChanged(int)), this,SLOT(onCenterChanged(int)));
    connect(ui->centerYSmokeSpinbox, SIGNAL(valueChanged(int)), this,SLOT(onCenterChanged(int)));

    connect(ui->centerZFireSpinbox, SIGNAL(valueChanged(int)), this,SLOT(onCenterChanged(int)));
    connect(ui->centerZSmokeSpinbox, SIGNAL(valueChanged(int)), this,SLOT(onCenterChanged(int)));

    /* lifetime */
    connect(ui->lifetimeMaxSliderFire_4, SIGNAL(valueChanged(int)), this,SLOT(onLifetimeChanged(int)));
    connect(ui->lifetimeMinSliderFire_4, SIGNAL(valueChanged(int)), this,SLOT(onLifetimeChanged(int)));

    connect(ui->lifetimeMinSliderSmoke, SIGNAL(valueChanged(int)), this,SLOT(onLifetimeChanged(int)));
    connect(ui->lifetimeMaxSliderSmoke, SIGNAL(valueChanged(int)), this,SLOT(onLifetimeChanged(int)));

    /* velocity */
    connect(ui->velocityMinSliderFire, SIGNAL(valueChanged(int)), this,SLOT(onVelocityChanged(int)));
    connect(ui->velocityMaxSliderFire, SIGNAL(valueChanged(int)), this,SLOT(onVelocityChanged(int)));

    connect(ui->velocityMaxSliderSmoke, SIGNAL(valueChanged(int)), this,SLOT(onVelocityChanged(int)));
    connect(ui->velocityMinSliderSmoke, SIGNAL(valueChanged(int)), this,SLOT(onVelocityChanged(int)));

    /* size */
    connect(ui->sizeMaxSliderFire, SIGNAL(valueChanged(int)), this,SLOT(onSizeChanged(int)));
    connect(ui->sizeMinSliderFire, SIGNAL(valueChanged(int)), this,SLOT(onSizeChanged(int)));

    connect(ui->coefSizeSliderSmoke, SIGNAL(valueChanged(int)), this,SLOT(onSizeChanged(int)));

    connect(ui->setValuesButton, SIGNAL(clicked()), this, SLOT(setCurrentValues()));
    connect(ui->setValuesButtonSmoke, SIGNAL(clicked()), this, SLOT(setCurrentValues()));

}


void MainWindow::onCenterChanged(int) {
    int tab = ui->controlSelector->currentIndex();
    if(tab == 0) {
        QSpinBox * x = ui->centerXFireSpinbox;
        QSpinBox * y = ui->centerYFireSpinbox;
        QSpinBox * z = ui->centerZFireSpinbox;
        QString centerS = QString("(%1 %2 %3)").arg(QString::number(x->value()),QString::number(y->value()) ,QString::number(z->value()));
        ui->centerFireValue->setText(centerS);
        Fire * fire =  ui->app->getFire();
        if(fire)
            fire->setCenter(Vec3(x->value(),y->value(),z->value()));

    } else if (tab == 1){
        QSpinBox * x = ui->centerXSmokeSpinbox;
        QSpinBox * y = ui->centerYSmokeSpinbox;
        QSpinBox * z = ui->centerZSmokeSpinbox;
        QString centerS = QString("(%1 %2 %3)").arg(QString::number(x->value()),QString::number(y->value()) ,QString::number(z->value()));
        ui->centerSmokeValue->setText(centerS);
        Smoke * smoke =  ui->app->getSmoke();
        if(smoke)
            smoke->setCenter(Vec3(x->value(),y->value(),z->value()));
    } else if (tab == 2) {
//        QSpinBox * x = ui->centerXFountainSpinbox;
//        QSpinBox * y = ui->centerYFountainSpinbox;
//        QSpinBox * z = ui->centerZFountainSpinbox;
//        QString centerS = QString("(%1 %2 %3)").arg(QString::number(x->value()),QString::number(y->value()) ,QString::number(z->value()));
//        ui->centerFountainValue->setText(centerS);
//        Fountain * fountain =  ui->app->getFountain();
//        if(fountain)
//            fountain->setCenter(Vec3(x->value(),y->value(),z->value()));
    }
}


void MainWindow::onLifetimeChanged(int) {
    int tab = ui->controlSelector->currentIndex();
    if(tab == 0) {
        QSlider * min = ui->lifetimeMinSliderFire_4;
        QSlider * max = ui->lifetimeMaxSliderFire_4;

        QLabel * labMin = ui->lifetimeMinFireValue_4;
        QLabel * labMax = ui->lifetimeMaxFireValue_4;

        int minValue = min->value();
        int maxValue = max->value();

        if(minValue > maxValue) {
            maxValue = minValue;
            min->setValue(minValue);
            max->setValue(maxValue);
        }

        QString minS = QString::number(minValue);
        QString maxS = QString::number(maxValue);
        labMin->setText(minS);
        labMax->setText(maxS);

        Fire * fire =  ui->app->getFire();
        if(fire) {
            fire->setLifeTimeMin(minValue);
            fire->setLifeTimeMax(maxValue);
        }
    } else if (tab == 1){
        QSlider * min = ui->lifetimeMinSliderSmoke;
        QSlider * max = ui->lifetimeMaxSliderSmoke;

        QLabel * labMin = ui->lifetimeMinSmokeValue;
        QLabel * labMax = ui->lifetimeMaxSmokeValue;

        int minValue = min->value();
        int maxValue = max->value();

        if(minValue > maxValue) {
            maxValue = minValue;
            min->setValue(minValue);
            max->setValue(maxValue);
        }

        QString minS = QString::number(minValue);
        QString maxS = QString::number(maxValue);
        labMin->setText(minS);
        labMax->setText(maxS);

        Smoke * smoke =  ui->app->getSmoke();
        if(smoke) {
            smoke->setLifeTimeMin(minValue);
            smoke->setLifeTimeMax(maxValue);
        }
    } else if (tab == 2) {
//        QSlider * min = ui->lifetimeMinSliderFountain;
//        QSlider * max = ui->lifetimeMaxSliderFountain;

//        QLabel * labMin = ui->lifetimeMinFountainValue;
//        QLabel * labMax = ui->lifetimeMaxFountainValue;

//        int minValue = min->value();
//        int maxValue = max->value();

//        if(minValue > maxValue) {
//            maxValue = minValue;
//            min->setValue(minValue);
//            max->setValue(maxValue);
//        }

//        QString minS = QString::number(minValue);
//        QString maxS = QString::number(maxValue);
//        labMin->setText(minS);
//        labMax->setText(maxS);

//        Fountain * fountain =  ui->app->getFountain();
//        if(fountain) {
//            fountain->setLifeTimeMin(minValue);
//            fountain->setLifeTimeMax(maxValue);
//        }
    }
}




void MainWindow::onVelocityChanged(int) {
    int tab = ui->controlSelector->currentIndex();
    if(tab == 0) {
        QSlider * min = ui->velocityMinSliderFire;
        QSlider * max = ui->velocityMaxSliderFire;

        QLabel * labMin = ui->velocityMinFireValue;
        QLabel * labMax = ui->velocityMaxFireValue;

        int minValue = min->value();
        int maxValue = max->value();

        if(minValue > maxValue) {
            maxValue = minValue;
            min->setValue(minValue);
            max->setValue(maxValue);
        }

        QString minS = QString::number(minValue);
        QString maxS = QString::number(maxValue);
        labMin->setText(minS);
        labMax->setText(maxS);

        Fire * fire =  ui->app->getFire();
        if(fire) {
            fire->setVelocityMin(minValue);
            fire->setVelocityMax(maxValue);
        }
    } else if (tab == 1) {
        QSlider * min = ui->velocityMinSliderSmoke;
        QSlider * max = ui->velocityMaxSliderSmoke;

        QLabel * labMin = ui->velocityMinSmokeValue;
        QLabel * labMax = ui->velocityMaxSmokeValue;

        int minValue = min->value();
        int maxValue = max->value();

        if(minValue > maxValue) {
            maxValue = minValue;
            min->setValue(minValue);
            max->setValue(maxValue);
        }

        QString minS = QString::number(minValue);
        QString maxS = QString::number(maxValue);
        labMin->setText(minS);
        labMax->setText(maxS);

        Smoke * smoke =  ui->app->getSmoke();
        if(smoke) {
            smoke->setVelocityMin(minValue);
            smoke->setVelocityMax(maxValue);
        }
    } else if (tab == 2) {
//        QSlider * min = ui->velocityMinSliderFountain;
//        QSlider * max = ui->velocityMaxSliderFountain;

//        QLabel * labMin = ui->velocityMinFountainValue;
//        QLabel * labMax = ui->velocityMaxFountainValue;

//        int minValue = min->value();
//        int maxValue = max->value();

//        if(minValue > maxValue) {
//            maxValue = minValue;
//            min->setValue(minValue);
//            max->setValue(maxValue);
//        }

//        QString minS = QString::number(minValue);
//        QString maxS = QString::number(maxValue);
//        labMin->setText(minS);
//        labMax->setText(maxS);

//        Fountain * fountain =  ui->app->getFountain();
//        if(fountain) {
//            fountain->setVelocityMin(minValue);
//            fountain->setVelocityMax(maxValue);
//        }
    }
}


void MainWindow::onSizeChanged(int) {
    int tab = ui->controlSelector->currentIndex();
    if(tab == 0) {
        QSlider * min = ui->sizeMinSliderFire;
        QSlider * max = ui->sizeMaxSliderFire;

        QLabel * labMin = ui->sizeMinFireValue;
        QLabel * labMax = ui->sizeMaxFireValue;

        int minValue = min->value();
        int maxValue = max->value();

        if(minValue > maxValue) {
            maxValue = minValue;
            min->setValue(minValue);
            max->setValue(maxValue);
        }

        QString minS = QString::number(minValue);
        QString maxS = QString::number(maxValue);
        labMin->setText(minS);
        labMax->setText(maxS);

        Fire * fire =  ui->app->getFire();
        if(fire) {
            fire->setSizeMin(minValue);
            fire->setSizeMax(maxValue);
        }
    } else if (tab == 1){
        QSlider * coef = ui->coefSizeSliderSmoke;
        QString coefs = QString::number(coef->value());
        ui->coefSizeSmokeLabel->setText(coefs);

        Smoke * smoke =  ui->app->getSmoke();
        if(smoke) {
            smoke->setSizeMaxCoef(coef->value());
        }
    } else if (tab == 2){
//        QSlider * min = ui->sizeMinSliderFountain;
//        QSlider * max = ui->sizeMaxSliderFountain;

//        QLabel * labMin = ui->sizeMinFountainValue;
//        QLabel * labMax = ui->sizeMaxFountainValue;

//        int minValue = min->value();
//        int maxValue = max->value();

//        if(minValue > maxValue) {
//            maxValue = minValue;
//            min->setValue(minValue);
//            max->setValue(maxValue);
//        }

//        QString minS = QString::number(minValue);
//        QString maxS = QString::number(maxValue);
//        labMin->setText(minS);
//        labMax->setText(maxS);

//        Fountain * fountain =  ui->app->getFountain();
//        if(fountain) {
//            fountain->setSizeMin(minValue);
//            fountain->setSizeMax(maxValue);
//        }
    }

}

void MainWindow::onRadiusChanged(int new_radius) {
    int tab = ui->controlSelector->currentIndex();
    if(tab == 0) {
            Fire * fire =  ui->app->getFire();
            if(fire)
                fire->setRadius((float) new_radius);
    } else if(tab == 1){
        Smoke * smoke =  ui->app->getSmoke();
        if(smoke)
            smoke->setRadius((float) new_radius);
    }   else if(tab == 2){
        Fountain * fountain =  ui->app->getFountain();
        if(fountain)
            fountain->setRadius((float) new_radius);
    }

}

void MainWindow::onNbItemChanged(int nbitem) {
    int tab = ui->controlSelector->currentIndex();
    if(tab == 0) {
        Fire * fire =  ui->app->getFire();
        cout << "setting nbitem:" << nbitem << endl;
        if(fire)
            fire->setNbItem(nbitem);
    } else if(tab == 1)
    {

    } else if (tab == 2) {

    }
}


void MainWindow::onNbItemPerFrameChanged(int nbitemperframe) {
    int tab = ui->controlSelector->currentIndex();
    if(tab == 0) {
        Fire * fire =  ui->app->getFire();
        if(fire)
            fire->setNbItemPerFrame(nbitemperframe);
    } else if(tab == 2) {
        Fountain * fountain =  ui->app->getFountain();
        if(fountain)
            fountain->setNbItemPerFrame(nbitemperframe);
    }
}


void MainWindow::onFrametimeChanged(int frametime) {
    int tab = ui->controlSelector->currentIndex();
    if(tab == 0) {
        Fire * fire =  ui->app->getFire();
        if(fire)
            fire->setFrameTime(frametime);
    } else if (tab == 1) {
        Smoke * smoke =  ui->app->getSmoke();
        if(smoke)
            smoke->setFrameTime(frametime);
    } else if (tab == 2) {
        Fountain * fountain =  ui->app->getFountain();
        if(fountain)
            fountain->setFrameTime(frametime);
    }
}

void MainWindow::ageAttenuationFactorChanged(int factor) {
    if(ui->controlSelector->currentIndex() == 0) {
        ui->ageAttenuationFactorFireValue->setText(QString::number(( ((float)factor )/100)));
        Fire * fire =  ui->app->getFire();
        if(fire)
            fire->setAtenuationFactor( ((float)factor )/100);
    }
}



void MainWindow::ageAttenuationLimitChanged(int limit) {
    if(ui->controlSelector->currentIndex() == 0) {
        ui->ageAttenuationLimitFireValue->setText(QString::number(( ((float)limit )/100)));
        Fire * fire =  ui->app->getFire();
        if(fire)
            fire->setAtenuationLimit( ((float)limit )/100);
    }
}


void MainWindow::setCurrentValues() {
    int tab = ui->controlSelector->currentIndex();
    if(tab == 0) {
        Fire * fire =  ui->app->getFire();
        if(fire) {
            ui->ageAttenuationFactorSliderFire->setValue(fire->getAgeAtenuationFactor() * 100);
            ui->ageAttenuationLimitSliderFire->setValue(fire->getAgeAtenuationLimit() * 100);
            ui->radiusSliderFire->setValue(fire->getRadius());
            ui->frameTimeSliderFire->setValue(fire->getFrameTime());

            ui->lifetimeMaxSliderFire_4->setValue(fire->getLifeTimeMax());
            ui->lifetimeMinSliderFire_4->setValue(fire->getLifeTimeMin());

            cout << "vel mac!" << fire->getSizeMin() <<endl;
            ui->velocityMaxSliderFire->setValue((float) fire->getVelocityMax());
            ui->velocityMinSliderFire->setValue((float) fire->getVelocityMin());

            ui->sizeMaxSliderFire->setValue(fire->getSizeMax());
            ui->sizeMinSliderFire->setValue(fire->getSizeMin());

            ui->nbItemPerFrameSliderFire->setValue(fire->getNbItemPerFrame());
            ui->nbItemSliderFire->setValue(fire->getNbItem());

            Vec3 center = fire->getCenter();
            ui->centerXFireSpinbox->setValue(center.x);
            ui->centerYFireSpinbox->setValue(center.y);
            ui->centerZFireSpinbox->setValue(center.z);
        }
    } else if(tab == 1) {
        Smoke * smoke =  ui->app->getSmoke();
        if(smoke) {
            ui->radiusSliderSmoke->setValue(smoke->getRadius());
            ui->frameTimeSliderSmoke->setValue(smoke->getFrameTime());

            ui->lifetimeMaxSliderSmoke->setValue(smoke->getLifeTimeMax());
            ui->lifetimeMinSliderSmoke->setValue(smoke->getLifeTimeMin());

            cout << "vel mac!" << smoke->getSizeMin() <<endl;
            ui->velocityMaxSliderSmoke->setValue((float) smoke->getVelocityMax());
            ui->velocityMinSliderSmoke->setValue((float) smoke->getVelocityMin());

//            ui->sizeMaxSliderSmoke->setValue(smoke->getSizeMax());
//            ui->sizeMinSliderSmoke->setValue(smoke->getSizeMin());
            ui->coefSizeSliderSmoke->setValue(smoke->getSizeMaxCoef());

            ui->nbMaxItemPerFrameSliderSmoke->setValue(smoke->getItemPerFrameMax());
            ui->nbMinItemPerFrameSliderSmoke->setValue(smoke->getItemPerFrameMin());

            ui->genTimerSliderSmoke->setValue(smoke->getUpdateNbItemTimer());

            Vec3 center = smoke->getCenter();
            ui->centerXSmokeSpinbox->setValue(center.x);
            ui->centerYSmokeSpinbox->setValue(center.y);
            ui->centerZSmokeSpinbox->setValue(center.z);
        }
    } else if(tab == 2) {

    }
}


void MainWindow::onNbMaxItemPerFrameChanged(int newValue){
    if(ui->app->getSmoke() != NULL) {
        Smoke* smoke = ui->app->getSmoke();
        if(newValue >= ui->nbMinItemPerFrameSliderSmoke->value())
            smoke->setItemPerFrameMax(newValue);
        else {
            smoke->setItemPerFrameMax(ui->nbMinItemPerFrameSliderSmoke->value());
            ui->nbMaxItemPerFrameSliderSmoke->setValue(ui->nbMinItemPerFrameSliderSmoke->value());
        }
    }
}

void MainWindow::onNbMinItemPerFrameChanged(int newValue){
    if(ui->app->getSmoke() != NULL) {
        Smoke* smoke = ui->app->getSmoke();
        if(newValue <= ui->nbMaxItemPerFrameSliderSmoke->value())
            smoke->setItemPerFrameMin(newValue);
        else {
            smoke->setItemPerFrameMin(ui->nbMaxItemPerFrameSliderSmoke->value());
            ui->nbMinItemPerFrameSliderSmoke->setValue(ui->nbMaxItemPerFrameSliderSmoke->value());
        }
    }
}

void MainWindow::onUpdateTimerChanged(int newValue) {
    if(ui->app->getSmoke() != NULL) {
        Smoke* smoke = ui->app->getSmoke();
        smoke->setUpdateNbItemTimer(newValue);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
