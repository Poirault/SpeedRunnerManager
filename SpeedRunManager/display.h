#ifndef DISPLAY_H
#define DISPLAY_H

#include <QFileDialog>
#include "jeu.h"
#include "run.h"
#include "level.h"
#include <QPushButton>
#include <QTabWidget>
#include <QSortFilterProxyModel>
#include <QAbstractTableModel>
#include <QAbstractListModel>
#include <QTableView>
#include <QHeaderView>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QScrollArea>
#include <QListView>
#include <QDataStream>

class Display:public QDialog
{
    Q_OBJECT
public:
    Display(QWidget* parent =0);
    Run* runs;
    void save(QString fileName);
    void load(QString fileName);

public slots:
    void newInfoGame();
    void selectGame(QModelIndex selection);

signals:
    void sendPath(QString name);
    void selectionChanged (const QItemSelection &selected);
    void sendPseudo(QString text);
    void sendLevel(QString text);
    void startRun(QString Player);

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


    QVBoxLayout* vbox;
    QPushButton* addGame;
    QPushButton* startGame;
    QFormLayout* layout;
    QScrollArea* pickGame;
    QListView* list;
    QLineEdit* pseu;
    QLineEdit* lev;
};

#endif // DISPLAY_H
