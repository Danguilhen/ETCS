#ifndef OVERRIDE
#define OVERRIDE

#include "define.hpp"
#include "Fenetre.hpp"
#include "Menu.hpp"

class Override : public Menu
{
	public :
		Override(RenderWindow &fenetre, Data &data, ETCS_Bord &bord, vector<Symbol> & symbol, vector<Button> & buttons, string & ecran, string & version);
		void update();
};

#endif