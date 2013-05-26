
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

    /* nbitem & nbitemperframe */
    connect(ui->nbItemSliderFire, SIGNAL(valueChanged(int)), this,SLOT(onNbItemChanged(int)));
    connect(ui->nbItemPerFrameSliderFire, SIGNAL(valueChanged(int)), this,SLOT(onNbItemPerFrameChanged(int)));

    /* frametime */
    connect(ui->frameTimeSliderFire, SIGNAL(valueChanged(int)), this,SLOT(onFrametimeChanged(int)));

    /* factor age attenuation */
    connect(ui->ageAttenuationFactorSliderFire, SIGNAL(valueChanged(int)), this,SLOT(ageAttenuationFactorChanged(int)));
    connect(ui->ageAttenuationLimitSliderFire, SIGNAL(valueChanged(int)), this,SLOT(ageAttenuationLimitChanged(int)));

    /* center */
    connect(ui->centerXFireSpinbox, SIGNAL(valueChanged(int)), this,SLOT(onCenterChanged(int)));
    connect(ui->centerYFireSpinbox, SIGNAL(valueChanged(int)), this,SLOT(onCenterChanged(int)));
    connect(ui->centerZFireSpinbox, SIGNAL(valueChanged(int)), this,SLOT(onCenterChanged(int)));

    /* lifetime */
    connect(ui->lifetimeMaxSliderFire_4, SIGNAL(valueChanged(int)), this,SLOT(onLifetimeChanged(int)));
    connect(ui->lifetimeMinSliderFire_4, SIGNAL(valueChanged(int)), this,SLOT(onLifetimeChanged(int)));

    /* velocity */
    connect(ui->velocityMinSliderFire_4, SIGNAL(valueChanged(int)), this,SLOT(onVelocityChanged(int)));
    connect(ui->velocityMaxSliderFire_4, SIGNAL(valueChanged(int)), this,SLOT(onVelocityChanged(int)));

    /* size */
    connect(ui->sizeMaxSliderFire, SIGNAL(valueChanged(int)), this,SLOT(onSizeChanged(int)));
    connect(ui->sizeMinSliderFire, SIGNAL(valueChanged(int)), this,SLOT(onSizeChanged(int)));

    connect(ui->setValuesButton, SIGNAL(clicked()), this, SLOT(setCurrentValues()));

}


void MainWindow::onCenterChanged(int) {
    if(ui->controlSelector->currentIndex() == 0) {
        QSpinBox * x = ui->centerXFireSpinbox;
        QSpinBox * y = ui->centerYFireSpinbox;
        QSpinBox * z = ui->centerZFireSpinbox;
        QString centerS = QString("(%1 %2 %3)").arg(QString::number(x->value()),QString::number(y->value()) ,QString::number(z->value()));
        ui->centerFireValue->setText(centerS);
        Fire * fire =  ui->app->getFire();
        if(fire)
            fire->setCenter(Vec3(x->value(),y->value(),z->value()));

    }
}


void MainWindow::onLifetimeChanged(int) {
    if(ui->controlSelector->currentIndex() == 0) {
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
    }
}




void MainWindow::onVelocityChanged(int) {
    if(ui->controlSelector->currentIndex() == 0) {
        QSlider * min = ui->velocityMinSliderFire_4;
        QSlider * max = ui->velocityMaxSliderFire_4;

        QLabel * labMin = ui->velocityMinFireValue_4;
        QLabel * labMax = ui->velocityMaxFireValue_4;

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
    }
}


void MainWindow::onSizeChanged(int) {
    if(ui->controlSelector->currentIndex() == 0) {
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
    }

}

void MainWindow::onRadiusChanged(int new_radius) {
    if(ui->controlSelector->currentIndex() == 0) {
        Fire * fire =  ui->app->getFire();
        if(fire)
            fire->setRadius((float) new_radius);
    }
}

void MainWindow::onNbItemChanged(int nbitem) {
    if(ui->controlSelector->currentIndex() == 0) {
        Fire * fire =  ui->app->getFire();
        cout << "setting nbitem:" << nbitem << endl;
        if(fire)
            fire->setNbItem(nbitem);
    }
}


void MainWindow::onNbItemPerFrameChanged(int nbitemperframe) {
    if(ui->controlSelector->currentIndex() == 0) {
        Fire * fire =  ui->app->getFire();
        if(fire)
            fire->setNbItemPerFrame(nbitemperframe);
    }
}


void MainWindow::onFrametimeChanged(int frametime) {
    if(ui->controlSelector->currentIndex() == 0) {
        Fire * fire =  ui->app->getFire();
        if(fire)
            fire->setFrameTime(frametime);
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
    Fire * fire =  ui->app->getFire();
    if(fire) {
        ui->ageAttenuationFactorSliderFire->setValue(fire->getAgeAtenuationFactor() * 100);
        ui->ageAttenuationLimitSliderFire->setValue(fire->getAgeAtenuationLimit() * 100);
        ui->radiusSliderFire->setValue(fire->getRadius());
        ui->frameTimeSliderFire->setValue(fire->getFrameTime());

        ui->lifetimeMaxSliderFire_4->setValue(fire->getLifeTimeMax());
        ui->lifetimeMinSliderFire_4->setValue(fire->getLifeTimeMin());

        cout << "vel mac!" << fire->getSizeMin() <<endl;
        ui->velocityMaxSliderFire_4->setValue((float) fire->getVelocityMax());
        ui->velocityMinSliderFire_4->setValue((float) fire->getVelocityMin());

        ui->sizeMaxSliderFire->setValue(fire->getSizeMax());
        ui->sizeMinSliderFire->setValue(fire->getSizeMin());

        ui->nbItemPerFrameSliderFire->setValue(fire->getNbItemPerFrame());
        ui->nbItemSliderFire->setValue(fire->getNbItem());

        Vec3 center = fire->getCenter();
        ui->centerXFireSpinbox->setValue(center.x);
        ui->centerYFireSpinbox->setValue(center.y);
        ui->centerZFireSpinbox->setValue(center.z);
    }
}




MainWindow::~MainWindow()
{
    delete ui;
}
