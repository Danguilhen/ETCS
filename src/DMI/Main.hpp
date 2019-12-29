#ifndef MAIN
#define MAIN

#include "define.hpp"
#include "Fenetre.hpp"
#include "Menu.hpp"

class Main : public Menu
{
	public :
		Main(RenderWindow &fenetre, Data &data, ETCS_Bord &bord, vector<Symbol> & symbol, vector<Button> & buttons, string & ecran, string & version);
		void update();
};

#endif