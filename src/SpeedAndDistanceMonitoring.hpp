#ifndef CCC
#define CCC

class SpeedAndDistanceMonitoring
{
	private :
		int V_MRSP = 130;
		int V_ebi;
		int V_sbi;
		int V_warning;
		std::string status = "CSM";
		std::string supervision_status;
		std::string command_triggered;
	public :
		void MSRP(TrackRelatedInputs TrackRI, TrainRelatedInputs TrainRI);
		void Supervision_limits(TrainRelatedInputs TrainRI);
		void SpeedAndDistanceMonitoringCommands(TrainRelatedInputs TrainRI);

};



#endif