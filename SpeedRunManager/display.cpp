/*!
 * \class Display display.h
 * \brief gére l'affichage et le model
 */
#include "display.h"


/*!
 * \brief Display::Display constucteur de base
 * \param parent
 */
Display::Display(QWidget* parent)
    : QDialog(parent)
{
    jeux = new Jeu;
    runs = new Run;
    levels = new Level;
    joueurs = new Joueur;
    tab = new QTabWidget;
    Box = new QHBoxLayout;
    gameInfo = new QGroupBox;
    pseu = new QLineEdit;
    lev = new QLineEdit;
    shcut = new QShortcut(Qt::CTRL + Qt::Key_W,this, nullptr, nullptr,  Qt::ApplicationShortcut);

    Box->addWidget(gameInfo);
    Box->addWidget(tab);

    setup();
    setLayout(Box);

}


void Display::newInfoGame(){
    emit sendPseudo(pseu->text());
    emit sendLevel(lev->text());
    emit startRun(pseu->text());
}


void Display::selectGame(QModelIndex selection){
    jeux->currentGame = selection.data().toString();
}

/*!
 * \brief Display::setup 
 */
void Display::setup()
{
    vbox = new QVBoxLayout;
    addGame = new QPushButton("Add a Game");
    QObject::connect(addGame,SIGNAL(clicked(bool)),jeux,SLOT(addGame()));
    startGame = new QPushButton("Start Game");
    QObject::connect(startGame,SIGNAL(clicked(bool)),this,SLOT(newInfoGame()));
    QObject::connect(this,SIGNAL(sendLevel(QString)),levels,SLOT(newlevel(QString)));
    QObject::connect(this,SIGNAL(sendPseudo(QString)),joueurs,SLOT(newPseudo(QString)));
    QObject::connect(this,SIGNAL(startRun(QString)),jeux,SLOT(startGame(QString)));
    layout = new QFormLayout;
    pickGame = new QScrollArea;
    list = new QListView;
    list->setModel(jeux);
    pickGame->setWidgetResizable(true);
    pickGame->setWidget(list);
    QObject::connect(list,SIGNAL(clicked(QModelIndex)),this,SLOT(selectGame(QModelIndex)));
    QObject::connect(jeux,SIGNAL(sendPath(QString,QString,QString)),runs,SLOT(startRun(QString,QString,QString)));
    vbox->addWidget(pickGame);
    vbox->addWidget(addGame);
    layout->addRow(new QLabel(tr("Pseudo")),pseu);
    layout->addRow(new QLabel(tr("Level")),lev);
    vbox->addLayout(layout);
    vbox->addWidget(startGame);
    gameInfo->setLayout(vbox);


    QObject::connect(shcut,SIGNAL(activated()),runs,SLOT(chrono()));


    QStringList groups;
    groups << "Players" << "Runs" << "Levels" << "Games";

    for (int i = 0; i < groups.size(); ++i) {
        QString str = groups.at(i);


        QTableView *tableView = new QTableView;

        if( groups.at(i) == "Games")
            tableView->setModel(jeux);
        if( groups.at(i) == "Levels")
            tableView->setModel(levels);
        if( groups.at(i) == "Runs")
            tableView->setModel(runs);
        if( groups.at(i) == "Player")
            tableView->setModel(joueurs);

        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->hide();
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);

        tableView->setSortingEnabled(true);

        tab->addTab(tableView, str);
    }
}


