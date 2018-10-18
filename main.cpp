#include <iostream>
#include <string>
#include "gangster.h"
#include "personnage.h"
#include "policier.h"
#include "heritiere.h"
#include "bijou.h"
#include "alea.h"
#include "scenario.h"

using namespace std;

int main()
{
    Lieu * paris = new Lieu("paris");
    Lieu * london = new Lieu("london");
    Lieu * lehavre = new Lieu("lehavre");
    Gangster *alcapone = new Gangster("Alcapone", "gang des 4");
    Policier *p2 = new Policier("mr policier", lehavre, london);
    Heritiere *alice= new Heritiere("Alice");
    alcapone->recupereBijoux(*alice);
    std::cout <<"mon buttin est "<< alcapone->getButin()<<std::endl;
    Scenario s;
    s.initScenario();
    s.getPersonnages()[5]->action();

    delete alice;
    delete paris;

    // std::cout << "je suis le policier " << p2->getNom()<<" je suis à "<<p2->getLieu()->getNom()<<std::endl;
    // // pourquoi si on declare p2 comme personnage, ON NE PEUX PAS acceder aux methodes de la classe policieer???
    // std::cout << p3->estCaptive()<<std::endl;
    // Bijou *b = new Bijou ("bague", 545);
    // std::cout << b->getNom()<<" de valeur "<< b->getValeur()<<std::endl;

    // Heritiere *alice= new Heritiere("Alice");
    //
    // Gangster alcapone("Alcapone", "Les voleurs");
    // alcapone.recupereBijoux(*alice);
    // delete alice;
    //
    // Alea a;
    //  cout << Alea::value() << endl;
    //  cout << Alea::value() << endl;
    //  cout << Alea::value() << endl;
    //  cout << Alea::value() << endl;

   // Lieu * douvres = new Lieu ("douvres");
   // Lieu * bordeaux = new Lieu ("bordeaux");
   // Scenario s;
   // s.initScenario();
   // std::cout<<s.getPersonnages()[4]->getLieu()->getNom()<<std::endl;
   // s.getPersonnages()[4]->deplace("bateau", bordeaux);

    return 0;
}
