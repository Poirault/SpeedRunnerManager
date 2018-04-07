#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QDate>


class Level:public QObject
{
public:
    Level(QString name);
    QString nom;
    QString dificulte;
    QList<QString> checkpoints;
    QList<QTime> WR;

};

#endif // LEVEL_H
