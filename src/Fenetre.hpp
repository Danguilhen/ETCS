#ifndef FENETRE
#define FENETRE

#include "Tools.hpp"
#include "define.hpp"

class Fenetre : public virtual Tools
{
	protected :
		void creation_rectangle(V2f pos, V2f dim, int mode);
		void affichageBoutons();
};

#endif