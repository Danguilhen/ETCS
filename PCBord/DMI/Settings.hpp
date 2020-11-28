#ifndef SETT
#define SETT

#include "../define.hpp"
#include "Fenetre.hpp"
#include "Menu.hpp"
#include "../Train_dynamique.hpp"

class Settings : public Menu
{
	private :
		Train_dynamique *T_D;
	public :
		Settings(std::vector<Symbol> &symbol, std::vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, std::string &ecran);
		void update();
};



#endif