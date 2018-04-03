#ifndef RUN_H
#define RUN_H

#include <QTime>
#include <QObject>
#include "joueur.h"
#include "level.h"
#include <QDateTime>


class Run : public QObject
{
public:
    Run(Joueur joueur, Level level);
private:

    QTime _chrono;
    Joueur * _joueur;
    Level * _level;
    QDateTime _date;
public:
    // Doit pouvoir lancer un run, et si on le souhaite en comparant à un autre (QTimer)
    void startRun();

    void stopRun();

    void drapeau();
};

#endif // RUN_H
