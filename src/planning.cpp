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


class Planning
{
	private :

	PASP pasp0;//évite erreur vector vide
	PASP pasp1;
	PASP pasp2;
	PASP pasp5;

	vector<PASP> tab_pasp;

	Gradient gradient1;
	Gradient gradient2;
	Gradient gradient3;
	Gradient gradient4;
	Gradient gradient5;

	vector<Gradient> tab_grad;

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

	void SpeedProfileDiscontinuityInformation(int scale,double RE, int * ecart, float delta_distance, vector<Announcements> &tab_paf, vector<Symbol> & symbol, RenderWindow & fenetre, Font arial);
	void Orders_and_announcements(int scale,double RE, int * ecart, float delta_distance, vector<Announcements> &tab_pa, vector<Symbol> & symbol, RenderWindow & fenetre);
	void gradientProfile(RenderWindow & fenetre, double RE, Font & arial, int scale, int * ecart, float delta_distance, vector<Gradient> &tab_grad);
	void pasp(int scale, double RE, RenderWindow & fenetre, int * ecart, vector<PASP> &tab_pasp, donnees &train, float delta_distance);

	public:

	Planning();
	void planningInformation(RenderWindow & fenetre, double RE, Font & arial, vector<Symbol> & symbol, donnees &train, int * ecart, float temps_ecoule);
};


float Gradient::getDistance_debut(){return distance_debut;}
void Gradient::setDistance_debut(float D){distance_debut = D;}
float Gradient::getTaille(){return taille;}
void Gradient::setTaille(float T){taille = T;}
int Gradient::getValeur(){return valeur;}
void Gradient::setValeur(int V){valeur = V;}

int PASP::getVitesse_but(){return vitesse_but;}
void PASP::setVitesse_but(int V){vitesse_but = V;}
int PASP::getDistance_but(){return distance_but;}
void PASP::setDistance_but(int D){distance_but = D;}

int Announcements::getDistance(){return distance;}
void Announcements::setDistance(int D){distance = D;}
int Announcements::getnumero(){return numero;}
void Announcements::setnumero(int N){numero = N;}
int Announcements::getPosition(){return position;}
void Announcements::setPosition(int P){position = P;}
int Announcements::getVitesse(){return vitesse;}
void Announcements::setVitesse(int V){vitesse = V;}


void Planning::pasp(int scale, double RE, RenderWindow & fenetre, int * ecart, vector<PASP> &tab_pasp, donnees & train, float delta_distance)
{
	int distance = 0;
	int target = 0;
	int vitesse = 0;
	int quart = 0;
	int plus_petite_V = train.getVligne();
	int distance_plus_petite_V = 40000;
	int n;

	for (size_t i = 0; i < tab_pasp.size(); i++)
	{
		if(i != 0)
		{
			tab_pasp[i].setDistance_but(tab_pasp[i].getDistance_but() - delta_distance);
			if(tab_pasp[i].getDistance_but()<0)
			{
				//train.setVligne(tab_pasp[i].getVitesse_but());
				tab_pasp.erase(tab_pasp.begin() + i);
			}
		}
		if(tab_pasp[i].getVitesse_but() < plus_petite_V)
		{
			plus_petite_V = tab_pasp[i].getVitesse_but();
			distance_plus_petite_V = tab_pasp[i].getDistance_but();
		}
	}

	plus_petite_V = train.getVligne();
	for(size_t i = 0; i < tab_pasp.size(); i++)
	{
			n = 0;
		if(tab_pasp[i].getVitesse_but() <= plus_petite_V && tab_pasp[i].getDistance_but() > 0 && i > 0)
		{
			if(tab_pasp[i].getDistance_but() == distance_plus_petite_V && tab_pasp[i].getVitesse_but() != 0)
				distance = 40000;
			else
				distance = tab_pasp[i].getDistance_but();
			if(i == 1)
				vitesse = train.getVligne();
			else
			{
				do
				{
					n++;
				}while(tab_pasp[i-n].getVitesse_but() != plus_petite_V);
				vitesse = tab_pasp[i-n].getVitesse_but();
			}
			if(vitesse > 0 && vitesse <= int(train.getVligne()) / 4.0)
				quart = 1;
			else if(vitesse <= int(train.getVligne()) / 2.0)
				quart = 2;
			else if(vitesse <= 3 * int(train.getVligne()) / 4.0)
				quart = 3;
			else if (vitesse >= 3 * int(train.getVligne()) / 4.0)
				quart = 4;
			if(distance <= (scale / 40.0) && distance >= 0)
				target = 283 - (distance * (283 - 250) / (scale / 40.0));
			else if(distance <= scale && distance >= 0)
				target =  283 - (283 - 250) - log10(distance / (scale / 40.0)) * (250 - 21) / log10(scale / (scale / 40.0));
			else
				target = 15;
			rectangle(V2f(54 + 280 + 40 + 25 * 3 + 18 + 14, target), V2f(quart * 93 / 4.0, 283 - target), PASP_LIGHT, RE, fenetre, ecart);
		}
		else if (tab_pasp.size() == 1)
		{
			quart = 4;
			distance = 40000;
			if(distance <= (scale / 40.0) && distance >= 0)
				target = 283 - (distance * (283 - 250) / (scale / 40.0));
			else if(distance <= scale && distance >= 0)
				target =  283 - (283 - 250) - log10(distance / (scale / 40.0)) * (250 - 21) / log10(scale / (scale / 40.0));
			else
				target = 15;
		}
		plus_petite_V = tab_pasp[i].getVitesse_but();
		if(i==tab_pasp.size()-1)
		{
			plus_petite_V = train.getVligne();
		}
	}
}

