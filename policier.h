#ifndef POLICIER_H
#define POLICIER_H

#include <iostream>
#include <string>
#include "personnage.h"
//#include "lieu.h"

class Policier :public Personnage
{
    private:
        Lieu* plieu;
        int reputation;

    public:
        Policier(std::string _nom, Lieu* _lieu, Lieu* pl);
        Lieu* getPlieu();
        void setReputation(int _reputation);
        int getReputation();
      /*  void libere(Personnage &p);
        void attaque(Personnage& p);
        void incrementePopularite();
        void decrementePopularite();*/


};


#endif
