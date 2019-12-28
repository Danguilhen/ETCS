#ifndef MENU
#define MENU

#include "../define.hpp"
#include "Fenetre.hpp"
#include "Symbol.hpp"

class Menu : public Fenetre
{
	protected :
		Data *data;
		RenderWindow *fenetre;
		vector <Symbol> *symbol;
		Menu(Data &data, vector<Symbol> &symbol, ETCS_Bord &bord);
		void menu(vector <string> selection, vector <int>& enable, string title);
};

#endif