#ifndef MENU
#define MENU

#include "../define.hpp"
#include "Fenetre.hpp"
#include "Symbol.hpp"
#include "LeftSide.hpp"
#include "Button.hpp"

class Menu : public Fenetre
{
	protected :
		LeftSide left;
		vector <Button> *buttons;
		int page = 1;
		Menu(vector<Symbol> &symbol, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D);
		void menu(vector <string> selection, vector <int>& enable, string title);
};

#endif