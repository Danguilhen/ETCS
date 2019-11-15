#ifndef ETCS
#define ETCS

class ETCS_Bord
{
	public :
	TrackRelatedInputs TrackRI;
	TrainRelatedInputs TrainRI;
	SpeedAndDistanceMonitoring SDM;

	void etcs_bord_update()
	{
		SDM.Supervision_limits(TrainRI);
	}
};


#endif