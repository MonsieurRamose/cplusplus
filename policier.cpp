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
  Personnage::libere(p); // appeler la méthode de la super classe
  Personnage* h = p.getPers();
  p.setPers(NULL);
  h->parle("Grand merci "+ this->getNom() +" vous m'avez sauvé");
  //h->setCaptive(false);
  reputation += 2;
}


void Policier::attaque(Gangster& p)
{
  Personnage::attaque(p); // appel à la methode de la super classe
  this->action();

  if(this->lieu->getNom().compare(p.getLieu()->getNom()) == 0) // s'ils se trouvent dans le meme lieu
  {
    this->parle(p.getNom()+" sortez les mains en l'air");

    double pro = (pow(0.75, 1./(getReputation()+1.))) * (1. - (pow(0.75, (10./p.getRecompense()))));
    double al = Alea::value()%2;
    // a revoir je ne sais pas trop sur les probas
    if(al == 0)
    {
      // le policier gagne
      this->incrementePopularite();
      this->parle(p.getNom() +" je vous arrete. Vous avez le droit de garder le silence");

      if(p.getPers() != NULL)
      {
        // le gangster detient une Heritiere

        this->libere(p);            /*liberer l'heritiere detenue par le gangster p*/
      }else{
        // le gangster n'a pas detenu d'heritiere
          if(p.getButin() >= 3 * p.getRecompense())
          {
            double convaincre = (1 - (0.25, (1./1.+this->getReputation())));
            // a revoir
            double aleat = Alea::value()%2;
            if(aleat == 0)
            {
              // le gangster a réussi a convaicre le Policier
              // a mettre quelque chose ici, le policier recois 2/3 de buttin
              this->setReputation(0); // le policier perd sa réputation
              p.parle("Tu vois, " + this->getNom() + ", je vavais bien qu'on pourrait s'arranger....");
            }else{
              // le gangster n'a pas réussi a convaicre le Policier
              this->parle("Misirable "+ p.getNom() + ", tu me crois aussi cupide et malfaisant que toi?");
              this->incrementePopularite();
            }
          }
      }

      p.setPrison(true);          /*le gangster emprisonné*/
      this->setReputation(p.getRecompense());  /* La recompense du gangster versé au policier*/
      p.effaceRecompense();       /*remise à zero de la recompense du gangster*/
      p.setButin(0);              // le buttin du gangster confisqué

      /*Un gangster peut s evader de prison*/
      /*On consider que il a une chance sur 2 de s'evader */
      long tirAl = Alea::value()%2;
      if(tirAl == 0)
      {
        /*le gangster s'evade de prison*/
        p.sEvade();
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
