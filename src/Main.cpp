#include <SFML/Graphics.hpp> //test Thomas 3
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
#include "son_train.hpp"
#include "Buttons.hpp"
#include "planning.hpp"

class Donnees
{
	V2f m_cartesiens;
	V2f m_polaire;
    float m_vitesse;
};

// test 27/09/19 a 13h20
// test 27/09/19 a 13h40
//TEST NICOLAS gdqsihbsdf aaaaaa

//Prototypes
void affichageRectangle(double RE, RenderWindow & fenetre, string ecran, int * ecart);
void affichageBoutons(double RE, RenderWindow & fenetre, int * ecart);
void arcVitesse(V2f centre, float V_red, float V_orange, float V_yellow, float V_white, float V_medium_grey, float V_dark_grey, double RE, RenderWindow & fenetre, Font & arial, DonneesAfficheurVitesse graduations[], int * ecart);
void initialisation(int Vmax, double RE, vector<Symbol> & symbol, RenderWindow & fenetre, Font & arial, V2f & centreIV, ConvexShape & aiguille, DonneesAfficheurVitesse graduations[], int * ecart);
void demarage(RenderWindow & fenetre);
void fondEcran(RenderWindow & fenetre, double RE, int * ecart);
V2f initValeurIndicateurVitesse(int Vmax, double RE, DonneesAfficheurVitesse graduations[], int * ecart);
void indicateurVitesse(V2f centre, Color couleurAiguille, double RE, RenderWindow & fenetre, Font & arial, DonneesAfficheurVitesse graduations[], int Vmax, int * ecart);
V2f local2globalCoordonates(V2f localOrigin, float teta_origine, V2f CoordonneesPolaires);
ConvexShape dessinAiguilleIV(V2f centre, double RE);
void positionnementAiguille(ConvexShape aiguille, float vitesse, double RE, RenderWindow & fenetre, Font & arial, DonneesAfficheurVitesse graduations[], int * ecart);
void planningInformation(RenderWindow & fenetre, double RE, Font & arial, vector<Symbol> & symbol, donnees &train, int * ecart, float temps_ecoule, Gradient &gradient, vector<PASP> &tab_pasp);
void gestionnaireAffichage(donnees & train);
void windows(string & ecran, RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string version, donnees &train, vector<VBC> vbc, vector<Buttons> & boutons, int & numero, int * ecart);
void close(string & ecran, vector<Buttons> & boutons, int & numero);
void driverIDWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void test();
void actualisationDonnees(donnees & train, string status, float red, float orange, float yellow, float white, float mediumGrey, float darkGrey);
void mainWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string version, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void specialWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void settingsWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<VBC> & vbc, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void SRspeedWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void dataViewWindows(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string title, int & numero, vector<Buttons> & boutons, string & ecran, vector<vector<string>> item, int * ecart);
void RBCdataWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void dataViewWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void systemVersionWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void dataEntryWindows(vector<vector<string>> input_field, RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, int complete, string title, vector<string> selection, int & sel, string keyboard, vector<Buttons> & boutons, string & ecran, donnees & train, int * ecart);
void menuWindows(vector <string> selection, vector <int>& enable, RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string title, int * ecart);
void overrideWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string version, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void adhesionWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void RBCcontactWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void ERTMS_ETCSlevelWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void trainRunningNumberWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void radionetworkIDWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void trainDataWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void brightnessWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void volumeWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void languageWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);

void test()
{
	while(true)
		sleep(milliseconds(10));
}

