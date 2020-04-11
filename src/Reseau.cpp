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
    pupitre_entrant.pupitre = "%1024!0!0!00!0!0!0!01!00!00!00!00!00!10%";

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

    // INITIALISATION DES COMMANDES A 0

    //pupitre_entrant.commande_projecteurs = 0;
    pupitre_entrant.commande_disj = 0;
    pupitre_entrant.commande_BP_urgence = 0;
    pupitre_entrant.commande_frein = 0;
    //pupitre_entrant.commande_sablage = 0;
    pupitre_entrant.commande_acquitt1 = 0;
    pupitre_entrant.commande_acquitt2 = 0;
    //pupitre_entrant.commande_essui_glace = 0;
    //pupitre_entrant.commande_lave_glace = 0;
    //pupitre_entrant.commande_light_cabine = 0;
    //pupitre_entrant.commande_light_pupitre = 0;
    pupitre_entrant.commande_sifflet = 0;
    //pupitre_entrant.commande_LS_SF = 0;
    pupitre_entrant.commande_BP_SF = 0;
    //pupitre_entrant.commande_ETCS_release = 0;
    //pupitre_entrant.commande_VI = 0;
    //pupitre_entrant.commande_inverseur = 0;
    //pupitre_entrant.commande_conduct_mod = 0;
    pupitre_entrant.commande_tract_frein = 0;
    //pupitre_entrant.commande_sens_porte = 0;
    //pupitre_entrant.commande_annul_ouverture_porte = 0;
    pupitre_entrant.commande_BP_URG_panto = 0;
    pupitre_entrant.commande_BP_frein_neutre = 0;
    //pupitre_entrant.commande_essai_VA = 0;
    //pupitre_entrant.commande_annul_VA = 0;
    pupitre_entrant.commande_cle_BL = 0;
    //pupitre_entrant.commande_ventilation = 0;
    //pupitre_entrant.commande_GROG = 0;
    pupitre_entrant.commande_TVM_V1 = 0;
    pupitre_entrant.commande_TVM_V2 = 0;
    //pupitre_entrant.commande_TVM_desarm = 0;
    pupitre_entrant.commande_BP_alarme = 0;
    pupitre_entrant.commande_VA = 0;
    pupitre_entrant.commande_BP_panto = 0;
    pupitre_entrant.commande_allum_diesel = 0;


    Reseau::Serial_update();

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

    //ACTUALISATION DE L'ETAT DES BOUTONS
    //"%0024!0!0!00!0!0!0!00!00!00!00!00!00!00!00%"

    // string etat;
    // int i=0;
    // for (i=1;i<=4;i++)
    // {
    // etat = etat + pupitre_entrant.pupitre[i];
    // }
    // pupitre_entrant.commande_tract_frein = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[6];
    // pupitre_entrant.commande_BP_URG_panto = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[8];
    // pupitre_entrant.commande_BP_SF = atoi(etat.c_str());

    //etat = pupitre_entrant.pupitre[10];
    // pupitre_entrant.commande_sifflet_pin1 = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[11];
    // pupitre_entrant.commande_sifflet_pin2 = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[13];
    // pupitre_entrant.commande_BP_frein_neutre = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[15];
    // pupitre_entrant.commande_acquitt1 = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[17];
    // pupitre_entrant.commande_acquitt2 = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[19];
    // pupitre_entrant.commande_allum_diesel_pin1 = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[20];
    // pupitre_entrant.commande_allum_diesel_pin2 = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[22];
    // pupitre_entrant.commande_disj_pin1 = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[23];
    // pupitre_entrant.commande_disj_pin2 = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[25];
    // pupitre_entrant.commande_frein_pin1 = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[26];
    // pupitre_entrant.commande_frein_pin2 = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[28];
    // pupitre_entrant.commande_BP_panto_pin1 = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[29];
    // pupitre_entrant.commande_BP_panto_pin2 = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[31];
    // pupitre_entrant.commande_TVM_V1 = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[32];
    // pupitre_entrant.commande_TVM_V2 = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[34];
    // pupitre_entrant.commande_cle_BL_pin1 = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[35];
    // pupitre_entrant.commande_cle_BL_pin2 = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[37];
    // pupitre_entrant.commande_VA_pin1 = atoi(etat.c_str());

    // etat = pupitre_entrant.pupitre[38];
    // pupitre_entrant.commande_VA_pin2 = atoi(etat.c_str());


    // cout << "yes" << endl;
    // cout << pupitre_entrant.commande_tract_frein << endl;
    // cout << pupitre_entrant.commande_sifflet << endl;
    // cout << pupitre_entrant.commande_VA << endl;

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

