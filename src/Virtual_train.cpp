#include "Virtual_train.hpp"

Virtual_train::Virtual_train() : etcs(soft, train_dynamique, reseau), basic(train_dynamique, soft), auxiliaire(train_dynamique, soft), train_statique(reseau), train_dynamique(reseau,train_statique)
{
    //cout<< "VT" <<endl;
    //constructeur
}

void Virtual_train::update()
{

    soft.software_update();
    train_statique.update();
    train_dynamique.update();
    reseau.Reseau_update();
    if(soft.getType_signalisation() == "ETCS")
    {
        etcs.ETCS_uptade();
    }
    else if(soft.getType_signalisation() == "A_VIDE")
    {
        basic.update();
    }

}