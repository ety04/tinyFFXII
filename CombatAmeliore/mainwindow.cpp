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

    player = new QMediaPlayer();
    prepareLieux();

    // Icône de musique
    sound = new MyLabel(this);
    if(carteActuelle->getInversion()) // c'est tout noir, nécessité d'inverser les couleurs
        sound->setPixmap(QPixmap(":/images/sound_off_inv.png"));
    else
        sound->setPixmap(QPixmap(":/images/sound_off.png"));
    sound->move(900, 50);
    sound->resize(40,40);
    connect(sound, SIGNAL(clicked()), this, SLOT(soundOnOff()));
    sound->show();

    setTheme(*carteActuelle);

    prepareLog();
    prepareTable();
    prepareMenus();
    prepareTeleportation();
    prepareEnnemis();

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
    setLog(tr("Ceci est le log par défaut"), *log);
    setLog(tr("Bienvenue dans mon petit programme!"), *log);
    log->show();
    cout << "Log: " << (getLog(log)).toStdString() << endl;

    // Création du log de déroulement des combats
    deroulement = new MyLabel(this);
}


/** Cette méthode sert à préparer le tableau central contenant les icônes des personnages, les actions et les cibles */
void MainWindow::prepareTable()
{
    // Création du tableau et de sa disposition
    tableau = new QWidget(this);
    tableau->move(150, 120);
    tableau->resize(700, 500);
    grille = new QGridLayout();

    // Création des en-têtes des colonnes du tableau
    QLabel* header1 = new QLabel(tr("Personnages"));
    QPalette headerpalette;
    headerpalette.setColor(QPalette::Window, Qt::white);
    headerpalette.setColor(QPalette::WindowText, Qt::red);
    header1->setPalette(headerpalette);
    header1->setAlignment(Qt::AlignCenter);
    header1->setAutoFillBackground(true);
    QLabel* header2 = new QLabel(tr("Action"));
    header2->setPalette(headerpalette);
    header2->setAlignment(Qt::AlignCenter);
    header2->setAutoFillBackground(true);
    QLabel* header3 = new QLabel(tr("Cibles"));
    header3->setPalette(headerpalette);
    header3->setAlignment(Qt::AlignCenter);
    header3->setAutoFillBackground(true);

    // Crétion des personnages
    bal = new Balthier();
    fra = new Fran();

    // Création des icônes personnage
    MyLabel* atche = new MyLabel();
    atche->setAlignment(Qt::AlignCenter);
    MyLabel* van = new MyLabel();
    van->setAlignment(Qt::AlignCenter);
    MyLabel* thablier = new MyLabel();
    thablier->setAlignment(Qt::AlignCenter);
    MyLabel* frAN = new MyLabel();
    frAN->setAlignment(Qt::AlignCenter);
    MyLabel* batch = new MyLabel();
    batch->setAlignment(Qt::AlignCenter);
    MyLabel* peuneulo = new MyLabel();
    peuneulo->setAlignment(Qt::AlignCenter);
    MyLabel* larsa = new MyLabel();
    larsa->setAlignment(Qt::AlignCenter);

    van->setPixmap(QPixmap(":/images/persos/vaan.png"));
    atche->setPixmap(QPixmap(":/images/persos/ashe2.png"));
    thablier->setPixmap(QPixmap(":/images/persos/balthier.png"));
    frAN->setPixmap(QPixmap(":/images/persos/fran.png"));
    batch->setPixmap(QPixmap(":/images/persos/basch.png"));
    peuneulo->setPixmap(QPixmap(":/images/persos/penelo.png"));
    //larsa->setPixmap(QPixmap(":/images/persos/larsa.png"));

    // Liaison des icônes avec leur (courte) biographie
    connect(van, SIGNAL(labelClicked(int,int)), this, SLOT(vanBio(int, int)));
    connect(thablier, SIGNAL(labelClicked(int,int)), this, SLOT(thablierBio(int,int)));
    connect(frAN, SIGNAL(labelClicked(int,int)), this, SLOT(frANBio(int,int)));
    connect(batch, SIGNAL(labelClicked(int,int)), this, SLOT(batchBio(int,int)));
    connect(atche, SIGNAL(labelClicked(int,int)), this, SLOT(atcheBio(int,int)));
    connect(peuneulo, SIGNAL(labelClicked(int,int)), this, SLOT(peuneuloBio(int,int)));

    // Création des boutons d'action
    QIcon epee(QPixmap(":/images/excalibur.png"));
    QIcon flamme(QPixmap(":/images/flame.png"));
    QIcon fusil(QPixmap(":/images/arcturus.png"));
    QPushButton* vanAttaque = new QPushButton(epee, tr("Attaquer"));
    thablierAttaque = new MyButton(fusil, tr("Attaquer"), bal);
    frANAttaque = new MyButton(flamme, tr("Feu"), fra);
    QPushButton* batchAttaque = new QPushButton(epee, tr("Attaquer"));
    QPushButton* atcheAttaque = new QPushButton(epee, tr("Attaquer"));
    QPushButton* peuneuloAttaque = new QPushButton(epee, tr("Attaquer"));

    // Connexion des boutons Attaque et Recommencer avec leurs fonctions respectives
    recommencer = new MyButton(tr("Recommencer"), this);
    connect(recommencer, SIGNAL(buttonClickedForReset(Ennemi&)), this, SLOT(reinitialiser(Ennemi&)));
    recommencer->setVisible(false);

    connect(thablierAttaque, SIGNAL(buttonClickedForBattle(Allie*,Ennemi&)), this, SLOT(attaqueSimple(Allie*,Ennemi&)));
    connect(frANAttaque, SIGNAL(buttonClickedForBattle(Allie*,Ennemi&)), this, SLOT(feuSimple(Allie*,Ennemi&)));


    // Ajout des éléments précédents à la disposition du tableau
    grille->addWidget(header1, 0, 0);
    grille->addWidget(header2, 0, 1);
    grille->addWidget(header3, 0, 2);
    grille->addWidget(van, 1, 0);
    grille->addWidget(thablier, 2, 0);
    grille->addWidget(frAN, 3, 0);
    grille->addWidget(batch, 4, 0);
    grille->addWidget(atche, 5, 0);
    grille->addWidget(peuneulo, 6, 0);
    grille->addWidget(vanAttaque, 1, 1);
    grille->addWidget(thablierAttaque, 2, 1);
    grille->addWidget(frANAttaque, 3, 1);
    grille->addWidget(batchAttaque, 4, 1);
    grille->addWidget(atcheAttaque, 5, 1);
    grille->addWidget(peuneuloAttaque, 6, 1);

    tableau->setLayout(grille);

    //this->setCentralWidget(tableau);
    tableau->show();
}

