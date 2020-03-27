#include "Special.hpp"

Special::Special(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, string &ecran): Menu(symbol, soft, bord, T_D)
{
    //cout<< "DMI" <<endl;
	this->buttons = &buttons;
	this->bord = &bord;
    this->soft = &soft;
    this->T_D = &T_D;
    this->ecran = &ecran;
}

void Special::update()
{
    vector <string> selection(3);
    vector <int> enable(3);
    for (int i = 0; i <= 2; i++)
        enable[i] = 1;
    if ((T_D->getV_train() == 0 && bord->getGeneralMode() == "SB" && bord->getmodif_Adhesion() && bord->getDriverID() && bord->getTrainData() && bord->getETATLevelETCS())
        || (bord->getmodif_Adhesion() && (bord->getGeneralMode() == "FS" || bord->getGeneralMode() == "LS" || bord->getGeneralMode() == "SR" || bord->getGeneralMode() == "OS"||
        bord->getGeneralMode() == "UN" || bord->getGeneralMode() == "SN")))
    {
        enable[0] = 0;
        (*buttons)[0].settype("up_type");
    }
    else
        (*buttons)[0].settype("disabled");
    if(T_D->getV_train() == 0 && bord->getGeneralMode() == "SR")
    {
        enable[1] = 0;
        (*buttons)[1].settype("up_type");
    }
    else
        (*buttons)[1].settype("disabled");
    if (T_D->getV_train() == 0 && bord->getDriverID() && bord->getTrainData() && bord->getETATLevelETCS() && (bord->getGeneralMode() == "FS" || bord->getGeneralMode() == "LS" ||
		bord->getGeneralMode() == "SR" || bord->getGeneralMode() == "OS"|| bord->getGeneralMode() == "PT" || bord->getGeneralMode() == "SB"))
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
    close();
}