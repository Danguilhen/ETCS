#include "Cadran.hpp"

V2f Cadran::local2globalCoordonates(V2f CoordonneesPolaires)
{
	V2f Coordonnees;
	Coordonnees.x = centre.x - (- 1) * CoordonneesPolaires.x * cos((CoordonneesPolaires.y - teta_origine) * PI / 180.0); //PI/180 permet de passer de la valeur de radians a une valeur en degree
	Coordonnees.y = centre.y - (- 1) * CoordonneesPolaires.x * sin((CoordonneesPolaires.y - teta_origine) * PI / 180.0); // le facteur -1 permet de se mettre dans le cas du cercle trigonometrique
	return Coordonnees;
}

VertexArray Cadran::Shape(DonneesAfficheurVitesse grad, V2f a, V2f b, V2f c, V2f d)
{
	VertexArray Barre(Quads, 4);
	Barre[0].position = local2globalCoordonates(V2f(a.x * data->getRE(),grad.teta() + a.y));
	Barre[1].position = local2globalCoordonates(V2f(b.x * data->getRE(),grad.teta() + b.y));
	Barre[2].position = local2globalCoordonates(V2f(c.x * data->getRE(),grad.teta() + c.y));
	Barre[3].position = local2globalCoordonates(V2f(d.x * data->getRE(),grad.teta() + d.y));
	return Barre;
}

Cadran::Cadran(int Vmax, Data &data, RenderWindow &fenetre, ETCS_Bord &bord)
{
	this->bord = &bord;
	this->data = &data;
	this->fenetre = &fenetre;
	this->Vmax = Vmax;
	creation();
}

Cadran::Cadran(int Vmax, Data &data, RenderWindow &fenetre)
{
	this->bord = 0;
	this->data = &data;
	this->fenetre = &fenetre;
	this->Vmax = Vmax;
	creation();
}

