/*!
 * \class Joueur joueur.h
 * \brief la class joueur est une liste des joueurs
 */

#include "joueur.h"

/*!
 * \brief Joueur::Joueur constructeur de base
 */
Joueur::Joueur()
{
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

/*!
 * \brief Joueur::rowCount
 * \return nombre de joueurs
 */
int Joueur::rowCount(const QModelIndex & /* parent */)const{return itemList.size();}

/*!
 * \brief Joueur::data
 * \param index
 * \param role
 * \return 
 */
QVariant Joueur::data(const QModelIndex &index, int role)const
{
    if (!index.isValid())
            return QVariant();

    if (index.row() >= itemList.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        return itemList.at(index.row());
    } else if (role == Qt::BackgroundRole) {
        int batch = (index.row() / 100) % 2;
        if (batch == 0)
            return qApp->palette().base();
        else
            return qApp->palette().alternateBase();
    }
    return QVariant();
}

void Joueur::newPseudo(QString text){
    if(!itemList.contains(text)){
        QAbstractListModel::beginInsertRows(QModelIndex(), itemList.size(),itemList.size() );

        itemList.append(text);

        QAbstractListModel::endInsertRows();

    }
}
