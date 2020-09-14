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
    std::thread reseau_Update(Reseau::Reseau_update, &reseau);
    etcs.ETCS_uptade();
    reseau_Update.join();
}