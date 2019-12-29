#include "Special.hpp"

Special::Special(RenderWindow &fenetre, Data &data, ETCS_Bord &bord, vector<Symbol> & symbol, vector<Button> & buttons, string & ecran, string & version): Menu(data, symbol, bord, fenetre)
{
	this->buttons = &buttons;
	this->bord = &bord;
	this->ecran = &ecran;
	this->version = &version;
}

void Special::update()
{
    vector <string> selection(3);
    vector <int> enable(3);
    for (int i = 0; i <= 2; i++)
        enable[i] = 1;
    if ((bord->TrainRI.T_data.getVtrain() == 0 && data->getGeneralMode() == "SB" && data->getmodif_Adhesion() && data->getDriverID() && data->getTrainData() && data->getETATLevelETCS())
        || (data->getmodif_Adhesion() && (data->getGeneralMode() == "FS" || data->getGeneralMode() == "LS" || data->getGeneralMode() == "SR" || data->getGeneralMode() == "OS"||
        data->getGeneralMode() == "UN" || data->getGeneralMode() == "SN")))
    {
        enable[0] = 0;
        (*buttons)[0].settype("up_type");
    }
    else
        (*buttons)[0].settype("disabled");
    if(bord->TrainRI.T_data.getVtrain() == 0 && data->getGeneralMode() == "SR")
    {
        enable[1] = 0;
        (*buttons)[1].settype("up_type");
    }
    else
        (*buttons)[1].settype("disabled");
    if (bord->TrainRI.T_data.getVtrain() == 0 && data->getDriverID() && data->getTrainData() && data->getETATLevelETCS() && (data->getGeneralMode() == "FS" || data->getGeneralMode() == "LS" ||
		data->getGeneralMode() == "SR" || data->getGeneralMode() == "OS"|| data->getGeneralMode() == "PT" || data->getGeneralMode() == "SB"))
    {
        enable[2] = 0;
        (*buttons)[2].settype("up_type");
    }
    else
        (*buttons)[2].settype("disabled");
    if ((*buttons)[2].getactivation())
        *ecran = "Default";
    else if ((*buttons)[1].getactivation())
        *ecran = "SRspeed/distance";
    else if ((*buttons)[0].getactivation())
    {
        *ecran = "adhesion";
		(*buttons)[10].settype("disabled");
		(*buttons)[12].settype("disabled");
		(*buttons)[13].settype("disabled");
		(*buttons)[14].settype("disabled");
    }
    selection = {"Adhesion", "SR speed / distance", "Train integrity"};
    menu(selection, enable, "Special");
    if((*buttons)[11].getactivation())
	{
        page = 1;
        *ecran = "Default";
	}
}