int main()
{
	Son son;
	init_alarmes(son);
	Clock chrono;//d�but d�mo (delta_t = 0)
	Time difftemps;
	donnees train;
	DonneesAfficheurVitesse graduations[401];
	ConvexShape aiguille;	// Creation des formes de l'aiguille de l'IV
	V2f centreIV;						// Position du centre de l'indicateur de Vitesse
	Font arial;
	RenderWindow fenetre;
	double RE;
	int ecart[] = {0, 0};
	vector<Symbol> symbol(154);
	string version;
	string TTI = "On";
	int LSSMA = 120;
	int speedRange = 400;
	string ecran = "defaultWindow";
	vector<VBC> vbc(20);
	Event event;
	vector <Buttons> buttons(16);
	for(int i = 0; i <= 15; i++)
		buttons[i].settype("up_type");
	buttons[6].settype("up_type");
	int numero = 1;
	int temp_TTI = 0;


///////////////////////////////////////////////
	PASP pasp0(400,40000);//évite erreur vector vide
	PASP pasp1(225, 3000);
	PASP pasp2(150, 5000);
	PASP pasp5(0,8000);

	vector<PASP> tab_pasp;
	tab_pasp.push_back(pasp0);
	tab_pasp.push_back(pasp1);
	tab_pasp.push_back(pasp2);
	tab_pasp.push_back(pasp5);

	Gradient gradient1(2001,2000,20);
	Gradient gradient2(0,2000,0);
	Gradient gradient3(10000,5000,-5);
	Gradient gradient4(4001,6000,0);
	Gradient gradient5(15001,7000,35);

	vector<Gradient> tab_grad;
	tab_grad.push_back(gradient1);
	tab_grad.push_back(gradient2);
	tab_grad.push_back(gradient3);
	tab_grad.push_back(gradient4);
	tab_grad.push_back(gradient5);

	Planning_Announcements PA1(1500,98);
	Planning_Announcements PA2(1000,72);
	Planning_Announcements PA3(3000,97);
	Planning_Announcements PA6(4000,75);


	vector<Planning_Announcements> tab_pa;//tout picto sauf flèche
	tab_pa.push_back(PA1);
	tab_pa.push_back(PA2);
	tab_pa.push_back(PA3);
	tab_pa.push_back(PA6);

	Planning_Announcements PAF1;
	Planning_Announcements PAF2;
	Planning_Announcements PAF3;
	Planning_Announcements PAF4;
	Planning_Announcements PAF5;


	vector<Planning_Announcements> tab_paf;//FLÉCHES VITESSE

	PAF1.PAF(225, 3000);
	PAF2.PAF(150, 5000);
	PAF3.PAF(0,8000);

	tab_paf.push_back(PAF1);
	tab_paf.push_back(PAF2);
	tab_paf.push_back(PAF3);



////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////////////////////
	string choix;
	do
	{
		cout << "MERCI DE RENTRER LA VERSION A = 3.6.0 B = 3.4.0"<<endl;
		cin >> choix;
		cout << choix << endl;
	}while(choix !="A" && choix !="B");
	if(choix == "A")
		version = "3.6.0";
	if(choix =="B")
		version = "3.4.0";
	///////////////////////////////////////////////////////////////////////////////////////////////

	if(VideoMode::getDesktopMode().width / 640.0 < VideoMode::getDesktopMode().height / 480.0)
		RE = VideoMode::getDesktopMode().width / 640.0;	//rapport Ecran
	else
		RE = VideoMode::getDesktopMode().height / 480.0; //rapport Ecran
	CircleShape SSI(10 / 2.0 * RE);
	SSI.setFillColor(WHITE);

	initialisation(speedRange, RE, symbol, fenetre, arial, centreIV, aiguille, graduations, ecart);
	//clockMoteurIsole.restart();

	Thread thread1(&test);
	thread1.launch();

    //affiche la fenetre tant que l'utilisateur n'appuie pas sur la croix
    while(fenetre.isOpen())
    {
		for(int i = 0; i <= 15; i++)
		{
			if(buttons[i].getdriver_action() == 3)
				buttons[i].setdriver_action(0);
			if(buttons[i].getdriver_action() == 1)
				buttons[i].setdriver_action(2);
		}
        while(fenetre.pollEvent(event))
        {
		    if(event.type == Event::Closed)
                fenetre.close();
			if(event.type == Event::KeyPressed)
			{
			    if(event.key.code == Keyboard::Escape)
			        fenetre.close();
				else if(event.key.code == Keyboard::A)
				{
			        if(buttons[0].getdriver_action() == 0)
						buttons[0].setdriver_action(1);
				}
				else if(event.key.code == Keyboard::Z)
				{
					if(buttons[1].getdriver_action() == 0)
						buttons[1].setdriver_action(1);
					else
						buttons[1].setdriver_action(2);
				}
				else if(event.key.code == Keyboard::E)
				{
			        if(buttons[2].getdriver_action() == 0)
						buttons[2].setdriver_action(1);
					else
						buttons[2].setdriver_action(2);
				}
				else if(event.key.code == Keyboard::R)
				{
			        if(buttons[3].getdriver_action() == 0)
						buttons[3].setdriver_action(1);
					else
						buttons[3].setdriver_action(2);
				}
				else if(event.key.code == Keyboard::T)
				{
			        if(buttons[4].getdriver_action() == 0)
						buttons[4].setdriver_action(1);
					else
						buttons[4].setdriver_action(2);
				}
				else if(event.key.code == Keyboard::Y)
				{
			        if(buttons[5].getdriver_action() == 0)
						buttons[5].setdriver_action(1);
					else
						buttons[5].setdriver_action(2);
				}
				else if(event.key.code == Keyboard::U)
				{
			        if(buttons[6].getdriver_action() == 0)
						buttons[6].setdriver_action(1);
					else
						buttons[6].setdriver_action(2);
				}
				else if(event.key.code == Keyboard::I)
				{
			        if(buttons[7].getdriver_action() == 0)
						buttons[7].setdriver_action(1);
					else
						buttons[7].setdriver_action(2);
				}
				else if(event.key.code == Keyboard::O)
				{
			        if(buttons[8].getdriver_action() == 0)
						buttons[8].setdriver_action(1);
					else
						buttons[8].setdriver_action(2);
				}
				else if(event.key.code == Keyboard::P)
				{
			        if(buttons[9].getdriver_action() == 0)
						buttons[9].setdriver_action(1);
					else
						buttons[9].setdriver_action(2);
				}
				else if(event.key.code == Keyboard::Q)
				{
			        if(buttons[10].getdriver_action() == 0)
						buttons[10].setdriver_action(1);
					else
						buttons[10].setdriver_action(2);
				}
				else if(event.key.code == Keyboard::S)
				{
			        if(buttons[11].getdriver_action() == 0)
						buttons[11].setdriver_action(1);
					else
						buttons[11].setdriver_action(2);
				}
				else if(event.key.code == Keyboard::D)
				{
			        if(buttons[12].getdriver_action() == 0)
						buttons[12].setdriver_action(1);
					else
						buttons[12].setdriver_action(2);
				}
				else if(event.key.code == Keyboard::F)
				{
			        if(buttons[13].getdriver_action() == 0)
						buttons[13].setdriver_action(1);
					else
						buttons[13].setdriver_action(2);
				}
				else if(event.key.code == Keyboard::G)
				{
			        if(buttons[14].getdriver_action() == 0)
						buttons[14].setdriver_action(1);
					else
						buttons[14].setdriver_action(2);
				}
				else if(event.key.code == Keyboard::H)
				{
			        if(buttons[15].getdriver_action() == 0)
						buttons[15].setdriver_action(1);
					else
						buttons[15].setdriver_action(2);
				}
			}
			if(event.type == Event::KeyReleased)
			{
				if(event.key.code == Keyboard::A)
			        buttons[0].setdriver_action(3);
				else if(event.key.code == Keyboard::Z)
			        buttons[1].setdriver_action(3);
				else if(event.key.code == Keyboard::E)
			        buttons[2].setdriver_action(3);
				else if(event.key.code == Keyboard::R)
			        buttons[3].setdriver_action(3);
				else if(event.key.code == Keyboard::T)
			        buttons[4].setdriver_action(3);
				else if(event.key.code == Keyboard::Y)
			        buttons[5].setdriver_action(3);
				else if(event.key.code == Keyboard::U)
			        buttons[6].setdriver_action(3);
				else if(event.key.code == Keyboard::I)
			        buttons[7].setdriver_action(3);
				else if(event.key.code == Keyboard::O)
			        buttons[8].setdriver_action(3);
				else if(event.key.code == Keyboard::P)
			        buttons[9].setdriver_action(3);
				else if(event.key.code == Keyboard::Q)
			        buttons[10].setdriver_action(3);
				else if(event.key.code == Keyboard::S)
			        buttons[11].setdriver_action(3);
				else if(event.key.code == Keyboard::D)
			        buttons[12].setdriver_action(3);
				else if(event.key.code == Keyboard::F)
			        buttons[13].setdriver_action(3);
				else if(event.key.code == Keyboard::G)
			        buttons[14].setdriver_action(3);
				else if(event.key.code == Keyboard::H)
			        buttons[15].setdriver_action(3);
			}
        }
		for(int i = 0; i <= 15; i++)
			buttons[i].action_type(son);

        difftemps = chrono.getElapsedTime();
        chrono.restart();
        float delta_ts=difftemps.asSeconds();

        if(train.getVtrain() > 160 || train.getVtrain() == - 1)
        	demo(train);
        if(train.getVtrain() < 160)
        	demo2(train);
        calcul(delta_ts,train);

		//train.setVtrain(0);
        gestionnaireAffichage(train);
		aiguille.setFillColor(train.getCouleurAiguille());
       	fenetre.clear();

		fondEcran(fenetre, RE, ecart);

		affichageBoutons(RE, fenetre, ecart);


		if(ecran != "trainDataWindow" && ecran != "RBCdataWindow")
		{
			affichageRectangle(RE, fenetre, ecran, ecart);
			for(int i = 0; i < 154; i++) // reafficher toutes les images
			{
				symbol[i].effacer();
			}
		}
		else
		{
			for(int i = 0; i < 154; i++) // reafficher toutes les images
			{
				symbol[i].effacer();
			}
		}

		if(ecran != "trainDataWindow" && ecran != "RBCdataWindow")
		{
			indicateurVitesse(centreIV, train.getCouleurAiguille(), RE, fenetre, arial, graduations, speedRange, ecart);
			if(train.getVtrain() > 0)
				arcVitesse(centreIV, train.getVred(), train.getVorange(), train.getVyellow(), train.getVwhite(), train.getVmediumGrey(), train.getVdarkGrey(), RE, fenetre, arial, graduations, ecart);
			positionnementAiguille(aiguille, train.getVtrain(), RE, fenetre, arial, graduations, ecart);
			if(train.getConnection() == "Up") //Connection Up
				{
				ST_03.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 * 3 + 25 / 2.0), RE, ecart, fenetre);	//E1
				}
			else if(train.getConnection() == "Lost/Set-Up failed") //Connection Lost/Set-Up failed
				ST_04.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 * 3 + 25 / 2.0), RE, ecart, fenetre);	//E1
			if(train.getReversing() == "Permitted") //Reversing permitted indication
				ST_06.afficher(V2f(54 + 37 * 3 + 58 + 37 + 37 / 2.0, 300 + 50 / 2.0), RE, ecart, fenetre);	//C6

			if(version == "3.6.0")
			{
				train.setTTI((train.getDEOA() - (3 / 5.0)*train.getD_but())/train.getVtrain()); // TEMPORAIRE POUR LA DEMO

				if((train.getGeneralMode() == "FS" || ((train.getGeneralMode() == "OS" || train.getGeneralMode() == "SR") && TTI == "On")) && (train.getMode() == "CSM" || train.getMode() == "PIM"))  //A1 : TTI
				{
					if(temp_TTI == 0)
					{
						jouer_alarmes(son, 2, 1);
						temp_TTI = 1;
					}
					rectangle(V2f(2,2), V2f(50, 50), DARK_GREY, RE, fenetre, ecart);
					for(int n = 0; n <= 10; n++)
					{
						if(14*(10 - n)/10 <= train.getTTI() && train.getTTI() < 14*(10 - (n - 1))/10)
							rectangle(V2f(54/2 - 2.5*n, 54/2 - 2.5*n), V2f(n*5,n*5), WHITE, RE, fenetre, ecart);
					}
				}
				else
					temp_TTI = 0;

				SSI.setPosition(V2f(local2globalCoordonates(centreIV, 90 + 144, V2f(111 * RE, graduations[20].teta() - abs(graduations[0].teta() - graduations[1].teta()) / 2.0)).x - 6 * RE, local2globalCoordonates(centreIV, 90 + 144, V2f(111 * RE, graduations[20].teta() - abs(graduations[0].teta() - graduations[1].teta()) / 2.0)).y - 6 * RE));
				fenetre.draw(SSI);
			}
			if(version == "3.4.0")		//Voir avec benoit
			{

				LS_01.afficher(V2f(54 / 2.0, 54 / 2.0), RE, ecart, fenetre);	//A1
				creation_texte(RE, to_string(LSSMA), arial, GREY, 16, 0, V2f(54 / 2.0, 54 / 2.0), fenetre, 1, ecart); //400km/h

			}

			if(train.getLevelETCS() == "Level 0")
                LE_01.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 + 25 / 2.0), RE, ecart, fenetre);
            else if(train.getLevelETCS()  == "Level 1")
                LE_03.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 + 25 / 2.0), RE, ecart, fenetre);
            else if(train.getLevelETCS()  == "Level 2")
                LE_04.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 + 25 / 2.0), RE, ecart, fenetre);
            else if(train.getLevelETCS()  == "Level 3")
                LE_05.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 + 25 / 2.0), RE, ecart, fenetre);

			if((train.getGeneralMode() == "FS" && (train.getMode() == "PIM" || train.getMode() == "TSM" || train.getMode() == "RSM")) || train.getGeneralMode() == "RV")
				targetDistance(train.getDEOA(), fenetre, RE, arial, ecart);

			if(ecran == "defaultWindow")
			{
				for (int i = 0; i <= 15; i++)
					buttons[i].settype("up_type");
				if(buttons[0].getactivation() == 1)
				{
					buttons[3].settype("disabled");
					buttons[10].settype("disabled");
					buttons[12].settype("disabled");
					buttons[13].settype("disabled");
					buttons[14].settype("disabled");
					buttons[15].settype("disabled");
                    ecran = "mainWindow";
				}
				else if(buttons[1].getactivation() == 1)
				{
					ecran = "overrideWindow";
					for(int i = 0; i <= 15; i++)
						buttons[i].settype("disabled");
					buttons[0].settype("up_type");
					buttons[11].settype("up_type");
				}
				else if(buttons[2].getactivation() == 1)
				{
					ecran = "dataViewWindow";
					for(int i = 0; i <= 15; i++)
						buttons[i].settype("disabled");
				}
				else if(buttons[3].getactivation() == 1)
					ecran = "specialWindow";
				else if(buttons[4].getactivation() == 1)
					ecran = "settingsWindow";
				else if (buttons[5].getactivation() == 1)
                {
                    if(train.getTunnelStoppingArea() == "TunnelStoppingArea" || train.getTunnelStoppingArea() == "TunnelStoppingAreaAnnouncement")
                        train.setTunnelStoppingArea(train.getTunnelStoppingArea() + "-");
                    else if (train.getTunnelStoppingArea() == "TunnelStoppingArea-" || train.getTunnelStoppingArea() == "TunnelStoppingAreaAnnouncement-")
                        train.setTunnelStoppingArea(train.getTunnelStoppingArea().substr(0, train.getTunnelStoppingArea().size() - 1));
                }

				else if (buttons[6].getactivation() == 1)
				{
					if(train.getS_D_monitoring() == "On")
						train.setS_D_monitoring("Off");
					else if (train.getS_D_monitoring() == "Off")
						train.setS_D_monitoring("On");
				}

				else if (buttons[7].getactivation() == 1)
				{
					if(train.getGeographicalPosition() == "On")
						train.setGeographicalPosition("Off");
					else if (train.getGeographicalPosition() == "Off")
						train.setGeographicalPosition("On");
				}
				else if(buttons[8].getactivation() == 1)
				{
					if(train.getPlanningScale() < 32000)
					train.setPlanningScale(train.getPlanningScale() * 2.0);
				}
				else if(buttons[9].getactivation() == 1)
				{
					if(train.getPlanningScale() > 1000)
					train.setPlanningScale(train.getPlanningScale() / 2.0);
				}
				else if (buttons[10].getactivation() == 1 && version == "3.4.0")
				{
					if(train.getPlanning() == "show planning information")
						train.setPlanning("Off");
					else if(train.getPlanning() == "Off")
						train.setPlanning("show planning information");
				}
				if(train.getTunnelStoppingArea() != "TunnelStoppingAreaUnknown")
                {
                    if(train.getTunnelStoppingArea() == "TunnelStoppingArea")
                    {
                        TC_36.afficher(V2f(54 + 37 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE, ecart, fenetre);  //C2
                        creation_texte(RE, to_string(train.getRemainingDistanceTunnel()), arial, GREY, 12, 0, V2f(54 + 3 * 37 - 10, 54 + 30 + 191 + 25 + 50 / 2.0), fenetre, 2, ecart);
                    }
                    else if(train.getTunnelStoppingArea() == "TunnelStoppingAreaAnnouncement")
                    {
                        TC_37.afficher(V2f(54 + 37 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE, ecart, fenetre);  //C2
                        creation_texte(RE, to_string(train.getRemainingDistanceTunnel()), arial, GREY, 12, 0, V2f(54 + 3 * 37 - 10, 54 + 30 + 191 + 25 + 50 / 2.0), fenetre, 2, ecart);
                    }
                    DR_05.afficher(V2f(64 * 5 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0), RE, ecart, fenetre); //F6
                }
				if(train.getGeographicalPosition() != "Unknown") //Geographical position
				{
					if(train.getGeographicalPosition() == "On") //toggled on
					{
						rectangle(V2f(54 + 234 + 46 + 63, 54 + 30 + 191 + 25 + 50 + 50), V2f(120, 30), GREY, RE, fenetre, ecart);//G12
						creation_texte(RE, to_string(train.getPointKilometrique()), arial, BLACK, 12, 0, V2f(54 + 234 + 46 + 63 + 120 / 2.0, 54 + 30 + 191 + 25 + 50 + 50 + 30 / 2.0), fenetre, 3, ecart);
					}
					DR_03.afficher(V2f(64 * 7 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0), RE, ecart, fenetre);	//F8

				}
				if(train.getPlanning() != "Unknown")
				{
					if(version == "3.4.0")
					{
						NA_02.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 / 2.0), RE, ecart, fenetre);		//H2
						if(train.getPlanning() == "show planning information" && train.getGeneralMode() == "FS")
							planningInformation(fenetre, RE, arial, symbol, train, ecart, delta_ts, tab_grad, tab_pasp, tab_pa, tab_paf);
					}
					if(version == "3.6.0" && (train.getGeneralMode() == "FS" || (train.getGeneralMode() == "OS" && train.getS_D_monitoring() == "On")))
					{
						planningInformation(fenetre, RE, arial, symbol, train, ecart, delta_ts, tab_grad, tab_pasp, tab_pa, tab_paf);
					}
				}

				time_t curtime;
				time(&curtime);
				string date = ctime(&curtime);
				creation_texte(RE, date.substr(10,9), arial, GREY, 10, 0, V2f(54 + 280 + 63 + 120 + 63 / 2.0, 300 + 50 + 50 + 30 / 2.0), fenetre, 1, ecart);
				creation_texte(RE, "Main", arial, GREY, 16, 0, V2f(64 / 2.0, 300 + 4 * 25 + 30 + 50 / 2.0), fenetre, 1, ecart);
				creation_texte(RE, "Over-", arial, GREY, 16, 0, V2f(64 + 64 / 2.0, 300 + 4 * 25 + 30 + 50 / 2.0 - 10), fenetre, 1, ecart);
				creation_texte(RE, "ride", arial, GREY, 16, 0, V2f(64 + 64 / 2.0, 300 + 4 * 25 + 30 + 50 / 2.0 + 10), fenetre, 1, ecart);
				creation_texte(RE, "Data", arial, GREY, 16, 0, V2f(64 * 2 + 64 / 2.0, 300 + 4 * 25 + 30 + 50 / 2.0 - 10), fenetre, 1, ecart);
				creation_texte(RE, "view", arial, GREY, 16, 0, V2f(64 * 2 + 64 / 2.0, 300 + 4 * 25 + 30 + 50 / 2.0 + 10), fenetre, 1, ecart);
				creation_texte(RE, "Spec", arial, GREY, 16, 0, V2f(64 * 3 + 64 / 2.0, 300 + 4 * 25 + 30 + 50 / 2.0), fenetre, 1, ecart);

				SE_04.afficher(V2f(64 * 4 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0), RE, ecart, fenetre);			//F5
				DR_01.afficher(V2f(64 * 6 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0), RE, ecart, fenetre);			//F7
				NA_13.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 3 + 64 / 2.0), RE, ecart, fenetre);	//H5
				NA_14.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 4 + 64 / 2.0), RE, ecart, fenetre);	//H6
				NA_17.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2 + 64 / 2.0), RE, ecart, fenetre);	//H4
				NA_18.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0), RE, ecart, fenetre);		//H3
				NA_20.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 5 * 64 + 82 / 2.0), RE, ecart, fenetre);	//H7
				DR_04.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2, 28 + 5 * 64 + 82 / 2.0), RE, ecart, fenetre);		//H7
			}
		}

		windows(ecran, fenetre, RE, symbol, arial, version, train, vbc, buttons, numero, ecart);

		//ST_02.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 / 2.0), RE);	//A4
		//ST_01.afficher(V2f(54 / 2.0, 54 + 30 + 191 + + 25 + 25 + 25 / 2.0), RE);	//C9
		//LE_06.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);	//C1
		//LE_07.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);	//C1
		//LE_08.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);	//C1
		//LE_08a.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);//C1
		//LE_09.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);	//C1
		//LE_09a.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);//C1
		//LE_10.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);	//C1
		//LE_11.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);	//C1
		//LE_12.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);	//C1
		//LE_13.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);	//C1
		//LE_14.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);	//C1
		//LE_15.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);	//C1
		//MO_01.afficher(V2f(54 + 254, 274), RE);	//B7
		//MO_02.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);	//C1
		//MO_04.afficher(V2f(54 + 254, 274), RE);	//B7
		//MO_05.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);	//C1
		//MO_06.afficher(V2f(54 + 254, 274), RE);	//B7
		//MO_07.afficher(V2f(54 + 254, 274), RE);	//B7
		//MO_08.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);	//C1
		//MO_09.afficher(V2f(54 + 254, 274), RE);	//B7
		//MO_10.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);	//C1
		//MO_11.afficher(V2f(54 + 254, 274), RE);	//B7
		//MO_12.afficher(V2f(54 + 254, 274), RE);	//B7
		//MO_13.afficher(V2f(54 + 254, 274), RE);	//B7
		//MO_14.afficher(V2f(54 + 254, 274), RE);	//B7
		//MO_15.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);	//C1
		//MO_16.afficher(V2f(54 + 254, 274), RE);	//B7
		//MO_17.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);	//C1
		//MO_18.afficher(V2f(54 + 254, 274), RE);	//B7
		//MO_20.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);	//C1
		//MO_21.afficher(V2f(54 + 254, 274), RE);	//B7
		//MO_22.afficher(V2f(54 + 3 * 37 + 58 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0), RE);	//C1

        fenetre.display();
    }
    return 0;
}

