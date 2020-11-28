#ifndef PLANNING
#define PLANNING

#include "../define.hpp"
#include "Symbol.hpp"
#include "../Tools.hpp"
#include "../Bord/ETCS_Bord.hpp"

class PASP
{
	private :
	int vitesse_but;
	int distance_but;

	public :

	PASP(int V_but, int D_but)
	{
		vitesse_but = V_but;
		distance_but = D_but;
	}

	int getVitesse_but();
	void setVitesse_but(int V);
	int getDistance_but();
	void setDistance_but(int D);
};


class Announcements
{
	private :
	int distance;
	int numero;
	int position;
	int vitesse;

	public:

	Announcements(int D, int N)
	{
		distance = D;
		numero = N;
	}

	Announcements()
	{

	}

	void PAF(int V, double D)
	{
		distance = int(D);
		vitesse = V;
	}

	int getnumero();
	void setnumero(int V);
	int getDistance();
	void setDistance(int D);
	int getPosition();
	void setPosition(int P);
	int getVitesse();
	void setVitesse(int V);
};


class Planning : public Tools
{
	private :
		int scale = 32000;
/*
		Announcements PA1;
		Announcements PA2;
		Announcements PA3;
		Announcements PA6;

		vector<Announcements> tab_pa;//tout picto sauf flèche
*/

		std::vector <Symbol> *symbol;
		ETCS_Bord *bord;
		Train_dynamique *T_D;


	public:
		Planning(std::vector<Symbol> &symbol, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D);
		void SpeedProfileDiscontinuityInformation();
		//void Orders_and_announcements(int scale, double delta_distance, vector<Announcements> &tab_pa);
		void gradientProfile();
		void pasp();
		void planningInformation();
		int getScale();
		void setScale(int S);
};

#endif