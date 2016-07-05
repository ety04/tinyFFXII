#include "mainwindow.h"

using namespace std;

MainWindow::MainWindow()
{
    cout << "MainWindow default constructor called" << endl;
}

MainWindow::MainWindow(int width, int height)
{
    // Initialisation de la fenêtre globale
    resize(width, height);
    setGeometry( QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, size(), qApp->desktop()->availableGeometry() )  );
    QPalette p(palette());
    p.setBrush(QPalette::Window, QBrush(QPixmap(":/images/phon_coast.png")));
    setPalette(p);
    player = new QMediaPlayer();
    player->setMedia(QUrl("qrc:/sons/phon.mp3"));
    player->play();
    soundOn = true;
    sound = new MyLabel(this);
    sound->setPixmap(QPixmap(":/images/sound_off.png"));
    sound->move(900, 50);
    sound->resize(40,40);
    connect(sound, SIGNAL(clicked()), this, SLOT(soundOnOff()));
    sound->show();

    prepareLog();
    prepareTable();
    prepareMenus();

}

/** Cette méthode sert à préparer le log de combat */
void MainWindow::prepareLog()
{
    // Création de l'arrière-plan du log
    QLabel* logBackground = new QLabel(this);
    logBackground->resize(300, 100);
    logBackground->move(0, 23);
    QPixmap bleu(":/images/bleu.jpg");
    logBackground->setPixmap(bleu);
    logBackground->show();

    // Initialisation du log
    log = new QTextEdit("Un log", this);
    log->setReadOnly(true);
    log->viewport()->setAutoFillBackground(false);
    log->resize(300, 100);
    log->move(0, 23);
    setLog("Ceci est le log par défaut", *log);
    setLog("Apparition prépare l'action: ", "Glas", *log);
    log->show();
    cout << "Log: " << (getLog(log)).toStdString() << endl;
}


