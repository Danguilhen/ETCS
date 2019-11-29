#ifndef DATA
#define DATA

#include "define.hpp"

class Data
{
	private :
		int Vtrain = 0;
		string generalMode = "FS";
		string mode = "CSM";
		string status = "Normal";
		string level = "Level 1";
		double RE;
		int ecartX = 0;
		int ecartY = 0;
		Font arial;
		int son;
		//Son :
		//	Num�ro 1 : click
		//	Num�ro 2 : S-info
		//	Num�ro 3 : S1_toofast
		//	Num�ro 4 : S2_warning
		//	Mode 1 : Jouer UNE fois
		//	Mode 2 : Jouer en boucle
		//	Mode 3 : Stopper la boucle, le son s'arr�te
		int Vligne = 0;
		float V_red = 0;
		float V_orange = 50;
		float V_yellow = 70;
		float V_white = 0;
		float V_medium_grey = 0;
		float V_dark_grey = 0;
		Color aiguille = WHITE;
		string version = "3.6.0";
		int pointKilometrique = 0;
		int remainingDistanceTunnel = 500;
		string tunnelStoppingArea = "TunnelStoppingArea";
		/*int sock = socket(AF_INET, SOCK_STREAM,0);
		int socketValue = 0;*/
		//void SocketSend(char buf[]);
		int signalisation = 2;
		bool eteindre = false;
		bool allumage = true;

	public :
		Data();
		void update();
		int getVtrain();
		string getGeneralMode();
		string getMode();
		string getStatus();
		string getLevel();
		double getRE();
		int getEcartX();
		int getEcartY();
		Font getFont();
		void setSon(int a);
		int getVligne();
		float getV_red();
		float getV_orange();
		float getV_yellow();
		float getV_white();
		float getV_medium_grey();
		float getV_dark_grey();
		Color getAiguilleColor();
		string getVersion();
		int getPointKilometrique();
		int getRemainingDistanceTunnel();
		string getTunnelStoppingArea();
		void setTunnelStoppingArea(string TSA);
		int getSignalisation();
		bool getEteindre();
		bool getAllumage();
};

#endif