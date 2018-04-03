#include "run.h"


Run::Run(Joueur joueur,Level level):
    _joueur(&joueur),
    _level(&level),
    _chrono(QTime()),
    _date(QDateTime::currentDateTime())
{
}

void Run::startRun(){

}