/** Cette méthode sert à préparer le tableau central contenant les icônes des personnages, les actions et les cibles */
void MainWindow::prepareTable()
{
    // Création du tableau et de sa disposition
    tableau = new QWidget(this);
    tableau->move(150, 120);
    tableau->resize(700, 500);
    QGridLayout* grille = new QGridLayout();

    // Création des en-têtes des colonnes du tableau
    QLabel* header1 = new QLabel("Personnages");
    QPalette headerpalette;
    headerpalette.setColor(QPalette::Window, Qt::white);
    headerpalette.setColor(QPalette::WindowText, Qt::red);
    header1->setPalette(headerpalette);
    header1->setAlignment(Qt::AlignCenter);
    header1->setAutoFillBackground(true);
    QLabel* header2 = new QLabel("Action");
    header2->setPalette(headerpalette);
    header2->setAlignment(Qt::AlignCenter);
    header2->setAutoFillBackground(true);
    QLabel* header3 = new QLabel("Cibles");
    header3->setPalette(headerpalette);
    header3->setAlignment(Qt::AlignCenter);
    header3->setAutoFillBackground(true);

    // Création des icônes personnage
    MyLabel* ashe = new MyLabel();
    ashe->setAlignment(Qt::AlignCenter);
    MyLabel* vaan = new MyLabel();
    vaan->setAlignment(Qt::AlignCenter);
    MyLabel* balthier = new MyLabel();
    balthier->setAlignment(Qt::AlignCenter);
    MyLabel* fran = new MyLabel();
    fran->setAlignment(Qt::AlignCenter);
    MyLabel* basch = new MyLabel();
    basch->setAlignment(Qt::AlignCenter);
    MyLabel* penelo = new MyLabel();
    penelo->setAlignment(Qt::AlignCenter);
    MyLabel* larsa = new MyLabel();
    larsa->setAlignment(Qt::AlignCenter);
    MyLabel* apparition = new MyLabel();
    vaan->setPixmap(QPixmap(":/images/vaan.png"));
    ashe->setPixmap(QPixmap(":/images/ashe2.png"));
    balthier->setPixmap(QPixmap(":/images/balthier.png"));
    fran->setPixmap(QPixmap(":/images/fran.png"));
    basch->setPixmap(QPixmap(":/images/basch.png"));
    penelo->setPixmap(QPixmap(":/images/penelo.png"));
    //larsa->setPixmap(QPixmap(":/images/larsa.png"));
    apparition->setPixmap(QPixmap(":/images/wraith_apparition.png"));

    // Liaison des icônes avec leur (courte) biographie
    connect(vaan, SIGNAL(labelClicked(int,int)), this, SLOT(vaanBio(int, int)));
    connect(balthier, SIGNAL(labelClicked(int,int)), this, SLOT(balthierBio(int,int)));
    connect(fran, SIGNAL(labelClicked(int,int)), this, SLOT(franBio(int,int)));
    connect(basch, SIGNAL(labelClicked(int,int)), this, SLOT(baschBio(int,int)));
    connect(ashe, SIGNAL(labelClicked(int,int)), this, SLOT(asheBio(int,int)));
    connect(penelo, SIGNAL(labelClicked(int,int)), this, SLOT(peneloBio(int,int)));
    connect(apparition, SIGNAL(bigLabelClicked(int,int)), this, SLOT(ennemiBio(int,int)));

    // Création des boutons d'action
    QIcon epee(QPixmap(":/images/excalibur.png"));
    QPushButton* vaanAttaque = new QPushButton(epee, "Attaquer");
    balthierAttaque = new MyButton(epee, "Attaquer", bal);
    QPushButton* franAttaque = new QPushButton(epee, "Attaquer");
    QPushButton* baschAttaque = new QPushButton(epee, "Attaquer");
    QPushButton* asheAttaque = new QPushButton(epee, "Attaquer");
    QPushButton* peneloAttaque = new QPushButton(epee, "Attaquer");

    // Connexion des boutons Attaque et Recommencer avec leurs fonctions respectives
    recommencer = new MyButton("Recommencer", this);
    connect(recommencer, SIGNAL(buttonClickedForReset(Ennemi&)), this, SLOT(reinitialiser(Ennemi&)));
    recommencer->setVisible(false);
    connect(balthierAttaque, SIGNAL(buttonClickedForBattle(Allie&,Ennemi&)), this, SLOT(attaqueSimple(Allie&,Ennemi&)));

    // Ajout des éléments précédents à la disposition du tableau
    grille->addWidget(header1, 0, 0);
    grille->addWidget(header2, 0, 1);
    grille->addWidget(header3, 0, 2);
    grille->addWidget(vaan, 1, 0);
    grille->addWidget(balthier, 2, 0);
    grille->addWidget(fran, 3, 0);
    grille->addWidget(basch, 4, 0);
    grille->addWidget(ashe, 5, 0);
    grille->addWidget(penelo, 6, 0);
    grille->addWidget(vaanAttaque, 1, 1);
    grille->addWidget(balthierAttaque, 2, 1);
    grille->addWidget(franAttaque, 3, 1);
    grille->addWidget(baschAttaque, 4, 1);
    grille->addWidget(asheAttaque, 5, 1);
    grille->addWidget(peneloAttaque, 6, 1);
    grille->addWidget(apparition, 1, 2, 6, 1);
    tableau->setLayout(grille);

    //this->setCentralWidget(tableau);
    tableau->show();
}

/** Cette méthode sert à préparer la barre de menus de la fenêtre globale */
void MainWindow::prepareMenus()
{
    QMenu* fichier = menuBar()->addMenu("Fichier");
    QAction* quitter = new QAction("&Quitter", this);
    quitter->setIcon(QIcon(":/images/oofl.png"));
    quitter->setShortcut(QKeySequence("Ctrl+Q"));
    connect(quitter, SIGNAL(triggered()), qApp, SLOT(quit()));
    fichier->addAction(quitter);

    QMenu* autre = menuBar()->addMenu("?");
    QAction* apropos = new QAction("&A propos", this);
    connect(apropos, SIGNAL(triggered()), this, SLOT(aPropos()));
    autre->addAction(apropos);

    menuBar()->setPalette(QPalette(QColor("grey")));
}

void MainWindow::setLog(const QString& text, QTextEdit& boiteDeLog)
{
    boiteDeLog.setText(text);
}

