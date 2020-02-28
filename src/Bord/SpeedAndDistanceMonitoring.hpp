#ifndef CCC
#define CCC

#include "../define.hpp"
#include "../Tools.hpp"

class TrackRelatedInputs;
class TrainRelatedInputs;
class Train_dynamique;

class Traction_Braking_system : public Tools //Ici sont calculées les décélérations
{
	private :
		std::vector<vector<float>> A_brake_emergency{{0, 40, 0.81}, {40, 80, 0.72}, {80, 100, 0.66}, {100, 155, 0.64}, {155, 180, 0.44}, {180, 250, 0.48}, {250, 320, 0.4}};
		std::vector<vector<float>> A_gradient;
		std::vector<vector<float>> A_brake_safe;
		//std::vector<vector<float>> A_safe;
		//std::vector<int> calculsegment; // détermine les segments dans lesqeulles la décélération sera équivalente
		TrackRelatedInputs *TrackRI;
		TrainRelatedInputs *TrainRI;

	public :
		Traction_Braking_system(TrainRelatedInputs &TrainRI, TrackRelatedInputs &TrackRI);
		void calculA_brake_safe();
		void calculA_gradient();
		void calcul_A_safe();
		void TBS_Update();
		std::vector<vector<float>> getA_brake_safe();
		std::vector<vector<float>> getA_gradient();
		//std::vector<vector<float>> getA_safe();

};


class MostRestrictiveSpeedLimit
{
	private :
		float V_MRSP;
		TrackRelatedInputs *TrackRI;
	public :
		MostRestrictiveSpeedLimit(TrackRelatedInputs &TrackRI);
		void function_MRSP();
		float getV_MRSP();
};

class DeterminationOfDecelerationCurves : public Tools
{
	private :
		vector<vector<float>> EBD; // [distance][vitesse][deceleration]
		TrackRelatedInputs *TrackRI;
		TrainRelatedInputs *TrainRI;
		Train_dynamique *T_D;
		Traction_Braking_system *TBS;

	public :
	DeterminationOfDecelerationCurves(TrackRelatedInputs &TrackRI, TrainRelatedInputs &TrainRI, Train_dynamique &T_D, Traction_Braking_system &TBS);
	void calculEBD();
	vector<vector<float>> getEBD();
	float getDistanceEBD(float speed);
	float getVitesseEBD(float distance);
	float getAccEBD(float distance);
	float getV_start();
};

class SupervisionLimits : public Tools
{
	private :
		Train_dynamique *T_D;
		TrainRelatedInputs *TrainRI;
		TrackRelatedInputs *TrackRI;
		MostRestrictiveSpeedLimit *MRSP;
		DeterminationOfDecelerationCurves *DODC;
		vector<vector<float>> curvestab;// [vitesse][ebi][warning][permitted][indication]
		float V_ebi;
		float V_sbi;
		float V_warning;
		float V_permited;
		float V_indication;
		float d_ebi;
		float d_warning;
		float d_permitted;
		float d_indication;
		std::string status = "CSM"; // "TSM" "CSM"
		float V_delta0 = 0; //en m/s
		float V_delta1 = 0; //en m/s
		float V_delta2 = 0; //en m/s
		float Aest1 = 0;
		float Aest2 = 0;
		float T_traction = 2; //valeur suivant le doc ERTMS3
		float T_be;
		float T_berem;
		float T_brake_emergency = 2; //arbitraire
		float T_indication = 9; //valeur suivant le doc ERTMS3
		float Vbec;
		float Dbec;
	public :
		SupervisionLimits(Train_dynamique &T_R, TrainRelatedInputs &TrainRI, TrackRelatedInputs &TrackRI, MostRestrictiveSpeedLimit &MRSP, DeterminationOfDecelerationCurves &DODC);
		void Curves();
		void Supervision_limits();
		float getV_ebi();
		float getV_sbi();
		float getV_warning();
		float getV_permitted();
		float getV_indication();
		float getd_indication();
		float getd_permitted();
		float getd_ebi();
		float getd_warning();
		float getV_ebi_CSM(float vitesse);
		float getV_warning_CSM(float vitesse);
		std::string getStatus();
};

class SpeedAndDistanceMonitoringCommands
{
	private :
		Train_dynamique *T_D;
		TrackRelatedInputs *TrackRI;
		MostRestrictiveSpeedLimit *MRSP;
		SupervisionLimits *SL;
		std::string supervision_status = "Normal";// au démarrage il est en condition normal
		std::string command_triggered;

	public :
		SpeedAndDistanceMonitoringCommands(Train_dynamique &T_D, MostRestrictiveSpeedLimit &MRSP, SupervisionLimits &SL, TrackRelatedInputs &TrackRI);
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
		Clock chronoSDM;//créer le chrono
		Time diftimeSDM;//créer la varaible qui stocke le temps écoulé
		float deltatsSDM = TMAJ;//créer la variable qui stocke le temps écoulé en seconde

	public :
		Traction_Braking_system TBS;
		MostRestrictiveSpeedLimit MRSP;
		DeterminationOfDecelerationCurves DODC;
		SupervisionLimits SL;
		SpeedAndDistanceMonitoringCommands SADMC;
		SpeedAndDistanceMonitoring(Train_dynamique &T_D, TrainRelatedInputs &TrainRI, TrackRelatedInputs &TrackRI);
		void SDM_Update();
};





#endif