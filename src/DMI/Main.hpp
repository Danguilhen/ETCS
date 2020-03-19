#ifndef MAIN
#define MAIN

#include "define.hpp"
#include "Fenetre.hpp"
#include "Menu.hpp"
#include "Train_dynamique.hpp"


class Main : public Menu
{
	private :
	Train_dynamique *T_D;


	public :
		Main(std::vector<Symbol> &symbol, std::vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, std::string &ecran);
		void update();
};

#endif