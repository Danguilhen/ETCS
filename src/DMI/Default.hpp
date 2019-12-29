#ifndef DEFAULT
#define DEFAULT

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
		Default(RenderWindow &fenetre, Data &data, vector<Symbol> &symbol, vector<Button> &buttons, ETCS_Bord &bord, string & ecran);
		void update();
};

#endif