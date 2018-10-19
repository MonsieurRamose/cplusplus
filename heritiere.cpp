#include <iostream>
#include <string>
#include "heritiere.h"

Heritiere::Heritiere(std::string _nom) : Personnage(_nom), captive(false)
{
    this->possessions.push_back(new Bijou("emeraude", 1000));
    std::cout << "Je suis " << nom << " et je suis une heritiere" << std::endl;
    std::cout << "Je possede une emeraude d'une valeur de 1000" << std::endl;
    //gangster  = NULL;
}

bool Heritiere::estCaptive()
{
    return captive;
}
void Heritiere::setCaptive(bool c)
{
  captive = c;
}
bool Heritiere::estEnlevee(Personnage& p)
{
  // si l'heritiere est enlevee par le gangster passé en paramètre
  Personnage::estEnlevee(p);
  //j ai retiré && p.estCaptive()
  if(p.getPers() != NULL && p.getPers()->getNom().compare(this->getNom()) )
  {
    return true;
  }
  return false;
}
bool Heritiere::estLiberee(Personnage& p)
{
  /* regarder si l heritiere est liberée par la personne p qui l a enlevé*/
  
  if((p.getPers() == NULL) && !(this->estCaptive()))
  {
    return true;
  }
  return false;

}
// Gangster* Heritiere::getGangster()
// {
//   return gangster;
// }
// void heritiere::setGangster(Gangster* g)
//  {
//    gangster = g;
//  }

/*
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
}*/
