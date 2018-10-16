#include "lieu.h"
#include <iostream>
//mis a jour le 11 octobre

long Lieu::DERNIER_NUMERO = 0;

Lieu::Lieu(): nom("nulle part"), train(NULL), bateau(NULL), nbTrain(0), nbBateau(0)
{
  DERNIER_NUMERO++;
  std::cout << "Creation d'un lieu en utilisant un constructeur sans paramètre, nom par défaut: " << nom << std::endl;
  this->numero = DERNIER_NUMERO;
}

Lieu::Lieu(const std::string &_nom, long _nbTrain, long _nbBateau): nom(_nom), train(NULL), bateau(NULL), nbTrain(_nbTrain), nbBateau(_nbBateau)
{
  if(nbTrain != 0)
  {
      train = new Lieu*[_nbTrain];
  }
  if(nbBateau != 0) {
      bateau = new Lieu*[_nbBateau];
  }
  DERNIER_NUMERO++;
  std::cout << "Creation d'un lieu en utiliant un constructeur avec parametre, nom: " << nom << " numero: " << DERNIER_NUMERO << std::endl;
  this->numero = DERNIER_NUMERO;
}

Lieu::~Lieu()
{

  for(int i = 0; i < nbTrain; i++)
  {
    delete train[i];
  }
  delete[] train;

  for(int i = 0; i < nbBateau; i++)
  {
    delete bateau[i];
  }
  delete[] bateau;

  std::cout << "Destruction d'un lieu, nom: " << nom << std::endl;
}

const std::string & Lieu::getNom()
{
  return nom;
}

 int Lieu::getNbBateau()
{
  return nbBateau;
}

 int Lieu::getNbTrain()
{
  return nbTrain;
}

Lieu** Lieu::getTrains()
{
  return train;
}
Lieu** Lieu::getBateaux()
{
  return bateau;
}
void Lieu::afficherConnexion(){

  std::cout<<"les connexions de "<<this->nom<<" en bateau sont: nb bateau est:  "<<this->nbBateau<<std::endl;
  for (int i = 0; i < nbBateau; i++) {
  std::cout<<(bateau[i])->getNom()<<std::endl;
  }
  std::cout<<std::endl;
  std::cout<<"les connexions de "<<this->nom<<" en train sont : nb train est:"<<this->nbTrain <<std::endl;
  for (int i = 0; i < nbTrain; i++) {
  std::cout<<(train[i])->getNom()<<std::endl;
  }
  std::cout<<std::endl;
}

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
        // std::cout<<"bateau  "<<this->nom;
        // std::cout<<"  avant  " <<this->nbBateau;
        this->nbBateau=this->nbBateau+1;
        // std::cout<<" bateau  "<<this->nom;
        // std::cout<<"  apres  " <<this->nbBateau<< std::endl;
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
          //std::cout<<"train  "<<this->nom;
          //std::cout<<" avant  " <<this->nbBateau;
          this->nbTrain=this->nbTrain+1;
          // std::cout<<" train  "<<this->nom;
          // std::cout<<"  apres  " <<this->nbBateau<< std::endl;
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
      std::cout<<"bateau  "<<this->nom;
      std::cout<<"  apres REMOVE " <<this->nbBateau<< std::endl;
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
        std::cout<<"TRAIN "<<this->nom;
        std::cout<<"  apres  " <<this->nbTrain<<lieu->nom<< std::endl;
        lieu->removeConnexion(transport, this);
      }
    }else{
      if (transport=="tous")
      {
        removeConnexion("bateau", lieu);
        removeConnexion("train", lieu);
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
    }
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
    }
    if(transport == "tous")
    {
      int i=0;
      while(i<nbBateau && (bateau[i]->getNom()).compare(lieu->getNom())!=0)
      {
        i++;
      }
      if(i<nbBateau){
          return true;
      }else{
        int j=0;
        while(j<nbTrain && (train[j]->getNom()).compare(lieu->getNom())!=0)
        {
          j++;
        }
        if(j<nbTrain){
            return true;
        }
        return false;
    }
  }
      std::cout<<"Le moyen de transport < "<< transport << " > n'existe pas"<<std::endl;
      return false;


}


