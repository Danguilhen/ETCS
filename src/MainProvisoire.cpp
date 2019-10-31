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

// Reste fenetre ------------------------------------------------------------------------------------------------------------



void MainWindow(vector<Symbol> & symbol, string version, vector<Buttons> & boutons, string & ecran, int & numero);
void specialWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void settingsWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<VBC> & vbc, vector<Buttons> & boutons, string & ecran, int & numero);
void SRspeedWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void dataViewWindows(vector<Symbol> & symbol, Font & arial, string title, int & numero, vector<Buttons> & boutons, string & ecran, vector<vector<string>> item);
void RBCdataWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void dataViewWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void systemVersionWindow(vector<Symbol> & symbol, Font & arial, vector<Buttons> & boutons, string & ecran, int & numero);

void overrideWindow(vector<Symbol> & symbol, Font & arial, string version, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void adhesionWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void RBCcontactWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void ERTMS_ETCSlevelWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void trainRunningNumberWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void radionetworkIDWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void trainDataWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void brightnessWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void volumeWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void languageWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);
void windows(string & ecran, vector<Symbol> & symbol, Font & arial, string version, donnees &train, vector<VBC> vbc, vector<Buttons> & boutons, int & numero);
void close(string & ecran, vector<Buttons> & boutons, int & numero);
void driverIDWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero);



