#include "lieu.h"
#include <iostream>
#include <queue>

long Lieu::DERNIER_NUMERO = 0; /* initialisation de dernier lieu instancié à 0 qui s'incrémente à chaque nouvelle instanciation*/


/* Constructeur par défaut:
Ce constructeur initialise le nom du lieu à "nulle part", les
tableaux: train et tableau à NULL e la taille des tableaux à 0
On incrémente l'attribut statique DERNIER_NUMERO, et on
l'affecte à l'attribut "numero" du lieu instancié.*/

Lieu::Lieu(): nom("nulle part"), train(NULL), bateau(NULL), nbTrain(0), nbBateau(0)
{
  DERNIER_NUMERO++;
  std::cout << "Creation d'un lieu en utilisant un constructeur sans paramètre, nom par défaut: " << nom << std::endl;
  this->numero = DERNIER_NUMERO;
}

/*Constructeur avec des paramètres:
Ce constructeur initialise les attributs passés en paramètre
dans la liste d'initialisation, et les tableaux à NULL.
Dans le cas ou le nombre de train ou de bateaux est strictement
superieur à 0, on instancie le tableau de train et de baetau de
taille nbBateau et nbTrain passés en paramètre.
On incrémente l'attribut statique DERNIER_NUMERO, et on
l'affecte à l'attribut "numero" du lieu instancié.
*/

Lieu::Lieu(const std::string &_nom, long _nbTrain, long _nbBateau): nom(_nom), train(NULL), bateau(NULL), nbTrain(_nbTrain), nbBateau(_nbBateau)
{
  if(nbTrain > 0)
  {
      train = new Lieu*[_nbTrain];
  }
  if(nbBateau > 0) {
      bateau = new Lieu*[_nbBateau];
  }
  DERNIER_NUMERO++;
  std::cout << "Creation d'un lieu en utiliant un constructeur avec parametre, nom: " << nom << " numero: " << DERNIER_NUMERO << std::endl;
  this->numero = DERNIER_NUMERO;
}


/*Destructeur:
Ce destructeur libère l'espace occupé par le tableau de train et de bateaux
on commence donc par libérer les lieus instanciés dans les tableaux
puis on libre les tableaux train et bateau*/

Lieu::~Lieu()
{

  for(int i = 0; i < nbTrain; i++)
  {
    delete train[i];
  }
  if(train != NULL)
  {
    delete[] train;
    train = NULL;
  }

  for(int i = 0; i < nbBateau; i++)
  {
    delete bateau[i];
  }
  if(bateau != NULL)
  {
    delete[] bateau;
    train = NULL;
  }

  std::cout << "Destruction d'un lieu, nom: " << nom << std::endl;
}
/*Guetter:
Cette méthode permet de récuperer le nom du lieu*/

const std::string & Lieu::getNom()
{
  return nom;
}

/*Guetter:
Cette méthode permet de récuperer le nombre de villes avec lesquelles le lieu
appelant est connecté par "bateau"*/

 int Lieu::getNbBateau()
{
  return nbBateau;
}

/*Guetter:
Cette méthode permet de récuperer le nombre de villes avec lesquelles le lieu
appelant est connecté par "train"*/

 int Lieu::getNbTrain()
{
  return nbTrain;
}

/*Guetter:
Cette méthode renvoie le tableau de villes avec lesquelles le lieu
appelant est connecté par "train"*/

Lieu** Lieu::getTrains()
{
  return train;
}

/*Guetter:
Cette méthode renvoie le tableau de villes avec lesquelles le lieu
appelant est connecté par "bateau"*/

Lieu** Lieu::getBateaux()
{
  return bateau;
}

/*Cette méthode permet d'afficher les connexions du lieu appelant
 en bateau et en train*/

void Lieu::afficherConnexion()
{

  std::cout<<"les connexions de "<<this->nom<<" en bateau sont:"<<std::endl;
  for (int i = 0; i < nbBateau; i++)
  {
      std::cout<<(bateau[i])->getNom()<<std::endl;
  }
  std::cout<<std::endl;

  std::cout<<"les connexions de "<<this->nom<<" en train sont :" <<std::endl;

  for (int i = 0; i < nbTrain; i++)
   {
     std::cout<<(train[i])->getNom()<<std::endl;
   }

  std::cout<<std::endl;
}
/*Cette méthode permet d'ajouter une connexion entre l’objet
appelant et un lieu en mode de transport passés en paramètre.

L'idée est la suivante:
Selon le moyen de transport passé en paramètre, on parcourt le tableau

 */

void Lieu::addConnexion(std::string transport, Lieu* lieu)
{

  if(transport == "bateau") {
      bool present = false;

      for(int i = 0; i < nbBateau; i++)
      {
        if((bateau[i]->getNom()).compare(lieu->getNom()) == 0) {
          present = true;
          break;
        }
      }
      if(!present)
      {
        Lieu** newBateau = new Lieu*[nbBateau+1];
        for(int i = 0; i < nbBateau; i++)
        {
          newBateau[i] = bateau[i];
        }
        if(nbBateau !=0)
        delete[] bateau;
        newBateau[nbBateau] = lieu;
        bateau = newBateau;
        this->nbBateau=this->nbBateau+1;
       lieu->addConnexion("bateau", this);
     }
  }else{
    if(transport == "train") {
        bool present = false;

        for(int i = 0; i <nbTrain; i++)
        {
          if((train[i]->getNom()).compare(lieu->getNom()) == 0) {
            present = true;
            break;
          }
        }
        if(!present)
        {
          Lieu** newTrain = new Lieu*[nbTrain+1];
          for(int i = 0; i < nbTrain; i++)
          {
            newTrain[i] = train[i];
          }
          if(nbTrain !=0)
          delete[] train;
          newTrain[nbTrain] = lieu;
          train = newTrain;
          this->nbTrain=this->nbTrain+1;
         lieu->addConnexion("train", this);
        }
    }else{
      std::cout<<"le moyen de transport < " << transport << " > n'existe pas !!"<<std::endl;
    }

  }
}