void Cadran::creation()
{
	for(int i =0; i <= 400; i++)
	{
		graduations.push_back(DonneesAfficheurVitesse(centre));
	}
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
	teta_origine = 90 + 144; //decalage d'angle par rapport a un repere trigonometrique place la valeur 0
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
	if(!bord)
	convertisseurVitesses();

	V2f position;
	CircleShape Centre;
	Centre.setFillColor(aiguilleColor);
	aiguille.setFillColor(aiguilleColor);
	Centre.setPosition(V2f(centre.x - 25 * data->getRE(), centre.y - 25 * data->getRE()));
	Centre.setRadius(25 * data->getRE());
	fenetre->draw(Centre);
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
			Barre = Shape(graduations[i], V2f(125, - tetaep / 2.0), V2f(125, tetaep / 2.0), V2f(125 - 25, tetaep / 2.0), V2f(125 - 25, - tetaep / 2.0));
			if(i != 250 && i != 350)
			{
				position = local2globalCoordonates(V2f(83 * data->getRE(), graduations[i].teta()));
				creation_texte(to_string(graduations[i].vitesse()), WHITE, 16, 0, V2f(position.x / data->getRE() - data->getEcartX(), position.y / data->getRE() - data->getEcartX()), 1);
			}
		}
		else
		{
			//positionnement de chaque points
			Barre = Shape(graduations[i], V2f(125, - tetaep / 2.0), V2f(125, tetaep / 2.0), V2f(125 - 15, tetaep / 2.0), V2f(125 - 15, - tetaep / 2.0));
		}
		fenetre->draw(Barre);
	}
	//ecriture des vitesses
	//position = local2globalCoordonates(centre,V2f(200,graduations[0].teta()));
	//creation_texte(RE, to_string(graduations[0].vitesse()), arial, WHITE, 16, 0, V2f(position.x / RE, position.y / RE), fenetre, 1); //0km/h
	//position = local2globalCoordonates(centre,V2f(200,graduations[50].teta()));
	//creation_texte(RE, to_string(graduations[50].vitesse()), arial, WHITE, 16, 0, V2f(position.x / RE, position.y / RE), fenetre, 1); //50km/h
	//position = local2globalCoordonates(centre,V2f(200,graduations[100].teta()));
	//creation_texte(RE, to_string(graduations[100].vitesse()), arial, WHITE, 16, 0, V2f(position.x / RE, position.y / RE), fenetre, 1); //100km/h
	//position = local2globalCoordonates(centre,V2f(200,graduations[150].teta()));
	//creation_texte(RE, to_string(graduations[150].vitesse()), arial, WHITE, 16, 0, V2f(position.x / RE, position.y / RE), fenetre, 1); //150km/h
	//position = local2globalCoordonates(centre,V2f(200,graduations[200].teta()));
	//creation_texte(RE, to_string(graduations[200].vitesse()), arial, WHITE, 16, 0, V2f(position.x / RE, position.y / RE), fenetre, 1); //200km/h
	//position = local2globalCoordonates(centre,V2f(200,graduations[300].teta()));
	//creation_texte(RE, to_string(graduations[300].vitesse()), arial, WHITE, 16, 0, V2f(position.x / RE, position.y / RE), fenetre, 1); //300km/h
	//position = local2globalCoordonates(centre,V2f(200,graduations[400].teta()));
	//creation_texte(RE, to_string(graduations[400].vitesse()), arial, WHITE, 16, 0, V2f(position.x / RE, position.y / RE), fenetre, 1); //400km/h

	int V1 = max(max(Vorange, Vred), max(max(VdarkGrey, Vyellow), Vwhite));
	int V2 = max(max(VdarkGrey, Vyellow), Vwhite);

	float deltateta = abs(graduations[0].teta()-graduations[1].teta());
	Color couleur2 = GREY;
	Color couleur4 = BLACK;

	if(VmediumGrey != 0)
		creation_texte(to_string((int)VmediumGrey), GREY, 17, 0, V2f(54 + 26, 274), 1);
	for(int i = V2 + 1; i <= V1; i++)
	{
		Barre = Shape(graduations[i], V2f(137, - deltateta / 2.0), V2f(137, deltateta / 2.0), V2f(137 - 20, deltateta / 2.0), V2f(137 - 20, - deltateta / 2.0));
		if(Vred > Vorange)
			couleurForme(Barre, RED, 4);
		else if(Vred < Vorange)
			couleurForme(Barre, ORANGE, 4);
		fenetre->draw(Barre);
	}
	for(int i = 0; i<= V2; i++)
	{
		Barre = Shape(graduations[i], V2f(137, - deltateta / 2.0), V2f(137, deltateta / 2.0), V2f(128, deltateta / 2.0), V2f(128, - deltateta / 2.0));
		couleurForme(Barre, WHITE, 4);
		fenetre->draw(Barre);
	}
	for(int i = (V2 - 2 * asin(3 / float(137 - 20))); i <= V2; i++)
	{
		Barre = Shape(graduations[i], V2f(128, - deltateta / 2.0), V2f(128, deltateta / 2.0), V2f(128 - 11, deltateta / 2.0), V2f(128 - 11, - deltateta / 2.0));
		if(Vyellow > VdarkGrey && Vyellow > Vwhite)
			couleurForme(Barre, YELLOW, 4);
		else if(Vwhite > VdarkGrey && Vwhite > Vyellow)
			couleurForme(Barre, WHITE, 4);
		else
			couleurForme(Barre, DARK_GREY, 4);
		fenetre->draw(Barre);
	}
	for(int i = V1; i <= Vred; i++)
	{
		Barre = Shape(graduations[i], V2f(137, - deltateta / 2.0), V2f(137, deltateta / 2.0), V2f(128, deltateta / 2.0), V2f(128, - deltateta / 2.0));
		couleurForme(Barre, RED, 4);
		fenetre->draw(Barre);
	}
	for(int i = 0; i <= Vyellow; i++)
	{
		Barre = Shape(graduations[i], V2f(137, - deltateta / 2.0), V2f(137, deltateta / 2.0), V2f(128, deltateta / 2.0), V2f(128, - deltateta / 2.0));
		couleurForme(Barre, YELLOW, 4);
		fenetre->draw(Barre);
	}
	for(int i = 0; i <= VdarkGrey; i++)
	{
		Barre = Shape(graduations[i], V2f(137, - deltateta / 2.0), V2f(137, deltateta / 2.0), V2f(128, deltateta / 2.0), V2f(128, - deltateta / 2.0));
		couleurForme(Barre, DARK_GREY, 4);
		fenetre->draw(Barre);
	}
	for(int i = 1; i <= VmediumGrey; i++)
	{
		Barre = Shape(graduations[i], V2f(137, - deltateta / 2.0), V2f(137, deltateta / 2.0), V2f(128 + 4, deltateta / 2.0), V2f(128 + 4, - deltateta / 2.0));
		couleurForme(Barre, couleur2, 4);
		fenetre->draw(Barre);
	}
	if(V1 < VmediumGrey)
	{
		for(int i = 1; i <= V1; i++)
		{
			Barre = Shape(graduations[i], V2f(128 + 4, - deltateta / 2.0), V2f(128 + 4, deltateta / 2.0), V2f(128 + 3, deltateta / 2.0), V2f(128 + 3, - deltateta / 2.0));
			couleurForme(Barre, couleur4, 4);
			fenetre->draw(Barre);
		}
		for(int i = V1 + 1; i <= VmediumGrey; i++) //trait noir
		{
			Barre = Shape(graduations[i], V2f(128 + 4, - deltateta / 2.0), V2f(128 + 4, deltateta / 2.0), V2f(128, deltateta / 2.0), V2f(128, - deltateta / 2.0));
			couleurForme(Barre, couleur2, 4);
			fenetre->draw(Barre);
		}
	}
	else
	{
		for(int i = 1; i <= VmediumGrey; i++)
		{
			Barre = Shape(graduations[i], V2f(128 + 4, - deltateta / 2.0), V2f(128 + 4, deltateta / 2.0), V2f(128 + 3, deltateta / 2.0), V2f(128 + 3, - deltateta / 2.0));
			couleurForme(Barre, couleur4, 4);
			fenetre->draw(Barre);
		}
	}
	for(int i = 0; i <= 4; i++) //Affichage fixe
	{
		Barre = Shape(graduations[i], V2f(137, - 4 - deltateta / 2.0), V2f(137, - 4 + deltateta / 2.0), V2f(128, - 4 + deltateta / 2.0), V2f(128, - 4 - deltateta / 2.0));
		couleurForme(Barre, DARK_GREY, 4);
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

void Cadran::convertisseurVitesses()
{
	if(data->getGeneralMode() == "FS" || data->getGeneralMode() == "OS")
	{
		if(bord->SDM.getStatus() == "CSM")
		{
			if(bord->SDM.getSupervision_status() == "Intervention")
			{
				if(data->getVtrain()<= bord->SDM.getV_MRSP())
					aiguilleColor = GREY;
				else
					aiguilleColor = RED;
				actualisationVitesse(bord->SDM.getV_ebi(), 0, 0, 0, 0, bord->SDM.getV_MRSP());
			}
			else if(bord->SDM.getSupervision_status() == "Warning")
			{
				aiguilleColor = ORANGE;
				actualisationVitesse(0, bord->SDM.getV_ebi(), 0, 0, 0, bord->SDM.getV_MRSP());
			}
			else if(bord->SDM.getSupervision_status() == "Overspeed")
			{
				aiguilleColor = ORANGE;
				actualisationVitesse(0, bord->SDM.getV_ebi(), 0, 0, 0, bord->SDM.getV_MRSP());
			}
			else if(bord->SDM.getSupervision_status() == "Normal")
			{
				aiguilleColor = GREY;
				actualisationVitesse(0, 0, 0, 0, 0, bord->SDM.getV_MRSP());
			}
		}
	}
		/* REFLECHIR A L AVENIR DE PIM ET LA COULEUR JAUNE DANS TSM
        else if(bord->SDM.getStatus() == "PIM")
        {
            if(bord->SDM.getSupervision_status() == "IntS" || data->getVtrain() >= bord->SDM.getV_ebi())
            {
            	if(data->getVtrain()<= train.getVbut())
            		aiguilleColor = GREY;
            	else if(data->getVtrain()<= bord->SDM.getV_MRSP())
            		aiguilleColor = WHITE;
            	else
            		aiguilleColor = RED;
            	actualisationVitesse(bord->SDM.getV_ebi(), 0,0, bord->SDM.getV_MRSP(), train.getVrelease(), train.getVbut());

                if(data->getVtrain() < bord->SDM.getV_MRSP())
                    train.setStatus("NoS");
            }
            else if(bord->SDM.getSupervision_status() == "WaS" || (data->getVtrain() >= train.getVWaS() && data->getVtrain() < bord->SDM.getV_ebi()))
            {
            	aiguilleColor = ORANGE;
                actualisationVitesse(0, bord->SDM.getV_ebi(), 0, bord->SDM.getV_MRSP(), train.getVrelease(),train.getVbut());
                if(data->getVtrain() < bord->SDM.getV_MRSP())
                    train.setStatus("NoS");
            }
            else if(bord->SDM.getSupervision_status() == "OvS" || (data->getVtrain() >= bord->SDM.getV_MRSP() && data->getVtrain() < train.getVWaS()))
            {
            	aiguilleColor = ORANGE;
                actualisationVitesse(0, bord->SDM.getV_ebi(), 0,bord->SDM.getV_MRSP(), train.getVrelease(), train.getVbut());
                if(data->getVtrain() < bord->SDM.getV_MRSP())
                    train.setStatus("NoS");
            }
            else if(bord->SDM.getSupervision_status() == "NoS")
            {
				if(data->getVtrain()<= train.getVbut())
					aiguilleColor = GREY;
				else
					aiguilleColor = WHITE;
                actualisationVitesse(0, 0, 0, bord->SDM.getV_MRSP(), train.getVrelease(), train.getVbut());
                if(data->getVtrain() < bord->SDM.getV_MRSP())
                    train.setStatus("NoS");
            }
        }

		else if(bord->SDM.getStatus() == "TSM")
		{
			if(bord->SDM.getSupervision_status() == "IntS" || data->getVtrain() >= bord->SDM.getV_ebi())
			{
				if(data->getVtrain()<= train.getVbut())
					aiguilleColor = GREY;
				else if(data->getVtrain()<= bord->SDM.getV_MRSP())
					aiguilleColor = YELLOW;
				else
					aiguilleColor = RED;
				actualisationVitesse(bord->SDM.getV_ebi(), 0,bord->SDM.getV_MRSP(), 0 , train.getVrelease(), train.getVbut());
				if(data->getVtrain() < train.getVbut())
					train.setStatus("NoS");
			}
			else if(bord->SDM.getSupervision_status() == "WaS" || (data->getVtrain() >= train.getVWaS() && data->getVtrain() < bord->SDM.getV_ebi()))
			{
				aiguilleColor = ORANGE;
				actualisationVitesse(0, bord->SDM.getV_ebi(), bord->SDM.getV_MRSP(), 0, train.getVrelease(), train.getVbut());
				if(data->getVtrain() < train.getVbut())
					train.setStatus("NoS");
			}
			else if(bord->SDM.getSupervision_status() == "OvS" || (data->getVtrain() >= bord->SDM.getV_MRSP() && data->getVtrain() < train.getVWaS()))
			{
				aiguilleColor = ORANGE;
				actualisationVitesse(0, bord->SDM.getV_ebi(), bord->SDM.getV_MRSP(), 0 , train.getVrelease(), train.getVbut());
				if(data->getVtrain() < train.getVbut())
					train.setStatus("NoS");
			}
			else if (bord->SDM.getSupervision_status() == "IndS"||(data->getVtrain() < bord->SDM.getV_MRSP() && data->getVtrain() >= train.getVitesseISL()))
			{
				actualisationVitesse(0, 0, bord->SDM.getV_MRSP(), 0 , train.getVrelease(), train.getVbut() );//OK
				if (data->getVtrain() < train.getVbut())
					train.setStatus("NoS");
			}
			else if(bord->SDM.getSupervision_status() == "NoS")
			{
				if(data->getVtrain()<= train.getVbut())
					aiguilleColor = GREY;
				else
					aiguilleColor = WHITE;
				actualisationVitesse(0, 0, 0, bord->SDM.getV_MRSP(), train.getVrelease(), train.getVbut());//OK
				if(data->getVtrain() < train.getVbut())
					train.setStatus("NoS");
			}
		}
		else if(bord->SDM.getStatus() == "RSM")
		{

		}
	}
	else if(data->getGeneralMode() == "LS")
	{
		if(bord->SDM.getStatus() == "CSM")
		{

		}
		else if(bord->SDM.getStatus() == "PIM")
		{

		}
		else if(bord->SDM.getStatus() == "TSM")
		{

		}
		else if(bord->SDM.getStatus() == "RSM")
		{

		}
	}
	else if(data->getGeneralMode() == "SR/UN")
	{
		if(bord->SDM.getStatus() == "CSM")
		{

		}
		else if(bord->SDM.getStatus() == "PIM")
		{

		}
		else if(bord->SDM.getStatus() == "TSM")
		{

		}
	}
	else if(data->getGeneralMode() == "SH/RV")
	{
		if(bord->SDM.getStatus() == "CSM")
		{

		}
	}
	else if(data->getGeneralMode() == "NL/SB/PT")
	{

	}
	else if(data->getGeneralMode() == "TR")
	{

	}
	*/
}

void Cadran::actualisationVitesse(float red, float orange, float yellow, float white, float mediumGrey, float darkGrey)
{
	Vred = red;
	Vorange = orange;
	Vyellow = yellow;
	Vwhite = white;
	if(darkGrey == 0)
		VmediumGrey = mediumGrey;
	else
		VmediumGrey = 0;
	VdarkGrey = darkGrey;
}


DonneesAfficheurVitesse::DonneesAfficheurVitesse(V2f &centre)
{
	this->centre = &centre;
	m_cartesiens.x = 0;
	m_cartesiens.y = 0;
	m_polaire.x = 0;
	m_polaire.y = 0;
	m_vitesse = 0;
}

DonneesAfficheurVitesse::DonneesAfficheurVitesse(V2f cartesiens, V2f polaire, int vitesse, V2f &centre)
{
	this->centre = &centre;
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