#ifndef dem
#define dem

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

/*
class TRACK_TO_TRAIN
{
	//All Variables have one of the following prefixes:
	//A_ Acceleration
	//D_ distance
	//G_ Gradient
	//L_ length
	//M_ Miscellaneous
	//N_ Number
	//NC_ class number
	//NID_ identity number
	//Q_ Qualifier
	//T_ time/date
	//V_ Speed
	//X_ Text
	Virtual_Balise_Cover_marker packet0;
	System_Version_order packet2;
	National_Values packet3;
	Linking packet5;
	Virtual_Balise_Cover_order packet6;
	Level_1_Movement_Authority packet12;
	Staff_Responsible_distance_information_from_loop packet13;
	Level_2_3_Movement_Authority packet15;
	Repositioning_Information packet16;
	Gradient_Profile packet21;
	International_Static_Speed_Profile packet27;
	Track_Condition_Change_of_traction_system packet39;
	Track_Condition_Change_of_allowed_current_consumption packet40;
	Level_Transition_Order packet41;
	Session_Management packet42;
	Data_ueed_by_applications_outside_the_ERTMS/ETCS_system packet44;
	Radio_Network_registration packet45;
	Conditional_Level_Transition_Order packet46;
	List_of_balises_for_SH_Area packet49;
	Axle_load_Speed_Profile packet51;
	Permitted_Braking_Distance_Information packet52;
	Movement_Authority_Request_Parameters packet57;
	Position_Report_Parameters packet58;
	List_of_Balises_in_SR_Authority packet63;
	Inhibition_of_revocable_TSRs_from_balises_in_L2_3 packet64;
	Temporary_Speed_Restriction packet65;
	Temporary_Speed_Restriction_Revocation packet66;
	Track_Condition_Big_Metal_Masses packet67;
	Track_Condition packet68;
	Track_Condition_Station_Platforms packet69;
	Route_Suitability_Data packet70;
	Adhesion_Factor packet71;
	Packet_for_sending_plain_text_messages packet72;
	Packet_for_sending_fixed_text_messages packet76;
	Geographical_Position_Information packet79;
	Mode_profile packet80;
	Level_crossing_information packet88;
	Track_Ahead_Free_up_to_level2_3_transition_location packet90;
	RBC_transition_order packet131;
	Danger_for_Shunting_information packet132;
	Radion_infill_area_information packet133;
	EOLM_Packet packet134;
	Stop_Shunting_on_desk_opening packet135;
	Infill_location_reference packet136;
	Stop_if_in_Staff_Responsible packet137;
	Reversing_area_information packet138;
	Reversing_supervision_information packet139;
	Train_running_number_from_RBC packet140;
	Default_Gradient_for_Temporary_Speed_Restriction packet141;
	Session_Management_with_neighbouring_Radio_Infill_Unit packet143;
	Inhibition_of_balise_group_message_consistency_reaction packet145;
	LSSMA_display_toggle_order packet180;
	Generic_LS_function_marker packet181;
	Default_balise_loop_or_RIU_information packet254;
	End_of_Information packet255;
};


class TRAIN_TO_TRACK
{
	Position_Report packet0;
	Position_Report_based_on_two_balise_groups packet1;
	Onboard_supported_system_versions packet2;
};


class Virtual_Balise_Cover_marker
{
	int NID_PACKET;
	int NID_VBCMK;
};


class System_Version_order
{
	int NID_PACKET;
	int Q_DIR;
	int L_PACKET;
	int M_VERSION;
};


class National_values
{
	int NID_PACKET;
	int Q_DIR;
	int L_PACKET;
	int Q_SCALE;
	int D_VALIDNV;
	int NID_C;
	int N_ITER;
	int NID_Ck;    //<----------------------------------- PAS SUR
	int V_NVSHUNT;
	int V_NVSTFF;
	int V_NVONSIGHT;
	int V_NVLIMSUPERV;
	int V_NVUNFIT;
};

*/
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
	void mode_test();

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