#ifndef VI
#define VI

#include "ETCS.hpp"
#include "Train_dynamique.hpp"
#include "Train_statique.hpp"
#include "Reseau.hpp"
#include "Bord/TVM_Bord.hpp"
#include "Software.hpp"

class Virtual_train
{
	private :

		int n = 0;;


    public :
        //Data data;
        Software *soft;
        Reseau reseau;
		TVM_Bord tvm_bord;
        ETCS etcs;
        Train_statique train_statique;
        Train_dynamique train_dynamique;
        Virtual_train(Software &soft);
        void update();
};

#endif