void Planning::planningInformation(RenderWindow & fenetre, double RE, Font & arial, vector<Symbol> & symbol, donnees & train, int * ecart, float temps_ecoule)
{
	float delta_distance;
	if(train.getPlanningScale() == 1000)
	{
		NA_05.afficher(V2f(54 + 280 + 40 / 2.0, 15 + 270 + 15 / 2.0), RE, ecart, fenetre);	//D9
		NA_09.afficher(V2f(64 * 9 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0), RE, ecart, fenetre);	//F10
	}
	else
	{
		NA_03.afficher(V2f(54 + 280 + 40 / 2.0, 15 + 270 + 15 / 2.0), RE, ecart, fenetre);	//D9
		NA_07.afficher(V2f(64 * 9 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0), RE, ecart, fenetre);	//F10
	}
	if(train.getPlanningScale() == 32000)
	{
		NA_06.afficher(V2f(54 + 280 + 40 / 2.0, 15 / 2.0), RE, ecart, fenetre);	//D9
		NA_10.afficher(V2f(64 * 8 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0), RE, ecart, fenetre);	//F9
	}
	else
	{
		NA_04.afficher(V2f(54 + 280 + 40 / 2.0, 15 / 2.0), RE, ecart, fenetre);	//D9
		NA_08.afficher(V2f(64 * 8 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0), RE, ecart, fenetre);	//F9
	}
	//TEXTE GRADUATION
	creation_texte(RE, to_string(int(train.getPlanningScale())), arial, MEDIUM_GREY, 10, 0, V2f(54 + 280 + 40 - 3, 21 + 1), fenetre, 2, ecart);
	creation_texte(RE, to_string(int(train.getPlanningScale() / 2)), arial, MEDIUM_GREY, 10, 0, V2f(54 + 280 + 40 - 3, 64), fenetre, 2, ecart);
	creation_texte(RE, to_string(int(train.getPlanningScale() / 4)), arial, MEDIUM_GREY, 10, 0, V2f(54 + 280 + 40 - 3, 107), fenetre, 2, ecart);
	creation_texte(RE, to_string(int(train.getPlanningScale() / 8)), arial, MEDIUM_GREY, 10, 0, V2f(54 + 280 + 40 - 3, 150 + 1), fenetre, 2, ecart);
	creation_texte(RE, "0", arial, MEDIUM_GREY, 10, 0, V2f(54 + 280 + 40 - 3, 283 + 1), fenetre, 2, ecart);
	//FOND
	rectangle(V2f(54 + 280 + 40 + 25 * 3 + 18 + 14, 15), V2f(93 + 8, 270), PASP_DARK, RE, fenetre, ecart);
	//MOUVEMENT
	delta_distance = (train.getVtrain()/3.6)*temps_ecoule;
	//LES PASP

	pasp(train.getPlanningScale(), RE, fenetre, ecart, tab_pasp, train, delta_distance);
	Orders_and_announcements(train.getPlanningScale(), RE, ecart, delta_distance, tab_pa, symbol, fenetre);
	SpeedProfileDiscontinuityInformation(train.getPlanningScale(), RE, ecart, delta_distance, tab_paf, symbol, fenetre, arial);
	//LES GRADUATIONS
	rectangle(V2f(54 + 280 + 40, 283), V2f(200, 2), MEDIUM_GREY, RE, fenetre, ecart);
	rectangle(V2f(54 + 280 + 40, 250), V2f(200, 1), DARK_GREY, RE, fenetre, ecart);
	rectangle(V2f(54 + 280 + 40, 206), V2f(200, 1), DARK_GREY, RE, fenetre, ecart);
	rectangle(V2f(54 + 280 + 40, 182), V2f(200, 1), DARK_GREY, RE, fenetre, ecart);
	rectangle(V2f(54 + 280 + 40, 164), V2f(200, 1), DARK_GREY, RE, fenetre, ecart);
	rectangle(V2f(54 + 280 + 40, 150), V2f(200, 2), MEDIUM_GREY, RE, fenetre, ecart);
	rectangle(V2f(54 + 280 + 40, 107), V2f(200, 1), DARK_GREY, RE, fenetre, ecart);
	rectangle(V2f(54 + 280 + 40, 64), V2f(200, 1), DARK_GREY, RE, fenetre, ecart);
	rectangle(V2f(54 + 280 + 40, 21), V2f(200, 2), MEDIUM_GREY, RE, fenetre, ecart);

	//?
	//if(TSMstart <= (scale / 40.0) && TSMstart >= 0) //Indication Marker
	//	rectangle(V2f(54 + 280 + 40 + 25 * 3 + 18 + 14, 283 - TSMstart * (283 - 250) / (scale / 40.0)), V2f(93, 2), YELLOW, RE, fenetre, ecart);
	//else if(TSMstart <= scale && TSMstart >= 0)
	//	rectangle(V2f(54 + 280 + 40 + 25 * 3 + 18 + 14, 283 - (283 - 250) - log10(TSMstart / (scale / 40.0)) * (250 - 21) / log10(scale / (scale / 40.0))), V2f(93, 2), YELLOW, RE,
	//		fenetre, ecart); //Indication Marker
	//LES GRADIENT
	gradientProfile(fenetre, RE, arial, train.getPlanningScale(), ecart, delta_distance, tab_grad);
}

