#ifndef VI
#define VI

#include "Data.hpp"
#include "ETCS.hpp"
#include "DMI/BASIC.hpp"
#include "Train_dynamique.hpp"
#include "Reseau.hpp"


class Virtual_train
{
	public :
		//Data data;
<<<<<<< HEAD
		Reseau reseau;
=======
		//Reseau reseau;
>>>>>>> b7575f6a74f80a8af54954a7363ecf52eb1a4550
		Software soft;
		Train_dynamique train_dynamique;
		ETCS etcs;
		BASIC basic; // écran affichage restreint
		BASIC auxiliaire; // écran avec affichage information auxiliaire
		//Train_Statique train_statique;
		Virtual_train();
		void update();
};

#endif