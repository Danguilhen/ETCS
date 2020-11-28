#include "TrainRunningNumberWindow.hpp"

TrainRunningNumberWindow::TrainRunningNumberWindow(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, string &ecran) : DataEntry(symbol, buttons, soft, bord, T_D, ecran)
{
	this->soft = &soft;
	this->bord = &bord;
	this->symbol = &symbol;
	this->buttons = &buttons;
	this->T_D = &T_D;
	this->ecran = &ecran;
}

void TrainRunningNumberWindow::update()
{
	if((*buttons)[0].getactivation())
		tempTRN = tempTRN * 10 + 1;
	else if((*buttons)[1].getactivation())
	    tempTRN = tempTRN  * 10 + 2;
	else if((*buttons)[2].getactivation())
	    tempTRN = tempTRN * 10 + 3;
	else if((*buttons)[3].getactivation())
	    tempTRN = tempTRN  * 10 + 4;
	else if((*buttons)[4].getactivation())
	    tempTRN = tempTRN * 10 + 5 ;
	else if((*buttons)[5].getactivation())
	    tempTRN = tempTRN * 10 + 6;
	else if((*buttons)[6].getactivation())
	    tempTRN = tempTRN  * 10 + 7;
	else if((*buttons)[7].getactivation())
	    tempTRN = tempTRN  * 10 + 8;
	else if((*buttons)[8].getactivation())
	    tempTRN = tempTRN  * 10 + 9;
	else if((*buttons)[9].getactivation())
	    tempTRN = tempTRN  * 10 + 0;
	else if((*buttons)[10].getactivation())
	    tempTRN = static_cast<int>(ceil(tempTRN /10));
	else if((*buttons)[15].getactivation())
	{
	    bord->TrainRI.T_data.setTrainRunningNumber(tempTRN);
	}
	if(tempTRN == 0)
		dataEntry({{"", "", "0"}}, 0, "Train running number", {}, "numeric");
	else
		dataEntry({{"", to_string(tempTRN), "0"}}, 0, "Train running number", {}, "numeric");
	if(bord->getGeneralMode() == "SB")
	{
		NA_12.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0));
		if ((*buttons)[15].getactivation() && bord->TrainRI.T_data.getTrainRunningNumber() != 0)
			*ecran = "DriverID";
	}
	else
	{
		if((*buttons)[11].getactivation())
	    	tempTRN = bord->TrainRI.T_data.getTrainRunningNumber();
		close();
	}
}

