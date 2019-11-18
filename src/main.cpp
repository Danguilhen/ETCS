#include <cstdlib>
#include <iostream>
#include <thread>
#include <math.h>
#include <string>
#include <ctime>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include <chrono>
#include "TrackRelatedInputs.hpp"
#include "TrainRelatedInputs.hpp"
#include "SpeedAndDistanceMonitoring.hpp"
#include "ETCS_Bord_Main.hpp"


int main()
{
	ETCS_Bord etcs;
	etcs.etcs_bord_update();
	return 0;
}
