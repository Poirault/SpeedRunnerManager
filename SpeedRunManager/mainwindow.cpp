#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow()
{
    display = new Display;
    setCentralWidget(display);
    connect(qApp, SIGNAL(hotkey(bool)), display->runs, SLOT(chrono(bool)));
    setWindowTitle(tr("SpeedRunMannager"));
}


void MainWindow::updateActions(const QItemSelection &selection)
{
    QModelIndexList indexes = selection.indexes();
}


