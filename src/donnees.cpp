#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <math.h>
#include <string>
#include <ctime>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include "donnees.hpp"

using namespace sf;
using namespace std;


donnees::donnees(float vitesse_EOA, float vitesse_train, float distance_but, float vitesse_ligne, float acceleration) //CONSTRUCTEUR
{
	V_ligne = vitesse_ligne;//Vitesse ligne avant d�c�l�ration
	V_but = vitesse_EOA;//vitesse BUT � la EOA
	Vf_ISL = 0;//Indication speed
	Vf_PSL = 0;//Permited speed
	Vf_FLOISL = 0;//Intervention speed
	V_train = vitesse_train;
	V_init = vitesse_train;//Vitesse mise � jour du train
	d_parcourue = 0; // distance parcourue en entrant dans la TSM
	d_train_EOA = distance_but;//distance avant but d�croit vers 0
	a_train = acceleration ;//acc�l�ration du train
}
donnees::donnees(){}

void donnees::vitesse_train(float delta_ts)
{
	V_train = (V_train / 3.6 + a_train * delta_ts) * 3.6;
	//return (VINIT/3.6 - 0.5 * delta_ts)*3.6;
}

void donnees::delta_d(float delta_ts)
{
	float d_parcourue_local;
	d_parcourue_local = (V_train / 3.6) * delta_ts;
	d_train_EOA = d_train_EOA - d_parcourue_local;
	//cout << d_train_EOA << " m ";
}

void donnees::TSM(float delta_ts)
{
	float temp;
	d_parcourue = d_parcourue + (V_train / 3.6) * delta_ts;
	temp = V_ligne + (((((V_but) / 3.6) - (V_ligne / 3.6)) / ((3 / 5.0) * (d_but-550))) * d_parcourue) * 3.6;

	if((int)Vf_ISL != -2)
	{
		Vf_ISL = temp;
	}
	if ((int)Vf_ISL == (int)V_but)
	{
		Vf_ISL = - 2;
	}

	if ((int)Vf_PSL == (int)(V_but))
	{
		Vf_PSL = V_but ;
	}
	else if(temp + 20 < V_ligne)
	Vf_PSL = temp + 20;

	if ((int)VWaS == (int)(V_but)+15)
		{
		VWaS = V_but + 15 ;
		}
		else if(temp + 15 < V_ligne)
			VWaS = temp + 15;

	if ((int)Vf_FLOISL == (int)(V_but + 30))
	{
		Vf_FLOISL = V_but + 30	;
	}
	else if(temp + 30 < V_ligne)
	Vf_FLOISL = temp + 30;

	if((int)getDEOA() > 0)
	delta_d(delta_ts);

	if(etat_train)
		{

			vitesse_train(delta_ts);
		}

	//cout<< "d�c�l�ration" << ((V_BUT  /3.6) - (V_LIGNE/3.6)) / ((float(3)/5)*D_BUT-50) ;
}

void donnees::CSM_PIM(float delta_ts)
{
	Vf_PSL = V_ligne;
	VWaS = V_ligne +15;
	Vf_ISL = - 1;
	Vf_FLOISL = V_ligne + 30;
	d_parcourue = 0;

	if(getDEOA() > -1)
		delta_d(delta_ts);

	if(etat_train)
	{
		vitesse_train(delta_ts);
	}

}
void donnees::mode_test()
{
	cout << "rentrer le mode, le status, la vitesse du train, la vitesse EBI, la vitesse PSL, la distance avant le but" << endl;
	cin >> mode >> status >> V_train >> Vf_FLOISL >> Vf_PSL >> Vf_ISL >> d_train_EOA;
}

