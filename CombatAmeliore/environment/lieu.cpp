#include "lieu.h"

Lieu::Lieu()
    :QObject()
{
    inversion = false;
}

Lieu::Lieu(const QString& pic, const QString& zik):
    image(pic), musique(zik)
{
    inversion = false;
}

Lieu::Lieu(const QString& pic, const QString& zik, bool invert):
    image(pic), musique(zik)
{
    inversion = invert;
}

const QString Lieu::getImage() const
{
    return image;
}

const QString Lieu::getMusique() const
{
    return musique;
}

bool Lieu::getInversion() const
{
    return inversion;
}

void Lieu::setInversion(bool value)
{
    inversion = value;
}
