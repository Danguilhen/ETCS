#include "Reseau.hpp"
#include <iostream>
#include "define.hpp"
//#include "ArduSerial.h"

using namespace std;

Reseau::Reseau()
// Constructeur
//**********************************************************
{
    // Initialisation de la structure dynamique train aux paramètres de la duplex
    dynamique_train.A=2.27;
    dynamique_train.B=0.032;
    dynamique_train.C=0.00053;
    dynamique_train.P_traction=9280;
    dynamique_train.F_traction=222;
    dynamique_train.P_freinage=5000;
    dynamique_train.mannip_traction=0;
    dynamique_train.type_train = 0;
    // INITIALISATION DE LA LIAISON RESEAU TCP à UE4
    //bool done = false;
    short int port = 2000;
    // Définition de l'adresse IP de l'ordinateur sur le réseau local
    string ip = "192.168.0.30";
    // Définition du nom du client sur le Réseau
    string pseudo = "Train";
    // Connexion du Train au serveur
    if (client.connect(ip, port) == Socket::Done)
    {
        cout << "Connecte au serveur !\n" << endl;
        Packet sendPacket;
        sendPacket << pseudo;
        client.send(sendPacket);
        Packet Premier;
        while (client.receive(Premier) != Socket::Done)
            cout << "waiting for serveur";
        Premier >> dynamique_train.A >> dynamique_train.B >> dynamique_train.C >> dynamique_train.P_traction >> dynamique_train.F_traction >> dynamique_train.P_freinage >> dynamique_train.type_train;
    }
    else
        cout << "Serveur DOWN !" << endl;
    //Définissant des fonctions liés au train non bloquante
    client.setBlocking(false);
    cout << "Les parametres dynamiques du train sont les suivants:\n" << endl;
    cout << "coefficient A: " << dynamique_train.A << endl;
    cout << "coefficient B: " << dynamique_train.B << endl;
    cout << "coefficient c: " << dynamique_train.C << endl;
    cout << "Puissance: " << dynamique_train.P_traction << " KW" << endl;
    cout << "Effort maximal: " << dynamique_train.F_traction << "KN" << endl;
    cout << "Puissance en freinage:" << dynamique_train.P_freinage << "KW" << endl;
    cout << "type de train (1=fret, 0=voyageur): " << dynamique_train.type_train << endl <<endl;

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
        cout<<"mais merde";
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
struct Dynamique_train Reseau::getDynamique_train()
{
    return dynamique_train;
}
