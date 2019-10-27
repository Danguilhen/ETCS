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
#include "symbol.hpp"
#include "donnees.hpp"

DonneesAfficheurVitesse::DonneesAfficheurVitesse()
{
	m_cartesiens.x = 0;
	m_cartesiens.y = 0;
	m_polaire.x = 0;
	m_polaire.y = 0;
	m_vitesse = 0;
}

DonneesAfficheurVitesse::DonneesAfficheurVitesse(Vector2f cartesiens, Vector2f polaire, int vitesse)
{
	m_cartesiens = cartesiens;
	m_polaire = polaire;
	m_vitesse = vitesse;
}

void DonneesAfficheurVitesse::cartesiens(Vector2f cartesiens) {m_cartesiens = cartesiens;}
void DonneesAfficheurVitesse::polaire(Vector2f polaire) {m_polaire = polaire;}
void DonneesAfficheurVitesse::x(int x) {m_cartesiens.x = x;} // set x
void DonneesAfficheurVitesse::y(int y) {m_cartesiens.y = y;} // set y
void DonneesAfficheurVitesse::r(int r) {m_polaire.x = r;} // set r
void DonneesAfficheurVitesse::teta(int teta) {m_polaire.y = teta;} // set teta
void DonneesAfficheurVitesse::vitesse(int vitesse) {m_vitesse = vitesse;} // set vitesse
Vector2f DonneesAfficheurVitesse::cartesien() {return m_cartesiens;}
Vector2f DonneesAfficheurVitesse::polaire() {return m_polaire;}
float DonneesAfficheurVitesse::x() {return m_cartesiens.x;}
float DonneesAfficheurVitesse::y() {return m_cartesiens.y;}
float DonneesAfficheurVitesse::r() {return m_polaire.x;}
float DonneesAfficheurVitesse::teta() {return m_polaire.y;}
int DonneesAfficheurVitesse::vitesse() {return m_vitesse;}



