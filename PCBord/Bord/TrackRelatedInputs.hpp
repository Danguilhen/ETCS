#ifndef BBB
#define BBB

#include "../Tools.hpp"
#include "TrainRelatedInputs.hpp"
#include "../Train_dynamique.hpp"
#include "../Reseau.hpp"
#include "../define.hpp"

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
	double D_NVROLL; //Distance to be used in Roll Away protection, Reverse movement protection and Standstill supervision
	bool Q_NVSBTSMPERM; //Permission to use service brake in target speed monitoring
	bool Q_NVEMRRLS; //Permission to release emergency brake
	bool Q_NVGUIPERM; //Permission to use guidance curves
	bool Q_NVSBFBPERM; //Permission to use the service brake feedback
	bool Q_NVINHSMICPERM; //Permission to inhibit the compensation of the speed measurement inaccuracy
	int V_NVALLOWOVTRP; //Speed limit for triggering the override function
	int V_NVSUPOVTRP; //Override speed limit to be supervised when the “override” function is active
	int D_NVOVTRP; //Distance for train trip suppression when override function is triggered
	double T_NVOVTRP; //Max. time for train trip suppression when override function is triggered
	bool M_NVDERUN; //Change of driver ID permitted while running
	bool M_NVCONTACT; //System reaction if T_NVCONTACT elapses
	double T_NVCONTAC; //Maximum time since the time-stamp in the last received message
	double D_NVPOTRP; //Distance to be allowed for reversing in Post Trip mode.
	double D_NVSTFF; //Max permitted distance to run in Staff Responsible mode
	double Q_NVLOCACC; //Default location accuracy of a balise group
	double M_NVAVADH; //Weighting factor for available wheel/rail adhesioN
	double M_NVEBCL; //Confidence level for emergency brake safe deceleration on dry rails
	double L_NVKRINT; //Train length step used for the integrated correction factor Kr_int
	double M_NVKRINT; //Train length dependent integrated correction factor Kr_int
	double V_NVKVINT; //Speed step used for the integrated correction factor Kv_int
	double M_NVKVINT; //Speed dependent integrated correction factor Kv_int
	double M_NVKTINT; //Integrated correction factor for brake build up time
	double A_NVMAXREDADH1; //Maximum deceleration value under reduced adhesion conditions (1)
	double A_NVMAXREDADH2; //Maximum deceleration value under reduced adhesion conditions (2)
	double A_NVMAXREDADH3; //Maximum deceleration value under reduced adhesion conditions (3)
	double A_NVP12; //Lower deceleration limit to determine the set of Kv_int to be used
	double A_NVP23; //Upper deceleration limit to determine the set of Kv_int to be used

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
	double getD_NVROLL();
	bool getQ_NVSBTSMPERM();
	bool getQ_NVEMRRLS();
	bool getQ_NVGUIPERM();
	bool getQ_NVSBFBPERM();
	bool getQ_NVINHSMICPERM();
	int getV_NVALLOWOVTRP();
	int getV_NVSUPOVTRP();
	int getD_NVOVTRP();
	double getT_NVOVTRP();
	bool getM_NVDERUN();
	bool getM_NVCONTACT();
	double getT_NVCONTAC();
	double getD_NVPOTRP();
	double getD_NVSTFF();
	double getQ_NVLOCACC();
	double getM_NVAVADH();
	double getM_NVEBCL();
	double getL_NVKRINT();
	double getM_NVKRINT();
	double getV_NVKVINT();
	double getM_NVKVINT();
	double getM_NVKTINT();
	double getA_NVMAXREDADH1();
	double getA_NVMAXREDADH2();
	double getA_NVMAXREDADH3();
	double getA_NVP12();
	double getA_NVP23();

};


class TracksideSpeedRestriction : public Tools
{
	private :
		//std::vector<std::vector<double>> tableau_vitesse_ligne = {{0, 0, 0}};//[distance debut][distance fin][vitesse]
		std::vector<std::vector<double>> tableau_vitesse_ligne{{0, 5000, 250}, {5000, 10000, 160}, {10000, 17000, 200}, {17000, 20000, 50}, {20000,23000, 0}};//[distance debut][distance fin][vitesse]
		bool speed_change = true;
		Reseau *Res;
	public :
		TracksideSpeedRestriction(Reseau &Res);
		std::vector<std::vector<double>> getVitesseTableau();
		void TSR_Update(double distance_update);
		bool getSpeed_change();
		void setSpeed_change(bool S);

	//void actualisation_vitesse();//Si une vitesse vient se rajouter

};


class Gradient : public Tools
{
	private :
		std::vector<std::vector<double>> tableau_gradient{{0, 2000, 0}, {2000, 4000, -5}, {4000, 5000, 10}, {5000, 12500, 20}, {12500, 20000, -5} } ;//[distance debut][distance fin][gradient]
		TrainRelatedInputs *TrainRI;
	public :
		Gradient(TrainRelatedInputs &TrainRI);
		std::vector<std::vector<double>> getTab_Gradient();
		void Gradient_Update(double distance_update);//permet de déterminer le gradient à prendre en compte

		//void actualisation_vitesse();//Si une vitesse vient se rajouter

};


class SpeedAndDistanceLimits
{
	private :
		double target_distance;
		double speed_target;
		bool target_update = false;
		TracksideSpeedRestriction *TSR;
	public :
		SpeedAndDistanceLimits(TracksideSpeedRestriction &TSR);
		void target_determination();
		void Target_update();
		void SADL_update();
		double getTargetDistance();
		void SetTargetDistance(double D);
		double getSpeedTarget();
		void setSpeedTarget(double S);
		bool getTarget_update();
		void setTarget_update(bool B);

};


class TrackRelatedInputs
{
	private :
		double pointKilometrique = 0.0;
		double remainingDistanceTunnel = 500;
		std::string tunnelStoppingArea = "TunnelStoppingArea";
		//Clock chronoTRI;//créer le chrono
		//Time diftimeTRI;//créer la varaible qui stocke le temps écoulé
		//double deltatsTRI;//créer la variable qui stocke le temps écoulé en seconde
		//double distance_update; // distance parcourue entre chaque mise à jour
		Train_dynamique *T_D;
		Reseau *Res;

	public :
		National_Value_Data NVD;
		TracksideSpeedRestriction TSR;
		Gradient gradient_ligne;
		SpeedAndDistanceLimits SADL;
		TrackRelatedInputs(TrainRelatedInputs &TrainRI, Train_dynamique &T_D, Reseau &Res);
		void TrackRI_Update();
		double getPointKilometrique();
		void setPointKilometrique(double P);
		double getRemainingDistanceTunnel();
		std::string getTunnelStoppingArea();
		void setTunnelStoppingArea(std::string TSA);
};

class AnnouncementInfrastructureInformation
{

	private :
	std::vector<std::vector<double>> tab_announcement; // [distance][numero de l'annonce]

	public :
	AnnouncementInfrastructureInformation();
	void getTab_announcement();

};


#endif