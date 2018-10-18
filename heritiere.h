#ifndef HERITIER_H
#define HERITIER_H

#include <iostream>
#include <string>
#include "personnage.h"
#include "bijou.h"
// #include "gangster.h"

class Heritiere : public Personnage
{
    private:
        bool captive;
        //Gangster* gangster;
    public:
        Heritiere(std::string _nom);
        bool estCaptive();
        // Gangster* getGangster();
        // void setGangster(Gangster* g);
        // void recupereBijoux(Personnage &p);
        // std::list<Bijou*> enleveBijoux();
};

#endif
