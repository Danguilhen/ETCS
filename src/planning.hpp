#ifndef plan
#define plan

#include "symbol.hpp"
#include "donnees.hpp"

class Gradient
{
	private :

	float distance_debut;
	float taille;
	int valeur;

	public :

	Gradient(float D_debut, float T, int V)
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


class Planning_Announcements
{
	private :
	int distance;
	int numero;
	int position;
	int vitesse;

	public:

	Planning_Announcements(int D, int N)
	{
		distance = D;
		numero = N;
	}

	Planning_Announcements()
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


void planningInformation(RenderWindow & fenetre, double RE, Font & arial, vector<Symbol> & symbol, donnees &train, int * ecart, float temps_ecoule, vector<Gradient> &tab_grad, vector<PASP> &tab_pasp, vector<Planning_Announcements> &tab_pa, vector<Planning_Announcements> &tab_paf);
void pasp(int scale, double RE, RenderWindow & fenetre, int * ecart, vector<PASP> &tab_pasp, donnees &train, float delta_distance);
void gradientProfile(RenderWindow & fenetre, double RE, Font & arial, int scale, int * ecart, float delta_distance, vector<Gradient> &tab_grad);
void Orders_and_announcements(int scale,double RE, int * ecart, float delta_distance, vector<Planning_Announcements> &tab_pa, vector<Symbol> & symbol, RenderWindow & fenetre);
void SpeedProfileDiscontinuityInformation(int scale,double RE, int * ecart, float delta_distance, vector<Planning_Announcements> &tab_paf, vector<Symbol> & symbol, RenderWindow & fenetre, Font arial);

#endif