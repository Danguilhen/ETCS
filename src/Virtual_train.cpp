#include "TrackRelatedInputs.hpp"
#include "TrainRelatedInputs.hpp"
#include "SpeedAndDistanceMonitoring.hpp"
#include "ETCS_Bord_Main.hpp"
#include "DMI.hpp"
#include "Virtual_train.hpp"

void Virtual_train::update()
{
	etcs_bord.update();
}
