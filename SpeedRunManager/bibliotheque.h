#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H
#include <QAbstractListModel>
#include <QVariant>
#include <QApplication>
#include <QPalette>

class Bibliotheque:public QAbstractListModel
{
public:
    Bibliotheque(QObject *parent = 0);
    int rowCount(const QModelIndex & /* parent */) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    void insert(QString item);
    void remove(const QString item);
    int count;
private:
     QStringList itemList;
signals:
     void countChanged();
};

#endif // BIBLIOTHEQUE_H