void Lieu::removeConnexion(std::string transport, Lieu* lieu)
{
  if(transport=="bateau")
  {
    int i=0;
    while(i<nbBateau && (bateau[i]->getNom()).compare(lieu->getNom()) != 0)
    {
      i++;
    }
    if(i==nbBateau)
    {
      std::cout<<"Il n'existe pas de connexion entre "<<this->nom<<" et "<<lieu->nom << std::endl;
    }else{
      for(int j=i; j<nbBateau; j++)
      {
        bateau[j]=bateau[j+1];
      }
      nbBateau--;
      lieu->removeConnexion(transport, this);

    }
  }else{
    if(transport=="train")
    {
      int i=0;
      while(i<nbTrain && (train[i]->getNom()).compare(lieu->getNom()) != 0)
      {
        i++;
      }
      if(i==nbTrain)
      {
        std::cout<<"Il n'existe pas de connexion entre "<<this->nom<<" et "<<lieu->nom <<" en "<< transport<< std::endl;
      }else{
        for(int j=i; j<nbTrain; j++)
        {
          train[j]=train[j+1];
        }
        nbTrain--;
        lieu->removeConnexion(transport, this);
      }
    }else{
      if (transport=="tous")
      {
        this->removeConnexion("bateau", lieu);
        this->removeConnexion("train", lieu);
      }else{
        std::cout<<"Le moyen de transport < "<< transport << " > n'existe pas"<<std::endl;
    }
  }
  }
}

bool Lieu::estAccessible(std::string transport, Lieu* lieu)
{
    if(transport=="bateau")
    {
      for(int i=0; i<nbBateau; i++)
      {
        if((bateau[i]->getNom()).compare(lieu->getNom()) == 0)
        {
          return true;
        }
      }
      return false;
    }else{
      if(transport=="train")
      {
        for(int i=0; i<nbTrain; i++)
        {
          if((train[i]->getNom()).compare(lieu->getNom())==0)
          {
            return true;
          }
        }
        return false;
      }else{
        if(transport == "tous")
        {
          if( this->estAccessible("train", lieu))
          {
            return true;
          }else{
            return this->estAccessible("bateau", lieu);
          }
       }else{
         std::cout<<"Le moyen de transport < "<< transport << " > n'existe pas"<<std::endl;
         return false;
       }
      }
  }


}

long Lieu::distance(const std::string &moyen, Lieu* l)
{
    std::cout<<"dans la fct distance "<< moyen<<" "<<l->getNom()<<std::endl;
    if (this->estAccessible(moyen, l))
    {
      std::cout<<"est accessible"<<std::endl;
        return 1;
    }
    std::cout<<"dans=============== "<< moyen<<" "<<l->getNom()<<std::endl;

    Lieu* start = this;

    std::queue<std::pair<Lieu*, long> > file;
    file.push(std::make_pair(start, 1));

    std::cout<<"dernier numero"<<Lieu::DERNIER_NUMERO<<std::endl;

    bool *visited = new bool[Lieu::DERNIER_NUMERO];
    for (int i = 0; i < Lieu::DERNIER_NUMERO; i++)
    {
      std::cout<<"dans le premier for"<<std::endl;
      visited[i] = false;
    }

    long maxDis = 100;

    while (!file.empty())
    {
        std::cout<<"dans le while"<<std::endl;
        Lieu* u = file.front().first;
        long dis = file.front().second;
        file.pop();
        visited[u->numero] = true;
        int nbTrain = u->nbTrain;
        int nbBateau = u->nbBateau;

        for(int i = 0; i < nbTrain; i++)
        {
          std::cout<<"dans la for"<<std::endl;
            Lieu* destination = u->train[i];
            if (u->estAccessible(moyen, destination) && !visited[destination->numero])
            {
                if (destination->getNom().compare(l->getNom()) == 0)
                    maxDis = std::min(maxDis, dis);
                file.push(std::make_pair(destination, dis + 1));
            }
        }

        for(int i = 0; i < nbBateau; i++)
        {
            Lieu* destination = u->bateau[i];
            if (u->estAccessible(moyen, destination) && !visited[destination->numero])
            {
                if (destination->getNom().compare(l->getNom()) == 0)
                    maxDis = std::min(maxDis, dis);
                file.push(std::make_pair(destination, dis + 1));
            }
        }
    }
    if(visited != NULL)
    {
      delete visited;
    }

    std::cout<<"max"<<maxDis<<std::endl;
    return (maxDis == 100) ? -1 : maxDis;
}

void Lieu::test()
{

  // Lieu *portsmouth=new Lieu("portsmouth");
  // Lieu *paris=new Lieu("paris");
   //std::cout << "c'est" << portsmouth->distance("bateau",paris);
  // Lieu::init();


}