/** Cette méthode sert à préparer la barre de menus de la fenêtre globale */
void MainWindow::prepareMenus()
{
    QMenu* fichier = menuBar()->addMenu(tr("Fichier"));
    QAction* quitter = new QAction(tr("&Quitter"), this);
    quitter->setIcon(QIcon(":/images/oofl.png"));
    quitter->setShortcut(QKeySequence(tr("Ctrl+Q", "Raccourci clavier pour Quitter")));
    connect(quitter, SIGNAL(triggered()), qApp, SLOT(quit()));
    fichier->addAction(quitter);

    QMenu* autre = menuBar()->addMenu("?");
    QAction* apropos = new QAction(tr("&A propos"), this);
    connect(apropos, SIGNAL(triggered()), this, SLOT(aPropos()));
    autre->addAction(apropos);

    menuBar()->setPalette(QPalette(QColor("grey")));
}

/** Cette méthode initialise les lieux possibles de la fenêtre globale */
void MainWindow::prepareLieux()
{
    Lieu* coteDePhon = new Lieu(":/images/lieux/phon_coast.png", "qrc:/sons/phon.mp3");
    Lieu* foretDeSalika = new Lieu(":/images/lieux/salika.png", "qrc:/sons/salika.mp3", true);
    Lieu* desertEst = new Lieu(":/images/lieux/desert_est.png", "qrc:/sons/desert_est.mp3");
    Lieu* gorgesDeParamina = new Lieu(":/images/lieux/paramina.png", "qrc:/sons/paramina.mp3");
    lieux["phon"] = coteDePhon;
    lieux["salika"] = foretDeSalika;
    lieux["desert_est"] = desertEst;
    lieux["paramina"] = gorgesDeParamina;
    carteActuelle = lieux.begin()->second; // obtenir la valeur du premier élément de la map
}

