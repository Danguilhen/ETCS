#include "Planning.hpp"

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


/*void Planning::pasp()
{
	int distance = 0;
	int target = 0;
	int vitesse = 0;
	int quart = 0;
	int plus_petite_V = bord->SDM.MRSP.getV_MRSP(); // ATTENTION A PRENDRE V_LIGNE DANS soft
	int distance_plus_petite_V = 40000;
	int n;

	for (size_t i = 0; i < bord->TrackRI.TSR.getVitesseTableau().size(); i++)
	{
		if(bord->TrackRI.TSR.getVitesseTableau()[i][2] < plus_petite_V)
		{
			plus_petite_V = bord->TrackRI.TSR.getVitesseTableau()[i][2];
			distance_plus_petite_V = bord->TrackRI.TSR.getVitesseTableau()[i][1];
		}
	}

	//plus_petite_V = soft->getVligne();
	for(size_t i = 0; i < bord->TrackRI.TSR.getVitesseTableau().size(); i++)
	{
			n = 0;
		if(bord->TrackRI.TSR.getVitesseTableau()[i][2] <= plus_petite_V && bord->TrackRI.TSR.getVitesseTableau()[i][1] > 0 && i > 0)
		{
			if(bord->TrackRI.TSR.getVitesseTableau()[i][1] == distance_plus_petite_V && bord->TrackRI.TSR.getVitesseTableau()[i][2] != 0)
				distance = 40000;
			else
				distance = bord->TrackRI.TSR.getVitesseTableau()[i][1];
			if(i == 1)
				vitesse = bord->SDM.MRSP.getV_MRSP();
			else
			{
				do
				{
					n++;
				}while(bord->TrackRI.TSR.getVitesseTableau()[i - n][2]!= plus_petite_V);
				vitesse = bord->TrackRI.TSR.getVitesseTableau()[i - n][2];
			}
			if(vitesse > 0 && vitesse <= int(bord->SDM.MRSP.getV_MRSP()) / 4.0)
				quart = 1;
			else if(vitesse <= int(bord->SDM.MRSP.getV_MRSP()) / 2.0)
				quart = 2;
			else if(vitesse <= 3 * int(bord->SDM.MRSP.getV_MRSP()) / 4.0)
				quart = 3;
			else if (vitesse >= 3 * int(bord->SDM.MRSP.getV_MRSP()) / 4.0)
				quart = 4;
			if(distance <= (scale / 40.0) && distance >= 0)
				target = 283 - (distance * (283 - 250) / (scale / 40.0));
			else if(distance <= scale && distance >= 0)
				target =  283 - (283 - 250) - log10(distance / (scale / 40.0)) * (250 - 21) / log10(scale / (scale / 40.0));
			else
				target = 15;
			rectangle(V2f(54 + 280 + 40 + 25 * 3 + 18 + 14, target), V2f(quart * 93 / 4.0, 283 - target), PASP_LIGHT);
		}
		else if (bord->SDM.MRSP.getV_MRSP() == 1)
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
		plus_petite_V = bord->TrackRI.TSR.getVitesseTableau()[i][2];
		if(i==bord->TrackRI.TSR.getVitesseTableau().size() - 1)
		{
			plus_petite_V = bord->TrackRI.TSR.getVitesseTableau()[i][2];
		}
	}
}*/

void Planning::planningInformation()
{
	//int delta_distance = 0;
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

	//LES PASP

	//pasp();
	//Orders_and_announcements(scale, delta_distance, tab_pa);
	SpeedProfileDiscontinuityInformation();
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
	gradientProfile();
}

/*void Planning::Orders_and_announcements(int scale, double delta_distance, vector<Announcements> &tab_pa)
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
			(*symbol)[tab_pa[i].getnumero()].afficher(V2f(position + 12, target));

		tab_pa[i].setDistance(tab_pa[i].getDistance() - delta_distance);
		if(tab_pa[i].getDistance() <= 0)
		{
			tab_pa.erase(tab_pa.begin()+i);
		}
	}
}*/

