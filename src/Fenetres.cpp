/*#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <math.h>
#include <string>
#include <ctime>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include "symbol.hpp"
#include "donnees.hpp"
#include "Buttons.hpp"
#include "planning.hpp"
#include "Fenetres.hpp"

void menuWindows(vector <string> selection, vector <int>& enable, RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string title, int * ecart)
{
	Color color;
	rectangle(V2f(54 + 280, 0), V2f(266, 24), BLACK, RE, fenetre, ecart);
	NA_11.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0), RE, ecart, fenetre);	//H5
	for(int i = 0; i < (int)selection.size(); i++)
	{
		if(enable[i] == 0)
			color = GREY;
		else if(enable[i] == 1)
			color = DARK_GREY;
		if(enable[i] != 2)
		{
			creation_texte(RE, to_string(i + 1) + " - " + selection[i], arial, color, 12, 0, V2f(54 + 280 + 15, 100 + 6 + i * 20), fenetre, 4, ecart);
			creation_texte(RE, to_string(i + 1), arial, color, 16, 0, V2f(64 / 2.0 + i * 64, 430 + 50 / 2.0), fenetre, 1, ecart);
		}
	}
	creation_texte(RE, title, arial, GREY, 12, 0, V2f(54 + 280 + 3, 12), fenetre, 4, ecart);
}

void MainWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string version, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
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


void overrideWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string version, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
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

void specialWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
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

void settingsWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<VBC> & vbc, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
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


void RBCcontactWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
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

void dataEntryWindows(vector<vector<string>> input_field, RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, int complete, string title, vector<string> selection, int & sel,
	string keyboard, vector<Buttons> & boutons, string & ecran, donnees & train, int * ecart)
{
	for(int i = 0; i <= 9; i++)
		boutons[i].settype("down_type");
	if(keyboard == "numeric")
	{
		NA_21.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 / 2.0), RE, ecart, fenetre);			//H2
		boutons[10].settype("down_type");
		for(int i = 1; i <= 10; i++)
			creation_texte(RE, to_string(i % 10), arial, GREY, 16, 0, V2f(- 64 / 2.0 + i * 64, 430 + 50 / 2.0), fenetre, 1, ecart);
	}
	else if(keyboard == "enhanced numeric")
	{
		NA_21.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 / 2.0), RE, ecart, fenetre);			//H2
		creation_texte(RE, "1.  ", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 1 * 64, 430 + 50 / 2.0), fenetre, 3, ecart);
		for(int i = 2; i <= 10; i++)
			creation_texte(RE, to_string(i % 10), arial, GREY, 16, 0, V2f(- 64 / 2.0 + i * 64, 430 + 50 / 2.0), fenetre, 1, ecart);
	}
	else if(keyboard == "alphanumeric")
	{
		NA_21.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 / 2.0), RE, ecart, fenetre);			//H2
		creation_texte(RE, "1", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 1 * 64, 430 + 50 / 2.0), fenetre, 1, ecart);
		creation_texte(RE, "2abc", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 2 * 64, 430 + 50 / 2.0), fenetre, 3, ecart);
		creation_texte(RE, "3def", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 3 * 64, 430 + 50 / 2.0), fenetre, 3, ecart);
		creation_texte(RE, "4hij", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 4 * 64, 430 + 50 / 2.0), fenetre, 3, ecart);
		creation_texte(RE, "5klm", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 5 * 64, 430 + 50 / 2.0), fenetre, 3, ecart);
		creation_texte(RE, "6nop", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 6 * 64, 430 + 50 / 2.0), fenetre, 3, ecart);
		creation_texte(RE, "7qrs", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 7 * 64, 430 + 50 / 2.0), fenetre, 3, ecart);
		creation_texte(RE, "8tuv", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 8 * 64, 430 + 50 / 2.0), fenetre, 3, ecart);
		creation_texte(RE, "9wxyz", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 9 * 64, 430 + 50 / 2.0), fenetre, 3, ecart);
		creation_texte(RE, "0", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 10 * 64, 430 + 50 / 2.0), fenetre, 1, ecart);
	}
	else if(keyboard == "dedicated keyboard")
    {
        for(int i = 1; i <= (int)selection.size(); i++)
            creation_texte(RE, to_string(i % 10), arial, GREY, 16, 0, V2f(- 64 / 2.0 + i * 64, 430 + 50 / 2.0), fenetre, 1, ecart);
        if(selection.size() >= 10)
            boutons[9].settype("up_type");
    }
	if(boutons[14].getactivation())
		sel = sel % input_field.size() + 1;
	else if(boutons[13].getactivation())
	{
		if(sel != 1)
			sel--;
		else
			sel = input_field.size();
	}
	int numero = sel;
	string sequenceNumber;
	Color color;
	if(complete == 1 && input_field.size() > 4)
		sequenceNumber = string(" (") + to_string((int)ceil(numero / 4.0)) + "/" + to_string((int)ceil(input_field.size() / 4.0)) + ")";
	else if(complete == 0 && input_field.size() > 3)
		sequenceNumber = string(" (") + to_string((int)ceil(numero / 3.0)) + "/" + to_string((int)ceil(input_field.size() / 3.0)) + ")";
	if(((int)ceil(numero / 4.0) == 1 && complete == 1) || ((int)ceil(numero / 3.0) == 1 && complete == 0))
	{
		NA_11.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0), RE, ecart, fenetre);		//H3
		boutons[11].settype("up_type");
		close(ecran, boutons, sel);
	}
	else
	{
		NA_18.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0), RE, ecart, fenetre);		//H3
		boutons[11].settype("up_type");
		if(boutons[11].getactivation())
		{
			while(sel % 4 != 0)
				sel--;
			sel = sel - 3;
		}
	}
	if((((complete == 1 && input_field.size() > 4 && (int)ceil(numero / 4.0) == (int)ceil(input_field.size() / 4.0)) || (complete == 0 && input_field.size() > 3 &&
		(int)ceil(numero / 3.0) == (int)ceil(input_field.size() / 3.0)))))
	{
		NA_18_2.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2+ 64 / 2.0), RE, ecart, fenetre);	//H4
		boutons[12].settype("disabled");
	}
	else if((complete == 1 && input_field.size() > 4) || (complete == 0 && input_field.size() > 3))
	{
		boutons[12].settype("up_type");
		NA_17.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2+ 64 / 2.0), RE, ecart, fenetre);	//H4
		if(boutons[12].getactivation())
		{
			while(sel % 4 != 0)
				sel++;
			sel++;
		}
	}
	if(input_field.size() > 1)
	{
		NA_14.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 4 + 64 / 2.0), RE, ecart, fenetre);	//H6
		NA_13.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 3 + 64 / 2.0), RE, ecart, fenetre);	//H5
	}
	NA_20.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 5 + 41), RE, ecart, fenetre);		//H7
	if(complete)
	{
		rectangle(V2f(0, 380), V2f(334, 50), DARK_GREY, RE, fenetre, ecart);
		rectangle(V2f(0, 380), V2f(334 - 1, 50 - 1), WHITE, RE, fenetre, ecart);
		rectangle(V2f(0 + 1, 380 + 1), V2f(334 - 2, 50 - 2), MEDIUM_GREY, RE, fenetre, ecart);
		creation_texte(RE, "Yes", arial, BLACK, 12, 0, V2f(334 / 2.0, 380 + 25), fenetre, 1, ecart);
		creation_texte(RE, title + " entry complete ?", arial, GREY, 12, 0, V2f(334 / 2.0, 330 + 25), fenetre, 1, ecart);
		rectangle(V2f(0, 0), V2f(334, 24), BLACK, RE, fenetre, ecart);
		creation_texte(RE, title + sequenceNumber, arial, GREY, 12, 0, V2f(54 + 280 - 3, 12), fenetre, 2, ecart);
	}
	else
	{
		rectangle(V2f(54 + 280, 0), V2f(266, 24), BLACK, RE, fenetre, ecart);
		creation_texte(RE, title, arial, GREY, 12, 0, V2f(54 + 280 + 3, 12), fenetre, 4, ecart);
	}
	if(input_field.size() == 1)
	{
		rectangle(V2f(54 + 280, 50), V2f(266, 50), DARK_GREY, RE, fenetre, ecart);
		rectangle(V2f(54 + 280, 50), V2f(266 - 1, 50 - 1), WHITE, RE, fenetre, ecart);
		rectangle(V2f(54 + 280 + 1, 50 + 1), V2f(266 - 2, 50 - 2), MEDIUM_GREY, RE, fenetre, ecart);
		creation_texte(RE, input_field[0][1], arial, BLACK, 12, 0, V2f(54 + 280 + 10, 25 + 50), fenetre, 4, ecart);
	}
	else
	{
		if(complete)
		{
			if(numero % 4)
				numero = numero - numero % 4;
			else
				numero = numero - 4;
		}
		else
			numero = numero - numero % 3;
		for(int i = numero; i <= min((int)input_field.size() - 1, 3 + numero); i++)
		{
			rectangle(V2f(54 + 280, 50 * (i - numero) + 50 * (1 - complete)), V2f(164, 50), MEDIUM_GREY, RE, fenetre, ecart);
			rectangle(V2f(54 + 280 + 1, 50 * (i - numero) + 1 + 50 * (1 - complete)), V2f(164 - 2, 50 - 2), BLACK, RE, fenetre, ecart);
			rectangle(V2f(54 + 280 + 1, 1 + 50 * (i - numero) + 50 * (1 - complete)), V2f(164 - 2, 50 - 2), DARK_GREY, RE, fenetre, ecart);
			if(i == sel - 1)
			{
				rectangle(V2f(54 + 280 + 164, 50 * (i - numero) + 50 * (1 - complete)), V2f(102, 50), DARK_GREY, RE, fenetre, ecart);
				rectangle(V2f(54 + 280 + 164, 50 * (i - numero) + 50 * (1 - complete)), V2f(102 - 1, 50 - 1), WHITE, RE, fenetre, ecart);
				rectangle(V2f(54 + 280 + 164 + 1, 50 * (i - numero) + 1 + 50 * (1 - complete)), V2f(102 - 2, 50 - 2), MEDIUM_GREY, RE, fenetre, ecart);
			}
			else
			{
				rectangle(V2f(54 + 280 + 164, 50 * (i - numero) + 50 * (1 - complete)), V2f(102, 50), MEDIUM_GREY, RE, fenetre, ecart);
				rectangle(V2f(54 + 280 + 164 + 1, 50 * (i - numero) + 1 + 50 * (1 - complete)), V2f(102 - 2, 50 - 2), BLACK, RE, fenetre, ecart);
				rectangle(V2f(54 + 280 + 164 + 1, 1 + 50 * (i - numero) + 50 * (1 - complete)), V2f(102 - 2, 50 - 2), DARK_GREY, RE, fenetre, ecart);
			}
			creation_texte(RE, input_field[i][0], arial, GREY, 12, 0, V2f(54 + 280 + 10, 50 * (i - numero) + 25 + 50 * (1 - complete)), fenetre, 4, ecart);
			if(i == sel - 1)
			{	if(train.getClignotementTexte()/30 <= 1)
				{
					creation_texte(RE, input_field[i][1], arial, BLACK, 12, 0, V2f(54 + 280 + 164 + 10, 50 * (i - numero) + 25 + 50 * (1 - complete)), fenetre, 4, ecart);
					train.setClignotementTexte(train.getClignotementTexte() + 1);
				}
				else if (train.getClignotementTexte()/30 <= 2)
				{
					creation_texte(RE, input_field[i][1] + "_", arial, BLACK, 12, 0, V2f(54 + 280 + 164 + 10, 50 * (i - numero) + 25 + 50 * (1 - complete)), fenetre, 4, ecart);
					train.setClignotementTexte(train.getClignotementTexte() + 1);
				}
				else
					train.setClignotementTexte(0);
			}
			else if(input_field[i][2] == "1")
				creation_texte(RE, input_field[i][1], arial, WHITE, 12, 0, V2f(54 + 280 + 164 + 10, 50 * (i - numero) + 25 + 50 * (1 - complete)), fenetre, 4, ecart);
			else
				creation_texte(RE, input_field[i][1], arial, GREY, 12, 0, V2f(54 + 280 + 164 + 10, 50 * (i - numero) + 25 + 50 * (1 - complete)), fenetre, 4, ecart);
		}
	}
	for(int i = 0; i < (int)selection.size(); i++)
		creation_texte(RE, to_string(i + 1) + " - " + selection[i], arial, GREY, 12, 0, V2f(54 + 280 + 15, 200 + 15 + 6 + i * 20), fenetre, 4, ecart);
}

void trainRunningNumberWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
	dataEntryWindows({{"", "", "0"}}, fenetre, RE, symbol, arial, 0, "Train running number", {}, numero, "numeric", boutons, ecran, train, ecart);
}

void ERTMS_ETCSlevelWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
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

void driverIDWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
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

void radionetworkIDWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
	dataEntryWindows({{"", train.getRadioNetworkID(), "0"}}, fenetre, RE, symbol, arial, 0, "Radio network ID", {}, numero, "dedicated keyboard", boutons, ecran, train, ecart);
	if(boutons[0].getactivation())
		train.setRadioNetworkID("GSMR-A");
	else if(boutons[1].getactivation())
		train.setRadioNetworkID("GSMR-B");
	else if(boutons[1].getactivation())
		train.setRadioNetworkID("Telecom X");
}

void RBCdataWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
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


void languageWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
	dataEntryWindows({{"", train.getLanguage(), "0"}}, fenetre, RE, symbol, arial, 0, "Language", {"English", "Francais"}, numero, "dedicated keyboard", boutons, ecran, train, ecart);
	if(boutons[0].getactivation())
		train.setLanguage("English");
	else if(boutons[1].getactivation())
		train.setLanguage("Francais");
}

void volumeWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
	dataEntryWindows({{""}}, fenetre, RE, symbol, arial, 0, "Volume", {}, numero, "", boutons, ecran, train, ecart);
}

void brightnessWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
	dataEntryWindows({{""}}, fenetre, RE, symbol, arial, 0, "Brightness", {}, numero, "", boutons, ecran, train, ecart);
}

void trainDataWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
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

void SRspeedWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
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

void adhesionWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
	dataEntryWindows({{"", train.getAdhesion(),"0"}}, fenetre, RE, symbol, arial, 0, "Adhesion", {"Non slippery rail","Slippery rail"}, numero, "dedicated keyboard", boutons, ecran, train, ecart);
	if(boutons[0].getactivation())
		train.setAdhesion("Non slippery rail");
	else if(boutons[1].getactivation())
		train.setAdhesion("Slippery rail");
}

void dataViewWindows(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string title, int & numero, vector<Buttons> & boutons, string & ecran, vector<vector<string>> item, int * ecart)
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

void dataViewWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
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

void systemVersionWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
	vector<vector<string>> item = {{"Operated system version", ""}};
	dataViewWindows(fenetre, RE, symbol, arial, "System version", numero, boutons, ecran, item, ecart);
}

void windows(string & ecran, RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string version, donnees & train, vector<VBC> vbc, vector<Buttons> & boutons, int & numero, int * ecart)
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



void Fenetre::creation_texte(double RE, string message, Font police, Color couleur, int taille, double OutlineThickness, V2f pos, RenderWindow & fenetre, int mode, int * ecart) //mode 1 : centrer / mode 2 : aligner droite / mode 3 : Geographical position / mode 4 : aligner gauche
{
	Text texte;
	texte.setString(message);
	texte.setFont(police);
	texte.setOutlineThickness(OutlineThickness);
	texte.setOutlineColor(couleur);
	texte.setCharacterSize(taille * RE);
	texte.setFillColor(couleur);
	if(mode == 2)
		texte.setOrigin(texte.getLocalBounds().left + texte.getLocalBounds().width * 1.0f, texte.getLocalBounds().top + texte.getLocalBounds().height / 2.0f);
	else if(mode == 4)
	{
		if(message[message.size() - 1] == '_')
		{
			message = message.substr(0, message.size() - 1);
		}

		texte.setOrigin(texte.getLocalBounds().left, texte.getLocalBounds().top + texte.getLocalBounds().height / 2.0f);
		if(message[message.size() - 1] == '_')
		{
			message += "_";
			texte.setOrigin(texte.getLocalBounds().left, (pos.y + ecart[1]) * RE);
		}
	}
	else if(mode == 3 && message.size() > 3)
	{
		Text metre;
		if(couleur == BLACK)
			metre.setString(message.substr(message.size() - 3, 3));
		else
			metre.setString(message.substr(1, message.size() - 1));
		if(message.size() > 6)
			message = message.substr(0, message.size() - 6) + " " + message.substr(message.size() - 6, 6);
		if(couleur == BLACK)
			message = message.substr(0, message.size() - 3) + " ";
		else
			message = message.substr(0, 1) + " ";
		texte.setString(message);
		metre.setFont(police);
		metre.setOutlineThickness(OutlineThickness);
		metre.setOutlineColor(couleur);
		metre.setCharacterSize(10 * RE);
		metre.setFillColor(couleur);
		texte.setOrigin(texte.getLocalBounds().left + (texte.getLocalBounds().width + metre.getLocalBounds().width) / 2.0f, texte.getLocalBounds().top + texte.getLocalBounds().height / 2.0f);
		metre.setOrigin(metre.getLocalBounds().left - (texte.getLocalBounds().width - metre.getLocalBounds().width) / 2.0f, metre.getLocalBounds().top - texte.getLocalBounds().height / 2.0f + metre.getLocalBounds().height * 1.0f);
		metre.setPosition((pos.x + ecart[0]) * RE * 1.0f, (pos.y + ecart[1]) * RE * 1.0f);
		fenetre.draw(metre);
	}
	else if(mode == 1 || mode == 3)
	{
		if(mode == 3)
			texte.setCharacterSize(10 * RE);
		texte.setOrigin(texte.getLocalBounds().left + texte.getLocalBounds().width / 2.0f, texte.getLocalBounds().top + texte.getLocalBounds().height / 2.0f);
	}
	texte.setPosition((pos.x + ecart[0]) * RE * 1.0f, (pos.y + ecart[1]) * RE * 1.0f);
	fenetre.draw(texte);
}

void Fenetre::rectangle(V2f pos, V2f taille, Color col, double RE, RenderWindow & fenetre, int * ecart)
{
	RectangleShape barre(V2f(taille.x * RE, taille.y * RE));
	barre.setPosition((pos.x + ecart[0]) * RE, (pos.y + ecart[1]) * RE);
	barre.setFillColor(col);
	fenetre.draw(barre);
}

//RESUME DE LA FONCTION
//Besoin de la position de point en haut � gauche et de la dimension du quadrilat�re
//RE permet de modifier l'�paisseur en fct du rapport d'�cran
//mode 1=case mode 2=bouton mode 3=rappelle de la fonction pour cr�ation du carr� int�rieur
void Fenetre::creation_rectangle(V2f pos, V2f dim, double RE, int mode, RenderWindow & fenetre, int * ecart)
{
	if(mode == 1)
	{
		rectangle(pos, dim, SHADOW, RE, fenetre, ecart);
		rectangle(pos, V2f(dim.x - 1, dim.y - 1), BLACK, RE, fenetre, ecart);
		rectangle(V2f(pos.x + 1, pos.y + 1), V2f(dim.x - 2, dim.y - 2), DARK_BLUE, RE, fenetre, ecart);
	}
	if(mode == 2)
	{
		rectangle(pos, dim, SHADOW, RE, fenetre, ecart);
		rectangle(pos, V2f(dim.x - 1, dim.y - 1), BLACK, RE, fenetre, ecart);
		rectangle(V2f(pos.x + 1, pos.y + 1), V2f(dim.x - 3, dim.y - 3), SHADOW, RE, fenetre, ecart);
		rectangle(V2f(pos.x + 2, pos.y + 2), V2f(dim.x - 4, dim.y - 4), DARK_BLUE, RE, fenetre, ecart);
	}*/
	/*
	int epaisseur = RE;
	VertexArray bande(Quads,4);
	pos.x = pos.x * RE;
	pos.y = pos.y * RE;
	dim.x = dim.x * RE;
	dim.y = dim.y * RE;

	//Creation 1 ere bande
	bande[0].position=pos;
	bande[1].position=V2f(pos.x + dim.x - epaisseur, pos.y);
	bande[2].position=V2f(pos.x + dim.x - epaisseur, pos.y + epaisseur);
	bande[3].position=V2f(pos.x, pos.y + epaisseur);

	if(mode == 3)
	{
		couleurForme(bande, SHADOW, 4);
	}
	else
	{
		couleurForme(bande, BLACK, 4);
	}
	fenetre.draw(bande);

	//Creation 2eme bande
	bande[0].position= pos;
	bande[1].position=V2f(pos.x + epaisseur, pos.y);
	bande[2].position=V2f(pos.x + epaisseur, pos.y + dim.y - epaisseur);
	bande[3].position=V2f(pos.x, pos.y + dim.y - epaisseur);

	if(mode == 3)
	{
		couleurForme(bande, SHADOW, 4);
	}
	else
	{
		couleurForme(bande, BLACK, 4);
	}
	fenetre.draw(bande);

	//Creation 3eme bande
	bande[0].position= V2f(pos.x, pos.y + dim.y - epaisseur);
	bande[1].position=V2f(pos.x + dim.x, pos.y + dim.y - epaisseur);
	bande[2].position=V2f(pos.x + dim.x, pos.y + dim.y);
	bande[3].position=V2f(pos.x, pos.y + dim.y);

	if(mode == 3)
	{
		couleurForme(bande, BLACK, 4);
	}
	else
	{
		couleurForme(bande, SHADOW, 4);
	}

	fenetre.draw(bande);

	//Creation 4eme bande
	bande[0].position= V2f(pos.x+ dim.x - epaisseur, pos.y);
	bande[1].position=V2f(pos.x + dim.x, pos.y);
	bande[2].position=V2f(pos.x + dim.x, pos.y + dim.y);
	bande[3].position=V2f(pos.x+ dim.x - epaisseur, pos.y + dim.y);

	if(mode == 3)
	{
		couleurForme(bande, BLACK, 4);
	}
	else
	{
		couleurForme(bande, SHADOW, 4);
	}
	fenetre.draw(bande);

	if(mode == 2)		//CREER LE CARRE INTERIEUR POUR UN BOUTON
	{
		pos.x = pos.x + epaisseur;
		pos.y = pos.y + epaisseur;
		dim.x = dim.x - 2 * epaisseur;
		dim.y = dim.y - 2 * epaisseur;

		creation_rectangle(pos, dim,3, 3, fenetre, ecart);
	}
	*//*
}

void LeftSide::targetDistance(int distance, RenderWindow & fenetre, double RE, Font & arial, int * ecart)
{
	if(distance >= 0)
	{
		creation_texte(RE, to_string((int)round((distance / 10.0)) * 10), arial, GREY, 10, 0, V2f(54 / 2.0, 54 + 30 / 2.0), fenetre, 1, ecart);
		rectangle(V2f(12, 54 + 30 - 1), V2f(13, 2), GREY, RE, fenetre, ecart);
		rectangle(V2f(16, 54 + 30 + 6), V2f(9, 1), GREY, RE, fenetre, ecart);
		rectangle(V2f(16, 54 + 30 + 13), V2f(9, 1), GREY, RE, fenetre, ecart);
		rectangle(V2f(16, 54 + 30 + 22), V2f(9, 1), GREY, RE, fenetre, ecart);
		rectangle(V2f(16, 54 + 30 + 32), V2f(9, 1), GREY, RE, fenetre, ecart);
		rectangle(V2f(12, 54 + 30 + 45), V2f(13, 2), GREY, RE, fenetre, ecart);
		rectangle(V2f(16, 54 + 30 + 59), V2f(9, 1), GREY, RE, fenetre, ecart);
		rectangle(V2f(16, 54 + 30 + 79), V2f(9, 1), GREY, RE, fenetre, ecart);
		rectangle(V2f(16, 54 + 30 + 105), V2f(9, 1), GREY, RE, fenetre, ecart);
		rectangle(V2f(16, 54 + 30 + 152), V2f(9, 1), GREY, RE, fenetre, ecart);
		rectangle(V2f(12, 54 + 30 + 185), V2f(13, 2), GREY, RE, fenetre, ecart);
		if(distance <= 100)
		{
			rectangle(V2f(29 , 85 + 185 * ( 1 - (1.722*pow(10,-3)*distance))), V2f(10, 185 * (1.722*pow(10,-3)*distance)), GREY, RE, fenetre, ecart);
		}
		else if(distance <= 1000)
		{
			rectangle(V2f(29, 186 + 54 + 30 - (185 - 152)), V2f(10, 185 - 152), GREY, RE, fenetre, ecart);
			rectangle(V2f(29 , 85 + 185 * ( 1 - (log(distance*(1/58.8236)) / log(17)))), V2f(10, 185 * (log(distance*(1/58.8236)) / log(17))), GREY, RE, fenetre, ecart);

		}
		else
		{
			rectangle(V2f(29, 186  + 54 + 30 -185), V2f(10, 185), GREY, RE, fenetre, ecart);
		}
	}
}

void Fenetre::couleurForme(VertexArray & bande,Color col, int n)
{
	for(int i = 0; i < n; i++)
	{
		bande[i].color= col;
	}
}

void Fenetre::affichageBoutons(double RE, RenderWindow & fenetre, int * ecart)
{
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);							//F1
	creation_rectangle(V2f(64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);							//F2
	creation_rectangle(V2f(2 *64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);						//F3
	creation_rectangle(V2f(3 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);						//F4
	creation_rectangle(V2f(4 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);						//F5
	creation_rectangle(V2f(5 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);						//F6
	creation_rectangle(V2f(6 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);						//F7
	creation_rectangle(V2f(7 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);						//F8
	creation_rectangle(V2f(8 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);						//F9
	creation_rectangle(V2f(9 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);						//F10
	creation_rectangle(V2f((640 - 40), 28), V2f(40, 64), RE, 2, fenetre, ecart);											//H2
	creation_rectangle(V2f((640 - 40), (28 + 64)), V2f(40, 64), RE, 2, fenetre, ecart);										//H3
	creation_rectangle(V2f((640 - 40), (28 + 2 * 64)), V2f(40, 64), RE, 2, fenetre, ecart);									//H4
	creation_rectangle(V2f((640 - 40), (28 + 3 * 64)), V2f(40, 64), RE, 2, fenetre, ecart);									//H5
	creation_rectangle(V2f((640 - 40), (28 + 4 * 64)), V2f(40, 64), RE, 2, fenetre, ecart);									//H6
	creation_rectangle(V2f((640 - 40), (28 + 5 * 64)), V2f(40, 82), RE, 2, fenetre, ecart);									//H7
}*/