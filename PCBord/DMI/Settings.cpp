#include "Settings.hpp"

Settings::Settings(std::vector<Symbol> &symbol, std::vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, std::string &ecran) : Menu(symbol, soft, bord, T_D)
{
	this->buttons = &buttons;
	this->bord = &bord;
	this->soft = &soft;
	this->T_D = &T_D;
	this->ecran = &ecran;
}

void Settings::update()
{
	left.update();
	vector <string> selection(6);
    vector <int> enable(6);
    for (int i = 0; i <= 5; i++)
        enable[i] = 1;
    if ((T_D->getV_train() == 0 && bord->getGeneralMode() == "SB")
        ||(bord->getGeneralMode() == "SH" || bord->getGeneralMode() == "FS" || bord->getGeneralMode() == "LS" || bord->getGeneralMode() == "SR" ||bord->getGeneralMode() == "OS" ||
        bord->getGeneralMode() == "NL" || bord->getGeneralMode() == "UN" || bord->getGeneralMode() == "TR" || bord->getGeneralMode() == "PT" || bord->getGeneralMode() == "SN" ||
        bord->getGeneralMode() == "RV"|| bord->getGeneralMode() == "TVM"))
    {
        for (int i = 0; i <= 3; i++)
        {
            enable[i] = 0;
            (*buttons)[i].settype("up_type");
        }
		/*
        if((*buttons)[0].getactivation() == 1)
            *ecran = "Language";
        else if((*buttons)[1].getactivation() == 1)
            *ecran = "Volume";
        else if((*buttons)[2].getactivation() == 1)
            *ecran = "Brightness";
        else if((*buttons)[3].getactivation() == 1)
            *ecran = "SystemVersion";
			*/
    }
    else
    {
        for (int i = 0; i <= 3; i++)
            (*buttons)[i].settype("delayed");
    }
    if(T_D->getV_train() == 0 && bord->getGeneralMode() == "SB" /*&& vbc.size() < 20*/)
    {
        enable[4] = 0;
        (*buttons)[4].settype("up_type");
    }
    else
        (*buttons)[4].settype("delayed");
    if(T_D->getV_train() == 0 && bord->getGeneralMode() == "SB" /*&& vbc.size() > 0*/)
    {
        enable[5] = 0;
        (*buttons)[5].settype("up_type");
    }
    else
        (*buttons)[5].settype("delayed");
    selection = {"Language", "Volume", "Brightness", "System version", "Set VBC", "Remote VBC"};
    menu(selection, enable, "Settings");
    if((*buttons)[11].getactivation())
	{
		if(bord->getGeneralMode() == "SB")
		{
			*ecran = "DriverID";
		}
		else
        {
			page = 1;
        	close();
		}
	}
}