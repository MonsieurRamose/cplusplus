#include "bijou.h"

Bijou::Bijou(std::string _nom, int _valeur): nom(_nom), valeur(_valeur) 
{
}

std::string Bijou::getNom()
{
    return nom;
}

long Bijou::getValeur()
{
    return valeur;
}