int Reseau::getCmd_projecteurs(){return pupitre_entrant.commande_projecteurs;}
int Reseau::getCmd_disj(){return pupitre_entrant.commande_disj;}
bool Reseau::getCmd_BP_urgence(){return pupitre_entrant.commande_BP_urgence;}
int Reseau::getCmd_frein(){return pupitre_entrant.commande_frein;}
int Reseau::getCmd_sablage(){return pupitre_entrant.commande_sablage;}
bool Reseau::getCmd_acquitt1(){return pupitre_entrant.commande_acquitt1;}
bool Reseau::getCmd_acquitt2(){return pupitre_entrant.commande_acquitt2;}
int Reseau::getCmd_essui_glace(){return pupitre_entrant.commande_essui_glace;}
bool Reseau::getCmd_lave_glace(){return pupitre_entrant.commande_lave_glace;}
int Reseau::getCmd_light_cabine(){return pupitre_entrant.commande_light_cabine;}
int Reseau::getCmd_light_pupitre(){return pupitre_entrant.commande_light_pupitre;}
int Reseau::getCmd_sifflet(){return pupitre_entrant.commande_sifflet;}
bool Reseau::getCmd_LS_SF(){return pupitre_entrant.commande_LS_SF;}
bool Reseau::getCmd_BP_SF(){return pupitre_entrant.commande_BP_SF;}
int Reseau::getCmd_ETCS_release(){return pupitre_entrant.commande_ETCS_release;}
float Reseau::getCmd_VI(){return pupitre_entrant.commande_VI;}
int Reseau::getCmd_inverseur(){return pupitre_entrant.commande_inverseur;}
int Reseau::getCmd_conduct_mod(){return pupitre_entrant.commande_conduct_mod;}
float Reseau::getCmd_tract_frein(){return pupitre_entrant.commande_tract_frein;}
int Reseau::getCmd_sens_porte(){return pupitre_entrant.commande_sens_porte;}
bool Reseau::getCmd_annul_ouverture_porte(){return pupitre_entrant.commande_annul_ouverture_porte;}
bool Reseau::getCmd_BP_URG_panto(){return pupitre_entrant.commande_BP_URG_panto;}
bool Reseau::getCmd_BP_frein_neutre(){return pupitre_entrant.commande_BP_frein_neutre;}
bool Reseau::getCmd_essai_VA(){return pupitre_entrant.commande_essai_VA;}
bool Reseau::getCmd_annul_VA(){return pupitre_entrant.commande_annul_VA;}
bool Reseau::getCmd_cle_BL(){return pupitre_entrant.commande_cle_BL;}
bool Reseau::getCmd_ventilation(){return pupitre_entrant.commande_ventilation;}
int Reseau::getCmd_GROG(){return pupitre_entrant.commande_GROG;}
bool Reseau::getCmd_TVM_V1(){return pupitre_entrant.commande_TVM_V1;}
bool Reseau::getCmd_TVM_V2(){return pupitre_entrant.commande_TVM_V2;}
bool Reseau::getCmd_TVM_desarm(){return pupitre_entrant.commande_TVM_desarm;}
bool Reseau::getCmd_BP_alarme(){return pupitre_entrant.commande_BP_alarme;}
bool Reseau::commande_VA(){return pupitre_entrant.commande_VA;}
int Reseau::getCmd_BP_panto(){return pupitre_entrant.commande_BP_panto;}
int Reseau::getCmd_allum_diesel(){return pupitre_entrant.commande_allum_diesel;}
