#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "App.h"

#include <QSlider>
#include <QGroupBox>


#include <QMainWindow>

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow {

private:
    Q_OBJECT
    Ui::MainWindow *ui;
    App* app;


    //void setUpCurrentValues();

    void keyPressEvent(QKeyEvent *);
public:
    MainWindow(QWidget * parent);
    ~MainWindow();


public slots:
    void onCenterChanged(int);
    void onLifetimeChanged(int);
    void onVelocityChanged(int);
    void onSizeChanged(int);
    void onRadiusChanged(int);
    void onNbItemChanged(int);
    void onNbItemPerFrameChanged(int);
    void onFrametimeChanged(int);
    void ageAttenuationFactorChanged(int);
    void ageAttenuationLimitChanged(int);
    void setCurrentValues();
};

#endif // MAINWINDOW_H
