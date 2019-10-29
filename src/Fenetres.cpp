#include <thread>
#include <math.h>
#include <string>
#include <ctime>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>

void MainWindow(vector<Symbol> & symbol, string version, vector<Buttons> & boutons, string & ecran, int & numero);
void specialWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void settingsWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<VBC> & vbc, vector<Buttons> & boutons, string & ecran, int & numero);
void SRspeedWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void dataViewWindows(vector<Symbol> & symbol, Font & arial, string title, int & numero, vector<Buttons> & boutons, string & ecran, vector<vector<string>> item);
void RBCdataWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void dataViewWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void systemVersionWindow(vector<Symbol> & symbol, Font & arial, vector<Buttons> & boutons, string & ecran, int & numero);

void overrideWindow(vector<Symbol> & symbol, Font & arial, string version, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void adhesionWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void RBCcontactWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void ERTMS_ETCSlevelWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void trainRunningNumberWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void radionetworkIDWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void trainDataWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void brightnessWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void volumeWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void languageWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void windows(string & ecran, vector<Symbol> & symbol, Font & arial, string version, donnees &train, vector<VBC> vbc, vector<Buttons> & boutons, int & numero);
void close(string & ecran, vector<Buttons> & boutons, int & numero);
void driverIDWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);



void MainWindow(vector<Symbol> & symbol, Font & arial, string version, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
    vector <string> selection(9);
    vector <int> enable(9);
    for (int i = 0; i <= 9; i++)
        enable[i] = 1;
    enable[3] = 2;
	if((train.getVtrain() == 0 && train.getGeneralMode() == "SB" && train.getDriverID() && train.getTrainData() && train.getETATLevelETCS() && train.getTrainNumber()) ||
		((train.getVtrain() == 0 && train.getGeneralMode() == "PT" && train.getTrainData()) && (train.getLevel() == "Level 1" || ((train.getLevel() == "Level 2" ||
		train.getLevel() == "Level 3") && train.getConnection() == "Up" && version == "3.6.0" && train.getPending_Emergency_Stop() == false))) || ((train.getVtrain() == 0 &&
		train.getGeneralMode() == "PT" && train.getTrainData()) && (train.getLevel() == "Level 1" || ((train.getLevel() == "Level 2" || train.getLevel() == "Level 3") &&
		version == "3.4.0" && train.getPending_Emergency_Stop() == false))) || (train.getGeneralMode() == "SR" && (train.getLevel() == "Level 2" || train.getLevel() == "Level 3") &&
		train.getConnection() == "Up" && version == "3.6.0") || (train.getGeneralMode() == "SR" && (train.getLevel() == "Level 2" || train.getLevel() == "Level 3") && version == "3.4.0"))
	{
		enable[0] = 0;
		boutons[0].settype("up_type");
	}
	else
		boutons[0].settype("disabled");
	if((train.getVtrain() == 0 && train.getGeneralMode() == "SB" && train.getDriverID() && train.getETATLevelETCS()) ||((train.getModif_DriverID_NTC() ||(train.getModif_DriverID_NTC() == false &&
		train.getVtrain() == 0)) && (train.getGeneralMode() == "SH" || train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" ||
		train.getGeneralMode() == "OS" || train.getGeneralMode() == "NL" || train.getGeneralMode() == "UN" || train.getGeneralMode() == "SN" )))
	{
		enable[1] = 0;
		boutons[1].settype("up_type");
		if(boutons[1].getactivation() == 1)
		{
			ecran = "driverIDWindow";
			for(int i = 0; i <= 10; i++)
				boutons[i].settype("down_type");
			boutons[11].settype("up_type");
			boutons[12].settype("disabled");
			boutons[13].settype("disabled");
			boutons[14].settype("disabled");
			boutons[15].settype("delay_type");
		}
	}
	else
		boutons[1].settype("disabled");
	if(train.getVtrain() == 0 && train.getDriverID() && train.getDriverID() && train.getETATLevelETCS() && (train.getGeneralMode() == "SB" || train.getGeneralMode() == "FS" ||
		train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" || train.getGeneralMode() == "OS" || train.getGeneralMode() == "NL" || train.getGeneralMode() == "UN" ||
		train.getGeneralMode() == "SN" ))
	{
		enable[2] = 0;
		boutons[2].settype("up_type");
		if(boutons[2].getactivation() == 1)
		{
			ecran = "trainDataWindow";
			for(int i = 0; i <= 14; i++)
				boutons[i].settype("down_type");
			boutons[10].settype("disabled");
			boutons[11].settype("up_type");
			boutons[12].settype("up_type");
			boutons[15].settype("delay_type");
		}
	}
	else
		boutons[2].settype("disabled");
	if(train.getVtrain() == 0 && train.getDriverID() && (train.getGeneralMode() == "SB" || train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" ||
		train.getGeneralMode() == "OS" || train.getGeneralMode() == "NL" || train.getGeneralMode() == "UN" || train.getGeneralMode() == "SN" ))
	{
		enable[4] = 0;
		boutons[4].settype("up_type");
		if(boutons[4].getactivation() == 1)
		{
			ecran = "ERTMS_ETCSlevelWindow";
			for(int i = 0; i <= 14; i++)
				boutons[i].settype("down_type");
			boutons[10].settype("disabled");
			boutons[11].settype("up_type");
			boutons[12].settype("disabled");
			boutons[13].settype("disabled");
			boutons[14].settype("disabled");
			boutons[15].settype("delay_type");
		}
	}
	else
		boutons[4].settype("disabled");
	if((train.getVtrain() == 0 && train.getGeneralMode() == "SB" && train.getDriverID() && train.getETATLevelETCS()) || ((train.getGeneralMode() == "SB" || train.getGeneralMode() == "FS" ||
		train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" || train.getGeneralMode() == "OS" || train.getGeneralMode() == "NL"|| train.getGeneralMode() == "UN" ||
		train.getGeneralMode() == "SN" )))
	{
		enable[5] = 0;
		boutons[5].settype("up_type");
		if(boutons[5].getactivation() == 1)
		{
			ecran = "trainRunningNumberWindow";
			for(int i = 0; i <= 14; i++)
				boutons[i].settype("down_type");
			boutons[10].settype("down_type");
			boutons[11].settype("up_type");
			boutons[12].settype("disabled");
			boutons[13].settype("disabled");
			boutons[14].settype("disabled");
			boutons[15].settype("delay_type");
		}
	}
	else
		boutons[5].settype("disabled");
	if((train.getVtrain() == 0 && train.getDriverID() && (train.getGeneralMode() == "SB" || train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" ||
		train.getGeneralMode() == "OS" || train.getGeneralMode() == "UN" || train.getGeneralMode() == "SN" ) && train.getETATLevelETCS() && ((train.getLevel() == "Level 0" ||
		train.getLevel() == "Level 1" || train.getLevel().substr(0,2) == "NTC") || ((train.getLevel() == "Level 2" || train.getLevel() == "Level 3") &&
		train.getConnection() == "Up"))) || (train.getVtrain() == 0 && train.getGeneralMode() == "PT" && (train.getLevel() == "Level 1" || ((train.getLevel() == "Level 2" ||
		train.getLevel() == "Level 3") && train.getConnection() == "Up" && train.getPending_Emergency_Stop() == false))))
	{
		enable[6] = 0; //shunting  x
		boutons[6].settype("up_type");
	}
	else if(train.getVtrain() == 0 && train.getGeneralMode() == "SH")
	{
		enable[6] = 0;//Exit Shunting
		boutons[6].settype("up_type");
	}
	else
		boutons[6].settype("disabled");
	if(train.getVtrain() == 0 && train.getDriverID() && train.getETATLevelETCS() && (train.getGeneralMode() == "SB" || train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" ||
		train.getGeneralMode() == "SR" || train.getGeneralMode() == "OS" || train.getGeneralMode() == "SH") && train.getNon_Leading() == false)
	{
		enable[7] = 0;
		boutons[7].settype("up_type");
	}
	else
		boutons[7].settype("disabled");
	if(train.getGeneralMode() == "SH" && train.getPassive_Shunting())
	{
		enable[8] = 0;
		boutons[8].settype("up_type");
	}
	else
		boutons[8].settype("disabled");
	if (version == "3.6.0")
	{
		if (train.getVtrain() == 0 && train.getDriverID() && train.getETATLevelETCS() && (train.getGeneralMode() == "SB" || train.getGeneralMode() == "FS" ||
			train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" || train.getGeneralMode() == "OS" || train.getGeneralMode() == "NL"||
			train.getGeneralMode() == "UN" || train.getGeneralMode() == "SN" || train.getGeneralMode() == "PT"))
		{
			enable[9] = 0;
			boutons[9].settype("up_type");
		}
		else
			boutons[9].settype("disabled");
	}
	else
	{
		enable[9] = 2;
		boutons[9].settype("disabled");
	}
	selection = {"Start", "Driver ID", "Train data", "", "Level", "Train running number", "Shunting", "Non-Leading", "Maintain Shunting"};
	if(version == "3.6.0")
		selection.push_back("Radio data");
    menuWindows(selection, enable, fenetre, RE, symbol, arial, "Main", ecart);
    close(ecran, boutons, numero);
}


