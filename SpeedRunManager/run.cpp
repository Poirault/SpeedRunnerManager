#include "run.h"

Run::Run()
{
    count = 0;
}

//QProcess* Run::startRun(QString GamePath){
   // QProcess* game = new QProcess(this);
   // game->start(GamePath, QStringList() << "");
   // return game;
//}

int Run::rowCount(const QModelIndex & /* parent */)const{return count;}
QVariant Run::data(const QModelIndex &index, int role)const
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

void Run::startRun(QString currentPath){
    QAbstractListModel::beginInsertRows(QModelIndex(),count,count);
    itemList.append(currentPath);
    count++;
    QAbstractListModel::endInsertRows();
    game = new QProcess(this);
    game->start(currentPath, QStringList() << "");
}
