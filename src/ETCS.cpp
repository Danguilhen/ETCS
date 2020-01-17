#include "ETCS.hpp"

ETCS::ETCS(Software &soft, Train_dynamique &T_D) : bord(T_D), EDMI(soft, bord, T_D)// Constructeur avec pointeur sur software
{
	cout<< "ETCS" <<endl;
	//constructeur
}

void ETCS::ETCS_uptade() // Update des fonctions calculs et affichages de ETCS
{
	bord.bord_update();
	EDMI.update();

}
