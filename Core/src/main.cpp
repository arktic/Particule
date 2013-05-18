#include <QtGui/QApplication>
#include "app.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    App win;
    win.show();

    return a.exec();
}
