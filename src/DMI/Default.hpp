#ifndef DEF
#define DEF

#include "Fenetre.hpp"
#include "LeftSide.hpp"
#include "Symbol.hpp"
#include "Button.hpp"
#include "Bord/ETCS_Bord.hpp"
#include "Planning.hpp"

class Default : public Fenetre
{
	private :
		LeftSide left;
		vector <Button> *buttons;
		Planning planning;
		string geographicalPosition;
		string S_D_monitoring = "Off";
		string planningAffichage = "show planning information";
	public :
		Default(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, string &ecran);
		void update();
};

#endif