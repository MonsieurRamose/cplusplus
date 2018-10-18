#include <iostream>
#include <string>
#include "gangster.h"

Gangster::Gangster(std::string _nom, std::string _gang) : Personnage(_nom), gang(_gang), recompense(100), enPrison(false), butin(0)
{
  //heritiere = NULL;
  std::cout << "Je suis " << this->getNom() << ", membre du gang " << gang << std::endl;
}

std::string Gangster::getGang()
{
  return gang;
}
long Gangster::getRecompense()
{
  return recompense;
}
void  Gangster::setRecompense(long rec)
{
  recompense = rec;
}
bool Gangster::estEnPrison()
{
  return enPrison;
}

void Gangster::setPrison(bool b)
{
  enPrison = b;
}
long Gangster::getButin()
{
  return butin;
}

void Gangster::setButin(long bt)
{
  butin = bt;
}
 //
 // Heritiere* Gangster::getHeritiere()
 // {
 //   return heritiere;
 // }
 // void Gangster::setHeritiere(Heritiere* h)
 // {
 //   heritiere = h;
 // }
void Gangster::recupereBijoux(Personnage &p)
{
  std::list<Bijou*> bijouxEnleve = p.enleveBijoux();

  std::cout << "Je vais voler les possessions de :" << p.getNom() << std::endl;
  for (std::list<Bijou*>::iterator it = bijouxEnleve.begin(); it != bijouxEnleve.end(); ++it)
  {
    std::cout << "Je prend " << (*it)->getNom() << " de " << p.getNom() <<" d'une valeur de" <<  (*it)->getValeur() << std::endl;
    butin = butin + (*it)->getValeur();
    possessions.push_back(*it);
  }
}

std::list<Bijou*> Gangster::enleveBijoux()
{
  std::list<Bijou*> biens = possessions;
  for (std::list<Bijou*>::iterator it = biens.begin(); it != biens.end(); ++it)
  {
    butin = butin - (*it)->getValeur();
  }
  possessions.clear();
  return biens;
}

void Gangster::enleve(Personnage& p)
{
  Personnage::enleve(p);
  if(estCapture(p))
  {
    // A BIEN REGARDER, JE NE SUIS PAS SUR

    setPers(NULL); // un gangster a capturé une heritiere
    //p.setCaptive(true);
    p.parle("A l'aide! je suis " + p.getNom() + ", on m'enlève! Sauvez-moi ! ");
    this->parle(p.getNom() + ", tu es maitenant à la merci du gang " + this->getGang());
    this->augmenteRecompense(); // la recompense du gangter augmente de 100
  }

}
bool Gangster::estCapture(Personnage& p)
{
  Personnage::estCapture(p);
  // l'enlevement de l'heritiere reussit une chance sur trois
  long al = (Alea::value()%3);
  if(al == 0)
  {
    // enlevement de l'heritiere
    return true;
  }
  false;
}

void Gangster::sEvade()
{
  this->setPrison(false);
  this->setRecompense(100);
}

void Gangster::augmenteRecompense()
{
  this->recompense += 100;
}
void Gangster::effaceRecompense()
{

  this->recompense = 0;
}
