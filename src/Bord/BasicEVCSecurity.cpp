#include "BasicEVCSecurity.hpp"

BasicEVCSecurity::BasicEVCSecurity(Train_dynamique &T_D)
{
	this->T_D = &T_D;
}
//void BasicEVCSecurity::respect_vitesse(std::string general_mode)
//{
//	//if(general_mode == "SR" && T_D->getV_train() > V_SR)
//	//	//enclencher freinage d'urgence
//	//if(general_mode == "SB" && T_D->getV_train() > V_SB)
//	//	//enclencher freinage d'urgence
//
//}