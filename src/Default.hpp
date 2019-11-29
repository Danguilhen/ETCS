#ifndef DEFAULT
#define DEFAULT

#include "Fenetre.hpp"
#include "LeftSide.hpp"
#include "Symbol.hpp"
#include "Button.hpp"
#include "ETCS_Bord.hpp"

class Default : public Fenetre, public LeftSide
{
	private :
		vector <Symbol> *symbol;
		vector <Button> *buttons;
		string *ecran;
		//Planning planning;
		string geographicalPosition;
		string S_D_monitoring = "Off";
		string planningAffichage = "show planning information";
		Cadran cadran;
	public :
		Default(RenderWindow &fenetre, Data &data, vector<Symbol> &symbol, vector<Button> &buttons, ETCS_Bord &bord);
		void update();
};

#endif