#ifndef CCC
#define CCC


class SpeedAndDistanceMonitoring
{
	public :
		int V_MRSP = 220;
		int V_ebi;
		int V_sbi;
		int V_warning;
		std::string staut = "CSM";

		void Supervision_limits(TrainRelatedInputs TrainRI);



};



#endif