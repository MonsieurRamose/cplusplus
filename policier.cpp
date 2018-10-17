#include "policier.h"

// Attention à lieu (par rapport à sa modification)
Policier::Policier(std::string _nom, Lieu* _lieu) : Personnage(_nom), lieu(_lieu), reputation(0)
{
}

Lieu* Policier::getLieu()
{
    return lieu;
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
