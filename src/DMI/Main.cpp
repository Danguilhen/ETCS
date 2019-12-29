#include "Main.hpp"

Main::Main(RenderWindow &fenetre, Data &data, ETCS_Bord &bord, vector<Symbol> & symbol, vector<Button> & buttons, string & ecran, string & version): Menu(data, symbol, bord, fenetre)
{
	this->buttons = &buttons;
	this->bord = &bord;
	this->ecran = &ecran;
	this->version = &version;
}

void Main::update()
{
    vector <string> selection(9);
    vector <int> enable(9);
    for (int i = 0; i <= 9; i++)
        enable[i] = 1;
    enable[3] = 2;
	if((bord->TrainRI.T_data.getVtrain() == 0 && data->getGeneralMode() == "SB" && data->getDriverID() && data->getTrainData() && data->getETATLevelETCS() && data->getTrainNumber()) ||
		((bord->TrainRI.T_data.getVtrain() == 0 && data->getGeneralMode() == "PT" && data->getTrainData()) && (data->getLevel() == "Level 1" || ((data->getLevel() == "Level 2" ||
		data->getLevel() == "Level 3") && data->getConnection() == "Up" && *version == "3.6.0" && data->getPending_Emergency_Stop() == false))) || ((bord->TrainRI.T_data.getVtrain() == 0 &&
		data->getGeneralMode() == "PT" && data->getTrainData()) && (data->getLevel() == "Level 1" || ((data->getLevel() == "Level 2" || data->getLevel() == "Level 3") &&
		*version == "3.4.0" && data->getPending_Emergency_Stop() == false))) || (data->getGeneralMode() == "SR" && (data->getLevel() == "Level 2" || data->getLevel() == "Level 3") &&
		data->getConnection() == "Up" && *version == "3.6.0") || (data->getGeneralMode() == "SR" && (data->getLevel() == "Level 2" || data->getLevel() == "Level 3") && *version == "3.4.0"))
	{
		enable[0] = 0;
		(*buttons)[0].settype("up_type");
	}
	else
		(*buttons)[0].settype("disabled");
	if((bord->TrainRI.T_data.getVtrain() == 0 && data->getGeneralMode() == "SB" && data->getDriverID() && data->getETATLevelETCS()) || ((data->getModif_DriverID_NTC() || (data->getModif_DriverID_NTC() == false &&
		bord->TrainRI.T_data.getVtrain() == 0)) && (data->getGeneralMode() == "SH" || data->getGeneralMode() == "FS" || data->getGeneralMode() == "LS" || data->getGeneralMode() == "SR" ||
		data->getGeneralMode() == "OS" || data->getGeneralMode() == "NL" || data->getGeneralMode() == "UN" || data->getGeneralMode() == "SN")))
	{
		enable[1] = 0;
		(*buttons)[1].settype("up_type");
		if((*buttons)[1].getactivation() == 1)
		{
			*ecran = "driverID";
			for(int i = 0; i <= 10; i++)
				(*buttons)[i].settype("down_type");
			(*buttons)[11].settype("up_type");
			(*buttons)[12].settype("disabled");
			(*buttons)[13].settype("disabled");
			(*buttons)[14].settype("disabled");
			(*buttons)[15].settype("delay_type");
		}
	}
	else
		(*buttons)[1].settype("disabled");
	if(bord->TrainRI.T_data.getVtrain() == 0 && data->getDriverID() && data->getDriverID() && data->getETATLevelETCS() && (data->getGeneralMode() == "SB" || data->getGeneralMode() == "FS" ||
		data->getGeneralMode() == "LS" || data->getGeneralMode() == "SR" || data->getGeneralMode() == "OS" || data->getGeneralMode() == "NL" || data->getGeneralMode() == "UN" ||
		data->getGeneralMode() == "SN" ))
	{
		enable[2] = 0;
		(*buttons)[2].settype("up_type");
		if((*buttons)[2].getactivation() == 1)
		{
			*ecran = "trainData";
			for(int i = 0; i <= 14; i++)
				(*buttons)[i].settype("down_type");
			(*buttons)[10].settype("disabled");
			(*buttons)[11].settype("up_type");
			(*buttons)[12].settype("up_type");
			(*buttons)[15].settype("delay_type");
		}
	}
	else
		(*buttons)[2].settype("disabled");
	if(bord->TrainRI.T_data.getVtrain() == 0 && data->getDriverID() && (data->getGeneralMode() == "SB" || data->getGeneralMode() == "FS" || data->getGeneralMode() == "LS" || data->getGeneralMode() == "SR" ||
		data->getGeneralMode() == "OS" || data->getGeneralMode() == "NL" || data->getGeneralMode() == "UN" || data->getGeneralMode() == "SN" ))
	{
		enable[4] = 0;
		(*buttons)[4].settype("up_type");
		if((*buttons)[4].getactivation() == 1)
		{
			*ecran = "ERTMS_ETCSlevel";
			for(int i = 0; i <= 14; i++)
				(*buttons)[i].settype("down_type");
			(*buttons)[10].settype("disabled");
			(*buttons)[11].settype("up_type");
			(*buttons)[12].settype("disabled");
			(*buttons)[13].settype("disabled");
			(*buttons)[14].settype("disabled");
			(*buttons)[15].settype("delay_type");
		}
	}
	else
		(*buttons)[4].settype("disabled");
	if((bord->TrainRI.T_data.getVtrain() == 0 && data->getGeneralMode() == "SB" && data->getDriverID() && data->getETATLevelETCS()) || ((data->getGeneralMode() == "SB" || data->getGeneralMode() == "FS" ||
		data->getGeneralMode() == "LS" || data->getGeneralMode() == "SR" || data->getGeneralMode() == "OS" || data->getGeneralMode() == "NL"|| data->getGeneralMode() == "UN" ||
		data->getGeneralMode() == "SN" )))
	{
		enable[5] = 0;
		(*buttons)[5].settype("up_type");
		if((*buttons)[5].getactivation() == 1)
		{
			*ecran = "trainRunningNumber";
			for(int i = 0; i <= 14; i++)
				(*buttons)[i].settype("down_type");
			(*buttons)[10].settype("down_type");
			(*buttons)[11].settype("up_type");
			(*buttons)[12].settype("disabled");
			(*buttons)[13].settype("disabled");
			(*buttons)[14].settype("disabled");
			(*buttons)[15].settype("delay_type");
		}
	}
	else
		(*buttons)[5].settype("disabled");
	if((bord->TrainRI.T_data.getVtrain() == 0 && data->getDriverID() && (data->getGeneralMode() == "SB" || data->getGeneralMode() == "FS" || data->getGeneralMode() == "LS" || data->getGeneralMode() == "SR" ||
		data->getGeneralMode() == "OS" || data->getGeneralMode() == "UN" || data->getGeneralMode() == "SN" ) && data->getETATLevelETCS() && ((data->getLevel() == "Level 0" ||
		data->getLevel() == "Level 1" || data->getLevel().substr(0,2) == "NTC") || ((data->getLevel() == "Level 2" || data->getLevel() == "Level 3") &&
		data->getConnection() == "Up"))) || (bord->TrainRI.T_data.getVtrain() == 0 && data->getGeneralMode() == "PT" && (data->getLevel() == "Level 1" || ((data->getLevel() == "Level 2" ||
		data->getLevel() == "Level 3") && data->getConnection() == "Up" && data->getPending_Emergency_Stop() == false))))
	{
		enable[6] = 0; //shunting  x
		(*buttons)[6].settype("up_type");
	}
	else if(bord->TrainRI.T_data.getVtrain() == 0 && data->getGeneralMode() == "SH")
	{
		enable[6] = 0;//Exit Shunting
		(*buttons)[6].settype("up_type");
	}
	else
		(*buttons)[6].settype("disabled");
	if(bord->TrainRI.T_data.getVtrain() == 0 && data->getDriverID() && data->getETATLevelETCS() && (data->getGeneralMode() == "SB" || data->getGeneralMode() == "FS" || data->getGeneralMode() == "LS" ||
		data->getGeneralMode() == "SR" || data->getGeneralMode() == "OS" || data->getGeneralMode() == "SH") && data->getNon_Leading() == false)
	{
		enable[7] = 0;
		(*buttons)[7].settype("up_type");
	}
	else
		(*buttons)[7].settype("disabled");
	if(data->getGeneralMode() == "SH" && data->getPassive_Shunting())
	{
		enable[8] = 0;
		(*buttons)[8].settype("up_type");
	}
	else
		(*buttons)[8].settype("disabled");
	if (*version == "3.6.0")
	{
		if (bord->TrainRI.T_data.getVtrain() == 0 && data->getDriverID() && data->getETATLevelETCS() && (data->getGeneralMode() == "SB" || data->getGeneralMode() == "FS" ||
			data->getGeneralMode() == "LS" || data->getGeneralMode() == "SR" || data->getGeneralMode() == "OS" || data->getGeneralMode() == "NL"||
			data->getGeneralMode() == "UN" || data->getGeneralMode() == "SN" || data->getGeneralMode() == "PT"))
		{
			enable[9] = 0;
			(*buttons)[9].settype("up_type");
		}
		else
			(*buttons)[9].settype("disabled");
	}
	else
	{
		enable[9] = 2;
		(*buttons)[9].settype("disabled");
	}
	selection = {"Start", "Driver ID", "Train data", "", "Level", "Train running number", "Shunting", "Non-Leading", "Maintain Shunting"};
	if(*version == "3.6.0")
		selection.push_back("Radio data");
    menu(selection, enable, "Main");
	if((*buttons)[11].getactivation())
	{
    	page = 1;
    	*ecran = "Default";
	}
}