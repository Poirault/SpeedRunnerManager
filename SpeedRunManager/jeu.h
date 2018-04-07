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
    Jeu(QWidget* parent,QString name, QDate dateDeSortie);
    QString _Path;



private:

};

#endif // JEU_H

