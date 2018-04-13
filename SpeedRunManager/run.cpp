#include "run.h"

Run::Run(QObject *parent)
: QAbstractTableModel(parent)
{
}

//QProcess* Run::startRun(QString GamePath){
   // QProcess* game = new QProcess(this);
   // game->start(GamePath, QStringList() << "");
   // return game;
//}

int Run::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return itemList.size();
}

int Run::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}
QVariant Run::data(const QModelIndex &index, int role)const
{
    if (!index.isValid())
            return QVariant();

    if (index.row() >= itemList.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
             Tuple tuple = itemList.at(index.row());

             if (index.column() == 0)
                 return tuple.first.first;
             if (index.column() == 1)
                 return tuple.first.second;
             else if (index.column() == 2)
                 return tuple.second.at(0);
         }
    return QVariant();
}

QVariant Run::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Game");

            case 1:
                return tr("Player");

            case 2:
                return tr("Chrono");

            default:
                return QVariant();
        }
    }
    return QVariant();
}

bool Run::removeRows(int position, int rows, const QModelIndex &index)
 {
     Q_UNUSED(index);
     beginRemoveRows(QModelIndex(), position, position+rows-1);

     for (int row=0; row < rows; ++row) {
         itemList.removeAt(position);
     }

     endRemoveRows();
     return true;
 }

bool Run::setData(const QModelIndex &index, const QVariant &value, int role)
{
         if (index.isValid() && role == Qt::EditRole) {
                 int row = index.row();

                 Tuple p = itemList.value(row);

                 if (index.column() == 0)
                         p.first.first = value.toString();
                 else if (index.column() == 1)
                         p.first.second = value.toString();
                 else if (index.column() == 2)
                         p.second.prepend(value.toString());
         else
             return false;

         itemList.replace(row, p);
                 emit(dataChanged(index, index));

         return true;
         }

         return false;
}

Qt::ItemFlags Run::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

QList<Tuple> Run::getList()
{
    return itemList;
}

void Run::startRun(QString Game,QString Player,QString currentPath){
    game = new QProcess(this);
    game->start(currentPath, QStringList() << "");

    _chrono = new QTime();

    QList<Tuple>list = this->getList();

    this->insertRows(0, 1, QModelIndex());

    QModelIndex index = this->index(0, 0, QModelIndex());

    index = this->index(0, 0, QModelIndex());
    this->setData(index, Game, Qt::EditRole);
    index = this->index(0, 1, QModelIndex());
    this->setData(index, Player, Qt::EditRole);
    index = this->index(0, 2, QModelIndex());
    this->setData(index, QTime(0,0,0).toString(), Qt::EditRole);


}

bool Run::insertRows(int position, int rows, const QModelIndex &index)
 {
     Q_UNUSED(index);
     beginInsertRows(QModelIndex(), position, position+rows-1);

     for (int row=0; row < rows; row++) {
         Tuple pair= QPair<QPair<QString, QString>, QList<QString>>();
         itemList.insert(position, pair);
     }

     endInsertRows();
     return true;
 }

void Run::chrono(){
    QModelIndex index = this->index(0, 2, QModelIndex());
    if(index.isValid()){
        if(_chrono->isNull())
            _chrono->start();
        int all = _chrono->elapsed();
        int mili = all % 1000;
        int second = (all / 1000) % 60;
        int minute = all / 60000 ;
        QString time = QString::number(minute) + ":" + QString::number(second) + ":" + QString::number(mili);
        this->setData(index, time, Qt::EditRole);
    }
}
