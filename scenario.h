#ifndef SCENARIO_H
#define SCENARIO_H
#include <string>
#include "lieu.h"
class Personnage;
//class Lieu;

class Scenario{


  private:
    long nbVilles;
    long nbPers;
    Lieu** villes;
    Personnage** personnages;


   public:
     void setNbVilles(long nbV);
     long getNbVilles();
     void setNbPers(long nbP);
     long getNbPers();
      Lieu** getVilles();
      Personnage** getPersonnages();
      void initLieu();
      void initPersonnage();
      void initScenario();
      Lieu* getVilleByNumero(long n);
      void scene();
};
#endif
