#ifndef ETCS
#define ETCS

class ETCS_Bord
{
	private :
		TrackRelatedInputs TrackRI;
		TrainRelatedInputs TrainRI;
		SpeedAndDistanceMonitoring SDM;

	public :
	void update();
};


#endif