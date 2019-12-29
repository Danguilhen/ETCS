#ifndef MAIN
#define MAIN

#include "define.hpp"
#include "Button.hpp"
#include "Fenetre.hpp"
#include "LeftSide.hpp"
#include "Menu.hpp"

class Main : public Menu
{
	private :
		vector <Button> *buttons;
		string *version;
	public :
		Main(RenderWindow &fenetre, Data &data, ETCS_Bord &bord, vector<Symbol> & symbol, vector<Button> & buttons, string & ecran, string & version);
		void update();
};

#endif