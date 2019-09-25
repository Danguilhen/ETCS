#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <thread>
#include <chrono>
#include <GL/gl.h>
#include "symbol.hpp"
#include "sardine3.hpp"

using namespace sf;
using namespace std;

string finale = " ";
string l0 = " ";
string string_ecran = " ";
float vitesseTrain;
string f0 = " ";
string etat;
string se11 = "";
string se12 = "";
string se13 = "";
string se14 = "";
string se15 = "";
string l1 = "";
string l2 = "";
string l3 = "";
string l4 = "";
string l5 = "";
int colorTvm;

class PictoBAG :  public Sprite
{

public :

	PictoBAG()
	{
		m_chemin_dacces = " ";
		m_afficher = false;
		m_mise_a_lechelle = false;
		m_is_consverted = false;
	}

	PictoBAG(string chemin_dacces, Vector2i m_position)
	{
		m_chemin_dacces = chemin_dacces;
		position = m_position;
		m_afficher = false;
		m_mise_a_lechelle = false;
		m_is_consverted = false;
		convesionImage();
	}

	void setChemin_dacces(string chemin_dacces)
	{
		m_chemin_dacces = chemin_dacces;
	}

	void convesionImage()
	{
		m_image.loadFromFile(m_chemin_dacces);
		m_texture.loadFromImage(m_image);
		sprite.setTexture(m_texture);
		m_is_consverted = true;
	}

	void afficher()
	{
		m_color = sprite.getColor();
		m_color.a = 255;
		sprite.setColor(m_color);
	}

	void effacer()
	{
		m_color=sprite.getColor();
		m_color.a=0;
		sprite.setColor(m_color);
	}

	void mise_a_lechelle (float facteurx, float facteury)
	{

		sprite.setScale(facteurx,facteury);
		m_mise_a_lechelle=true;
	}

	bool is_converted()
	{
		return m_is_consverted;
	}

	Sprite sprite;
	Vector2i position;

private :
	string m_chemin_dacces;
	bool m_afficher;
	bool m_mise_a_lechelle;
	bool m_is_consverted;
	Image m_image;
	Texture m_texture;
	Color m_color;

};
///////////////////////////////////////
//Variables Globales
RenderWindow fenetre;
Font eurostile,arial,digital;
Color color;
int height;
int connectRes = -1;
int width;
int Vmax = 400;
DonneesAfficheurVitesse graduations[401];
int NbEmplacementVert = 4;					//nombre de cases suivant y
int NbEmplacementHoriz = 8;					//nombre de cases suivant x
Vector2f positionsCaseBAG[8][4];//Vector2f positionsCaseBAG[NbEmplacementHoriz][NbEmplacementVert];
int socketValue = 0;
int arduinoValue = 0;
int pcValue = 0;
PictoBAG *tabPointPicto[8][4];
int fd;
int sock = socket(AF_INET, SOCK_STREAM,0);
int clientSocket;
float vitesse = 0;
float actualRav = 0;
int lastPanto = 0;
float positionTension = 0;
float positionEffort = 0;
int effortTraction = 0;
int power = 0;
char bf[1024];
char debut[1];
PictoBAG LSDJ("ressources/pictoBoiteAGlacons/LS DJ.png",Vector2i(0, 0));
PictoBAG LSDJAUX("ressources/pictoBoiteAGlacons/LS DJ AUX.png",Vector2i(1, 0));
PictoBAG LSGR("ressources/pictoBoiteAGlacons/LS GR.png",Vector2i(2, 0));
PictoBAG LSSab("ressources/pictoBoiteAGlacons/LS Sab.png",Vector2i(3, 0));
PictoBAG LSDFP("ressources/pictoBoiteAGlacons/LS DF P.png",Vector2i(5, 0));
PictoBAG AUTORFERMDJ("ressources/pictoBoiteAGlacons/AUTOR FERM DJ.png",Vector2i(6, 0));
PictoBAG LSUTCAB("ressources/pictoBoiteAGlacons/LS UT CAB.png",Vector2i(7, 0));
PictoBAG LSDFT("ressources/pictoBoiteAGlacons/LS DF T.png",Vector2i(0, 1));
PictoBAG LSDFDJC("ressources/pictoBoiteAGlacons/LS DF DJ C.png",Vector2i(1, 1));
PictoBAG LSAEBA("ressources/pictoBoiteAGlacons/LS AE-BA.png",Vector2i(2, 1));
PictoBAG LSDFF("ressources/pictoBoiteAGlacons/LS DF F.png",Vector2i(4, 1));
PictoBAG LSDFSURV("ressources/pictoBoiteAGlacons/LS DF SURV.png",Vector2i(6, 1));
PictoBAG LSFRVAN("ressources/pictoBoiteAGlacons/LS FR V-AN.png",Vector2i(7, 1));
PictoBAG LSDFTRA("ressources/pictoBoiteAGlacons/LS DF TRA.png",Vector2i(0, 2));
PictoBAG LSI("ressources/pictoBoiteAGlacons/LS I.png",Vector2i(1, 2));
PictoBAG LSINSBG("ressources/pictoBoiteAGlacons/LS INS BG.png",Vector2i(2, 2));
PictoBAG LSDFND("ressources/pictoBoiteAGlacons/LS DF ND.png",Vector2i(3, 2));
PictoBAG LSSIAL("ressources/pictoBoiteAGlacons/LS SI-AL.png",Vector2i(4, 2));
PictoBAG LSFEP("ressources/pictoBoiteAGlacons/LS FEP.png",Vector2i(5, 2));
PictoBAG LSPCO("ressources/pictoBoiteAGlacons/LS PCO.png",Vector2i(6, 2));
PictoBAG LSAL("ressources/pictoBoiteAGlacons/LS AL.png",Vector2i(7, 2));
PictoBAG LSBCRD("ressources/pictoBoiteAGlacons/LS BC RD.png",Vector2i(0, 3));
PictoBAG LSBCJS("ressources/pictoBoiteAGlacons/LS BC JS.png",Vector2i(1, 3));
PictoBAG LSECO("ressources/pictoBoiteAGlacons/LS ECO.png",Vector2i(5, 3));
string vitesseTVM;
Color couleurTVM;
bool clignotementTVM;
bool enableTVM;
char nombreMotIsole = '2';
bool enableDJ;
int reboot;
Clock fermDJ, armDJ, tvm1, tvm2, tvmdm, bpurgence;
Time fermDJt, armDJt, tvm1t, tvm2t, tvmdmt, bpurgencet;
string s12t = " ", s13t = " ", s14t = " ", s15t = " ", s16t = " ", s0t = " ";
string s12t2 = " ", s13t2 = " ", s14t2 = " ", s15t2 = " ", s16t2 = " ", s0t2 = " ";
string manipTraction = "0"; //0 à 511 : frein motrice, 512 à 1023 : traction
string manipPantoMode = "0"; // 0 : 0, 1 : N, 2 : S, 3 : LGV
string manipPantoTension = "0"; //0 : M, 1 : C, 2 : LGV
string urgencePanto = "true"; //0 : urgence panto activé, 1 : non activé
string bpUrg = "true"; //0 : frein d'urgence activé, 1 : non activé
string manipFreinageSerrage = "false"; //0 : non serrage, 1 : serrage;
string manipFreinageDesserrage = "false"; //0 : non desserrage, 1 : desserrage;
string fermetureDisjoncteur = "false"; //0 = ouvert, 1 = fermé;
string armementDisjoncteur = "false"; //0 = non changement d'etat, 1 = changement d'etat
string tvmVoie2 = "false"; //0 = non changement d'état, 1 = changement d'etat
string tvmVoie1 = "false"; //0 = non armé, 1 = armé
string tvmDesarmement = "false"; //0 = non armé, 1 = armé
string q0 = " ";


