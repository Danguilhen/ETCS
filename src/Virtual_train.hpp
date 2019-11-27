#ifndef VT
#define VI

class Virtual_train
{
	private :
	ETCS_Bord etcs_bord;
	DMI dmi{etcs_bord};
	//Train_Dynamique train_dynamique;
	//Train_Statique train_statique;

	public :
	void update();
};

#endif