void Planning::Orders_and_announcements(int scale,double RE, int * ecart, float delta_distance, vector<Announcements> &tab_pa, vector<Symbol> & symbol, RenderWindow & fenetre)
{
	int target = 0;
	int distance;
	int position = 0;

	for(size_t i = 0; i<tab_pa.size(); i++)
	{
		if (i == 0)
		{
			for(size_t k = 1; k < tab_pa.size(); k++)
			{
				for(size_t j = 1; j <= k; j++)
				{
					if(tab_pa[k].getDistance() < tab_pa[k - j].getDistance())
					{	position = k - j;
						tab_pa.insert(tab_pa.begin() + position, tab_pa[k]);
						tab_pa.erase(tab_pa.begin() + k + 1);
					}
				}

				position = 0;
			}
		}


		distance = tab_pa[i].getDistance();
		position = 0;
		if(distance <= (scale / 40.0) && distance >= 0)
			target = 283 - (distance * (283 - 250) / (scale / 40.0));
		else if(distance <= scale && distance >= 0)
			target =  283 - (283 - 250) - log10(distance / (scale / 40.0)) * (250 - 21) / log10(scale / (scale / 40.0));
		else
			target = 15;
		target = target - 5;

		if(i == 0 || tab_pa[i-1].getPosition() == 3)
		{
			position = 54+280+40;
			tab_pa[i].setPosition(1);
		}
		else if(tab_pa[i-1].getPosition() == 1)
		{
			position = 54+280+40+25;
			tab_pa[i].setPosition(2);
		}
		else if(tab_pa[i-1].getPosition() == 2)
		{
			position = 54+280+40+2*25;
			tab_pa[i].setPosition(3);
		}
		if(tab_pa[i].getDistance() <= scale)
			symbol[tab_pa[i].getnumero()].afficher(V2f(position + 12, target), RE, ecart, fenetre);

		tab_pa[i].setDistance(tab_pa[i].getDistance() - delta_distance);
		if(tab_pa[i].getDistance() <= 0)
		{
			tab_pa.erase(tab_pa.begin()+i);
		}
	}

}