/////////////////////////////////////////
//Prototypes

void demarage();
void SocketSend();
void initboiteAGlacons();
void boiteAGlacons(double RE);
void fondEcran();
void receptionDonneesEcran1();
void barreTension();
void effotMetre();
Vector2f local2globalCoordonates(Vector2f localOrigin, float teta_origine, Vector2f CoordonneesPolaires);
void fondStatique(double RE);
ConvexShape dessinFlecheTension();
void positionnementFlecheTension(ConvexShape FlecheTension,float position);
void positionnementCurseurEffortMetre(float position);
void chargementPictoBAG(PictoBAG *Picto, double RE);
void affichageMoteursIsole(char nombre, Vector2i position);
void traitementDonneesRecues();
void animationMotIsole(Clock *clockMotIsol);
void reinitialise();
void affichageTexteDivers();

void sardine(double RE, RenderWindow & fenetre)
{
	//recuperation de la police
	eurostile.loadFromFile("ressources/fonts/Eurostile.ttf");
	arial.loadFromFile("ressources/fonts/arial.ttf");
    digital.loadFromFile("ressources/fonts/digital-7.ttf");

	//recuperation de la taille de l'ecran
	width = VideoMode::getDesktopMode().width - (640 * RE);
	cout << VideoMode::getDesktopMode().width << "  " << width << endl;
	height = VideoMode::getDesktopMode().height;
	cout << height << RE << endl;

	//creation du vecteur null definissant l'origine du repère
	Vector2i origine(0, 0);

	//definission des parametres
	ContextSettings settings;
	settings.antialiasingLevel = 8;
    settings.majorVersion = 2;
    settings.minorVersion = 5;

	//initialisation des données
	ConvexShape aiguille, flecheTension;
    initboiteAGlacons();
    //initPicto();

	//calculs preliminaires
    flecheTension = dessinFlecheTension();

    //definition et initialiasation des pictogrammes
    //initialisation tableau pointeur
    for(int i = 0; i < 8; i++)
	{
    	for (int j = 0; i < 4; i++)
		{
    		tabPointPicto[i][j] = NULL;
    	}
    }

    //premiere ligne
	chargementPictoBAG(&LSDJ, RE);
    tabPointPicto[0][0] = &LSDJ;
	chargementPictoBAG(&LSDJAUX, RE);
    tabPointPicto[1][0] = &LSDJAUX;
	chargementPictoBAG(&LSGR, RE);
    tabPointPicto[2][0] = &LSGR;
	chargementPictoBAG(&LSSab, RE);
    tabPointPicto[3][0] = &LSSab;
	chargementPictoBAG(&LSDFP, RE);
    tabPointPicto[5][0] = &LSDFP;
	chargementPictoBAG(&AUTORFERMDJ, RE);
    tabPointPicto[6][0] = &AUTORFERMDJ;
	chargementPictoBAG(&LSUTCAB, RE);
    tabPointPicto[7][0] = &LSUTCAB;
	//deuxi�me ligne
	chargementPictoBAG(&LSDFT, RE);
    tabPointPicto[0][1] = &LSDFT;
	chargementPictoBAG(&LSDFDJC, RE);
    tabPointPicto[1][1] = &LSDFDJC;
	chargementPictoBAG(&LSAEBA, RE);
    tabPointPicto[2][1] = &LSAEBA;
	chargementPictoBAG(&LSDFF, RE);
    tabPointPicto[4][1] = &LSDFF;
	chargementPictoBAG(&LSDFSURV, RE);
    tabPointPicto[6][1] = &LSDFSURV;
	chargementPictoBAG(&LSFRVAN, RE);
    tabPointPicto[7][1] = &LSFRVAN;
	//troisi�me ligne
	chargementPictoBAG(&LSDFTRA, RE);
    tabPointPicto[0][2] = &LSDFTRA;
	chargementPictoBAG(&LSI, RE);
    tabPointPicto[1][2] = &LSI;
	chargementPictoBAG(&LSINSBG, RE);
    tabPointPicto[2][2] = &LSINSBG;
	chargementPictoBAG(&LSDFND, RE);
    tabPointPicto[3][2] = &LSDFND;
	chargementPictoBAG(&LSSIAL, RE);
    tabPointPicto[4][2] = &LSSIAL;
	chargementPictoBAG(&LSFEP, RE);
    tabPointPicto[5][2] = &LSFEP;
	chargementPictoBAG(&LSPCO, RE);
    tabPointPicto[6][2] = &LSPCO;
	chargementPictoBAG(&LSAL, RE);
    tabPointPicto[7][2] = &LSAL;
	//quatri�me ligne
	chargementPictoBAG(&LSBCRD, RE);
    tabPointPicto[0][3] = &LSBCRD;
	chargementPictoBAG(&LSBCJS, RE);
    tabPointPicto[1][3] = &LSBCJS;
	chargementPictoBAG(&LSECO, RE);
    tabPointPicto[2][3] = &LSECO;

    //glEnable(GL_ARB_multisample);


	//Time t1=seconds(0);
	//Time tf=seconds(5);
    //Time tbuf = t1;
	Clock clock,clockMoteurIsole, clockMotIsol;

	reinitialise();

    Thread thread1(&SocketSend);
    thread1.launch();

 	/*while(true)
	{
    	cout << "";
    	if (arduinoValue == 1)
    	break;
    }*/

	while(true)
	{
	    //fenetre.clear(Color(20,20,20,255));
	    demarage();
	    //fenetre.display();
	    debut[0] = '&';
		//if(socketValue == 12)
		//{
            break;
      	//}
	}
	int mode = 0;

    //Thread thread5(&receptionDonneesEcran1());

   	//Thread threadX(&affichageTexteDivers);
  	//threadX.launch();
	//

    //thread5.launch();

    Event event;
    while(fenetre.pollEvent(event))
    {
        if(event.type == Event::Closed)
		{
            fenetre.close();
            //system("sudo poweroff");
        }
    }

   	if(vitesse < 200 && mode == 2)
        vitesse = vitesse - 0.5;
  	else if(vitesse < 400 && mode == 2)
        vitesse = vitesse - 1;
   	if(vitesse == 0 && mode == 2)
    	mode = 3;

    if(positionTension <= 100 && mode == 3)
    	positionTension=positionTension + 1;

    if(positionTension == 100  && mode == 3)
    	mode = 4;

    if(positionTension >= - 100 && mode == 4)
    	positionTension=positionTension - 1;

    if(positionTension != 0 && mode == 5)
    	positionTension = positionTension + 1;

    if(positionTension == - 100  && mode == 4)
        mode = 5;

    if(positionTension == 0  && mode == 5)
        mode = 6;

    if(positionEffort <= 100 && mode == 6)
    	positionEffort = positionEffort + 1;

    if(positionEffort >= - 100 && mode == 7)
    	positionEffort = positionEffort - 1;

    if(positionEffort !=0 && mode == 8)
    	positionEffort = positionEffort + 1;

    if(positionEffort == 100 && mode == 6)
    	mode=7;

    if(positionEffort == - 100  && mode == 7)
    	mode = 8;

    if(positionEffort == 0 && mode == 8)
	{
    	fenetre.close();
        //system("sudo poweroff");
    }

	//Thread thread5 (envoiTrainz);
    //thread5.launch();

    //fenetre.clear(Color(20,20,20,255));
    fondStatique(RE);
    //traitementDonneesPhysiques();
    //traitementDonneesRecues();
    positionnementFlecheTension(flecheTension,positionTension);
    positionnementCurseurEffortMetre(positionEffort);
    //chargementPictoBAG();

    for(int i = 0; i < 8; i++)
	{
    	for(int j = 0; j < 4; j++)
		{
    		if(tabPointPicto[i][j] != NULL)
    			fenetre.draw(tabPointPicto[i][j]->sprite);
    	}
    }

    if(enableDJ == true && nombreMotIsole != ' ')
        animationMotIsole(&clockMoteurIsole);
    else if(enableDJ==false)
        nombreMotIsole='2';

    affichageMoteursIsole(nombreMotIsole, Vector2i(5,1));

    affichageTexteDivers();

    //if (reboot==1)
	//	break;

   	// a effacer a la fin

    LSDFDJC.afficher();
    AUTORFERMDJ.afficher();
    LSAEBA.afficher();
    LSAL.afficher();
    LSSab.afficher();
    LSBCJS.afficher();
    LSBCRD.afficher();
    LSDFF.afficher();
    LSDFND.afficher();
    LSDFP.afficher();
    LSDFSURV.afficher();
    LSDFT.afficher();
    LSDFTRA.afficher();
    LSECO.afficher();
    LSFEP.afficher();
    LSFRVAN.afficher();
    LSI.afficher();
    LSINSBG.afficher();
    LSPCO.afficher();
    LSSIAL.afficher();
    LSUTCAB.afficher();
    LSGR.afficher();

   	fenetre.display();
	cout << "hello" << endl;
}

