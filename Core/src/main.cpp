#include <QtGui/QApplication>
#include <time.h>
#include "app.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(NULL));


    MainWindow win(NULL);
    win.show();

    return a.exec();
}
