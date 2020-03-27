#ifndef RS
#define RS

#include <iostream>
#include "define.hpp"

using namespace std;
struct Eurobalise
{
    short int longueur;
    short int vitesse;
    bool MAJ_eurobalise;
};
struct Pupitre_entrant
{
    string pupitre;
    int taille_pupitre;
    bool MAJ_pupitre;
};
struct Dynamique_train
{
    float A;
    float B;
    float C;
    float P_traction;
    float F_traction;
    float P_freinage;
    float mannip_traction;
    bool type_train;
};

class Reseau
{

private:
    TcpSocket client;
    Packet receivePacket;
    struct Eurobalise eurobalise;
    struct Pupitre_entrant pupitre_entrant;
    struct Dynamique_train dynamique_train;

public:

    Reseau();
    void Reseau_update();
    void TCPClient_update();
    void Serial_update();
    struct Pupitre_entrant getPupitre_entrant();
    struct Eurobalise getEurobalise();
    struct Dynamique_train getDynamique_train();
};

#endif