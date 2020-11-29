#ifndef DEFTVM
#define DEFTVM

#include "Fenetre.hpp"
#include "LeftSide.hpp"
#include "Symbol.hpp"
#include "Button.hpp"
#include "../Bord/ETCS_Bord.hpp"
#include "../Bord/TVM_Bord.hpp"
#include "Planning.hpp"

class DefaultTVM : public Fenetre
{
	private :
		LeftSide left;
		TVM_Bord *TVM;
		std::vector <Button> *buttons;
		Planning planning;
		std::string geographicalPosition;
		std::string S_D_monitoring = "Off";
		std::string planningAffichage = "show planning information";
	    string indication="";
		bool sect = 0;
		bool bp = 0;

		Time periodeClignotement = seconds(0.65f);
		float floatdeux = 2;

		Clock clockTVM;
	public :
		DefaultTVM(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, std::string & ecran, TVM_Bord &TVM);
		void update();
};

#endif