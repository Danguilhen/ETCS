#include "Menu.hpp"

Menu::Menu(Data &data, vector<Symbol> &symbol, ETCS_Bord &bord)
{
	this->data = &data;
	this->symbol = &symbol;
	this->bord = &bord;
}

void Menu::menu(vector <string> selection, vector <int>& enable, string title)
{
	Color color;
	rectangle(V2f(54 + 280, 0), V2f(266, 24), BLACK);
	NA_11.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0));	//H5
	for(int i = 0; i < (int)selection.size(); i++)
	{
		if(enable[i] == 0)
			color = GREY;
		else if(enable[i] == 1)
			color = DARK_GREY;
		if(enable[i] != 2)
		{
			creation_texte(to_string(i + 1) + " - " + selection[i], color, 12, 0, V2f(54 + 280 + 15, 100 + 6 + i * 20), 4);
			creation_texte(to_string(i + 1), color, 16, 0, V2f(64 / 2.0 + i * 64, 430 + 50 / 2.0), 1);
		}
	}
	creation_texte(title, GREY, 12, 0, V2f(54 + 280 + 3, 12), 4);
}