void demarage()
{
	Image ImageDemarage;
	Texture textureDemarage;
	Sprite spriteDemarage;

	ImageDemarage.loadFromFile("ressources/ecran demarage.png");

	textureDemarage.loadFromImage(ImageDemarage, IntRect());
	textureDemarage.setSmooth(true);
	spriteDemarage.setTexture(textureDemarage);

	///////////////////////////////////////////////////////////
	//mise à l'echelle de l'image

	FloatRect rectDemarage;

	//recuperation de la taille de l'image
	rectDemarage = spriteDemarage.getGlobalBounds();

	float scaleHeight, scaleWidth;
	//calcul du facteur d'echelle a appliquer
	scaleHeight = height / rectDemarage.height;
	scaleWidth = width / rectDemarage.width;

	//mise a l'echelle absolue
	spriteDemarage.setScale(scaleWidth, scaleHeight);
	//////////////////////////////////////////////////////////////////
	//positionnement du sprite
	spriteDemarage.setPosition(0, 0);

	//////////////////////////////////////////////////////////////////
	//ecriture du texte
	Text chargement("", eurostile, 80);
	if (socketValue != 6 && pcValue != 11 && arduinoValue == 1)
	{
        chargement.setString(L"Connexion à l'écran 2 et au PC");
    	//chargement.setString(l0);
    	//chargement.setString(manipTraction + "!" + manipPantoMode);
	}
    else if(socketValue != 6 && pcValue != 11 && arduinoValue == 0)
        chargement.setString(L"Connexion à l'écran 2, au PC\n et à l'Arduino");
    else if(socketValue != 6 && pcValue == 11 && arduinoValue == 0)
        chargement.setString(L"Connexion à l'écran 2 et à l'Arduino");
    else if(socketValue != 6 && pcValue == 11 && arduinoValue == 1)
        chargement.setString(L"Connexion à l'écran 2");
    else if(socketValue == 6 && pcValue == 11 && arduinoValue == 0)
        chargement.setString(L"Connexion à l'Arduino");
    else if(socketValue == 6 && pcValue != 11 && arduinoValue == 1)
	{
    	//chargement.setString(to_string(pcValue));
        chargement.setString(l0);
	}
    else if(socketValue == 6 && pcValue != 11 && arduinoValue == 0)
	{
        chargement.setString(L"Connexion au PC et à l'Arduino");
		//chargement.setString(to_string(pcValue));
	}
    else
	{
        chargement.setString("Chargement");
	}
	//centrage
	FloatRect texte;
	texte = chargement.getGlobalBounds();
	int position = width / 2 - texte.width / 2;
	chargement.setPosition(position, height / 1.4);
	//chargement.setColor(color.White);

	fenetre.draw(spriteDemarage);
	fenetre.draw(chargement);
}