float donnees::getDEOA() {return d_train_EOA;}
float donnees::getVitesseISL() {return Vf_ISL;}
float donnees::getVitessePSL() {return Vf_PSL;}
float donnees::getVitesseFLOISL() {return Vf_FLOISL;}
float donnees::getVtrain() {return V_train;}
void donnees::setVtrain(float V) {V_train = V;}
void donnees::setVligne(float V) {V_ligne = V;}
float donnees::getVligne(){return V_ligne;}
void donnees::setDEOA(float d) { d_train_EOA = d;}
float donnees::getVbut() {return V_but;}
void donnees::setVbut(float V) {V_but = V;}
float donnees::getD_but(){return d_but;}
void donnees::setD_but(float D){d_but = D;}
void donnees::setA_train(float A){a_train = A;}
int donnees::getRemainingDistanceTunnel() {return remainingDistanceTunnel;}
Color donnees::getCouleurAiguille() {return couleurAiguille;}
void donnees::setCouleurAiguille(Color T) {couleurAiguille = T;}
string donnees::getTunnelStoppingArea() {return tunnelStoppingArea;}
void donnees::setTunnelStoppingArea(string P) {tunnelStoppingArea = P;}
string donnees::getReversing() {return reversing;}
string donnees::getGeographicalPosition() {return geographicalPosition;}
void donnees::setGeographicalPosition(string P) {geographicalPosition = P;}
string donnees::getConnection() {return connection;}
float donnees::getVred() {return V_red;}
float donnees::getVorange() {return V_orange;}
float donnees::getVyellow() {return V_yellow;}
float donnees::getVwhite() {return V_white;}
float donnees::getVmediumGrey() {return V_medium_grey;}
float donnees::getVdarkGrey() {return V_dark_grey;}
void donnees::setVred(float V) {V_red = V;}
void donnees::setVorange(float V) {V_orange = V;}
void donnees::setVyellow(float V) {V_yellow = V;}
void donnees::setVwhite(float V) {V_white = V;}
void donnees::setVmediumGrey(float V) {V_medium_grey = V;}
void donnees::setVdarkGrey(float V) {V_dark_grey = V;}
int donnees::getPointKilometrique() {return pointKilometrique;}
float donnees::getTSMstart() {return TSMstart;}
void donnees::setMode(string M) {mode = M;}
string donnees::getMode() {return mode;}
void donnees::setStatus(string S) {status = S;}
string donnees::getStatus() {return status;}
void donnees::setGeneralMode(string G) {generalMode = G;}
string donnees::getGeneralMode() {return generalMode;}
void donnees::setVWaS(float V) {VWaS = V;}
float donnees::getVWaS() {return VWaS;}
float donnees::getVscale() {return Vscale;}
void donnees::setVscale(float V) {Vscale = V;}
float donnees::getVrelease() {return Vrelease;}
void donnees::setEtat_train(bool R) {etat_train = R;}
bool donnees::getEtat_train() {return etat_train;}
void donnees::setDriverID(bool D) {driverid = D;}
bool donnees::getDriverID() {return driverid;}
bool donnees::getTrainData() {return traindata;}
void donnees::setTrainData(bool V) {traindata = V;}
void donnees::setETATLevelETCS(bool R) {etat_level = R;}
bool donnees::getETATLevelETCS() {return etat_level;}
void donnees::setTrainNuber(bool R) {train_number = R;}
bool donnees::getTrainNumber() {return train_number;}
void donnees::setLevelETCS(string L) {ETCS_level = L;}
string donnees::getLevelETCS() {return ETCS_level;}
void donnees::setPending_Emergency_Stop(bool S) {pending_emergency_stop = S;}
bool donnees::getPending_Emergency_Stop() {return pending_emergency_stop;}
void donnees::setModif_DriverID_NTC(bool S) {modif_driverid_NTC = S;}
bool donnees::getModif_DriverID_NTC() {return modif_driverid_NTC;}
bool donnees::getPassive_Shunting() {return passive_shunting;}
void donnees::setPassive_Shunting(bool P) {passive_shunting = P;}
bool donnees::getNon_Leading() {return non_leading;}
void donnees::setNon_Leading(bool P) {non_leading = P;}
bool donnees::getmodif_Adhesion() {return modif_adhesion;}
void donnees::setmodif_Adhesion(bool P) {modif_adhesion = P;}
string donnees::getPlanning() {return planning;}
void donnees::setPlanning(string P) {planning = P;}
string donnees::getS_D_monitoring() {return speed_and_distance_monitoring;}
void donnees::setS_D_monitoring(string P) {speed_and_distance_monitoring = P;}
Train_Data donnees::get_cTrain_data() {return train_Data;}
void donnees::set_cTrain_Data(Train_Data & P) {train_Data = P;}
bool donnees::getEOA() {return EOA;}
void donnees::setEOA(bool P) {EOA = P;}
int donnees::getSRspeed() {return SRspeed;}
void donnees::setSRspeed(int N) {SRspeed = N;}
string donnees::getAdhesion(){return adhesion;}
void donnees::setAdhesion(string P) {adhesion = P;}
string donnees::getLanguage() {return language;}
void donnees::setLanguage(string P) {language = P;}
int donnees::getRBCID() {return RBCID;}
void donnees::setRBCID(int N) {RBCID = N;}
int donnees::getTempRBCID() {return RBCIDtemp;}
void donnees::setTempRBCID(int N) {RBCIDtemp = N;}
int donnees::getRBCphoneNumber() {return RBCphoneNumber;}
void donnees::setRBCphoneNumber(int N) {RBCphoneNumber = N;}
int donnees::getTempRBCphoneNumber() {return RBCphoneNumbertemp;}
void donnees::setTempRBCphoneNumber(int N) {RBCphoneNumbertemp = N;}
string donnees::getRadioNetworkID() {return radioNetworkID;}
void donnees::setRadioNetworkID(string P) {radioNetworkID = P;}
int donnees::getClignotementTexte() {return clignotementTexte;}
void donnees::setClignotementTexte(int N) {clignotementTexte = N;}
float donnees::getTTI(){return TTI;}
void donnees::setTTI(float N){TTI = N;}


