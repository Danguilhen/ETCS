#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
//#include "Fenetres.hpp"

using namespace sf;
using namespace std;

//define ---------------------------------------------------------------------------------------------------------------------------------
#define V2f Vector2f

#define DARK_BLUE Color(3,17,34)
#define SHADOW Color(8,24,57)
#define BLACK Color(0,0,0)
#define WHITE Color(255,255,255)
#define RED Color(191,0,2)
#define ORANGE Color(234,145,0)
#define YELLOW Color(223,223,0)
#define PASP_DARK Color(33,49,74)
#define PASP_LIGHT Color(41,74,107)
#define GREY Color(195,195,195)
#define MEDIUM_GREY Color(150,150,150)
#define DARK_GREY Color(85,85,85)

#define DR_01 symbol[0]
#define DR_02 symbol[1]
#define DR_03 symbol[2]
#define DR_04 symbol[3]
#define DR_05 symbol[4]
#define LE_01 symbol[5]
#define LE_02 symbol[6]
#define LE_02a symbol[7]
#define LE_03 symbol[8]
#define LE_04 symbol[9]
#define LE_05 symbol[10]
#define LE_06 symbol[11]
#define LE_07 symbol[12]
#define LE_08 symbol[13]
#define LE_08a symbol[14]
#define LE_09 symbol[15]
#define LE_09a symbol[16]
#define LE_10 symbol[17]
#define LE_11 symbol[18]
#define LE_12 symbol[19]
#define LE_13 symbol[20]
#define LE_14 symbol[21]
#define LE_15 symbol[22]
#define LS_01 symbol[23]
#define LX_01 symbol[24]
#define MO_01 symbol[25]
#define MO_02 symbol[26]
#define MO_03 symbol[27]
#define MO_04 symbol[28]
#define MO_05 symbol[29]
#define MO_06 symbol[30]
#define MO_07 symbol[31]
#define MO_08 symbol[32]
#define MO_09 symbol[33]
#define MO_10 symbol[34]
#define MO_11 symbol[35]
#define MO_12 symbol[36]
#define MO_13 symbol[37]
#define MO_14 symbol[38]
#define MO_15 symbol[39]
#define MO_16 symbol[40]
#define MO_17 symbol[41]
#define MO_18 symbol[42]
#define MO_19 symbol[43]
#define MO_20 symbol[44]
#define MO_21 symbol[45]
#define MO_22 symbol[46]
#define NA_01 symbol[47]
#define NA_02 symbol[48]
#define NA_03 symbol[49]
#define NA_04 symbol[50]
#define NA_05 symbol[51]
#define NA_06 symbol[52]
#define NA_07 symbol[53]
#define NA_08 symbol[54]
#define NA_09 symbol[55]
#define NA_10 symbol[56]
#define NA_11 symbol[57]
#define NA_12 symbol[58]
#define NA_13 symbol[59]
#define NA_14 symbol[60]
#define NA_15 symbol[61]
#define NA_16 symbol[62]
#define NA_17 symbol[63]
#define NA_18 symbol[64]
#define NA_18_2 symbol[65]
#define NA_19 symbol[66]
#define NA_20 symbol[67]
#define NA_21 symbol[68]
#define NA_22 symbol[69]
#define NA_23 symbol[70]
#define PL_01 symbol[71]
#define PL_02 symbol[72]
#define PL_03 symbol[73]
#define PL_04 symbol[74]
#define PL_05 symbol[75]
#define PL_06 symbol[76]
#define PL_07 symbol[77]
#define PL_08 symbol[78]
#define PL_09 symbol[79]
#define PL_10 symbol[80]
#define PL_11 symbol[81]
#define PL_12 symbol[82]
#define PL_13 symbol[83]
#define PL_14 symbol[84]
#define PL_15 symbol[85]
#define PL_16 symbol[86]
#define PL_17 symbol[87]
#define PL_18 symbol[88]
#define PL_19 symbol[89]
#define PL_20 symbol[90]
#define PL_21 symbol[91]
#define PL_22 symbol[92]
#define PL_23 symbol[93]
#define PL_24 symbol[94]
#define PL_25 symbol[95]
#define PL_26 symbol[96]
#define PL_27 symbol[97]
#define PL_28 symbol[98]
#define PL_29 symbol[99]
#define PL_30 symbol[100]
#define PL_31 symbol[101]
#define PL_32 symbol[102]
#define PL_33 symbol[103]
#define PL_34 symbol[104]
#define PL_35 symbol[105]
#define PL_36 symbol[106]
#define SE_01 symbol[107]
#define SE_02 symbol[108]
#define SE_03 symbol[109]
#define SE_04 symbol[110]
#define ST_01 symbol[111]
#define ST_02 symbol[112]
#define ST_03 symbol[113]
#define ST_04 symbol[114]
#define ST_05 symbol[115]
#define ST_06 symbol[116]
#define TC_01 symbol[117]
#define TC_02 symbol[118]
#define TC_03 symbol[119]
#define TC_04 symbol[120]
#define TC_05 symbol[121]
#define TC_06 symbol[122]
#define TC_07 symbol[123]
#define TC_08 symbol[124]
#define TC_09 symbol[125]
#define TC_10 symbol[126]
#define TC_11 symbol[127]
#define TC_12 symbol[128]
#define TC_13 symbol[129]
#define TC_14 symbol[130]
#define TC_15 symbol[131]
#define TC_16 symbol[132]
#define TC_17 symbol[133]
#define TC_18 symbol[134]
#define TC_19 symbol[135]
#define TC_20 symbol[136]
#define TC_21 symbol[137]
#define TC_22 symbol[138]
#define TC_23 symbol[139]
#define TC_24 symbol[140]
#define TC_25 symbol[141]
#define TC_26 symbol[142]
#define TC_27 symbol[143]
#define TC_28 symbol[144]
#define TC_29 symbol[145]
#define TC_30 symbol[146]
#define TC_31 symbol[147]
#define TC_32 symbol[148]
#define TC_33 symbol[149]
#define TC_34 symbol[150]
#define TC_35 symbol[151]
#define TC_36 symbol[152]
#define TC_37 symbol[153]

