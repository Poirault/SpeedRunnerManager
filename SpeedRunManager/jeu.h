#ifndef JEU_H
#define JEU_H

#include <QObject>
#include <QDate>

class Jeu:public QObject
{
public:
    QString name;
    QDate dateDeSortie;
public:
    Jeu();
};

#endif // JEU_H