void initialisation(int Vmax, double RE, vector<Symbol> & symbol, RenderWindow & fenetre, Font & arial, V2f & centreIV, ConvexShape & aiguille, DonneesAfficheurVitesse graduations[], int * ecart)
{
	//recuperation de la police
	arial.loadFromFile("ressources/fonts/arial.ttf");

	//definition des parametres de la fenetre
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	//initialisation des donnees
	initSymbol(symbol);

	//calculs preliminaires
	centreIV= initValeurIndicateurVitesse(Vmax, RE, graduations, ecart);
    aiguille = dessinAiguilleIV(centreIV, RE);

	//creation et affichage de la fenetre
	fenetre.create(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height),"Ecran central", Style::Default, settings);
//	fenetre.create(VideoMode(VideoMode::getDesktopMode().width,height),"Ecran central",Style::Fullscreen, settings);
	fenetre.setFramerateLimit(60);
}

void demarage(RenderWindow & fenetre)
{
	Image ImageDemarage;
	Texture textureDemarage;
	Sprite spriteDemarage;

	ImageDemarage.loadFromFile("ressources/ecran demarage.png");

	textureDemarage.loadFromImage(ImageDemarage,IntRect());
	textureDemarage.setSmooth(true);
	spriteDemarage.setTexture(textureDemarage);

	///////////////////////////////////////////////////////////
	//mise � l'echelle de l'image

	FloatRect rectDemarage;

	//recuperation de la taille de l'image
	rectDemarage = spriteDemarage.getGlobalBounds();

	float scaleHeight, scaleWidth;
	//calcul du facteur d'echelle a appliquer
	scaleHeight = VideoMode::getDesktopMode().height/rectDemarage.height;
	scaleWidth = VideoMode::getDesktopMode().width / rectDemarage.width;

	//mise a l'echelle absolue
	spriteDemarage.setScale(scaleWidth,scaleHeight);
	//////////////////////////////////////////////////////////////////
	//positionnement du sprite
	spriteDemarage.setPosition(0,0);

	//////////////////////////////////////////////////////////////////
	//ecriture du texte
	Font eurostile;
	eurostile.loadFromFile("ressources/fonts/Eurostile.ttf");
	Text chargement("Chargement", eurostile, 80);
	//centrage
	FloatRect texte;
	texte = chargement.getGlobalBounds();
	int position= VideoMode::getDesktopMode().width / 2 - texte.width / 2;
	chargement.setPosition(position, VideoMode::getDesktopMode().height / 1.4);
	//chargement.setColor(color.White);

	fenetre.draw(spriteDemarage);
	fenetre.draw(chargement);
}

void fondEcran(RenderWindow & fenetre, double RE, int * ecart)
{
	// definition d'un Vertex array
	VertexArray fond(Quads,4);
	//definition des points

	fond[0].position = V2f(ecart[0] * RE, ecart[1] * RE);
	fond[1].position = V2f((640 + ecart[0]) * RE, ecart[1] * RE);
	fond[2].position = V2f((640 + ecart[0]) * RE, (480 + ecart[1]) * RE);
	fond[3].position = V2f(ecart[0] * RE, (480 + ecart[1]) * RE);

	couleurForme(fond, DARK_BLUE, 4);

	fenetre.draw(fond);
}

V2f initValeurIndicateurVitesse(int Vmax, double RE, DonneesAfficheurVitesse graduations[], int * ecart)
{
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

	V2f centre(RE * (54 + 280 / 2.0 + ecart[0]), RE * (300 / 2.0 + ecart[1]));
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
	return centre;
}

void indicateurVitesse(V2f centre, Color couleurAiguille, double RE, RenderWindow & fenetre, Font & arial, DonneesAfficheurVitesse graduations[], int Vmax, int * ecart)
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

	// ecriture des vitesses
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

V2f local2globalCoordonates(V2f localOrigin, float teta_origine, V2f CoordonneesPolaires)
{
	V2f Coordonnees;
	Coordonnees.x = localOrigin.x - (- 1) * CoordonneesPolaires.x* cos((CoordonneesPolaires.y-teta_origine)* PI / 180.0); //PI/180 permet de passer de la valeur de radians a une valeur en degree
	Coordonnees.y = localOrigin.y - (- 1) * CoordonneesPolaires.x* sin((CoordonneesPolaires.y-teta_origine)* PI / 180.0); // le facteur -1 permet de se mettre dans le cas du cercle trigonometrique
	return Coordonnees;
}

