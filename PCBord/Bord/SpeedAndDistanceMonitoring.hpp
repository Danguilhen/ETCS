#ifndef CCC
#define CCC

#include "../define.hpp"
#include "../Tools.hpp"
#include "../Sound.hpp"
#include "../Reseau.hpp"

class TrackRelatedInputs;
class TrainRelatedInputs;
class Train_dynamique;

class Traction_Braking_system : public Tools //Ici sont calculées les décélérations
{
	private :
		std::vector<vector<double>> A_brake_emergency{{0, 40, 0.81}, {40, 80, 0.72}, {80, 100, 0.66}, {100, 155, 0.64}, {155, 180, 0.44}, {180, 250, 0.48}, {250, 320, 0.4}};
		std::vector<vector<double>> A_gradient;
		std::vector<vector<double>> A_brake_safe;
		//std::vector<vector<double>> A_safe;
		//std::vector<int> calculsegment; // détermine les segments dans lesqeulles la décélération sera équivalente
		TrackRelatedInputs *TrackRI;
		TrainRelatedInputs *TrainRI;

	public :
		Traction_Braking_system(TrainRelatedInputs &TrainRI, TrackRelatedInputs &TrackRI);
		void calculA_brake_safe();
		void calculA_gradient();
		void calcul_A_safe();
		void TBS_Update();
		std::vector<vector<double>> getA_brake_safe();
		std::vector<vector<double>> getA_gradient();
		//std::vector<vector<double>> getA_safe();

};


class MostRestrictiveSpeedLimit
{
	private :
		double V_MRSP;
		double distance;
		TrackRelatedInputs *TrackRI;
	public :
		MostRestrictiveSpeedLimit(TrackRelatedInputs &TrackRI);
		void function_MRSP();
		double getV_MRSP();
		double getDistance();
};

class DeterminationOfDecelerationCurves : public Tools
{
	private :
		vector<vector<double>> EBD; // [distance][vitesse][deceleration]
		TrackRelatedInputs *TrackRI;
		TrainRelatedInputs *TrainRI;
		Train_dynamique *T_D;
		Traction_Braking_system *TBS;

	public :
	DeterminationOfDecelerationCurves(TrackRelatedInputs &TrackRI, TrainRelatedInputs &TrainRI, Train_dynamique &T_D, Traction_Braking_system &TBS);
	void calculEBD();
	vector<vector<double>> getEBD();
	double getDistanceEBD(double speed);
	double getVitesseEBD(double distance);
	double getAccEBD(double distance);
	//double getV_start();
};

class SupervisionLimits : public Tools, public Son
{
	private :
		Train_dynamique *T_D;
		TrainRelatedInputs *TrainRI;
		TrackRelatedInputs *TrackRI;
		MostRestrictiveSpeedLimit *MRSP;
		DeterminationOfDecelerationCurves *DODC;
		vector<vector<double>> curvestab;// [vitesse][ebi][warning][permitted][indication]
		double V_ebi;
		double V_sbi;
		double V_warning;
		double V_permited;
		double V_indication;
		double d_ebi;
		double d_warning;
		double d_permitted;
		double d_indication;
		std::string status = "CSM"; // "TSM" "CSM" "RSM"
		double V_delta0 = 0; //en m/s
		double V_delta1 = 0; //en m/s
		double V_delta2 = 0; //en m/s
		double Aest1 = 0;
		double Aest2 = 0;
		double T_traction = 2; //valeur suivant le doc ERTMS3
		double T_be;
		double T_berem;
		double T_brake_emergency = 2; //arbitraire
		double T_indication = 9; //valeur suivant le doc ERTMS3
		double Vbec;
		double Dbec;
		double releaseSpeed = 30;
	public :
		SupervisionLimits(Train_dynamique &T_R, TrainRelatedInputs &TrainRI, TrackRelatedInputs &TrackRI, MostRestrictiveSpeedLimit &MRSP, DeterminationOfDecelerationCurves &DODC);
		void Curves();
		void Supervision_limits();
		void Changement_status();
		double getV_ebi();
		double getV_sbi();
		double getV_warning();
		double getV_permitted();
		double getV_indication();
		double getd_indication();
		double getd_permitted();
		double getd_ebi();
		double getd_warning();
		double getV_ebi_CSM(double vitesse);
		double getV_warning_CSM(double vitesse);
		std::string getStatus();
		double getReleaseSpeed();
};

class SpeedAndDistanceMonitoringCommands : public Son
{
	private :
		Train_dynamique *T_D;
		TrackRelatedInputs *TrackRI;
		MostRestrictiveSpeedLimit *MRSP;
		SupervisionLimits *SL;
		Software *soft;
		std::string supervision_status = "Normal";// au démarrage il est en condition normal
		std::string command_triggered;

	public :
		SpeedAndDistanceMonitoringCommands(Train_dynamique &T_D, MostRestrictiveSpeedLimit &MRSP, SupervisionLimits &SL, TrackRelatedInputs &TrackRI, Software &soft);
		void SpeedAndDistanceMonitoringCommands_update();
		std::string getSupervision_status();
		std::string getCommand_triggered();
};

class SpeedAndDistanceMonitoring
{
	private :
		Train_dynamique *T_D;
		TrainRelatedInputs *TrainRI;
		TrackRelatedInputs *TrackRI;
		Reseau *Res;
		Clock chronoSDM;//créer le chrono
		Time diftimeSDM;//créer la varaible qui stocke le temps écoulé
		double deltatsSDM = TMAJ;//créer la variable qui stocke le temps écoulé en seconde

	public :
		Traction_Braking_system TBS;
		MostRestrictiveSpeedLimit MRSP;
		DeterminationOfDecelerationCurves DODC;
		SupervisionLimits SL;
		SpeedAndDistanceMonitoringCommands SADMC;
		SpeedAndDistanceMonitoring(Train_dynamique &T_D, TrainRelatedInputs &TrainRI, TrackRelatedInputs &TrackRI, Software &soft, Reseau &Res);
		void SDM_Update_FS();
		void SDM_Update_SR();
};





#endif