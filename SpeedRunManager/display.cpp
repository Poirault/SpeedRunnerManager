#include "display.h"

Display::Display()
{
    mainlayout = new QTabWidget;
    Choosegame = new QPushButton("choose a game");
    QObject::connect(Choosegame,&QAbstractButton::clicked,this,&Display::addGame);
}

void Display::addGame(){
    QFileDialog(QWidget *parent = Q_NULLPTR, const QString &caption = QString(), const QString &directory = QString(), const QString &filter = QString())
}
