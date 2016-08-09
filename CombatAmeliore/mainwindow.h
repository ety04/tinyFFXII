#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>
#include <iostream>
#include <list>
#include <random>
#include <map>
#include <iterator>

#include <QMainWindow>

#include <QStyle>
#include <QDesktopWidget>

#include <QApplication>
#include <QLabel>
#include <QTextEdit>
#include <QTableWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QMenu>
#include <QMenuBar>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QComboBox>

#include "helpers/mylabel.h"
#include "helpers/mytextedit.h"
#include "helpers/mybutton.h"
#include "helpers/mytimer.h"
#include "helpers/mycombobox.h"
#include "target/balthier.h"
#include "target/fran.h"
#include "target/apparition.h"
#include "target/mandragore.h"
#include "target/destrierfantome.h"
#include "target/poulatrice.h"
#include "target/gelee.h"
#include "target/treant.h"
#include "environment/lieu.h"
#include "systeme.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    MainWindow(int width, int height);
    void setLog(const QString& text, QTextEdit& boiteDeLog);
    void setLog(const QString& text, const QString& textHighlight, QTextEdit& boiteDeLog);
    const QString getLog(QTextEdit* boiteDeLog);
    void prepareLog();
    void prepareDeroulement();
    void prepareTable();
    void prepareMenus();
    void prepareLieux();
    void prepareTeleportation();
    void prepareEnnemis();
    void prepareArmes();
    void genericBio(int x, int y, int r, int g, int b, QString& description); 
    void bioCombat(Ennemi& e);
    void setArrPlan(const QString& image);
    void setMusique(const QString& musique);
    void setTheme(Lieu& nouveauLieu);
    void setTheme(const QString& nomDeZone);
    void setEnnemi(Ennemi& ennemi);
    void setEnnemi(QString &ennemi);
    ~MainWindow();

private:
    QGridLayout* grille;
    MyLabel* sound;
    bool soundOn;
    QTextEdit* log;
    QWidget* tableau;
    MyLabel* deroulement;
    MyButton* thablierAttaque, *frANAttaque;
    MyButton* recommencer;
    QMediaPlayer* player;
    QMediaPlayer* soundBim;
    MyTimer* timer1, *timer2, *timerBioCombat;
    Balthier* bal;
    Fran* fra;
    Systeme sys;
    std::map<QString, Lieu*> lieux;
    Lieu* carteActuelle;
    MyComboBox* teleportation;
    std::map<QString, Ennemi*> ennemis;
    Ennemi* monstreActuel;
    MyComboBox* changementFusils;

public slots:

    void soundOnOff();
    void aPropos();
    void vanBio(int xBio, int yBio);
    void thablierBio(int xBio, int yBio);
    void frANBio(int xBio, int yBio);
    void batchBio(int xBio, int yBio);
    void atcheBio(int xBio, int yBio);
    void peuneuloBio(int xBio, int yBio);

    void ennemiBio(int xBio, int yBio, QString &bio);

    void attaqueSimple(Allie *a, Ennemi &e);
    void feuSimple(Allie *a, Ennemi &e);
    void attaqueRetourPreparation(Ennemi &e, Allie *a);
    void attaqueRetour(Ennemi &e, Allie *a);
    void affichageAttaque(Cible& attaquant, Cible& victime);
    void reinitialiser(Ennemi& e);

    void seTeleporter(int index);
    void changeEnnemi();

};

#endif // MAINWINDOW_H
