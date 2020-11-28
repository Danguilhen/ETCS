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
		Menu(std::vector<Symbol> &symbol, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D);
		void menu(std::vector <string> selection, std::vector <int>& enable, std::string title);
};

#endif