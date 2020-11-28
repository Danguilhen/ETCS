#include "ETCS_Bord.hpp"


ETCS_Bord::ETCS_Bord(Train_dynamique &T_D, Software &soft, Reseau &Res, TVM_Bord &TVM) : TrackRI(TrainRI, T_D, Res), SDM(T_D, TrainRI, TrackRI, soft, Res), BasicEVCcommands(T_D)
{
	//cout<< "BORD" <<endl;
	this->T_D = &T_D;
	this->soft = &soft;
	this->Res = &Res;
	this->TVM = &TVM;
}

void ETCS_Bord::bord_update()
{
	/*//changement fin juin

		TrackRI.TrackRI_Update();
		SDM.SDM_Update_FS();
*/

	/*
	if(connection == "Down" && Res->getEurobalise().MAJ_eurobalise == true)
	{
		connection = "Up";
		cout<<"connection"<<endl;
	}*/

	if (Res->getValidationSocket() == 1)
		connection = "Up";
	else if (Res->getValidationSocket() == 0)
		connection = "Down";
	
	transition_generalMode();
	if(generalMode == "FS")
	{
		TrackRI.TrackRI_Update();
		SDM.SDM_Update_FS();
	}
	else if (generalMode == "TVM") {
		TVM->update();
	}
	/*else // Lancer les fonctions de sécurité basiques
	{
		//BasicEVCcommands.respect_vitesse(generalMode);
	}*/

}
void ETCS_Bord::transition_generalMode()
{
	//Autres transition hors de cette méthode,
	// - SB ---> SR quand start up fini
	// - ** ---> TR quand il n'y a plus de MA où franchisement d'un signal
	if(connection == "Up" && generalMode == "SR")
	{
		//cout<<"changement FS"<<endl;
		generalMode = "FS";
	}
	if(connection == "Down" && generalMode == "FS")
	{
		generalMode = "SR";
	}
}

string ETCS_Bord::getGeneralMode(){return generalMode;}
void ETCS_Bord::setGeneralMode(std::string M){generalMode = M;}
string ETCS_Bord::getVersion(){return version;}
void ETCS_Bord::setVersion(string V){version = V;}
bool ETCS_Bord::getDriverID()
{
	if(TrainRI.T_data.getDriverID() != 0)
        return 1;
    else
        return 0;
}
bool ETCS_Bord::getTrainData(){return 1;}
bool ETCS_Bord::getETATLevelETCS(){return 1;}
bool ETCS_Bord::getTrainNumber()
{
    if(TrainRI.T_data.getTrainRunningNumber() != 0)
        return 1;
    else
        return 0;
}
string ETCS_Bord::getConnection(){return connection;}
void ETCS_Bord::setConnection(bool C)
{
	if(C)
		connection = "Up";
	else
		connection = "Down";
}
bool ETCS_Bord::getPending_Emergency_Stop(){return 0;}
bool ETCS_Bord::getModif_DriverID_NTC(){return 1;}
bool ETCS_Bord::getNon_Leading(){return 0;}
bool ETCS_Bord::getPassive_Shunting(){return 1;}
int ETCS_Bord::getVrelease(){return 30;}
bool ETCS_Bord::getEOA(){return 0;}
void ETCS_Bord::setEOA(bool EOA){(void)EOA;}
bool ETCS_Bord::getmodif_Adhesion(){return 1;}