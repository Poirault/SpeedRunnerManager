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

    Box->addWidget(gameInfo);
    Box->addWidget(tab);

    setup();
    setLayout(Box);

}

/*!
 * \brief Display::newPseudo slot
 */
void Display::newPseudo(){}
/*!
 * \brief Display::newlevel slot
 */
void Display::newlevel(){}
/*!
 * \brief Display::selectGame slot
 * \param selection
 */
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
    QObject::connect(startGame,SIGNAL(clicked(bool)),jeux,SLOT(startGame()));
    layout = new QFormLayout;
    pickGame = new QScrollArea;
    list = new QListView;
    list->setModel(jeux);
    pickGame->setWidgetResizable(true);
    pickGame->setWidget(list);
    QObject::connect(list,SIGNAL(clicked(QModelIndex)),this,SLOT(selectGame(QModelIndex)));
    QObject::connect(jeux,SIGNAL(sendPath(QString)),runs,SLOT(startRun(QString)));
    vbox->addWidget(pickGame);
    vbox->addWidget(addGame);
    layout->addRow(new QLabel(tr("Pseudo")),new QLineEdit);
    layout->addRow(new QLabel(tr("Level")),new QLineEdit);
    vbox->addLayout(layout);
    vbox->addWidget(startGame);
    gameInfo->setLayout(vbox);


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

        //connect(tableView->selectionModel(),
        //    &QItemSelectionModel::selectionChanged,
        //    this, &Display::selectionChanged);

        //connect(this, &QTabWidget::currentChanged, this, [this](int tabIndex) {
        //    auto *tableView = qobject_cast<QTableView *>(widget(tabIndex));
        //    if (tableView)
        //        emit selectionChanged(tableView->selectionModel()->selection());
        //});

        tab->addTab(tableView, str);
    }
}


