#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow()
{
    display = new Display;
    setCentralWidget(display);

    setWindowTitle(tr("SpeedRunMannager"));
}


void MainWindow::updateActions(const QItemSelection &selection)
{
    QModelIndexList indexes = selection.indexes();
}


