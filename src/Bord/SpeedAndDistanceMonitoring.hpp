#ifndef CCC
#define CCC


class TrackRelatedInputs;
class TrainRelatedInputs;
class Train_dynamique;

class SpeedAndDistanceMonitoring
{
	private :
		int V_MRSP = 130;
		int V_ebi;
		int V_sbi;
		int V_warning;
		Train_dynamique *T_D;
		std::string status = "CSM";
		std::string supervision_status = "Normal";// au démarrage il est en condition normal
		std::string command_triggered;
	public :
		SpeedAndDistanceMonitoring(Train_dynamique &T_D);
		void MSRP(TrackRelatedInputs TrackRI, TrainRelatedInputs TrainRI);
		void Supervision_limits(TrainRelatedInputs TrainRI);
		void SpeedAndDistanceMonitoringCommands();
		int getV_MRSP();
		int getV_ebi();
		int getV_sbi();
		int getV_warning();
		std::string getStatus();
		std::string getSupervision_status();
		std::string getCommand_triggered();
};



#endif