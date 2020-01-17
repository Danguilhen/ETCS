#ifndef VI
#define VI

#include "Data.hpp"
#include "ETCS.hpp"
#include "DMI/BASIC.hpp"
#include "Train_dynamique.hpp"


class Virtual_train
{
	public :
		//Data data;
		Software soft;
		Train_dynamique train_dynamique;
		ETCS etcs;
		BASIC basic;
		//Train_Statique train_statique;
		Virtual_train();
		void update();
};

#endif