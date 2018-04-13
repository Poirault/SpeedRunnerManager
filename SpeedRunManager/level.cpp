#include "level.h"

Level::Level()
{
    count = 0;
}


int Level::rowCount(const QModelIndex & /* parent */)const{return count;}
QVariant Level::data(const QModelIndex &index, int role)const
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

void Level::newlevel(QString text){
    if(text!= "" && !itemList.contains(text)){
        QAbstractListModel::beginInsertRows(QModelIndex(),count,count);
        itemList.append(text);
        count++;
        QAbstractListModel::endInsertRows();
    }
}
