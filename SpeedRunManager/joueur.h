#ifndef JOUEUR_H
#define JOUEUR_H

#include <QObject>
#include "jeu.h"
#include <QDate>
#include "nation.h"


class Joueur : public Nation
{
public:
    Joueur(QString);
    Joueur(QString,QDate);
    void rename(QString);
    void newfavorite(Jeu);
    void rebirth(QDate);
private:
    QString nom;
    Jeu * jeu_prefere;
    QDate date_naissance;

};

#endif // JOUEUR_H
