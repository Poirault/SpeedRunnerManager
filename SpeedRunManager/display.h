#ifndef DISPLAY_H
#define DISPLAY_H

#include <QFileDialog>
#include "jeu.h"
#include <QPushButton>
#include <QTabWidget>
#include <QObject>

class Display:public QObject
{
public:
    Display();

public slots:
      void addGame();
signals:
    void sendPath(QString name, QString address);

private:
    QTabWidget* mainlayout;
    QPushButton* Choosegame;
};

#endif // DISPLAY_H
