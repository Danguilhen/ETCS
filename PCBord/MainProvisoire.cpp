
/*
int main()
{
	Clock chrono;//d�but d�mo (delta_t = 0)
	Time difftemps;
	ConvexShape aiguille;	// Creation des formes de l'aiguille de l'IV
	V2f centreIV;						// Position du centre de l'indicateur de Vitesse
	int ecart[] = {0, 0};
	vector<Symbol> symbol(154);
	string version;
	string TTI = "On";
	int LSSMA = 120;
	int speedRange = 400;
	string ecran = "defaultWindow";
	vector<VBC> vbc(20);

	int page = 1;
	int temp_TTI = 0;
	int version_test;

	CircleShape SSI(10 / 2.0 * RE);
	SSI.setFillColor(WHITE);

	//clockMoteurIsole.restart();

    //affiche la fenetre tant que l'utilisateur n'appuie pas sur la croix
    while(fenetre.isOpen())
    {

        difftemps = chrono.getElapsedTime();
        chrono.restart();
        double delta_ts=difftemps.asSeconds();
        if((bord->TrainRI.T_data.getVtrain() > 160 || bord->TrainRI.T_data.getVtrain() == - 1) && version_test != 1)
        {
			demo();
        	calcul(delta_ts);
		}
        if(bord->TrainRI.T_data.getVtrain() < 160 && version_test != 1)
        {
			demo2();
        	calcul(delta_ts);
		}

		//bord->TrainRI.T_data.setVtrain(0);
        gestionnaireAffichage();
		aiguille.setFillColor(data->getCouleurAiguille());
       	fenetre.clear();

		affichageBoutons();

		if(ecran != "trainDataWindow" && ecran != "RBCdataWindow")
		{
			for(int i = 0; i < 154; i++) // reafficher toutes les images
			{
				symbol[i].effacer();
			}
		}
		else
		{
			for(int i = 0; i < 154; i++) // reafficher toutes les images
			{
				symbol[i].effacer();
			}
		}

		if(ecran != "trainDataWindow" && ecran != "RBCdataWindow")
		{

			}
		}

		windows(ecran, symbol, version, vbc, buttons);

		//ST_02.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 / 2.0));	//A4
		//ST_01.afficher(V2f(54 / 2.0, 54 + 30 + 191 + + 25 + 25 + 25 / 2.0));	//C9
		//LE_06.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));	//C1
		//LE_07.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));	//C1
		//LE_08.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));	//C1
		//LE_08a.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));//C1
		//LE_09.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));	//C1
		//LE_09a.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));//C1
		//LE_10.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));	//C1
		//LE_11.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));	//C1
		//LE_12.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));	//C1
		//LE_13.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));	//C1
		//LE_14.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));	//C1
		//LE_15.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));	//C1
		//MO_01.afficher(V2f(54 + 254, 274));	//B7
		//MO_02.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));	//C1
		//MO_04.afficher(V2f(54 + 254, 274));	//B7
		//MO_05.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));	//C1
		//MO_06.afficher(V2f(54 + 254, 274));	//B7
		//MO_07.afficher(V2f(54 + 254, 274));	//B7
		//MO_08.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));	//C1
		//MO_09.afficher(V2f(54 + 254, 274));	//B7
		//MO_10.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));	//C1
		//MO_11.afficher(V2f(54 + 254, 274));	//B7
		//MO_12.afficher(V2f(54 + 254, 274));	//B7
		//MO_13.afficher(V2f(54 + 254, 274));	//B7
		//MO_14.afficher(V2f(54 + 254, 274));	//B7
		//MO_15.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));	//C1
		//MO_16.afficher(V2f(54 + 254, 274));	//B7
		//MO_17.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));	//C1
		//MO_18.afficher(V2f(54 + 254, 274));	//B7
		//MO_20.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));	//C1
		//MO_21.afficher(V2f(54 + 254, 274));	//B7
		//MO_22.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));	//C1

        fenetre->display();
    }
    return 0;
}

// Reste fenetre ------------------------------------------------------------------------------------------------------------



void MainWindow(vector<Symbol> & symbol, string version, vector<Buttons> & boutons, string & ecran);
void specialWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran);
void settingsWindow(vector<Symbol> & symbol, vector<VBC> & vbc, vector<Buttons> & boutons, string & ecran);
void SRspeedWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran);
void dataViewWindows(vector<Symbol> & symbol, string title, vector<Buttons> & boutons, string & ecran, vector<vector<string>> item);
void RBCdataWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran);
void dataViewWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran);
void systemVersionWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran);

void overrideWindow(vector<Symbol> & symbol, string version, vector<Buttons> & boutons, string & ecran);
void adhesionWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran);
void RBCcontactWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran);
void ERTMS_ETCSlevelWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran);
void trainRunningNumberWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran);
void radionetworkIDWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran);
void trainDataWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran);
void brightnessWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran);
void volumeWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran);
void languageWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran);
void windows(string & ecran, vector<Symbol> & symbol, string version, vector<VBC> vbc, vector<Buttons> & boutons);
void driverIDWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran);


void settingsWindow(vector<Symbol> & symbol, vector<VBC> & vbc, vector<Buttons> & boutons, string & ecran)
{
    vector <string> selection(6);
    vector <int> enable(6);
    for (int i = 0; i <= 5; i++)
        enable[i] = 1;
    if ((bord->TrainRI.T_data.getVtrain() == 0 && data->getGeneralMode() == "SB")
        || (data->getGeneralMode() == "SH" || data->getGeneralMode() == "FS" || data->getGeneralMode() == "LS" || data->getGeneralMode() == "SR" ||data->getGeneralMode() == "OS" ||
        data->getGeneralMode() == "NL" || data->getGeneralMode() == "UN" || data->getGeneralMode() == "TR" || data->getGeneralMode() == "PT" || data->getGeneralMode() == "SN" ||
        data->getGeneralMode() == "RV"))
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
    if(bord->TrainRI.T_data.getVtrain() == 0 && data->getGeneralMode() == "SB" && vbc.size() < 20)
    {
        enable[4] = 0;
        boutons[4].settype("up_type");
    }
    else
        boutons[4].settype("delayed");
    if(bord->TrainRI.T_data.getVtrain() == 0 && data->getGeneralMode() == "SB" && vbc.size() > 0)
    {
        enable[5] = 0;
        boutons[5].settype("up_type");
    }
    else
        boutons[5].settype("delayed");
    selection = {"Language", "Volume", "Brightness", "System version", "Set VBC", "Remote VBC"};
    menuWindows(selection, enable, symbol, "Settings");
    if(boutons[11].getactivation())
	{
        page = 1;
        ecran = "defaultWindow";
	}
}


void RBCcontactWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran)
{
    vector <string> selection(4);
    vector <int> enable(4);
    for (int i = 0; i <= 3; i++)
        enable[i] = 1;
    if(bord->TrainRI.T_data.getVtrain() == 0 && data->getDriverID() && (data->getGeneralMode() == "SB" || data->getGeneralMode() == "FS" || data->getGeneralMode() == "LS" || data->getGeneralMode() == "SR" ||
		data->getGeneralMode() == "OS" || data->getGeneralMode() == "NL" || data->getGeneralMode() == "PT") && data->getETATLevelETCS() && (data->getLevel() == "Level 2" ||
		data->getLevel() == "Level 3"))
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
    if(bord->TrainRI.T_data.getVtrain() == 0 && data->getDriverID() && (data->getGeneralMode() == "SB" || data->getGeneralMode() == "FS" || data->getGeneralMode() == "LS" || data->getGeneralMode() == "SR" ||
		data->getGeneralMode() == "OS" || data->getGeneralMode() == "NL" || data->getGeneralMode() == "PT" || data->getGeneralMode() == "UN" || data->getGeneralMode() == "SN") &&
		data->getETATLevelETCS())
    {
         enable[3] = 0;
         boutons[3].settype("up_type");
    }
    else
         boutons[3].settype("delayed");
    selection = {"Contact last RBC", "Use short number", "Enter RBC data", "Radio Network ID"};
    menuWindows(selection, enable, symbol, "RBC contact");
    close(ecran, boutons);
}

void trainRunningNumberWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran)
{
	dataEntryWindows({{"", "", "0"}}, symbol, 0, "Train running number", {}, "numeric", boutons, ecran);
}

void ERTMS_ETCSlevelWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran)
{
	dataEntryWindows({{"", data->getLevel(), ""}}, symbol, 0, "Level", {"Level 1", "Level 2", "Level 3", "Level 0"}, "dedicated keyboard", boutons, ecran);
	if(boutons[0].getactivation())
		data->setLevelETCS("Level 1");
	else if(boutons[1].getactivation())
		data->setLevelETCS("Level 2");
	else if(boutons[2].getactivation())
		data->setLevelETCS("Level 3");
	else if(boutons[3].getactivation())
		data->setLevelETCS("Level 0");
}

void driverIDWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran)
{
    if(boutons[0].getactivation())
		data->setTempDriver_ID(data->getTempDriver_ID() * 10 + 1);
    else if(boutons[1].getactivation())
        data->setTempDriver_ID(data->getTempDriver_ID()  * 10 + 2);
    else if(boutons[2].getactivation())
        data->setTempDriver_ID(data->getTempDriver_ID() * 10 + 3);
    else if(boutons[3].getactivation())
        data->setTempDriver_ID(data->getTempDriver_ID()  * 10 + 4);
    else if(boutons[4].getactivation())
        data->setTempDriver_ID(data->getTempDriver_ID() * 10 + 5) ;
    else if(boutons[5].getactivation())
        data->setTempDriver_ID(data->getTempDriver_ID() * 10 + 6);
    else if(boutons[6].getactivation())
        data->setTempDriver_ID(data->getTempDriver_ID()  * 10 + 7);
    else if(boutons[7].getactivation())
        data->setTempDriver_ID(data->getTempDriver_ID()  * 10 + 8);
    else if(boutons[8].getactivation())
        data->setTempDriver_ID(data->getTempDriver_ID()  * 10 + 9);
    else if(boutons[9].getactivation())
        data->setTempDriver_ID(data->getTempDriver_ID()  * 10 + 0);
    else if(boutons[10].getactivation())
        data->setTempDriver_ID(ceil(data->getTempDriver_ID() /10));
    else if(boutons[12].getactivation())
        data->setTempDriver_ID(data->getDriver_ID());
    else if(boutons[15].getactivation())
    {
        data->setDriver_ID(data->getTempDriver_ID());
        dataEntryWindows({{"", to_string(data->getDriver_ID()), "1"}}, symbol, 0, "Driver ID", {}, "alphanumeric", boutons, ecran);
    }
	//if(data->getTempDriver_ID() == 0)
	//	dataEntryWindows({{"", "", "0"}}, symbol, 0, "Driver ID", {}, "alphanumeric", boutons, ecran);
	//else
	dataEntryWindows({{"", to_string(data->getTempDriver_ID()), "0"}}, symbol, 0, "Driver ID", {}, "alphanumeric", boutons, ecran);
}

void radionetworkIDWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran)
{
	dataEntryWindows({{"", data->getRadioNetworkID(), "0"}}, symbol, 0, "Radio network ID", {}, "dedicated keyboard", boutons, ecran);
	if(boutons[0].getactivation())
		data->setRadioNetworkID("GSMR-A");
	else if(boutons[1].getactivation())
		data->setRadioNetworkID("GSMR-B");
	else if(boutons[1].getactivation())
		data->setRadioNetworkID("Telecom X");
}

void RBCdataWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran)
{
    int i = 0;
    if(page == 1)
    {
        if(boutons[0].getactivation())
            data->setTempRBCID(data->getTempRBCID() * 10 + 1);
        else if(boutons[1].getactivation())
            data->setTempRBCID(data->getTempRBCID() * 10 + 2);
        else if(boutons[2].getactivation())
            data->setTempRBCID(data->getTempRBCID() * 10 + 3);
        else if(boutons[3].getactivation())
            data->setTempRBCID(data->getTempRBCID() * 10 + 4);
        else if(boutons[4].getactivation())
            data->setTempRBCID(data->getTempRBCID() * 10 + 5);
        else if(boutons[5].getactivation())
            data->setTempRBCID(data->getTempRBCID() * 10 + 6);
        else if(boutons[6].getactivation())
            data->setTempRBCID(data->getTempRBCID() * 10 + 7);
        else if(boutons[7].getactivation())
            data->setTempRBCID(data->getTempRBCID() * 10 + 8);
        else if(boutons[8].getactivation())
            data->setTempRBCID(data->getTempRBCID() * 10 + 9);
        else if(boutons[9].getactivation())
            data->setTempRBCID(data->getTempRBCID() * 10 + 0);
        else if(boutons[10].getactivation())
            data->setTempRBCID(ceil(data->getTempRBCID()/10));
        else if (boutons[13].getactivation() || boutons[14].getactivation() || boutons[12].getactivation())
        {
            data->setTempRBCID(data->getRBCID());
            i = 1;
            dataEntryWindows({{"RBC ID", to_string(data->getRBCID()), "0"}, {"RBC phone number", to_string(data->getRBCphoneNumber()), "0"}}, symbol, 1, "RBC data", {},
				"numeric", boutons, ecran);
        }
        else if(boutons[15].getactivation())
        {
            data->setRBCID(data->getTempRBCID());
            page++;
            i = 1;
            dataEntryWindows({{"RBC ID", to_string(data->getRBCID()), "1"}, {"RBC phone number", to_string(data->getRBCphoneNumber()), "0"}}, symbol, 1, "RBC data", {},
				"numeric", boutons, ecran);
        }
        if(i ==0)
		{
			if(data->getTempRBCID() == 0)
				dataEntryWindows({{"RBC ID", "", "0"}, {"RBC phone number", to_string(data->getRBCphoneNumber()), "0"}}, symbol, 1, "RBC data", {}, "numeric", boutons,
					ecran);
			else
				dataEntryWindows({{"RBC ID", to_string(data->getTempRBCID()), "0"}, {"RBC phone number", to_string(data->getRBCphoneNumber()), "0"}}, symbol, 1, "RBC data", {},
					"numeric", boutons, ecran);
		}
    }
    else
    {
        if(boutons[0].getactivation())
            data->setTempRBCphoneNumber(data->getTempRBCphoneNumber() * 10 + 1);
        else if(boutons[1].getactivation())
            data->setTempRBCphoneNumber(data->getTempRBCphoneNumber() * 10 + 2);
        else if(boutons[2].getactivation())
            data->setTempRBCphoneNumber(data->getTempRBCphoneNumber() * 10 + 3);
        else if(boutons[3].getactivation())
            data->setTempRBCphoneNumber(data->getTempRBCphoneNumber() * 10 + 4);
        else if(boutons[4].getactivation())
            data->setTempRBCphoneNumber(data->getTempRBCphoneNumber() * 10 + 5);
        else if(boutons[5].getactivation())
            data->setTempRBCphoneNumber(data->getTempRBCphoneNumber() * 10 + 6);
        else if(boutons[6].getactivation())
            data->setTempRBCphoneNumber(data->getTempRBCphoneNumber() * 10 + 7);
        else if(boutons[7].getactivation())
            data->setTempRBCphoneNumber(data->getTempRBCphoneNumber() * 10 + 8);
        else if(boutons[8].getactivation())
            data->setTempRBCphoneNumber(data->getTempRBCphoneNumber() * 10 + 9);
        else if(boutons[9].getactivation())
            data->setTempRBCphoneNumber(data->getTempRBCphoneNumber() * 10 + 0);
        else if(boutons[10].getactivation())
            data->setTempRBCphoneNumber(ceil(data->getTempRBCphoneNumber()/10));
        else if (boutons[13].getactivation() || boutons[14].getactivation() || boutons[14].getactivation())
        {
            data->setTempRBCphoneNumber(data->getRBCphoneNumber());
            i = 1;
            dataEntryWindows({{"RBC ID", to_string(data->getRBCID()), "0"}, {"RBC phone number", to_string(data->getRBCphoneNumber()), "0"}}, symbol, 1, "RBC data", {},
				"numeric", boutons, ecran);
        }
        else if(boutons[15].getactivation())
        {
            data->setRBCphoneNumber(data->getTempRBCphoneNumber());
            page--;
            i = 1;
            dataEntryWindows({{"RBC ID", to_string(data->getRBCID()), "1"}, {"RBC phone number", to_string(data->getRBCphoneNumber()), "0"}}, symbol, 1, "RBC data", {},
				"numeric", boutons, ecran);
        }

       if(i ==0)
		{
			if(data->getTempRBCphoneNumber() == 0)
				dataEntryWindows({{"RBC ID", to_string(data->getRBCID()), "0"}, {"RBC phone number", "", "0"}}, symbol, 1, "RBC data", {}, "numeric", boutons, ecran);
			else
				dataEntryWindows({{"RBC ID", to_string(data->getRBCID()), "0"}, {"RBC phone number", to_string(data->getTempRBCphoneNumber()), "0"}}, symbol, 1, "RBC data", {},
					"numeric", boutons, ecran);

		}
	}
}


void languageWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran)
{
	dataEntryWindows({{"", data->getLanguage(), "0"}}, symbol, 0, "Language", {"English", "Francais"}, "dedicated keyboard", boutons, ecran);
	if(boutons[0].getactivation())
		data->setLanguage("English");
	else if(boutons[1].getactivation())
		data->setLanguage("Francais");
}

void volumeWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran)
{
	dataEntryWindows({{""}}, symbol, 0, "Volume", {}, "", boutons, ecran);
}

void brightnessWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran)
{
	dataEntryWindows({{""}}, symbol, 0, "Brightness", {}, "", boutons, ecran);
}

void trainDataWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran)
{
	vector<vector<string>> input_field = {{"Train category", data->getTrain_category(), "0"}, {"Length (m)", to_string(data->getlength()), "1"}, {"Brake percentage",
		to_string(data->getbreaking_percetage()), "0"}, {"Max speed (km/h)", to_string(data->getmaximum_train_speed()), "0"}, {"Axle load category",
		data->getaxle_load_category(), "0"}, {"Airtight", data->getAirtight(), "0"}, {"Loading gauge", data->getloading_gauge(), "0"}};
	vector <string> selection = {};
	string keyboard = "";
	//if(page == 1)
	//
	//if(page == 2)
	//
	//if(page == 3)
	//
	//if(page == 4)
	//
	//if(page == 5)
	//
	//if(page == 6)
	//
	//if(page == 7)
	//
	dataEntryWindows(input_field, symbol, 1, "Train data", selection, keyboard, boutons, ecran);
	for(int i = 0; i < int(input_field.size()); i++)
		creation_texte(input_field[i][0], GREY, 12, 0, V2f(204 - 5, 20 * i + 100 + 6), 2);
}

void SRspeedWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran)
{
    dataEntryWindows({{"SR speed (km/h)", to_string(data->getSRspeed()), "0"}, {"SR distance (m)", "b", "0"}}, symbol, 0, "SR speed/distance", {}, "numeric", boutons,
		ecran);
	if(boutons[0].getactivation())
		data->setSRspeed(data->getSRspeed() * 10 + 1);
	else if(boutons[1].getactivation())
		data->setSRspeed(data->getSRspeed() * 10 + 2);
	else if(boutons[2].getactivation())
		data->setSRspeed(data->getSRspeed() * 10 + 3);
	else if(boutons[3].getactivation())
		data->setSRspeed(data->getSRspeed() * 10 + 4);
	else if(boutons[4].getactivation())
		data->setSRspeed(data->getSRspeed() * 10 + 5);
	else if(boutons[5].getactivation())
		data->setSRspeed(data->getSRspeed() * 10 + 6);
	else if(boutons[6].getactivation())
		data->setSRspeed(data->getSRspeed() * 10 + 7);
	else if(boutons[7].getactivation())
		data->setSRspeed(data->getSRspeed() * 10 + 8);
	else if(boutons[8].getactivation())
		data->setSRspeed(data->getSRspeed() * 10 + 9);
	else if(boutons[9].getactivation())
		data->setSRspeed(data->getSRspeed() * 10 + 0);
}

void adhesionWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran)
{
	dataEntryWindows({{"", data->getAdhesion(),"0"}}, symbol, 0, "Adhesion", {"Non slippery rail","Slippery rail"}, "dedicated keyboard", boutons, ecran);
	if(boutons[0].getactivation())
		data->setAdhesion("Non slippery rail");
	else if(boutons[1].getactivation())
		data->setAdhesion("Slippery rail");
}

void dataViewWindows(vector<Symbol> & symbol, string title, vector<Buttons> & boutons, string & ecran, vector<vector<string>> item)
{
	rectangle(V2f(54 + 280, 0), V2f(266, 24), BLACK);
	if(title == "Data View")
		title += " (" + to_string(page) + "/2)";
	creation_texte(title, GREY, 17, 0, V2f(54 + 280 + 3, 12), 4);
	for(int i = 0; i <= int(item.size()) - 1; i++)
	{
		creation_texte(item[i][0], GREY, 17, 0, V2f(280 + 54 + 176 - 5, 60 + 17 / 2.0 + i * 22), 2);
		creation_texte(item[i][1], GREY, 17, 0, V2f(280 + 54 + 176 + 5, 60 + 17 / 2.0 + i * 22), 4);
	}
	if(page == 1)
	{
		NA_11.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0));		//H3
		boutons[11].settype("up_type");
		close(ecran, boutons);
	}
	else if(page == 2)
	{
		NA_18.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0));		//H3
		boutons[11].settype("up_type");
		if(boutons[11].getactivation())
			page--;
	}
	if(page == 2)
	{
		NA_18_2.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2+ 64 / 2.0));	//H4
		boutons[12].settype("disabled");
	}
	else if(page == 1)
	{
		boutons[12].settype("up_type");
		NA_17.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2+ 64 / 2.0));	//H4
		if(boutons[12].getactivation())
			page++;
	}
}

void dataViewWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran)
{
    vector<vector<string>> item;
    if(page == 1)
    	item = {{"Driver ID", to_string(data->getDriver_ID())}, {"", ""},{"Train running number", to_string(data->getTrain_running_number()) },
			{"", ""}, {"Train type", data->getTrain_type()}, {"Train category", data->getTrain_category()}, {"Length (m)", to_string(data->getlength())},
			{"Brake percentage", to_string(data->getbreaking_percetage())}, {"Max speed (km/h)", to_string(data->getmaximum_train_speed())},
			{"Axle load category", data->getaxle_load_category()}, {"Airtight", data->getAirtight()}, {"Loading gauge", data->getloading_gauge()}};
    else
    	item = {{"Radio network ID", data->getRadioNetworkID()}, {"RBC ID", to_string(data->getRBCID())}, {"RBC phone number", to_string(data->getRBCphoneNumber())}, {"", ""},
		{"VBC #1 set code", "d"}, {"VBC #2 set code", "e"}};
    dataViewWindows(symbol, "Data View", boutons, ecran, item);
}

void systemVersionWindow(vector<Symbol> & symbol, vector<Buttons> & boutons, string & ecran)
{
	vector<vector<string>> item = {{"Operated system version", ""}};
	dataViewWindows(symbol, "System version", boutons, ecran, item);
}

void windows(string & ecran, vector<Symbol> & symbol, string version, vector<VBC> vbc, vector<Buttons> & boutons)
{
    if(ecran == "mainWindow")
        MainWindow(symbol, version, boutons, ecran);
    else if(ecran == "overrideWindow")
        overrideWindow(symbol, version, boutons, ecran);
    else if(ecran == "specialWindow")
        specialWindow(symbol, boutons, ecran);
    else if(ecran == "settingsWindow")
        settingsWindow(symbol, vbc, boutons, ecran);
    else if(ecran == "RBCcontactWindow")
        RBCcontactWindow(symbol, boutons, ecran);
    else if(ecran == "trainRunningNumberWindow")
        trainRunningNumberWindow(symbol, boutons, ecran);
    else if(ecran == "ERTMS_ETCSlevelWindow")
        ERTMS_ETCSlevelWindow(symbol, boutons, ecran);
    else if(ecran == "driverIDWindow")
        driverIDWindow(symbol, boutons, ecran);
    else if(ecran == "radionetworkIDWindow")
        radionetworkIDWindow(symbol, boutons, ecran);
    else if(ecran == "RBCdataWindow")
        RBCdataWindow(symbol, boutons, ecran);
    else if(ecran == "languageWindow")
        languageWindow(symbol, boutons, ecran);
    else if(ecran == "volumeWindow")
        volumeWindow(symbol, boutons, ecran);
    else if(ecran == "brightnessWindow")
        brightnessWindow(symbol, boutons, ecran);
    else if(ecran == "SRspeed/distanceWindow")
        SRspeedWindow(symbol, boutons, ecran);
    else if(ecran == "adhesionWindow")
        adhesionWindow(symbol, boutons, ecran);
    else if(ecran == "trainDataWindow")
        trainDataWindow(symbol, boutons, ecran);
    else if(ecran == "dataViewWindow")
        dataViewWindow(symbol, boutons, ecran);
    else if(ecran == "systemVersionWindow")
        systemVersionWindow(symbol, boutons, ecran);
}


void close(string & ecran, vector<Buttons> & boutons)
{
    if(boutons[11].getactivation())
        page = 1;
    if(boutons[11].getactivation() && (ecran == "dataViewWindow"))
        ecran = "defaultWindow";
    else if(boutons[11].getactivation() && (ecran == "languageWindow" || ecran == "volumeWindow" || ecran == "brightnessWindow"))
        ecran = "settingsWindow";
    else if(boutons[11].getactivation() && (ecran == "driverIDWindow" || ecran == "trainDataWindow" || ecran == "trainRunningNumberWindow" || ecran == "RBCdataWindow" ||
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
}*/