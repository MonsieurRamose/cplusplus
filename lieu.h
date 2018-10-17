#ifndef LIEU_H
#define LIEU_H

#include <string>

class Lieu {

  static long DERNIER_NUMERO; //un attribut statique qui attribut un numero unique à chaque lieu

  private:
    std::string nom;
    long numero;
    Lieu** train;
    Lieu** bateau;
    long nbTrain;
    long nbBateau;

  public:
    Lieu();
    Lieu(const std::string &_nom, long _nbTrain = 0, long nbBateau = 0);/* */
    ~Lieu();

  public:
    const std::string & getNom();
    int getNbBateau();
    int getNbTrain();
    Lieu** getTrains();
    Lieu** getBateaux();
    void afficherConnexion();
    void addConnexion(std::string transport, Lieu* lieu);
    void removeConnexion(std::string transport, Lieu* lieu);
    bool estAccessible(std::string, Lieu*);
    long distance(const std::string&, Lieu*);
    static void test();
};

#endif
