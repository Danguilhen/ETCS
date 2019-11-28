//#include "TrackRelatedInputs.hpp"
//#include "TrainRelatedInputs.hpp"
//#include "SpeedAndDistanceMonitoring.hpp"
//#include "ETCS_Bord.hpp"
//#include "DMI.hpp"

#include "Virtual_train.hpp"

Virtual_train::Virtual_train(Data &data)
{
	this->data = &data;
}

void Virtual_train::update()
{
	etcs_bord.update();
	dmi.update();
}
