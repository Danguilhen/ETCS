#include "ETCS_Bord.hpp"


ETCS_Bord::ETCS_Bord(Train_dynamique &T_D) : SDM(T_D)
{
	cout<< "BORD" <<endl;
	this->T_D = &T_D;
}


void ETCS_Bord::bord_update()
{
	//ATTENTION A L ORDRE LES RELATED INPUTS AVANT LE SDM

	TrackRI.TSR.TSR_Update();//trackspeedrestriction
	SDM.MSRP(TrackRI, TrainRI);
	SDM.Supervision_limits(TrainRI);
	SDM.SpeedAndDistanceMonitoringCommands();
}

string ETCS_Bord::getGeneralMode(){return generalMode;}
string ETCS_Bord::getLevel(){return level;}
string ETCS_Bord::getVersion(){return version;}
void ETCS_Bord::setVersion(string V){version = V;}
int ETCS_Bord::getPointKilometrique(){return pointKilometrique;}
int ETCS_Bord::getRemainingDistanceTunnel(){return remainingDistanceTunnel;}
string ETCS_Bord::getTunnelStoppingArea(){return tunnelStoppingArea;}
void ETCS_Bord::setTunnelStoppingArea(string TSA){tunnelStoppingArea = TSA;}
bool ETCS_Bord::getDriverID(){return 1;}
bool ETCS_Bord::getTrainData(){return 1;}
bool ETCS_Bord::getETATLevelETCS(){return 1;}
bool ETCS_Bord::getTrainNumber(){return 1;}
string ETCS_Bord::getConnection(){return "Up";}
bool ETCS_Bord::getPending_Emergency_Stop(){return 0;}
bool ETCS_Bord::getModif_DriverID_NTC(){return 1;}
bool ETCS_Bord::getNon_Leading(){return 0;}
bool ETCS_Bord::getPassive_Shunting(){return 1;}
int ETCS_Bord::getVrelease(){return 30;}
bool ETCS_Bord::getEOA(){return 0;}
void ETCS_Bord::setEOA(bool EOA){(void)EOA;}
bool ETCS_Bord::getmodif_Adhesion(){return 1;}