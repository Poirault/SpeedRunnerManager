#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "display.h"
#include <QSystemTrayIcon>
#include "windows.h"
#include <QDebug>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

private slots:
    void updateActions(const QItemSelection &selection);
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

signals:
    void capture();

private:
    Display *display;
    QSystemTrayIcon *trayIcon;
};

#endif // MAINWINDOW_H
