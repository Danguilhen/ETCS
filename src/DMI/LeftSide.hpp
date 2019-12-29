#ifndef LS
#define LS

#include "Cadran.hpp"
#include "Symbol.hpp"

class LeftSide : public virtual Tools
{
	private :
		Cadran cadran;
		vector <Symbol> *symbol;
		void targetDistance(int distance);
	public :
		LeftSide(Data &data, RenderWindow &fenetre, ETCS_Bord &bord, vector<Symbol> &symbol);
		void update();
};

#endif