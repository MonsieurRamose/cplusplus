#ifndef GANGSTER_H
#define GANGSTER_H

#include <iostream>
#include <string>
#include "personnage.h"
#include "bijou.h"
#include "alea.h"
//#include "heritiere.h"

class Gangster: public Personnage
{
  private:
    std::string gang;
    long recompense;
    bool enPrison;
    long butin;
  //  Heritiere* heritiere;

  private:
    Gangster();
  public:
    Gangster(std::string _nom, std::string _gang);

  public:
    std::string getGang();
    long getRecompense();
    bool estEnPrison();
    long getButin();
    // Heritiere* getHeritiere();
    // void setHeritiere(Heritiere* h);
    void recupereBijoux(Personnage &p);
    virtual std::list<Bijou*> enleveBijoux();
   void enleve(Personnage& p);
    bool estCapture(Personnage& p);
    bool sEvade();
    void augmenteRecompense();
    void effaceRecompense();
};

#endif
