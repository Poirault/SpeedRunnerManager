#include "run.h"


Run::Run(Joueur joueur,Level level):
    _joueur(&joueur),
    _level(&level),
    _chrono(QTime()),
    _date(QDateTime::currentDateTime())
{
}

QProcess* Run::startRun(QString GamePath){
    QProcess* game = new QProcess(this);
    game->start(GamePath, QStringList() << "");
    return game;
}
