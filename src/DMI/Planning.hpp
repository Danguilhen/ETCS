#ifndef PLANNING
#define PLANNING

#include "define.hpp"
#include "Symbol.hpp"
#include "Tools.hpp"
#include "Bord/ETCS_Bord.hpp"

class Gradient_DMI
{
	private :

	float distance_debut;
	float taille;
	int valeur;

	public :

	Gradient_DMI(float D_debut, float T, int V)
	{
		distance_debut = D_debut;
		taille = T;
		valeur = V;
	}

	float getDistance_debut();
	void setDistance_debut(float D);
	float getTaille();
	void setTaille(float T);
	int getValeur();
	void setValeur(int V);
};


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

	void PAF(int V, float D)
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

		PASP pasp0;//évite erreur vector vide
		PASP pasp1;
		PASP pasp2;
		PASP pasp5;

		vector<PASP> tab_pasp;

		Gradient_DMI gradient1;
		Gradient_DMI gradient2;
		Gradient_DMI gradient3;
		Gradient_DMI gradient4;
		Gradient_DMI gradient5;

		vector<Gradient_DMI> tab_grad;

		Announcements PA1;
		Announcements PA2;
		Announcements PA3;
		Announcements PA6;

		vector<Announcements> tab_pa;//tout picto sauf flèche

		Announcements PAF1;
		Announcements PAF2;
		Announcements PAF3;
		Announcements PAF4;
		Announcements PAF5;

		vector<Announcements> tab_paf;//FLÉCHES VITESSE

		vector <Symbol> *symbol;
		ETCS_Bord *bord;
		Train_dynamique *T_D;

		void SpeedProfileDiscontinuityInformation(int scale, float delta_distance, vector<Announcements> &tab_paf);
		void Orders_and_announcements(int scale, float delta_distance, vector<Announcements> &tab_pa);
		void gradientProfile(int scale, float delta_distance, vector<Gradient_DMI> &tab_grad);
		void pasp(int scale, vector<PASP> &tab_pasp, float delta_distance);

	public:
		Planning(vector<Symbol> &symbol, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D);
		void planningInformation(float temps_ecoule);
		int getScale();
		void setScale(int S);
};

#endif