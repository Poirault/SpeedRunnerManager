#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QDate>
#include <QAbstractTableModel>
#include <QAbstractListModel>
#include <QVariant>
#include <QApplication>
#include <QPalette>


class Level:public QAbstractListModel
{
public:
    Level();
    QString nom;
    QString dificulte;
    QList<QString> checkpoints;
    QList<QTime> WR;
    int count;
    QStringList itemList;

    int rowCount(const QModelIndex & /* parent */) const override;
    QVariant data(const QModelIndex &index, int role) const override;
public slots:
    void newlevel();


};

#endif // LEVEL_H
