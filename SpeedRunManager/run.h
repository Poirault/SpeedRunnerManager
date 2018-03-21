#ifndef RUN_H
#define RUN_H

#include <QTime>
#include <QObject>
#include "joueur.h"
#include "level.h"



class Run : public QObject
{
public:
    Run();
private:
    QTime chrono;
    Joueur joueur;
    Level level;
};

#endif // RUN_H
