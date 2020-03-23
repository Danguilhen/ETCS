#include "Reseau.hpp"
#include <iostream>
#include "define.hpp"
//#include "ArduSerial.h"

using namespace std;

Reseau::Reseau()
{
    // Constructeur
    //**********************************************************
    // INITIALISATION DE LA LIAISON RESEAU TCP à UE4
    short int port = 2000;
    // Définition de l'adresse IP de l'ordinateur sur le réseau local
    string ip = "192.168.2.107";
    // Définition du nom du client sur le Réseau
    string pseudo = "Train";
    // Connexion du Train au serveur
    if (client.connect(ip, port) == Socket::Done)
    {
        cout << "Connecte au serveur !\n" << endl;
        Packet sendPacket;
        sendPacket << pseudo;
        client.send(sendPacket);
    }
    else
        cout << "Serveur DOWN !" << endl;
    //Définissant des fonctions liés au train non bloquante
    client.setBlocking(false);


    //************************************************************
    // INITIALISATION DE LA LIAISON SERIE SUR LE PORT 7

    // creation du string. Mettre dedans le string qu'est censé recevoir l'ordinateur
    pupitre_entrant.pupitre = "AB";
    pupitre_entrant.taille_pupitre = pupitre_entrant.pupitre.length();

    // A partir de cette ligne, tout est commenté le temps que aucune liaison n'est établie
    /*
    // Initialisation de la liaison série sur le port 7
    Serial7.begin(115200);
    std::cout << "Starting..." << std::endl;

    // Test la liaison initialisée
    while (!Serial7);
    while (Serial7.available())
        Serial7.read();
    // Confirmation de la création de la liaison
    std::cout << "Connected" << std::endl; */
    }


void Reseau::Reseau_update() // Update des fonctions calculs et affichages de ETCS
{
    Reseau::TCPClient_update();
   // Reseau::Serial_update();

}
void Reseau::TCPClient_update()
{
    eurobalise.MAJ_eurobalise = false;
    if (client.receive(receivePacket) == Socket::Done)
    {
        eurobalise.MAJ_eurobalise = true;
        receivePacket >> eurobalise.vitesse >> eurobalise.longueur;
        cout << "la vitesse max est" << eurobalise.vitesse << " km/h\n" << "la longueur de la MA est de " << eurobalise.longueur << " m\n" << endl;
    }
}
void Reseau::Serial_update()
{
    pupitre_entrant.MAJ_pupitre = false;
    /*if (Serial7.available() == pupitre_entrant.taille_pupitre)
    {
        pupitre_entrant.MAJ_pupitre = true;
        pupitre_entrant.pupitre = "";
        while (Serial7.available())
            pupitre_entrant.pupitre = pupitre_entrant.pupitre + (char)Serial7.read();
        cout << pupitre_entrant.pupitre << endl;
    }*/
}
struct Pupitre_entrant Reseau::getPupitre_entrant()
{
    return pupitre_entrant;
}
struct Eurobalise Reseau::getEurobalise()
{
    return eurobalise;
}