int Train_Data::getlength() {return length;}
void Train_Data::setlength(int P) {length = P;}
int Train_Data::getbreaking_percetage() {return breaking_percetage;}
void Train_Data::setbreaking_percetage(int P) {breaking_percetage = P;}
vector <float> Train_Data::getOnboard_correction_factors() {return Onboard_correction_factors;}
void Train_Data::setOnboard_correction_factors(vector <float> P) {Onboard_correction_factors = P;}
int Train_Data::getnominal_rotating_mass() {return nominal_rotating_mass;}
void Train_Data::setnominal_rotating_mass(int P) {nominal_rotating_mass = P;}
int Train_Data::getmaximum_train_speed() {return maximum_train_speed;}
void Train_Data::setmaximum_train_speed(int P) {maximum_train_speed = P;}
string Train_Data::getloading_gauge() {return loading_gauge;}
void Train_Data::setloading_gauge(string P) {loading_gauge = P;}
string Train_Data::getaxle_load_category() {return axle_load_category;}
void Train_Data::setaxle_load_category(string P) {axle_load_category = P;}
int Train_Data::getaxle_number() {return axle_number;}
void Train_Data::setaxle_number(int P) {axle_number = P;}
vector <string> Train_Data::gettraction_systems() {return traction_systems;}
void Train_Data::settraction_systems(vector <string> P) {traction_systems = P;}
vector <string> Train_Data::getList_of_National_Systems_available_onboard() {return List_of_National_Systems_available_onboard;}
void Train_Data::setList_of_National_Systems_available_onboard(vector <string> P) {List_of_National_Systems_available_onboard = P;}
string Train_Data::getTrain_category() {return train_category;}
void Train_Data::setTrain_category(string P) {train_category = P;}
string Train_Data::getAirtight() {return airtight;}
void Train_Data::setAirtight(string P) {airtight = P;}
int Train_Data::getDriver_ID() {return driver_id;}
void Train_Data::setDriver_ID(int P) {driver_id = P;}
int Train_Data::getTrain_running_number() {return train_running_number;}
void Train_Data::setTrain_running_number(int P) {train_running_number = P;}
void Train_Data::setTrain_type(string P) {train_type = P;}
string Train_Data::getTrain_type() {return train_type;}
int Train_Data::getTempDriver_ID() {return driver_idTemp;}
void Train_Data::setTempDriver_ID(int P) {driver_idTemp = P;}



void calcul(float delta_ts, donnees &donnee)
{
	///Circulation normal
	if(donnee.getDEOA() > (float(3) / 5) * donnee.getD_but() )
	{	// il est dans la CSM/PIM avant la TSM

			if(donnee.getDEOA() < (float(4) / 5)* donnee.getD_but() && donnee.getDEOA() > (float(3) / 5)* donnee.getD_but())	//ZONE PIM
			{
				donnee.setMode("PIM");
				donnee.CSM_PIM(delta_ts);
			}
			else
			{
				donnee.setMode("CSM");
				donnee.CSM_PIM(delta_ts);
			}
	}
	if(donnee.getDEOA() < (3 / 5.0) * donnee.getD_but() && (int)donnee.getDEOA() > -1) // dans la TSM car la distance n'a pas �t� atteinte
	{
		donnee.TSM(delta_ts);
		donnee.setMode("TSM");
	}

	if(donnee.getDEOA() < 1)//d�passement de la EOA
	{
			donnee.setMode("CSM");
			donnee.setVligne(donnee.getVbut());
			donnee.CSM_PIM(delta_ts);


	}
	if((int)donnee.getVtrain() == 0)
		{
			donnee.setVtrain(0.0);
		}
	//cout << donnee.getMode() << " " << donnee.getStatus() << " etat freinage : " <<  donnee.getEtat_train() << " " << donnee.getVtrain() << "| LIGNE JAUNE  " << donnee.getVitesseISL() << "| LIGNE ORANGE  " << donnee.getVitessePSL() << "| LIGNE ROUGE  " << donnee.getVitesseFLOISL() << endl;
}

void demo(donnees &donnee)
{
	if(donnee.getVtrain() == -1) //1�re exp�rience
	{
		donnee.setDEOA(4000);
		donnee.setD_but(4000);
		donnee.setVtrain(295);
		donnee.setVligne(300);
		donnee.setVbut(170);
		donnee.setA_train(-0.8);


	}
	if( donnee.getMode() == "PIM" || (donnee.getMode() == "TSM" && (int)donnee.getVtrain() > (donnee.getVbut() - 10) ))
	{
		donnee.setEtat_train(true);
	}
	else
	{
		donnee.setEtat_train(false);
	}
	if(donnee.getMode() == "CSM" && (int)donnee.getVtrain() == (int)(donnee.getVbut() - 10))
	{
		donnee.setVtrain(-2);
	}
}

void demo2(donnees &donnee)
{
	if(donnee.getVtrain() == -2) //2�re exp�rience
		{
			donnee.setDEOA(2000);
			donnee.setD_but(2000);
			donnee.setVtrain(159);
			donnee.setVligne(170);
			donnee.setVbut(0);
			donnee.setA_train(-0.75);
		}
	if(donnee.getMode() == "PIM" || (donnee.getMode() == "TSM" && (int)donnee.getVtrain() > (int)(donnee.getVbut()) ))
		{
			donnee.setEtat_train(true);
		}
		else
		{
			donnee.setEtat_train(false);
		}

	}