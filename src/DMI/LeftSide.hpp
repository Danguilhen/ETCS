#ifndef LS
#define LS

#include "Cadran.hpp"
#include "Symbol.hpp"

class LeftSide : public virtual Tools
{
	protected :
		Cadran cadran;
		vector <Symbol> *symbol;
		void targetDistance(int distance);
		LeftSide(Data &data, RenderWindow &fenetre, ETCS_Bord &bord, vector<Symbol> &symbol);
		void leftSide();
};

#endif