#ifndef LIEU_H
#define LIEU_H

#include <QObject>
#include <QString>

class Lieu : public QObject
{
    Q_OBJECT

public:
    Lieu();
    Lieu(const QString& pic, const QString& zik);
    Lieu(const QString& pic, const QString& zik, bool invert);

    const QString getImage() const;

    const QString getMusique() const;

    bool getInversion() const;
    void setInversion(bool value);

private:
    const QString image;
    const QString musique;
    bool inversion;
};

#endif // LIEU_H