//Data -----------------------------------------------------------------------------------------------------------------------------------
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
};

Data::Data()
{
	if(VideoMode::getDesktopMode().width / 640.0 < VideoMode::getDesktopMode().height / 480.0)
		RE = VideoMode::getDesktopMode().width / 640.0;	//rapport Ecran
	else
		RE = VideoMode::getDesktopMode().height / 480.0; //rapport Ecran
	arial.loadFromFile("ressources/fonts/arial.ttf"); //recuperation de la police
}

void Data::update()
{

}

int Data::getVtrain(){return Vtrain;}
string Data::getGeneralMode(){return generalMode;}
string Data::getMode(){return mode;}
string Data::getStatus(){return status;}
string Data::getLevel(){return level;}
double Data::getRE(){return RE;}
int Data::getEcartX(){return ecartX;}
int Data::getEcartY(){return ecartY;}
Font Data::getFont(){return arial;}
void Data::setSon(int a){son = a;}

//Symbol -----------------------------------------------------------------------------------------------------------------------------------
class Symbol
{
	private :
		RenderWindow *fenetre;
		Data *data;
		Image image;
		Texture texture;
		Color m_color;
		vector<Sprite> sprite;
		void loadSymbol(string chemin_dacces);
	public :
		void afficher(Vector2f position);
		void effacer();
		Symbol(vector<Symbol> & symbol);
};

void Symbol::loadSymbol(string chemin_dacces)
{
	if (!image.loadFromFile(chemin_dacces)) // Si le chargement du fichier a �chou�
	{
	     cout << "Erreur durant le chargement de l'image" << endl;
	}
	else // Si le chargement de l'image a r�ussi
	{
		texture.loadFromImage(image);
	}
}

