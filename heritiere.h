#ifndef HERITIER_H
#define HERITIER_H

#include <iostream>
#include <string>
#include "personnage.h"
#include "bijou.h"
// #include "gangster.h"

class Heritiere : public Personnage {
private:
    bool captive;
    //Gangster* gangster;
public:
    Heritiere(const char *_nom, Lieu *_lieu);

    Heritiere(std::string _nom);

     ~Heritiere();

    bool estCaptive();

    void setCaptive(bool c);

    // Gangster* getGangster();
    // void setGangster(Gangster* g);
    // void recupereBijoux(Personnage &p);
    // std::list<Bijou*> enleveBijoux();
     void libere(Personnage &p);

     void attaque(Personnage &p);

     bool estEnlevee(Personnage &p);

     bool estLiberee(Personnage &p);

     void enleve(Personnage &p);

     bool estCapture(Personnage &p);
     void interaction(Scenario &s);
};

#endif
