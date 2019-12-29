#ifndef FENETRE
#define FENETRE

#include "Tools.hpp"
#include "define.hpp"
#include "Bord/ETCS_Bord.hpp"
#include "Symbol.hpp"

class Fenetre : public virtual Tools
{
	protected :
		vector <Symbol> *symbol;
		ETCS_Bord *bord;
		string *ecran;
		void affichageBoutons();
};

#endif