void Planning::gradientProfile()
{
	Color couleur;
	string sens;
	double taille;
	double hauteur;
	int valeur;
	for(size_t i=0; i < bord->TrackRI.gradient_ligne.getTab_Gradient().size(); i++)
		{
			if(bord->TrackRI.gradient_ligne.getTab_Gradient()[i][0] > 0)
			{
				hauteur = bord->TrackRI.gradient_ligne.getTab_Gradient()[i][0];
				taille = bord->TrackRI.gradient_ligne.getTab_Gradient()[i][1];
			}
		else
		{
			hauteur = 0;
			taille = bord->TrackRI.gradient_ligne.getTab_Gradient()[i][1];
		}
		if(taille < 0)
			taille = 0;
		valeur = static_cast<int>(bord->TrackRI.gradient_ligne.getTab_Gradient()[i][2]);
		if(i == 2)
		{
			//cout << "hauteur : " << hauteur << "taille : " << taille <<endl;
		}

		if(hauteur < scale)
		{
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
			rectangle(V2f(static_cast<float>(54 + 280 + 40 + 25 * 3), static_cast<float>(283 - 2 - hauteur - taille)), V2f((float)18, (float)1), WHITE);
			rectangle(V2f(static_cast<float>(54 + 280 + 40 + 25 * 3), static_cast<float>(283 - 1 - hauteur - taille)), V2f((float)1, static_cast<float>(1 + taille)), WHITE);
			rectangle(V2f(static_cast<float>(54 + 280 + 40 + 25 * 3 + 1), static_cast<float>(283 - 1 - hauteur - taille)), V2f((float)17, (float)taille), couleur);
			rectangle(V2f(static_cast<float>(54 + 280 + 40 + 25 * 3), static_cast<float>(283 - 1 - hauteur)), V2f(18, 1), BLACK);
			if(couleur == GREY)
				couleur = BLACK;
			else if(couleur == DARK_GREY)
				couleur = WHITE;
			if(taille > 30)
			{
				creation_texte(sens, couleur, 12, 0, V2f(static_cast<float>(54 + 280 + 40 + 25 * 3 + 18 /2.0), static_cast<float>(283 - hauteur - taille + 12)), 1); //400km/h
				creation_texte(sens, couleur, 12, 0, V2f(static_cast<float>(54 + 280 + 40 + 25 * 3 + 18 /2.0), static_cast<float>(283 - hauteur - 12)), 1); //400km/h
			}
			if(taille > 50)
				creation_texte(to_string(valeur), couleur, 12, 0, V2f(static_cast<float>(54 + 280 + 40 + 25 * 3 + 18 / 2.0), static_cast<float>(283 - hauteur - taille / 2.0)), 1); //400km/h
		}
	}
}

void Planning::SpeedProfileDiscontinuityInformation()
{
	int distance;
	int target;
	int position;
	int indice;

	for (size_t i = 1; i < bord->TrackRI.TSR.getVitesseTableau().size(); i++)
	{
		distance = static_cast<int>(bord->TrackRI.TSR.getVitesseTableau()[i][0]);
		if(distance <= (scale / 40.0) && distance >= 0)
			target = 283 - static_cast<int>((distance * (283 - 250) / (scale / 40.0)));
		else if(distance <= scale && distance >= 0)
			target =  283 - (283 - 250) - static_cast<int>(log10(distance / (scale / 40.0))) * (250 - 21) / static_cast<int>(log10(scale / (scale / 40.0)));
		else
			target = 15;
		target = target - 5;
		if(bord->TrackRI.TSR.getVitesseTableau()[i][2] > bord->TrackRI.TSR.getVitesseTableau()[i - 1][2])
			indice = 91;
		else
			indice = 92;

		if(bord->TrackRI.TSR.getVitesseTableau()[i][0] <= scale)
		{
			(*symbol)[indice].afficher(V2f(static_cast<float>(54 + 280 + 40 + 3 * 25 + 18 + 13), static_cast<float>(target + 10)));
			if(static_cast<int>(bord->TrackRI.TSR.getVitesseTableau()[i][2]) > 99)
				position = 19;
			else if(static_cast<int>(bord->TrackRI.TSR.getVitesseTableau()[i][2]) > 9)
				position = 20 - 4;
			else
				position = 20 - 7;
			if(indice == 92)
				creation_texte(to_string(static_cast<int>(bord->TrackRI.TSR.getVitesseTableau()[i][2])), GREY, 11, 0.0f, V2f(static_cast<float>(54 + 280 + 40 + 3 * 25 + 18 + 13 + position), static_cast<float>(target + 9)), 1);
			if(indice == 91)
				creation_texte(to_string(static_cast<int>(bord->TrackRI.TSR.getVitesseTableau()[i][2])), GREY, 11, 0.0f, V2f(static_cast<float>(54 + 280 + 40 + 3 * 25 + 18 + 13 + position), static_cast<float>(target + 14)), 1);
		}
	}
}

Planning::Planning(vector<Symbol> &symbol, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D)  /* PA1(1500, 98), PA2(1000, 72), PA3(3000, 97), PA6(4000, 75)*/
{
	//cout<<"Pla"<<endl;
	this->bord = &bord;
	this->symbol = &symbol;
	this->soft = &soft;
	this->T_D = &T_D;

/*

	tab_pa.push_back(PA1);
	tab_pa.push_back(PA2);
	tab_pa.push_back(PA3);
	tab_pa.push_back(PA6);
	*/
}

