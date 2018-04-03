#ifndef JEU_H
#define JEU_H

#include <QObject>
#include <QDate>
#include "level.h"

class Jeu:public QObject
{
public:
    QString _name;
    QDate _dateDeSortie;
    QList<Level> * levels;
public:
    Jeu(QString name, QDate dateDeSortie);
};

#endif // JEU_H
