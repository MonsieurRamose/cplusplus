#include "policier.h"

// Attention à lieu (par rapport à sa modification)
Policier::Policier(std::string _nom, Lieu* _lieu, Lieu* pl) : Personnage(_nom, _lieu), plieu(pl), reputation(0)
{
}

Lieu* Policier::getPlieu()
{
    return plieu;
}

int Policier::getReputation()
{
    return reputation;
}

void Policier::setReputation(int _reputation)
{
    this->reputation = _reputation;
}
/*
void Policier::recupereBijoux(Personnage &p)
{
  std::list<Bijou*> bijouxEnleve = p.enleveBijoux();

  for (std::list<Bijou*>::iterator it = bijouxEnleve.begin(); it != bijouxEnleve.end(); ++it)
  {
    possessions.push_back(*it);
  }
}

std::list<Bijou*> Policier::enleveBijoux()
{
  std::list<Bijou*> biens = possessions;
  possessions.clear();
  return biens;
}
*/

/*
void Polocier::libere(Personnage &p)
{
  reputation += 2;
}
void attaque(Personnage& p)
{
  this.action();
  if(this->lieu->getNom().compare(p.lieu->getNom()) == 0) // s'ils se trouvent dans le meme lieu
  {
    std::cout << p.getNom() << ", sortez les mains en l'air"<< std::endl;
    double pro = (pow(0.75, 1./(getReputation()+1.))) * (1. - (pow(0.75, (10./p.getRecompense()))));

  }

}
void incrementePopularite()
{
  reputation += 1;
}
void decrementePopularite()
{
  reputation -= 1;
}
*/