void Cadran::indicateurVitesse(V2f centre, Color couleurAiguille, double RE, RenderWindow & fenetre, Font & arial, DonneesAfficheurVitesse graduations[], int Vmax, int * ecart)
{
	V2f position;
	CircleShape Centre;
	Centre.setFillColor(couleurAiguille);
	Centre.setPosition(V2f(centre.x - 25 * RE,centre.y - 25 * RE));
	Centre.setRadius(25 * RE);
	fenetre.draw(Centre);
	float teta_origine = 90 + 144;
	float tetaep = 0.5;

	VertexArray Barre(Quads, 4);

	// trace d'une barre
	//definition de la couleur de chaque points

	couleurForme(Barre, WHITE, 4);

	///////////////////////////////////////////////////////////////////////////////
	//affichage des graduations

	for(int i = 0; i <= Vmax; i = i + 10) //i correspond a la vitesse
	{
		if((Vmax == 400 && i % 50 == 0) || (Vmax != 400 && i % 20 == 0))
		{ //affiche des barres plus longues tous les 50km/h
			//positionnement de chaque points
			Barre[0].position = local2globalCoordonates(centre, teta_origine,V2f(RE * 125, graduations[i].teta() - tetaep / 2));
			Barre[1].position = local2globalCoordonates(centre, teta_origine,V2f(RE * 125, graduations[i].teta() + tetaep / 2));
			Barre[2].position = local2globalCoordonates(centre, teta_origine,V2f(RE * (125 - 25), graduations[i].teta() + tetaep / 2));
			Barre[3].position = local2globalCoordonates(centre, teta_origine,V2f(RE * (125 - 25), graduations[i].teta() - tetaep / 2));
			if(i != 250 && i != 350)
			{
				position = local2globalCoordonates(centre,teta_origine,V2f(83 * RE, graduations[i].teta()));
				creation_texte(RE, to_string(graduations[i].vitesse()), arial, WHITE, 16, 0, V2f(position.x / RE - ecart[0], position.y / RE - ecart[1]), fenetre, 1, ecart);
			}
		}
		else
		{
			//positionnement de chaque points
			Barre[0].position = local2globalCoordonates(centre,teta_origine,V2f(RE * 125, graduations[i].teta() - tetaep / 2));
			Barre[1].position = local2globalCoordonates(centre,teta_origine,V2f(RE * 125, graduations[i].teta() + tetaep / 2));
			Barre[2].position = local2globalCoordonates(centre,teta_origine,V2f(RE * (125 - 15), graduations[i].teta() + tetaep / 2));
			Barre[3].position = local2globalCoordonates(centre,teta_origine,V2f(RE * (125 - 15), graduations[i].teta() - tetaep / 2));
		}
		fenetre.draw(Barre);
	}

	//ecriture des vitesses
	//position = local2globalCoordonates(centre,teta_origine,V2f(200,graduations[0].teta()));
	//creation_texte(RE, to_string(graduations[0].vitesse()), arial, WHITE, 16, 0, V2f(position.x / RE, position.y / RE), fenetre, 1); //0km/h
	//position = local2globalCoordonates(centre,teta_origine,V2f(200,graduations[50].teta()));
	//creation_texte(RE, to_string(graduations[50].vitesse()), arial, WHITE, 16, 0, V2f(position.x / RE, position.y / RE), fenetre, 1); //50km/h
	//position = local2globalCoordonates(centre,teta_origine,V2f(200,graduations[100].teta()));
	//creation_texte(RE, to_string(graduations[100].vitesse()), arial, WHITE, 16, 0, V2f(position.x / RE, position.y / RE), fenetre, 1); //100km/h
	//position = local2globalCoordonates(centre,teta_origine,V2f(200,graduations[150].teta()));
	//creation_texte(RE, to_string(graduations[150].vitesse()), arial, WHITE, 16, 0, V2f(position.x / RE, position.y / RE), fenetre, 1); //150km/h
	//position = local2globalCoordonates(centre,teta_origine,V2f(200,graduations[200].teta()));
	//creation_texte(RE, to_string(graduations[200].vitesse()), arial, WHITE, 16, 0, V2f(position.x / RE, position.y / RE), fenetre, 1); //200km/h
	//position = local2globalCoordonates(centre,teta_origine,V2f(200,graduations[300].teta()));
	//creation_texte(RE, to_string(graduations[300].vitesse()), arial, WHITE, 16, 0, V2f(position.x / RE, position.y / RE), fenetre, 1); //300km/h
	//position = local2globalCoordonates(centre,teta_origine,V2f(200,graduations[400].teta()));
	//creation_texte(RE, to_string(graduations[400].vitesse()), arial, WHITE, 16, 0, V2f(position.x / RE, position.y / RE), fenetre, 1); //400km/h
}

V2f Cadran::local2globalCoordonates(V2f localOrigin, float teta_origine, V2f CoordonneesPolaires)
{
	V2f Coordonnees;
	Coordonnees.x = localOrigin.x - (- 1) * CoordonneesPolaires.x* cos((CoordonneesPolaires.y-teta_origine)* PI / 180.0); //PI/180 permet de passer de la valeur de radians a une valeur en degree
	Coordonnees.y = localOrigin.y - (- 1) * CoordonneesPolaires.x* sin((CoordonneesPolaires.y-teta_origine)* PI / 180.0); // le facteur -1 permet de se mettre dans le cas du cercle trigonometrique
	return Coordonnees;
}