void Lieu::init()
{
    Lieu *edimbourg=new Lieu("edimbourg");
    Lieu *londres=new Lieu("londres");
    Lieu *douvres=new Lieu("douvres");
    Lieu *portsmouth=new Lieu("portsmouth");
    Lieu *plymouth=new Lieu("plymouth");
    Lieu *brest=new Lieu("brest");
    Lieu *lehavre=new Lieu("lehavre");
    Lieu *calais=new Lieu("calais");
    Lieu *paris=new Lieu("paris");
    Lieu *rennes=new Lieu("rennes");
    Lieu *quimper=new Lieu("quimper");
    Lieu *bordeaux=new Lieu("bordeaux");

    edimbourg->addConnexion("train", londres);
    std::cout<<edimbourg->nom;
    std::cout<< edimbourg->nbBateau<< std::endl;
    londres->addConnexion("train", plymouth);
    londres->addConnexion("train", portsmouth);
    londres->addConnexion("train", douvres);
    douvres->addConnexion("bateau", calais);
    portsmouth->addConnexion("bateau", lehavre);
    plymouth->addConnexion("bateau", brest);
    lehavre->addConnexion("bateau", paris);
    calais->addConnexion("train", paris);
    paris->addConnexion("train", rennes);
    brest->addConnexion("train", rennes);
    rennes->addConnexion("train", quimper);
    quimper->addConnexion("train", bordeaux );
    brest->addConnexion("bateau",bordeaux);
    bordeaux->addConnexion("train", paris);
}
int Lieu::MinDist(int *tabDist,  int n)
{
  int min = tabDist[0];
  for(int i=0; i<n; i++)
  {
    if(tabDist[i] < min)
    {

      min = tabDist[i];
    }
  }

  return min;
}



long Lieu::distance(std::string transport, Lieu* lieu)
{
  int i = 0;
  int k = 0;
  if(this->nom.compare(lieu->nom)==0)
  {
    return 0;
  }
  if(this->estAccessible(transport,lieu))
  {
    return 1;
  }
  if(transport =="tous")
  {
    Lieu* lieuSub;
    Lieu **tabTous=new Lieu *[nbBateau+nbTrain];
    int *tabDist = new int[nbBateau+nbTrain];
    for(i=0; i<nbBateau; i++)
    {
      tabTous[i]= bateau[i];
      k++;
    }
    for(int j= 0; j<nbTrain; j++)
    {
      tabTous[j+i]=train[j];
      k++;
    }
    for(i=0; i<nbBateau+nbTrain; i++)
    {
    //  std::cout<<"DANs "<<i <<" "<<tabTous[i]->nom <<" "<<std::endl;
    }
    if(k !=0)
    {
      for(i=0; i < k; i++)
      {
        lieuSub = tabTous[i];
        this->removeConnexion(transport, tabTous[i]);
        tabDist[i] =  1 + lieuSub->distance(transport, lieu);
        std::cout<<"++++++++++++++++++++++++++++++++++++++++++++===DANs "<< this->nom <<" "<<tabDist[i]<<" "<<std::endl;
      }
      if(MinDist(tabDist, k) == 0)
      {
        int c;
        bool trouve;
        for(i=0; i<k; i++)
        {
          if(tabDist[i] == 0)
          {
             c=i;
             trouve = true;
          }
        }
        if(trouve)
        {
          i=0;
          while(i<k && i != c)
          {
            i++;
          }
          for(int j=i; j<k; j++)
          {
            tabDist[j]=tabDist[j+1];
          }
          return MinDist(tabDist, k-1);
        }
      }
    return MinDist(tabDist, k);
    }
    return -1;
  }
  /*  if(transport != "bateau" || transport!="train")
  {
    return -4;
  }*/

    if(transport=="bateau")
    {
      Lieu* bat;

      if(nbBateau != 0)
      {

      int *tabDist=new int[nbBateau];
      for(i=0;i<nbBateau;i++)
      {
        bat=bateau[i];
        this->removeConnexion(transport, bateau[i]);

            tabDist[i]= 1 + bat->distance(transport, lieu);
      }
      //std::cout <<nbBateau<< std::endl;
      return MinDist(tabDist, nbBateau);
    }else{

      return -1;
    }
    }
    if(transport=="train")
    {
      Lieu* tra;

      if(nbTrain!= 0)
      {

        int *tabDist=new int[nbTrain];
        for(i=0;i<nbTrain;i++)
        {
          tra=train[i];
          this->removeConnexion(transport, train[i]);

          tabDist[i]=1+ tra->distance(transport, lieu);
        }
        //std::cout <<nbBateau<< std::endl;
        return MinDist(tabDist, nbTrain);
    }else{

      return -1;
    }
    }

}


void Lieu::test()
{

  // Lieu *portsmouth=new Lieu("portsmouth");
  // Lieu *paris=new Lieu("paris");
   //std::cout << "c'est" << portsmouth->distance("bateau",paris);
  // Lieu::init();


}