void MainWindow::setLog(const QString& text, const QString& textHighlight, QTextEdit& boiteDeLog)
{
    boiteDeLog.setTextColor(QColor("black"));
    boiteDeLog.setText(text);
    boiteDeLog.moveCursor(QTextCursor::End);
    boiteDeLog.setTextColor(QColor("red"));
    boiteDeLog.insertPlainText(textHighlight);
}

const QString MainWindow::getLog(QTextEdit* boiteDeLog)
{
    return boiteDeLog->toPlainText();
}

/** Cette méthode affiche un petit texte autour de ce programme */
void MainWindow::aPropos()
{
    MyTextEdit* apropos = new MyTextEdit(this);
    apropos->move(300, 50);
    apropos->resize(250, 170);
    apropos->setText("Ceci est une application (très) basique développée à but expérimental et ludique.");
    apropos->append("Les outils utilisés sont le langage C++ et la bibliothèque Qt 5.6 (avec Qt Creator 4).");
    apropos->append("FINAL FANTASY XII appartient à SQUARE ENIX CO., LTD. Ce produit est purement à titre de fan.");
    apropos->append("Version 0.1 ~ Copyleft Ety, 2016");
    apropos->setReadOnly(true);
    apropos->setFrameStyle(QFrame::Box);
    connect(apropos, SIGNAL(clicked()), apropos, SLOT(close()));
    apropos->show();
}

/** Les méthodes suivantes initialisent les biographies des différents personnages */

void MainWindow::vaanBio(int xBio, int yBio)
{
    QString desc("Un jeune garçon de 17 ans vivant à Rabanastre. "
                  "Ses principales occupations sont tuer des rats dans les égouts et voler les impériaux. "
                  "Son rêve est de devenir pirate de l'air, mais est-ce là tout?");
    genericBio(xBio, yBio, 119, 80, 239, desc);
}

void MainWindow::balthierBio(int xBio, int yBio)
{
    QString desc("Un pirate de l'air de 22 ans sillonnant les cieux d'Ivalice à bord de son vaisseau, le Sillage. "
                 "Il est attiré par les trésors, et notamment par une certaine pierre précieuse cachée à Rabanastre. "
                 "Cependant, son passé et ses origines restent assez obscurs.");
    genericBio(xBio, yBio, 78, 183, 106, desc);
}

void MainWindow::franBio(int xBio, int yBio)
{
    QString desc("Une viéra d'âge inconnu. Elle est la partenaire pirate de Balthier. "
                 "Habile avec tout type d'armes, elle maîtrise également les mécanismes du Sillage. "
                 "Elle a une vaste connaissance d'Ivalice, mais est mal à l'aise avec une substance nommée 'myste'. De quoi s'agit-il?");
    genericBio(xBio, yBio, 218, 174, 53, desc);
}

void MainWindow::baschBio(int xBio, int yBio)
{
    QString desc("Un membre de l'Ordre des Chevaliers de Dalmasca, âgé de 36 ans. "
                 "Loyal envers ses compagnons et son roi, il change soudainement d'attitude pendant l'invasion archadienne. "
                 "Suite à ces évènements, on le déclarera mort. Mais est-ce vraiment le cas?");
    genericBio(xBio, yBio, 218, 86, 53, desc);
}

void MainWindow::asheBio(int xBio, int yBio)
{
    QString desc("La princesse héritière du trône de Dalmasca, âgée de 19 ans. "
                 "Pour quelle raison son 'oncle' déclarera sa mort, tout comme celle de Basch, après la chute de son royaume? "
                 "Quel est son ressenti suite à la perte de son pays, de son père et de son jeune époux? Quels choix fera-t-elle? ");
    genericBio(xBio, yBio, 243, 255, 124, desc);
}

void MainWindow::peneloBio(int xBio, int yBio)
{
    QString desc("Une jeune habitante de Rabanastre de 16 ans. "
                 "Amie de Vaan, elle aime la danse, servir ses amis, et travaille comme lui au magasin d'objets du vangaa Migelo. "
                 "Elle s'inquiète pour Vaan et est protectrice envers lui, au point de vouloir l'accompagner dans sa prochaine aventure.");
    genericBio(xBio, yBio, 249, 83, 227, desc);
}

