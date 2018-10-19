#ifndef HERITIER_H
#define HERITIER_H

#include <iostream>
#include <string>
#include "personnage.h"
#include "bijou.h"
#include "scenario.h"
// #include "gangster.h"

class Heritiere : public Personnage {
private:
    bool captive;
    //Gangster* gangster;
public:
    Heritiere(std::string _nom, Lieu *_lieu);

    Heritiere(std::string _nom);

     ~Heritiere();

    bool estCaptive();

    void setCaptive(bool c);

     bool estEnlevee(Personnage &p);

     bool estLiberee(Personnage &p);


     void interaction(Scenario &s);
};

#endif
