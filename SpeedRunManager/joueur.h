#ifndef JOUEUR_H
#define JOUEUR_H

#include <QObject>
#include "jeu.h"
#include <QDate>
#include "nation.h"
#include <QAbstractListModel>
#include <QVariant>
#include <QApplication>
#include <QPalette>


class Joueur : public QAbstractListModel
{
public:
    Joueur();
    void rename(QString);
    void newfavorite(Jeu);
    void rebirth(QDate);
    int count;
    QStringList itemList;

    int rowCount(const QModelIndex & /* parent */) const override;
    QVariant data(const QModelIndex &index, int role) const override;
private:
    QString nom;
    Jeu * jeu_prefere;
    QDate date_naissance;
public slots:
    void newPseudo();



};

#endif // JOUEUR_H
