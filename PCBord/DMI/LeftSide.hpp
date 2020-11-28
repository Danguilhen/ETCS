#ifndef LS
#define LS

#include "Cadran.hpp"
#include "Symbol.hpp"

class LeftSide : public virtual Tools
{
	private :
		Cadran cadran;
		std::vector <Symbol> *symbol;
		ETCS_Bord *bord;

	public :
		LeftSide(vector<Symbol> &symbol, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D);
		void update();
		void targetDistance(int distance);
};

#endif