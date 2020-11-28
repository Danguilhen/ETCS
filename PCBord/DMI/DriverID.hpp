#ifndef DID
#define DID

#include "../define.hpp"
#include "DataEntry.hpp"
#include "../Bord/ETCS_Bord.hpp"

class DriverID_window : public DataEntry
{
	private :

	int tempID = bord->TrainRI.T_data.getDriverID();

	public :

	DriverID_window(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, string &ecran);
	void update();

};


#endif