/** Cette méthode initialise le cristal de téléportation et sa liste déroulante */
void MainWindow::prepareTeleportation()
{
    MyLabel* cristal = new MyLabel(this);
    cristal->setPixmap(QPixmap(":/images/cristal.png"));
    cristal->move(10, 530);
    cristal->resize(135, 135);
    cristal->show();

    teleportation = new MyComboBox(this);
    teleportation->addItem(tr("Côte de Phon"), QVariant::fromValue(lieux["phon"]));
    teleportation->addItem(tr("Forêt de Salika"), QVariant::fromValue(lieux["salika"]));
    teleportation->addItem(tr("Désert Est"), QVariant::fromValue(lieux["desert_est"]));
    teleportation->addItem(tr("Gorges de Paramina"), QVariant::fromValue(lieux["paramina"]));
    teleportation->resize(150, 30);
    teleportation->move(10, 490);
    teleportation->setVisible(false);

    connect(teleportation, SIGNAL(activated(int)), this, SLOT(seTeleporter(int)));
    connect(cristal, SIGNAL(clicked()), teleportation, SLOT(teleportOnOff()));

}

/** Cette méthode initialise les ennemis possibles et le bouton de changement */
void MainWindow::prepareEnnemis()
{
    monstreActuel = new Ennemi();

    // Création des ennemis
    Apparition* ap = new Apparition();
    Ennemi* ma = new Mandragore();
    Treant* tr = new Treant();
    Gelee* ge = new Gelee();
    Poulatrice* po = new Poulatrice();
    DestrierFantome* df = new DestrierFantome();
    ennemis["apparition"] = ap;
    ennemis["mandragore"] = ma;
    ennemis["treant"] = tr;
    ennemis["gelee"] = ge;
    ennemis["poulatrice"] = po;
    ennemis["destrier_fantome"] = df;

    MyLabel* change = new MyLabel(this);
    change->setPixmap(QPixmap(":/images/change.png"));
    grille->addWidget(change, 6, 2, 1, 1, Qt::AlignCenter);
    connect(change, SIGNAL(clicked()), this, SLOT(changeEnnemi()));

    setEnnemi(*ma);
}

void MainWindow::setLog(const QString& text, QTextEdit& boiteDeLog)
{
    boiteDeLog.setTextColor(QColor("black"));
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
    apropos->setText(tr("Ceci est une application (très) basique développée à but expérimental et ludique."));
    apropos->append(tr("Les outils utilisés sont le langage C++ et la bibliothèque Qt 5.6 (avec Qt Creator 4)."));
    apropos->append(tr("FINAL FANTASY XII appartient à SQUARE ENIX CO., LTD. Ce produit est purement à titre de fan."));
    apropos->append("Version 0.3 ~ Copyleft Ety, 2016");
    apropos->setReadOnly(true);
    apropos->setFrameStyle(QFrame::Box);
    connect(apropos, SIGNAL(clicked()), apropos, SLOT(close()));
    apropos->show();
}

/** Les méthodes suivantes initialisent les biographies des différents personnages */

void MainWindow::vanBio(int xBio, int yBio)
{
    QString desc(tr("Un jeune garçon de 17 ans vivant à Rabanastre. "
                  "Ses principales occupations sont tuer des rats dans les égouts et voler les impériaux. "
                  "Son rêve est de devenir pirate de l'air, mais est-ce là tout?"));
    genericBio(xBio, yBio, 119, 80, 239, desc);
}

void MainWindow::thablierBio(int xBio, int yBio)
{
    QString desc(tr("Un pirate de l'air de 22 ans sillonnant les cieux d'Ivalice à bord de son vaisseau, le Sillage. "
                 "Il est attiré par les trésors, et notamment par une certaine pierre précieuse cachée à Rabanastre. "
                 "Cependant, son passé et ses origines restent assez obscurs."));
    genericBio(xBio, yBio, 78, 183, 106, desc);
}

