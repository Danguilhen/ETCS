#include "Main2.hpp"

Main2::Main2(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, string &ecran): Menu(symbol, soft, bord, T_D)
{
	//cout<< "MAIN" <<endl;
	this->buttons = &buttons;
	this->bord = &bord;
	this->soft = &soft;
	this->T_D = &T_D;
	this->ecran = &ecran;
}

void Main2::update()
{
    vector <string> selection(9);
    vector <int> enable(10);
    for (int i = 0; i <= 9; i++)
        enable[i] = 1;
    enable[3] = 2;
	if((T_D->getV_train() == 0 && bord->getGeneralMode() == "SB" && bord->getDriverID() && bord->getTrainData() && bord->getETATLevelETCS() && bord->getTrainNumber()) ||
		((T_D->getV_train() == 0 && bord->getGeneralMode() == "PT" && bord->getTrainData()) && (bord->TrainRI.T_data.getLevel() == "Level 1" || ((bord->TrainRI.T_data.getLevel() == "Level 2" ||
		bord->TrainRI.T_data.getLevel() == "Level 3") && bord->getConnection() == "Up" && bord->getVersion() == "3.6.0" && bord->getPending_Emergency_Stop() == false))) || ((T_D->getV_train() == 0 &&
		bord->getGeneralMode() == "PT" && bord->getTrainData()) && (bord->TrainRI.T_data.getLevel() == "Level 1" || ((bord->TrainRI.T_data.getLevel() == "Level 2" || bord->TrainRI.T_data.getLevel() == "Level 3") &&
		bord->getVersion() == "3.4.0" && bord->getPending_Emergency_Stop() == false))) || (bord->getGeneralMode() == "SR" && (bord->TrainRI.T_data.getLevel() == "Level 2" || bord->TrainRI.T_data.getLevel() == "Level 3") &&
		bord->getConnection() == "Up" && bord->getVersion() == "3.6.0") || (bord->getGeneralMode() == "SR" && (bord->TrainRI.T_data.getLevel() == "Level 2" || bord->TrainRI.T_data.getLevel() == "Level 3") && bord->getVersion() == "3.4.0"))
	{
		enable[0] = 0;
		(*buttons)[0].settype("up_type");
	}
	else
		(*buttons)[0].settype("disabled");
	if((T_D->getV_train() == 0 && bord->getGeneralMode() == "SB" && bord->getDriverID() && bord->getETATLevelETCS()) || ((bord->getModif_DriverID_NTC() || (bord->getModif_DriverID_NTC() == false &&
		T_D->getV_train() == 0)) && (bord->getGeneralMode() == "SH" || bord->getGeneralMode() == "FS" || bord->getGeneralMode() == "LS" || bord->getGeneralMode() == "SR" ||
		bord->getGeneralMode() == "OS" || bord->getGeneralMode() == "NL" || bord->getGeneralMode() == "UN" || bord->getGeneralMode() == "SN")))
	{
		enable[1] = 0;
		(*buttons)[1].settype("up_type");
		if((*buttons)[1].getactivation() == 1)
		{
			*ecran = "driverID";
			for(int i = 0; i <= 10; i++)
				(*buttons)[i].settype("up_type");
			(*buttons)[11].settype("up_type");
			(*buttons)[12].settype("disabled");
			(*buttons)[13].settype("disabled");
			(*buttons)[14].settype("disabled");
			(*buttons)[15].settype("delay_type");
		}
	}
	else
		(*buttons)[1].settype("disabled");
	if(T_D->getV_train() == 0 && bord->getDriverID() && bord->getDriverID() && bord->getETATLevelETCS() && (bord->getGeneralMode() == "SB" || bord->getGeneralMode() == "FS" ||
		bord->getGeneralMode() == "LS" || bord->getGeneralMode() == "SR" || bord->getGeneralMode() == "OS" || bord->getGeneralMode() == "NL" || bord->getGeneralMode() == "UN" ||
		bord->getGeneralMode() == "SN" ))
	{
		enable[2] = 0;
		(*buttons)[2].settype("up_type");
		if((*buttons)[2].getactivation() == 1)
		{
			*ecran = "trainData";
			for(int i = 0; i <= 14; i++)
				(*buttons)[i].settype("up_type");
			(*buttons)[10].settype("disabled");
			(*buttons)[11].settype("up_type");
			(*buttons)[12].settype("up_type");
			(*buttons)[15].settype("delay_type");
		}
	}
	else
		(*buttons)[2].settype("disabled");
	if(T_D->getV_train() == 0 && bord->getDriverID() && (bord->getGeneralMode() == "SB" || bord->getGeneralMode() == "FS" || bord->getGeneralMode() == "LS" || bord->getGeneralMode() == "SR" ||
		bord->getGeneralMode() == "OS" || bord->getGeneralMode() == "NL" || bord->getGeneralMode() == "UN" || bord->getGeneralMode() == "SN" ))
	{
		enable[4] = 0;
		(*buttons)[4].settype("up_type");
		if((*buttons)[4].getactivation() == 1)
		{
			*ecran = "ERTMS_ETCSlevel";
			for(int i = 0; i <= 14; i++)
				(*buttons)[i].settype("up_type");
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
	if((T_D->getV_train() == 0 && bord->getGeneralMode() == "SB" && bord->getDriverID() && bord->getETATLevelETCS()) || ((bord->getGeneralMode() == "SB" || bord->getGeneralMode() == "FS" ||
		bord->getGeneralMode() == "LS" || bord->getGeneralMode() == "SR" || bord->getGeneralMode() == "OS" || bord->getGeneralMode() == "NL"|| bord->getGeneralMode() == "UN" ||
		bord->getGeneralMode() == "SN" )))
	{
		enable[5] = 0;
		(*buttons)[5].settype("up_type");
		if((*buttons)[5].getactivation() == 1)
		{
			*ecran = "trainRunningNumber";
			for(int i = 0; i <= 14; i++)
				(*buttons)[i].settype("up_type");
			(*buttons)[10].settype("up_type");
			(*buttons)[11].settype("up_type");
			(*buttons)[12].settype("disabled");
			(*buttons)[13].settype("disabled");
			(*buttons)[14].settype("disabled");
			(*buttons)[15].settype("delay_type");
		}
	}
	else
		(*buttons)[5].settype("disabled");
	if((T_D->getV_train() == 0 && bord->getDriverID() && (bord->getGeneralMode() == "SB" || bord->getGeneralMode() == "FS" || bord->getGeneralMode() == "LS" || bord->getGeneralMode() == "SR" ||
		bord->getGeneralMode() == "OS" || bord->getGeneralMode() == "UN" || bord->getGeneralMode() == "SN" ) && bord->getETATLevelETCS() && ((bord->TrainRI.T_data.getLevel() == "Level 0" ||
		bord->TrainRI.T_data.getLevel() == "Level 1" || bord->TrainRI.T_data.getLevel().substr(0,2) == "NTC") || ((bord->TrainRI.T_data.getLevel() == "Level 2" || bord->TrainRI.T_data.getLevel() == "Level 3") &&
		bord->getConnection() == "Up"))) || (T_D->getV_train() == 0 && bord->getGeneralMode() == "PT" && (bord->TrainRI.T_data.getLevel() == "Level 1" || ((bord->TrainRI.T_data.getLevel() == "Level 2" ||
		bord->TrainRI.T_data.getLevel() == "Level 3") && bord->getConnection() == "Up" && bord->getPending_Emergency_Stop() == false))))
	{
		enable[6] = 0; //shunting  x
		(*buttons)[6].settype("up_type");
	}
	else if(T_D->getV_train() == 0 && bord->getGeneralMode() == "SH")
	{
		enable[6] = 0;//Exit Shunting
		(*buttons)[6].settype("up_type");
	}
	else
		(*buttons)[6].settype("disabled");
	if(T_D->getV_train() == 0 && bord->getDriverID() && bord->getETATLevelETCS() && (bord->getGeneralMode() == "SB" || bord->getGeneralMode() == "FS" || bord->getGeneralMode() == "LS" ||
		bord->getGeneralMode() == "SR" || bord->getGeneralMode() == "OS" || bord->getGeneralMode() == "SH") && bord->getNon_Leading() == false)
	{
		enable[7] = 0;
		(*buttons)[7].settype("up_type");
	}
	else
		(*buttons)[7].settype("disabled");
	if(bord->getGeneralMode() == "SH" && bord->getPassive_Shunting())
	{
		enable[8] = 0;
		(*buttons)[8].settype("up_type");
	}
	else
		(*buttons)[8].settype("disabled");
	if (bord->getVersion() == "3.6.0")
	{
		if (T_D->getV_train() == 0 && bord->getDriverID() && bord->getETATLevelETCS() && (bord->getGeneralMode() == "SB" || bord->getGeneralMode() == "FS" ||
			bord->getGeneralMode() == "LS" || bord->getGeneralMode() == "SR" || bord->getGeneralMode() == "OS" || bord->getGeneralMode() == "NL"||
			bord->getGeneralMode() == "UN" || bord->getGeneralMode() == "SN" || bord->getGeneralMode() == "PT"))
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
	selection = {"Start", "Driver ID", "Train bord", "", "Level", "Train running number", "Shunting", "Non-Leading", "Maintain Shunting"};
	if(bord->getVersion() == "3.6.0")
		selection.push_back("Radio bord");
    menu(selection, enable, "Main");
	close();
}