#include <iostream>
#include "scenario.h"
#include "heritiere.h"
#include "policier.h"


void Scenario::setNbVilles(long nbV) {
    nbVilles = nbV;
}

long Scenario::getNbVilles() {
    return nbVilles;
}

void Scenario::setNbPers(long nbP) {
    nbPers = nbP;
}

long Scenario::getNbPers() {
    return nbPers;
}

Lieu **Scenario::getVilles() {
    return villes;
}

Personnage **Scenario::getPersonnages() {
    return personnages;
}

void Scenario::initLieu() {
    Lieu *edimbourg = new Lieu("edimbourg");
    Lieu *londres = new Lieu("londres");
    Lieu *douvres = new Lieu("douvres");
    Lieu *portsmouth = new Lieu("portsmouth");
    Lieu *plymouth = new Lieu("plymouth");
    Lieu *brest = new Lieu("brest");
    Lieu *lehavre = new Lieu("lehavre");
    Lieu *calais = new Lieu("calais");
    Lieu *paris = new Lieu("paris");
    Lieu *rennes = new Lieu("rennes");
    Lieu *quimper = new Lieu("quimper");
    Lieu *bordeaux = new Lieu("bordeaux");

    edimbourg->addConnexion("train", londres);
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
    quimper->addConnexion("train", bordeaux);
    brest->addConnexion("bateau", bordeaux);
    bordeaux->addConnexion("train", paris);
    setNbVilles(12);
    villes = new Lieu *[nbVilles];
    villes[0] = edimbourg;
    villes[1] = londres;
    villes[2] = douvres;
    villes[3] = portsmouth;
    villes[4] = plymouth;
    villes[5] = brest;
    villes[6] = lehavre;
    villes[7] = calais;
    villes[8] = paris;
    villes[9] = rennes;
    villes[10] = quimper;
    villes[11] = bordeaux;
}


void Scenario::initPersonnage() {
    Heritiere* alice = new Heritiere("Alice", villes[0]);

    Personnage *Alice = alice;
    Personnage *Sophie = new Heritiere("Sophie", villes[1]);
    Personnage *John = new Policier("John", villes[2]);
    Personnage *Noah = new Policier("Noah", villes[3]);
    Personnage *Alain = new Gangster("Alain", villes[4]);
    Personnage *Dupont = new Policier("Dupont", villes[5]);
    Personnage *Lola = new Heritiere("Lola", villes[6]);
    setNbPers(7);
    personnages = new Personnage *[nbPers];
    personnages[0] = Alice;
    personnages[1] = Sophie;
    personnages[2] = John;
    personnages[3] = Noah;
    personnages[4] = Alain;
    personnages[5] = Dupont;
    personnages[6] = Lola;
    for (int i = 0; i < 7; i++) {
        personnages[i]->setScenario(this);
        /* code */
    }

}


void Scenario::initScenario() {

    initLieu();
    initPersonnage();

}

Lieu *Scenario::getVilleByNumero(long n) {
    for (int i = 0; i < getNbVilles(); i++) {
        if (n == villes[i]->getNumero()) {
            return villes[i];
        }
    }
    return NULL;
}

void Scenario::scene()
{
  for(int i = 0; i < nbPers; i++) {
    personnages[i]->action();
    personnages[i]->interaction(*this);
  }
}
