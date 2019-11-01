#include <cstdlib>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
//#include "Fenetres.hpp"

using namespace sf;
using namespace std;

//define ---------------------------------------------------------------------------------------------------------------------------------
#define V2f Vector2f
#define V2i Vector2i
#define PI 3.14159265

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
		int Vligne;
		float V_red;
		float V_orange;
		float V_yellow;
		float V_white;
		float V_medium_grey;
		float V_dark_grey;
		Color aiguille;
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
		int getVligne();
		float getV_red();
		float getV_orange();
		float getV_yellow();
		float getV_white();
		float getV_medium_grey();
		float getV_dark_grey();
		Color getAiguilleColor();
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
int Data::getVligne(){return Vligne;}
float Data::getV_red(){return V_red;}
float Data::getV_orange(){return V_orange;}
float Data::getV_yellow(){return V_yellow;}
float Data::getV_white(){return V_white;}
float Data::getV_medium_grey(){return V_medium_grey;}
float Data::getV_dark_grey(){return V_dark_grey;}
Color Data::getAiguilleColor(){return aiguille;}

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
		void afficher(V2f position);
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



//Tools -----------------------------------------------------------------------------------------------------------------------------------
class Tools
{
	protected :
		RenderWindow *fenetre;
		Data *data;
		void creation_texte(string message, Color couleur, int taille, double OutlineThickness, V2f pos, int mode);
		void rectangle(V2f pos, V2f taille, Color col);
		void couleurForme(VertexArray & bande,Color col, int n);
		V2f local2globalCoordonates(V2f localOrigin, float teta_origine, V2f CoordonneesPolaires);
};