void MainWindow::frANBio(int xBio, int yBio)
{
    QString desc(tr("Une viéra d'âge inconnu. Elle est la partenaire pirate de Balthier. "
                 "Habile avec tout type d'armes, elle maîtrise également les mécanismes du Sillage. "
                 "Elle a une vaste connaissance d'Ivalice, mais est mal à l'aise avec une substance nommée 'myste'. De quoi s'agit-il?"));
    genericBio(xBio, yBio, 218, 174, 53, desc);
}

void MainWindow::batchBio(int xBio, int yBio)
{
    QString desc(tr("Un membre de l'Ordre des Chevaliers de Dalmasca, âgé de 36 ans. "
                 "Loyal envers ses compagnons et son roi, il change soudainement d'attitude pendant l'invasion archadienne. "
                 "Suite à ces évènements, on le déclarera mort. Mais est-ce vraiment le cas?"));
    genericBio(xBio, yBio, 218, 86, 53, desc);
}

void MainWindow::atcheBio(int xBio, int yBio)
{
    QString desc(tr("La princesse héritière du trône de Dalmasca, âgée de 19 ans. "
                 "Pour quelle raison son 'oncle' déclarera sa mort, tout comme celle de Basch, après la chute de son royaume? "
                 "Quel est son ressenti suite à la perte de son pays, de son père et de son jeune époux? Quels choix fera-t-elle? "));
    genericBio(xBio, yBio, 243, 255, 124, desc);
}

void MainWindow::peuneuloBio(int xBio, int yBio)
{
    QString desc(tr("Une jeune habitante de Rabanastre de 16 ans. "
                 "Amie de Vaan, elle aime la danse, servir ses amis, et travaille comme lui au magasin d'objets du vangaa Migelo. "
                 "Elle s'inquiète pour Vaan et est protectrice envers lui, au point de vouloir l'accompagner dans sa prochaine aventure."));
    genericBio(xBio, yBio, 249, 83, 227, desc);
}

