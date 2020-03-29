#include "TrainStatique.hpp"

TrainStatique::TrainStatique()
{
}
    /*int etat_projecteurs = 0;
    int etat_disj = 0;
    int etat_sablage = 0;
    bool etat_acquitt = 0;
    int etat_essui_glace = 0;
    bool etat_lave_glace = 0;
    int etat_light_cabine = 0;
    int etat_light_pupitre = 0;
    int etat_sifflet = 0;
    bool etat_LS_F = 0;
    bool etat_BP_SF = 0;
    int signalisation = 0;
    float etat_VI = 0;
    int direction = 0;
    int etat_conduct_mod = 0;
    float etat_tract_frein = 0;
    int etat_porte = 0;
    bool etat_panto = 0;
    bool etat_VA = 0;
    bool etat_cle_BL = 0;
    bool etat_ventilation = 0;
    int etat_GROG = 0;
    bool etat_TVM_V1 = 0;
    bool etat_TVM_V2 = 0;
    bool etat_alarme = 0;*/

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
//void TrainStatique::set_disj()
//{
//  // Timer : maintien 2s pour l'armement uniquement
//  // Voir Benoît pour savoir comment gérer le bouton armement et fermeture
//}
//
//void TrainStatique::set_sablage()
//{
//  // Timer : maintien
//
//}
//
//void TrainStatique::set_acquitt()
//{
//  // Timer : à voir
//}
//
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
//void TrainStatique::set_sifflet()
//{
//  ///
//}
//
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
//void TrainStatique::set_signalisation()
//{
//  // C'est écrit dans le manuel de spec comment je dois le coder
//}
//
//void TrainStatique::set_VI()
//{VI = PE->getCmd_VI();}
//
//void TrainStatique::set_direction()
//{direction = PE->getCmd_inverseur();}
//
//void TrainStatique::set_conduct_mod()
//{conduct_mod = PE->getCmd_conduct_mod();}
//
//void TrainStatique::set_tract_frein()
//{tract_frein = PE->getCmd_tract_frein();}
//
//void TrainStatique::setPorte()
//{
//
//}
//
//void TrainStatique::set_panto()
//{
//
//}
//
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
//void TrainStatique::set_GROG()
//{

//}
//
//void TrainStatique::set_TVM_V1()
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