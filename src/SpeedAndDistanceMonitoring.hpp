#ifndef CCC
#define CCC


class SpeedAndDistanceMonitoring
{
	private :
		int V_MRSP = 130;
		int V_ebi;
		int V_sbi;
		int V_warning;
		std::string staut = "CSM";
	public :
		void MSRP(TrackRelatedInputs TrackRI, TrainRelatedInputs TrainRI);
		void Supervision_limits(TrainRelatedInputs TrainRI);



};



#endif