void MainWindow::ennemiBio(int xBio, int yBio, QString& bio)
{
    QString desc(bio);
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

/** Cette méthode affiche le cri du monstre au-dessus de son image lorsqu'il contre-attaque */
void MainWindow::bioCombat(Ennemi &e)
{
    cout << "biocombat appelé" << endl;
    MyLabel* bio = new MyLabel(243, 237, 196, this);
    bio->setText(e.getCri());
    bio->setWordWrap(true);
    bio->move(430, 30);
    bio->resize(460, 115);
    bio->setFrameStyle(QFrame::Box | QFrame::Sunken);
    bio->setMidLineWidth(1);
    bio->setAutoFillBackground(true);
    bio->setAlignment(Qt::AlignCenter);
    bio->show();
    timerBioCombat = new MyTimer("bioCombat");
    timerBioCombat->start(1500);
    connect(timerBioCombat, SIGNAL(timeout()), bio, SLOT(close()));
}

/** Cette méthode, appelée avec le bouton Attaque, déclenche une attaque simple contre l'ennemi à l'écran */
void MainWindow::attaqueSimple(Allie* a, Ennemi& e)
{
    setLog(e.getNom() + tr(" prépare l'action: "), e.getActionPrincipale(), *log);

    // BOUM
    soundBim = new QMediaPlayer();
    soundBim->setMedia(QUrl("qrc:/sons/shot.wav"));
    soundBim->play();

    // Initialisation du panneau de description des actions
    deroulement->setFrameStyle(QFrame::Panel || QFrame::Raised);
    deroulement->setLineWidth(3);
    deroulement->setPalette(QColor("white"));
    deroulement->setAutoFillBackground(true);
    deroulement->move(300, 600);
    deroulement->resize(500, 100);
    deroulement->setAlignment(Qt::AlignCenter);
    deroulement->show();
    cout << "L'allié est: " << a->getNom().toStdString() << " (" << a->getPV() << "/" << a->getPVmax()
         << ") avec comme butin: " << ((a->getButins().empty())?"rien":(a->getButins().at(0)).toStdString())
         << "; et l'ennemi est: " << e.getNom().toStdString() << " (" << e.getPV() << "/" << e.getPVmax() << ")" << endl;

    // Attaque et affichage du résultat
    sys.attaqueSimpleFusil(*a, e);
    affichageAttaque(*a, e);

    // Mise à disposition du bouton Recommencer lorsque le combat est terminé
    recommencer->move(810, 600);
    if(e.getPV() == 0)
    {
        e.setEtat("coma", true);
        QString ko = "\n\n" + e.getNom() + tr(" est dans le Coma! ") + a->getNom() + tr(" a gagné la partie!");
        deroulement->setText(deroulement->text() + ko);
        connect(deroulement, SIGNAL(clicked()), deroulement, SLOT(clear()));
        a->addButin(e.getButin());
        setLog("\n" + a->getNom() + tr(" obtient: "), e.getButin(), *log);
        a->addExp(e.getExpDonnee());
        QString exp = QString::fromStdString(to_string(e.getExpDonnee()));
        deroulement->setText(deroulement->text() + QString("\n" + a->getNom() + tr(" gagne ") + exp + tr(" points d'expérience")));
        recommencer->show();
    }
    else
        // Au tour du monstre d'attaquer!
    {
        cout << "1°°° Combat pas encore terminé --> contre-attaque" << endl;
        timer1 = new MyTimer("timerAttaqueRetourPréparation", e, a);
        connect(timer1, SIGNAL(timeoutNowAttack(Ennemi&,Allie*)), this, SLOT(attaqueRetourPreparation(Ennemi&,Allie*)));
        timer1->start(2000);
    }
}

/** Cette méthode, appelée avec le bouton Feu, lance une attaque Feu2 sur l'ennemi à l'écran */
void MainWindow::feuSimple(Allie *a, Ennemi &e)
{
    setLog(e.getNom() + tr(" prépare l'action: "), e.getActionPrincipale(), *log);

    // BOUM
    soundBim = new QMediaPlayer();
    soundBim->setMedia(QUrl("qrc:/sons/feu2.wav"));
    soundBim->play();

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
    cout << "L'allié est: " << a->getNom().toStdString() << " (" << a->getPV() << "/" << a->getPVmax()
         << ") avec comme butin: " << ((a->getButins().empty())?"rien":(a->getButins().at(0)).toStdString())
         << "; et l'ennemi est: " << e.getNom().toStdString() << " (" << e.getPV() << "/" << e.getPVmax() << ")" << endl;

    // Attaque et affichage du résultat
    sys.feu2(*a, e);
    affichageAttaque(*a, e);

    // Mise à disposition du bouton Recommencer lorsque le combat est terminé
    recommencer->move(810, 600);
    if(e.getPV() == 0)
    {
        e.setEtat("coma", true);
        QString ko = "\n\n" + e.getNom() + tr(" est dans le Coma! ") + a->getNom() + tr(" a gagné la partie!");
        deroulement->setText(deroulement->text() + ko);
        connect(deroulement, SIGNAL(clicked()), deroulement, SLOT(clear()));
        a->addButin(e.getButin());
        setLog("\n" + a->getNom() + tr(" obtient: "), e.getButin(), *log);
        a->addExp(e.getExpDonnee());
        QString exp = QString::number(e.getExpDonnee());
        deroulement->setText(deroulement->text() + QString("\n" + a->getNom() + tr(" gagne ") + exp + tr(" points d'expérience")));
        recommencer->show();
    }
    else
        // Au tour du monstre d'attaquer!
    {
        cout << "1°°° Combat pas encore terminé --> contre-attaque" << endl;
        timer1 = new MyTimer("timerAttaqueRetourPréparation", e, a);
        connect(timer1, SIGNAL(timeoutNowAttack(Ennemi&,Allie*)), this, SLOT(attaqueRetourPreparation(Ennemi&,Allie*)));
        timer1->start(2000);
    }
}

/** Les méthodes suivantes servent à la contre-attaque du monstre */
void MainWindow::attaqueRetourPreparation(Ennemi &e, Allie *a)
{
    cout << "2°°° Méthode de préparation" << endl;
    cout << e.getNom().toStdString() << " ne se laisse pas faire face à " << a->getNom().toStdString() << "!" << endl;
    timer1->stopAndBlock();
    deroulement->setText(tr("CONTRE-ATTAQUE!"));
    bioCombat(e);
    setLog(e.getNom() + tr(" prépare l'action: "), tr("Charge"), *log);
    timer2 = new MyTimer("timerAttaqueRetour", e, a);
    connect(timer2, SIGNAL(timeoutNowAttack(Ennemi&,Allie*)), this, SLOT(attaqueRetour(Ennemi&,Allie*)));
    timer2->start(1500);
}

void MainWindow::attaqueRetour(Ennemi &e, Allie* a)
{
    cout << "3°°° Méthode d'attaque du monstre" << endl;
    cout << "L'allié est: " << a->getNom().toStdString() << " (" << a->getPV() << "/" << a->getPVmax()
         << ") et l'ennemi est: " << e.getNom().toStdString() << " (" << e.getPV() << "/" << e.getPVmax() << ")" << endl;
    timer2->stopAndBlock(); timerBioCombat->stopAndBlock();
    soundBim->setMedia(QUrl("qrc:/sons/punch.wav"));
    soundBim->play();
    sys.attaqueMonstre(e, *a);
    affichageAttaque(e, *a);
    if(a->getPV() == 0)
    {
        setLog(a->getNom() + tr(" s'effondre..."), *log);
    }
}

/** Cette méthode s'occupe d'afficher une ligne ou deux sur le déroulement d'une attaque */
void MainWindow::affichageAttaque(Cible &attaquant, Cible &victime)
{
    QString detail = attaquant.getNom() + tr(" attaque! ---------- PV de ") + victime.getNom() + " : "
            + QString::number(victime.getPV()) + "/" + QString::number(victime.getPVmax());
    deroulement->setText(detail);
    cout << "/!\\ Les PV de " << victime.getNom().toStdString() << " sont à présent de "
         << victime.getPV() << " sur " << victime.getPVmax() << endl;
}


/** Cette méthode réinitialise les PV d'un ennemi et son état de Coma */
void MainWindow::reinitialiser(Ennemi& e)
{
    e.setPV(e.getPVmax());
    e.setEtat("coma", false);

    recommencer->setVisible(false);

    // Affichage du soin
    cout << "Les PV de " << e.getNom().toStdString() << " ont été réinitialisés! "
         << e.getNom().toStdString() << " est de nouveau prêt à combattre" << endl;
    cout << "PV: " << e.getPV() << "/" << e.getPVmax() << endl;
    QString logtext = e.getNom() + tr(" prépare l'action ");
    QString highlight = tr("Soin5");
    QString detail = tr("PV de ") + e.getNom() + " : " + QString::number(e.getPV()) + "/" + QString::number(e.getPVmax());
    setLog(logtext, highlight, *log);
    deroulement->setText(detail);

    thablierAttaque->setEnnemi(e); // renvoi de l'ennemi soigné à disposition du bouton d'Attaque
    frANAttaque->setEnnemi(e);
}

/** Ce slot se charge d'activer/désactiver la musique de fond et change les icônes en conséquence */
void MainWindow::soundOnOff()
{
    if(soundOn) // le son est activé et le slot a été enclenché
    {
        player->stop();
        soundOn = false;
        if(carteActuelle->getInversion())
            sound->setPixmap(QPixmap(":/images/sound_on_inv.png"));
        else
            sound->setPixmap(QPixmap(":/images/sound_on.png"));
    }
    else // le son est désactivé et le slot a été enclenché
    {
        player->play();
        soundOn = true;
        if(carteActuelle->getInversion())
            sound->setPixmap(QPixmap(":/images/sound_off_inv.png"));
        else
            sound->setPixmap(QPixmap(":/images/sound_off.png"));
    }
}

/** Cette méthode modifie l'arrière-plan de la fenêtre principale avec l'URI donnée */
void MainWindow::setArrPlan(const QString &image)
{
    QPalette p(palette());
    p.setBrush(QPalette::Window, QBrush(QPixmap(image)));
    setPalette(p);
}

/** Cette méthode modifie la musique de fond avec l'URI donnée */
void MainWindow::setMusique(const QString &musique)
{
    player->setMedia(QUrl(musique));
    player->setVolume(40);
    player->play();
    if(carteActuelle->getInversion()) // c'est tout noir, nécessité d'inverser les couleurs
        sound->setPixmap(QPixmap(":/images/sound_off_inv.png"));
    else
        sound->setPixmap(QPixmap(":/images/sound_off.png"));
    soundOn = true;
}

/** Ces méthodes modifient le thème (arrière-plan + musique) selon le lieu en paramètre */
void MainWindow::setTheme(Lieu& nouveauLieu)
{
    carteActuelle = &nouveauLieu;
    setArrPlan(nouveauLieu.getImage());
    setMusique(nouveauLieu.getMusique());
}

void MainWindow::setTheme(const QString& nomDeZone)
{
    setTheme(*lieux[nomDeZone]);
}

/** Cette méthode permet de changer l'ennemi à l'écran */
void MainWindow::setEnnemi(Ennemi &ennemi)
{
    // On supprime le monstre affiché avant d'en ramener un nouveau
    if(monstreActuel->getNom() != "")
        grille->itemAtPosition(1, 2)->widget()->deleteLater();

    // On crée l'image du nouveau monstre
    MyLabel* enn = new MyLabel();
    enn->setPixmap(QPixmap(ennemi.getLienImage()));
    enn->setBio(ennemi.getCri());
    thablierAttaque->setEnnemi(ennemi);
    frANAttaque->setEnnemi(ennemi);
    recommencer->setEnnemi(ennemi);
    connect(enn, SIGNAL(bigLabelClicked(int,int,QString&)), this, SLOT(ennemiBio(int,int,QString&)));
    grille->addWidget(enn, 1, 2, 6, 1);

    grille->itemAtPosition(6, 2)->widget()->raise(); // on rehausse l'image de changement de monstre pour qu'elle reste visible

    monstreActuel = &ennemi;
}

void MainWindow::setEnnemi(QString &ennemi)
{
    Ennemi* enn = ennemis[ennemi];
    setEnnemi(*enn);
}

/** Cette méthode change le thème de la fenêtre principale selon le lieu sélectionné dans la liste déroulante du cristal orange */
void MainWindow::seTeleporter(int index)
{
    int currentIndex = teleportation->currentIndex();
    printf("Choix numéro %d sélectionné - Index courant: %d \n", index, currentIndex);
    Lieu* currentData = qvariant_cast<Lieu*>(teleportation->currentData());
    cout << "LIEU: " << teleportation->currentText().toStdString() << " - INVERSION: " << boolalpha << currentData->getInversion() << endl;
    QMediaPlayer* son = new QMediaPlayer();
    son->setMedia(QUrl("qrc:/sons/teleport.wav"));
    son->play();
    setTheme(*currentData);
    teleportation->setVisible(false);
}

/** Ce slot permet de déclencher le changement d'ennemi à l'écran
    Premier élément de la map = ennemis.begin()
    Dernier élément de la map = ennemis.end() - 1    // ennemis.end() pointe sur celui suivant la fin */
void MainWindow::changeEnnemi()
{
    cout << "Ennemi 1: " << ennemis.begin()->second->getNom().toStdString() << endl;
    cout << "Ennemi 2: " << (--ennemis.end())->second->getNom().toStdString() << endl;
    QString nom = monstreActuel->getId();
    cout << "Ennemi actuel: " << nom.toStdString() << endl;
    map<QString, Ennemi*>::iterator it0, it;
    it0 = ennemis.find(nom);
    if(it0 == --ennemis.end()) // si on est à la fin de la map
        it = ennemis.begin(); // on revient au début
    else
        it = next(it0); // sinon on prend l'élément suivant
    cout << "Ennemi suivant: " << it->second->getId().toStdString() << endl;
    setEnnemi(*(it->second));
    setLog(it->second->getNom() + tr(" prépare l'action: "), it->second->getActionPrincipale(), *log);
    QString changement = tr("L'ennemi est ") + it->second->getNom() + tr(" --- (PV: ")
            + QString::number(it->second->getPV()) + "/" + QString::number(it->second->getPVmax()) + ")";
    deroulement->setText(changement);
}

MainWindow::~MainWindow()
{

}
