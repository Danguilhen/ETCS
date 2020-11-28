#ifndef TRNW
#define TRNW

#include "../define.hpp"
#include "DataEntry.hpp"
#include "../Bord/ETCS_Bord.hpp"

class TrainRunningNumberWindow : public DataEntry
{
private:
	int tempTRN = bord->TrainRI.T_data.getTrainRunningNumber();
public:
	TrainRunningNumberWindow(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, string &ecran);
	void update();
};


#endif