#include "Cadran.hpp"

V2f Cadran::local2globalCoordonates(V2f CoordonneesPolaires)
{
	V2f Coordonnees;
	Coordonnees.x = centre.x - (- 1) * CoordonneesPolaires.x * (float)cos((CoordonneesPolaires.y - teta_origine) * PI / 180.0f); //PI/180 permet de passer de la valeur de radians a une valeur en degree
	Coordonnees.y = centre.y - (- 1) * CoordonneesPolaires.x * (float)sin((CoordonneesPolaires.y - teta_origine) * PI / 180.0f); // le facteur -1 permet de se mettre dans le cas du cercle trigonometrique
	return Coordonnees;
}

VertexArray Cadran::Shape(DonneesAfficheurVitesse grad, V2f a, V2f b, V2f c, V2f d)
{
	VertexArray Barre(Quads, 4);
	Barre[0].position = local2globalCoordonates(V2f(a.x * soft->getRE(), static_cast<float>(grad.teta()) + a.y));
	Barre[1].position = local2globalCoordonates(V2f(b.x * soft->getRE(), static_cast<float>(grad.teta()) + b.y));
	Barre[2].position = local2globalCoordonates(V2f(c.x * soft->getRE(), static_cast<float>(grad.teta()) + c.y));
	Barre[3].position = local2globalCoordonates(V2f(d.x * soft->getRE(),static_cast<float>(grad.teta()) + d.y));
	return Barre;
}

Cadran::Cadran(Software &soft, Train_dynamique &T_D, ETCS_Bord &bord)
{
	this->bord = &bord;
	this->soft = &soft;
	this->T_D = &T_D;


	creation();

}

Cadran::Cadran(Software &soft, Train_dynamique &T_D)
{
	this->soft = &soft;
	this->T_D = &T_D;
	creation();
}


void Cadran::creation()
{
	for(int i =0; i <= 400; i++)
	{
		graduations.push_back(DonneesAfficheurVitesse(centre, teta_origine));
	}
	teta0 = 90 - 144;
	kmh2degVfaible = 144.0f / 150.0f;  //nombre de degre pour 1km/h ici a 144� on a 150km/h
	kmh2degVeleve = kmh2degVfaible / 2.0f;



	centre.x = soft->getRE() * (54 + 280 / 2.0f + soft->getEcartX());
	centre.y = soft->getRE() * (300 / 2.0f + soft->getEcartY());

	aiguille.setPointCount(8);
	aiguille.setPosition(centre);

	aiguille.setPoint(0,V2f(- (80 + 25) * soft->getRE(), - 3 / 2.0f * soft->getRE()));
	aiguille.setPoint(1,V2f(- (80 + 25) * soft->getRE(), 3 / 2.0f * soft->getRE()));
	aiguille.setPoint(2,V2f(- (80 + 25 - 15) * soft->getRE(), 3 / 2.0f * soft->getRE()));
	aiguille.setPoint(3,V2f(- (57 + 25) * soft->getRE(),9 / 2.0f * soft->getRE()));
	aiguille.setPoint(4,V2f(- 20 * soft->getRE(),9 / 2.0f * soft->getRE()));
	aiguille.setPoint(5,V2f(- 20 * soft->getRE(), - 9 / 2.0f * soft->getRE()));
	aiguille.setPoint(6,V2f(- (57 + 25) * soft->getRE(), - 9 / 2.0f * soft->getRE()));
	aiguille.setPoint(7,V2f(- (80 + 25 - 15) * soft->getRE(), - 3 / 2.0f * soft->getRE()));

	int Vfaible;
	teta_origine = 90 + 144; //decalage d'angle par rapport a un repere trigonometrique place la valeur 0
	if(soft->getVmax() == 400) //petite vitesse : differentes echelles entre 0 et 200 et 200 et 400
	{
		Vfaible = 200;
		kmh2degVfaible = 144.0f / 150;
	}
	else
	{
		Vfaible = soft->getVmax();
		kmh2degVfaible = 144.0f / (soft->getVmax() / 2.0f);
	}
	double kmh2degVeleve = kmh2degVfaible / 2.0;

	for(int i = 1; i <= Vfaible; i++)	//i correspond a la vitesse
	{
		graduations[i].polaire(V2f(0, i * kmh2degVfaible));
		graduations[i].vitesse(i);
	}
	for(int i = 1 + Vfaible; i <= soft->getVmax(); i++) //i correspond a la vitesse
	{
		graduations[i].polaire(V2f(0, Vfaible * kmh2degVfaible / 2.0f + i * (float)kmh2degVeleve));
		graduations[i].vitesse(i);
	}
}