void Symbol::afficher(V2f position)
{
	Sprite spr;
	sprite.push_back(spr);
	int m = sprite.size() - 1;
	sprite[m].setTexture(texture);
	sprite[m].setScale(data->getRE(), data->getRE());
	position.x = position.x * data->getRE() - sprite[m].getGlobalBounds().width / 2 + data->getEcartX() * data->getRE();
	position.y = position.y * data->getRE() - sprite[m].getGlobalBounds().height / 2 + data->getEcartY() * data->getRE();
	sprite[m].setPosition(position);
	m_color = sprite[m].getColor();
	m_color.a = 255;
	sprite[m].setColor(m_color);
	fenetre->draw(sprite[m]);
}

void Symbol::effacer()
{
	int m = sprite.size();
	for(int i = 0; i < m; i++)
	{
		sprite.erase(sprite.begin());
	}
	//m_color = sprite[0].getColor();
	//m_color.a = 0;
	//sprite[0].setColor(m_color);
}

Symbol::Symbol(vector<Symbol> & symbol)
{
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

//Fenetres -----------------------------------------------------------------------------------------------------------------------------------
class Tools
{
	protected :
		RenderWindow *fenetre;
		Data *data;
		void creation_texte(string message, Font police, Color couleur, int taille, double OutlineThickness, V2f pos, int mode);
		void rectangle(V2f pos, V2f taille, Color col);
};

void Tools::creation_texte(string message, Font police, Color couleur, int taille, double OutlineThickness, V2f pos, int mode) //mode 1 : centrer / mode 2 : aligner droite / mode 3 : Geographical position / mode 4 : aligner gauche
{
	Text texte;
	texte.setString(message);
	texte.setFont(police);
	texte.setOutlineThickness(OutlineThickness);
	texte.setOutlineColor(couleur);
	texte.setCharacterSize(taille * data->getRE());
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
			texte.setOrigin(texte.getLocalBounds().left, (pos.y + data->getEcartY()) * data->getRE());
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
		metre.setCharacterSize(10 * data->getRE());
		metre.setFillColor(couleur);
		texte.setOrigin(texte.getLocalBounds().left + (texte.getLocalBounds().width + metre.getLocalBounds().width) / 2.0f, texte.getLocalBounds().top + texte.getLocalBounds().height / 2.0f);
		metre.setOrigin(metre.getLocalBounds().left - (texte.getLocalBounds().width - metre.getLocalBounds().width) / 2.0f, metre.getLocalBounds().top - texte.getLocalBounds().height / 2.0f + metre.getLocalBounds().height * 1.0f);
		metre.setPosition((pos.x + data->getEcartX()) * data->getRE() * 1.0f, (pos.y + data->getEcartY()) * data->getRE() * 1.0f);
		fenetre->draw(metre);
	}
	else if(mode == 1 || mode == 3)
	{
		if(mode == 3)
			texte.setCharacterSize(10 * data->getRE());
		texte.setOrigin(texte.getLocalBounds().left + texte.getLocalBounds().width / 2.0f, texte.getLocalBounds().top + texte.getLocalBounds().height / 2.0f);
	}
	texte.setPosition((pos.x + data->getEcartX()) * data->getRE() * 1.0f, (pos.y + data->getEcartY()) * data->getRE() * 1.0f);
	fenetre->draw(texte);
}

void Tools::rectangle(V2f pos, V2f taille, Color col)
{
	RectangleShape barre(V2f(taille.x * data->getRE(), taille.y * data->getRE()));
	barre.setPosition((pos.x + data->getEcartX()) * data->getRE(), (pos.y + data->getEcartY()) * data->getRE());
	barre.setFillColor(col);
	fenetre->draw(barre);
}


class LeftSide : public virtual Tools
{
	protected :
		void targetDistance(int distance);
};