void initboiteAGlacons()
{
	//boite A glacon abrégé en BAG
	int NbLignesHoriz = NbEmplacementHoriz + 1;
	int NbLignesVert = NbEmplacementVert + 1;
	int BAGWidth = width * 97 / 100; 			//97% de l'epaisseur de l'ecran
	int lineWidth = BAGWidth * 0.5 / 100;		//0.5% de l'epaisseur de la boite a glacon
	int cubeWidth = (BAGWidth - NbLignesHoriz * lineWidth) / NbEmplacementHoriz;
	int BAGHeight = height * 50 / 100;		//50% de la hauteur de l'ecran
	int cubeHeight = (BAGHeight - NbLignesVert * lineWidth) / NbEmplacementVert;
	Vector2i BAG(width - BAGWidth, 0);

	/////////////////////////////////////////////////////////////////////////////////////
	//creation d'un tableau de vecteur comprenant les coordonnees de chaque cases
	//La valeur correspond a la coordonne en haut à gauche de la case
	//initialisation dela première case
	positionsCaseBAG[0][0].x = BAG.x + lineWidth;
	positionsCaseBAG[0][0].y = lineWidth;

	//initialisation de la première ligne
	for(int i = 1; i < NbEmplacementHoriz; i++)
	{
		positionsCaseBAG[i][0].x = positionsCaseBAG[i - 1][0].x + lineWidth + cubeWidth;
		positionsCaseBAG[i][0].y = positionsCaseBAG[0][0].y;
	}

	//initialisation de la première colone
	for (int j = 1; j < NbEmplacementVert; j++)
	{
		positionsCaseBAG[0][j].x = positionsCaseBAG[0][0].x;
		positionsCaseBAG[0][j].y = positionsCaseBAG[0][j - 1].y + lineWidth+cubeHeight;
	}

	//Remplissage du tableau
	for (int i = 1; i < NbEmplacementHoriz; i++)
	{
		for(int j = 1; j < NbEmplacementVert; j++)
		{
			positionsCaseBAG[i][j].x = positionsCaseBAG[i - 1][j - 1].x + lineWidth + cubeWidth;
			positionsCaseBAG[i][j].y = positionsCaseBAG[i - 1][j - 1].y + lineWidth + cubeHeight;
			//cout<<positionsCaseBAG[i][j].y<<endl;
		}
	}
}

void boiteAGlacons(double RE)
{
	//boite A glacon abrégé en BAG
	int NbLignesHoriz = NbEmplacementHoriz + 1;
	int NbLignesVert = NbEmplacementVert + 1;
	int BAGWidth = width * 97 / 100; 			//97% de l'epaisseur de l'ecran
	int lineWidth = BAGWidth * 0.5 / 100;		//0.5% de l'epaisseur de la boite a glacon
	int cubeWidth = (BAGWidth - NbLignesHoriz * lineWidth) / NbEmplacementHoriz;
	int BAGHeight = height * 50 / 100;		//50% de la hauteur de l'ecran
	int cubeHeight = (BAGHeight - NbLignesVert * lineWidth) / NbEmplacementVert;
	Vector2i BAG(width-BAGWidth, 0);

	//////////////////////////////////////////////////////////////////////////
	//definition de la ligne
	RectangleShape ligne;
	ligne.setFillColor(Color(40, 40, 40, 255));

	//tracé des lignes verticales
	ligne.setSize(Vector2f(lineWidth, BAGHeight));
	for (int i = 0; i < NbEmplacementHoriz; i++)
	{
			ligne.setPosition(640 * RE + positionsCaseBAG[i][0].x - lineWidth, 0);
			fenetre.draw(ligne);
	}

	//denière ligne du tableau
	ligne.setPosition(positionsCaseBAG[NbEmplacementHoriz - 1][0].x + cubeWidth, 0);
	fenetre.draw(ligne);


	//tracé des lignes horizontale
	ligne.setSize (Vector2f(BAGWidth, lineWidth));
	for (int i = 0; i < NbEmplacementVert; i++)
	{
			ligne.setPosition(BAG.x,positionsCaseBAG[0][i].y - lineWidth);
			fenetre.draw(ligne);
	}

	//denière ligne du tableau
	ligne.setPosition(BAG.x, positionsCaseBAG[0][NbEmplacementVert - 1].y + cubeHeight);
	fenetre.draw(ligne);
	/////////////////////////////////////////////////////////////////////////////////
	//mise en place des ombres
	RectangleShape ombre;
	ombre.setFillColor(Color(0, 0, 0, 255));
	ombre.setSize(Vector2f(cubeWidth, cubeHeight / 3));

	for(int i = 0; i < NbEmplacementHoriz; i++)
	{
		for(int j = 0; j<NbEmplacementVert; j++)
		{
			ombre.setPosition(positionsCaseBAG[i][j]);
			fenetre.draw(ombre);
		}
	}

	ombre.setSize(Vector2f(BAGWidth+lineWidth,cubeHeight/3));
	ombre.setPosition(positionsCaseBAG[0][0].x - lineWidth, positionsCaseBAG[3][7].y + cubeHeight + lineWidth);
	fenetre.draw(ombre);
}