Cadran::Cadran(double RE, int Vmax, DonneesAfficheurVitesse graduations[], int * ecart)	//aiguille = dessinAiguilleIV(centreIV, RE); a modifier !!!!!!    //centreIV = initValeurIndicateurVitesse(Vmax, RE, graduations, ecart); !!
{
	centre.x = RE * (54 + 280 / 2.0 + ecart[0]);
	centre.y = RE * (300 / 2.0 + ecart[1]);

	aiguille.setPointCount(8);
	aiguille.setPosition(centre);

	aiguille.setPoint(0,V2f(- (80 + 25) * RE, - 3 / 2.0 * RE));
	aiguille.setPoint(1,V2f(- (80 + 25) * RE, 3 / 2.0 * RE));
	aiguille.setPoint(2,V2f(- (80 + 25 - 15) * RE, 3 / 2.0 * RE));
	aiguille.setPoint(3,V2f(- (57 + 25) * RE,9 / 2.0 * RE));
	aiguille.setPoint(4,V2f(- 20 * RE,9 / 2.0 * RE));
	aiguille.setPoint(5,V2f(- 20 * RE, - 9 / 2.0 * RE));
	aiguille.setPoint(6,V2f(- (57 + 25) * RE, - 9 / 2.0 * RE));
	aiguille.setPoint(7,V2f(- (80 + 25 - 15) * RE, - 3 / 2.0 * RE));


	int Vfaible;
	float kmh2degVfaible;
	int workWidth = VideoMode::getDesktopMode().width * 49 / 100.0;
	int widthMargin = workWidth * 3 / 100.0;
	float teta_origine = 90 + 144; //decalage d'angle par rapport a un repere trigonometrique place la valeur 0
	float r = workWidth / 2.0 - widthMargin * 5;
	float teta = 0;
	if(Vmax == 400) //petite vitesse : differentes echelles entre 0 et 200 et 200 et 400
	{
		Vfaible = 200;
		kmh2degVfaible = 144.0 / 150;
	}
	else
	{
		Vfaible = Vmax;
		kmh2degVfaible = 144.0 / (Vmax / 2.0);
	}
	float kmh2degVeleve = kmh2degVfaible / 2.0;

	V2f polaire(r,teta);

	//initialisation
	graduations[0].polaire(polaire);
	graduations[0].local2globalCoordonates(centre,teta_origine);

	for(int i = 1; i <= Vfaible; i++)	//i correspond a la vitesse
	{
		polaire.y = i * kmh2degVfaible;
		graduations[i].polaire(polaire);
		graduations[i].local2globalCoordonates(centre,teta_origine);
		graduations[i].vitesse(i);
	}
	for(int i = 1 + Vfaible; i <= Vmax; i++) //i correspond a la vitesse
	{
		polaire.y = Vfaible * kmh2degVfaible / 2.0 + i * kmh2degVeleve;
		graduations[i].polaire(polaire);
		graduations[i].local2globalCoordonates(centre,teta_origine);
		graduations[i].vitesse(i);
	}
}