void LeftSide::targetDistance(int distance)
{
	if(distance >= 0)
	{
		creation_texte(to_string((int)round((distance / 10.0)) * 10), data->getFont(), GREY, 10, 0, V2f(54 / 2.0, 54 + 30 / 2.0), 1);
		rectangle(V2f(12, 54 + 30 - 1), V2f(13, 2), GREY);
		rectangle(V2f(16, 54 + 30 + 6), V2f(9, 1), GREY);
		rectangle(V2f(16, 54 + 30 + 13), V2f(9, 1), GREY);
		rectangle(V2f(16, 54 + 30 + 22), V2f(9, 1), GREY);
		rectangle(V2f(16, 54 + 30 + 32), V2f(9, 1), GREY);
		rectangle(V2f(12, 54 + 30 + 45), V2f(13, 2), GREY);
		rectangle(V2f(16, 54 + 30 + 59), V2f(9, 1), GREY);
		rectangle(V2f(16, 54 + 30 + 79), V2f(9, 1), GREY);
		rectangle(V2f(16, 54 + 30 + 105), V2f(9, 1), GREY);
		rectangle(V2f(16, 54 + 30 + 152), V2f(9, 1), GREY);
		rectangle(V2f(12, 54 + 30 + 185), V2f(13, 2), GREY);
		if(distance <= 100)
		{
			rectangle(V2f(29 , 85 + 185 * ( 1 - (1.722*pow(10,-3)*distance))), V2f(10, 185 * (1.722*pow(10,-3)*distance)), GREY);
		}
		else if(distance <= 1000)
		{
			rectangle(V2f(29, 186 + 54 + 30 - (185 - 152)), V2f(10, 185 - 152), GREY);
			rectangle(V2f(29 , 85 + 185 * ( 1 - (log(distance*(1/58.8236)) / log(17)))), V2f(10, 185 * (log(distance * (1 / 58.8236)) / log(17))), GREY);
		}
		else
		{
			rectangle(V2f(29, 186  + 54 + 30 -185), V2f(10, 185), GREY);
		}
	}
}


class Fenetre : public virtual Tools
{
	protected :
		Data *data;
		RenderWindow *fenetre;
		void creation_rectangle(V2f pos, V2f dim, int mode);
		void couleurForme(VertexArray & bande,Color col, int n);
		void affichageBoutons();
};

