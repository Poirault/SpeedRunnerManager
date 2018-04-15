#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow()
{
    display = new Display;
    setCentralWidget(display);
    setWindowTitle(tr("SpeedRunMannager"));
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
    trayIcon->show();

    file = menuBar()->addMenu(tr("&File"));
    open = new QAction(tr("&Open"), this);
    file->addAction(open);
    connect(open, SIGNAL(triggered()),this, SLOT(openFile()));
    save = new QAction(tr("&Save"), this);
    file->addAction(save);
    connect(save, SIGNAL(triggered()),this, SLOT(saveFile()));

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
    connect(this,SIGNAL(capture()),display->runs,SLOT(chrono()));
    RegisterHotKey((HWND)MainWindow::winId(),   // Set the system identifier of the widget window that will handle the HotKey
                       100,                         // Set identifier HotKey
                       MOD_CONTROL,         // Set modifiers
                       'W');                        // We define hotkeys for HotKey

}

bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    Q_UNUSED(eventType)
    Q_UNUSED(result)
    // Transform the message pointer to the MSG WinAPI
    MSG* msg = reinterpret_cast<MSG*>(message);

    // If the message is a HotKey, then ...
    if(msg->message == WM_HOTKEY){
        // ... check HotKey
        if(msg->wParam == 100){
            // We inform about this to the console
            emit capture();
            return true;
        }
    }
    return false;
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason){
    case QSystemTrayIcon::Trigger:
        !isVisible() ? show() : hide();
        break;
    default:
        break;
    }
}


void MainWindow::updateActions(const QItemSelection &selection)
{
    QModelIndexList indexes = selection.indexes();
}


void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()) {
        display->load(fileName);
    }
}


void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if (!fileName.isEmpty()) {
        display->save(fileName);
    }
}