void Cadran::update()
{
	if(bord) //SI ETCS
		convertisseurVitesses();

	V2f position;
	CircleShape Centre;
	Centre.setFillColor(aiguilleColor);
	aiguille.setFillColor(aiguilleColor);
	Centre.setPosition(V2f(centre.x - 25 * soft->getRE(), centre.y - 25 * soft->getRE()));
	Centre.setRadius(25 * soft->getRE());
	soft->getFenetre()->draw(Centre);
	float tetaep = 0.5f;

	VertexArray Barre(Quads, 4);

	// trace d'une barre
	//definition de la couleur de chaque points

	couleurForme(Barre, WHITE, 4);

	///////////////////////////////////////////////////////////////////////////////
	//affichage des graduations

	for(int i = 0; i <= soft->getVmax(); i = i + 10) //i correspond a la vitesse
	{
		if((soft->getVmax() == 400 && i % 50 == 0) || (soft->getVmax() != 400 && i % 20 == 0))
		{ //affiche des barres plus longues tous les 50km/h
			//positionnement de chaque points
			Barre = Shape(graduations[i], V2f(125, -(float)tetaep / 2.0f), V2f(125, (float)tetaep / 2.0f), V2f(125 - 25, (float)tetaep / 2.0f), V2f(125 - 25, -(float)tetaep / 2.0f));
			if(i != 250 && i != 350)
			{
				position = local2globalCoordonates(V2f(83 * soft->getRE(), static_cast<float>(graduations[i].teta())));
				creation_texte(to_string(graduations[i].vitesse()), WHITE, 16, 0, V2f(position.x / soft->getRE() - soft->getEcartX(), position.y / soft->getRE() - soft->getEcartX()), 1);
			}
		}
		else
		{
			//positionnement de chaque points
			Barre = Shape(graduations[i], V2f(125, -(float)tetaep / 2.0f), V2f(125, (float)tetaep / 2.0f), V2f(125 - 15, (float)tetaep / 2.0f), V2f(125 - 15, -(float)tetaep / 2.0f));
		}
		soft->getFenetre()->draw(Barre);
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

	int V1 = static_cast<int>(max(max(Vorange, Vred), max(max(VdarkGrey, Vyellow), Vwhite)));
	int V2 = static_cast<int>(max(max(VdarkGrey, Vyellow), Vwhite));

	double deltateta = abs(graduations[0].teta()-graduations[1].teta());
	Color couleur2 = GREY;
	Color couleur4 = BLACK;
	if(VmediumGrey != 0)
		creation_texte(to_string((int)VmediumGrey), GREY, 17, 0, V2f(54 + 26, 274), 1);
	for(int i = V2 + 1; i <= V1; i++)
	{
		Barre = Shape(graduations[i], V2f(137, -(float)deltateta / 2.0f), V2f(137, (float)deltateta / 2.0f), V2f(137 - 20, (float)deltateta / 2.0f), V2f(137 - 20, -(float)deltateta / 2.0f));
		if(Vred > Vorange)
			couleurForme(Barre, RED, 4);
		else if(Vred < Vorange)
			couleurForme(Barre, ORANGE, 4);
		soft->getFenetre()->draw(Barre);
	}
	if (bord->getGeneralMode() != "TVM" && bord->getGeneralMode() != "SB")
	{
		for(int i = 0; i<= V2; i++)
		{
			Barre = Shape(graduations[i], V2f(137, -(float)deltateta / 2.0f), V2f(137, (float)deltateta / 2.0f), V2f(128, (float)deltateta / 2.0f), V2f(128, -(float)deltateta / 2.0f));
			couleurForme(Barre, WHITE, 4);
			soft->getFenetre()->draw(Barre);
		}
		for(int i = static_cast<int>((V2 - 2 * asin(3 / (137 - 20)))); i <= V2; i++)
		{
			Barre = Shape(graduations[i], V2f(128, -(float)deltateta / 2.0f), V2f(128, (float)deltateta / 2.0f), V2f(128 - 11, (float)deltateta / 2.0f), V2f(128 - 11, -(float)deltateta / 2.0f));
			if(Vyellow > VdarkGrey && Vyellow > Vwhite)
				couleurForme(Barre, YELLOW, 4);
			else if(Vwhite > VdarkGrey && Vwhite > Vyellow)
				couleurForme(Barre, WHITE, 4);
			else
				couleurForme(Barre, DARK_GREY, 4);
			soft->getFenetre()->draw(Barre);
		}
		for(int i = V1; i <= Vred; i++)
		{
			Barre = Shape(graduations[i], V2f(137, -(float)deltateta / 2.0f), V2f(137, (float)deltateta / 2.0f), V2f(128, (float)deltateta / 2.0f), V2f(128, - (float)deltateta / 2.0f));
			couleurForme(Barre, RED, 4);
			soft->getFenetre()->draw(Barre);
		}
		for(int i = 0; i <= Vyellow; i++)
		{
			Barre = Shape(graduations[i], V2f(137, -(float)deltateta / 2.0f), V2f(137, (float)deltateta / 2.0f), V2f(128, (float)deltateta / 2.0f), V2f(128, - (float)deltateta / 2.0f));
			couleurForme(Barre, YELLOW, 4);
			soft->getFenetre()->draw(Barre);
		}
		for(int i = 0; i <= VdarkGrey; i++)
		{
			Barre = Shape(graduations[i], V2f(137, -(float)deltateta / 2.0f), V2f(137, (float)deltateta / 2.0f), V2f(128, (float)deltateta / 2.0f), V2f(128, -(float)deltateta / 2.0f));
			couleurForme(Barre, DARK_GREY, 4);
			soft->getFenetre()->draw(Barre);
		}
		for(int i = 1; i <= VmediumGrey; i++)
		{
			Barre = Shape(graduations[i], V2f(137, -(float)deltateta / 2.0f), V2f(137, (float)deltateta / 2.0f), V2f(128 + 4, (float)deltateta / 2.0f), V2f(128 + 4, -(float)deltateta / 2.0f));
			couleurForme(Barre, couleur2, 4);
			soft->getFenetre()->draw(Barre);
		}
		if(V1 < VmediumGrey)
		{
			for(int i = 1; i <= V1; i++)
			{
				Barre = Shape(graduations[i], V2f(128 + 4, -(float)deltateta / 2.0f), V2f(128 + 4, (float)deltateta / 2.0f), V2f(128 + 3, (float)deltateta / 2.0f), V2f(128 + 3, -(float)deltateta / 2.0f));
				couleurForme(Barre, couleur4, 4);
				soft->getFenetre()->draw(Barre);
			}
			for(int i = V1 + 1; i <= VmediumGrey; i++) //trait noir
			{
				Barre = Shape(graduations[i], V2f(128 + 4, - (float)deltateta / 2.0f), V2f(128 + 4, (float)deltateta / 2.0f), V2f(128, (float)deltateta / 2.0f), V2f(128, - (float)deltateta / 2.0f));
				couleurForme(Barre, couleur2, 4);
				soft->getFenetre()->draw(Barre);
			}
		}
		else
		{
			for(int i = 1; i <= VmediumGrey; i++)
			{
				Barre = Shape(graduations[i], V2f(128 + 4, - (float)deltateta / 2.0f), V2f(128 + 4, (float)deltateta / 2.0f), V2f(128 + 3, (float)deltateta / 2.0f), V2f(128 + 3, - (float)deltateta / 2.0f));
				couleurForme(Barre, couleur4, 4);
				soft->getFenetre()->draw(Barre);
			}
		}
		for(int i = 0; i <= 4; i++) //Affichage fixe
		{
			Barre = Shape(graduations[i], V2f(137, - 4 - (float)deltateta / 2.0f), V2f(137, - 4 + (float)deltateta / 2.0f), V2f(128, - 4 + (float)deltateta / 2.0f), V2f(128, - 4 - (float)deltateta / 2.0f));
			couleurForme(Barre, DARK_GREY, 4);
			soft->getFenetre()->draw(Barre);
		}
	}

	if(abs(T_D->getV_train()) < 200)
		aiguille.setRotation((float)abs(T_D->getV_train()) * kmh2degVfaible+teta0);
	else
		aiguille.setRotation(200 * kmh2degVfaible / 2.0f + (float)abs(T_D->getV_train()) * kmh2degVeleve+teta0);

	soft->getFenetre()->draw(aiguille);

	string str = to_string(graduations[abs((int)T_D->getV_train())].vitesse());
	string s;
	if(graduations[abs((int)T_D->getV_train())].vitesse() > 99)
	{
		s = str.at(2);
		creation_texte(s, BLACK, 18, 0, V2f(54 + 280 / 2.0f + 50 / 2.0f - 3, 300 / 2.0f), 2);
		s = str.at(1);
		creation_texte(s, BLACK, 18, 0, V2f(54 + 280 / 2.0f + 50 / 6.0f - 3, 300 / 2.0f), 2);
		s = str.at(0);
		creation_texte(s, BLACK, 18, 0, V2f(54 + 280 / 2.0f - 50 / 6.0f - 3, 300 / 2.0f), 2);
	}
	else if(graduations[abs(abs((int)T_D->getV_train()))].vitesse() > 9)
	{
		s = str.at(1);

		creation_texte(s, BLACK, 18, 0, V2f(54 + 280 / 2.0f + 50 / 3.0f, 300 / 2.0f), 1);
		s = str.at(0);
		creation_texte(s, BLACK, 18, 0, V2f(54 + 280 / 2.0f, 300 / 2.0f), 1);
	}
	else
	{
		s = str.at(0);
		creation_texte(s, BLACK, 18, 0, V2f(54 + 280 / 2.0f + 50 / 3.0f, 300 / 2.0f), 1);
	}
}

void Cadran::convertisseurVitesses()
{
	if(bord->getGeneralMode() == "FS" || bord->getGeneralMode() == "OS")
	{
		if(bord->SDM.SL.getStatus() == "CSM")
		{
			if(bord->SDM.SADMC.getSupervision_status() == "Intervention")
			{
				if(T_D->getV_train() <= bord->SDM.MRSP.getV_MRSP())
				{
					aiguilleColor = GREY;
					actualisationVitesse(0, 0, bord->SDM.MRSP.getV_MRSP(), 0, 0, 0);
				}
				else
				{
					aiguilleColor = RED;
					//actualisationVitesse(bord->SDM.SL.getV_ebi(), 0, bord->SDM.MRSP.getV_MRSP(), 0, 0, 0);
					actualisationVitesse(T_D->getV_train(), 0, bord->SDM.MRSP.getV_MRSP(), 0, 0, 0);
				}

			}
			else if(bord->SDM.SADMC.getSupervision_status() == "Warning")
			{
				aiguilleColor = ORANGE;
				actualisationVitesse(0, bord->SDM.SL.getV_ebi(), bord->SDM.MRSP.getV_MRSP(), 0, 0, 0);

			}
			else if(bord->SDM.SADMC.getSupervision_status() == "Overspeed")
			{
				aiguilleColor = ORANGE;
				actualisationVitesse(0, bord->SDM.SL.getV_ebi(), bord->SDM.MRSP.getV_MRSP(), 0, 0, 0);
			}
			else if(bord->SDM.SADMC.getSupervision_status() == "Normal")
			{
				aiguilleColor = GREY;
				actualisationVitesse(0, 0, 0, 0, 0, bord->SDM.MRSP.getV_MRSP());
			}
		}

		//REFLECHIR A L AVENIR DE PIM ET LA COULEUR JAUNE DANS TSM
        //else if(bord->SDM.getStatus() == "PIM")
        //{
        //    if(bord->SDM.SADMC.getSupervision_status() == "IntS" || bord->TrainRI.T_data.getVtrain() >= bord->SDM.getV_ebi())
        //    {
        //    	if(bord->TrainRI.T_data.getVtrain()<= train.getVbut())
        //    		aiguilleColor = GREY;
        //    	else if(bord->TrainRI.T_data.getVtrain()<= bord->SDM.MRSP.getV_MRSP())
        //    		aiguilleColor = WHITE;
        //    	else
        //    		aiguilleColor = RED;
        //    	actualisationVitesse(bord->SDM.getV_ebi(), 0,0, bord->SDM.MRSP.getV_MRSP(), train.getVrelease(), train.getVbut());
//
        //        if(bord->TrainRI.T_data.getVtrain() < bord->SDM.MRSP.getV_MRSP())
        //            train.setStatus("NoS");
        //    }
        //    else if(bord->SDM.SADMC.getSupervision_status() == "WaS" || (bord->TrainRI.T_data.getVtrain() >= train.getVWaS() && bord->TrainRI.T_data.getVtrain() < bord->SDM.getV_ebi()))
        //    {
        //    	aiguilleColor = ORANGE;
        //        actualisationVitesse(0, bord->SDM.getV_ebi(), 0, bord->SDM.MRSP.getV_MRSP(), train.getVrelease(),train.getVbut());
        //        if(bord->TrainRI.T_data.getVtrain() < bord->SDM.MRSP.getV_MRSP())
        //            train.setStatus("NoS");
        //    }
        //    else if(bord->SDM.SADMC.getSupervision_status() == "OvS" || (bord->TrainRI.T_data.getVtrain() >= bord->SDM.MRSP.getV_MRSP() && bord->TrainRI.T_data.getVtrain() < train.getVWaS()))
        //    {
        //    	aiguilleColor = ORANGE;
        //        actualisationVitesse(0, bord->SDM.getV_ebi(), 0,bord->SDM.MRSP.getV_MRSP(), train.getVrelease(), train.getVbut());
        //        if(bord->TrainRI.T_data.getVtrain() < bord->SDM.MRSP.getV_MRSP())
        //            train.setStatus("NoS");
        //    }
        //    else if(bord->SDM.SADMC.getSupervision_status() == "NoS")
        //    {
		//		if(bord->TrainRI.T_data.getVtrain()<= train.getVbut())
		//			aiguilleColor = GREY;
		//		else
		//			aiguilleColor = WHITE;
        //        actualisationVitesse(0, 0, 0, bord->SDM.MRSP.getV_MRSP(), train.getVrelease(), train.getVbut());
        //        if(bord->TrainRI.T_data.getVtrain() < bord->SDM.MRSP.getV_MRSP())
        //            train.setStatus("NoS");
        //    }
        //}

		else if(bord->SDM.SL.getStatus() == "TSM")
		{
			if(bord->SDM.SADMC.getSupervision_status() == "Intervention")
			{
				//if(T_D->getV_train() <= bord->SDM.MRSP.getV_MRSP())
				//{
				//	aiguilleColor = GREY;
				//	actualisationVitesse(0, 0, bord->SDM.MRSP.getV_MRSP(), 0, 0, 0);
				//}
				//else
				//{
					aiguilleColor = RED;
					//actualisationVitesse(bord->SDM.SL.getV_ebi(), 0, bord->SDM.MRSP.getV_MRSP(), 0, 0, 0);
					actualisationVitesse(T_D->getV_train(), 0, bord->SDM.SL.getV_permitted(), 0, 0, bord->TrackRI.SADL.getSpeedTarget());
				//}

			}
			else if(bord->SDM.SADMC.getSupervision_status() == "Warning")
			{
				aiguilleColor = ORANGE;
				actualisationVitesse(0, bord->SDM.SL.getV_ebi(), bord->SDM.SL.getV_permitted(), 0, 0, bord->TrackRI.SADL.getSpeedTarget());

			}
			else if(bord->SDM.SADMC.getSupervision_status() == "Overspeed")
			{
				aiguilleColor = ORANGE;
				actualisationVitesse(0, bord->SDM.SL.getV_ebi(), bord->SDM.SL.getV_permitted(), 0, 0, bord->TrackRI.SADL.getSpeedTarget());
			}
			else if(bord->SDM.SADMC.getSupervision_status() == "Indication")
			{
				aiguilleColor = YELLOW;
				actualisationVitesse(0,0,bord->SDM.SL.getV_permitted(),0,0, bord->TrackRI.SADL.getSpeedTarget());
			}
			else if(bord->SDM.SADMC.getSupervision_status() == "Normal")
			{
				aiguilleColor = GREY;
				actualisationVitesse(0, 0, 0, 0, 0, bord->SDM.SL.getV_permitted());
			}
		}
		else if(bord->SDM.SL.getStatus() == "RSM")
		{
			aiguilleColor = YELLOW;
			actualisationVitesse(0, 0, bord->SDM.SL.getV_permitted(), 0, 0, 0);
		}
	}
	//else if(bord->getGeneralMode() == "LS")
	//{
	//	if(bord->SDM.getStatus() == "CSM")
	//	{
//
	//	}
	//	else if(bord->SDM.getStatus() == "PIM")
	//	{
//
	//	}
	//	else if(bord->SDM.getStatus() == "TSM")
	//	{
//
	//	}
	//	else if(bord->SDM.getStatus() == "RSM")
	//	{
//
	//	}
	//}
	//else if(bord->getGeneralMode() == "SR/UN")
	//{
	//	if(bord->SDM.getStatus() == "CSM")
	//	{
//
	//	}
	//	else if(bord->SDM.getStatus() == "PIM")
	//	{
//
	//	}
	//	else if(bord->SDM.getStatus() == "TSM")
	//	{
//
	//	}
	//}
	//else if(bord->getGeneralMode() == "SH/RV")
	//{
	//	if(bord->SDM.getStatus() == "CSM")
	//	{
//
	//	}
	//}
	//else if(bord->getGeneralMode() == "NL/SB/PT")
	//{
//
	//}
	//else if(bord->getGeneralMode() == "TR")
	//{
//
	//}

}

void Cadran::actualisationVitesse(double red, double orange, double yellow, double white, double mediumGrey, double darkGrey)
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


DonneesAfficheurVitesse::DonneesAfficheurVitesse(V2f &centre, float &teta_origine)
{
	this->centre = &centre;
	this->teta_origine = &teta_origine;
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
	m_cartesiens.x = centre->x - (-1) * m_polaire.x * (float)cos((m_polaire.y - *teta_origine) * PI / 180.0f); //PI/180 permet de passer de la valeur de radians a une valeur en degree
	m_cartesiens.y = centre->y - (-1) * m_polaire.x * (float)sin((m_polaire.y - *teta_origine) * PI / 180.0f); // le facteur -1 permet de se mettre dans le cas du cercle trigonometrique
}

void DonneesAfficheurVitesse::cartesiens(V2f cartesiens) {m_cartesiens = cartesiens;}
void DonneesAfficheurVitesse::x(int x) {m_cartesiens.x = (float)x;} // set x
void DonneesAfficheurVitesse::y(int y) {m_cartesiens.y = (float)y;} // set y
void DonneesAfficheurVitesse::r(int r) {m_polaire.x = (float)r;} // set r
void DonneesAfficheurVitesse::teta(int teta) {m_polaire.y = (float)teta;} // set teta
void DonneesAfficheurVitesse::vitesse(int vitesse) {m_vitesse = vitesse;} // set vitesse
V2f DonneesAfficheurVitesse::cartesien() {return m_cartesiens;}
V2f DonneesAfficheurVitesse::polaire() {return m_polaire;}
double DonneesAfficheurVitesse::x() {return m_cartesiens.x;}
double DonneesAfficheurVitesse::y() {return m_cartesiens.y;}
double DonneesAfficheurVitesse::r() {return m_polaire.x;}
double DonneesAfficheurVitesse::teta() {return m_polaire.y;}
int DonneesAfficheurVitesse::vitesse() {return m_vitesse;}