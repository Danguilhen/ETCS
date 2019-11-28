#ifndef DATA
#define DATA

using namespace std;
using namespace sf;

class Data
{
	private :
		int Vtrain;
		string generalMode = "FS";
		string mode = "CSM";
		string status = "NoS";
		string level = "Level 1";
		double RE;
		int ecartX;
		int ecartY;
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
		int Vligne;
		float V_red;
		float V_orange;
		float V_yellow;
		float V_white;
		float V_medium_grey;
		float V_dark_grey;
		Color aiguille;
		string version;
		int pointKilometrique;
		int remainingDistanceTunnel = 500;
		string tunnelStoppingArea = "TunnelStoppingArea";
		bool eteindre = false;
		bool allumage = false;
		/*int sock = socket(AF_INET, SOCK_STREAM,0);
		int socketValue = 0;*/
		//void SocketSend(char buf[]);

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
		bool getEteindre();
		bool getAllumage();
};

#endif