void fondEcran()
{
	// definition d'un Vertex array
	VertexArray fond(Quads, 4);
	//definition des points

	fond[0].position = Vector2f(0, 0);
	fond[1].position = Vector2f(width * 3 / 100, 0);
	fond[2].position = Vector2f(width * 3 / 100, height);
	fond[3].position = Vector2f(0, height);

	fond[0].color = Color(0, 0, 80, 244);
	fond[1].color = Color(20, 20, 60, 244);
	fond[2].color = Color(20, 20, 20, 244);
	fond[3].color = Color(20, 20, 20, 244);

	fenetre.draw(fond);
}

void barreTension()
{
	//deffinition de la zone ou va se trouver la barre
	int workWidth = width * 1 / 100;		//positionnement � 1% de la largeur de l'ecran
	int workHeight = height * 50 / 100;	//50% de la hauteur de l'ecran
	int widthMargin = workWidth * 1 / 100;
	int heightMargin = workHeight * 4 / 100;
	int vertHeight = (workHeight - 2 * heightMargin) / 2;
	int jauneHeight = vertHeight / 4;
	int rougeHeight = vertHeight;
	int barreWidth = width * 2 / 100 - 2 * widthMargin;
	//int centreBarreTension=workWidth+widthMargin+barreWidth/2;

	//trace du rectangle vert
	RectangleShape Vert;
	Vert.setFillColor(Color(0, 255, 0, 255));
	Vert.setSize(Vector2f(barreWidth, vertHeight));
	Vert.setPosition(workWidth + widthMargin, heightMargin);
	fenetre.draw(Vert);

	//trace du rectangle rouge
	RectangleShape Rouge;
	Rouge.setFillColor(Color(255, 0, 0, 255));
	Rouge.setSize(Vector2f(barreWidth, rougeHeight));
	Rouge.setPosition(workWidth + widthMargin, heightMargin + vertHeight);
	fenetre.draw(Rouge);

	//trace du rectangle rouge
	RectangleShape Jaune;
	Jaune.setFillColor(Color(255, 255, 0, 255));
	Jaune.setSize(Vector2f(barreWidth, jauneHeight));
	Jaune.setPosition(workWidth + widthMargin, heightMargin + vertHeight - jauneHeight / 2);
	fenetre.draw(Jaune);
}

void effotMetre()
{
	//definition de la zone ou va se trouver l'effortmetre
	int workWidth=width * 1 / 100;		//positionnement � 1% de la largeur de l'ecran
	int workHeight=height * 50 / 100;	//50% de la hauteur de l'ecran
	int widthMargin=workWidth * 1 / 100;
	int heightMargin=workHeight * 4 / 100;

	VertexArray BarreSuperieure(Quads, 4);

	// trace de la forme superieure de l'effort metre
	BarreSuperieure[0].position = Vector2f(workWidth + widthMargin, workHeight); //+heightMargin);
	BarreSuperieure[1].position = Vector2f(workWidth + widthMargin + width * 2 / 100 - 2 * widthMargin, workHeight); //+heightMargin);
	BarreSuperieure[2].position = Vector2f(workWidth + widthMargin + width * 2 / 100 - 2 * widthMargin, workHeight + (workHeight - 2 * heightMargin) / 2);
	BarreSuperieure[3].position = Vector2f(workWidth + widthMargin + (width * 2 / 100 - 2 * widthMargin) * 0.7, workHeight + (workHeight - 2 * heightMargin) / 2); //positionne a la moyenne des deux premieres coordonnes

	fenetre.draw(BarreSuperieure);

	VertexArray BarreInferieure(Quads, 4);

	//2 premiers points a la meme position que les deux dernier de la barre superieur
	BarreInferieure[0].position = Vector2f(workWidth+widthMargin + (width * 2 / 100 - 2 * widthMargin) * 0.7, workHeight + (workHeight - 2 * heightMargin) / 2);
	BarreInferieure[1].position = Vector2f(workWidth+widthMargin + width * 2 / 100 - 2 * widthMargin, workHeight + (workHeight - 2 * heightMargin) / 2);
	BarreInferieure[2].position = Vector2f(workWidth+widthMargin + width * 2 / 100 - 2 * widthMargin, height - heightMargin);
	BarreInferieure[3].position = Vector2f(workWidth + widthMargin, height - heightMargin); //positionne a la moyenne des deux premieres coordonnes

	fenetre.draw(BarreInferieure);

	//dessin du trait du milieu
	int traitHeight = height * 1 / 100; //4% de la largeur de l'ecran
	int traitWidht = width * 2 / 100 - 2 * widthMargin;
	RectangleShape trait;
	trait.setFillColor(Color(255,255,255,255));
	trait.setSize(Vector2f(traitWidht, traitHeight));
	trait.setPosition(workWidth + widthMargin, workHeight + (workHeight - 2 * heightMargin) / 2);
	fenetre.draw(trait);

	//ecriture dest textes 0, T et F
	Text neutre("0", arial, height * 2 / 100);
	int position = workHeight + (workHeight - 2 * heightMargin) / 2.2;
	neutre.setPosition(workWidth - width * 0.5 / 100, position);
	//neutre.setColor(color.White);
	fenetre.draw(neutre);

	Text traction("T", arial, height * 2 / 100);
	position = workHeight;
	traction.setPosition((workWidth + widthMargin) + width * 0.2 / 100, position);
	traction.setFillColor(color.Black);
	fenetre.draw(traction);

	Text freinage("F", arial, height * 2 / 100);
	position = height - heightMargin - height * 2.1 / 100;
	freinage.setPosition((workWidth + widthMargin) + width * 0.2 / 100, position);
	freinage.setFillColor(color.Black);
	fenetre.draw(freinage);
}

