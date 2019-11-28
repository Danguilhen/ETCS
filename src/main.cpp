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
//#include "ETCS_Bord.hpp"
//#include "DMI.hpp"

#include "Virtual_train.hpp"
#include "Data.hpp"

int main()
{
	Virtual_train virtual_train;
	Data data;
	while(!data.getEteindre())
	{
		data.update();
		if(data.getAllumage())
			virtual_train.update();
	}
	return 0;
}
