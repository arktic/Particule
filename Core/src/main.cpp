#include <QtGui/QApplication>
#include <time.h>
#include "app.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(NULL));


    App win;
    win.show();

    return a.exec();
}
