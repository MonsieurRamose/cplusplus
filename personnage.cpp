#include <iostream>
#include <string>
#include "personnage.h"


Personnage::Personnage(const std::string &_nom) : nom(_nom)
{

}

Personnage::Personnage(const std::string &_nom, Lieu* l) : nom(_nom),lieu(l)
{
  std::cout << "Bonjour, je suis " << nom << " et je viens d'arriver en ville " <<l->getNom()<< std::endl;
}

Personnage::~Personnage()
{
  std::cout << "Il n'y a plus rien à faire pour moi," << nom << ".Adieu!" << std::endl;
  for (std::list<Bijou*>::iterator it = possessions.begin(); it != possessions.end(); ++it)
  {
    std::cout 
              << "Destruction de ma possession (" << nom << "): " << (*it)->getNom() 
              << " d'une valeur de: " << (*it)->getValeur() << std::endl;
    delete (*it);
  }
  possessions.clear();
}

std::string& Personnage::getNom()
{
  return nom;
}

Lieu* Personnage::getLieu()
{
  return lieu;
}
void Personnage::setLieu(Lieu* l)
{
  lieu = l;
}

void Personnage::parle(const std::string &texte)
{
  std::cout << nom << ":" << texte << std::endl;
}
void Personnage::deplace(std::string transport, Lieu* l)
{
  int i=0;
  long n =0;
 if(transport == "train")
 {
   n = lieu->distance(transport, l);
   if (n != -1)
   {
     setLieu(l);
     std::cout<<"Je vais à "<<l->getNom()<<" en prenant "<<n<<" trains"<<std::endl;
   }else{
     if(lieu->getNbTrain() > 0)
     {
       lieu=lieu->getTrains()[0];
       std::cout<< "Zut! Je me suis trompé de mode, celui-ci ne va pas à"<<l->getNom()<<std::endl;
     }else{
       std::cout<< "Je ne peux pas me deplacer à "<<l->getNom()<<std::endl;
     }
   }

 }else{
   if(transport == "bateau")
   {
     n = lieu->distance(transport, l);
     if (n != -1)
     {
       setLieu(l);
       std::cout<<"Je vais à "<<l->getNom()<<" en prenant "<<n<<" bateaux"<<std::endl;
     }else{
       if(lieu->getNbBateau() > 0)
       {
         lieu=lieu->getBateaux()[0];
         std::cout<< "Zut! Je me suis trompé de mode, celui-ci ne va pas à"<<l->getNom()<<std::endl;
       }else{
         std::cout<< "Je ne peux pas me deplacer à "<<l->getNom()<<std::endl;
       }
     }

   }
 }
}
