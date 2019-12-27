#ifndef VI
#define VI

#include "Bord/ETCS_Bord.hpp"
#include "DMI/DMI.hpp"
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