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
  Personnage::estLiberee(p);
  if((p.getPers() == NULL) && !(this->estCaptive()))
  {
    return true;
  }
  return false;

}

Heritiere::Heritiere(const char *_nom, Lieu *_lieu) {
    std::cout << "Je suis " << nom << " et je suis une heritiere, et je viens d'arriver dans la ville " << _lieu->getNom() << std::endl;
    this->possessions.push_back(new Bijou("emeraude", 1000));
    std::cout << "Je possede une emeraude d'une valeur de 1000" << std::endl;
}

void Heritiere::interaction(Scenario &s) {
    std::cout << "Interaction heritiere" << std::endl;
    for(int j = 0; j = s.getPersonnages(); j++) {
        Personnage* personnage = s.getPersonnages()[j];
        if(personnage->getLieu()->getNom().compare(this->getLieu()->getNom()) ) {
            personnage->enleve(*this);
            personnage->libere(*this);
        }
    }


}

Heritiere::~Heritiere() {

}

void Heritiere::libere(Personnage &p) {
    Personnage::libere(p);
}

void Heritiere::attaque(Personnage &p) {
    Personnage::attaque(p);
}

bool Heritiere::estCapture(Personnage &p) {
    return Personnage::estCapture(p);
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
