#ifndef LS
#define LS

#include "Cadran.hpp"
#include "Symbol.hpp"

class LeftSide : public virtual Tools
{
	private :
		Cadran cadran;
		vector <Symbol> *symbol;
		ETCS_Bord *bord;
		void targetDistance(int distance);
	public :
		LeftSide(vector<Symbol> &symbol, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D);
		void update();
};

#endif