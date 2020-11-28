#ifndef OVERRIDE
#define OVERRIDE

#include "../define.hpp"
#include "Fenetre.hpp"
#include "Menu.hpp"

class Override : public Menu
{
	private :

	Train_dynamique *T_D;
	public :
		Override(std::vector<Symbol> &symbol, std::vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, std::string &ecran);
		void update();
};

#endif