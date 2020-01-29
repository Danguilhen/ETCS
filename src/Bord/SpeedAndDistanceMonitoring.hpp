#ifndef CCC
#define CCC

#include "define.hpp"
#include "Tools.hpp"

class TrackRelatedInputs;
class TrainRelatedInputs;
class Train_dynamique;

class Traction_Braking_system : public Tools
{
	private :
		std::vector<vector<float>> A_brake_emergency{{0, 4668.21, 0.9}, {4668.21, 5733.03, 0.75}};
		std::vector<vector<float>> A_gradient;
		std::vector<vector<float>> A_safe;
		TrackRelatedInputs *TrackRI;
		TrainRelatedInputs *TrainRI;
	public :
		Traction_Braking_system(TrainRelatedInputs &TrainRI, TrackRelatedInputs &TrackRI);
		void TBS_Update();
};

class SpeedAndDistanceMonitoring
{
	private :
		Train_dynamique *T_D;
		TrainRelatedInputs *TrainRI;
		TrackRelatedInputs *TrackRI;
		Traction_Braking_system TBS;
		float V_MRSP = 130;
		float V_ebi;
		float V_sbi;
		float V_warning;
		int target_distance = 0;
		std::string status = "CSM";
		std::string supervision_status = "Normal";// au démarrage il est en condition normal
		std::string command_triggered;

	public :
		SpeedAndDistanceMonitoring(Train_dynamique &T_D, TrainRelatedInputs &TrainRI, TrackRelatedInputs &TrackRI);
		void SDM_Update();
		void MSRP();
		void Supervision_limits();
		void SpeedAndDistanceMonitoringCommands();
		float getV_MRSP();
		float getV_ebi();
		float getV_sbi();
		float getV_warning();
		std::string getStatus();
		std::string getSupervision_status();
		std::string getCommand_triggered();
};






#endif