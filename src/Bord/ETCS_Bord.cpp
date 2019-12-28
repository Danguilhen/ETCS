#include "ETCS_Bord.hpp"

void ETCS_Bord::update()
{
	//ATTENTION A L ORDRE LES RELATED INPUTS AVANT LE SDM

	TrackRI.TSR.TSR_Update();//trackspeedrestriction
	SDM.MSRP(TrackRI, TrainRI);
	SDM.Supervision_limits(TrainRI);
	SDM.SpeedAndDistanceMonitoringCommands(TrainRI);
}
