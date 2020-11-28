#include "Fenetre.hpp"

void Fenetre::affichageBoutons()
{
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);			//F1
	creation_rectangle(V2f(64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);			//F2
	creation_rectangle(V2f(2 *64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F3
	creation_rectangle(V2f(3 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F4
	creation_rectangle(V2f(4 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F5
	creation_rectangle(V2f(5 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F6
	creation_rectangle(V2f(6 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F7
	creation_rectangle(V2f(7 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F8
	creation_rectangle(V2f(8 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F9
	creation_rectangle(V2f(9 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F10
	creation_rectangle(V2f((640 - 40), 28), V2f(40, 64), 2);							//H2
	creation_rectangle(V2f((640 - 40), (28 + 64)), V2f(40, 64), 2);						//H3
	creation_rectangle(V2f((640 - 40), (28 + 2 * 64)), V2f(40, 64), 2);					//H4
	creation_rectangle(V2f((640 - 40), (28 + 3 * 64)), V2f(40, 64), 2);					//H5
	creation_rectangle(V2f((640 - 40), (28 + 4 * 64)), V2f(40, 64), 2);					//H6
	creation_rectangle(V2f((640 - 40), (28 + 5 * 64)), V2f(40, 82), 2);					//H7
}

void Fenetre::close()
{
	if((*buttons)[11].getactivation()) // ?
        page = 1;
    if((*buttons)[11].getactivation() && (*ecran == "Main" || *ecran == "Override" || *ecran == "Special" || *ecran == "Settings"|| *ecran == "dataView") && bord->getGeneralMode()!="TVM")
        *ecran = "Default";
	else if ((*buttons)[11].getactivation() && (*ecran == "Main" || *ecran == "Override" || *ecran == "Special" || *ecran == "Settings" || *ecran == "dataView") && bord->getGeneralMode() == "TVM")
		*ecran = "DefaultTVM";
    else if((*buttons)[11].getactivation()&& (*ecran == "languageWindow" || *ecran == "volumeWindow" || *ecran == "brightnessWindow"))
        *ecran = "Settings";
    else if((*buttons)[11].getactivation()&& (*ecran == "DriverID" || *ecran == "trainDataWindow" || *ecran == "trainRunningNumberWindow" || *ecran == "RBCdataWindow" ||
		*ecran == "ERTMS_ETCSlevelWindow"))
        {
            *ecran = "Main";
            (*buttons)[3].settype("disabled");
			(*buttons)[10].settype("disabled");
			(*buttons)[12].settype("disabled");
			(*buttons)[13].settype("disabled");
			(*buttons)[14].settype("disabled");
			(*buttons)[15].settype("disabled");
        }
    else if((*buttons)[11].getactivation()&& (*ecran == "adhesionWindow" || *ecran == "SRspeed/distanceWindow"))
        *ecran = "Special";
}