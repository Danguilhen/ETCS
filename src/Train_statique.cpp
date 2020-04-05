#include "Train_statique.hpp"

Train_statique::Train_statique(Reseau &res)
{
	this->res = &res;
etat_projecteurs = 0;
etat_disj = 0;
etat_sablage = 0;
etat_acquitt = 0;
// etat_essui_glace = 0;
// etat_lave_glace = 0;
// etat_light_cabine = 0;
// etat_light_pupitre = 0;
etat_sifflet = 0;
// etat_LS_SF = 0;
// etat_BP_SF = 0;
signalisation = 0;
// etat_VI = 0;
// direction = 0;
// etat_conduct_mod = 0;
etat_tract_frein = 0;
//etat_porte = 0;
etat_panto = 0;
// etat_VA = 0;
// etat_cle_BL = 0;
// etat_ventilation = 0;
etat_GROG = 0;
// etat_TVM_V1 = 0;
// etat_TVM_V2 = 0;
// etat_alarme = 0;
}
void Train_statique::update()
{
	int a;
	a=res->getDynamique_train().A;
	cout<< "A" << a;
}


//
//// Les seters
//
//// Voir peut-être si coder CG CP
//// Voir les relations entre les différents états
//// Voir comment coder différemment un bouton et un interrupteur
//
//void Train_statique::set_projecteurs()
//{ etat_projecteurs = PE->getCmd_projecteurs();}
//
void Train_statique::set_disj()
{
 // Timer : maintien 2s pour l'armement uniquement
 // Voir Benoît pour savoir comment gérer le bouton armement et fermeture
}

void Train_statique::set_sablage()
{
 // Timer : maintien

}

void Train_statique::set_acquitt()
{
 // Timer : à voir
}

//void TrainStatique::set_essui_glace()
//{etat_essui_glace = PE->getCmd_essui_glace();}
//
//void TrainStatique::set_lave_glace()
//{
//  // Timer : voir
//  etat_lave_glace = PE->getCmd_lave_glace();
//}
//
//void TrainStatique::set_light_cabine()
//{
//  // Timer : voir
//
//}
//
//void TrainStatique::set_light_pupitre()
//{
//  // Timer : voir
//
//}
//
void Train_statique::set_sifflet()
{

}

//void TrainStatique::set_LS_SF()
//{
//  // C'est la lumière qui est modifiée par l'acquittement
//}
//
//void TrainStatique::set_BP_SF()
//{
//
//}
//
void Train_statique::set_signalisation()
{
 // C'est écrit dans le manuel de spec comment je dois le coder
}

//void TrainStatique::set_VI()
//{VI = PE->getCmd_VI();}
//
//void TrainStatique::set_direction()
//{direction = PE->getCmd_inverseur();}
//
//void TrainStatique::set_conduct_mod()
//{conduct_mod = PE->getCmd_conduct_mod();}
//
void Train_statique::set_tract_frein()
{
	//tract_frein = PE->getCmd_tract_frein();
}

//void TrainStatique::setPorte()
//{
//
//}
//
void Train_statique::set_panto()
{

}

//void TrainStatique::set_VA()
//{
//
//}
//
//void TrainStatique::set_cle_BL()
//{
//
//}
//
//void TrainStatique::set_ventilation()
//{
//
//}
//
void Train_statique::set_GROG()
{

}

//void Train_statique::set_TVM_V1()
//{
//
//}
//
//void TrainStatique::set_TVM_V2()
//{
//
//}
//
//void TrainStatique::set_alarme()
//{
//
//}

//int TrainStatique::getPanto(){return panto;}
//int TrainStatique::getSifflet(){return sifflet;}
//bool TrainStatique::getDisj(){return disj;}

//void TrainStatique::update()
//{
//  set_disj();
//  set_panto();
//  set_sifflet();
//}