void overrideWindow(vector<Symbol> & symbol, Font & arial, string version, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
    vector <string> selection(1);
    vector <int> enable(1);
    enable[0] = 1;
    if ((train.getVtrain() <=  train.getVrelease() && (train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" || train.getGeneralMode() == "OS"||
        train.getGeneralMode() == "UN" || train.getGeneralMode() == "SN" || train.getGeneralMode() == "SH"))
        || (train.getVtrain() <=  train.getVrelease() && train.getGeneralMode() == "SB" && train.getDriverID() && train.getTrainData() && train.getETATLevelETCS() &&
		(train.getLevel() == "Level 2" || train.getLevel() == "Level 3")) || (version =="3.6.0" && (train.getVtrain() <=  train.getVrelease() && train.getGeneralMode() == "PT" &&
		train.getTrainData() && train.getTrainNumber())))
    {
        boutons[0].settype("up_type");
        if(version == "3.4.0" || (version == "3.6.0" && train.getTrainNumber()))
            enable[0] = 0;
    }
    else
        boutons[0].settype("disabled");
    if (boutons[0].getactivation())
    {
        ecran = "defaultWindow";
        if(train.getEOA())
            train.setEOA(false);
        else
            train.setEOA(true);
    }
    selection = {"EOA"};
    menuWindows(selection, enable, fenetre, RE, symbol, arial, "Override", ecart);
    close(ecran, boutons, numero);
}

void specialWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero)
{
    vector <string> selection(3);
    vector <int> enable(3);
    for (int i = 0; i <= 2; i++)
        enable[i] = 1;
    if ((train.getVtrain() == 0 && train.getGeneralMode() == "SB" && train.getmodif_Adhesion() && train.getDriverID() && train.getTrainData() && train.getETATLevelETCS())
        || (train.getmodif_Adhesion() && (train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" || train.getGeneralMode() == "OS"||
        train.getGeneralMode() == "UN" || train.getGeneralMode() == "SN")))
    {
            enable[0] = 0;
            boutons[0].settype("up_type");
    }
    else
        boutons[0].settype("disabled");
    if(train.getVtrain() == 0 && train.getGeneralMode() == "SR")
    {
        enable[1] = 0;
        boutons[1].settype("up_type");
    }
    else
        boutons[1].settype("disabled");
    if (train.getVtrain() == 0 && train.getDriverID() && train.getTrainData() && train.getETATLevelETCS() && (train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" ||
		train.getGeneralMode() == "SR" || train.getGeneralMode() == "OS"|| train.getGeneralMode() == "PT" || train.getGeneralMode() == "SB"))
    {
        enable[2] = 0;
        boutons[2].settype("up_type");
    }
    else
        boutons[2].settype("disabled");
    if (boutons[2].getactivation())
        ecran = "defaultWindow";
    else if (boutons[1].getactivation())
        ecran = "SRspeed/distanceWindow";
    else if (boutons[0].getactivation())
    {
        ecran = "adhesionWindow";
		boutons[10].settype("disabled");
		boutons[12].settype("disabled");
		boutons[13].settype("disabled");
		boutons[14].settype("disabled");
    }
    selection = {"Adhesion", "SR speed / distance", "Train integrity"};
    menuWindows(selection, enable, fenetre, RE, symbol, arial, "Special", ecart);
    close(ecran, boutons, numero);
}

void settingsWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<VBC> & vbc, vector<Buttons> & boutons, string & ecran, int & numero)
{
    vector <string> selection(6);
    vector <int> enable(6);
    for (int i = 0; i <= 5; i++)
        enable[i] = 1;
    if ((train.getVtrain() == 0 && train.getGeneralMode() == "SB")
        || (train.getGeneralMode() == "SH" || train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" ||train.getGeneralMode() == "OS" ||
        train.getGeneralMode() == "NL" || train.getGeneralMode() == "UN" || train.getGeneralMode() == "TR" || train.getGeneralMode() == "PT" || train.getGeneralMode() == "SN" ||
        train.getGeneralMode() == "RV"))
    {
        for (int i = 0; i <= 3; i++)
        {
            enable[i] = 0;
            boutons[i].settype("up_type");
        }
        if(boutons[0].getactivation() == 1)
            ecran = "languageWindow";
        else if(boutons[1].getactivation() == 1)
            ecran = "volumeWindow";
        else if(boutons[2].getactivation() == 1)
            ecran = "brightnessWindow";
        else if(boutons[3].getactivation() == 1)
            ecran = "systemVersionWindow";
    }
    else
    {
        for (int i = 0; i <= 3; i++)
            boutons[i].settype("delayed");
    }
    if(train.getVtrain() == 0 && train.getGeneralMode() == "SB" && vbc.size() < 20)
    {
        enable[4] = 0;
        boutons[4].settype("up_type");
    }
    else
        boutons[4].settype("delayed");
    if(train.getVtrain() == 0 && train.getGeneralMode() == "SB" && vbc.size() > 0)
    {
        enable[5] = 0;
        boutons[5].settype("up_type");
    }
    else
        boutons[5].settype("delayed");
    selection = {"Language", "Volume", "Brightness", "System version", "Set VBC", "Remote VBC"};
    menuWindows(selection, enable, fenetre, RE, symbol, arial, "Settings", ecart);
    close(ecran, boutons, numero);
}


void RBCcontactWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero)
{
    vector <string> selection(4);
    vector <int> enable(4);
    for (int i = 0; i <= 3; i++)
        enable[i] = 1;
    if(train.getVtrain() == 0 && train.getDriverID() && (train.getGeneralMode() == "SB" || train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" ||
		train.getGeneralMode() == "OS" || train.getGeneralMode() == "NL" || train.getGeneralMode() == "PT") && train.getETATLevelETCS() && (train.getLevel() == "Level 2" ||
		train.getLevel() == "Level 3"))
    {
         for (int i = 0; i <= 2 ; i++)
         {
            enable[i] = 0;
            boutons[i].settype("up_type");
          }
    }
    else
    {
        for (int i = 0; i <= 2; i++)
            boutons[i].settype("delayed");
    }
    if(train.getVtrain() == 0 && train.getDriverID() && (train.getGeneralMode() == "SB" || train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" ||
		train.getGeneralMode() == "OS" || train.getGeneralMode() == "NL" || train.getGeneralMode() == "PT" || train.getGeneralMode() == "UN" || train.getGeneralMode() == "SN") &&
		train.getETATLevelETCS())
    {
         enable[3] = 0;
         boutons[3].settype("up_type");
    }
    else
         boutons[3].settype("delayed");
    selection = {"Contact last RBC", "Use short number", "Enter RBC data", "Radio Network ID"};
    menuWindows(selection, enable, fenetre, RE, symbol, arial, "RBC contact", ecart);
    close(ecran, boutons, numero);
}

void trainRunningNumberWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
	dataEntryWindows({{"", "", "0"}}, fenetre, RE, symbol, arial, 0, "Train running number", {}, numero, "numeric", boutons, ecran, train, ecart);
}

