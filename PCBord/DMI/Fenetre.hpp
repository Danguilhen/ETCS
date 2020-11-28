#ifndef FENETRE
#define FENETRE

#include "../Tools.hpp"
#include "../define.hpp"
#include "../Bord/ETCS_Bord.hpp"
#include "Symbol.hpp"
#include "Button.hpp"

class Fenetre : public virtual Tools
{
	protected :
		std::vector <Symbol> *symbol;
		ETCS_Bord *bord;
		std::string *ecran;
		std::vector <Button> *buttons;
		int page = 1;
		void affichageBoutons();
		void close();
};

#endif