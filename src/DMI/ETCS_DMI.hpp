#ifndef ERTMS
#define ERTMS

#include "Symbol.hpp"
#include "Button.hpp"
#include "Default.hpp"
#include "define.hpp"
#include "Menu.hpp"
#include "Main.hpp"
#include "Override.hpp"
#include "Special.hpp"


class ETCS_DMI : public Fenetre
{
	private :
		std::string etat_ecran = "Default";
		std::vector <Symbol> symbol;
		std::vector <Button> button;
		Train_dynamique *T_D;
		sf::Event event;
		Default def;
		Main main;
		Override overide;
		Special special;
		//Special special;
		//Settings settings;
		//SRspeed srSpeed;
		//DataView dataView;
		//SystemVersion systemVersion;
		sf::VertexArray fond{Quads,4};
		void action();
	public :
		ETCS_DMI(Software &soft, ETCS_Bord &bord, Train_dynamique &T_D);
		void update();
		void affichage();
};

#endif