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

Vector2f DonneesAfficheurVitesse::local2globalCoordonates(Vector2f localOrigin, float teta_origine)
{
	Vector2f Coordonnees;
	m_cartesiens.x = localOrigin.x - (-1) * m_polaire.x * cos((m_polaire.y - teta_origine) * PI / 180.0); //PI/180 permet de passer de la valeur de radians a une valeur en degree
	m_cartesiens.y = localOrigin.y - (-1) * m_polaire.x * sin((m_polaire.y - teta_origine) * PI / 180.0); // le facteur -1 permet de se mettre dans le cas du cercle trigonometrique
	return m_cartesiens;
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

void Symbol::loadSymbol(string chemin_dacces)
{
	if (!image.loadFromFile(chemin_dacces)) // Si le chargement du fichier a �chou�
	{
	     cout<<"Erreur durant le chargement de l'image"<<endl;
	}
	else // Si le chargement de l'image a r�ussi
	{
		texture.loadFromImage(image);

	}
}

void Symbol::afficher(V2f position, double RE, int * ecart, RenderWindow & fenetre)
{
	Sprite spr;
	sprite.push_back(spr);
	int m = sprite.size() - 1;
	sprite[m].setTexture(texture);
	sprite[m].setScale(RE,RE);
	position.x = position.x * RE - sprite[m].getGlobalBounds().width / 2 + ecart[0] * RE;
	position.y = position.y * RE - sprite[m].getGlobalBounds().height / 2 + ecart[1] * RE;
	sprite[m].setPosition(position);
	m_color = sprite[m].getColor();
	m_color.a = 255;
	sprite[m].setColor(m_color);
	fenetre.draw(sprite[m]);
}

void Symbol::effacer()
{
	int m = sprite.size();
	for(int i = 0; i < m; i++)
	{
		sprite.erase(sprite.begin());
	}
	/*m_color = sprite[0].getColor();
	m_color.a = 0;
	sprite[0].setColor(m_color);*/
}

void initSymbol(vector<Symbol> & symbol)
{
	Symbol image;
	vector<string> nom{"DR_01", "DR_02", "DR_03", "DR_04", "DR_05", "LE_01", "LE_02", "LE_02a", "LE_03", "LE_04", "LE_05", "LE_06", "LE_07", "LE_08", "LE_08a", "LE_09", "LE_09a", "LE_10", "LE_11", "LE_12",
	"LE_13", "LE_14", "LE_15", "LS_01", "LX_01", "MO_01", "MO_02", "MO_03", "MO_04", "MO_05", "MO_06", "MO_07", "MO_08", "MO_09", "MO_10", "MO_11", "MO_12", "MO_13", "MO_14", "MO_15", "MO_16", "MO_17",
	"MO_18", "MO_19", "MO_20", "MO_21", "MO_22", "NA_01", "NA_02", "NA_03", "NA_04", "NA_05", "NA_06", "NA_07", "NA_08", "NA_09", "NA_10", "NA_11", "NA_12", "NA_13", "NA_14", "NA_15", "NA_16", "NA_17",
	"NA_18", "NA_18_2", "NA_19", "NA_20", "NA_21", "NA_22", "NA_23", "PL_01", "PL_02", "PL_03", "PL_04", "PL_05", "PL_06", "PL_07", "PL_08", "PL_09", "PL_10", "PL_11", "PL_12", "PL_13", "PL_14", "PL_15",
	"PL_16", "PL_17", "PL_18", "PL_19", "PL_20", "PL_21", "PL_22", "PL_23", "PL_24", "PL_25", "PL_26", "PL_27", "PL_28", "PL_29", "PL_30", "PL_31", "PL_32", "PL_33", "PL_34", "PL_35", "PL_36", "SE_01",
	"SE_02", "SE_03", "SE_04", "ST_01", "ST_02", "ST_03", "ST_04", "ST_05", "ST_06", "TC_01", "TC_02", "TC_03", "TC_04", "TC_05", "TC_06", "TC_07", "TC_08", "TC_09", "TC_10", "TC_11", "TC_12", "TC_13",
	"TC_14", "TC_15", "TC_16", "TC_17", "TC_18", "TC_19", "TC_20", "TC_21", "TC_22", "TC_23", "TC_24", "TC_25", "TC_26", "TC_27", "TC_28", "TC_29", "TC_30", "TC_31", "TC_32", "TC_33", "TC_34", "TC_35",
	"TC_36", "TC_37"};
	for(int i = 0; i < int(nom.size()); i++)
	{
		symbol[i].loadSymbol("ressources/symbols/" + nom[i] + ".bmp");
	}
}

void couleurForme(VertexArray & bande,Color col, int n)
{
	for(int i = 0; i < n; i++)
	{
		bande[i].color= col;
	}
}

void rectangle(V2f pos, V2f taille, Color col, double RE, RenderWindow & fenetre, int * ecart)
{
	RectangleShape barre(V2f(taille.x * RE, taille.y * RE));
	barre.setPosition((pos.x + ecart[0]) * RE, (pos.y + ecart[1]) * RE);
	barre.setFillColor(col);
	fenetre.draw(barre);
}

//RESUME DE LA FONCTION
//Besoin de la position de point en haut � gauche et de la dimension du quadrilat�re
//RE permet de modifier l'�paisseur en fct du rapport d'�cran
//mode 1=case mode 2=bouton mode 3=rappelle de la fonction pour cr�ation du carr� int�rieur
void creation_rectangle(V2f pos, V2f dim, double RE, int mode, RenderWindow & fenetre, int * ecart)
{
	if(mode == 1)
	{
		rectangle(pos, dim, SHADOW, RE, fenetre, ecart);
		rectangle(pos, V2f(dim.x - 1, dim.y - 1), BLACK, RE, fenetre, ecart);
		rectangle(V2f(pos.x + 1, pos.y + 1), V2f(dim.x - 2, dim.y - 2), DARK_BLUE, RE, fenetre, ecart);
	}
	if(mode == 2)
	{
		rectangle(pos, dim, SHADOW, RE, fenetre, ecart);
		rectangle(pos, V2f(dim.x - 1, dim.y - 1), BLACK, RE, fenetre, ecart);
		rectangle(V2f(pos.x + 1, pos.y + 1), V2f(dim.x - 3, dim.y - 3), SHADOW, RE, fenetre, ecart);
		rectangle(V2f(pos.x + 2, pos.y + 2), V2f(dim.x - 4, dim.y - 4), DARK_BLUE, RE, fenetre, ecart);
	}
	/*
	int epaisseur = RE;
	VertexArray bande(Quads,4);
	pos.x = pos.x * RE;
	pos.y = pos.y * RE;
	dim.x = dim.x * RE;
	dim.y = dim.y * RE;

	//Creation 1 ere bande
	bande[0].position=pos;
	bande[1].position=V2f(pos.x + dim.x - epaisseur, pos.y);
	bande[2].position=V2f(pos.x + dim.x - epaisseur, pos.y + epaisseur);
	bande[3].position=V2f(pos.x, pos.y + epaisseur);

	if(mode == 3)
	{
		couleurForme(bande, SHADOW, 4);
	}
	else
	{
		couleurForme(bande, BLACK, 4);
	}
	fenetre.draw(bande);

	//Creation 2eme bande
	bande[0].position= pos;
	bande[1].position=V2f(pos.x + epaisseur, pos.y);
	bande[2].position=V2f(pos.x + epaisseur, pos.y + dim.y - epaisseur);
	bande[3].position=V2f(pos.x, pos.y + dim.y - epaisseur);

	if(mode == 3)
	{
		couleurForme(bande, SHADOW, 4);
	}
	else
	{
		couleurForme(bande, BLACK, 4);
	}
	fenetre.draw(bande);

	//Creation 3eme bande
	bande[0].position= V2f(pos.x, pos.y + dim.y - epaisseur);
	bande[1].position=V2f(pos.x + dim.x, pos.y + dim.y - epaisseur);
	bande[2].position=V2f(pos.x + dim.x, pos.y + dim.y);
	bande[3].position=V2f(pos.x, pos.y + dim.y);

	if(mode == 3)
	{
		couleurForme(bande, BLACK, 4);
	}
	else
	{
		couleurForme(bande, SHADOW, 4);
	}

	fenetre.draw(bande);

	//Creation 4eme bande
	bande[0].position= V2f(pos.x+ dim.x - epaisseur, pos.y);
	bande[1].position=V2f(pos.x + dim.x, pos.y);
	bande[2].position=V2f(pos.x + dim.x, pos.y + dim.y);
	bande[3].position=V2f(pos.x+ dim.x - epaisseur, pos.y + dim.y);

	if(mode == 3)
	{
		couleurForme(bande, BLACK, 4);
	}
	else
	{
		couleurForme(bande, SHADOW, 4);
	}
	fenetre.draw(bande);

	if(mode == 2)		//CREER LE CARRE INTERIEUR POUR UN BOUTON
	{
		pos.x = pos.x + epaisseur;
		pos.y = pos.y + epaisseur;
		dim.x = dim.x - 2 * epaisseur;
		dim.y = dim.y - 2 * epaisseur;

		creation_rectangle(pos, dim,3, 3, fenetre, ecart);
	}
	*/

}

void creation_texte(double RE, string message, Font police, Color couleur, int taille, double OutlineThickness, V2f pos, RenderWindow & fenetre, int mode, int * ecart) //mode 1 : centrer / mode 2 : aligner droite / mode 3 : Geographical position / mode 4 : aligner gauche
{
	Text texte;
	texte.setString(message);
	texte.setFont(police);
	texte.setOutlineThickness(OutlineThickness);
	texte.setOutlineColor(couleur);
	texte.setCharacterSize(taille * RE);
	texte.setFillColor(couleur);
	if(mode == 2)
		texte.setOrigin(texte.getLocalBounds().left + texte.getLocalBounds().width * 1.0f, texte.getLocalBounds().top + texte.getLocalBounds().height / 2.0f);
	else if(mode == 4)
	{
		if(message[message.size() - 1] == '_')
		{
			message = message.substr(0, message.size() - 1);
		}

		texte.setOrigin(texte.getLocalBounds().left, texte.getLocalBounds().top + texte.getLocalBounds().height / 2.0f);
		if(message[message.size() - 1] == '_')
		{
			message += "_";
			texte.setOrigin(texte.getLocalBounds().left, (pos.y + ecart[1]) * RE);
		}
	}
	else if(mode == 3 && message.size() > 3)
	{
		Text metre;
		if(couleur == BLACK)
			metre.setString(message.substr(message.size() - 3, 3));
		else
			metre.setString(message.substr(1, message.size() - 1));
		if(message.size() > 6)
			message = message.substr(0, message.size() - 6) + " " + message.substr(message.size() - 6, 6);
		if(couleur == BLACK)
			message = message.substr(0, message.size() - 3) + " ";
		else
			message = message.substr(0, 1) + " ";
		texte.setString(message);
		metre.setFont(police);
		metre.setOutlineThickness(OutlineThickness);
		metre.setOutlineColor(couleur);
		metre.setCharacterSize(10 * RE);
		metre.setFillColor(couleur);
		texte.setOrigin(texte.getLocalBounds().left + (texte.getLocalBounds().width + metre.getLocalBounds().width) / 2.0f, texte.getLocalBounds().top + texte.getLocalBounds().height / 2.0f);
		metre.setOrigin(metre.getLocalBounds().left - (texte.getLocalBounds().width - metre.getLocalBounds().width) / 2.0f, metre.getLocalBounds().top - texte.getLocalBounds().height / 2.0f + metre.getLocalBounds().height * 1.0f);
		metre.setPosition((pos.x + ecart[0]) * RE * 1.0f, (pos.y + ecart[1]) * RE * 1.0f);
		fenetre.draw(metre);
	}
	else if(mode == 1 || mode == 3)
	{
		if(mode == 3)
			texte.setCharacterSize(10 * RE);
		texte.setOrigin(texte.getLocalBounds().left + texte.getLocalBounds().width / 2.0f, texte.getLocalBounds().top + texte.getLocalBounds().height / 2.0f);
	}
	texte.setPosition((pos.x + ecart[0]) * RE * 1.0f, (pos.y + ecart[1]) * RE * 1.0f);
	fenetre.draw(texte);
}

void targetDistance(int distance, RenderWindow & fenetre, double RE, Font & arial, int * ecart)
{
	if(distance >= 0)
	{
		creation_texte(RE, to_string((int)round((distance / 10.0)) * 10), arial, GREY, 10, 0, V2f(54 / 2.0, 54 + 30 / 2.0), fenetre, 1, ecart);
		rectangle(V2f(12, 54 + 30 - 1), V2f(13, 2), GREY, RE, fenetre, ecart);
		rectangle(V2f(16, 54 + 30 + 6), V2f(9, 1), GREY, RE, fenetre, ecart);
		rectangle(V2f(16, 54 + 30 + 13), V2f(9, 1), GREY, RE, fenetre, ecart);
		rectangle(V2f(16, 54 + 30 + 22), V2f(9, 1), GREY, RE, fenetre, ecart);
		rectangle(V2f(16, 54 + 30 + 32), V2f(9, 1), GREY, RE, fenetre, ecart);
		rectangle(V2f(12, 54 + 30 + 45), V2f(13, 2), GREY, RE, fenetre, ecart);
		rectangle(V2f(16, 54 + 30 + 59), V2f(9, 1), GREY, RE, fenetre, ecart);
		rectangle(V2f(16, 54 + 30 + 79), V2f(9, 1), GREY, RE, fenetre, ecart);
		rectangle(V2f(16, 54 + 30 + 105), V2f(9, 1), GREY, RE, fenetre, ecart);
		rectangle(V2f(16, 54 + 30 + 152), V2f(9, 1), GREY, RE, fenetre, ecart);
		rectangle(V2f(12, 54 + 30 + 185), V2f(13, 2), GREY, RE, fenetre, ecart);
		if(distance <= 100)
		{
			rectangle(V2f(29 , 85 + 185 * ( 1 - (1.722*pow(10,-3)*distance))), V2f(10, 185 * (1.722*pow(10,-3)*distance)), GREY, RE, fenetre, ecart);
		}
		else if(distance <= 1000)
		{
			rectangle(V2f(29, 186 + 54 + 30 - (185 - 152)), V2f(10, 185 - 152), GREY, RE, fenetre, ecart);
			rectangle(V2f(29 , 85 + 185 * ( 1 - (log(distance*(1/58.8236)) / log(17)))), V2f(10, 185 * (log(distance*(1/58.8236)) / log(17))), GREY, RE, fenetre, ecart);

		}
		else
		{
			rectangle(V2f(29, 186  + 54 + 30 -185), V2f(10, 185), GREY, RE, fenetre, ecart);
		}
	}
}
