
#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "App.h"

/*
#include "MainWindow.h"
#include "App.h"
#include <QGroupBox>
#include <QSlider>
#include <QGridLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <iostream>
#include "ui_mainwindow.h"
*/


    /*setWindowTitle("IN55 - generateur de particules ");
*/
    /* opengl Widget */
  /*  app = new App();

*/
    /* QSizepolicy to have 2/3 opengl, 1/3 parameters */
 /*   QSizePolicy spApp(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spApp.setHorizontalStretch(3);
    app->setSizePolicy(spApp);
    app->setMinimumHeight(300);
    app->setMinimumWidth(300);
*/
    /* right panel */
  /*  QGroupBox * rightBox = new QGroupBox();
    QSizePolicy spRight(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spRight.setHorizontalStretch(1);
    rightBox->setSizePolicy(spRight);
    rightBox->setMinimumHeight(300);
    rightBox->setMinimumWidth(100);

    rightBox->setLayout(new QVBoxLayout);

    QGroupBox * velocityBox = createVelocityBox(rightBox);
    *//* horizontal layout for that */
    /*QHBoxLayout * horizLayout = new QHBoxLayout;
    horizLayout->addWidget(app);
    horizLayout->addWidget(rightBox);

    setCentralWidget(new QWidget);
    centralWidget()->setLayout(horizLayout);


    resize(1000,600);
}*/



/*
QGroupBox* MainWindow::createVelocityBox(QWidget* parent) {
    QGroupBox * velocityBox = new QGroupBox("Velocities", parent);
    QGridLayout * layout = new QGridLayout;
    QSlider* minVel = new QSlider(Qt::Horizontal, velocityBox);
    QLabel* minLabel = new QLabel("0.0",velocityBox);
    QLabel* maxLabel = new QLabel("0.0",velocityBox);
    QSlider* maxVel = new QSlider(Qt::Horizontal, velocityBox);


    //connect(minVel, QSlider::)


    layout->addWidget(minVel,0,0);
    layout->addWidget(maxVel,1,0);
    layout->addWidget(minLabel,0,1);
    layout->addWidget(maxLabel,1,1);

    velocityBox->setLayout(layout);
    velocityBox->adjustSize();
    return velocityBox;
}
*/
/*
void MainWindow::keyPressEvent(QKeyEvent * event) {

  */  /* just redirect event to app */
   /* if(app!=NULL) {
        app->keyPressEvent(event);
    }
}
*/




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   // ui->layoutHoriz->addWidget(new App());

    ui->app = new App();

}

MainWindow::~MainWindow()
{
    delete ui;
}


