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

Heritiere::Heritiere(std::string _nom, Lieu * _lieu): Personnage(_nom, _lieu), captive(false)
 {
    std::cout << "Je suis " << nom << " et je suis une heritiere, et je viens d'arriver dans la ville " << _lieu->getNom() << std::endl;
    std::cout << "Je possede une emeraude d'une valeur de 1000" << std::endl;
    this->possessions.push_back(new Bijou("emeraude", 1000));
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

void Heritiere::interaction(Scenario &s) {
    std::cout << "Interaction heritiere" << std::endl;
    for(int j = 0; j < s.getNbPers(); j++) {
        Personnage* personnage = s.getPersonnages()[j];
        if(personnage->getLieu()->getNom().compare(this->getLieu()->getNom()) ) {
            personnage->enleve(*this);
            personnage->libere(*this);
        }
    }


}

Heritiere::~Heritiere() {

}


bool Heritiere::testHeritiere(Scenario& s) {
  bool ok = false;


  estEnlevee();
  estLiberee();
  estCaptive();
}
