#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>
#include <iostream>
#include <list>
#include <random>

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

#include <mylabel.h>
#include <mytextedit.h>
#include <mybutton.h>
#include <balthier.h>
#include <apparition.h>
#include <systeme.h>


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
    void prepareTable();
    void prepareMenus();
    void genericBio(int x, int y, int r, int g, int b, QString& description);
    ~MainWindow();

private:
    MyLabel* sound;
    bool soundOn;
    QTextEdit* log;
    QWidget* tableau;
    MyLabel* deroulement;
    MyButton* balthierAttaque;
    MyButton* recommencer;
    QMediaPlayer* player;
    Balthier bal;
    Systeme sys;

public slots:

    void soundOnOff();
    void aPropos();
    void vaanBio(int xBio, int yBio);
    void balthierBio(int xBio, int yBio);
    void franBio(int xBio, int yBio);
    void baschBio(int xBio, int yBio);
    void asheBio(int xBio, int yBio);
    void peneloBio(int xBio, int yBio);

    void ennemiBio(int xBio, int yBio);

    void attaqueSimple(Allie &a, Ennemi &e);
    void reinitialiser(Ennemi& e);

};

#endif // MAINWINDOW_H
