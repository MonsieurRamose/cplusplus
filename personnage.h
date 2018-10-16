#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <string>
#include <list>
#include "lieu.h"
#include "bijou.h"

class Personnage
{
  protected:
    std::string nom;
    Lieu* lieu;
    std::list<Bijou *> possessions;
  public:
    Personnage();
    Personnage(const std::string &_nom);
    Personnage(const std::string &_nom, Lieu* l);
    virtual ~Personnage();

    std::string& getNom();
    Lieu* getLieu();
    void setLieu(Lieu* l);
    void parle(const std::string &texte);
    void deplace(std::string, Lieu* l);

    virtual void recupereBijoux(Personnage& p) = 0;
    virtual std::list<Bijou *> enleveBijoux() = 0;
};

#endif
