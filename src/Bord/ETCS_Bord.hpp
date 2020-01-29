#ifndef ET
#define ET

#include "TrainRelatedInputs.hpp"
#include "TrackRelatedInputs.hpp"
#include "../Train_dynamique.hpp"
#include "SpeedAndDistanceMonitoring.hpp"

class SpeedAndDistanceMonitoring;


class ETCS_Bord
{
	protected :
		string generalMode = "FS";
		string level = "Level 1";
		string version = "3.6.0";
		Train_dynamique *T_D;

	public :
		SpeedAndDistanceMonitoring SDM;
		TrackRelatedInputs TrackRI;
		TrainRelatedInputs TrainRI;
		ETCS_Bord(Train_dynamique &T_D);
		void bord_update();
		string getGeneralMode();
		string getLevel();
		string getVersion();
		void setVersion(string V);
		bool getDriverID();
		bool getTrainData();
		bool getETATLevelETCS();
		bool getTrainNumber();
		string getConnection();
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