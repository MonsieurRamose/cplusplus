#include <iostream>
#include <string>
#include "heritiere.h"

Heritiere::Heritiere(std::string _nom) : Personnage(_nom), captive(false)
{
    this->possessions.push_back(new Bijou("emeraude", 1000));
    std::cout << "Je suis " << nom << " et je suis une heritiere" << std::endl;
    std::cout << "Je possede une emeraude d'une valeur de 1000" << std::endl;
}

bool Heritiere::estCaptive()
{
    return captive;
}

void Heritiere::recupereBijoux(Personnage &p)
{
  std::list<Bijou*> bijouxEnleve = p.enleveBijoux();

  for (std::list<Bijou*>::iterator it = bijouxEnleve.begin(); it != bijouxEnleve.end(); ++it)
  {
    possessions.push_back(*it);
  }
}

std::list<Bijou*> Heritiere::enleveBijoux()
{
  std::list<Bijou*> biens = possessions;
  possessions.clear();
  return biens;
}
