#ifndef CIBLE_H
#define CIBLE_H

#include <string>
#include <map>
#include <vector>

#include "equipement.h"

class Cible
{
    public:
	Cible();
    Cible(std::string nom);
	
    std::string getNom() const;
    void setNom(const std::string &value);

    unsigned int getNiveau() const;
    void setNiveau(unsigned int value);

    unsigned int getPVmax() const;
    void setPVmax(unsigned int value);

    unsigned int getPMmax() const;
    void setPMmax(unsigned int value);

    unsigned int getPV() const;
    void setPV(unsigned int value);

    unsigned int getPM() const;
    void setPM(unsigned int value);

    std::map<std::string, bool> getEtat() const;
    bool getEtat(std::string etat);
    void setEtat(const std::map<std::string, bool> &value);
    void setEtat(std::string etat, bool value);

    std::map<std::string, unsigned int> getStats() const;
    unsigned int getStat(std::string stat);
    void setStats(const std::map<std::string, unsigned int> &value);
    void setStat(std::string stat, unsigned int value);

protected:
    std::string nom;
    unsigned int niveau;
    unsigned int PVmax;
    unsigned int PMmax;
    unsigned int PV;
    unsigned int PM;
    std::map<std::string, bool> etat;
    std::map<std::string, unsigned int> stats;
		
};

#endif // CIBLE_H
