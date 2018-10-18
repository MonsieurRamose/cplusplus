#include "policier.h"
#include "alea.h"
#include "cmath"

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


void Policier::libere(Personnage &p)
{
  //liberer l'heritiere detenu par le gangster p
  Personnage* h = p.getPers();
  p.setPers(NULL);
  h->parle("Grand merci "+ this->getNom() +" vous m'avez sauvé");
  reputation += 2;
}


void Policier::attaque(Gangster& p)
{
  this->action();

  if(this->lieu->getNom().compare(p.getLieu()->getNom()) == 0) // s'ils se trouvent dans le meme lieu
  {
    this->parle(p.getNom()+" sortez les mains en l'air");

    double pro = (pow(0.75, 1./(getReputation()+1.))) * (1. - (pow(0.75, (10./p.getRecompense()))));
    double al = Alea::value()%2;
    // a revoir je ne sais pas trop les probas
    if(al == 0)
    {
      // le policier gagne
      this->incrementePopularite();
      this->parle(p.getNom() +" je vous arrete. Vous avez le droit de garder le silence");
      if(p.getPers() != NULL)
      {
        // le gangster detient une Heritiere
        this->libere(p);


      }
    }else{
      // le gangster gagne
      this->decrementePopularite();
      p.parle( "Tu crois vraiment pouvoir vaincre le gang "+ p.getGang());
    }


  }

}

void Policier::incrementePopularite()
{
  reputation += 1;
}
void Policier::decrementePopularite()
{
  reputation -= 1;
}
