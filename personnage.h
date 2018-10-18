#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <string>
#include <list>
#include "lieu.h"
#include "bijou.h"
#include "alea.h"
class Scenario;

class Personnage
{
  protected:
    std::string nom;
    Lieu* lieu;
    std::list<Bijou *> possessions;
    Scenario* scenario;
    Personnage* pers;
  public:
    Personnage();
    Personnage(const std::string &_nom);
    Personnage(const std::string &_nom, Lieu* l);
    virtual ~Personnage();

    std::string& getNom();
    void setScenario(Scenario* s);
    Lieu* getLieu();
    void setLieu(Lieu* l);
    Personnage* getPers();
    void setPers(Personnage* p);
    void parle(const std::string &texte);
    void deplace(std::string, Lieu* l);
    virtual void recupereBijoux(Personnage& p);
    virtual std::list<Bijou *> enleveBijoux();
     void action();
     virtual void libere(Personnage &p);
     virtual void attaque(Personnage& p);
     virtual bool estEnlevee(Personnage& p);
     virtual bool estLiberee(Personnage& p);
     virtual void enleve(Personnage& p);
     virtual bool estCapture(Personnage& p);


};

#endif
