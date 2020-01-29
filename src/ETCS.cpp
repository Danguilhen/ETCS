#include "ETCS.hpp"

ETCS::ETCS(Software &soft, Train_dynamique &T_D) : Bord(T_D), EDMI(soft, Bord, T_D)// Constructeur avec pointeur sur software
{
	//cout<< "ETCS" <<endl;
	//constructeur
}

void ETCS::ETCS_uptade() // Update des fonctions calculs et affichages de ETCS
{
	EDMI.update();
	Bord.bord_update();
}
