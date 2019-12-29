#include "Override.hpp"

Override::Override(RenderWindow &fenetre, Data &data, ETCS_Bord &bord, vector<Symbol> & symbol, vector<Button> & buttons, string & ecran, string & version): Menu(data, symbol, bord, fenetre)
{
	this->buttons = &buttons;
	this->bord = &bord;
	this->ecran = &ecran;
	this->version = &version;
}

void Override::update()
{
    vector <string> selection(1);
    vector <int> enable(1);
    enable[0] = 1;
    if ((bord->TrainRI.T_data.getVtrain() <=  data->getVrelease() && (data->getGeneralMode() == "FS" || data->getGeneralMode() == "LS" || data->getGeneralMode() == "SR" || data->getGeneralMode() == "OS"||
        data->getGeneralMode() == "UN" || data->getGeneralMode() == "SN" || data->getGeneralMode() == "SH"))
        || (bord->TrainRI.T_data.getVtrain() <=  data->getVrelease() && data->getGeneralMode() == "SB" && data->getDriverID() && data->getTrainData() && data->getETATLevelETCS() &&
		(data->getLevel() == "Level 2" || data->getLevel() == "Level 3")) || (*version =="3.6.0" && (bord->TrainRI.T_data.getVtrain() <=  data->getVrelease() && data->getGeneralMode() == "PT" &&
		data->getTrainData() && data->getTrainNumber())))
    {
        (*buttons)[0].settype("up_type");
        if(*version == "3.4.0" || (*version == "3.6.0" && data->getTrainNumber()))
            enable[0] = 0;
    }
    else
        (*buttons)[0].settype("disabled");
    if ((*buttons)[0].getactivation())
    {
        *ecran = "Default";
        if(data->getEOA())
            data->setEOA(false);
        else
            data->setEOA(true);
    }
    selection = {"EOA"};
    menu(selection, enable, "Override");
	if((*buttons)[11].getactivation())
	{
        page = 1;
        *ecran = "Default";
	}
}