void MainWindow::ennemiBio(int xBio, int yBio)
{
    QString desc("BOOOOOOOOOOOOOOOOOUH!");
    genericBio(xBio, yBio, 243, 237, 196, desc);
}

void MainWindow::genericBio(int x, int y, int r, int g, int b, QString& description)
{
    MyLabel* bio = new MyLabel(r, g, b, this);
    bio->setText(description);
    bio->setWordWrap(true);
    bio->move(x, y);
    bio->resize(460, 115);
    bio->setFrameStyle(QFrame::Box | QFrame::Sunken);
    bio->setMidLineWidth(1);
    bio->setAutoFillBackground(true);
    bio->setAlignment(Qt::AlignCenter);
    connect(bio, SIGNAL(clicked()), bio, SLOT(close()));
    bio->show();
}


/** Cette méthode, appelée avec le bouton Attaque, déclenche une attaque simple contre l'ennemi à l'écran */
void MainWindow::attaqueSimple(Allie& a, Ennemi& e)
{
    setLog("Apparition prépare l'action: ", "Glas", *log);

    // BOUM
    QMediaPlayer* soundShot = new QMediaPlayer();
    soundShot->setMedia(QUrl("qrc:/sons/shot.wav"));
    soundShot->play();

    // Création du panneau de description des actions
    deroulement = new MyLabel(this);
    deroulement->setFrameStyle(QFrame::Panel || QFrame::Raised);
    deroulement->setLineWidth(3);
    deroulement->setPalette(QColor("white"));
    deroulement->setAutoFillBackground(true);
    deroulement->move(300, 600);
    deroulement->resize(500, 100);
    deroulement->setAlignment(Qt::AlignCenter);
    deroulement->show();
    cout << "L'allié est: " << a.getNom() << " (" << a.getPV() << "/" << a.getPVmax()
         << ") et l'ennemi est: " << e.getNom() << " (" << e.getPV() << "/" << e.getPVmax() << ")" << endl;

    // Attaque et affichage du résultat
    sys.attaqueSimpleFusil(a, e);
    string detail = a.getNom() + " attaque! ---------- PV de " + e.getNom() + " : " + to_string(e.getPV()) + "/" + to_string(e.getPVmax());
    deroulement->setText(QString::fromStdString(detail));

    // Mise à disposition du bouton Recommencer lorsque le combat est terminé
    recommencer->move(810, 600);
    if(e.getPV() == 0)
    {
        e.setEtat("coma", true);
        string ko = "\n\n" + e.getNom() + " est dans le Coma! " + a.getNom() + " a gagné la partie!";
        deroulement->setText(deroulement->text() + QString::fromStdString(ko));
        connect(deroulement, SIGNAL(clicked()), deroulement, SLOT(clear()));
        recommencer->show();
    }
}

/** Cette méthode réinitialise les PV d'un ennemi et son état de Coma */
void MainWindow::reinitialiser(Ennemi& e)
{
    e.setPV(e.getPVmax());
    e.setEtat("coma", false);

    recommencer->setVisible(false);

    // Affichage du soin
    cout << "Les PV de " << e.getNom() << " ont été réinitialisés! " << e.getNom() << " est de nouveau prêt à combattre" << endl;
    cout << "PV: " << e.getPV() << "/" << e.getPVmax() << endl;
    string logtext = e.getNom() + " prépare l'action ";
    string highlight = "Soin5";
    string detail = "PV de " + e.getNom() + " : " + to_string(e.getPV()) + "/" + to_string(e.getPVmax());
    setLog(QString::fromStdString(logtext), QString::fromStdString(highlight), *log);
    deroulement->setText(QString::fromStdString(detail));

    balthierAttaque->setEnnemi(e); // renvoi de l'ennemi soigné à disposition du bouton d'Attaque
}

void MainWindow::soundOnOff()
{
    if(soundOn) // le son est activé et le slot a été enclenché
    {
        player->stop();
        soundOn = false;
        sound->setPixmap(QPixmap(":/images/sound_on.png"));
    }
    else // le son est désactivé et le slot a été enclenché
    {
        player->play();
        soundOn = true;
        sound->setPixmap(QPixmap(":/images/sound_off.png"));
    }
}

MainWindow::~MainWindow()
{

}
