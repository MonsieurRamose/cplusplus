#ifndef BIJOU_H
#define BIJOU_H

#include <iostream>
#include <string>

class Bijou
{
    private:
        std::string nom;
        long valeur;

    public:
        Bijou(std::string _nom, int _valeur);
        std::string getNom();
        long getValeur();

};

#endif
