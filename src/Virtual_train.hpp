#ifndef VT
#define VI

#include "ETCS_Bord.hpp"
#include "DMI.hpp"
#include "Data.hpp"

class Virtual_train
{
	private :
		ETCS_Bord etcs_bord;
		Data *data;
		DMI dmi;
		//Train_Dynamique train_dynamique;
		//Train_Statique train_statique;

	public :
		Virtual_train(Data &data);
		void update();
};

#endif