//RESUME DE LA FONCTION
//Besoin de la position de point en haut � gauche et de la dimension du quadrilat�re
//RE permet de modifier l'�paisseur en fct du rapport d'�cran
//mode 1=case mode 2=bouton mode 3=rappelle de la fonction pour cr�ation du carr� int�rieur
void Fenetre::creation_rectangle(V2f pos, V2f dim, int mode)
{
	if(mode == 1)
	{
		rectangle(pos, dim, SHADOW);
		rectangle(pos, V2f(dim.x - 1, dim.y - 1), BLACK);
		rectangle(V2f(pos.x + 1, pos.y + 1), V2f(dim.x - 2, dim.y - 2), DARK_BLUE);
	}
	if(mode == 2)
	{
		rectangle(pos, dim, SHADOW);
		rectangle(pos, V2f(dim.x - 1, dim.y - 1), BLACK);
		rectangle(V2f(pos.x + 1, pos.y + 1), V2f(dim.x - 3, dim.y - 3), SHADOW);
		rectangle(V2f(pos.x + 2, pos.y + 2), V2f(dim.x - 4, dim.y - 4), DARK_BLUE);
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

void Fenetre::couleurForme(VertexArray & bande,Color col, int n)
{
	for(int i = 0; i < n; i++)
	{
		bande[i].color= col;
	}
}

void Fenetre::affichageBoutons()
{
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);			//F1
	creation_rectangle(V2f(64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);			//F2
	creation_rectangle(V2f(2 *64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F3
	creation_rectangle(V2f(3 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F4
	creation_rectangle(V2f(4 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F5
	creation_rectangle(V2f(5 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F6
	creation_rectangle(V2f(6 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F7
	creation_rectangle(V2f(7 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F8
	creation_rectangle(V2f(8 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F9
	creation_rectangle(V2f(9 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F10
	creation_rectangle(V2f((640 - 40), 28), V2f(40, 64), 2);							//H2
	creation_rectangle(V2f((640 - 40), (28 + 64)), V2f(40, 64), 2);						//H3
	creation_rectangle(V2f((640 - 40), (28 + 2 * 64)), V2f(40, 64), 2);					//H4
	creation_rectangle(V2f((640 - 40), (28 + 3 * 64)), V2f(40, 64), 2);					//H5
	creation_rectangle(V2f((640 - 40), (28 + 4 * 64)), V2f(40, 64), 2);					//H6
	creation_rectangle(V2f((640 - 40), (28 + 5 * 64)), V2f(40, 82), 2);					//H7
}


class Main : public Fenetre, public LeftSide
{

};


class Menu : public Fenetre
{

};


class DataEntry : public Fenetre
{

};


class Special : public Menu
{

};


class Settings : public Menu
{

};


class SRspeed : public Menu
{

};


class DataView : public Menu
{

};


class SystemVersion : public Menu
{

};

//Button -----------------------------------------------------------------------------------------------------------------------------------
class Button
{
	private :
		Data *data;
		string type;
		int driver_action;//press� ou non
		int button_activation = 0;//nombre de fois activ�
		bool button_state;//enabled ou non
		Clock chrono;
		Time t_actif;
		int n; // variable utilis�e pour le down_type

	public :
		Button(Data &data);
		string gettype();
		void settype(string P);
		int getdriver_action();
		void setdriver_action(int P);
		void action_type();
		int getactivation();
};

Button::Button(Data &data)
{
	this->data = &data;
}

string Button::gettype() {return type;}
void Button::settype(string P) {type = P;}
int Button::getdriver_action(){return driver_action;}
void Button::setdriver_action(int P){driver_action = P;}
int Button::getactivation(){return button_activation;}

void Button::action_type()
{
	t_actif = chrono.getElapsedTime();
	float delta_ts=t_actif.asSeconds();
	button_activation = 0;
	if(type == "up_type")
	{
		if(driver_action == 1)
		{
			data->setSon(11);
		}
		if(driver_action == 3)
		{
			button_activation = 1;
		}
	}
	if(type == "down_type")
	{
		if(driver_action == 1)
		{
			data->setSon(11);
			chrono.restart();
			button_activation = 1;
			n = 0;
		}
		else if(driver_action == 2)
		{
			if(delta_ts <= 1.5 && n == 0)
			{
				button_activation = 0;
			}
			if (delta_ts > 1.5)
			{
				n = 1;
				chrono.restart();
			}
			if(n == 1)
			{
				if(round(delta_ts*10) == 0.3*10)
				{
					button_activation = 1;
					chrono.restart();
				}
				else
					button_activation = 0;
			}
		}
	}
	if (type == "delay_type")
	{
		if(driver_action == 1)
		{
			data->setSon(11);
			chrono.restart();
		}
		if(driver_action == 3 && delta_ts > 2)
		{
			button_activation = 1;
		}
	}
}

//ETCS -----------------------------------------------------------------------------------------------------------------------------------
class ETCS
{
	private :
		RenderWindow *fenetre;
		Data *data;
		vector <Button> button;
		Event event;
	public :
		ETCS(RenderWindow &fenetre, Data &data);
		void update();
		void action();
};

ETCS::ETCS(RenderWindow &fenetre, Data& data): button(16, data)
{
	this->fenetre = &fenetre;
	this->data = &data;
	for(int i = 0; i <= 15; i++)
		button[i].settype("up_type");
}

void ETCS::update()
{

}

void ETCS::action()
{
	for(int i = 0; i <= 15; i++)
	{
		if(button[i].getdriver_action() == 3)
			button[i].setdriver_action(0);
		if(button[i].getdriver_action() == 1)
			button[i].setdriver_action(2);
	}
    while(fenetre->pollEvent(event))
    {
	    if(event.type == Event::Closed)
            fenetre->close();
		if(event.type == Event::KeyPressed)
		{
		    if(event.key.code == Keyboard::Escape)
		        fenetre->close();
			else if(event.key.code == Keyboard::A)
			{
		        if(button[0].getdriver_action() == 0)
					button[0].setdriver_action(1);
			}
			else if(event.key.code == Keyboard::Z)
			{
				if(button[1].getdriver_action() == 0)
					button[1].setdriver_action(1);
				else
					button[1].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::E)
			{
		        if(button[2].getdriver_action() == 0)
					button[2].setdriver_action(1);
				else
					button[2].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::R)
			{
		        if(button[3].getdriver_action() == 0)
					button[3].setdriver_action(1);
				else
					button[3].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::T)
			{
		        if(button[4].getdriver_action() == 0)
					button[4].setdriver_action(1);
				else
					button[4].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::Y)
			{
		        if(button[5].getdriver_action() == 0)
					button[5].setdriver_action(1);
				else
					button[5].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::U)
			{
		        if(button[6].getdriver_action() == 0)
					button[6].setdriver_action(1);
				else
					button[6].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::I)
			{
		        if(button[7].getdriver_action() == 0)
					button[7].setdriver_action(1);
				else
					button[7].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::O)
			{
		        if(button[8].getdriver_action() == 0)
					button[8].setdriver_action(1);
				else
					button[8].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::P)
			{
		        if(button[9].getdriver_action() == 0)
					button[9].setdriver_action(1);
				else
					button[9].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::Q)
			{
		        if(button[10].getdriver_action() == 0)
					button[10].setdriver_action(1);
				else
					button[10].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::S)
			{
		        if(button[11].getdriver_action() == 0)
					button[11].setdriver_action(1);
				else
					button[11].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::D)
			{
		        if(button[12].getdriver_action() == 0)
					button[12].setdriver_action(1);
				else
					button[12].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::F)
			{
		        if(button[13].getdriver_action() == 0)
					button[13].setdriver_action(1);
				else
					button[13].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::G)
			{
		        if(button[14].getdriver_action() == 0)
					button[14].setdriver_action(1);
				else
					button[14].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::H)
			{
		        if(button[15].getdriver_action() == 0)
					button[15].setdriver_action(1);
				else
					button[15].setdriver_action(2);
			}
		}
		if(event.type == Event::KeyReleased)
		{
			if(event.key.code == Keyboard::A)
		        button[0].setdriver_action(3);
			else if(event.key.code == Keyboard::Z)
		        button[1].setdriver_action(3);
			else if(event.key.code == Keyboard::E)
		        button[2].setdriver_action(3);
			else if(event.key.code == Keyboard::R)
		        button[3].setdriver_action(3);
			else if(event.key.code == Keyboard::T)
		        button[4].setdriver_action(3);
			else if(event.key.code == Keyboard::Y)
		        button[5].setdriver_action(3);
			else if(event.key.code == Keyboard::U)
		        button[6].setdriver_action(3);
			else if(event.key.code == Keyboard::I)
		        button[7].setdriver_action(3);
			else if(event.key.code == Keyboard::O)
		        button[8].setdriver_action(3);
			else if(event.key.code == Keyboard::P)
		        button[9].setdriver_action(3);
			else if(event.key.code == Keyboard::Q)
		        button[10].setdriver_action(3);
			else if(event.key.code == Keyboard::S)
		        button[11].setdriver_action(3);
			else if(event.key.code == Keyboard::D)
		        button[12].setdriver_action(3);
			else if(event.key.code == Keyboard::F)
		        button[13].setdriver_action(3);
			else if(event.key.code == Keyboard::G)
		        button[14].setdriver_action(3);
			else if(event.key.code == Keyboard::H)
		        button[15].setdriver_action(3);
		}
    }
	for(int i = 0; i <= 15; i++)
		button[i].action_type();
}

//DMI ------------------------------------------------------------------------------------------------------------------------------------

class DMI
{
	private :
		RenderWindow fenetre;
		ContextSettings settings;
		int signalisation;
		Data data;
		ETCS etcs{fenetre, data};
	public :
		DMI();
		void start();
};

DMI::DMI()
{
	//creation et affichage de la fenetre
	fenetre.create(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height),"Ecran central", Style::Default, settings);
	fenetre.setFramerateLimit(60);
	settings.antialiasingLevel = 8;
}

void DMI::start()
{
	while(fenetre.isOpen())
	{
		data.update();
		switch(signalisation)
		{
			case 0: etcs.update();
			case 1: ;
			case 2: ;
			default: ;
		}
	};
}

//Main -----------------------------------------------------------------------------------------------------------------------------------
int main()
{
	DMI app;
	app.start();
	return 0;
}