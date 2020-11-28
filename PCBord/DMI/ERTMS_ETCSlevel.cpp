#include "ERTMS_ETCSlevel.hpp"

ERTMS_ETCSlevel::ERTMS_ETCSlevel(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, string &ecran) : DataEntry(symbol, buttons, soft, bord, T_D, ecran)
{
	this->soft = &soft;
	this->bord = &bord;
	this->symbol = &symbol;
	this->buttons = &buttons;
	this->T_D = &T_D;
	this->ecran = &ecran;
}

void ERTMS_ETCSlevel::update()
{
	dataEntry({{"", tempLevel, ""}}, 0, "Level", {bord->TrainRI.T_data.getlist_of_national_systems_available_on_board()}, "dedicated keyboard");

	for (size_t i = 0; i < bord->TrainRI.T_data.getlist_of_national_systems_available_on_board().size(); i++)
	{
		if((*buttons)[i].getactivation())
			tempLevel = bord->TrainRI.T_data.getlist_of_national_systems_available_on_board()[i];
	}


	/*else if((*buttons)[1].getactivation())
		bord->TrainRI.T_data.setLevel("Level 2");
	else if((*buttons)[2].getactivation())
		bord->TrainRI.T_data.setLevel("Level 3");
	else if((*buttons)[3].getactivation())
		bord->TrainRI.T_data.setLevel("Level 0");*/
	if((*buttons)[15].getactivation())
	{
	    bord->TrainRI.T_data.setLevel(tempLevel);
	}
	if(bord->getGeneralMode() == "SB")
	{
		NA_12.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0));
	}
	else
	{
		NA_11.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0));
		close();
	}

}