/*!
 * \class Run run.h
 */
#include "run.h"

/*!
 * \brief Run::Run constructeur de base
 */
Run::Run()
{
    count = 0;
    _chrono= new QTime();
    _chrono->start();
}

//QProcess* Run::startRun(QString GamePath){
   // QProcess* game = new QProcess(this);
   // game->start(GamePath, QStringList() << "");
   // return game;
//}

/*!
 * \brief Run::rowCount
 * \return 
 */
int Run::rowCount(const QModelIndex & /* parent */)const{return count;}
/*!
 * \brief Run::data
 * \param index
 * \param role
 * \return 
 */
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

/*!
 * \brief Run::startRun slot
 * \param currentPath
 */
void Run::startRun(QString currentPath){
    QAbstractListModel::beginInsertRows(QModelIndex(),count,count);
    itemList.append(currentPath);
    count++;
    QAbstractListModel::endInsertRows();
    game = new QProcess(this);
    game->start(currentPath, QStringList() << "");

}

void Run::chrono(bool status){
    if(status){
        QAbstractListModel::beginInsertRows(QModelIndex(),count,count);
            itemList.append(QString::number(_chrono->elapsed()));
            count++;
        QAbstractListModel::endInsertRows();
    }
}
