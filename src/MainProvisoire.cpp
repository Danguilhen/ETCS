#include <cstdlib>
#include <iostream>
#include <thread>
#include <math.h>
#include <string>
#include <ctime>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include <string>

class Donnees
{
	V2f m_cartesiens;
	V2f m_polaire;
    float m_vitesse;
};

void demarage(RenderWindow & fenetre);
void fondEcran(RenderWindow & fenetre, double RE, int * ecart);

int main()
{
	Clock chrono;//d�but d�mo (delta_t = 0)
	Time difftemps;
	donnees train;
	DonneesAfficheurVitesse graduations[401];
	ConvexShape aiguille;	// Creation des formes de l'aiguille de l'IV
	V2f centreIV;						// Position du centre de l'indicateur de Vitesse
	double RE;
	int ecart[] = {0, 0};
	vector<Symbol> symbol(154);
	string version;
	string TTI = "On";
	int LSSMA = 120;
	int speedRange = 400;
	string ecran = "defaultWindow";
	vector<VBC> vbc(20);

	int numero = 1;
	int temp_TTI = 0;
	int version_test;

	///////////////////////////////////////////////
	Planning planning;

	///////////////////////////////////////////////////////////////////////////////////////////////
	string choix;
	do
	{
		cout << "MERCI DE RENTRER LA VERSION A = 3.6.0 B = 3.4.0"<<endl;
		cin >> choix;
		cout << choix << endl;
	}while(choix !="A" && choix !="B" && choix != "C" && choix != "D");
	if(choix == "A" || choix == "C")
		version = "3.6.0";
	if(choix == "B" || choix == "D")
		version = "3.4.0";
	if(choix == "C" || choix == "D")
	{
		version_test = 1;
		train.mode_test();
	}
	else
	version_test = 0;
	///////////////////////////////////////////////////////////////////////////////////////////////


	CircleShape SSI(10 / 2.0 * RE);
	SSI.setFillColor(WHITE);


	//clockMoteurIsole.restart();

    //affiche la fenetre tant que l'utilisateur n'appuie pas sur la croix
    while(fenetre.isOpen())
    {



        difftemps = chrono.getElapsedTime();
        chrono.restart();
        float delta_ts=difftemps.asSeconds();
        if((train.getVtrain() > 160 || train.getVtrain() == - 1) && version_test != 1)
        {
			demo(train);
        	calcul(delta_ts,train);
		}
        if(train.getVtrain() < 160 && version_test != 1)
        {
			demo2(train);
        	calcul(delta_ts,train);
		}

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
				train.setTTI((train.getDEOA() - (3 / 5.0)*train.getD_but())/(train.getVtrain()/3.6)); // TEMPORAIRE POUR LA DEMO
				//Rappel TTIdisp est à 14 s selon la subset026
				if((train.getGeneralMode() == "FS" || ((train.getGeneralMode() == "OS" || train.getGeneralMode() == "SR") && TTI == "On")) && (train.getMode() == "CSM" || train.getMode() == "PIM") && train.getTTI() < 14)  //A1 : TTI
				{
					if(temp_TTI == 0)
					{
						son.jouer_alarmes(2, 1);
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

			if(train.getLevel() == "Level 0")
                LE_01.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 + 25 / 2.0), RE, ecart, fenetre);
            else if(train.getLevel()  == "Level 1")
                LE_03.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 + 25 / 2.0), RE, ecart, fenetre);
            else if(train.getLevel()  == "Level 2")
                LE_04.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 + 25 / 2.0), RE, ecart, fenetre);
            else if(train.getLevel()  == "Level 3")
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
							planning.planningInformation(fenetre, RE, arial, symbol, train, ecart, delta_ts);
					}
					if(version == "3.6.0" && (train.getGeneralMode() == "FS" || (train.getGeneralMode() == "OS" && train.getS_D_monitoring() == "On")))
					{
						planning.planningInformation(fenetre, RE, arial, symbol, train, ecart, delta_ts);
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
				TexteMessages(fenetre, RE, arial, ecart);//special class texte

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
	int position = VideoMode::getDesktopMode().width / 2 - texte.width / 2;
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

//Prototypes -----------------------------------------------------------------------------------------------------------------------------
void affichageRectangle(string ecran);


//Brouillon ------------------------------------------------------------------------------------------------------------------------------

void affichageRectangle(string ecran)		//Affiche toutes les cases sur l'\E9cran
{
	if(ecran == "defaultWindow")
	{
		creation_rectangle(V2f((54 + 234 + 46), (54 + 30 + 191 + 25 + 50 + 50)), V2f(63, 30), 1);			//G11
		creation_rectangle(V2f((54 + 234 + 46 + 63), (54 + 30 + 191 + 25 + 50 + 50)), V2f(120, 30), 1);		//G12
		creation_rectangle(V2f((54 + 234 + 46 + 63 + 120), (54 + 30 + 191 + 25 + 2 * 50)), V2f(63, 30), 1);	//G13
	}
	creation_rectangle(V2f(0, 0), V2f(54, 54), 1);															//A1
	creation_rectangle(V2f(0, 54), V2f(54, (191 + 30)), 1);													//A2-3
	creation_rectangle(V2f(0, (54 +30 + 191)), V2f(54, 25), 1);												//A4
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25)), V2f(54, 25), 1);										//C8
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 2)), V2f(54, 25), 1);									//C9
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 3)), V2f(54, 25), 1);									//E1
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 4)), V2f(54, 25), 1);									//E2
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 5)), V2f(54, 25), 1);									//E3
	creation_rectangle(V2f((54 + 26 - 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), 1);						//B6
	creation_rectangle(V2f((54 + 140 + 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), 1);						//B5
	creation_rectangle(V2f((54 + 140 - 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), 1);						//B4
	creation_rectangle(V2f((54 + 140 - 36 * 3 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), 1);					//B3
	creation_rectangle(V2f((54 + 254 - 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), 1);						//B7
	creation_rectangle(V2f((54 + 3 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 1);							//C1
	creation_rectangle(V2f(54, 0), V2f(280, 300), 1);														//B
	creation_rectangle(V2f(54, (54 + 30 + 191 + 25 + 50)), V2f(234, 4 * 20), 1);							//E5-6-7-8
	creation_rectangle(V2f((54 + 234), (54 + 30 + 191 + 25 + 50)), V2f(46, 40), 2);							//E10
	creation_rectangle(V2f((54 + 234), (54 + 30 + 191 + 25 + 50 + 40)), V2f(46, 40), 2);					//E11
	creation_rectangle(V2f(62, 257), V2f(36, 36), 1); //B6
	creation_rectangle(V2f(140, 257), V2f(36, 36), 1); //B3
	creation_rectangle(V2f(177, 257), V2f(36, 36), 1); //B4
	creation_rectangle(V2f(212, 257), V2f(36, 36), 1); //B5
	creation_rectangle(V2f(289, 257), V2f(36, 36), 1); //B7
}

// Reste cadran ------------------------------------------------------------------------------------------------------------



class DonneesAfficheurVitesse
{
    public:

	DonneesAfficheurVitesse();
	DonneesAfficheurVitesse(Vector2f cartesiens, Vector2f polaire, int vitesse);

	/////////////////////////////////////////////////////////////
	//definition des methodes
	/////////////////////////////////////////////////////////////

	//definition des get
	void cartesiens(Vector2f cartesiens);
	void polaire(Vector2f polaire);
	void x(int x);
	void y(int y);
	void r(int r);
	void teta(int teta);
	void vitesse(int vitesse);

	/////////////////////////////////////////////////////////////
	//definition des set

	Vector2f cartesien();
	Vector2f polaire();
	float x();
	float y();
	float r();
	float teta();
	int vitesse();

    private:

	Vector2f m_cartesiens;
	Vector2f m_polaire;
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

// Brouillon --------------------------------------------------------------------------------------------------------------------------

void positionnementAiguille(ConvexShape aiguille, float vitesse, DonneesAfficheurVitesse graduations[]);

void positionnementAiguille(ConvexShape aiguille,float vitesse, DonneesAfficheurVitesse graduations[])
{
	float teta0 = 90 - 144;
	float kmh2degVfaible = 144.0 / 150.0;  //nombre de degre pour 1km/h ici a 144� on a 150km/h
	float kmh2degVeleve = kmh2degVfaible / 2.0;

	if (vitesse < 200)
		aiguille.setRotation(vitesse * kmh2degVfaible+teta0);
	else
		aiguille.setRotation(200 * kmh2degVfaible / 2.0 + vitesse * kmh2degVeleve+teta0);

	fenetre.draw(aiguille);

	string str = to_string(graduations[(int)vitesse].vitesse());
	string s;
	if(graduations[(int)vitesse].vitesse() > 99)
	{
		s = str.at(2);
		creation_texte(s, arial, BLACK, 18, 0, V2f(54 + 280 / 2.0 + 50 / 2.0 - 3, 300 / 2.0), 2);
		s = str.at(1);
		creation_texte(s, arial, BLACK, 18, 0, V2f(54 + 280 / 2.0 + 50 / 6.0 - 3, 300 / 2.0), 2);
		s = str.at(0);
		creation_texte(s, arial, BLACK, 18, 0, V2f(54 + 280 / 2.0 - 50 / 6.0 - 3, 300 / 2.0), 2);
	}
	else if(graduations[(int)vitesse].vitesse() > 9)
	{
		s = str.at(1);
		creation_texte(s, arial, BLACK, 18, 0, V2f(54 + 280 / 2.0 + 50 / 3.0, 300 / 2.0), 1);
		s = str.at(0);
		creation_texte(s, arial, BLACK, 18, 0, V2f(54 + 280 / 2.0, 300 / 2.0), 1);
	}
	else
	{
		s = str.at(0);
		creation_texte(RE, s, arial, BLACK, 18, 0, V2f(54 + 280 / 2.0 + 50 / 3.0, 300 / 2.0), 1);
	}
}

void indicateurVitesse(V2f centre, Color couleurAiguille, double RE, RenderWindow & fenetre, Font & arial, DonneesAfficheurVitesse graduations[], int Vmax, int * ecart);