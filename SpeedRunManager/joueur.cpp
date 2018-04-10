#include "joueur.h"


Joueur::Joueur()
{
    count = 0;
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


int Joueur::rowCount(const QModelIndex & /* parent */)const{return count;}
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
    if(text != "" && !itemList.contains(text)){
        QAbstractListModel::beginInsertRows(QModelIndex(),count,count);
        itemList.append(text);
        count++;
        QAbstractListModel::endInsertRows();
    }}
