#ifndef Basic
#define Basic

#include "Data.hpp"
#include "Cadran.hpp"
#include "define.hpp"
#include "Tools.hpp"

class BASIC : public Tools
{
	protected :

		Cadran cadran;
		Event event;
		VertexArray fond{Quads,4};
	public :
		BASIC(Train_dynamique &T_D, Software &soft);
		void update();
		void Basic_action();
		void fond_ecran();
		void affichageBoutons();
};

#endif