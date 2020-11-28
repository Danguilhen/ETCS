#include "StartUp.hpp"

StartUp::StartUp(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, string &ecran) : Driver_DMI(symbol, buttons, soft, bord, T_D, ecran), TRN_DMI(symbol, buttons, soft, bord, T_D, ecran), Set_DMI(symbol, buttons, soft, bord, T_D, ecran), level_DMI(symbol, buttons, soft, bord, T_D, ecran)
{
	this->ecran = &ecran;
	this->buttons = &buttons;
	this->bord = &bord;
}

void StartUp::update()
{
	if(status_STU == "S1")
	{
		if(*ecran == "Default")
			*ecran = "DriverID"; // si écran Default, alors on considère que c'est le premier lancement de update
		if(*ecran == "DriverID")
		{
			Driver_DMI.update();
			if((*buttons)[15].getactivation() && bord->TrainRI.T_data.getDriverID() != 0)
				status_STU = "S2";
		}
		if(*ecran == "TrainRunningNumber")
			TRN_DMI.update();
		if(*ecran == "Settings")
			Set_DMI.update();
	}
	else if(status_STU == "S2")
	{
		level_DMI.update();
		if((*buttons)[15].getactivation() && bord->TrainRI.T_data.getLevel() != "" && bord->TrainRI.T_data.getLevel() != "TVM")
		{
			bord->setGeneralMode("SR");
			*ecran = "Default";
		}
	    if((*buttons)[15].getactivation() && bord->TrainRI.T_data.getLevel() == "TVM")
		{
			bord->setGeneralMode("TVM");
			*ecran = "DefaultTVM";
		}
	}

}