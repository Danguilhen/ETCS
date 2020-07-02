#include "Virtual_train.hpp"

Virtual_train::Virtual_train(Software &soft) : etcs(soft, train_dynamique, reseau), train_statique(reseau), train_dynamique(reseau,train_statique)
{
    //cout<< "VT" <<endl;
    this->soft = &soft;
}

void Virtual_train::update()
{

    train_statique.update();
    train_dynamique.update();
    //reseau.Reseau_update();
    etcs.ETCS_uptade();

}