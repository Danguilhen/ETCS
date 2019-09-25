#ifndef dem
#define dem

#include "symbol.hpp"

#define VINIT 250
#define ACCELERATION -0.9
#define D_BUT 2000.0
#define V_BUT 200
#define V_LIGNE 300
#define R_SPEED 30
class Traction_models
{

};
class Breaking_models
{

};
class Train_Data
{
	private :

	string category;
	int length = 200;
	//traction_models � voir avec Benoit 3.13 (vector)
	//breaking_models � voir avec Benoit 3.13 (vector)
	int breaking_percetage = 100;
	string train_category = "PASS 1";
	vector <float> Onboard_correction_factors;
	int nominal_rotating_mass;
	int maximum_train_speed = 300;
	string loading_gauge = "GC";
	string axle_load_category = "D4XL";
	vector <string> traction_systems; // incertain
	vector <string> List_of_National_Systems_available_onboard;
	string airtight = "Yes";
	int axle_number;
	int driver_id = 0;
	int driver_idTemp = 0;
	int train_running_number = 881702;
	string train_type = "PASS";


	public :

	Breaking_models breaking_models;
	Traction_models traction_models;

	// ATTENTION LES FONCTIONS N ONT PAS ETE CREES DANS LE CPP
	int getlength();
	void setlength(int P);
	int getbreaking_percetage();
	void setbreaking_percetage(int P);
	vector <float> getOnboard_correction_factors();
	void setOnboard_correction_factors(vector <float> P);
	int getnominal_rotating_mass();
	void setnominal_rotating_mass(int P);
	int getmaximum_train_speed();
	void setmaximum_train_speed(int P);
	string getloading_gauge();
	void setloading_gauge(string P);
	string getaxle_load_category();
	void setaxle_load_category(string P);
	int getaxle_number();
	void setaxle_number(int P);
	vector <string> gettraction_systems();
	void settraction_systems(vector <string> P);
	vector <string> getList_of_National_Systems_available_onboard();
	void setList_of_National_Systems_available_onboard(vector <string> P);
	string getTrain_category();
	void setTrain_category(string P);
	string getAirtight();
	void setAirtight(string P);
	int getDriver_ID();
	void setDriver_ID(int P);
	int getTempDriver_ID();
	void setTempDriver_ID(int P);
	int getTrain_running_number();
	void setTrain_running_number(int P);
	void setTrain_type(string P);
	string getTrain_type();
};

class donnees
{

	private :

	float V_ligne;						//ici consid�r�e comme la vitesse ligne
	float V_but;						//Vitesse but
	float d_but;
	float Vf_ISL;						//Indication supervision limit
	float Vf_PSL;						//Permited supervision limit
	float Vf_FLOISL;					//FLOI supervision limit
	//float Vf_release;					//Release speed
	float d_train_EOA;					//distance avant but d�croit vers 0
	float V_train = -1;						//Vitesse mise � jour du train
	float V_init;						//vitesse initiale
	float d_parcourue;					//distance parcourue en entrant dans la TSM
	float a_train;						//acc�l�ration du train
	bool etat_train = false;			//le train est entrain de freiner

	string mode = "CSM";
	string status = "NoS";
	float VWaS = 0 ;
	string generalMode = "FS";
	float Vscale = 400;

	string tunnelStoppingArea = "TunnelStoppingArea";
	string reversing = "Permitted";
	string geographicalPosition = "On";
	string connection = "Up";
	float V_red;
	float V_orange;
	float V_yellow;
	float V_white ;
	float V_medium_grey;
	float V_dark_grey;
	int pointKilometrique = 256708;
	float TSMstart = 800;
	float planningScale = 32000;
	Color couleurAiguille = RED;		//Changer la couleur de l'aiguille
	int remainingDistanceTunnel = 348;
	float Vrelease = 30;

	bool driverid = true;
	bool traindata = true;
	string ETCS_level = "Level 1";
	bool etat_level = true;
	bool train_number = true;
	bool pending_emergency_stop = false;
	bool modif_driverid_NTC = true;
	bool passive_shunting = true;
	bool non_leading = true;
	bool modif_adhesion = true;
	string planning = "show planning information";
	string speed_and_distance_monitoring = "On";


