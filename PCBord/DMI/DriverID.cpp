#include "DriverID.hpp"

DriverID_window::DriverID_window(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, string &ecran) : DataEntry(symbol, buttons, soft, bord, T_D, ecran)
{
	this->soft = &soft;
	this->bord = &bord;
	this->symbol = &symbol;
	this->buttons = &buttons;
	this->T_D = &T_D;
	this->ecran = &ecran;
}

void DriverID_window::update()
{
	//cout << (*buttons)[15].gettype() << endl;
	if((*buttons)[0].getactivation())
			tempID = tempID * 10 + 1;
	    else if((*buttons)[1].getactivation())
	        tempID = tempID  * 10 + 2;
	    else if((*buttons)[2].getactivation())
	        tempID = tempID * 10 + 3;
	    else if((*buttons)[3].getactivation())
	        tempID = tempID  * 10 + 4;
	    else if((*buttons)[4].getactivation())
	        tempID = tempID * 10 + 5 ;
	    else if((*buttons)[5].getactivation())
	        tempID = tempID * 10 + 6;
	    else if((*buttons)[6].getactivation())
	        tempID = tempID  * 10 + 7;
	    else if((*buttons)[7].getactivation())
	        tempID = tempID  * 10 + 8;
	    else if((*buttons)[8].getactivation())
	        tempID = tempID  * 10 + 9;
	    else if((*buttons)[9].getactivation())
	        tempID = tempID  * 10 + 0;
	    else if((*buttons)[10].getactivation())
	        tempID = static_cast<int>(ceil(tempID /10));
	    else if((*buttons)[15].getactivation())
	    {
	        bord->TrainRI.T_data.setDriverID(tempID);
	    }
		if(tempID == 0)
			dataEntry({{"", "", "0"}},  0, "Driver ID", {}, "alphanumeric");
		else
			dataEntry({{"", to_string(tempID), "0"}}, 0, "Driver ID", {}, "alphanumeric");

		if(bord->getGeneralMode() == "SB")
		{
			NA_12.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0));
			creation_texte("TRN", GREY, 16, 0, V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 +64 + 64 / 2.0), 1);
			SE_04.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 +64 + 64 + 64 / 2.0));
			if((*buttons)[13].getactivation())
				*ecran = "TrainRunningNumber";
			else if((*buttons)[14].getactivation())
				*ecran = "Settings";

		}
		else
		{
			close();
		}



}

