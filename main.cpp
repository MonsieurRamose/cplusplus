#include <iostream>
#include <string>
#include "gangster.h"
#include "personnage.h"
#include "policier.h"
#include "heritiere.h"
#include "bijou.h"

int main()
{
    // Lieu * paris = new Lieu("paris");
    // Lieu * london = new Lieu("london");
    // Lieu * lehavre = new Lieu("lehavre");
    // Personnage *p = new Gangster("Alcapone", "gang des 4");
    // Policier *p2 = new Policier("mr policier", lehavre);

    // std::cout << "je suis le policier " << p2->getNom()<<" je suis à "<<p2->getLieu()->getNom()<<std::endl;
    // // pourquoi si on declare p2 comme personnage, ON NE PEUX PAS acceder aux methodes de la classe policieer???
    // std::cout << p3->estCaptive()<<std::endl;
    // Bijou *b = new Bijou ("bague", 545);
    // std::cout << b->getNom()<<" de valeur "<< b->getValeur()<<std::endl;

    Heritiere alice("Alice");

    Gangster alcapone("Alcapone", "Les voleurs");
    alcapone.recupereBijoux(alice);

    return 0;
}
