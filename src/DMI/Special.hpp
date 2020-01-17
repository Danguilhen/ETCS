#ifndef SPECIAL
#define SPECIAL

#include "define.hpp"
#include "Fenetre.hpp"
#include "Menu.hpp"

class Special : public Menu
{
	private :

		Train_dynamique *T_D;

	public :
		Special(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, string &ecran);
		void update();
};

#endif