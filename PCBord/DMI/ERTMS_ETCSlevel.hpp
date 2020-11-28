#ifndef ETLE
#define ETLE

#include "../define.hpp"
#include "DataEntry.hpp"
#include "../Bord/ETCS_Bord.hpp"

class ERTMS_ETCSlevel : public DataEntry
{
private:

	std::string tempLevel = "";

public:

	ERTMS_ETCSlevel(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, string &ecran);
	void update();
};


#endif