#ifndef GANGSTER_H
#define GANGSTER_H

#include <iostream>
#include <string>
#include "personnage.h"
#include "bijou.h"

class Gangster: public Personnage
{
  private:
    std::string gang;
    long recompense;
    bool enPrison;
    long butin;

  private:
    Gangster();
  public:
    Gangster(std::string _nom, std::string _gang);

  public:
    std::string getGang();
    long getRecompense();
    bool estEnPrison();
    long getButin();
    void recupereBijoux(Personnage &p);
    virtual std::list<Bijou*> enleveBijoux();
};

#endif
