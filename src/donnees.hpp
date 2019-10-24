#ifndef dem
#define dem

#include "symbol.hpp"

#define VINIT 250
#define ACCELERATION -0.9
#define D_BUT 2000.0
#define V_BUT 200
#define V_LIGNE 300
#define R_SPEED 30


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

		float VWaS = 0 ;
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






		int Vtrain;
		string generalMode = "FS";
		string mode = "CSM";
		string status = "NoS";
		string level = "Level 1";

	public :
		donnees(float vitesse_EOA, float vitesse_train, float distance_but, float vitesse_ligne, float acceleration);
		donnees();
		int getVtrain();
		string getGeneralMode();
		string getMode();
		string getStatus();
		string getLevel();
};

#endif