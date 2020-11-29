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
    unsigned int taille_pupitre;
    bool MAJ_pupitre;
    int commande_projecteurs;
    int commande_disj_pin1;
    int commande_disj_pin2;
    bool commande_BP_urgence;
    int commande_frein_pin1;
    int commande_frein_pin2;
    int commande_sablage;
    bool commande_acquitt1;
    bool commande_acquitt2;
    int commande_essui_glace;
    bool commande_lave_glace;
    int commande_light_cabine;
    int commande_light_pupitre;
    int commande_sifflet_pin1;
    int commande_sifflet_pin2;
    bool commande_LS_SF;
    bool commande_BP_SF;
    int commande_ETCS_release;
    double commande_VI;
    int commande_inverseur;
    int commande_conduct_mod;
    double commande_tract_frein;
    int commande_sens_porte;
    bool commande_annul_ouverture_porte;
    bool commande_BP_URG_panto;
    bool commande_BP_frein_neutre;
    bool commande_essai_VA;
    bool commande_annul_VA;
    bool commande_cle_BL_pin1;
    bool commande_cle_BL_pin2;
    bool commande_ventilation;
    int commande_GROG;
    bool commande_TVM_V1;
    bool commande_TVM_V2;
    bool commande_TVM_desarm;
    bool commande_BP_alarme;
    bool commande_VA_pin1;
    bool commande_VA_pin2;
    int commande_BP_panto_pin1;
    int commande_BP_panto_pin2;
    int commande_allum_diesel_pin1;
    int commande_allum_diesel_pin2;
};
struct Dynamique_train
{
    double A;
    double B;
    double C;
    double P_traction;
    double F_traction;
    double P_freinage;
    double mannip_traction;
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
    sf::TcpSocket sock;
    std::size_t received;
    // variable a partager
    double res_vitesse;
	int port = 52001;
	string ip = "192.168.1.105";
	SOCKET ConnectSocket = INVALID_SOCKET;
	int startUp = 0;
	struct sockaddr_in server;
	bool validationSocket = 0;

    // variables TVM
    double mainFrequency;
    double secondFrequency;
    double selfTimer;
	int sideFrequency;

	int loop = 0;

public:

    Reseau();
    void SocketSendInit();
    void SocketUpdate();
    void Reseau_update();
    void TCPClient_update();
    void Serial_update();
    struct Pupitre_entrant getPupitre_entrant();
    struct Eurobalise getEurobalise();
    struct Dynamique_train getDynamique_train();

    // fonctions variable a partager

    double getRes_vitesse();
    void setRes_vitesse(double V);

    // fonctions TVM

    double getMainFrequency();
    void setMainFrequency(double MF);

    double getSecondFrequency();
    void setSecondFrequency(double SF);

    double getSelfTimer();
    void setSelfTimer(double ST);



	int getSideFrequency();
	void setSideFrequency(int SIF);

	bool getValidationSocket();

      //geters commande boutons
       // int getCmd_projecteurs();
        // int getCmd_disj();
        // bool getCmd_BP_urgence();
        // int getCmd_frein();
        // int getCmd_sablage();
        // bool getCmd_acquitt1();
        // bool getCmd_acquitt2();
        // int getCmd_essui_glace();
        // bool getCmd_lave_glace();
        // int getCmd_light_cabine();
        // int getCmd_light_pupitre();
        // int getCmd_sifflet();
        // bool getCmd_LS_SF();
        // bool getCmd_BP_SF();
        // int getCmd_ETCS_release();
        // double getCmd_VI();
        // int getCmd_inverseur();
        // int getCmd_conduct_mod();
        // double getCmd_tract_frein();
        // int getCmd_sens_porte();
        // bool getCmd_annul_ouverture_porte();
        // bool getCmd_BP_URG_panto();
        // bool getCmd_BP_frein_neutre();
        // bool getCmd_essai_VA();
        // bool getCmd_annul_VA();
        // bool getCmd_cle_BL();
        // bool getCmd_ventilation();
        // int getCmd_GROG();
        // bool getCmd_TVM_V1();
        // bool getCmd_TVM_V2();
        // bool getCmd_TVM_desarm();
        // bool getCmd_BP_alarme();
        // bool commande_VA();
        // int getCmd_BP_panto();
        // int getCmd_allum_diesel();
};

#endif