void ERTMS_ETCSlevelWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
	dataEntryWindows({{"", train.getLevel(), ""}}, fenetre, RE, symbol, arial, 0, "Level", {"Level 1", "Level 2", "Level 3", "Level 0"}, numero, "dedicated keyboard", boutons, ecran, train, ecart);
	if(boutons[0].getactivation())
		train.setLevelETCS("Level 1");
	else if(boutons[1].getactivation())
		train.setLevelETCS("Level 2");
	else if(boutons[2].getactivation())
		train.setLevelETCS("Level 3");
	else if(boutons[3].getactivation())
		train.setLevelETCS("Level 0");
}

void driverIDWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
    if(boutons[0].getactivation())
		train.setTempDriver_ID(train.getTempDriver_ID() * 10 + 1);
    else if(boutons[1].getactivation())
        train.setTempDriver_ID(train.getTempDriver_ID()  * 10 + 2);
    else if(boutons[2].getactivation())
        train.setTempDriver_ID(train.getTempDriver_ID() * 10 + 3);
    else if(boutons[3].getactivation())
        train.setTempDriver_ID(train.getTempDriver_ID()  * 10 + 4);
    else if(boutons[4].getactivation())
        train.setTempDriver_ID(train.getTempDriver_ID() * 10 + 5) ;
    else if(boutons[5].getactivation())
        train.setTempDriver_ID(train.getTempDriver_ID() * 10 + 6);
    else if(boutons[6].getactivation())
        train.setTempDriver_ID(train.getTempDriver_ID()  * 10 + 7);
    else if(boutons[7].getactivation())
        train.setTempDriver_ID(train.getTempDriver_ID()  * 10 + 8);
    else if(boutons[8].getactivation())
        train.setTempDriver_ID(train.getTempDriver_ID()  * 10 + 9);
    else if(boutons[9].getactivation())
        train.setTempDriver_ID(train.getTempDriver_ID()  * 10 + 0);
    else if(boutons[10].getactivation())
        train.setTempDriver_ID(ceil(train.getTempDriver_ID() /10));
    else if(boutons[12].getactivation())
        train.setTempDriver_ID(train.getDriver_ID());
    else if(boutons[15].getactivation())
    {
        train.setDriver_ID(train.getTempDriver_ID());
        dataEntryWindows({{"", to_string(train.getDriver_ID()), "1"}}, fenetre, RE, symbol, arial, 0, "Driver ID", {}, numero, "alphanumeric", boutons, ecran, train, ecart);
    }
	//if(train.getTempDriver_ID() == 0)
	//	dataEntryWindows({{"", "", "0"}}, fenetre, RE, symbol, arial, 0, "Driver ID", {}, numero, "alphanumeric", boutons, ecran, train);
	//else
	dataEntryWindows({{"", to_string(train.getTempDriver_ID()), "0"}}, fenetre, RE, symbol, arial, 0, "Driver ID", {}, numero, "alphanumeric", boutons, ecran, train, ecart);
}

void radionetworkIDWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
	dataEntryWindows({{"", train.getRadioNetworkID(), "0"}}, fenetre, RE, symbol, arial, 0, "Radio network ID", {}, numero, "dedicated keyboard", boutons, ecran, train, ecart);
	if(boutons[0].getactivation())
		train.setRadioNetworkID("GSMR-A");
	else if(boutons[1].getactivation())
		train.setRadioNetworkID("GSMR-B");
	else if(boutons[1].getactivation())
		train.setRadioNetworkID("Telecom X");
}

void RBCdataWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
    int i = 0;
    if(numero == 1)
    {
        if(boutons[0].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 1);
        else if(boutons[1].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 2);
        else if(boutons[2].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 3);
        else if(boutons[3].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 4);
        else if(boutons[4].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 5);
        else if(boutons[5].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 6);
        else if(boutons[6].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 7);
        else if(boutons[7].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 8);
        else if(boutons[8].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 9);
        else if(boutons[9].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 0);
        else if(boutons[10].getactivation())
            train.setTempRBCID(ceil(train.getTempRBCID()/10));
        else if (boutons[13].getactivation() || boutons[14].getactivation() || boutons[12].getactivation())
        {
            train.setTempRBCID(train.getRBCID());
            i = 1;
            dataEntryWindows({{"RBC ID", to_string(train.getRBCID()), "0"}, {"RBC phone number", to_string(train.getRBCphoneNumber()), "0"}}, fenetre, RE, symbol, arial, 1, "RBC data", {}, numero,
				"numeric", boutons, ecran, train, ecart);
        }
        else if(boutons[15].getactivation())
        {
            train.setRBCID(train.getTempRBCID());
            numero++;
            i = 1;
            dataEntryWindows({{"RBC ID", to_string(train.getRBCID()), "1"}, {"RBC phone number", to_string(train.getRBCphoneNumber()), "0"}}, fenetre, RE, symbol, arial, 1, "RBC data", {},
				numero, "numeric", boutons, ecran, train, ecart);
        }
        if(i ==0)
		{
			if(train.getTempRBCID() == 0)
				dataEntryWindows({{"RBC ID", "", "0"}, {"RBC phone number", to_string(train.getRBCphoneNumber()), "0"}}, fenetre, RE, symbol, arial, 1, "RBC data", {}, numero, "numeric", boutons,
					ecran, train, ecart);
			else
				dataEntryWindows({{"RBC ID", to_string(train.getTempRBCID()), "0"}, {"RBC phone number", to_string(train.getRBCphoneNumber()), "0"}}, fenetre, RE, symbol, arial, 1, "RBC data", {},
					numero, "numeric", boutons, ecran, train, ecart);
		}
    }
    else
    {
        if(boutons[0].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 1);
        else if(boutons[1].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 2);
        else if(boutons[2].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 3);
        else if(boutons[3].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 4);
        else if(boutons[4].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 5);
        else if(boutons[5].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 6);
        else if(boutons[6].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 7);
        else if(boutons[7].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 8);
        else if(boutons[8].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 9);
        else if(boutons[9].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 0);
        else if(boutons[10].getactivation())
            train.setTempRBCphoneNumber(ceil(train.getTempRBCphoneNumber()/10));
        else if (boutons[13].getactivation() || boutons[14].getactivation() || boutons[14].getactivation())
        {
            train.setTempRBCphoneNumber(train.getRBCphoneNumber());
            i = 1;
            dataEntryWindows({{"RBC ID", to_string(train.getRBCID()), "0"}, {"RBC phone number", to_string(train.getRBCphoneNumber()), "0"}}, fenetre, RE, symbol, arial, 1, "RBC data", {}, numero,
				"numeric", boutons, ecran, train, ecart);
        }
        else if(boutons[15].getactivation())
        {
            train.setRBCphoneNumber(train.getTempRBCphoneNumber());
            numero--;
            i = 1;
            dataEntryWindows({{"RBC ID", to_string(train.getRBCID()), "1"}, {"RBC phone number", to_string(train.getRBCphoneNumber()), "0"}}, fenetre, RE, symbol, arial, 1, "RBC data", {},
				numero, "numeric", boutons, ecran, train, ecart);
        }

       if(i ==0)
		{
			if(train.getTempRBCphoneNumber() == 0)
				dataEntryWindows({{"RBC ID", to_string(train.getRBCID()), "0"}, {"RBC phone number", "", "0"}}, fenetre, RE, symbol, arial, 1, "RBC data", {}, numero, "numeric", boutons, ecran, train, ecart);
			else
				dataEntryWindows({{"RBC ID", to_string(train.getRBCID()), "0"}, {"RBC phone number", to_string(train.getTempRBCphoneNumber()), "0"}}, fenetre, RE, symbol, arial, 1, "RBC data", {},
					numero, "numeric", boutons, ecran, train, ecart);

		}
	}
}


void languageWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
	dataEntryWindows({{"", train.getLanguage(), "0"}}, fenetre, RE, symbol, arial, 0, "Language", {"English", "Francais"}, numero, "dedicated keyboard", boutons, ecran, train, ecart);
	if(boutons[0].getactivation())
		train.setLanguage("English");
	else if(boutons[1].getactivation())
		train.setLanguage("Francais");
}

void volumeWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
	dataEntryWindows({{""}}, fenetre, RE, symbol, arial, 0, "Volume", {}, numero, "", boutons, ecran, train, ecart);
}

void brightnessWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
	dataEntryWindows({{""}}, fenetre, RE, symbol, arial, 0, "Brightness", {}, numero, "", boutons, ecran, train, ecart);
}

void trainDataWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
	vector<vector<string>> input_field = {{"Train category", train.getTrain_category(), "0"}, {"Length (m)", to_string(train.getlength()), "1"}, {"Brake percentage",
		to_string(train.getbreaking_percetage()), "0"}, {"Max speed (km/h)", to_string(train.getmaximum_train_speed()), "0"}, {"Axle load category",
		train.getaxle_load_category(), "0"}, {"Airtight", train.getAirtight(), "0"}, {"Loading gauge", train.getloading_gauge(), "0"}};
	vector <string> selection = {};
	string keyboard = "";
	//if(numero == 1)
	//
	//if(numero == 2)
	//
	//if(numero == 3)
	//
	//if(numero == 4)
	//
	//if(numero == 5)
	//
	//if(numero == 6)
	//
	//if(numero == 7)
	//
	dataEntryWindows(input_field, fenetre, RE, symbol, arial, 1, "Train data", selection, numero, keyboard, boutons, ecran, train, ecart);
	for(int i = 0; i < int(input_field.size()); i++)
		creation_texte(RE, input_field[i][0], arial, GREY, 12, 0, V2f(204 - 5, 20 * i + 100 + 6), fenetre, 2, ecart);
}

void SRspeedWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
    dataEntryWindows({{"SR speed (km/h)", to_string(train.getSRspeed()), "0"}, {"SR distance (m)", "b", "0"}}, fenetre, RE, symbol, arial, 0, "SR speed/distance", {}, numero, "numeric", boutons,
		ecran, train, ecart);
	if(boutons[0].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 1);
	else if(boutons[1].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 2);
	else if(boutons[2].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 3);
	else if(boutons[3].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 4);
	else if(boutons[4].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 5);
	else if(boutons[5].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 6);
	else if(boutons[6].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 7);
	else if(boutons[7].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 8);
	else if(boutons[8].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 9);
	else if(boutons[9].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 0);
}

void adhesionWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
	dataEntryWindows({{"", train.getAdhesion(),"0"}}, fenetre, RE, symbol, arial, 0, "Adhesion", {"Non slippery rail","Slippery rail"}, numero, "dedicated keyboard", boutons, ecran, train, ecart);
	if(boutons[0].getactivation())
		train.setAdhesion("Non slippery rail");
	else if(boutons[1].getactivation())
		train.setAdhesion("Slippery rail");
}

void dataViewWindows(vector<Symbol> & symbol, Font & arial, string title, int & numero, vector<Buttons> & boutons, string & ecran, vector<vector<string>> item)
{
	rectangle(V2f(54 + 280, 0), V2f(266, 24), BLACK, RE, fenetre, ecart);
	if(title == "Data View")
		title += " (" + to_string(numero) + "/2)";
	creation_texte(RE, title, arial, GREY, 17, 0, V2f(54 + 280 + 3, 12), fenetre, 4, ecart);
	for(int i = 0; i <= int(item.size()) - 1; i++)
	{
		creation_texte(RE, item[i][0], arial, GREY, 17, 0, V2f(280 + 54 + 176 - 5, 60 + 17 / 2.0 + i * 22), fenetre, 2, ecart);
		creation_texte(RE, item[i][1], arial, GREY, 17, 0, V2f(280 + 54 + 176 + 5, 60 + 17 / 2.0 + i * 22), fenetre, 4, ecart);
	}
	if(numero == 1)
	{
		NA_11.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0), RE, ecart, fenetre);		//H3
		boutons[11].settype("up_type");
		close(ecran, boutons, numero);
	}
	else if(numero == 2)
	{
		NA_18.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0), RE, ecart, fenetre);		//H3
		boutons[11].settype("up_type");
		if(boutons[11].getactivation())
			numero--;
	}
	if(numero == 2)
	{
		NA_18_2.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2+ 64 / 2.0), RE, ecart, fenetre);	//H4
		boutons[12].settype("disabled");
	}
	else if(numero == 1)
	{
		boutons[12].settype("up_type");
		NA_17.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2+ 64 / 2.0), RE, ecart, fenetre);	//H4
		if(boutons[12].getactivation())
			numero++;
	}
}

void dataViewWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
    vector<vector<string>> item;
    if(numero == 1)
    	item = {{"Driver ID", to_string(train.getDriver_ID())}, {"", ""},{"Train running number", to_string(train.getTrain_running_number()) },
			{"", ""}, {"Train type", train.getTrain_type()}, {"Train category", train.getTrain_category()}, {"Length (m)", to_string(train.getlength())},
			{"Brake percentage", to_string(train.getbreaking_percetage())}, {"Max speed (km/h)", to_string(train.getmaximum_train_speed())},
			{"Axle load category", train.getaxle_load_category()}, {"Airtight", train.getAirtight()}, {"Loading gauge", train.getloading_gauge()}};
    else
    	item = {{"Radio network ID", train.getRadioNetworkID()}, {"RBC ID", to_string(train.getRBCID())}, {"RBC phone number", to_string(train.getRBCphoneNumber())}, {"", ""},
		{"VBC #1 set code", "d"}, {"VBC #2 set code", "e"}};
    dataViewWindows(fenetre, RE, symbol, arial, "Data View", numero, boutons, ecran, item, ecart);
}

void systemVersionWindow(vector<Symbol> & symbol, Font & arial, vector<Buttons> & boutons, string & ecran, int & numero)
{
	vector<vector<string>> item = {{"Operated system version", ""}};
	dataViewWindows(fenetre, RE, symbol, arial, "System version", numero, boutons, ecran, item, ecart);
}

void windows(string & ecran, vector<Symbol> & symbol, Font & arial, string version, donnees & train, vector<VBC> vbc, vector<Buttons> & boutons, int & numero)
{
    if(ecran == "mainWindow")
        MainWindow(fenetre, RE, symbol, arial, version, train, boutons, ecran, numero, ecart);
    else if(ecran == "overrideWindow")
        overrideWindow(fenetre, RE, symbol, arial, version, train, boutons, ecran, numero, ecart);
    else if(ecran == "specialWindow")
        specialWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "settingsWindow")
        settingsWindow(fenetre, RE, symbol, arial, train, vbc, boutons, ecran, numero, ecart);
    else if(ecran == "RBCcontactWindow")
        RBCcontactWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "trainRunningNumberWindow")
        trainRunningNumberWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "ERTMS_ETCSlevelWindow")
        ERTMS_ETCSlevelWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "driverIDWindow")
        driverIDWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "radionetworkIDWindow")
        radionetworkIDWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "RBCdataWindow")
        RBCdataWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "languageWindow")
        languageWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "volumeWindow")
        volumeWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "brightnessWindow")
        brightnessWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "SRspeed/distanceWindow")
        SRspeedWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "adhesionWindow")
        adhesionWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "trainDataWindow")
        trainDataWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "dataViewWindow")
        dataViewWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "systemVersionWindow")
        systemVersionWindow(fenetre, RE, symbol, arial, boutons, ecran, numero, ecart);
}


void close(string & ecran, vector<Buttons> & boutons, int & numero)
{
    if(boutons[11].getactivation())
        numero = 1;
    if(boutons[11].getactivation() && (ecran == "mainWindow" || ecran == "overrideWindow" || ecran == "specialWindow" || ecran == "settingsWindow"|| ecran == "dataViewWindow"))
        ecran = "defaultWindow";
    else if(boutons[11].getactivation()&& (ecran == "languageWindow" || ecran == "volumeWindow" || ecran == "brightnessWindow"))
        ecran = "settingsWindow";
    else if(boutons[11].getactivation()&& (ecran == "driverIDWindow" || ecran == "trainDataWindow" || ecran == "trainRunningNumberWindow" || ecran == "RBCdataWindow" ||
		ecran == "ERTMS_ETCSlevelWindow"))
        {
            ecran = "mainWindow";
            boutons[3].settype("disabled");
			boutons[10].settype("disabled");
			boutons[12].settype("disabled");
			boutons[13].settype("disabled");
			boutons[14].settype("disabled");
			boutons[15].settype("disabled");
        }
    else if(boutons[11].getactivation()&& (ecran == "adhesionWindow" || ecran == "SRspeed/distanceWindow"))
        ecran = "specialWindow";
}