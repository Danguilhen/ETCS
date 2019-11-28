/*#include <cstdlib>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>*/
/*#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <netdb.h>*/

// Texte --------------------------------------------------------------------------------------------------------------------------
/*
class Texte_DMI : public Tools
{
	private :
		int position;//position dans le 4 rectangle de E
		int heure;//heure de l'affichage
		string message;//message à diffuser
		int acknowledgement;//si besoin d'acquitter

	public :
		Texte_DMI(int h, string m, int a);
		void TexteMessages();

		int getPosition();
		void setPosition(int P);
		int getHeure();
		void setHeure(int H);
		string getMessage();
		void setMessage(string M);
		int getAcknowledgement();
		void setAcknowledgement(int A);
};

Texte_DMI::Texte_DMI(int h, string m, int a)
{
	heure = h;
	message = m;
	acknowledgement = a;
}

void Texte_DMI::TexteMessages()
{
	for (int n = 0; n < 4; n++)
	{
		creation_texte("10H30", WHITE, 10, 0, V2f(54 + 3, (350 + 7) + n * 20), 4);//+3 déplacement sur x par rapport à la norme
		creation_texte("Route unsuitable loading gauge", WHITE, 12, 0, V2f(54 + 3 + 37, (350 + 8) + n * 20), 4);//Police 12 et décallage de 3 par rapport à l'heure
	}
}

int Texte_DMI::getPosition(){return position;}
void Texte_DMI::setPosition(int P){position = P;}
int Texte_DMI::getHeure(){return heure;}
void Texte_DMI::setHeure(int H){heure = H;}
string Texte_DMI::getMessage(){return message;}
void Texte_DMI::setMessage(string M){message = M;}
int Texte_DMI::getAcknowledgement(){return acknowledgement;}
void Texte_DMI::setAcknowledgement(int A){acknowledgement = A;}

//Planning -----------------------------------------------------------------------------------------------------------------------------------

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


class Planning : public Tools
{
	private :
		int scale;

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

		vector <Symbol> symbol;

		void SpeedProfileDiscontinuityInformation(int scale, float delta_distance, vector<Announcements> &tab_paf, vector<Symbol> & symbol);
		void Orders_and_announcements(int scale, float delta_distance, vector<Announcements> &tab_pa, vector<Symbol> & symbol);
		void gradientProfile(int scale, float delta_distance, vector<Gradient> &tab_grad);
		void pasp(int scale, vector<PASP> &tab_pasp, float delta_distance);

	public:
		Planning(vector<Symbol> &symbol);
		void planningInformation(float temps_ecoule);
		int getScale();
		void setScale(int S);
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


int Planning::getScale(){return scale;}
void Planning::setScale(int S){scale = S;}


void Planning::pasp(int scale, vector<PASP> &tab_pasp, float delta_distance)
{
	int distance = 0;
	int target = 0;
	int vitesse = 0;
	int quart = 0;
	int plus_petite_V = data->getVligne();
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

	plus_petite_V = data->getVligne();
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
				vitesse = data->getVligne();
			else
			{
				do
				{
					n++;
				}while(tab_pasp[i-n].getVitesse_but() != plus_petite_V);
				vitesse = tab_pasp[i-n].getVitesse_but();
			}
			if(vitesse > 0 && vitesse <= int(data->getVligne()) / 4.0)
				quart = 1;
			else if(vitesse <= int(data->getVligne()) / 2.0)
				quart = 2;
			else if(vitesse <= 3 * int(data->getVligne()) / 4.0)
				quart = 3;
			else if (vitesse >= 3 * int(data->getVligne()) / 4.0)
				quart = 4;
			if(distance <= (scale / 40.0) && distance >= 0)
				target = 283 - (distance * (283 - 250) / (scale / 40.0));
			else if(distance <= scale && distance >= 0)
				target =  283 - (283 - 250) - log10(distance / (scale / 40.0)) * (250 - 21) / log10(scale / (scale / 40.0));
			else
				target = 15;
			rectangle(V2f(54 + 280 + 40 + 25 * 3 + 18 + 14, target), V2f(quart * 93 / 4.0, 283 - target), PASP_LIGHT);
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
			plus_petite_V = data->getVligne();
		}
	}
}

void Planning::planningInformation(float temps_ecoule)
{
	float delta_distance;
	if(scale == 1000)
	{
		NA_05.afficher(V2f(54 + 280 + 40 / 2.0, 15 + 270 + 15 / 2.0));	//D9
		NA_09.afficher(V2f(64 * 9 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0));	//F10
	}
	else
	{
		NA_03.afficher(V2f(54 + 280 + 40 / 2.0, 15 + 270 + 15 / 2.0));	//D9
		NA_07.afficher(V2f(64 * 9 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0));	//F10
	}
	if(scale == 32000)
	{
		NA_06.afficher(V2f(54 + 280 + 40 / 2.0, 15 / 2.0));	//D9
		NA_10.afficher(V2f(64 * 8 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0));	//F9
	}
	else
	{
		NA_04.afficher(V2f(54 + 280 + 40 / 2.0, 15 / 2.0));	//D9
		NA_08.afficher(V2f(64 * 8 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0));	//F9
	}
	//TEXTE GRADUATION
	creation_texte(to_string(int(scale)), MEDIUM_GREY, 10, 0, V2f(54 + 280 + 40 - 3, 21 + 1), 2);
	creation_texte(to_string(int(scale / 2)), MEDIUM_GREY, 10, 0, V2f(54 + 280 + 40 - 3, 64), 2);
	creation_texte(to_string(int(scale / 4)), MEDIUM_GREY, 10, 0, V2f(54 + 280 + 40 - 3, 107), 2);
	creation_texte(to_string(int(scale / 8)), MEDIUM_GREY, 10, 0, V2f(54 + 280 + 40 - 3, 150 + 1), 2);
	creation_texte("0", MEDIUM_GREY, 10, 0, V2f(54 + 280 + 40 - 3, 283 + 1), 2);
	//FOND
	rectangle(V2f(54 + 280 + 40 + 25 * 3 + 18 + 14, 15), V2f(93 + 8, 270), PASP_DARK);
	//MOUVEMENT
	delta_distance = (data->getVtrain() / 3.6) * temps_ecoule;
	//LES PASP

	pasp(scale, tab_pasp, delta_distance);
	Orders_and_announcements(scale, delta_distance, tab_pa, symbol);
	SpeedProfileDiscontinuityInformation(scale, delta_distance, tab_paf, symbol);
	//LES GRADUATIONS
	rectangle(V2f(54 + 280 + 40, 283), V2f(200, 2), MEDIUM_GREY);
	rectangle(V2f(54 + 280 + 40, 250), V2f(200, 1), DARK_GREY);
	rectangle(V2f(54 + 280 + 40, 206), V2f(200, 1), DARK_GREY);
	rectangle(V2f(54 + 280 + 40, 182), V2f(200, 1), DARK_GREY);
	rectangle(V2f(54 + 280 + 40, 164), V2f(200, 1), DARK_GREY);
	rectangle(V2f(54 + 280 + 40, 150), V2f(200, 2), MEDIUM_GREY);
	rectangle(V2f(54 + 280 + 40, 107), V2f(200, 1), DARK_GREY);
	rectangle(V2f(54 + 280 + 40, 64), V2f(200, 1), DARK_GREY);
	rectangle(V2f(54 + 280 + 40, 21), V2f(200, 2), MEDIUM_GREY);

	//?
	//if(TSMstart <= (scale / 40.0) && TSMstart >= 0) //Indication Marker
	//	rectangle(V2f(54 + 280 + 40 + 25 * 3 + 18 + 14, 283 - TSMstart * (283 - 250) / (scale / 40.0)), V2f(93, 2), YELLOW, RE, fenetre, ecart);
	//else if(TSMstart <= scale && TSMstart >= 0)
	//	rectangle(V2f(54 + 280 + 40 + 25 * 3 + 18 + 14, 283 - (283 - 250) - log10(TSMstart / (scale / 40.0)) * (250 - 21) / log10(scale / (scale / 40.0))), V2f(93, 2), YELLOW, RE,
	//		fenetre, ecart); //Indication Marker
	//LES GRADIENT
	gradientProfile(scale, delta_distance, tab_grad);
}

void Planning::Orders_and_announcements(int scale, float delta_distance, vector<Announcements> &tab_pa, vector<Symbol> & symbol)
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
			symbol[tab_pa[i].getnumero()].afficher(V2f(position + 12, target));

		tab_pa[i].setDistance(tab_pa[i].getDistance() - delta_distance);
		if(tab_pa[i].getDistance() <= 0)
		{
			tab_pa.erase(tab_pa.begin()+i);
		}
	}
}

void Planning::gradientProfile(int scale, float delta_distance, vector<Gradient> &tab_grad)
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
			rectangle(V2f(54 + 280 + 40 + 25 * 3, 283 - 2 - hauteur - taille), V2f(18, 1), WHITE);
			rectangle(V2f(54 + 280 + 40 + 25 * 3, 283 - 1 - hauteur - taille), V2f(1, 1 + taille), WHITE);
			rectangle(V2f(54 + 280 + 40 + 25 * 3 + 1, 283 - 1 - hauteur - taille), V2f(17, taille), couleur);
			rectangle(V2f(54 + 280 + 40 + 25 * 3, 283 - 1 - hauteur), V2f(18, 1), BLACK);
			if(couleur == GREY)
				couleur = BLACK;
			else if(couleur == DARK_GREY)
				couleur = WHITE;
			if(taille > 30)
			{
				creation_texte(sens, couleur, 12, 0, V2f(54 + 280 + 40 + 25 * 3 + 18 / 2.0, 283 - hauteur - taille + 12), 1); //400km/h
				creation_texte(sens, couleur, 12, 0, V2f(54 + 280 + 40 + 25 * 3 + 18 / 2.0, 283 - hauteur - 12), 1); //400km/h
			}
			if(taille > 50)
				creation_texte(to_string(valeur), couleur, 12, 0, V2f(54 + 280 + 40 + 25 * 3 + 18 / 2.0, 283 - hauteur - taille / 2.0), 1); //400km/h
		}
	}
}

void Planning::SpeedProfileDiscontinuityInformation(int scale, float delta_distance, vector<Announcements> &tab_paf, vector<Symbol> & symbol)
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
			symbol[tab_paf[i].getnumero()].afficher(V2f(54 + 280 + 40 + 3 * 25 + 18 + 13, target + 10));
			if(tab_paf[i].getVitesse() > 99)
				position = 19;
			else if(tab_paf[i].getVitesse() > 9)
				position = 20 - 4;
			else
				position = 20 - 7;
			if(tab_paf[i].getnumero() == 92)
				creation_texte(to_string(tab_paf[i].getVitesse()), GREY, 11, 0, V2f(54 + 280 + 40 + 3 * 25 + 18 + 13 + position, target + 9), 1);
			if(tab_paf[i].getnumero() == 91)
				creation_texte(to_string(tab_paf[i].getVitesse()), GREY, 11, 0, V2f(54 + 280 + 40 + 3 * 25 + 18 + 13 + position, target + 14), 1);
		}
		tab_paf[i].setDistance(tab_paf[i].getDistance() - delta_distance);
		if(tab_paf[i].getDistance() <= 0)
		{
			tab_paf.erase(tab_paf.begin()+i);
		}
	}
}

Planning::Planning(vector<Symbol> &symbol) : pasp0(400, 40000), pasp1(225, 3000), pasp2(150, 5000), pasp5(0, 8000), gradient1(2001, 2000, 20), gradient2(0, 2000, 0), gradient3(10000, 5000, -5),
	gradient4(4001, 6000, 0), gradient5(15001, 7000, 35), PA1(1500, 98), PA2(1000, 72), PA3(3000, 97), PA6(4000, 75)
{
	this->symbol = symbol;

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


class Main : public Fenetre, public LeftSide
{
	private :
		Planning planning;
	public :
};


class Menu : public Fenetre
{
	protected :
		Data *data;
		RenderWindow *fenetre;
		void menu(vector <string> selection, vector <int>& enable, vector<Symbol> & symbol, string title);
};

void Menu::menu(vector <string> selection, vector <int>& enable, vector<Symbol> & symbol, string title)
{
	Color color;
	rectangle(V2f(54 + 280, 0), V2f(266, 24), BLACK);
	NA_11.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0));	//H5
	for(int i = 0; i < (int)selection.size(); i++)
	{
		if(enable[i] == 0)
			color = GREY;
		else if(enable[i] == 1)
			color = DARK_GREY;
		if(enable[i] != 2)
		{
			creation_texte(to_string(i + 1) + " - " + selection[i], color, 12, 0, V2f(54 + 280 + 15, 100 + 6 + i * 20), 4);
			creation_texte(to_string(i + 1), color, 16, 0, V2f(64 / 2.0 + i * 64, 430 + 50 / 2.0), 1);
		}
	}
	creation_texte(title, GREY, 12, 0, V2f(54 + 280 + 3, 12), 4);
}

class DataEntry : public Fenetre
{
	protected :
		//void dataEntry(vector<vector<string>> input_field, vector<Symbol> & symbol, int complete, string title, vector<string> selection, int & sel, string keyboard, vector<Button> & boutons, string & ecran);
};*/
/*
void DataEntry::dataEntry(vector<vector<string>> input_field, vector<Symbol> & symbol, int complete, string title, vector<string> selection, int & sel, string keyboard, vector<Button> & boutons, string & ecran)
{
	for(int i = 0; i <= 9; i++)
		boutons[i].settype("down_type");
	if(keyboard == "numeric")
	{
		NA_21.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 / 2.0));			//H2
		boutons[10].settype("down_type");
		for(int i = 1; i <= 10; i++)
			creation_texte(to_string(i % 10), GREY, 16, 0, V2f(- 64 / 2.0 + i * 64, 430 + 50 / 2.0), 1);
	}
	else if(keyboard == "enhanced numeric")
	{
		NA_21.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 / 2.0));			//H2
		creation_texte("1.  ", GREY, 16, 0, V2f(- 64 / 2.0 + 1 * 64, 430 + 50 / 2.0), 3);
		for(int i = 2; i <= 10; i++)
			creation_texte(to_string(i % 10), GREY, 16, 0, V2f(- 64 / 2.0 + i * 64, 430 + 50 / 2.0), 1);
	}
	else if(keyboard == "alphanumeric")
	{
		NA_21.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 / 2.0));			//H2
		creation_texte("1", GREY, 16, 0, V2f(- 64 / 2.0 + 1 * 64, 430 + 50 / 2.0), 1);
		creation_texte("2abc", GREY, 16, 0, V2f(- 64 / 2.0 + 2 * 64, 430 + 50 / 2.0), 3);
		creation_texte("3def", GREY, 16, 0, V2f(- 64 / 2.0 + 3 * 64, 430 + 50 / 2.0), 3);
		creation_texte("4hij", GREY, 16, 0, V2f(- 64 / 2.0 + 4 * 64, 430 + 50 / 2.0), 3);
		creation_texte("5klm", GREY, 16, 0, V2f(- 64 / 2.0 + 5 * 64, 430 + 50 / 2.0), 3);
		creation_texte("6nop", GREY, 16, 0, V2f(- 64 / 2.0 + 6 * 64, 430 + 50 / 2.0), 3);
		creation_texte("7qrs", GREY, 16, 0, V2f(- 64 / 2.0 + 7 * 64, 430 + 50 / 2.0), 3);
		creation_texte("8tuv", GREY, 16, 0, V2f(- 64 / 2.0 + 8 * 64, 430 + 50 / 2.0), 3);
		creation_texte("9wxyz", GREY, 16, 0, V2f(- 64 / 2.0 + 9 * 64, 430 + 50 / 2.0), 3);
		creation_texte("0", GREY, 16, 0, V2f(- 64 / 2.0 + 10 * 64, 430 + 50 / 2.0), 1);
	}
	else if(keyboard == "dedicated keyboard")
    {
        for(int i = 1; i <= (int)selection.size(); i++)
            creation_texte(to_string(i % 10), GREY, 16, 0, V2f(- 64 / 2.0 + i * 64, 430 + 50 / 2.0), 1);
        if(selection.size() >= 10)
            boutons[9].settype("up_type");
    }
	if(boutons[14].getactivation())
		sel = sel % input_field.size() + 1;
	else if(boutons[13].getactivation())
	{
		if(sel != 1)
			sel--;
		else
			sel = input_field.size();
	}
	int numero = sel;
	string sequenceNumber;
	Color color;
	if(complete == 1 && input_field.size() > 4)
		sequenceNumber = string(" (") + to_string((int)ceil(numero / 4.0)) + "/" + to_string((int)ceil(input_field.size() / 4.0)) + ")";
	else if(complete == 0 && input_field.size() > 3)
		sequenceNumber = string(" (") + to_string((int)ceil(numero / 3.0)) + "/" + to_string((int)ceil(input_field.size() / 3.0)) + ")";
	if(((int)ceil(numero / 4.0) == 1 && complete == 1) || ((int)ceil(numero / 3.0) == 1 && complete == 0))
	{
		NA_11.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0));		//H3
		boutons[11].settype("up_type");
		close(ecran, boutons, sel);
	}
	else
	{
		NA_18.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0));		//H3
		boutons[11].settype("up_type");
		if(boutons[11].getactivation())
		{
			while(sel % 4 != 0)
				sel--;
			sel = sel - 3;
		}
	}
	if((((complete == 1 && input_field.size() > 4 && (int)ceil(numero / 4.0) == (int)ceil(input_field.size() / 4.0)) || (complete == 0 && input_field.size() > 3 &&
		(int)ceil(numero / 3.0) == (int)ceil(input_field.size() / 3.0)))))
	{
		NA_18_2.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2+ 64 / 2.0));	//H4
		boutons[12].settype("disabled");
	}
	else if((complete == 1 && input_field.size() > 4) || (complete == 0 && input_field.size() > 3))
	{
		boutons[12].settype("up_type");
		NA_17.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2+ 64 / 2.0));	//H4
		if(boutons[12].getactivation())
		{
			while(sel % 4 != 0)
				sel++;
			sel++;
		}
	}
	if(input_field.size() > 1)
	{
		NA_14.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 4 + 64 / 2.0));	//H6
		NA_13.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 3 + 64 / 2.0));	//H5
	}
	NA_20.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 5 + 41));			//H7
	if(complete)
	{
		rectangle(V2f(0, 380), V2f(334, 50), DARK_GREY);
		rectangle(V2f(0, 380), V2f(334 - 1, 50 - 1), WHITE);
		rectangle(V2f(0 + 1, 380 + 1), V2f(334 - 2, 50 - 2), MEDIUM_GREY);
		creation_texte("Yes", BLACK, 12, 0, V2f(334 / 2.0, 380 + 25), 1);
		creation_texte(title + " entry complete ?", GREY, 12, 0, V2f(334 / 2.0, 330 + 25), 1);
		rectangle(V2f(0, 0), V2f(334, 24), BLACK);
		creation_texte(title + sequenceNumber, GREY, 12, 0, V2f(54 + 280 - 3, 12), 2);
	}
	else
	{
		rectangle(V2f(54 + 280, 0), V2f(266, 24), BLACK);
		creation_texte(title, GREY, 12, 0, V2f(54 + 280 + 3, 12), 4);
	}
	if(input_field.size() == 1)
	{
		rectangle(V2f(54 + 280, 50), V2f(266, 50), DARK_GREY);
		rectangle(V2f(54 + 280, 50), V2f(266 - 1, 50 - 1), WHITE);
		rectangle(V2f(54 + 280 + 1, 50 + 1), V2f(266 - 2, 50 - 2), MEDIUM_GREY);
		creation_texte(input_field[0][1], BLACK, 12, 0, V2f(54 + 280 + 10, 25 + 50), 4);
	}
	else
	{
		if(complete)
		{
			if(numero % 4)
				numero = numero - numero % 4;
			else
				numero = numero - 4;
		}
		else
			numero = numero - numero % 3;
		for(int i = numero; i <= min((int)input_field.size() - 1, 3 + numero); i++)
		{
			rectangle(V2f(54 + 280, 50 * (i - numero) + 50 * (1 - complete)), V2f(164, 50), MEDIUM_GREY);
			rectangle(V2f(54 + 280 + 1, 50 * (i - numero) + 1 + 50 * (1 - complete)), V2f(164 - 2, 50 - 2), BLACK);
			rectangle(V2f(54 + 280 + 1, 1 + 50 * (i - numero) + 50 * (1 - complete)), V2f(164 - 2, 50 - 2), DARK_GREY);
			if(i == sel - 1)
			{
				rectangle(V2f(54 + 280 + 164, 50 * (i - numero) + 50 * (1 - complete)), V2f(102, 50), DARK_GREY);
				rectangle(V2f(54 + 280 + 164, 50 * (i - numero) + 50 * (1 - complete)), V2f(102 - 1, 50 - 1), WHITE);
				rectangle(V2f(54 + 280 + 164 + 1, 50 * (i - numero) + 1 + 50 * (1 - complete)), V2f(102 - 2, 50 - 2), MEDIUM_GREY);
			}
			else
			{
				rectangle(V2f(54 + 280 + 164, 50 * (i - numero) + 50 * (1 - complete)), V2f(102, 50), MEDIUM_GREY);
				rectangle(V2f(54 + 280 + 164 + 1, 50 * (i - numero) + 1 + 50 * (1 - complete)), V2f(102 - 2, 50 - 2), BLACK);
				rectangle(V2f(54 + 280 + 164 + 1, 1 + 50 * (i - numero) + 50 * (1 - complete)), V2f(102 - 2, 50 - 2), DARK_GREY);
			}
			creation_texte(input_field[i][0], GREY, 12, 0, V2f(54 + 280 + 10, 50 * (i - numero) + 25 + 50 * (1 - complete)), 4);
			if(i == sel - 1)
			{
				if(train.getClignotementTexte() / 30 <= 1)
				{
					creation_texte(input_field[i][1], BLACK, 12, 0, V2f(54 + 280 + 164 + 10, 50 * (i - numero) + 25 + 50 * (1 - complete)), 4);
					train.setClignotementTexte(train.getClignotementTexte() + 1);
				}
				else if (train.getClignotementTexte()/30 <= 2)
				{
					creation_texte(input_field[i][1] + "_", BLACK, 12, 0, V2f(54 + 280 + 164 + 10, 50 * (i - numero) + 25 + 50 * (1 - complete)), 4);
					train.setClignotementTexte(train.getClignotementTexte() + 1);
				}
				else
					train.setClignotementTexte(0);
			}
			else if(input_field[i][2] == "1")
				creation_texte(input_field[i][1], WHITE, 12, 0, V2f(54 + 280 + 164 + 10, 50 * (i - numero) + 25 + 50 * (1 - complete)), 4);
			else
				creation_texte(input_field[i][1], GREY, 12, 0, V2f(54 + 280 + 164 + 10, 50 * (i - numero) + 25 + 50 * (1 - complete)), 4);
		}
	}
	for(int i = 0; i < (int)selection.size(); i++)
		creation_texte(to_string(i + 1) + " - " + selection[i], GREY, 12, 0, V2f(54 + 280 + 15, 200 + 15 + 6 + i * 20), 4);
}
*/
/*
class Special : public Menu
{
	private :
		RenderWindow *fenetre;
		Data *data;
	public :
		Special(RenderWindow &fenetre, Data &data);
};

Special::Special(RenderWindow &fenetre, Data &data)
{
	this->fenetre = &fenetre;
	this->data = &data;
}

class Settings : public Menu
{
	private :
		RenderWindow *fenetre;
		Data *data;
	public :
		Settings(RenderWindow &fenetre, Data &data);
};

Settings::Settings(RenderWindow &fenetre, Data &data)
{
	this->fenetre = &fenetre;
	this->data = &data;
}

class SRspeed : public Menu
{
	private :
		RenderWindow *fenetre;
		Data *data;
	public :
		SRspeed(RenderWindow &fenetre, Data &data);
};

SRspeed::SRspeed(RenderWindow &fenetre, Data &data)
{
	this->fenetre = &fenetre;
	this->data = &data;
}

class DataView : public Menu
{
	private :
		RenderWindow *fenetre;
		Data *data;
	public :
		DataView(RenderWindow &fenetre, Data &data);
};

DataView::DataView(RenderWindow &fenetre, Data &data)
{
	this->fenetre = &fenetre;
	this->data = &data;
}

class SystemVersion : public Menu
{
	private :
		RenderWindow *fenetre;
		Data *data;
	public :
		SystemVersion(RenderWindow &fenetre, Data &data);
};

SystemVersion::SystemVersion(RenderWindow &fenetre, Data &data)
{
	this->fenetre = &fenetre;
	this->data = &data;
}


*/