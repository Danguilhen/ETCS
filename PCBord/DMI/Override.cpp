#include "Override.hpp"

Override::Override(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, string &ecran): Menu(symbol, soft, bord, T_D)
{
    //cout<< "OVER" <<endl;
	this->buttons = &buttons;
	this->bord = &bord;
    this->soft = &soft;
    this->T_D = &T_D;
    this->ecran = &ecran;
}

void Override::update()
{
    vector <string> selection(1);
    vector <int> enable(1);
    enable[0] = 1;
    if ((T_D->getV_train() <=  bord->getVrelease() && (bord->getGeneralMode() == "FS" || bord->getGeneralMode() == "LS" || bord->getGeneralMode() == "SR" || bord->getGeneralMode() == "OS"||
        bord->getGeneralMode() == "UN" || bord->getGeneralMode() == "SN" || bord->getGeneralMode() == "SH"))
        || (T_D->getV_train() <=  bord->getVrelease() && bord->getGeneralMode() == "SB" && bord->getDriverID() && bord->getTrainData() && bord->getETATLevelETCS() &&
		(bord->TrainRI.T_data.getLevel() == "Level 2" || bord->TrainRI.T_data.getLevel() == "Level 3")) || (bord->getVersion() =="3.6.0" && (T_D->getV_train() <=  bord->getVrelease() && bord->getGeneralMode() == "PT" &&
		bord->getTrainData() && bord->getTrainNumber())))
    {
        (*buttons)[0].settype("up_type");
        if( bord->getVersion() == "3.4.0" || (bord->getVersion() == "3.6.0" && bord->getTrainNumber()))
            enable[0] = 0;
    }
    else
        (*buttons)[0].settype("disabled");
    if ((*buttons)[0].getactivation())
    {
        if (bord->getGeneralMode()=="TVM")
			*ecran = "DefaultTVM";
		else
			*ecran = "Default";
        if(bord->getEOA())
            bord->setEOA(false);
        else
            bord->setEOA(true);
    }
    selection = {"EOA"};
    menu(selection, enable, "Override");
    close();
}