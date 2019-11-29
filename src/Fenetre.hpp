#ifndef FENETRE
#define FENETRE

#include "Tools.hpp"
#include "define.hpp"
#include "ETCS_Bord.hpp"

class Fenetre : public virtual Tools
{
	protected :
		ETCS_Bord *bord;
		void creation_rectangle(V2f pos, V2f dim, int mode);
		void affichageBoutons();
};

#endif