	bool EOA = false;
	int SRspeed = 30;
	string adhesion = "Slippery Rail";
	string language = "English";
	int RBCID = 0;
	int RBCIDtemp = 0;
	int RBCphoneNumber = 0;
	int RBCphoneNumbertemp = 0;
	string radioNetworkID = "GSMR-A";
	int clignotementTexte = 0;

	float TTI;

	public :

	Train_Data train_Data;

	donnees(float vitesse_EOA, float vitesse_train, float distance_but, float vitesse_ligne, float acceleration);
	donnees();

	float getDEOA();
	float getVitesseISL();
	float getVitessePSL();
	float getVitesseFLOISL();
	float getVtrain();
	void setVtrain(float V);
	void setVligne(float V);
	float getVligne();
	void setDEOA(float d);
	float getVbut();
	void setVbut(float V);
	float getD_but();
	void setD_but(float D);
	void setA_train(float A);
	int getRemainingDistanceTunnel();
	Color getCouleurAiguille();
	void setCouleurAiguille(Color T);
	string getTunnelStoppingArea();
	void setTunnelStoppingArea(string P);
	string getReversing();
	string getGeographicalPosition();
	void setGeographicalPosition(string P);
	string getConnection();
	float getVred();
	float getVorange();
	float getVyellow();
	float getVwhite();
	float getVmediumGrey();
	float getVdarkGrey();
	void setVred(float V);
	void setVorange(float V);
	void setVyellow(float V);
	void setVwhite(float V);
	void setVmediumGrey(float V);
	void setVdarkGrey(float V);
	int getPointKilometrique();
	float getTSMstart();
	float getPlanningScale();
	void setPlanningScale(float P);
	void setMode(string M);
	string getMode();
	void setStatus(string S);
	string getStatus();
	float getVWaS();
	void setVWaS(float V);
	string getGeneralMode();
	void setGeneralMode(string G);
	float getVscale();
	void setVscale(float V);
	float getVrelease();
	bool getEtat_train();
	void setEtat_train(bool R);
	void setDriverID(bool D);
	bool getDriverID();
	bool getTrainData();
	void setTrainData(bool R);
	void setETATLevelETCS(bool R);
	bool getETATLevelETCS();
	string getLevelETCS();
	void setLevelETCS(string N);
	void setTrainNuber(bool R);
	bool getTrainNumber();
	void setPending_Emergency_Stop(bool S);
	bool getPending_Emergency_Stop();
	void setModif_DriverID_NTC(bool S);
	bool getModif_DriverID_NTC();
	bool getPassive_Shunting();
	void setPassive_Shunting(bool P);
	bool getNon_Leading();
	void setNon_Leading(bool P);
	bool getmodif_Adhesion();
	void setmodif_Adhesion(bool P);
	string getPlanning();
	void setPlanning(string P);
	string getS_D_monitoring();
	void setS_D_monitoring(string P);
	Train_Data get_cTrain_data();
	void set_cTrain_Data(Train_Data & P);
	bool getEOA();
	void setEOA(bool P);
	int getSRspeed();
	void setSRspeed(int N);
	string getAdhesion();
	void setAdhesion(string P);
	string getLanguage();
	void setLanguage(string P);
	int getRBCID();
	void setRBCID(int N);
	int getTempRBCID();
	void setTempRBCID(int N);
	int getRBCphoneNumber();
	void setRBCphoneNumber(int N);
	int getTempRBCphoneNumber();
	void setTempRBCphoneNumber(int N);
	string getRadioNetworkID();
	void setRadioNetworkID(string P);
	int getClignotementTexte();
	void setClignotementTexte(int N);
	float getTTI();
	void setTTI(float N);

	//Fonctions utilis�s dans calcul
	void vitesse_train(float delta_ts);//mise � jour de la vitesse train
	void delta_d(float delta_ts);//mise � jour de la distance parcourue en fonction de la vitesse train

	void TSM(float delta_ts);//R�duction de vitesse
	void CSM_PIM(float delta_ts);//Si vitesse au dessus de la release speed

};


class VBC
{
 /*A COMPLETER LORS DU TRAVAIL SUR LES VBC*/
};

void calcul(float delta_ts, donnees &donnee);
void demo(donnees &donnee);
void demo2(donnees &donnee);



#endif