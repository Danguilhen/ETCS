#ifndef DATA
#define DATA

#include "define.hpp"

class Data
{
	private :
		int Vtrain = 135;
		string generalMode = "FS";
		string level = "Level 1";
		double RE;
		int ecartX = 0;
		int ecartY = 0;
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
		void setVtrain(int V);
		string getGeneralMode();
		string getLevel();
		double getRE();
		int getEcartX();
		int getEcartY();
		void setSon(int a);
		int getVligne();
		string getVersion();
		int getPointKilometrique();
		int getRemainingDistanceTunnel();
		string getTunnelStoppingArea();
		void setTunnelStoppingArea(string TSA);
		int getSignalisation();
		bool getEteindre();
		void setEteindre(bool stop);
		bool getAllumage();
};

#endif