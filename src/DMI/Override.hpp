#ifndef OVERRIDE
#define OVERRIDE

#include "define.hpp"
#include "Fenetre.hpp"
#include "Menu.hpp"

class Override : public Menu
{
	private :

	Train_dynamique *T_D;
	public :
		Override(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, string &ecran);
		void update();
};

#endif