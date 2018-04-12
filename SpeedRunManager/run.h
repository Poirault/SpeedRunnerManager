#ifndef RUN_H
#define RUN_H

#include <QTime>
#include <QObject>
#include "joueur.h"
#include "level.h"
#include <QDateTime>
#include <QProcess>
#include <QApplication>
#include <QAbstractTableModel>
#include <QVariant>
#include <QApplication>
#include <QPalette>
#include <QPair>
#include <QMessageBox>

typedef QPair<QPair<QString, QString>, QList<QString>> Tuple;

class Run :public QAbstractTableModel
{
    Q_OBJECT
public:
    Run(QObject *parent=0);

    int rowCount(const QModelIndex &parent) const;
     int columnCount(const QModelIndex &parent) const;
     QVariant data(const QModelIndex &index, int role) const;
     QVariant headerData(int section, Qt::Orientation orientation, int role) const;
     Qt::ItemFlags flags(const QModelIndex &index) const;
     bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);
     bool insertRows(int position, int rows, const QModelIndex &index=QModelIndex());
     bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex());
     QList<Tuple> getList();


private:

    QTime* _chrono;
    QList<Tuple> itemList;
    QProcess* game;


public:
    // Doit pouvoir lancer un run, et si on le souhaite en comparant à un autre (QTimer)
   // QProcess* startRun(QString GamePath);

public slots:
    void startRun(QString Game,QString Player,QString currentPath);
    void chrono();

signals:

};

#endif // RUN_H
