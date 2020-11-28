#include "Menu.hpp"

Menu::Menu(vector<Symbol> &symbol, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D): left(symbol, soft, bord, T_D)
{
	//cout<< "MENU" <<endl;
	this->soft = &soft;
	this->bord = &bord;
	this->symbol = &symbol;
}

void Menu::menu(vector <string> selection, vector <int>& enable, string title)
{
	left.update();
	Color color;
	rectangle(V2f(54 + 280, 0), V2f(266, 24), BLACK); // rectangle titre
	NA_11.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0));	//H5
	for(int i = 0; i < (int)selection.size(); i++)
	{
		if(enable[i] == 0)
			color = GREY;
		else if(enable[i] == 1)
			color = DARK_GREY;
		if(enable[i] != 2)
		{
			creation_texte(to_string(i + 1) + " - " + selection[i], color, 12, 0.0f, V2f(static_cast<float>(54 + 280 + 15), static_cast<float>(100 + 6 + i * 20)), 4);
			creation_texte(to_string(i + 1), color, 16, 0.0f, V2f(static_cast<float>(64 / 2.0 + i * 64), static_cast<float>(430 + 50 / 2.0)), 1);
		}
	}
	creation_texte(title, GREY, 12, 0, V2f(54 + 280 + 3, 12), 4);
}