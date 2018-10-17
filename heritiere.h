#ifndef HERITIER_H
#define HERITIER_H

#include <iostream>
#include <string>
#include "personnage.h"
#include "bijou.h"

class Heritiere : public Personnage
{
    private:
        bool captive;
    public:
        Heritiere(std::string _nom);
        bool estCaptive();
        // void recupereBijoux(Personnage &p);
        // std::list<Bijou*> enleveBijoux();
};

#endif
