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
   // Q_OBJECT
    Ui::MainWindow *ui;
    QSlider* velocityMin;
    QSlider* velocityMax;

    void keyPressEvent(QKeyEvent *);
public:
    MainWindow(QWidget * parent);
    ~MainWindow();
};

#endif // MAINWINDOW_H