void Planning::gradientProfile(RenderWindow & fenetre, double RE, Font & arial, int scale, int * ecart, float delta_distance, vector<Gradient> &tab_grad)
{
	Color couleur;
	string sens;
	float taille;
	float hauteur;
	int valeur;
	for(size_t i=0; i<tab_grad.size(); i++)
		{
			tab_grad[i].setDistance_debut(tab_grad[i].getDistance_debut() - delta_distance);
			if(tab_grad[i].getDistance_debut() > 0)
			{
				hauteur = tab_grad[i].getDistance_debut();
				taille = tab_grad[i].getTaille();
			}
		else
		{
			hauteur = 0;
			tab_grad[i].setTaille(tab_grad[i].getTaille() - delta_distance);
			taille = tab_grad[i].getTaille();
		}
		if(tab_grad[i].getTaille() < 0)
		taille = 0;
		valeur = tab_grad[i].getValeur();

		if(hauteur < scale)
		{
			taille = hauteur + taille;
			if(hauteur <= (scale / 40.0) && hauteur >= 0)
				hauteur = hauteur * (283 - 250) / (scale / 40.0);
			else if(hauteur <= scale && hauteur >= 0)
				hauteur =  (283 - 250) + log10(hauteur / (scale / 40.0)) * (250 - 21) / log10(scale / (scale / 40.0));
			if(taille <= (scale / 40.0) && taille >= 0)
				taille = taille * (283 - 250) / (scale / 40.0);
			else if(taille <= scale && taille >= 0)
				taille =  (283 - 250) + log10(taille / (scale / 40.0)) * (250 - 21) / log10(scale / (scale / 40.0));
			else
				taille = 283 - 15;
			taille = taille - hauteur - 2;
			if(valeur >= 0)
			{
				couleur = GREY;
				sens = "+";
			}
			else
			{
				couleur = DARK_GREY;
				sens = "-";
				valeur = abs(valeur);
			}
			rectangle(V2f(54 + 280 + 40 + 25 * 3, 283 - 2 - hauteur - taille), V2f(18, 1), WHITE, RE, fenetre, ecart);
			rectangle(V2f(54 + 280 + 40 + 25 * 3, 283 - 1 - hauteur - taille), V2f(1, 1 + taille), WHITE, RE, fenetre, ecart);
			rectangle(V2f(54 + 280 + 40 + 25 * 3 + 1, 283 - 1 - hauteur - taille), V2f(17, taille), couleur, RE, fenetre, ecart);
			rectangle(V2f(54 + 280 + 40 + 25 * 3, 283 - 1 - hauteur), V2f(18, 1), BLACK, RE, fenetre, ecart);
			if(couleur == GREY)
				couleur = BLACK;
			else if(couleur == DARK_GREY)
				couleur = WHITE;
			if(taille > 30)
			{
				creation_texte(RE, sens, arial, couleur, 12, 0, V2f(54 + 280 + 40 + 25 * 3 + 18 / 2.0, 283 - hauteur - taille + 12), fenetre, 1, ecart); //400km/h
				creation_texte(RE, sens, arial, couleur, 12, 0, V2f(54 + 280 + 40 + 25 * 3 + 18 / 2.0, 283 - hauteur - 12), fenetre, 1, ecart); //400km/h
			}
			if(taille > 50)
				creation_texte(RE, to_string(valeur), arial, couleur, 12, 0, V2f(54 + 280 + 40 + 25 * 3 + 18 / 2.0, 283 - hauteur - taille / 2.0), fenetre, 1, ecart); //400km/h
		}
	}
}

