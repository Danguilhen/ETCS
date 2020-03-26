/*#ifndef DE
#define DE

#include "define.hpp"
#include "Fenetre.hpp"
#include "Symbol.hpp"
#include "LeftSide.hpp"
#include "Button.hpp"

class DataEntry : public Fenetre
{
	protected :
		LeftSide left;
		std::vector <Button> *buttons;
		DataEntry(std::vector<Symbol> &symbol, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D);
		void dataEntry(vector<vector<string>> input_field, vector<Symbol> & symbol, int complete, string title, vector<string> selection, int & sel, string keyboard, vector<Button> & boutons, string & ecran);
};

#endif*/