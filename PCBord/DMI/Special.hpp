#ifndef SPECIAL
#define SPECIAL

#include "../define.hpp"
#include "Fenetre.hpp"
#include "Menu.hpp"

class Special : public Menu
{
	private :

		Train_dynamique *T_D;

	public :
		Special(std::vector<Symbol> &symbol, std::vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, std::string &ecran);
		void update();
};

#endif