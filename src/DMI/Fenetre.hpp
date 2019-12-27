#ifndef FENETRE
#define FENETRE

#include "Tools.hpp"
#include "define.hpp"
#include "Bord/ETCS_Bord.hpp"

class Fenetre : public virtual Tools
{
	protected :
		ETCS_Bord *bord;
		void affichageBoutons();
};

#endif