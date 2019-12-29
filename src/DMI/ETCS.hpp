#ifndef ERTMS
#define ERTMS

#include "Data.hpp"
#include "Symbol.hpp"
#include "Button.hpp"
#include "Default.hpp"
#include "define.hpp"
#include "Menu.hpp"
#include "Main.hpp"
#include "Override.hpp"
#include "Special.hpp"

class ETCS : public Fenetre
{
	private :
		string version = "3.6.0";
		string ecran = "Default";
		vector <Symbol> symbol;
		vector <Button> button;
		Event event;
		Default def;
		Main main;
		Override overide;
		Special special;
		//Special special;
		//Settings settings;
		//SRspeed srSpeed;
		//DataView dataView;
		//SystemVersion systemVersion;
		VertexArray fond{Quads,4};
		void action();
	public :
		ETCS(RenderWindow &fenetre, Data &data, ETCS_Bord &bord);
		void update();
};

#endif