#ifndef ET
#define ET

#include "TrainRelatedInputs.hpp"
#include "TrackRelatedInputs.hpp"
#include "Train_dynamique.hpp"
#include "SpeedAndDistanceMonitoring.hpp"
#include "Reseau.hpp"
#include "BasicEVCSecurity.hpp"

class SpeedAndDistanceMonitoring;


class ETCS_Bord
{
	protected :
		std::string generalMode = "SB";// FS,SR,SB
		std::string version = "3.6.0";
		std::string connection = "Up"; // POur l'instant sur Up automatiquement
		Train_dynamique *T_D;
		Software *soft;
		Reseau *Res;

	public :
		TrackRelatedInputs TrackRI;
		TrainRelatedInputs TrainRI;
		SpeedAndDistanceMonitoring SDM;
		BasicEVCSecurity BasicEVCcommands;
		ETCS_Bord(Train_dynamique &T_D, Software &soft, Reseau &Res);
		void bord_update();
		void transition_generalMode();
		void connection_update();
		std::string getGeneralMode();
		void setGeneralMode(std::string M);
		std::string getVersion();
		void setVersion(std::string V);
		bool getDriverID();
		bool getTrainData();
		bool getETATLevelETCS();
		bool getTrainNumber();
		std::string getConnection();
		void setConnection(bool C);
		bool getPending_Emergency_Stop();
		bool getModif_DriverID_NTC();
		bool getNon_Leading();
		bool getPassive_Shunting();
		int getVrelease();
		bool getEOA();
		void setEOA(bool EOA);
		bool getmodif_Adhesion();


};

#endif