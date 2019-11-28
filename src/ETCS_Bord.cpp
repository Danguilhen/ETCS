//#include <cstdlib>
//#include <iostream>
//#include <thread>
//#include <math.h>
//#include <string>
//#include <ctime>
//#include <iostream>
//#include <vector>
//#include <unistd.h>
//#include <algorithm>
//#include <chrono>
//#include "TrackRelatedInputs.hpp"
//#include "TrainRelatedInputs.hpp"
//#include "SpeedAndDistanceMonitoring.hpp"

#include "ETCS_Bord.hpp"

void ETCS_Bord::update()
{
	//ATTENTION A L ORDRE LES RELATED INPUTS AVANT LE SDM

	TrackRI.TSR.TSR_Update();//trackspeedrestriction
	SDM.MSRP(TrackRI, TrainRI);
	SDM.Supervision_limits(TrainRI);
	SDM.SpeedAndDistanceMonitoringCommands(TrainRI);
}




