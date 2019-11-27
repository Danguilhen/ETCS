#ifndef ETCS
#define ETCS

class ETCS_Bord
{
	public :
		TrackRelatedInputs TrackRI;
		TrainRelatedInputs TrainRI;
		SpeedAndDistanceMonitoring SDM;

	void update();
};


#endif