#ifndef JOUEUR_H
#define JOUEUR_H

#include <QObject>
#include "jeu.h"
#include <QDate>
#include <QAbstractListModel>
#include <QVariant>
#include <QApplication>
#include <QPalette>


class Joueur : public QAbstractListModel
{
    Q_OBJECT
public:
    Joueur();
    void rename(QString);
    void newfavorite(Jeu);
    void rebirth(QDate);
    QStringList itemList;

    int rowCount(const QModelIndex & /* parent */) const override;
    QVariant data(const QModelIndex &index, int role) const override;
private:
    QString nom;
    Jeu * jeu_prefere;
    QDate date_naissance;
public slots:
    void newPseudo(QString text);



};

#endif // JOUEUR_H
