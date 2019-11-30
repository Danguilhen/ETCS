//#include <cstdlib>
//#include <iostream>
//#include <thread>
//#include <math.h>
//#include <string>
//#include <ctime>
//#include <vector>
//#include <unistd.h>
//#include <algorithm>
//#include <chrono>
//#include "TrackRelatedInputs.hpp"
//#include "TrainRelatedInputs.hpp"
//#include "SpeedAndDistanceMonitoring.hpp"
//#include "ETCS_Bord.hpp"
//#include "DMI.hpp"

#include "Data.hpp"
#include "Virtual_train.hpp"


int main()
{
	cout << "hello" << endl;
	Data data;
	Virtual_train virtual_train(data);
	while(!data.getEteindre())
	{
		data.update();
		if(data.getAllumage())
			virtual_train.update();
	}
	return 0;
}