void Tools::creation_texte(string message, Color couleur, int taille, double OutlineThickness, V2f pos, int mode) //mode 1 : centrer / mode 2 : aligner droite / mode 3 : Geographical position / mode 4 : aligner gauche
{
	Text texte;
	texte.setString(message);
	texte.setFont(data->getFont());
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
		metre.setFont(data->getFont());
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

void Tools::couleurForme(VertexArray & bande,Color col, int n)
{
	for(int i = 0; i < n; i++)
	{
		bande[i].color= col;
	}
}

V2f Tools::local2globalCoordonates(V2f localOrigin, float teta_origine, V2f CoordonneesPolaires)
{
	V2f Coordonnees;
	Coordonnees.x = localOrigin.x - (- 1) * CoordonneesPolaires.x * cos((CoordonneesPolaires.y - teta_origine) * PI / 180.0); //PI/180 permet de passer de la valeur de radians a une valeur en degree
	Coordonnees.y = localOrigin.y - (- 1) * CoordonneesPolaires.x * sin((CoordonneesPolaires.y - teta_origine) * PI / 180.0); // le facteur -1 permet de se mettre dans le cas du cercle trigonometrique
	return Coordonnees;
}

// Texte --------------------------------------------------------------------------------------------------------------------------

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

//Cadran -----------------------------------------------------------------------------------------------------------------------------------
class DonneesAfficheurVitesse
{
    public:
		DonneesAfficheurVitesse();
		DonneesAfficheurVitesse(V2f cartesiens, V2f polaire, int vitesse);

		//definition des get
		void cartesiens(V2f cartesiens);
		void polaire(V2f polaire);
		void x(int x);
		void y(int y);
		void r(int r);
		void teta(int teta);
		void vitesse(int vitesse);

		//definition des set
		V2f cartesien();
		V2f polaire();
		float x();
		float y();
		float r();
		float teta();
		int vitesse();

    private:
		V2f *centre;
		float *teta_origine;
		V2f m_cartesiens;
		V2f m_polaire;
    	float m_vitesse;
};

DonneesAfficheurVitesse::DonneesAfficheurVitesse()
{
	m_cartesiens.x = 0;
	m_cartesiens.y = 0;
	m_polaire.x = 0;
	m_polaire.y = 0;
	m_vitesse = 0;
}

DonneesAfficheurVitesse::DonneesAfficheurVitesse(V2f cartesiens, V2f polaire, int vitesse)
{
	m_cartesiens = cartesiens;
	m_polaire = polaire;
	m_vitesse = vitesse;
}

void DonneesAfficheurVitesse::polaire(V2f polaire)
{
	m_polaire = polaire;
	m_cartesiens.x = centre->x - (-1) * m_polaire.x * cos((m_polaire.y - *teta_origine) * PI / 180.0); //PI/180 permet de passer de la valeur de radians a une valeur en degree
	m_cartesiens.y = centre->y - (-1) * m_polaire.x * sin((m_polaire.y - *teta_origine) * PI / 180.0); // le facteur -1 permet de se mettre dans le cas du cercle trigonometrique
}

void DonneesAfficheurVitesse::cartesiens(V2f cartesiens) {m_cartesiens = cartesiens;}
void DonneesAfficheurVitesse::x(int x) {m_cartesiens.x = x;} // set x
void DonneesAfficheurVitesse::y(int y) {m_cartesiens.y = y;} // set y
void DonneesAfficheurVitesse::r(int r) {m_polaire.x = r;} // set r
void DonneesAfficheurVitesse::teta(int teta) {m_polaire.y = teta;} // set teta
void DonneesAfficheurVitesse::vitesse(int vitesse) {m_vitesse = vitesse;} // set vitesse
V2f DonneesAfficheurVitesse::cartesien() {return m_cartesiens;}
V2f DonneesAfficheurVitesse::polaire() {return m_polaire;}
float DonneesAfficheurVitesse::x() {return m_cartesiens.x;}
float DonneesAfficheurVitesse::y() {return m_cartesiens.y;}
float DonneesAfficheurVitesse::r() {return m_polaire.x;}
float DonneesAfficheurVitesse::teta() {return m_polaire.y;}
int DonneesAfficheurVitesse::vitesse() {return m_vitesse;}



class Cadran : public Tools
{
	private :
		int Vmax;
		ConvexShape aiguille;
		DonneesAfficheurVitesse graduations[401];
		V2f centre;
		CircleShape Centre;
		float teta0;
		float kmh2degVfaible;
		float kmh2degVeleve = kmh2degVfaible;
		VertexArray Shape(float teta_origine, DonneesAfficheurVitesse grad, V2f a, V2f b, V2f c, V2f d);
	public :
		Cadran(int Vmax);
		void update();
};

VertexArray Cadran::Shape(float teta_origine, DonneesAfficheurVitesse grad, V2f a, V2f b, V2f c, V2f d)
{
	VertexArray Barre(Quads, 4);
	Barre[0].position = local2globalCoordonates(centre,teta_origine, V2f(a.x * data->getRE(),grad.teta() + a.y));
	Barre[1].position = local2globalCoordonates(centre,teta_origine, V2f(b.x * data->getRE(),grad.teta() + b.y));
	Barre[2].position = local2globalCoordonates(centre,teta_origine, V2f(c.x * data->getRE(),grad.teta() + c.y));
	Barre[3].position = local2globalCoordonates(centre,teta_origine, V2f(d.x * data->getRE(),grad.teta() + d.y));
	return Barre;
}

Cadran::Cadran(int Vmax)	//aiguille = dessinAiguilleIV(centreIV, RE); a modifier !!!!!!    //centreIV = initValeurIndicateurVitesse(Vmax, RE, graduations, ecart); !!
{
	this->Vmax = Vmax;
	teta0 = 90 - 144;
	kmh2degVfaible = 144.0 / 150.0;  //nombre de degre pour 1km/h ici a 144� on a 150km/h
	kmh2degVeleve = kmh2degVfaible / 2.0;

	centre.x = data->getRE() * (54 + 280 / 2.0 + data->getEcartX());
	centre.y = data->getRE() * (300 / 2.0 + data->getEcartY());

	aiguille.setPointCount(8);
	aiguille.setPosition(centre);

	aiguille.setPoint(0,V2f(- (80 + 25) * data->getRE(), - 3 / 2.0 * data->getRE()));
	aiguille.setPoint(1,V2f(- (80 + 25) * data->getRE(), 3 / 2.0 * data->getRE()));
	aiguille.setPoint(2,V2f(- (80 + 25 - 15) * data->getRE(), 3 / 2.0 * data->getRE()));
	aiguille.setPoint(3,V2f(- (57 + 25) * data->getRE(),9 / 2.0 * data->getRE()));
	aiguille.setPoint(4,V2f(- 20 * data->getRE(),9 / 2.0 * data->getRE()));
	aiguille.setPoint(5,V2f(- 20 * data->getRE(), - 9 / 2.0 * data->getRE()));
	aiguille.setPoint(6,V2f(- (57 + 25) * data->getRE(), - 9 / 2.0 * data->getRE()));
	aiguille.setPoint(7,V2f(- (80 + 25 - 15) * data->getRE(), - 3 / 2.0 * data->getRE()));

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

	for(int i = 1; i <= Vfaible; i++)	//i correspond a la vitesse
	{
		graduations[i].polaire(V2f(0, i * kmh2degVfaible));
		graduations[i].vitesse(i);
	}
	for(int i = 1 + Vfaible; i <= Vmax; i++) //i correspond a la vitesse
	{
		graduations[i].polaire(V2f(0, Vfaible * kmh2degVfaible / 2.0 + i * kmh2degVeleve));
		graduations[i].vitesse(i);
	}
}

void Cadran::update()
{
	V2f position;
	CircleShape Centre;
	Centre.setFillColor(data->getAiguilleColor());
	Centre.setPosition(V2f(centre.x - 25 * data->getRE(),centre.y - 25 * data->getRE()));
	Centre.setRadius(25 * data->getRE());
	fenetre->draw(Centre);
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
			Barre = Shape(teta_origine, graduations[i], V2f(125, - tetaep / 2.0), V2f(125, tetaep / 2.0), V2f(125 - 25, tetaep / 2.0), V2f(125 - 25, - tetaep / 2.0));
			if(i != 250 && i != 350)
			{
				position = local2globalCoordonates(centre,teta_origine,V2f(83 * data->getRE(), graduations[i].teta()));
				creation_texte(to_string(graduations[i].vitesse()), WHITE, 16, 0, V2f(position.x / data->getRE() - data->getEcartX(), position.y / data->getRE() - data->getEcartX()), 1);
			}
		}
		else
		{
			//positionnement de chaque points
			Barre = Shape(teta_origine, graduations[i], V2f(125, - tetaep / 2.0), V2f(125, tetaep / 2.0), V2f(125 - 15, tetaep / 2.0), V2f(125 - 15, - tetaep / 2.0));
		}
		fenetre->draw(Barre);
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


	int V1 = max(max(data->getV_orange(), data->getV_red()), max(max(data->getV_dark_grey(), data->getV_yellow()), data->getV_white()));
	int V2 = max(max(data->getV_dark_grey(), data->getV_yellow()), data->getV_white());

	float teta_origine = 90 + 144;
	VertexArray Barre(Quads, 4);
	float deltateta = abs(graduations[0].teta()-graduations[1].teta());
	Color couleur2 = GREY;
	Color couleur4 = BLACK;

	if(data->getV_medium_grey() != 0)
		creation_texte(to_string((int)data->getV_medium_grey()), GREY, 17, 0, V2f(54 + 26, 274), 1);
	for(int i = V2 + 1; i <= V1; i++)
	{
		if(data->getV_red() > data->getV_orange())
			couleurForme(Barre, RED, 4);
		else if(data->getV_red() < data->getV_orange())
			couleurForme(Barre, ORANGE, 4);
		Barre = Shape(teta_origine, graduations[i], V2f(137, - deltateta / 2.0), V2f(137, deltateta / 2.0), V2f(137 - 20, deltateta / 2.0), V2f(137 - 20, - deltateta / 2.0));
		fenetre->draw(Barre);
	}
	for(int i = 0; i<= V2; i++)
	{
		couleurForme(Barre, WHITE, 4);
		Barre = Shape(teta_origine, graduations[i], V2f(137, - deltateta / 2.0), V2f(137, deltateta / 2.0), V2f(128, deltateta / 2.0), V2f(128, - deltateta / 2.0));
		fenetre->draw(Barre);
	}
	for(int i = (V2 - 2 * asin(3 / float(137 - 20))); i <= V2; i++)
	{
		if(data->getV_yellow() > data->getV_dark_grey() && data->getV_yellow() > data->getV_white())
			couleurForme(Barre, YELLOW, 4);
		else if(data->getV_white() > data->getV_dark_grey() && data->getV_white() > data->getV_yellow())
			couleurForme(Barre, WHITE, 4);
		else
			couleurForme(Barre, DARK_GREY, 4);
		Barre = Shape(teta_origine, graduations[i], V2f(128, - deltateta / 2.0), V2f(128, deltateta / 2.0), V2f(128 - 11, deltateta / 2.0), V2f(128 - 11, - deltateta / 2.0));
		fenetre->draw(Barre);
	}
	for(int i = V1; i <= data->getV_red(); i++)
	{
		couleurForme(Barre, RED, 4);
		Barre = Shape(teta_origine, graduations[i], V2f(137, - deltateta / 2.0), V2f(137, deltateta / 2.0), V2f(128, deltateta / 2.0), V2f(128, - deltateta / 2.0));
		fenetre->draw(Barre);
	}
	for(int i = 0; i <= data->getV_yellow(); i++)
	{
		couleurForme(Barre, YELLOW, 4);
		Barre = Shape(teta_origine, graduations[i], V2f(137, - deltateta / 2.0), V2f(137, deltateta / 2.0), V2f(128, deltateta / 2.0), V2f(128, - deltateta / 2.0));
		fenetre->draw(Barre);
	}
	for(int i = 0; i <= data->getV_dark_grey(); i++)
	{
		couleurForme(Barre, DARK_GREY, 4);
		Barre = Shape(teta_origine, graduations[i], V2f(137, - deltateta / 2.0), V2f(137, deltateta / 2.0), V2f(128, deltateta / 2.0), V2f(128, - deltateta / 2.0));
		fenetre->draw(Barre);
	}
	for(int i = 1; i <= data->getV_medium_grey(); i++)
	{
		couleurForme(Barre, couleur2, 4);
		Barre = Shape(teta_origine, graduations[i], V2f(137, - deltateta / 2.0), V2f(137, deltateta / 2.0), V2f(128 + 4, deltateta / 2.0), V2f(128 + 4, - deltateta / 2.0));
		fenetre->draw(Barre);
	}
	if(V1 < data->getV_medium_grey())
	{
		for(int i = 1; i <= V1; i++)
		{
			couleurForme(Barre, couleur4, 4);
			Barre = Shape(teta_origine, graduations[i], V2f(128 + 4, - deltateta / 2.0), V2f(128 + 4, deltateta / 2.0), V2f(128 + 3, deltateta / 2.0), V2f(128 + 3, - deltateta / 2.0));
			fenetre->draw(Barre);
		}
		for(int i = V1 + 1; i <= data->getV_medium_grey(); i++) //trait noir
		{
			couleurForme(Barre, couleur2, 4);
			Barre = Shape(teta_origine, graduations[i], V2f(128 + 4, - deltateta / 2.0), V2f(128 + 4, deltateta / 2.0), V2f(128, deltateta / 2.0), V2f(128, - deltateta / 2.0));
			fenetre->draw(Barre);
		}
	}
	else
	{
		for(int i = 1; i <= data->getV_medium_grey(); i++)
		{
			couleurForme(Barre, couleur4, 4);
			Barre = Shape(teta_origine, graduations[i], V2f(128 + 4, - deltateta / 2.0), V2f(128 + 4, deltateta / 2.0), V2f(128 + 3, deltateta / 2.0), V2f(128 + 3, - deltateta / 2.0));
			fenetre->draw(Barre);
		}
	}
	for(int i = 0; i <= 4; i++) //Affichage fixe
	{
		couleurForme(Barre, DARK_GREY, 4);
		Barre = Shape(teta_origine + 4.0, graduations[i], V2f(137, - deltateta / 2.0), V2f(137, deltateta / 2.0), V2f(128, deltateta / 2.0), V2f(128, - deltateta / 2.0));
		fenetre->draw(Barre);
	}

	if(data->getVtrain() < 200)
		aiguille.setRotation(data->getVtrain() * kmh2degVfaible+teta0);
	else
		aiguille.setRotation(200 * kmh2degVfaible / 2.0 + data->getVtrain() * kmh2degVeleve+teta0);

	fenetre->draw(aiguille);

	string str = to_string(graduations[(int)data->getVtrain()].vitesse());
	string s;
	if(graduations[(int)data->getVtrain()].vitesse() > 99)
	{
		s = str.at(2);
		creation_texte(s, BLACK, 18, 0, V2f(54 + 280 / 2.0 + 50 / 2.0 - 3, 300 / 2.0), 2);
		s = str.at(1);
		creation_texte(s, BLACK, 18, 0, V2f(54 + 280 / 2.0 + 50 / 6.0 - 3, 300 / 2.0), 2);
		s = str.at(0);
		creation_texte(s, BLACK, 18, 0, V2f(54 + 280 / 2.0 - 50 / 6.0 - 3, 300 / 2.0), 2);
	}
	else if(graduations[(int)data->getVtrain()].vitesse() > 9)
	{
		s = str.at(1);
		creation_texte(s, BLACK, 18, 0, V2f(54 + 280 / 2.0 + 50 / 3.0, 300 / 2.0), 1);
		s = str.at(0);
		creation_texte(s, BLACK, 18, 0, V2f(54 + 280 / 2.0, 300 / 2.0), 1);
	}
	else
	{
		s = str.at(0);
		creation_texte(s, BLACK, 18, 0, V2f(54 + 280 / 2.0 + 50 / 3.0, 300 / 2.0), 1);
	}
}

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

		void SpeedProfileDiscontinuityInformation(int scale, float delta_distance, vector<Announcements> &tab_paf, vector<Symbol> & symbol);
		void Orders_and_announcements(int scale, float delta_distance, vector<Announcements> &tab_pa, vector<Symbol> & symbol);
		void gradientProfile(int scale, float delta_distance, vector<Gradient> &tab_grad);
		void pasp(int scale, vector<PASP> &tab_pasp, float delta_distance);

	public:
		Planning();
		void planningInformation(vector<Symbol> & symbol, float temps_ecoule);
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

void Planning::planningInformation(vector<Symbol> & symbol, float temps_ecoule)
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

//Fenetres -----------------------------------------------------------------------------------------------------------------------------------
class LeftSide : public virtual Tools
{
	protected :
		Cadran speed;
		void targetDistance(int distance);
};

void LeftSide::targetDistance(int distance)
{
	if(distance >= 0)
	{
		creation_texte(to_string((int)round((distance / 10.0)) * 10), GREY, 10, 0, V2f(54 / 2.0, 54 + 30 / 2.0), 1);
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
		void creation_rectangle(V2f pos, V2f dim, int mode);
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
		void dataEntry(vector<vector<string>> input_field, vector<Symbol> & symbol, int complete, string title, vector<string> selection, int & sel, string keyboard, vector<Button> & boutons, string & ecran);
};

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