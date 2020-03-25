#ifndef RS
#define RS

#include <iostream>
#include "define.hpp"

using namespace std;
struct Eurobalise
{
    short int longueur;
    short int vitesse;
    bool MAJ_eurobalise = false;
};
struct Pupitre_entrant
{
    string pupitre;
    int taille_pupitre;
    bool MAJ_pupitre = false;
};

class Reseau
{

private:
    TcpSocket client;
    Packet receivePacket;
    struct Eurobalise eurobalise;
    struct Pupitre_entrant pupitre_entrant;

public:

    Reseau();
    void Reseau_update();
    void TCPClient_update();
    void Serial_update();
    struct Pupitre_entrant getPupitre_entrant();
    struct Eurobalise getEurobalise();
};

#endif