#include "../header/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setIsRoot(true);
    w.show();
    return a.exec();
}
