#include "ETCS.hpp"

ETCS::ETCS(Software &soft, Train_dynamique &T_D, Reseau &Res, TVM_Bord &TVM) : Bord(T_D, soft, Res, TVM), EDMI(soft, Bord, T_D, TVM)// Constructeur avec pointeur sur software
{
	//cout<< "ETCS" <<endl;
	//constructeur
	this->soft = &soft;
	this->Res = &Res;
	this->TVM = &TVM;
}

void ETCS::ETCS_uptade() // Update des fonctions calculs et affichages de ETCS
{
	std::thread ETCS_bord_update(&ETCS_Bord::bord_update, &Bord);
	EDMI.update();
	ETCS_bord_update.join();
}
