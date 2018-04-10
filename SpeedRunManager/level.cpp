/*!
 * \class Level level.h
 * \brief la class level conteint la list des levels
 */
#include "level.h"

/*!
 * \brief Level::Level constructeur de base
 */
Level::Level()
{
    count = 0;
}

/*!
 * \brief Level::rowCount
 * \return nombre de levels
 */
int Level::rowCount(const QModelIndex & /* parent */)const{return count;}

/*!
 * \brief Level::data
 * \param index
 * \param role
 * \return 
 */
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

/*!
 * \brief Level::newlevel slot
 */
void Level::newlevel(QString text){
    if(text!= "" && !itemList.contains(text)){
        QAbstractListModel::beginInsertRows(QModelIndex(),count,count);
        itemList.append(text);
        count++;
        QAbstractListModel::endInsertRows();
    }
}
