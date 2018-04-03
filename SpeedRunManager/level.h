#ifndef LEVEL_H
#define LEVEL_H

#include "jeu.h"


class Level:public Jeu
{
public:
    QString dificulte;
    QString * checkpoints;
    QTime * WR;
public:
    Level();

};

#endif // LEVEL_H
