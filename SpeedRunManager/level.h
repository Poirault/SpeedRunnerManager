#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QDate>


class Level:public QObject
{
public:
    QString nom;
    QString dificulte;
    QList<QString> checkpoints;
    QList<QTime> * WR;
public:
    Level();

};

#endif // LEVEL_H
