#include "bibliotheque.h"

Bibliotheque::Bibliotheque(QObject *parent)
    : QAbstractListModel(parent)
{
    count = 0;
}
int Bibliotheque::rowCount(const QModelIndex & /* parent */)const{return this->count;}
QVariant Bibliotheque::data(const QModelIndex &index, int role)const
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



void Bibliotheque::insert(QString item){
    beginInsertRows(QModelIndex(), itemList.count(), itemList.count());
    itemList.append(item);
    count++;
    endInsertRows();
    emit countChanged();
}


void Bibliotheque::remove(const QString item){

}


void Bibliotheque::countChanged(){}
