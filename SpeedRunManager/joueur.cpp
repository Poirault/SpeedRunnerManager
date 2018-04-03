#include "joueur.h"

Joueur::Joueur(QString name)
{
    this->nom=name;
    this->date_naissance=QDate::currentDate();
    this->jeu_prefere=NULL;
}

Joueur::Joueur(QString name, QDate birth):nom(name),date_naissance(birth),jeu_prefere(NULL){

}

void Joueur::rename(QString name){
    this->nom=name;
}

void Joueur::newfavorite(Jeu fav){
    this->jeu_prefere=&fav;
}

void Joueur::rebirth(QDate birth){
    int a,b,c;
    birth.getDate(&a,&b,&c);
    date_naissance.setDate(a,b,c);
}
