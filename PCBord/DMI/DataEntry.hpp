#ifndef DE
#define DE

#include "../define.hpp"
#include "Fenetre.hpp"
#include "Symbol.hpp"
#include "LeftSide.hpp"
#include "Button.hpp"

class DataEntry : public Fenetre
{
	protected :
		LeftSide left;
		Train_dynamique *T_D;
		double clignotement = 0;
		int sel = 1;
		DataEntry(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, string &ecran);
		void dataEntry(vector<vector<string>> input_field, int complete, string title, vector<string> selection, string keyboard);
};

#endif