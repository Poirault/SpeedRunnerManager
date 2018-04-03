#ifndef JEU_H
#define JEU_H

#include <QObject>
#include <QDate>

class Jeu:public QObject
{
public:
    QString _name;
    QDate _dateDeSortie;
public:
    Jeu(QString name, QDate dateDeSortie);
};

#endif // JEU_H
