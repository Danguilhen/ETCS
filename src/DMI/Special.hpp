#ifndef SPECIAL
#define SPECIAL

#include "define.hpp"
#include "Fenetre.hpp"
#include "Menu.hpp"

class Special : public Menu
{
	public :
		Special(RenderWindow &fenetre, Data &data, ETCS_Bord &bord, vector<Symbol> & symbol, vector<Button> & buttons, string & ecran, string & version);
		void update();
};

#endif