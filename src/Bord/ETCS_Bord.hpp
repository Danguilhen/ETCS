#ifndef ET
#define ET

#include "TrainRelatedInputs.hpp"
#include "TrackRelatedInputs.hpp"
#include "Train_dynamique.hpp"
#include "SpeedAndDistanceMonitoring.hpp"

class SpeedAndDistanceMonitoring;


class ETCS_Bord
{
	protected :
		std::string generalMode = "FS";
		std::string level = "Level 1";
		std::string version = "3.6.0";
		Train_dynamique *T_D;

	public :
		TrackRelatedInputs TrackRI;
		TrainRelatedInputs TrainRI;
		SpeedAndDistanceMonitoring SDM;
		Software *soft;
		ETCS_Bord(Train_dynamique &T_D, Software &soft);
		void bord_update();
		std::string getGeneralMode();
		std::string getLevel();
		std::string getVersion();
		void setVersion(std::string V);
		bool getDriverID();
		bool getTrainData();
		bool getETATLevelETCS();
		bool getTrainNumber();
		std::string getConnection();
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