//Vector2f local2globalCoordonates(Vector2f localOrigin, float teta_origine, Vector2f CoordonneesPolaires){
//	Vector2f Coordonnees;
//	Coordonnees.x=localOrigin.x-(-1)*CoordonneesPolaires.x* cos((CoordonneesPolaires.y-teta_origine)* PI / 180.0); //PI/180 permet de passer de la valeur de radians a une valeur en degree
//	Coordonnees.y=localOrigin.y-(-1)*CoordonneesPolaires.x* sin((CoordonneesPolaires.y-teta_origine)* PI / 180.0); // le facteur -1 permet de se mettre dans le cas du cercle trigonometrique
//	return Coordonnees;
//}

void fondStatique(double RE)
{
    boiteAGlacons(RE);
    fondEcran();
    barreTension();
    effotMetre();
}

ConvexShape dessinFlecheTension()
{
	int flecheWidth = width * 0.5 / 100;
	int barreWidth = width * 0.75 / 100;
	int barreHeight = height * 0.5 / 100;
	int flecheHeight = 2 * barreHeight;

	ConvexShape fleche;
	fleche.setPointCount(7);

	fleche.setPoint(0, Vector2f(0, 0));
	fleche.setPoint(1, Vector2f(0 - flecheWidth, 0 - flecheHeight / 2));
	fleche.setPoint(2, Vector2f(0 - flecheWidth, 0 - barreHeight / 2));
	fleche.setPoint(3, Vector2f(0 - flecheWidth - barreWidth, 0 - barreHeight / 2));
	fleche.setPoint(4, Vector2f(0 - flecheWidth - barreWidth, 0 + barreHeight / 2));
	fleche.setPoint(5, Vector2f(0 - flecheWidth, 0 + barreHeight / 2));
	fleche.setPoint(6, Vector2f(0 - flecheWidth, 0 + flecheHeight / 2));

	fleche.setPosition(width / 2,0);

	return fleche;
}

void positionnementFlecheTension(ConvexShape FlecheTension, float position)
{
	//position varie entre -100 (rouge) et 100 (vert) et est le positionnement du cursur en % sur la barre tension
	float posx = width * 2 / 100;
	float y0 = height * 25 / 100;
	float barreHeight = (height * 50 / 100 - 2 * height * 50 / 100 * 4 / 100) / 2;

	FlecheTension.setPosition(posx, y0 - barreHeight * position / 100);
        FlecheTension.setFillColor(color.Black);

	fenetre.draw(FlecheTension);
}

void positionnementCurseurEffortMetre(float position)
{
	int workHeight = height * 50 / 100;
	int heightMargin = workHeight * 4 / 100;
	float barreWidth = width * 2 / 100 - 2 * width * 2 / 100 * 1 / 100;
	float barreHeight = height * 0.5 / 100;
	float y0 = workHeight + (workHeight - 2 * heightMargin) / 2 + barreHeight / 2;
	float effortMetreHeight=(height * 50 / 100 - heightMargin) / 2;


	RectangleShape barre(Vector2f(barreWidth,barreHeight));
	barre.setPosition(width * 2 / 100 + width * 2 / 100 * 1 / 100, y0 - effortMetreHeight * position / 100);
	barre.setFillColor(color.Red);

	fenetre.draw(barre);
}

void chargementPictoBAG(PictoBAG *Picto, double RE)
{
	float facteur, facteurx, facteury;
	FloatRect dimPicto;
	float caseWidth,caseHeight,ombreHeight;

	dimPicto=Picto->sprite.getGlobalBounds();

	caseWidth = (positionsCaseBAG[1][0].x - positionsCaseBAG[0][0].x - width * 1 / 100);
	caseHeight = (positionsCaseBAG[0][1].y - positionsCaseBAG[0][0].y - width * 1 / 100);
	ombreHeight=caseHeight / 3;

	facteurx=caseWidth/dimPicto.width;
	facteury=(caseHeight-ombreHeight)/dimPicto.height;
	facteur=min(facteurx,facteury);
	Picto->mise_a_lechelle(facteur,facteur);
	dimPicto=Picto->sprite.getGlobalBounds();
	Picto->sprite.setPosition(640 * RE + positionsCaseBAG[Picto->position.x][Picto->position.y].x+caseWidth/2-dimPicto.width/2.1,positionsCaseBAG[Picto->position.x][Picto->position.y].y+(caseHeight+ombreHeight)/1.9-dimPicto.height/1.9);
}

