
#include "Virtual_train.hpp"

Virtual_train::Virtual_train() : reseau(),etcs(soft, train_dynamique), basic(train_dynamique, soft), auxiliaire(train_dynamique, soft)
{
	//cout<< "VT" <<endl;
	//constructeur
}

void Virtual_train::update()
{
	soft.getFenetre()->clear();
	soft.software_update();
	train_dynamique.update();
	//data.update();
	if(soft.getType_signalisation() == "ETCS")
	{
		etcs.ETCS_uptade();
	}
	else if(soft.getType_signalisation() == "A_VIDE")
	{
		basic.update();
	}
	auxiliaire.affichageFreinage();
	soft.getFenetre()->display();
}