void MainWindow(vector<Symbol> & symbol, Font & arial, string version, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
    vector <string> selection(9);
    vector <int> enable(9);
    for (int i = 0; i <= 9; i++)
        enable[i] = 1;
    enable[3] = 2;
	if((train.getVtrain() == 0 && train.getGeneralMode() == "SB" && train.getDriverID() && train.getTrainData() && train.getETATLevelETCS() && train.getTrainNumber()) ||
		((train.getVtrain() == 0 && train.getGeneralMode() == "PT" && train.getTrainData()) && (train.getLevel() == "Level 1" || ((train.getLevel() == "Level 2" ||
		train.getLevel() == "Level 3") && train.getConnection() == "Up" && version == "3.6.0" && train.getPending_Emergency_Stop() == false))) || ((train.getVtrain() == 0 &&
		train.getGeneralMode() == "PT" && train.getTrainData()) && (train.getLevel() == "Level 1" || ((train.getLevel() == "Level 2" || train.getLevel() == "Level 3") &&
		version == "3.4.0" && train.getPending_Emergency_Stop() == false))) || (train.getGeneralMode() == "SR" && (train.getLevel() == "Level 2" || train.getLevel() == "Level 3") &&
		train.getConnection() == "Up" && version == "3.6.0") || (train.getGeneralMode() == "SR" && (train.getLevel() == "Level 2" || train.getLevel() == "Level 3") && version == "3.4.0"))
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
		train.getGeneralMode() == "OS" || train.getGeneralMode() == "UN" || train.getGeneralMode() == "SN" ) && train.getETATLevelETCS() && ((train.getLevel() == "Level 0" ||
		train.getLevel() == "Level 1" || train.getLevel().substr(0,2) == "NTC") || ((train.getLevel() == "Level 2" || train.getLevel() == "Level 3") &&
		train.getConnection() == "Up"))) || (train.getVtrain() == 0 && train.getGeneralMode() == "PT" && (train.getLevel() == "Level 1" || ((train.getLevel() == "Level 2" ||
		train.getLevel() == "Level 3") && train.getConnection() == "Up" && train.getPending_Emergency_Stop() == false))))
	{
		enable[6] = 0; //shunting  x
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


void overrideWindow(vector<Symbol> & symbol, Font & arial, string version, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
    vector <string> selection(1);
    vector <int> enable(1);
    enable[0] = 1;
    if ((train.getVtrain() <=  train.getVrelease() && (train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" || train.getGeneralMode() == "OS"||
        train.getGeneralMode() == "UN" || train.getGeneralMode() == "SN" || train.getGeneralMode() == "SH"))
        || (train.getVtrain() <=  train.getVrelease() && train.getGeneralMode() == "SB" && train.getDriverID() && train.getTrainData() && train.getETATLevelETCS() &&
		(train.getLevel() == "Level 2" || train.getLevel() == "Level 3")) || (version =="3.6.0" && (train.getVtrain() <=  train.getVrelease() && train.getGeneralMode() == "PT" &&
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

void specialWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero)
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

void settingsWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<VBC> & vbc, vector<Buttons> & boutons, string & ecran, int & numero)
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


void RBCcontactWindow(vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero)
{
    vector <string> selection(4);
    vector <int> enable(4);
    for (int i = 0; i <= 3; i++)
        enable[i] = 1;
    if(train.getVtrain() == 0 && train.getDriverID() && (train.getGeneralMode() == "SB" || train.getGeneralMode() == "FS" || train.getGeneralMode() == "LS" || train.getGeneralMode() == "SR" ||
		train.getGeneralMode() == "OS" || train.getGeneralMode() == "NL" || train.getGeneralMode() == "PT") && train.getETATLevelETCS() && (train.getLevel() == "Level 2" ||
		train.getLevel() == "Level 3"))
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

void trainRunningNumberWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
	dataEntryWindows({{"", "", "0"}}, fenetre, RE, symbol, arial, 0, "Train running number", {}, numero, "numeric", boutons, ecran, train, ecart);
}

void ERTMS_ETCSlevelWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
	dataEntryWindows({{"", train.getLevel(), ""}}, fenetre, RE, symbol, arial, 0, "Level", {"Level 1", "Level 2", "Level 3", "Level 0"}, numero, "dedicated keyboard", boutons, ecran, train, ecart);
	if(boutons[0].getactivation())
		train.setLevelETCS("Level 1");
	else if(boutons[1].getactivation())
		train.setLevelETCS("Level 2");
	else if(boutons[2].getactivation())
		train.setLevelETCS("Level 3");
	else if(boutons[3].getactivation())
		train.setLevelETCS("Level 0");
}

void driverIDWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
    if(boutons[0].getactivation())
		train.setTempDriver_ID(train.getTempDriver_ID() * 10 + 1);
    else if(boutons[1].getactivation())
        train.setTempDriver_ID(train.getTempDriver_ID()  * 10 + 2);
    else if(boutons[2].getactivation())
        train.setTempDriver_ID(train.getTempDriver_ID() * 10 + 3);
    else if(boutons[3].getactivation())
        train.setTempDriver_ID(train.getTempDriver_ID()  * 10 + 4);
    else if(boutons[4].getactivation())
        train.setTempDriver_ID(train.getTempDriver_ID() * 10 + 5) ;
    else if(boutons[5].getactivation())
        train.setTempDriver_ID(train.getTempDriver_ID() * 10 + 6);
    else if(boutons[6].getactivation())
        train.setTempDriver_ID(train.getTempDriver_ID()  * 10 + 7);
    else if(boutons[7].getactivation())
        train.setTempDriver_ID(train.getTempDriver_ID()  * 10 + 8);
    else if(boutons[8].getactivation())
        train.setTempDriver_ID(train.getTempDriver_ID()  * 10 + 9);
    else if(boutons[9].getactivation())
        train.setTempDriver_ID(train.getTempDriver_ID()  * 10 + 0);
    else if(boutons[10].getactivation())
        train.setTempDriver_ID(ceil(train.getTempDriver_ID() /10));
    else if(boutons[12].getactivation())
        train.setTempDriver_ID(train.getDriver_ID());
    else if(boutons[15].getactivation())
    {
        train.setDriver_ID(train.getTempDriver_ID());
        dataEntryWindows({{"", to_string(train.getDriver_ID()), "1"}}, fenetre, RE, symbol, arial, 0, "Driver ID", {}, numero, "alphanumeric", boutons, ecran, train, ecart);
    }
	//if(train.getTempDriver_ID() == 0)
	//	dataEntryWindows({{"", "", "0"}}, fenetre, RE, symbol, arial, 0, "Driver ID", {}, numero, "alphanumeric", boutons, ecran, train);
	//else
	dataEntryWindows({{"", to_string(train.getTempDriver_ID()), "0"}}, fenetre, RE, symbol, arial, 0, "Driver ID", {}, numero, "alphanumeric", boutons, ecran, train, ecart);
}

void radionetworkIDWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
	dataEntryWindows({{"", train.getRadioNetworkID(), "0"}}, fenetre, RE, symbol, arial, 0, "Radio network ID", {}, numero, "dedicated keyboard", boutons, ecran, train, ecart);
	if(boutons[0].getactivation())
		train.setRadioNetworkID("GSMR-A");
	else if(boutons[1].getactivation())
		train.setRadioNetworkID("GSMR-B");
	else if(boutons[1].getactivation())
		train.setRadioNetworkID("Telecom X");
}

void RBCdataWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
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


void languageWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
	dataEntryWindows({{"", train.getLanguage(), "0"}}, fenetre, RE, symbol, arial, 0, "Language", {"English", "Francais"}, numero, "dedicated keyboard", boutons, ecran, train, ecart);
	if(boutons[0].getactivation())
		train.setLanguage("English");
	else if(boutons[1].getactivation())
		train.setLanguage("Francais");
}

void volumeWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
	dataEntryWindows({{""}}, fenetre, RE, symbol, arial, 0, "Volume", {}, numero, "", boutons, ecran, train, ecart);
}

void brightnessWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
	dataEntryWindows({{""}}, fenetre, RE, symbol, arial, 0, "Brightness", {}, numero, "", boutons, ecran, train, ecart);
}

void trainDataWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
	vector<vector<string>> input_field = {{"Train category", train.getTrain_category(), "0"}, {"Length (m)", to_string(train.getlength()), "1"}, {"Brake percentage",
		to_string(train.getbreaking_percetage()), "0"}, {"Max speed (km/h)", to_string(train.getmaximum_train_speed()), "0"}, {"Axle load category",
		train.getaxle_load_category(), "0"}, {"Airtight", train.getAirtight(), "0"}, {"Loading gauge", train.getloading_gauge(), "0"}};
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

void SRspeedWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
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

void adhesionWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
	dataEntryWindows({{"", train.getAdhesion(),"0"}}, fenetre, RE, symbol, arial, 0, "Adhesion", {"Non slippery rail","Slippery rail"}, numero, "dedicated keyboard", boutons, ecran, train, ecart);
	if(boutons[0].getactivation())
		train.setAdhesion("Non slippery rail");
	else if(boutons[1].getactivation())
		train.setAdhesion("Slippery rail");
}

void dataViewWindows(vector<Symbol> & symbol, Font & arial, string title, int & numero, vector<Buttons> & boutons, string & ecran, vector<vector<string>> item)
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

void dataViewWindow(vector<Symbol> & symbol, Font & arial, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero)
{
    vector<vector<string>> item;
    if(numero == 1)
    	item = {{"Driver ID", to_string(train.getDriver_ID())}, {"", ""},{"Train running number", to_string(train.getTrain_running_number()) },
			{"", ""}, {"Train type", train.getTrain_type()}, {"Train category", train.getTrain_category()}, {"Length (m)", to_string(train.getlength())},
			{"Brake percentage", to_string(train.getbreaking_percetage())}, {"Max speed (km/h)", to_string(train.getmaximum_train_speed())},
			{"Axle load category", train.getaxle_load_category()}, {"Airtight", train.getAirtight()}, {"Loading gauge", train.getloading_gauge()}};
    else
    	item = {{"Radio network ID", train.getRadioNetworkID()}, {"RBC ID", to_string(train.getRBCID())}, {"RBC phone number", to_string(train.getRBCphoneNumber())}, {"", ""},
		{"VBC #1 set code", "d"}, {"VBC #2 set code", "e"}};
    dataViewWindows(fenetre, RE, symbol, arial, "Data View", numero, boutons, ecran, item, ecart);
}

void systemVersionWindow(vector<Symbol> & symbol, Font & arial, vector<Buttons> & boutons, string & ecran, int & numero)
{
	vector<vector<string>> item = {{"Operated system version", ""}};
	dataViewWindows(fenetre, RE, symbol, arial, "System version", numero, boutons, ecran, item, ecart);
}

void windows(string & ecran, vector<Symbol> & symbol, Font & arial, string version, donnees & train, vector<VBC> vbc, vector<Buttons> & boutons, int & numero)
{
    if(ecran == "mainWindow")
        MainWindow(fenetre, RE, symbol, arial, version, train, boutons, ecran, numero, ecart);
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