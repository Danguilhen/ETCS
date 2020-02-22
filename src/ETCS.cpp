#include "ETCS.hpp"

ETCS::ETCS(Software &soft, Train_dynamique &T_D) : Bord(T_D, soft), EDMI(soft, Bord, T_D)// Constructeur avec pointeur sur software
{
	//cout<< "ETCS" <<endl;
	//constructeur
	this->soft = &soft;
}

void ETCS::ETCS_uptade() // Update des fonctions calculs et affichages de ETCS
{
	std::thread calcul(&ETCS_Bord::bord_update, &Bord);
	EDMI.update();
	calcul.join();
}
