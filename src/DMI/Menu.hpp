#ifndef MENU
#define MENU

#include "../define.hpp"
#include "Fenetre.hpp"
#include "Symbol.hpp"
#include "LeftSide.hpp"

class Menu : public Fenetre
{
	protected :
		LeftSide left;
		int page = 1;
		Menu(Data &data, vector<Symbol> &symbol, ETCS_Bord &bord, RenderWindow & fenetre);
		void menu(vector <string> selection, vector <int>& enable, string title);
};

#endif