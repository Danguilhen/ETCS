#include "ETCS_Bord.hpp"


ETCS_Bord::ETCS_Bord(Train_dynamique &T_D, Software &soft, Reseau &Res) : TrackRI(TrainRI, T_D, Res), SDM(T_D, TrainRI, TrackRI, soft, Res)
{
	//cout<< "BORD" <<endl;
	this->T_D = &T_D;
	this->soft = &soft;
	this->Res = &Res;
}

void ETCS_Bord::bord_update()
{
	//connection = getconnection; // Permet de savoir si il y a une connection
	transition_generalMode();
	if(generalMode == "FS")
	{
		TrackRI.TrackRI_Update();
		SDM.SDM_Update();
	}
	if(generalMode == "SR")
	{
		// à compléter
	}

}
void ETCS_Bord::transition_generalMode()
{
	if(connection == "Up" && generalMode == "SR")
	{
		generalMode == "FS";
	}
	if(connection == "Down" && generalMode == "FS")
	{
		generalMode == "SR";
	}
}

string ETCS_Bord::getGeneralMode(){return generalMode;}
string ETCS_Bord::getLevel(){return level;}
string ETCS_Bord::getVersion(){return version;}
void ETCS_Bord::setVersion(string V){version = V;}
bool ETCS_Bord::getDriverID(){return 1;}
bool ETCS_Bord::getTrainData(){return 1;}
bool ETCS_Bord::getETATLevelETCS(){return 1;}
bool ETCS_Bord::getTrainNumber(){return 1;}
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