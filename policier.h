#ifndef POLICIER_H
#define POLICIER_H

#include <iostream>
#include <string>
#include "personnage.h"
#include "gangster.h"

class Policier : public Personnage {
private:
    Lieu *plieu;
    int reputation;
    double potDeVin;

public:
    Policier(std::string _nom, Lieu *_lieu, Lieu *pl);

    Lieu *getPlieu();

    void setReputation(int _reputation);

    int getReputation();

    double getPotDeVin() const;

    void setPotDeVin(double potDeVin);

    void libere(Personnage &p);

    // void attaque(Personnage &p);

    void attaque(Gangster &p);

    void incrementePopularite();

    void decrementePopularite();

    void interaction(Scenario &s);



};


#endif
