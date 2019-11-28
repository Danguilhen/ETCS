#ifndef ETCS_BORD
#define ETCS_BORD

#include "TrackRelatedInputs.hpp"
#include "TrainRelatedInputs.hpp"
#include "SpeedAndDistanceMonitoring.hpp"

class ETCS_Bord
{
	public :
		TrackRelatedInputs TrackRI;
		TrainRelatedInputs TrainRI;
		SpeedAndDistanceMonitoring SDM;

	void update();
};

#endif