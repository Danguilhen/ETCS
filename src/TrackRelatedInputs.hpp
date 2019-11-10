#ifndef TRI
#define TRI

class TrackRelatedInputs
{
	public :
	National_Value_Data NVD;
	TracksideSpeedRestriction TSR;
}

class National_Value_Data
{
private:

bool Q_NVDRIVER_ADHES; //Modification of adhesion factor by driver
int V_NVSHUNT; //Shunting mode speed limit
int V_NVSTFF; //Staff Responsible mode speed limit
int V_NVONSIGHT; //On Sight mode speed limit
int V_NVLIMSUPERV; //Limited Supervision mode speed limit
int V_NVUNFIT ; //Unfitted mode speed limit
int V_NVREL; //Release Speed
float D_NVROLL; //Distance to be used in Roll Away protection, Reverse movement protection and Standstill supervision
bool Q_NVSBTSMPERM; //Permission to use service brake in target speed monitoring
bool Q_NVEMRRLS; //Permission to release emergency brake
bool Q_NVGUIPERM; //Permission to use guidance curves
bool Q_NVSBFBPERM; //Permission to use the service brake feedback
bool Q_NVINHSMICPERM; //Permission to inhibit the compensation of the speed measurement inaccuracy
int V_NVALLOWOVTRP; //Speed limit for triggering the override function
int V_NVSUPOVTRP; //Override speed limit to be supervised when the “override” function is active
int D_NVOVTRP; //Distance for train trip suppression when override function is triggered
float T_NVOVTRP; //Max. time for train trip suppression when override function is triggered
bool M_NVDERUN; //Change of driver ID permitted while running
bool M_NVCONTACT; //System reaction if T_NVCONTACT elapses
float T_NVCONTAC; //Maximum time since the time-stamp in the last received message
float D_NVPOTRP; //Distance to be allowed for reversing in Post Trip mode.
float D_NVSTFF; //Max permitted distance to run in Staff Responsible mode
float Q_NVLOCACC; //Default location accuracy of a balise group
float M_NVAVADH; //Weighting factor for available wheel/rail adhesioN
float M_NVEBCL; //Confidence level for emergency brake safe deceleration on dry rails
float L_NVKRINT; //Train length step used for the integrated correction factor Kr_int
float M_NVKRINT; //Train length dependent integrated correction factor Kr_int
float V_NVKVINT; //Speed step used for the integrated correction factor Kv_int
float M_NVKVINT; //Speed dependent integrated correction factor Kv_int
float M_NVKTINT; //Integrated correction factor for brake build up time
float A_NVMAXREDADH1; //Maximum deceleration value under reduced adhesion conditions (1)
float A_NVMAXREDADH2; //Maximum deceleration value under reduced adhesion conditions (2)
float A_NVMAXREDADH3; //Maximum deceleration value under reduced adhesion conditions (3)
float A_NVP12; //Lower deceleration limit to determine the set of Kv_int to be used
float A_NVP23; //Upper deceleration limit to determine the set of Kv_int to be used

public:

National_Value_Data(); // Le constructeur
void Afficher_National_value_data();

bool getQ_NVDRIVER_ADHES();
int getV_NVSHUNT();
int getV_NVSTFF();
int getV_NVONSIGHT();
int getV_NVLIMSUPERV();
int getV_NVUNFIT();
int getV_NVREL();
float getD_NVROLL();
bool getQ_NVSBTSMPERM();
bool getQ_NVEMRRLS();
bool getQ_NVGUIPERM();
bool getQ_NVSBFBPERM();
bool getQ_NVINHSMICPERM();
int getV_NVALLOWOVTRP();
int getV_NVSUPOVTRP();
int getD_NVOVTRP();
float getT_NVOVTRP();
bool getM_NVDERUN();
bool getM_NVCONTACT();
float getT_NVCONTAC();
float getD_NVPOTRP();
float getD_NVSTFF();
float getQ_NVLOCACC();
float getM_NVAVADH();
float getM_NVEBCL();
float getL_NVKRINT();
float getM_NVKRINT();
float getV_NVKVINT();
float getM_NVKVINT();
float getM_NVKTINT();
float getA_NVMAXREDADH1();
float getA_NVMAXREDADH2();
float getA_NVMAXREDADH3();
float getA_NVP12();
float getA_NVP23();

};


class TracksideSpeedRestriction
{
	private :

	vector< vector< int > > vitesse_tab_futur{{200, 10000}};//Chaque accolade correspond à une vitesse et la distance sur laquelle cette V s'applique

	public :
	int x;

	//void actualisation_vitesse();//Si une vitesse vient se rajouter

}
#endif