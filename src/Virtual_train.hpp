#ifndef VI
#define VI

#include "Data.hpp"
#include "ETCS.hpp"
#include "DMI/BASIC.hpp"
#include "Train_dynamique.hpp"
#include "TrainStatique.hpp"
#include "Reseau.hpp"

class Virtual_train
{
    public :
        //Data data;
        Reseau reseau;
        Software soft;
        ETCS etcs;
        BASIC basic; // écran affichage restreint
        BASIC auxiliaire; // écran avec affichage information auxiliaire
        Train_dynamique train_dynamique;
        TrainStatique trainStatique;
        Virtual_train();
        void update();
};

#endif