void SocketSend()
{
  	//create listening socket

	//int connected = 0;

	int listening=socket(AF_INET,SOCK_STREAM,0);

	if (listening ==-1)
	{
		return;
	}
	socketValue=1;
	//Bind to IP/Port

	string ipAddress="0.0.0.0";

	struct sockaddr_in hint;
	hint.sin_family = AF_INET;
  	hint.sin_port = htons(54000);
  	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);
	socketValue=3;
	while(true)
	{
        if (bind(listening, (struct sockaddr*)&hint, sizeof(hint))!=-1)
		{
            socketValue = 4;
            if(listen(listening, 1) != -1)
			{
                socketValue = 5;
                break;
            }
        }
        socketValue = 10;
    }

	//Accept a call

	struct sockaddr_in client;
	socklen_t clientSize;
	char host[NI_MAXHOST];
	char svc[NI_MAXSERV];

	clientSocket = accept(listening, (struct sockaddr*)&client, &clientSize);

	if(clientSocket == -1)
	{
		return;
	}
	socketValue = 6;
	close(listening);
	memset(host, 0, NI_MAXHOST);
	memset(svc, 0, NI_MAXSERV);

	int result = getnameinfo((struct sockaddr*)&client, sizeof(client), host, NI_MAXHOST, svc, NI_MAXSERV, 0);

	if(result)
	{
		//connected=1;
	}
	else
	{
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
	}
	socketValue = 7;
	//While

	char buf[4096];

	while(true)
	{
		//Clear buffer
		memset(buf, 0, 4096);
		int bytesReceived = recv(clientSocket, buf, sizeof(buf), 0);
                if(bytesReceived == -1)
				{
                    cout << "";
                    socketValue = 8;
                }
                else if(bytesReceived == 0)
				{
                    cout << "";
                    socketValue = 9;
                }

                //Display Connected
                else
				{
                    cout << "Connected" << endl;
                    send(clientSocket, buf, sizeof(buf), 0);
                    socketValue = 11;
                    break;
                }
	}
	while(true)
	{
		char c[1];
		recv(clientSocket,c,sizeof(c),0);
		if(c[0] == '&')
		{
		  socketValue = 12;
		  break;
		}
    }
}

void affichageMoteursIsole(char nombre, Vector2i position)
{
	float caseWidth, caseHeight, ombreHeight;
	FloatRect tailleTexte;

	caseWidth = (positionsCaseBAG[1][0].x - positionsCaseBAG[0][0].x - width * 1 / 100);
	caseHeight = (positionsCaseBAG[0][1].y - positionsCaseBAG[0][0].y - width * 1 / 100);
	ombreHeight = caseHeight / 3;

	Text MotIsol;
	MotIsol.setFont(digital);
	MotIsol.setString(nombre);
	MotIsol.setFillColor(color.Red);
	MotIsol.setCharacterSize(height * 8 / 100);
	tailleTexte = MotIsol.getGlobalBounds();
	MotIsol.setPosition(positionsCaseBAG[position.x][position.y].x + caseWidth / 2 - tailleTexte.width / 1.6, positionsCaseBAG[position.x][position.y].y + (caseHeight + ombreHeight) / 2 - tailleTexte.height / 1);

	//MotIsol.setPosition(100,100);
	fenetre.draw(MotIsol);
}

void animationMotIsole(Clock *clockMotIsol)
{
	Time intervalle = seconds(0.2);

	if(clockMotIsol->getElapsedTime() >= intervalle && nombreMotIsole == '2'  )
	{
		nombreMotIsole = '1';
		clockMotIsol->restart();
	}
	else if(clockMotIsol->getElapsedTime() >= intervalle && nombreMotIsole == '1')
	{
		nombreMotIsole = ' ';
		clockMotIsol->restart();
	}
}

void traitementDonneesRecues()
{

}

void reinitialise()
{
    clignotementTVM = false;
    enableTVM = false;
    nombreMotIsole = '2';
    enableDJ = false;
    socketValue = 0;
    pcValue = 0;
    arduinoValue = 0;
    sock = socket(AF_INET, SOCK_STREAM,0);
    clientSocket = 0;
    vitesse = 0;
    actualRav = 0;
    lastPanto = 0;
    positionTension = 0;
    positionEffort = 0;
    effortTraction = 0;
    power = 0;
    debut[0] = ' ';
    manipTraction = "0"; //0 à 511 : frein motrice, 512 à 1023 : traction
    manipPantoMode = "0"; // 0 : 0, 1 : N, 2 : S, 3 : LGV
    manipPantoTension = "0"; //0 : M, 1 : C, 2 : LGV
    urgencePanto = "true"; //0 : urgence panto activé, 1 : non activé
    bpUrg = "true"; //0 : frein d'urgence activé, 1 : non activé
    manipFreinageSerrage = "false"; //0 : non serrage, 1 : serrage;
    manipFreinageDesserrage = "false"; //0 : non desserrage, 1 : desserrage;
    fermetureDisjoncteur = "false"; //0 = ouvert, 1 = fermé;
    armementDisjoncteur = "false"; //0 = non changement d'etat, 1 = changement d'etat
    tvmVoie2 = "false"; //0 = non changement d'état, 1 = changement d'etat
    tvmVoie1 = "false"; //0 = non armé, 1 = armé
    tvmDesarmement = "false"; //0 = non armé, 1 = armé
    reboot = 0;
}

//void chargementPictoBAG(){
//	PictoBAG test("ressources/pictoBoiteAGlacons/LS DJ AUX.png");
//	test.convesionImage();
//
//
//}

