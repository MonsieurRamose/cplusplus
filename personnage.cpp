#include <iostream>
#include <string>
#include "personnage.h"
#include "scenario.h"


Personnage::Personnage(const std::string &_nom) : nom(_nom) {

}

Personnage::Personnage(const std::string &_nom, Lieu *l) : nom(_nom), lieu(l) {
    pers = nullptr;
    std::cout << "Bonjour, je suis " << nom << " et je viens d'arriver en ville " << l->getNom() << std::endl;
}

Personnage::~Personnage() {
    std::cout << "Il n'y a plus rien à faire pour moi," << nom << ".Adieu!" << std::endl;
    for (auto it = possessions.begin(); it != possessions.end(); ++it) {
        std::cout
                << "Destruction de ma possession (" << nom << "): " << (*it)->getNom()
                << " d'une valeur de: " << (*it)->getValeur() << std::endl;
        delete (*it);
    }
    possessions.clear();
}

std::string &Personnage::getNom() {
    return nom;
}

Lieu *Personnage::getLieu() {
    return lieu;
}

void Personnage::setLieu(Lieu *l) {
    lieu = l;
}


Personnage *Personnage::getPers() {
    return pers;
}

void Personnage::setPers(Personnage *p) {
    pers = p;
}

void Personnage::parle(const std::string &texte) {
    std::cout << nom << ":" << texte << std::endl;
}

void Personnage::deplace(std::string transport, Lieu *l) {
    int i = 0;
    long n = 0;
    if (transport == "train") {

        n = lieu->distance(transport, l);
        std::cout << " " << "la distance est " << n << std::endl;
        if (n != -1) {
            setLieu(l);
            std::cout << "Je vais à " << l->getNom() << " en prenant " << n << " trains" << std::endl;
        } else {
            if (lieu->getNbTrain() > 0) {
                lieu = lieu->getTrains()[0];
                std::cout << "Zut! Je me suis trompé de mode, celui-ci ne va pas à" << l->getNom()
                          << " mais je me depalce à " << lieu->getNom() << std::endl;
            } else {
                std::cout << "Je ne peux pas me deplacer à " << l->getNom() << std::endl;
            }
        }

    } else {
        if (transport == "bateau") {
            n = lieu->distance(transport, l);
            if (n != -1) {
                setLieu(l);
                std::cout << "Je vais à " << l->getNom() << " en prenant " << n << " bateaux" << std::endl;
            } else {
                if (lieu->getNbBateau() > 0) {
                    lieu = lieu->getBateaux()[0];
                    std::cout << "Zut! Je me suis trompé de mode, celui-ci ne va pas à" << l->getNom()
                              << " mais je me depalce à " << lieu->getNom() << std::endl;
                } else {
                    std::cout << "Je ne peux pas me deplacer à " << l->getNom() << std::endl;
                }
            }

        }
    }
}

void Personnage::recupereBijoux(Personnage &p) {
    std::list<Bijou *> bijouxEnleve = p.enleveBijoux();

    for (auto it = bijouxEnleve.begin(); it != bijouxEnleve.end(); ++it) {
        this->possessions.push_back(*it);
    }
}

std::list<Bijou *> Personnage::enleveBijoux() {
    std::list<Bijou *> biens = possessions;
    possessions.clear();
    return biens;
}

void Personnage::setScenario(Scenario *s) {
    scenario = s;
}

void Personnage::action() {
    long al = (Alea::value() % 3);

    if (al == 0) {
        std::cout << " Je suis " << getNom() << " et je reste dans la meme ville" << std::endl;
    } else {
        std::cout << " Je suis " << getNom() << " et je change de ville " << std::endl;
        int tir = Alea::value() % (scenario->getNbVilles());

        std::cout << "le tirage est: " << tir << " ville " << scenario->getVilles()[tir]->getNom() << std::endl;
        if (scenario->getVilleByNumero(tir) != NULL) {
            if (al == 1)  // il se deplace en train{

                this->deplace("train", scenario->getVilleByNumero(tir));

            } else {
                // il se deplace en bateau
                this->deplace("bateau", scenario->getVilleByNumero(tir));

            }
        }
    }
}

void Personnage::libere(Personnage &p) {
}

void Personnage::attaque(Personnage &p) {

}

bool Personnage::estEnlevee(Personnage &p) {

}

bool Personnage::estLiberee(Personnage &p) {

}

void Personnage::enleve(Personnage &p) {

}

bool Personnage::estCapture(Personnage &p) {

}
