#ifndef DISPLAY_H
#define DISPLAY_H

#include <QFileDialog>
#include "jeu.h"
#include "run.h"
#include "nation.h"
#include "level.h"
#include <QPushButton>
#include <QTabWidget>
#include <QSortFilterProxyModel>
#include <QAbstractTableModel>
#include <QTableView>
#include <QHeaderView>
#include "bibliotheque.h"
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QScrollArea>
#include <QListView>

class Display:public QDialog
{
    Q_OBJECT
public:
    Display(QWidget* parent =0);

public slots:
    void newPseudo();
    void newlevel();
    void selectGame(QModelIndex selection);

signals:
    void sendPath(QString name);
    void selectionChanged (const QItemSelection &selected);

private:
    QTabWidget* tab;
    QHBoxLayout* Box;
    QGroupBox* gameInfo;
    QPushButton* Choosegame;
    QSortFilterProxyModel *proxyModel;
    void setup();
    Jeu* jeux;
    Joueur* joueurs;
    Level* levels;
    Run* runs;

    QVBoxLayout* vbox;
    QPushButton* addGame;
    QPushButton* startGame;
    QFormLayout* layout;
    QScrollArea* pickGame;
    QListView* list;
};

#endif // DISPLAY_H
