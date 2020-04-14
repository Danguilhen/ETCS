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
    string pupitre; //string contenant l'état des boutons (istringstream est utilisé pour pouvoir convertir les états des boutons en entiers par la suite)
    int taille_pupitre;
    bool MAJ_pupitre;
    int commande_projecteurs;
    int commande_disj;
    bool commande_BP_urgence;
    int commande_frein;
    int commande_sablage;
    bool commande_acquitt1;
    bool commande_acquitt2;
    int commande_essui_glace;
    bool commande_lave_glace;
    int commande_light_cabine;
    int commande_light_pupitre;
    int commande_sifflet;
    bool commande_LS_SF;
    bool commande_BP_SF;
    int commande_ETCS_release;
    float commande_VI;
    int commande_inverseur;
    int commande_conduct_mod;
    float commande_tract_frein;
    int commande_sens_porte;
    bool commande_annul_ouverture_porte;
    bool commande_BP_URG_panto;
    bool commande_BP_frein_neutre;
    bool commande_essai_VA;
    bool commande_annul_VA;
    bool commande_cle_BL;
    bool commande_ventilation;
    int commande_GROG;
    bool commande_TVM_V1;
    bool commande_TVM_V2;
    bool commande_TVM_desarm;
    bool commande_BP_alarme;
    bool commande_VA;
    int commande_BP_panto;
    int commande_allum_diesel;
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
      //geters commande boutons
        int getCmd_projecteurs();
        int getCmd_disj();
        bool getCmd_BP_urgence();
        int getCmd_frein();
        int getCmd_sablage();
        bool getCmd_acquitt1();
        bool getCmd_acquitt2();
        int getCmd_essui_glace();
        bool getCmd_lave_glace();
        int getCmd_light_cabine();
        int getCmd_light_pupitre();
        int getCmd_sifflet();
        bool getCmd_LS_SF();
        bool getCmd_BP_SF();
        int getCmd_ETCS_release();
        float getCmd_VI();
        int getCmd_inverseur();
        int getCmd_conduct_mod();
        float getCmd_tract_frein();
        int getCmd_sens_porte();
        bool getCmd_annul_ouverture_porte();
        bool getCmd_BP_URG_panto();
        bool getCmd_BP_frein_neutre();
        bool getCmd_essai_VA();
        bool getCmd_annul_VA();
        bool getCmd_cle_BL();
        bool getCmd_ventilation();
        int getCmd_GROG();
        bool getCmd_TVM_V1();
        bool getCmd_TVM_V2();
        bool getCmd_TVM_desarm();
        bool getCmd_BP_alarme();
        bool commande_VA();
        int getCmd_BP_panto();
        int getCmd_allum_diesel();
};

#endif