void Cadran::arcVitesse(V2f centre, float V_red, float V_orange, float V_yellow, float V_white, float V_medium_grey, float V_dark_grey, double RE, RenderWindow & fenetre, Font & arial, DonneesAfficheurVitesse graduations[], int * ecart)
{
	int V1 = max(max(V_orange, V_red), max(max(V_dark_grey, V_yellow), V_white));
	int V2 = max(max(V_dark_grey, V_yellow), V_white);

	float teta_origine = 90 + 144;
	VertexArray Barre(Quads, 4);
	float deltateta = abs(graduations[0].teta()-graduations[1].teta());
	Color couleur2 = GREY;
	Color couleur4 = BLACK;

	if(V_medium_grey != 0)
		creation_texte(RE, to_string((int)V_medium_grey), arial, GREY, 17, 0, V2f(54 + 26, 274), fenetre, 1, ecart);
	for(int i = V2 + 1; i <= V1; i++)
	{
		if(V_red > V_orange)
			couleurForme(Barre, RED, 4);
		else if(V_red < V_orange)
			couleurForme(Barre, ORANGE, 4);
		Barre[0].position = local2globalCoordonates(centre,teta_origine,V2f(137 * RE,graduations[i].teta() - deltateta / 2.0));
		Barre[1].position = local2globalCoordonates(centre,teta_origine,V2f(137 * RE,graduations[i].teta() + deltateta / 2.0));
		Barre[2].position = local2globalCoordonates(centre,teta_origine,V2f((137 - 20) * RE,graduations[i].teta() + deltateta / 2.0));
		Barre[3].position = local2globalCoordonates(centre,teta_origine,V2f((137 - 20) * RE,graduations[i].teta() - deltateta / 2.0));
		fenetre.draw(Barre);
	}
	for(int i = 0; i<= V2; i++)
	{
		couleurForme(Barre, WHITE, 4);
		Barre[0].position = local2globalCoordonates(centre,teta_origine,V2f(137 * RE,graduations[i].teta() - deltateta / 2.0));
		Barre[1].position = local2globalCoordonates(centre,teta_origine,V2f(137 * RE,graduations[i].teta() + deltateta / 2.0));
		Barre[2].position = local2globalCoordonates(centre,teta_origine,V2f(128 * RE,graduations[i].teta() + deltateta / 2.0));
		Barre[3].position = local2globalCoordonates(centre,teta_origine,V2f(128 * RE,graduations[i].teta() - deltateta / 2.0));
		fenetre.draw(Barre);
	}
	for(int i = (V2 - 2 * asin(3 / float(137 - 20))); i <= V2; i++)
	{
		if(V_yellow > V_dark_grey && V_yellow > V_white)
			couleurForme(Barre, YELLOW, 4);
		else if(V_white > V_dark_grey && V_white > V_yellow)
			couleurForme(Barre, WHITE, 4);
		else
			couleurForme(Barre, DARK_GREY, 4);
		Barre[0].position = local2globalCoordonates(centre,teta_origine,V2f(128 * RE,graduations[i].teta() - deltateta / 2.0));
		Barre[1].position = local2globalCoordonates(centre,teta_origine,V2f(128 * RE,graduations[i].teta() + deltateta / 2.0));
		Barre[2].position = local2globalCoordonates(centre,teta_origine,V2f((128 - 11) * RE,graduations[i].teta() + deltateta / 2.0));
		Barre[3].position = local2globalCoordonates(centre,teta_origine,V2f((128 - 11) * RE,graduations[i].teta() - deltateta / 2.0));
		fenetre.draw(Barre);
	}
	for(int i = V1; i <= V_red; i++)
	{
		couleurForme(Barre, RED, 4);
		Barre[0].position = local2globalCoordonates(centre,teta_origine,V2f(137 * RE,graduations[i].teta() - deltateta / 2.0));
		Barre[1].position = local2globalCoordonates(centre,teta_origine,V2f(137 * RE,graduations[i].teta() + deltateta / 2.0));
		Barre[2].position = local2globalCoordonates(centre,teta_origine,V2f(128 * RE,graduations[i].teta() + deltateta / 2.0));
		Barre[3].position = local2globalCoordonates(centre,teta_origine,V2f(128 * RE,graduations[i].teta() - deltateta / 2.0));
		fenetre.draw(Barre);
	}
	for(int i = 0; i <= V_yellow; i++)
	{
		couleurForme(Barre, YELLOW, 4);
		Barre[0].position = local2globalCoordonates(centre,teta_origine,V2f(137 * RE,graduations[i].teta() - deltateta / 2.0));
		Barre[1].position = local2globalCoordonates(centre,teta_origine,V2f(137 * RE,graduations[i].teta() + deltateta / 2.0));
		Barre[2].position = local2globalCoordonates(centre,teta_origine,V2f(128 * RE,graduations[i].teta() + deltateta / 2.0));
		Barre[3].position = local2globalCoordonates(centre,teta_origine,V2f(128 * RE,graduations[i].teta() - deltateta / 2.0));
		fenetre.draw(Barre);
	}
	for(int i = 0; i <= V_dark_grey; i++)
	{
		couleurForme(Barre, DARK_GREY, 4);
		Barre[0].position = local2globalCoordonates(centre,teta_origine,V2f(137 * RE,graduations[i].teta() - deltateta / 2.0));
		Barre[1].position = local2globalCoordonates(centre,teta_origine,V2f(137 * RE,graduations[i].teta() + deltateta / 2.0));
		Barre[2].position = local2globalCoordonates(centre,teta_origine,V2f(128 * RE,graduations[i].teta() + deltateta / 2.0));
		Barre[3].position = local2globalCoordonates(centre,teta_origine,V2f(128 * RE,graduations[i].teta() - deltateta / 2.0));
		fenetre.draw(Barre);
	}
	for(int i = 1; i <= V_medium_grey; i++)
	{
		couleurForme(Barre, couleur2, 4);
		Barre[0].position = local2globalCoordonates(centre,teta_origine,V2f(137 * RE,graduations[i].teta() - deltateta / 2.0));
		Barre[1].position = local2globalCoordonates(centre,teta_origine,V2f(137 * RE,graduations[i].teta() + deltateta / 2.0));
		Barre[2].position = local2globalCoordonates(centre,teta_origine,V2f((128 + 4)* RE,graduations[i].teta() + deltateta / 2.0));
		Barre[3].position = local2globalCoordonates(centre,teta_origine,V2f((128 + 4)* RE,graduations[i].teta() - deltateta / 2.0));
		fenetre.draw(Barre);
	}
	if(V1 < V_medium_grey)
	{
		for(int i = 1; i <= V1; i++)
		{
			couleurForme(Barre, couleur4, 4);
			Barre[0].position = local2globalCoordonates(centre,teta_origine,V2f((128 + 4) * RE,graduations[i].teta() - deltateta / 2.0));
			Barre[1].position = local2globalCoordonates(centre,teta_origine,V2f((128 + 4) * RE,graduations[i].teta() + deltateta / 2.0));
			Barre[2].position = local2globalCoordonates(centre,teta_origine,V2f((128 + 3)* RE,graduations[i].teta() + deltateta / 2.0));
			Barre[3].position = local2globalCoordonates(centre,teta_origine,V2f((128 + 3)* RE,graduations[i].teta() - deltateta / 2.0));
			fenetre.draw(Barre);
		}
		for(int i = V1 + 1; i <= V_medium_grey; i++) //trait noir
		{
			couleurForme(Barre, couleur2, 4);
			Barre[0].position = local2globalCoordonates(centre,teta_origine,V2f((128 + 4) * RE,graduations[i].teta() - deltateta / 2.0));
			Barre[1].position = local2globalCoordonates(centre,teta_origine,V2f((128 + 4) * RE,graduations[i].teta() + deltateta / 2.0));
			Barre[2].position = local2globalCoordonates(centre,teta_origine,V2f(128* RE,graduations[i].teta() + deltateta / 2.0));
			Barre[3].position = local2globalCoordonates(centre,teta_origine,V2f(128* RE,graduations[i].teta() - deltateta / 2.0));
			fenetre.draw(Barre);
		}
	}
	else
	{
		for(int i = 1; i <= V_medium_grey; i++)
		{
			couleurForme(Barre, couleur4, 4);
			Barre[0].position = local2globalCoordonates(centre,teta_origine,V2f((128 + 4) * RE,graduations[i].teta() - deltateta / 2.0));
			Barre[1].position = local2globalCoordonates(centre,teta_origine,V2f((128 + 4) * RE,graduations[i].teta() + deltateta / 2.0));
			Barre[2].position = local2globalCoordonates(centre,teta_origine,V2f((128 + 3)* RE,graduations[i].teta() + deltateta / 2.0));
			Barre[3].position = local2globalCoordonates(centre,teta_origine,V2f((128 + 3)* RE,graduations[i].teta() - deltateta / 2.0));
			fenetre.draw(Barre);
		}
	}
	for(int i = 0; i <= 4; i++) //Affichage fixe
	{
		couleurForme(Barre, DARK_GREY, 4);
		Barre[0].position = local2globalCoordonates(centre,teta_origine + 4,V2f(137 * RE,graduations[i].teta() - deltateta / 2.0));
		Barre[1].position = local2globalCoordonates(centre,teta_origine + 4,V2f(137 * RE,graduations[i].teta() + deltateta / 2.0));
		Barre[2].position = local2globalCoordonates(centre,teta_origine + 4,V2f(128 * RE,graduations[i].teta() + deltateta / 2.0));
		Barre[3].position = local2globalCoordonates(centre,teta_origine + 4,V2f(128 * RE,graduations[i].teta() - deltateta / 2.0));
		fenetre.draw(Barre);
	}
}