void Planning::SpeedProfileDiscontinuityInformation(int scale,double RE, int * ecart, float delta_distance, vector<Announcements> &tab_paf, vector<Symbol> & symbol, RenderWindow & fenetre, Font arial)
{
	int distance;
	int target;
	int position;

	for (size_t i = 0; i < tab_paf.size(); i++)
	{
		distance = tab_paf[i].getDistance();
		if(distance <= (scale / 40.0) && distance >= 0)
			target = 283 - (distance * (283 - 250) / (scale / 40.0));
		else if(distance <= scale && distance >= 0)
			target =  283 - (283 - 250) - log10(distance / (scale / 40.0)) * (250 - 21) / log10(scale / (scale / 40.0));
		else
			target = 15;
		target = target - 5;
		tab_paf[i].setnumero(92);

		//Dans le futur faire comparer la première case avec la vitesse ligne puis comparer les cases entre elles afin de voir si il y aura une augmentation ou une diminution

		if(tab_paf[i].getDistance() <= scale)
		{
			symbol[tab_paf[i].getnumero()].afficher(V2f(54 + 280 + 40 + 3 * 25 + 18 + 13, target + 10), RE, ecart, fenetre);
			if(tab_paf[i].getVitesse() > 99)
				position = 19;
			else if(tab_paf[i].getVitesse() > 9)
				position = 20 - 4;
			else
				position = 20 - 7;
			if(tab_paf[i].getnumero() == 92)
				creation_texte(RE, to_string(tab_paf[i].getVitesse()), arial, GREY, 11, 0, V2f(54 + 280 + 40 + 3 * 25 + 18 + 13 + position, target + 9), fenetre, 1, ecart);
			if(tab_paf[i].getnumero() == 91)
				creation_texte(RE, to_string(tab_paf[i].getVitesse()), arial, GREY, 11, 0, V2f(54 + 280 + 40 + 3 * 25 + 18 + 13 + position, target + 14), fenetre, 1, ecart);
		}
		tab_paf[i].setDistance(tab_paf[i].getDistance() - delta_distance);
		if(tab_paf[i].getDistance() <= 0)
		{
			tab_paf.erase(tab_paf.begin()+i);
		}
	}
}

Planning::Planning() : pasp0(400, 40000), pasp1(225, 3000), pasp2(150, 5000), pasp5(0, 8000), gradient1(2001, 2000, 20), gradient2(0, 2000, 0), gradient3(10000, 5000, -5),
	gradient4(4001, 6000, 0), gradient5(15001, 7000, 35), PA1(1500, 98), PA2(1000, 72), PA3(3000, 97), PA6(4000, 75)
{
	tab_pasp.push_back(pasp0);
	tab_pasp.push_back(pasp1);
	tab_pasp.push_back(pasp2);
	tab_pasp.push_back(pasp5);

	tab_grad.push_back(gradient1);
	tab_grad.push_back(gradient2);
	tab_grad.push_back(gradient3);
	tab_grad.push_back(gradient4);
	tab_grad.push_back(gradient5);

	tab_pa.push_back(PA1);
	tab_pa.push_back(PA2);
	tab_pa.push_back(PA3);
	tab_pa.push_back(PA6);

	PAF1.PAF(225, 3000);
	PAF2.PAF(150, 5000);
	PAF3.PAF(0,8000);

	tab_paf.push_back(PAF1);
	tab_paf.push_back(PAF2);
	tab_paf.push_back(PAF3);
}