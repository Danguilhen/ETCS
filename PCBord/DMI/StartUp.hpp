#ifndef ST
#define ST

#include "../define.hpp"
#include "DriverID.hpp"
#include "Button.hpp"
#include "Symbol.hpp"
#include "../Software.hpp"
#include "../Bord/ETCS_Bord.hpp"
#include "../Train_dynamique.hpp"
#include "TrainRunningNumberWindow.hpp"
#include "Settings.hpp"
#include "ERTMS_ETCSlevel.hpp"


class StartUp
{
	private :
		std::string status_STU = "S1";
		DriverID_window Driver_DMI;
		TrainRunningNumberWindow TRN_DMI;
		Settings Set_DMI;
		ERTMS_ETCSlevel level_DMI;
		std::string *ecran;
		std::vector <Button> *buttons;
		ETCS_Bord *bord;

	public :

	StartUp(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, string &ecran);
	void update();

};


#endif