//envoi données vers Trainz
void receptionDonneesEcran1()
{
    while(true)
	{
    	char bf[1024];
    	//int bytesReceived;
    	do
		{
    	   memset(bf, 0, sizeof(bf));
    	   //bytesReceived = recv(clientSocket, bf, sizeof(bf), 0);
    	}
		while(bf[0] != '?');
		// on définit les 9 strings que l'on a recues précédemment
    	string s0 = "";
    	string s1 = "";
    	string s2 = "";
    	string s3 = "";
    	string s4 = "";
    	string s5 = "";
    	string s6 = "";
    	string s7 = "";
    	string s8 = "";

    	//on affecte les 9 strings reçues

    	//s0 = vitesse actuelle
    	//s1 = sablage
    	//s2 = tension ligne
    	//s3 = effort de traction
    	//s4 = puissance
    	//s5 = fermeture disjoncteur
    	//s6 = armement disjoncteur
    	//s7 = gradient
    	//s8 = PK

    	int counter = 1;
    	while(bf[counter] != '!')
		{
    		s0 = s0 + bf[counter];
    		counter = counter + 1;
    	}
    	l5 = s0;
    	counter = counter + 1;
    	while(bf[counter] != '!')
		{
    		s1 = s1 + bf[counter];
    		counter = counter + 1;
    	}

    	counter = counter + 1;
    	while(bf[counter] != '!')
		{
    		s2 = s2 + bf[counter];
    		counter = counter + 1;
    	}
    	counter = counter + 1;
    	while(bf[counter] != '!')
		{
    		s3 = s3 + bf[counter];
    		counter = counter + 1;
    	}
    	l1 = s3;
    	counter = counter + 1;
    	while(bf[counter]!='!')
		{
    		s4 = s4 + bf[counter];
    		counter = counter + 1;
    	}
    	l2 = s4;
    	counter = counter + 1;
    	while(bf[counter] != '!')
		{
    		s5 = s5 + bf[counter];
    		counter = counter + 1;
    	}
    	counter = counter + 1;
    	while(bf[counter] != '!')
		{
    		s6 = s6 + bf[counter];
    		counter = counter + 1;
    	}

    	counter = counter + 1;
    	while(bf[counter] != '!')
		{
    		s7 = s7 + bf[counter];
    		counter = counter + 1;
    	}
    	l3 = s7;
    	counter = counter + 1;
    	while(bf[counter] != '!')
		{
    		s8 = s8 + bf[counter];
    		counter = counter+1;
    	}
    	l4 = s8;

    	vitesseTrain = stof(s0);

    	// rajouter un ! a la fin de la string trainz !!!
   		// actualRav=stof(s0);
  		// actualRav = 2.7 + 0.032 * stof(s0) + 0.000535 * stof(s0) * stof(s0);

    	//affichage LS-SA
   		/*
    	if (s1=="true" or s1=="false")
    	    LSSab.afficher();
    	else
   		LSSab.effacer();

    	//Indicateur tension ligne


    	if (s2=="0" && lastPanto==1)
    		positionTension=-100;
    	else if (s2=="1" && lastPanto==0) {
    		positionTension=100;
    	}
    	else
    	    positionTension=0;

    	//effort traction

    	effortTraction=stoi(s7)*2;

    	//positionEffort

    	positionEffort = static_cast<float>(effortTraction)/2.5;

    	//power

    	power = stoi(s8)*2;


    	//lampes disjoncteur
   		*/
    	if(s6 == "false")
		{
    	    LSDJAUX.afficher();
    	    LSDJ.afficher();
    	}
    	else
		{
    	    LSDJAUX.effacer();
    	    LSDJ.effacer();
    	}

    	//autres lampes qui se ferment à la fermeture disjoncteur

    	if(s5 == "false")
		{
    	    enableDJ = false;
    	    LSDFDJC.afficher();
    	    AUTORFERMDJ.afficher();
    	    LSAEBA.afficher();
    	    LSAL.afficher();
    	    LSSab.afficher();
    	    LSBCJS.afficher();
    	    LSBCRD.afficher();
    	    LSDFF.afficher();
    	    LSDFND.afficher();
    	    LSDFP.afficher();
    	    LSDFSURV.afficher();
    	    LSDFT.afficher();
    	    LSDFTRA.afficher();
    	    LSECO.afficher();
    	    LSFEP.afficher();
    	    LSFRVAN.afficher();
    	    LSI.afficher();
    	    LSINSBG.afficher();
    	    LSPCO.afficher();
    	    LSSIAL.afficher();
    	    LSUTCAB.afficher();
    	}
    	else
		{
    	    enableDJ=true;
    		LSDFDJC.effacer();
    		AUTORFERMDJ.effacer();
    	    LSAEBA.effacer();
    	    LSAL.effacer();
    	    LSSab.effacer();
    	    LSBCJS.effacer();
    	    LSBCRD.effacer();
    	    LSDFF.effacer();
    	    LSDFND.effacer();
    	    LSDFP.effacer();
    	    LSDFSURV.effacer();
    	    LSDFT.effacer();
    	    LSDFTRA.effacer();
    	    LSECO.effacer();
    	    LSFEP.effacer();
    	    LSFRVAN.effacer();
    	    LSI.effacer();
    	    LSINSBG.effacer();
    	    LSPCO.effacer();
    	    LSSIAL.effacer();
    	    LSUTCAB.effacer();
    	}

    	//lampe de signalisation affichant si le manip traction est à 0 ou non (LS-MPC0)

    	if(s3 == "0")
    	    LSGR.afficher();
    	else
    	    LSGR.effacer();
    }

    send(clientSocket, "&", 1, 0);
}

void affichageTexteDivers()
{
    cout << "";
	Text texte;
    int tg = atoi(l2.c_str()) * 2;
    int rg = atoi(l1.c_str()) * 2;
    float lg = 10 * atof(l3.c_str());
    float mg = atof(l4.c_str());
    int tailleAffichDistance = 0;
    String rav = to_string(2.7 + atoi(l5.c_str()) * 0.032+atoi(l5.c_str()) * atoi(l5.c_str()) * 0.000535);
	String string = "Puissance = " + to_string(tg) + " kW\n";
    string = string + "Effort de traction = " + to_string(rg) + " kN\n";
    string = string + "RAV = " + rav.substring(0,5) + " kN\n";
    string = string + "Profil = " + to_string(lg).substr(0,4) + L" ‰\n";
    // calcul de la taille de la string distance à afficher
    if (mg < 10)
        tailleAffichDistance = 3;
    else if(mg < 100)
        tailleAffichDistance = 4;
    else if(mg < 1000)
        tailleAffichDistance = 5;
    string = string + "Distance = " + to_string(mg).substr(0,tailleAffichDistance) + " km";

	texte.setFont(arial);
	texte.setCharacterSize(height * 3 / 100);
	texte.setString(string);
	texte.setPosition((width * 0.05), (height / 2) * 1.07);
	fenetre.draw(texte);
}