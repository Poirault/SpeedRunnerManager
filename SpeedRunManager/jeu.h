#ifndef JEU_H
#define JEU_H

#include <QObject>
#include <QDate>
#include "level.h"
#include <QAbstractTableModel>
#include <QAbstractListModel>
#include <QVariant>
#include <QApplication>
#include <QItemSelection>
#include <QPalette>
#include <QFileDialog>
#include <QPair>





class Jeu:public QAbstractListModel
{
    Q_OBJECT
public:
    Jeu();
    int count;
    QStringList itemList;
    QList<QPair <QString,QString>> info;
    QString currentGame;
    int rowCount(const QModelIndex & /* parent */) const override;
    QVariant data(const QModelIndex &index, int role) const override;

public slots:
    void addGame();
    void suppGame();
    void startGame();

signals:
    void sendPath(QString address);
    void selectionChanged (const QItemSelection &selected);
};

#endif // JEU_H

