#include "jeu.h"

Jeu::Jeu()
{
}

int Jeu::rowCount(const QModelIndex & /* parent */)const{return itemList.size();}
QVariant Jeu::data(const QModelIndex &index, int role)const
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

void Jeu::addGame(){
    int deb,fin;

    QString Path = QFileDialog::getOpenFileName(0,tr("Find a game..."),"C:/User");

    deb = Path.lastIndexOf("/");
    fin = Path.lastIndexOf(".");
    if(!(itemList.contains(Path.mid(deb+1,fin - deb - 1)))){
        QAbstractListModel::beginInsertRows(QModelIndex(),itemList.size(),itemList.size());
        itemList.append(Path.mid(deb+1,fin - deb - 1));
        QAbstractListModel::endInsertRows();
        info.append(QPair<QString,QString>(Path.mid(deb+1,fin - deb - 1),Path));
    }
}
void Jeu::suppGame(){
    //QAbstractListModel::beginRemoveRows(QModelIndex(),count,count);
    //count--;
    //QAbstractListModel::endRemoveRows();

}



void Jeu::startGame(QString Player){
    for (int i=0;i<info.count();i++){
        QPair<QString, QString> pair = info.at(i);
        if (pair.first == currentGame)
            emit sendPath(currentGame,Player,pair.second);
    }
}
