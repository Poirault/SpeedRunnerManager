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
#include <QAbstractListModel>
#include <QVariant>
#include <QApplication>
#include <QPalette>

typedef
struct infoRun
{
    QDate date;
    QTime chrono;
    Level level;
    Joueur joueur;
} infoRun;



class Run :public QAbstractListModel
{
    Q_OBJECT
public:
    Run();

    int rowCount(const QModelIndex & /* parent */) const override;
    QVariant data(const QModelIndex &index, int role) const override;


private:

    QTime* _chrono;
    Joueur * _joueur;
    Level * _level;
    QDateTime _date;
    int count;
    QList<QString> itemList;
    QList<infoRun> info;
    QProcess* game;


public:
    // Doit pouvoir lancer un run, et si on le souhaite en comparant à un autre (QTimer)
   // QProcess* startRun(QString GamePath);

public slots:
    void startRun(QString currentPath);
    void chrono();

signals:

};

#endif // RUN_H