void affichageRectangle(double RE, RenderWindow & fenetre, string ecran, int * ecart)		//Affiche toutes les cases sur l'\E9cran
{
	if(ecran == "defaultWindow")
	{
		creation_rectangle(V2f((54 + 234 + 46), (54 + 30 + 191 + 25 + 50 + 50)), V2f(63, 30), RE, 1, fenetre, ecart);			//G11
		creation_rectangle(V2f((54 + 234 + 46 + 63), (54 + 30 + 191 + 25 + 50 + 50)), V2f(120, 30), RE, 1, fenetre, ecart);		//G12
		creation_rectangle(V2f((54 + 234 + 46 + 63 + 120), (54 + 30 + 191 + 25 + 2 * 50)), V2f(63, 30), RE, 1, fenetre, ecart);	//G13
	}
	creation_rectangle(V2f(0, 0), V2f(54, 54), RE, 1, fenetre, ecart);															//A1
	creation_rectangle(V2f(0, 54), V2f(54, (191 + 30)), RE, 1, fenetre, ecart);													//A2-3
	creation_rectangle(V2f(0, (54 +30 + 191)), V2f(54, 25), RE, 1, fenetre, ecart);												//A4
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25)), V2f(54, 25), RE, 1, fenetre, ecart);										//C8
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 2)), V2f(54, 25), RE, 1, fenetre, ecart);									//C9
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 3)), V2f(54, 25), RE, 1, fenetre, ecart);									//E1
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 4)), V2f(54, 25), RE, 1, fenetre, ecart);									//E2
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 5)), V2f(54, 25), RE, 1, fenetre, ecart);									//E3
	creation_rectangle(V2f((54 + 26 - 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), RE, 1, fenetre, ecart);						//B6
	creation_rectangle(V2f((54 + 140 + 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), RE, 1, fenetre, ecart);						//B5
	creation_rectangle(V2f((54 + 140 - 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), RE, 1, fenetre, ecart);						//B4
	creation_rectangle(V2f((54 + 140 - 36 * 3 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), RE, 1, fenetre, ecart);					//B3
	creation_rectangle(V2f((54 + 254 - 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), RE, 1, fenetre, ecart);						//B7
	creation_rectangle(V2f((54 + 3 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), RE, 1, fenetre, ecart);							//C1
	creation_rectangle(V2f(54, 0), V2f(280, 300), RE, 1, fenetre, ecart);														//B
	creation_rectangle(V2f(54, (54 + 30 + 191 + 25 + 50)), V2f(234, 4 * 20), RE, 1, fenetre, ecart);							//E5-6-7-8
	creation_rectangle(V2f((54 + 234), (54 + 30 + 191 + 25 + 50)), V2f(46, 40), RE, 2, fenetre, ecart);							//E10
	creation_rectangle(V2f((54 + 234), (54 + 30 + 191 + 25 + 50 + 40)), V2f(46, 40), RE, 2, fenetre, ecart);					//E11
	creation_rectangle(V2f(62, 257), V2f(36, 36), RE, 1, fenetre, ecart); //B6
	creation_rectangle(V2f(140, 257), V2f(36, 36), RE, 1, fenetre, ecart); //B3
	creation_rectangle(V2f(177, 257), V2f(36, 36), RE, 1, fenetre, ecart); //B4
	creation_rectangle(V2f(212, 257), V2f(36, 36), RE, 1, fenetre, ecart); //B5
	creation_rectangle(V2f(289, 257), V2f(36, 36), RE, 1, fenetre, ecart); //B7
}

void affichageBoutons(double RE, RenderWindow & fenetre, int * ecart)
{
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);							//F1
	creation_rectangle(V2f(64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);							//F2
	creation_rectangle(V2f(2 *64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);						//F3
	creation_rectangle(V2f(3 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);						//F4
	creation_rectangle(V2f(4 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);						//F5
	creation_rectangle(V2f(5 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);						//F6
	creation_rectangle(V2f(6 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);						//F7
	creation_rectangle(V2f(7 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);						//F8
	creation_rectangle(V2f(8 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);						//F9
	creation_rectangle(V2f(9 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), RE, 2, fenetre, ecart);						//F10
	creation_rectangle(V2f((640 - 40), 28), V2f(40, 64), RE, 2, fenetre, ecart);											//H2
	creation_rectangle(V2f((640 - 40), (28 + 64)), V2f(40, 64), RE, 2, fenetre, ecart);										//H3
	creation_rectangle(V2f((640 - 40), (28 + 2 * 64)), V2f(40, 64), RE, 2, fenetre, ecart);									//H4
	creation_rectangle(V2f((640 - 40), (28 + 3 * 64)), V2f(40, 64), RE, 2, fenetre, ecart);									//H5
	creation_rectangle(V2f((640 - 40), (28 + 4 * 64)), V2f(40, 64), RE, 2, fenetre, ecart);									//H6
	creation_rectangle(V2f((640 - 40), (28 + 5 * 64)), V2f(40, 82), RE, 2, fenetre, ecart);									//H7
}

void arcVitesse(V2f centre, float V_red, float V_orange, float V_yellow, float V_white, float V_medium_grey, float V_dark_grey, double RE, RenderWindow & fenetre, Font & arial, DonneesAfficheurVitesse graduations[], int * ecart)
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

ConvexShape dessinAiguilleIV(V2f centre, double RE)
{
	ConvexShape aiguille;
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

	return aiguille;
}

void positionnementAiguille(ConvexShape aiguille,float vitesse, double RE, RenderWindow & fenetre, Font & arial, DonneesAfficheurVitesse graduations[], int * ecart)
{
	float teta0 = 90 - 144;
	float kmh2degVfaible = 144.0 / 150.0;  //nombre de degre pour 1km/h ici a 144� on a 150km/h
	float kmh2degVeleve = kmh2degVfaible / 2.0;

	if (vitesse < 200)
		aiguille.setRotation(vitesse * kmh2degVfaible+teta0);
	else
		aiguille.setRotation(200 * kmh2degVfaible / 2.0 + vitesse * kmh2degVeleve+teta0);

	fenetre.draw(aiguille);

	string str=to_string(graduations[(int)vitesse].vitesse());
	string s;
	if(graduations[(int)vitesse].vitesse() > 100)
	{
		s = str.at(2);
		creation_texte(RE, s, arial, BLACK, 18, 0, V2f(54 + 280 / 2.0 + 50 / 2.0 - 3, 300 / 2.0), fenetre, 2, ecart);
		s = str.at(1);
		creation_texte(RE, s, arial, BLACK, 18, 0, V2f(54 + 280 / 2.0 + 50 / 6.0 - 3, 300 / 2.0), fenetre, 2, ecart);
		s = str.at(0);
		creation_texte(RE, s, arial, BLACK, 18, 0, V2f(54 + 280 / 2.0 - 50 / 6.0 - 3, 300 / 2.0), fenetre, 2, ecart);
	}
	else if(graduations[(int)vitesse].vitesse() > 10)
	{
		s = str.at(1);
		creation_texte(RE, s, arial, BLACK, 18, 0, V2f(54 + 280 / 2.0 + 50 / 3.0, 300 / 2.0), fenetre, 1, ecart);
		s = str.at(0);
		creation_texte(RE, s, arial, BLACK, 18, 0, V2f(54 + 280 / 2.0, 300 / 2.0), fenetre, 1, ecart);
	}
	else
	{
		s = str.at(0);
		creation_texte(RE, s, arial, BLACK, 18, 0, V2f(54 + 280 / 2.0 + 50 / 3.0, 300 / 2.0), fenetre, 1, ecart);
	}
}

void actualisationDonnees(donnees & train, string status, float red, float orange, float yellow, float white, float mediumGrey, float darkGrey)
{
	train.setStatus(status);
	train.setVred(red);
	train.setVorange(orange);
	train.setVyellow(yellow);
	train.setVwhite(white);
	if(darkGrey == 0)
		train.setVmediumGrey(mediumGrey);
	else
		train.setVmediumGrey(0);
	train.setVdarkGrey(darkGrey);
}

void gestionnaireAffichage(donnees & train)
{
	cout << train.getStatus() << train.getMode() << endl;
	if(train.getGeneralMode() == "FS" || train.getGeneralMode() == "OS")
	{
		if(train.getMode() == "CSM")
		{
			if(train.getStatus() == "IntS" || train.getVtrain() >= train.getVitesseFLOISL())
			{
				if(train.getVtrain()<= train.getVitessePSL())
					train.setCouleurAiguille(GREY);
				else
					train.setCouleurAiguille(RED);
				actualisationDonnees(train, "IntS", train.getVitesseFLOISL(), 0, 0, 0, 0, train.getVitessePSL());
				if(train.getVtrain() < train.getVitessePSL())
					train.setStatus("NoS");
			}
			else if(train.getStatus() == "WaS" || (train.getVtrain() >= train.getVWaS() && train.getVtrain() < train.getVitesseFLOISL()))
			{
				train.setCouleurAiguille(ORANGE);
				actualisationDonnees(train, "WaS", 0, train.getVitesseFLOISL(), 0, 0, 0, train.getVitessePSL());
				if(train.getVtrain() < train.getVitessePSL())
					train.setStatus("NoS");
			}
			else if(train.getStatus() == "OvS" || (train.getVtrain() >= train.getVitessePSL() && train.getVtrain() < train.getVWaS()))
			{
				train.setCouleurAiguille(ORANGE);
				actualisationDonnees(train, "OvS", 0, train.getVitesseFLOISL(), 0, 0, 0, train.getVitessePSL());
				if(train.getVtrain() < train.getVitessePSL())
					train.setStatus("NoS");
			}
			else if(train.getStatus() == "NoS")
			{
				train.setCouleurAiguille(GREY);
				actualisationDonnees(train, "OvS", 0, 0, 0, 0, 0, train.getVitessePSL());
				if(train.getVtrain() < train.getVitessePSL())
					train.setStatus("NoS");
			}
		}
        else if(train.getMode() == "PIM")
        {
            if(train.getStatus() == "IntS" || train.getVtrain() >= train.getVitesseFLOISL())
            {
            	if(train.getVtrain()<= train.getVbut())
            		train.setCouleurAiguille(GREY);
            	else if(train.getVtrain()<= train.getVitessePSL())
            		train.setCouleurAiguille(WHITE);
            	else
            		train.setCouleurAiguille(RED);
            	actualisationDonnees(train, "IntS", train.getVitesseFLOISL(), 0,0, train.getVitessePSL(), train.getVrelease(), train.getVbut());

                if(train.getVtrain() < train.getVitessePSL())
                    train.setStatus("NoS");
            }
            else if(train.getStatus() == "WaS" || (train.getVtrain() >= train.getVWaS() && train.getVtrain() < train.getVitesseFLOISL()))
            {
            	train.setCouleurAiguille(ORANGE);
                actualisationDonnees(train, "WaS", 0, train.getVitesseFLOISL(), 0, train.getVitessePSL(), train.getVrelease(),train.getVbut());
                if(train.getVtrain() < train.getVitessePSL())
                    train.setStatus("NoS");
            }
            else if(train.getStatus() == "OvS" || (train.getVtrain() >= train.getVitessePSL() && train.getVtrain() < train.getVWaS()))
            {
            	train.setCouleurAiguille(ORANGE);
                actualisationDonnees(train, "OvS", 0, train.getVitesseFLOISL(), 0,train.getVitessePSL(), train.getVrelease(), train.getVbut());
                if(train.getVtrain() < train.getVitessePSL())
                    train.setStatus("NoS");
            }
            else if(train.getStatus() == "NoS")
            {
				if(train.getVtrain()<= train.getVbut())
					train.setCouleurAiguille(GREY);
				else
					train.setCouleurAiguille(WHITE);
                actualisationDonnees(train, "NoS", 0, 0, 0, train.getVitessePSL(), train.getVrelease(), train.getVbut());
                if(train.getVtrain() < train.getVitessePSL())
                    train.setStatus("NoS");
            }
        }
		else if(train.getMode() == "TSM")
		{
			if(train.getStatus() == "IntS" || train.getVtrain() >= train.getVitesseFLOISL())
			{
				if(train.getVtrain()<= train.getVbut())
					train.setCouleurAiguille(GREY);
				else if(train.getVtrain()<= train.getVitessePSL())
					train.setCouleurAiguille(YELLOW);
				else
					train.setCouleurAiguille(RED);
				actualisationDonnees(train, "IntS",train.getVitesseFLOISL(), 0,train.getVitessePSL(), 0 , train.getVrelease(), train.getVbut());
				if(train.getVtrain() < train.getVbut())
					train.setStatus("NoS");
			}
			else if(train.getStatus() == "WaS" || (train.getVtrain() >= train.getVWaS() && train.getVtrain() < train.getVitesseFLOISL()))
			{
				train.setCouleurAiguille(ORANGE);
				actualisationDonnees(train, "WaS", 0, train.getVitesseFLOISL(), train.getVitessePSL(), 0, train.getVrelease(), train.getVbut());
				if(train.getVtrain() < train.getVbut())
					train.setStatus("NoS");
			}
			else if(train.getStatus() == "OvS" || (train.getVtrain() >= train.getVitessePSL() && train.getVtrain() < train.getVWaS()))
			{
				train.setCouleurAiguille(ORANGE);
				actualisationDonnees(train, "OvS",  0, train.getVitesseFLOISL(), train.getVitessePSL(), 0 , train.getVrelease(), train.getVbut());
				if(train.getVtrain() < train.getVbut())
					train.setStatus("NoS");
			}
			else if(train.getStatus() == "IndS" || (train.getVtrain() > train.getVbut() && (train.getVtrain() < train.getVitessePSL() && train.getVtrain() >= train.getVitesseISL())))
			{
				train.setCouleurAiguille(YELLOW);
				actualisationDonnees(train, "IndS", 0, 0, train.getVitessePSL(), 0 , train.getVrelease(), train.getVbut());//OK
				if (train.getVtrain() < train.getVbut())
					train.setStatus("NoS");
			}
			else if(train.getStatus() == "NoS")
			{
				if(train.getVtrain()<= train.getVbut())
					train.setCouleurAiguille(GREY);
				else
					train.setCouleurAiguille(WHITE);
				actualisationDonnees(train, "NoS", 0, 0, 0, train.getVitessePSL(), train.getVrelease(), train.getVbut());//OK
				if(train.getVtrain() < train.getVbut())
					train.setStatus("NoS");
			}
		}
		else if(train.getMode() == "RSM")
		{

		}
	}
	else if(train.getGeneralMode() == "LS")
	{
		if(train.getMode() == "CSM")
		{

		}
		else if(train.getMode() == "PIM")
		{

		}
		else if(train.getMode() == "TSM")
		{

		}
		else if(train.getMode() == "RSM")
		{

		}
	}
	else if(train.getGeneralMode() == "SR/UN")
	{
		if(train.getMode() == "CSM")
		{

		}
		else if(train.getMode() == "PIM")
		{

		}
		else if(train.getMode() == "TSM")
		{

		}
	}
	else if(train.getGeneralMode() == "SH/RV")
	{
		if(train.getMode() == "CSM")
		{

		}
	}
	else if(train.getGeneralMode() == "NL/SB/PT")
	{

	}
	else if(train.getGeneralMode() == "TR")
	{

	}
}

void menuWindows(vector <string> selection, vector <int>& enable, RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string title, int * ecart)
{
	Color color;
	rectangle(V2f(54 + 280, 0), V2f(266, 24), BLACK, RE, fenetre, ecart);
	NA_11.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0), RE, ecart, fenetre);	//H5
	for(int i = 0; i < (int)selection.size(); i++)
	{
		if(enable[i] == 0)
			color = GREY;
		else if(enable[i] == 1)
			color = DARK_GREY;
		if(enable[i] != 2)
		{
			creation_texte(RE, to_string(i + 1) + " - " + selection[i], arial, color, 12, 0, V2f(54 + 280 + 15, 100 + 6 + i * 20), fenetre, 4, ecart);
			creation_texte(RE, to_string(i + 1), arial, color, 16, 0, V2f(64 / 2.0 + i * 64, 430 + 50 / 2.0), fenetre, 1, ecart);
		}
	}
	creation_texte(RE, title, arial, GREY, 12, 0, V2f(54 + 280 + 3, 12), fenetre, 4, ecart);
}

void mainWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string version, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
    vector <string> selection(9);
    vector <int> enable(9);
    for (int i = 0; i <= 9; i++)
        enable[i] = 1;
    enable[3] = 2;
    if((train.getVtrain() == 0 && train.getGeneralMode() == "SB" && train.getDriverID() && train.getTrainData() && train.getETATLevelETCS() && train.getTrainNumber()) ||
		((train.getVtrain() == 0 && train.getGeneralMode() == "PT" && train.getTrainData()) && (train.getLevelETCS() == "Level 1" || ((train.getLevelETCS() == "Level 2" ||
		train.getLevelETCS() == "Level 3") && train.getConnection() == "Up" && version == "3.6.0" && train.getPending_Emergency_Stop() == false))) || ((train.getVtrain() == 0 &&
		train.getGeneralMode() == "PT" && train.getTrainData()) && (train.getLevelETCS() == "Level 1" || ((train.getLevelETCS() == "Level 2" || train.getLevelETCS() == "Level 3") &&
		version == "3.4.0" && train.getPending_Emergency_Stop() == false))) || (train.getGeneralMode() == "SR" && (train.getLevelETCS() == "Level 2" || train.getLevelETCS() == "Level 3") &&
		train.getConnection() == "Up" && version == "3.6.0") || (train.getGeneralMode() == "SR" && (train.getLevelETCS() == "Level 2" || train.getLevelETCS() == "Level 3") && version == "3.4.0"))
    {
        enable[0] = 0;
         boutons[0].settype("up_type");
    }
    else
        boutons[0].settype("disabled");
    if((train.getVtrain() == 0 && train.getGeneralMode() == "SB" && train.getDriverID() && train.getETATLevelETCS()) ||((train.getModif_DriverID_NTC() ||(train.getModif_DriverID_NTC() == false &&
		train.getVtrain() == 0)) && (train.getGeneralMode() == "SH" || train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" ||
		train.getGeneralMode() == "OS" || train.getGeneralMode() == "NL" || train.getGeneralMode() == "UN" || train.getGeneralMode() == "SN" )))
    {
        enable[1] = 0;
        boutons[1].settype("up_type");
        if(boutons[1].getactivation() == 1)
        {
            ecran = "driverIDWindow";
            for(int i = 0; i <= 10; i++)
                boutons[i].settype("down_type");
            boutons[11].settype("up_type");
			boutons[12].settype("disabled");
			boutons[13].settype("disabled");
			boutons[14].settype("disabled");
            boutons[15].settype("delay_type");
        }
    }
    else
        boutons[1].settype("disabled");
    if(train.getVtrain() == 0 && train.getDriverID() && train.getDriverID() && train.getETATLevelETCS() && (train.getGeneralMode() == "SB" || train.getGeneralMode() == "FS" ||
		train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" || train.getGeneralMode() == "OS" || train.getGeneralMode() == "NL" || train.getGeneralMode() == "UN" ||
		train.getGeneralMode() == "SN" ))
    {
        enable[2] = 0;
        boutons[2].settype("up_type");
        if(boutons[2].getactivation() == 1)
        {
            ecran = "trainDataWindow";
            for(int i = 0; i <= 14; i++)
                boutons[i].settype("down_type");
			boutons[10].settype("disabled");
            boutons[11].settype("up_type");
            boutons[12].settype("up_type");
            boutons[15].settype("delay_type");
        }
    }
    else
        boutons[2].settype("disabled");
    if(train.getVtrain() == 0 && train.getDriverID() && (train.getGeneralMode() == "SB" || train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" ||
		train.getGeneralMode() == "OS" || train.getGeneralMode() == "NL" || train.getGeneralMode() == "UN" || train.getGeneralMode() == "SN" ))
    {
        enable[4] = 0;
        boutons[4].settype("up_type");
        if(boutons[4].getactivation() == 1)
        {
            ecran = "ERTMS_ETCSlevelWindow";
            for(int i = 0; i <= 14; i++)
                boutons[i].settype("down_type");
			boutons[10].settype("disabled");
            boutons[11].settype("up_type");
			boutons[12].settype("disabled");
			boutons[13].settype("disabled");
			boutons[14].settype("disabled");
            boutons[15].settype("delay_type");
        }
    }
    else
        boutons[4].settype("disabled");
    if((train.getVtrain() == 0 && train.getGeneralMode() == "SB" && train.getDriverID() && train.getETATLevelETCS()) || ((train.getGeneralMode() == "SB" || train.getGeneralMode() == "FS" ||
		train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" || train.getGeneralMode() == "OS" || train.getGeneralMode() == "NL"|| train.getGeneralMode() == "UN" ||
		train.getGeneralMode() == "SN" )))
    {
        enable[5] = 0;
        boutons[5].settype("up_type");
        if(boutons[5].getactivation() == 1)
        {
            ecran = "trainRunningNumberWindow";
            for(int i = 0; i <= 14; i++)
                boutons[i].settype("down_type");
			boutons[10].settype("down_type");
            boutons[11].settype("up_type");
            boutons[12].settype("disabled");
			boutons[13].settype("disabled");
			boutons[14].settype("disabled");
            boutons[15].settype("delay_type");
        }
    }
    else
        boutons[5].settype("disabled");
    if((train.getVtrain() == 0 && train.getDriverID() && (train.getGeneralMode() == "SB" || train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" ||
		train.getGeneralMode() == "OS" || train.getGeneralMode() == "UN" || train.getGeneralMode() == "SN" ) && train.getETATLevelETCS() && ((train.getLevelETCS() == "Level 0" ||
		train.getLevelETCS() == "Level 1" || train.getLevelETCS().substr(0,2) == "NTC") || ((train.getLevelETCS() == "Level 2" || train.getLevelETCS() == "Level 3") &&
		train.getConnection() == "Up"))) || (train.getVtrain() == 0 && train.getGeneralMode() == "PT" && (train.getLevelETCS() == "Level 1" || ((train.getLevelETCS() == "Level 2" ||
		train.getLevelETCS() == "Level 3") && train.getConnection() == "Up" && train.getPending_Emergency_Stop() == false))))
    {
        enable[6] = 0; //shunting
        boutons[6].settype("up_type");
    }
    else if(train.getVtrain() == 0 && train.getGeneralMode() == "SH")
    {
        enable[6] = 0;//Exit Shunting
        boutons[6].settype("up_type");
    }
    else
        boutons[6].settype("disabled");
    if(train.getVtrain() == 0 && train.getDriverID() && train.getETATLevelETCS() && (train.getGeneralMode() == "SB" || train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" ||
		train.getGeneralMode() == "SR" || train.getGeneralMode() == "OS" || train.getGeneralMode() == "SH") && train.getNon_Leading() == false)
    {
        enable[7] = 0;
        boutons[7].settype("up_type");
    }
    else
        boutons[7].settype("disabled");
    if(train.getGeneralMode() == "SH" && train.getPassive_Shunting())
    {
        enable[8] = 0;
        boutons[8].settype("up_type");
    }
    else
        boutons[8].settype("disabled");
    if (version == "3.6.0")
    {
        if (train.getVtrain() == 0 && train.getDriverID() && train.getETATLevelETCS() && (train.getGeneralMode() == "SB" || train.getGeneralMode() == "FS" ||
        	train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" || train.getGeneralMode() == "OS" || train.getGeneralMode() == "NL"||
        	train.getGeneralMode() == "UN" || train.getGeneralMode() == "SN" || train.getGeneralMode() == "PT"))
        {
            enable[9] = 0;
            boutons[9].settype("up_type");
        }
        else
            boutons[9].settype("disabled");
    }
    else
    {
        enable[9] = 2;
        boutons[9].settype("disabled");
    }
    selection = {"Start", "Driver ID", "Train data", "", "Level", "Train running number", "Shunting", "Non-Leading", "Maintain Shunting"};
    if(version == "3.6.0")
        selection.push_back("Radio data");
    menuWindows(selection, enable, fenetre, RE, symbol, arial, "Main", ecart);
    close(ecran, boutons, numero);
}


void overrideWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string version, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
    vector <string> selection(1);
    vector <int> enable(1);
    enable[0] = 1;
    if ((train.getVtrain() <=  train.getVrelease() && (train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" || train.getGeneralMode() == "OS"||
        train.getGeneralMode() == "UN" || train.getGeneralMode() == "SN" || train.getGeneralMode() == "SH"))
        || (train.getVtrain() <=  train.getVrelease() && train.getGeneralMode() == "SB" && train.getDriverID() && train.getTrainData() && train.getETATLevelETCS() &&
		(train.getLevelETCS() == "Level 2" || train.getLevelETCS() == "Level 3")) || (version =="3.6.0" && (train.getVtrain() <=  train.getVrelease() && train.getGeneralMode() == "PT" &&
		train.getTrainData() && train.getTrainNumber())))
    {
        boutons[0].settype("up_type");
        if(version == "3.4.0" || (version == "3.6.0" && train.getTrainNumber()))
            enable[0] = 0;
    }
    else
        boutons[0].settype("disabled");
    if (boutons[0].getactivation())
    {
        ecran = "defaultWindow";
        if(train.getEOA())
            train.setEOA(false);
        else
            train.setEOA(true);
    }
    selection = {"EOA"};
    menuWindows(selection, enable, fenetre, RE, symbol, arial, "Override", ecart);
    close(ecran, boutons, numero);
}

void specialWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
    vector <string> selection(3);
    vector <int> enable(3);
    for (int i = 0; i <= 2; i++)
        enable[i] = 1;
    if ((train.getVtrain() == 0 && train.getGeneralMode() == "SB" && train.getmodif_Adhesion() && train.getDriverID() && train.getTrainData() && train.getETATLevelETCS())
        || (train.getmodif_Adhesion() && (train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" || train.getGeneralMode() == "OS"||
        train.getGeneralMode() == "UN" || train.getGeneralMode() == "SN")))
    {
            enable[0] = 0;
            boutons[0].settype("up_type");
    }
    else
        boutons[0].settype("disabled");
    if(train.getVtrain() == 0 && train.getGeneralMode() == "SR")
    {
        enable[1] = 0;
        boutons[1].settype("up_type");
    }
    else
        boutons[1].settype("disabled");
    if (train.getVtrain() == 0 && train.getDriverID() && train.getTrainData() && train.getETATLevelETCS() && (train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" ||
		train.getGeneralMode() == "SR" || train.getGeneralMode() == "OS"|| train.getGeneralMode() == "PT" || train.getGeneralMode() == "SB"))
    {
        enable[2] = 0;
        boutons[2].settype("up_type");
    }
    else
        boutons[2].settype("disabled");
    if (boutons[2].getactivation())
        ecran = "defaultWindow";
    else if (boutons[1].getactivation())
        ecran = "SRspeed/distanceWindow";
    else if (boutons[0].getactivation())
    {
        ecran = "adhesionWindow";
		boutons[10].settype("disabled");
		boutons[12].settype("disabled");
		boutons[13].settype("disabled");
		boutons[14].settype("disabled");
    }
    selection = {"Adhesion", "SR speed / distance", "Train integrity"};
    menuWindows(selection, enable, fenetre, RE, symbol, arial, "Special", ecart);
    close(ecran, boutons, numero);
}

void settingsWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<VBC> & vbc, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
    vector <string> selection(6);
    vector <int> enable(6);
    for (int i = 0; i <= 5; i++)
        enable[i] = 1;
    if ((train.getVtrain() == 0 && train.getGeneralMode() == "SB")
        || (train.getGeneralMode() == "SH" || train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" ||train.getGeneralMode() == "OS" ||
        train.getGeneralMode() == "NL" || train.getGeneralMode() == "UN" || train.getGeneralMode() == "TR" || train.getGeneralMode() == "PT" || train.getGeneralMode() == "SN" ||
        train.getGeneralMode() == "RV"))
    {
        for (int i = 0; i <= 3; i++)
        {
            enable[i] = 0;
            boutons[i].settype("up_type");
        }
        if(boutons[0].getactivation() == 1)
            ecran = "languageWindow";
        else if(boutons[1].getactivation() == 1)
            ecran = "volumeWindow";
        else if(boutons[2].getactivation() == 1)
            ecran = "brightnessWindow";
        else if(boutons[3].getactivation() == 1)
            ecran = "systemVersionWindow";
    }
    else
    {
        for (int i = 0; i <= 3; i++)
            boutons[i].settype("delayed");
    }
    if(train.getVtrain() == 0 && train.getGeneralMode() == "SB" && vbc.size() < 20)
    {
        enable[4] = 0;
        boutons[4].settype("up_type");
    }
    else
        boutons[4].settype("delayed");
    if(train.getVtrain() == 0 && train.getGeneralMode() == "SB" && vbc.size() > 0)
    {
        enable[5] = 0;
        boutons[5].settype("up_type");
    }
    else
        boutons[5].settype("delayed");
    selection = {"Language", "Volume", "Brightness", "System version", "Set VBC", "Remote VBC"};
    menuWindows(selection, enable, fenetre, RE, symbol, arial, "Settings", ecart);
    close(ecran, boutons, numero);
}


void RBCcontactWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
    vector <string> selection(4);
    vector <int> enable(4);
    for (int i = 0; i <= 3; i++)
        enable[i] = 1;
    if(train.getVtrain() == 0 && train.getDriverID() && (train.getGeneralMode() == "SB" || train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" ||
		train.getGeneralMode() == "OS" || train.getGeneralMode() == "NL" || train.getGeneralMode() == "PT") && train.getETATLevelETCS() && (train.getLevelETCS() == "Level 2" ||
		train.getLevelETCS() == "Level 3"))
    {
         for (int i = 0; i <= 2 ; i++)
         {
            enable[i] = 0;
            boutons[i].settype("up_type");
          }
    }
    else
    {
        for (int i = 0; i <= 2; i++)
            boutons[i].settype("delayed");
    }
    if(train.getVtrain() == 0 && train.getDriverID() && (train.getGeneralMode() == "SB" || train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" ||
		train.getGeneralMode() == "OS" || train.getGeneralMode() == "NL" || train.getGeneralMode() == "PT" || train.getGeneralMode() == "UN" || train.getGeneralMode() == "SN") &&
		train.getETATLevelETCS())
    {
         enable[3] = 0;
         boutons[3].settype("up_type");
    }
    else
         boutons[3].settype("delayed");
    selection = {"Contact last RBC", "Use short number", "Enter RBC data", "Radio Network ID"};
    menuWindows(selection, enable, fenetre, RE, symbol, arial, "RBC contact", ecart);
    close(ecran, boutons, numero);
}

void dataEntryWindows(vector<vector<string>> input_field, RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, int complete, string title, vector<string> selection, int & sel,
	string keyboard, vector<Buttons> & boutons, string & ecran, donnees & train, int * ecart)
{
	for(int i = 0; i <= 9; i++)
		boutons[i].settype("down_type");
	if(keyboard == "numeric")
	{
		NA_21.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 / 2.0), RE, ecart, fenetre);			//H2
		boutons[10].settype("down_type");
		for(int i = 1; i <= 10; i++)
			creation_texte(RE, to_string(i % 10), arial, GREY, 16, 0, V2f(- 64 / 2.0 + i * 64, 430 + 50 / 2.0), fenetre, 1, ecart);
	}
	else if(keyboard == "enhanced numeric")
	{
		NA_21.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 / 2.0), RE, ecart, fenetre);			//H2
		creation_texte(RE, "1.  ", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 1 * 64, 430 + 50 / 2.0), fenetre, 3, ecart);
		for(int i = 2; i <= 10; i++)
			creation_texte(RE, to_string(i % 10), arial, GREY, 16, 0, V2f(- 64 / 2.0 + i * 64, 430 + 50 / 2.0), fenetre, 1, ecart);
	}
	else if(keyboard == "alphanumeric")
	{
		NA_21.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 / 2.0), RE, ecart, fenetre);			//H2
		creation_texte(RE, "1", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 1 * 64, 430 + 50 / 2.0), fenetre, 1, ecart);
		creation_texte(RE, "2abc", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 2 * 64, 430 + 50 / 2.0), fenetre, 3, ecart);
		creation_texte(RE, "3def", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 3 * 64, 430 + 50 / 2.0), fenetre, 3, ecart);
		creation_texte(RE, "4hij", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 4 * 64, 430 + 50 / 2.0), fenetre, 3, ecart);
		creation_texte(RE, "5klm", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 5 * 64, 430 + 50 / 2.0), fenetre, 3, ecart);
		creation_texte(RE, "6nop", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 6 * 64, 430 + 50 / 2.0), fenetre, 3, ecart);
		creation_texte(RE, "7qrs", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 7 * 64, 430 + 50 / 2.0), fenetre, 3, ecart);
		creation_texte(RE, "8tuv", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 8 * 64, 430 + 50 / 2.0), fenetre, 3, ecart);
		creation_texte(RE, "9wxyz", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 9 * 64, 430 + 50 / 2.0), fenetre, 3, ecart);
		creation_texte(RE, "0", arial, GREY, 16, 0, V2f(- 64 / 2.0 + 10 * 64, 430 + 50 / 2.0), fenetre, 1, ecart);
	}
	else if(keyboard == "dedicated keyboard")
    {
        for(int i = 1; i <= (int)selection.size(); i++)
            creation_texte(RE, to_string(i % 10), arial, GREY, 16, 0, V2f(- 64 / 2.0 + i * 64, 430 + 50 / 2.0), fenetre, 1, ecart);
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
		NA_11.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0), RE, ecart, fenetre);		//H3
		boutons[11].settype("up_type");
		close(ecran, boutons, sel);
	}
	else
	{
		NA_18.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0), RE, ecart, fenetre);		//H3
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
		NA_18_2.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2+ 64 / 2.0), RE, ecart, fenetre);	//H4
		boutons[12].settype("disabled");
	}
	else if((complete == 1 && input_field.size() > 4) || (complete == 0 && input_field.size() > 3))
	{
		boutons[12].settype("up_type");
		NA_17.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2+ 64 / 2.0), RE, ecart, fenetre);	//H4
		if(boutons[12].getactivation())
		{
			while(sel % 4 != 0)
				sel++;
			sel++;
		}
	}
	if(input_field.size() > 1)
	{
		NA_14.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 4 + 64 / 2.0), RE, ecart, fenetre);	//H6
		NA_13.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 3 + 64 / 2.0), RE, ecart, fenetre);	//H5
	}
	NA_20.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 5 + 41), RE, ecart, fenetre);		//H7
	if(complete)
	{
		rectangle(V2f(0, 380), V2f(334, 50), DARK_GREY, RE, fenetre, ecart);
		rectangle(V2f(0, 380), V2f(334 - 1, 50 - 1), WHITE, RE, fenetre, ecart);
		rectangle(V2f(0 + 1, 380 + 1), V2f(334 - 2, 50 - 2), MEDIUM_GREY, RE, fenetre, ecart);
		creation_texte(RE, "Yes", arial, BLACK, 12, 0, V2f(334 / 2.0, 380 + 25), fenetre, 1, ecart);
		creation_texte(RE, title + " entry complete ?", arial, GREY, 12, 0, V2f(334 / 2.0, 330 + 25), fenetre, 1, ecart);
		rectangle(V2f(0, 0), V2f(334, 24), BLACK, RE, fenetre, ecart);
		creation_texte(RE, title + sequenceNumber, arial, GREY, 12, 0, V2f(54 + 280 - 3, 12), fenetre, 2, ecart);
	}
	else
	{
		rectangle(V2f(54 + 280, 0), V2f(266, 24), BLACK, RE, fenetre, ecart);
		creation_texte(RE, title, arial, GREY, 12, 0, V2f(54 + 280 + 3, 12), fenetre, 4, ecart);
	}
	if(input_field.size() == 1)
	{
		rectangle(V2f(54 + 280, 50), V2f(266, 50), DARK_GREY, RE, fenetre, ecart);
		rectangle(V2f(54 + 280, 50), V2f(266 - 1, 50 - 1), WHITE, RE, fenetre, ecart);
		rectangle(V2f(54 + 280 + 1, 50 + 1), V2f(266 - 2, 50 - 2), MEDIUM_GREY, RE, fenetre, ecart);
		creation_texte(RE, input_field[0][1], arial, BLACK, 12, 0, V2f(54 + 280 + 10, 25 + 50), fenetre, 4, ecart);
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
			rectangle(V2f(54 + 280, 50 * (i - numero) + 50 * (1 - complete)), V2f(164, 50), MEDIUM_GREY, RE, fenetre, ecart);
			rectangle(V2f(54 + 280 + 1, 50 * (i - numero) + 1 + 50 * (1 - complete)), V2f(164 - 2, 50 - 2), BLACK, RE, fenetre, ecart);
			rectangle(V2f(54 + 280 + 1, 1 + 50 * (i - numero) + 50 * (1 - complete)), V2f(164 - 2, 50 - 2), DARK_GREY, RE, fenetre, ecart);
			if(i == sel - 1)
			{
				rectangle(V2f(54 + 280 + 164, 50 * (i - numero) + 50 * (1 - complete)), V2f(102, 50), DARK_GREY, RE, fenetre, ecart);
				rectangle(V2f(54 + 280 + 164, 50 * (i - numero) + 50 * (1 - complete)), V2f(102 - 1, 50 - 1), WHITE, RE, fenetre, ecart);
				rectangle(V2f(54 + 280 + 164 + 1, 50 * (i - numero) + 1 + 50 * (1 - complete)), V2f(102 - 2, 50 - 2), MEDIUM_GREY, RE, fenetre, ecart);
			}
			else
			{
				rectangle(V2f(54 + 280 + 164, 50 * (i - numero) + 50 * (1 - complete)), V2f(102, 50), MEDIUM_GREY, RE, fenetre, ecart);
				rectangle(V2f(54 + 280 + 164 + 1, 50 * (i - numero) + 1 + 50 * (1 - complete)), V2f(102 - 2, 50 - 2), BLACK, RE, fenetre, ecart);
				rectangle(V2f(54 + 280 + 164 + 1, 1 + 50 * (i - numero) + 50 * (1 - complete)), V2f(102 - 2, 50 - 2), DARK_GREY, RE, fenetre, ecart);
			}
			creation_texte(RE, input_field[i][0], arial, GREY, 12, 0, V2f(54 + 280 + 10, 50 * (i - numero) + 25 + 50 * (1 - complete)), fenetre, 4, ecart);
			if(i == sel - 1)
			{	if(train.getClignotementTexte()/30 <= 1)
				{
					creation_texte(RE, input_field[i][1], arial, BLACK, 12, 0, V2f(54 + 280 + 164 + 10, 50 * (i - numero) + 25 + 50 * (1 - complete)), fenetre, 4, ecart);
					train.setClignotementTexte(train.getClignotementTexte() + 1);
				}
				else if (train.getClignotementTexte()/30 <= 2)
				{
					creation_texte(RE, input_field[i][1] + "_", arial, BLACK, 12, 0, V2f(54 + 280 + 164 + 10, 50 * (i - numero) + 25 + 50 * (1 - complete)), fenetre, 4, ecart);
					train.setClignotementTexte(train.getClignotementTexte() + 1);
				}
				else
					train.setClignotementTexte(0);
			}
			else if(input_field[i][2] == "1")
				creation_texte(RE, input_field[i][1], arial, WHITE, 12, 0, V2f(54 + 280 + 164 + 10, 50 * (i - numero) + 25 + 50 * (1 - complete)), fenetre, 4, ecart);
			else
				creation_texte(RE, input_field[i][1], arial, GREY, 12, 0, V2f(54 + 280 + 164 + 10, 50 * (i - numero) + 25 + 50 * (1 - complete)), fenetre, 4, ecart);
		}
	}
	for(int i = 0; i < (int)selection.size(); i++)
		creation_texte(RE, to_string(i + 1) + " - " + selection[i], arial, GREY, 12, 0, V2f(54 + 280 + 15, 200 + 15 + 6 + i * 20), fenetre, 4, ecart);
}

void trainRunningNumberWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
	dataEntryWindows({{"", "", "0"}}, fenetre, RE, symbol, arial, 0, "Train running number", {}, numero, "numeric", boutons, ecran, train, ecart);
}

void ERTMS_ETCSlevelWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
	dataEntryWindows({{"", train.getLevelETCS(), ""}}, fenetre, RE, symbol, arial, 0, "Level", {"Level 1", "Level 2", "Level 3", "Level 0"}, numero, "dedicated keyboard", boutons, ecran, train, ecart);
	if(boutons[0].getactivation())
		train.setLevelETCS("Level 1");
	else if(boutons[1].getactivation())
		train.setLevelETCS("Level 2");
	else if(boutons[2].getactivation())
		train.setLevelETCS("Level 3");
	else if(boutons[3].getactivation())
		train.setLevelETCS("Level 0");
}

void driverIDWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
    if(boutons[0].getactivation())
		train.train_Data.setTempDriver_ID(train.train_Data.getTempDriver_ID() * 10 + 1);
    else if(boutons[1].getactivation())
        train.train_Data.setTempDriver_ID(train.train_Data.getTempDriver_ID()  * 10 + 2);
    else if(boutons[2].getactivation())
        train.train_Data.setTempDriver_ID(train.train_Data.getTempDriver_ID() * 10 + 3);
    else if(boutons[3].getactivation())
        train.train_Data.setTempDriver_ID(train.train_Data.getTempDriver_ID()  * 10 + 4);
    else if(boutons[4].getactivation())
        train.train_Data.setTempDriver_ID(train.train_Data.getTempDriver_ID() * 10 + 5) ;
    else if(boutons[5].getactivation())
        train.train_Data.setTempDriver_ID(train.train_Data.getTempDriver_ID() * 10 + 6);
    else if(boutons[6].getactivation())
        train.train_Data.setTempDriver_ID(train.train_Data.getTempDriver_ID()  * 10 + 7);
    else if(boutons[7].getactivation())
        train.train_Data.setTempDriver_ID(train.train_Data.getTempDriver_ID()  * 10 + 8);
    else if(boutons[8].getactivation())
        train.train_Data.setTempDriver_ID(train.train_Data.getTempDriver_ID()  * 10 + 9);
    else if(boutons[9].getactivation())
        train.train_Data.setTempDriver_ID(train.train_Data.getTempDriver_ID()  * 10 + 0);
    else if(boutons[10].getactivation())
        train.train_Data.setTempDriver_ID(ceil(train.train_Data.getTempDriver_ID() /10));
    else if(boutons[12].getactivation())
        train.train_Data.setTempDriver_ID(train.train_Data.getDriver_ID());
    else if(boutons[15].getactivation())
    {
        train.train_Data.setDriver_ID(train.train_Data.getTempDriver_ID());
        dataEntryWindows({{"", to_string(train.train_Data.getDriver_ID()), "1"}}, fenetre, RE, symbol, arial, 0, "Driver ID", {}, numero, "alphanumeric", boutons, ecran, train, ecart);
    }
	//if(train.train_Data.getTempDriver_ID() == 0)
	//	dataEntryWindows({{"", "", "0"}}, fenetre, RE, symbol, arial, 0, "Driver ID", {}, numero, "alphanumeric", boutons, ecran, train);
	//else
	dataEntryWindows({{"", to_string(train.train_Data.getTempDriver_ID()), "0"}}, fenetre, RE, symbol, arial, 0, "Driver ID", {}, numero, "alphanumeric", boutons, ecran, train, ecart);
}

void radionetworkIDWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
	dataEntryWindows({{"", train.getRadioNetworkID(), "0"}}, fenetre, RE, symbol, arial, 0, "Radio network ID", {}, numero, "dedicated keyboard", boutons, ecran, train, ecart);
	if(boutons[0].getactivation())
		train.setRadioNetworkID("GSMR-A");
	else if(boutons[1].getactivation())
		train.setRadioNetworkID("GSMR-B");
	else if(boutons[1].getactivation())
		train.setRadioNetworkID("Telecom X");
}

void RBCdataWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
    int i = 0;
    if(numero == 1)
    {
        if(boutons[0].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 1);
        else if(boutons[1].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 2);
        else if(boutons[2].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 3);
        else if(boutons[3].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 4);
        else if(boutons[4].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 5);
        else if(boutons[5].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 6);
        else if(boutons[6].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 7);
        else if(boutons[7].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 8);
        else if(boutons[8].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 9);
        else if(boutons[9].getactivation())
            train.setTempRBCID(train.getTempRBCID() * 10 + 0);
        else if(boutons[10].getactivation())
            train.setTempRBCID(ceil(train.getTempRBCID()/10));
        else if (boutons[13].getactivation() || boutons[14].getactivation() || boutons[12].getactivation())
        {
            train.setTempRBCID(train.getRBCID());
            i = 1;
            dataEntryWindows({{"RBC ID", to_string(train.getRBCID()), "0"}, {"RBC phone number", to_string(train.getRBCphoneNumber()), "0"}}, fenetre, RE, symbol, arial, 1, "RBC data", {}, numero,
				"numeric", boutons, ecran, train, ecart);
        }
        else if(boutons[15].getactivation())
        {
            train.setRBCID(train.getTempRBCID());
            numero++;
            i = 1;
            dataEntryWindows({{"RBC ID", to_string(train.getRBCID()), "1"}, {"RBC phone number", to_string(train.getRBCphoneNumber()), "0"}}, fenetre, RE, symbol, arial, 1, "RBC data", {},
				numero, "numeric", boutons, ecran, train, ecart);
        }
        if(i ==0)
		{
			if(train.getTempRBCID() == 0)
				dataEntryWindows({{"RBC ID", "", "0"}, {"RBC phone number", to_string(train.getRBCphoneNumber()), "0"}}, fenetre, RE, symbol, arial, 1, "RBC data", {}, numero, "numeric", boutons,
					ecran, train, ecart);
			else
				dataEntryWindows({{"RBC ID", to_string(train.getTempRBCID()), "0"}, {"RBC phone number", to_string(train.getRBCphoneNumber()), "0"}}, fenetre, RE, symbol, arial, 1, "RBC data", {},
					numero, "numeric", boutons, ecran, train, ecart);
		}
    }
    else
    {
        if(boutons[0].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 1);
        else if(boutons[1].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 2);
        else if(boutons[2].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 3);
        else if(boutons[3].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 4);
        else if(boutons[4].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 5);
        else if(boutons[5].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 6);
        else if(boutons[6].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 7);
        else if(boutons[7].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 8);
        else if(boutons[8].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 9);
        else if(boutons[9].getactivation())
            train.setTempRBCphoneNumber(train.getTempRBCphoneNumber() * 10 + 0);
        else if(boutons[10].getactivation())
            train.setTempRBCphoneNumber(ceil(train.getTempRBCphoneNumber()/10));
        else if (boutons[13].getactivation() || boutons[14].getactivation() || boutons[14].getactivation())
        {
            train.setTempRBCphoneNumber(train.getRBCphoneNumber());
            i = 1;
            dataEntryWindows({{"RBC ID", to_string(train.getRBCID()), "0"}, {"RBC phone number", to_string(train.getRBCphoneNumber()), "0"}}, fenetre, RE, symbol, arial, 1, "RBC data", {}, numero,
				"numeric", boutons, ecran, train, ecart);
        }
        else if(boutons[15].getactivation())
        {
            train.setRBCphoneNumber(train.getTempRBCphoneNumber());
            numero--;
            i = 1;
            dataEntryWindows({{"RBC ID", to_string(train.getRBCID()), "1"}, {"RBC phone number", to_string(train.getRBCphoneNumber()), "0"}}, fenetre, RE, symbol, arial, 1, "RBC data", {},
				numero, "numeric", boutons, ecran, train, ecart);
        }

       if(i ==0)
		{
			if(train.getTempRBCphoneNumber() == 0)
				dataEntryWindows({{"RBC ID", to_string(train.getRBCID()), "0"}, {"RBC phone number", "", "0"}}, fenetre, RE, symbol, arial, 1, "RBC data", {}, numero, "numeric", boutons, ecran, train, ecart);
			else
				dataEntryWindows({{"RBC ID", to_string(train.getRBCID()), "0"}, {"RBC phone number", to_string(train.getTempRBCphoneNumber()), "0"}}, fenetre, RE, symbol, arial, 1, "RBC data", {},

					numero, "numeric", boutons, ecran, train, ecart);
		}
	}
}


void languageWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
	dataEntryWindows({{"", train.getLanguage(), "0"}}, fenetre, RE, symbol, arial, 0, "Language", {"English", "Francais"}, numero, "dedicated keyboard", boutons, ecran, train, ecart);
	if(boutons[0].getactivation())
		train.setLanguage("English");
	else if(boutons[1].getactivation())
		train.setLanguage("Francais");
}

void volumeWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
	dataEntryWindows({{""}}, fenetre, RE, symbol, arial, 0, "Volume", {}, numero, "", boutons, ecran, train, ecart);
}

void brightnessWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
	dataEntryWindows({{""}}, fenetre, RE, symbol, arial, 0, "Brightness", {}, numero, "", boutons, ecran, train, ecart);
}

void trainDataWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
	vector<vector<string>> input_field = {{"Train category", train.train_Data.getTrain_category(), "0"}, {"Length (m)", to_string(train.train_Data.getlength()), "1"}, {"Brake percentage",
		to_string(train.train_Data.getbreaking_percetage()), "0"}, {"Max speed (km/h)", to_string(train.train_Data.getmaximum_train_speed()), "0"}, {"Axle load category",
		train.train_Data.getaxle_load_category(), "0"}, {"Airtight", train.train_Data.getAirtight(), "0"}, {"Loading gauge", train.train_Data.getloading_gauge(), "0"}};
	vector <string> selection = {};
	string keyboard = "";
	//if(numero == 1)
	//
	//if(numero == 2)
	//
	//if(numero == 3)
	//
	//if(numero == 4)
	//
	//if(numero == 5)
	//
	//if(numero == 6)
	//
	//if(numero == 7)
	//
	dataEntryWindows(input_field, fenetre, RE, symbol, arial, 1, "Train data", selection, numero, keyboard, boutons, ecran, train, ecart);
	for(int i = 0; i < int(input_field.size()); i++)
		creation_texte(RE, input_field[i][0], arial, GREY, 12, 0, V2f(204 - 5, 20 * i + 100 + 6), fenetre, 2, ecart);
}

void SRspeedWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
    dataEntryWindows({{"SR speed (km/h)", to_string(train.getSRspeed()), "0"}, {"SR distance (m)", "b", "0"}}, fenetre, RE, symbol, arial, 0, "SR speed/distance", {}, numero, "numeric", boutons,
		ecran, train, ecart);
	if(boutons[0].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 1);
	else if(boutons[1].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 2);
	else if(boutons[2].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 3);
	else if(boutons[3].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 4);
	else if(boutons[4].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 5);
	else if(boutons[5].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 6);
	else if(boutons[6].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 7);
	else if(boutons[7].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 8);
	else if(boutons[8].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 9);
	else if(boutons[9].getactivation())
		train.setSRspeed(train.getSRspeed() * 10 + 0);
}

void adhesionWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
	dataEntryWindows({{"", train.getAdhesion(),"0"}}, fenetre, RE, symbol, arial, 0, "Adhesion", {"Non slippery rail","Slippery rail"}, numero, "dedicated keyboard", boutons, ecran, train, ecart);
	if(boutons[0].getactivation())
		train.setAdhesion("Non slippery rail");
	else if(boutons[1].getactivation())
		train.setAdhesion("Slippery rail");
}

void dataViewWindows(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string title, int & numero, vector<Buttons> & boutons, string & ecran, vector<vector<string>> item, int * ecart)
{
	rectangle(V2f(54 + 280, 0), V2f(266, 24), BLACK, RE, fenetre, ecart);
	if(title == "Data View")
		title += " (" + to_string(numero) + "/2)";
	creation_texte(RE, title, arial, GREY, 17, 0, V2f(54 + 280 + 3, 12), fenetre, 4, ecart);
	for(int i = 0; i <= int(item.size()) - 1; i++)
	{
		creation_texte(RE, item[i][0], arial, GREY, 17, 0, V2f(280 + 54 + 176 - 5, 60 + 17 / 2.0 + i * 22), fenetre, 2, ecart);
		creation_texte(RE, item[i][1], arial, GREY, 17, 0, V2f(280 + 54 + 176 + 5, 60 + 17 / 2.0 + i * 22), fenetre, 4, ecart);
	}
	if(numero == 1)
	{
		NA_11.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0), RE, ecart, fenetre);		//H3
		boutons[11].settype("up_type");
		close(ecran, boutons, numero);
	}
	else if(numero == 2)
	{
		NA_18.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0), RE, ecart, fenetre);		//H3
		boutons[11].settype("up_type");
		if(boutons[11].getactivation())
			numero--;
	}
	if(numero == 2)
	{
		NA_18_2.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2+ 64 / 2.0), RE, ecart, fenetre);	//H4
		boutons[12].settype("disabled");
	}
	else if(numero == 1)
	{
		boutons[12].settype("up_type");
		NA_17.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2+ 64 / 2.0), RE, ecart, fenetre);	//H4
		if(boutons[12].getactivation())
			numero++;
	}
}

void dataViewWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
    vector<vector<string>> item;
    if(numero == 1)
    	item = {{"Driver ID", to_string(train.train_Data.getDriver_ID())}, {"", ""},{"Train running number", to_string(train.train_Data.getTrain_running_number()) },
			{"", ""}, {"Train type", train.train_Data.getTrain_type()}, {"Train category", train.train_Data.getTrain_category()}, {"Length (m)", to_string(train.train_Data.getlength())},
			{"Brake percentage", to_string(train.train_Data.getbreaking_percetage())}, {"Max speed (km/h)", to_string(train.train_Data.getmaximum_train_speed())},
			{"Axle load category", train.train_Data.getaxle_load_category()}, {"Airtight", train.train_Data.getAirtight()}, {"Loading gauge", train.train_Data.getloading_gauge()}};
    else
    	item = {{"Radio network ID", train.getRadioNetworkID()}, {"RBC ID", to_string(train.getRBCID())}, {"RBC phone number", to_string(train.getRBCphoneNumber())}, {"", ""},
		{"VBC #1 set code", "d"}, {"VBC #2 set code", "e"}};
    dataViewWindows(fenetre, RE, symbol, arial, "Data View", numero, boutons, ecran, item, ecart);
}

void systemVersionWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart)
{
	vector<vector<string>> item = {{"Operated system version", ""}};
	dataViewWindows(fenetre, RE, symbol, arial, "System version", numero, boutons, ecran, item, ecart);
}


void windows(string & ecran, RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string version, donnees &train, vector<VBC> vbc, vector<Buttons> & boutons, int & numero, int * ecart)
{
    if(ecran == "mainWindow")
        mainWindow(fenetre, RE, symbol, arial, version, train, boutons, ecran, numero, ecart);
    else if(ecran == "overrideWindow")
        overrideWindow(fenetre, RE, symbol, arial, version, train, boutons, ecran, numero, ecart);
    else if(ecran == "specialWindow")
        specialWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "settingsWindow")
        settingsWindow(fenetre, RE, symbol, arial, train, vbc, boutons, ecran, numero, ecart);
    else if(ecran == "RBCcontactWindow")
        RBCcontactWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "trainRunningNumberWindow")
        trainRunningNumberWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "ERTMS_ETCSlevelWindow")
        ERTMS_ETCSlevelWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "driverIDWindow")
        driverIDWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "radionetworkIDWindow")
        radionetworkIDWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "RBCdataWindow")
        RBCdataWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "languageWindow")
        languageWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "volumeWindow")
        volumeWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "brightnessWindow")
        brightnessWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "SRspeed/distanceWindow")
        SRspeedWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "adhesionWindow")
        adhesionWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "trainDataWindow")
        trainDataWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "dataViewWindow")
        dataViewWindow(fenetre, RE, symbol, arial, train, boutons, ecran, numero, ecart);
    else if(ecran == "systemVersionWindow")
        systemVersionWindow(fenetre, RE, symbol, arial, boutons, ecran, numero, ecart);
}


void close(string & ecran, vector<Buttons> & boutons, int & numero)
{
    if(boutons[11].getactivation())
        numero = 1;
    if(boutons[11].getactivation() && (ecran == "mainWindow" || ecran == "overrideWindow" || ecran == "specialWindow" || ecran == "settingsWindow"|| ecran == "dataViewWindow"))
        ecran = "defaultWindow";
    else if(boutons[11].getactivation()&& (ecran == "languageWindow" || ecran == "volumeWindow" || ecran == "brightnessWindow"))
        ecran = "settingsWindow";
    else if(boutons[11].getactivation()&& (ecran == "driverIDWindow" || ecran == "trainDataWindow" || ecran == "trainRunningNumberWindow" || ecran == "RBCdataWindow" ||
		ecran == "ERTMS_ETCSlevelWindow"))
        {
            ecran = "mainWindow";
            boutons[3].settype("disabled");
			boutons[10].settype("disabled");
			boutons[12].settype("disabled");
			boutons[13].settype("disabled");
			boutons[14].settype("disabled");
			boutons[15].settype("disabled");
        }
    else if(boutons[11].getactivation()&& (ecran == "adhesionWindow" || ecran == "SRspeed/distanceWindow"))
        ecran = "specialWindow";
}



