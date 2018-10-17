#ifndef POLICIER_H
#define POLICIER_H

#include <iostream>
#include <string>
#include "personnage.h"
//#include "lieu.h"

class Policier :public Personnage
{
    private:
        Lieu* lieu;
        int reputation;

    public:
        Policier(std::string _nom, Lieu* _lieu);
        Lieu* getLieu();
        void setReputation(int _reputation);
        int getReputation();
      /*  void recupereBijoux(Personnage &p);
        std::list<Bijou*> enleveBijoux();*/
};


#endif
