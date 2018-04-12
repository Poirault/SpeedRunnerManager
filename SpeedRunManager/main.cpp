#include "mainwindow.h"
#include <QApplication>
#include "application.h"
#include "eventfilter.h"

int main(int argc, char *argv[])
{
    Application a(argc, argv);
    a.installEventFilter(new EventFilter(a.instance()));
    MainWindow w;
    w.show();

    return a.exec();
}


