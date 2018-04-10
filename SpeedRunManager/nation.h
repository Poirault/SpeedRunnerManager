#ifndef NATION_H
#define NATION_H

#include <QObject>
#include <QAbstractTableModel>

class Nation:public QObject
{
public:
    Nation();

private:
    QString Pays;
};

#endif // NATION_H
