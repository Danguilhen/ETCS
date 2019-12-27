#include "LeftSide.hpp"

LeftSide::LeftSide(Data &data, RenderWindow &fenetre, ETCS_Bord &bord, vector<Symbol> &symbol) : cadran(400, data, fenetre, bord), symbol(&symbol)
{
}

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

void LeftSide::leftSide()
{
	creation_rectangle(V2f(0, 0), V2f(54, 54), 1);															//A1
	creation_rectangle(V2f(0, 54), V2f(54, (191 + 30)), 1);													//A2-3
	creation_rectangle(V2f(0, (54 +30 + 191)), V2f(54, 25), 1);												//A4
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25)), V2f(54, 25), 1);										//C8
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 2)), V2f(54, 25), 1);									//C9
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 3)), V2f(54, 25), 1);									//E1
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 4)), V2f(54, 25), 1);									//E2
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 5)), V2f(54, 25), 1);									//E3
	creation_rectangle(V2f((54 + 3 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 1);							//C1
	creation_rectangle(V2f(54, 0), V2f(280, 300), 1);														//B
	creation_rectangle(V2f(54, (54 + 30 + 191 + 25 + 50)), V2f(234, 4 * 20), 1);							//E5-6-7-8
	creation_rectangle(V2f((54 + 234), (54 + 30 + 191 + 25 + 50)), V2f(46, 40), 2);							//E10
	creation_rectangle(V2f((54 + 234), (54 + 30 + 191 + 25 + 50 + 40)), V2f(46, 40), 2);					//E11
	creation_rectangle(V2f((54 + 26 - 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), 1);						//B6
	creation_rectangle(V2f((54 + 140 + 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), 1);						//B5
	creation_rectangle(V2f((54 + 140 - 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), 1);						//B4
	creation_rectangle(V2f((54 + 140 - 36 * 3 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), 1);					//B3
	creation_rectangle(V2f((54 + 254 - 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), 1);						//B7

	/*if(data->getConnection() == "Up") //Connection Up
	{
		ST_03.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 * 3 + 25 / 2.0));	//E1
	}
	else if(data->getConnection() == "Lost/Set-Up failed") //Connection Lost/Set-Up failed
		ST_04.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 * 3 + 25 / 2.0));	//E1
	if(data->getReversing() == "Permitted") //Reversing permitted indication
		ST_06.afficher(V2f(54 + 37 * 3 + 58 + 37 + 37 / 2.0, 300 + 50 / 2.0));	//C6

	if(version == "3.6.0")
	{
		data->setTTI((data->getDEOA() - (3 / 5.0)*data->getD_but())/(bord->TrainRI.T_data.getVtrain()/3.6)); // TEMPORAIRE POUR LA DEMO
		//Rappel TTIdisp est à 14 s selon la subset026
		if((data->getGeneralMode() == "FS" || ((data->getGeneralMode() == "OS" || data->getGeneralMode() == "SR") && TTI == "On")) && (data->getMode() == "CSM" || data->getMode() == "PIM") && data->getTTI() < 14)  //A1 : TTI
		{
			if(temp_TTI == 0)
			{
				son.jouer_alarmes(2, 1);
				temp_TTI = 1;
			}
			rectangle(V2f(2,2), V2f(50, 50), DARK_GREY);
			for(int n = 0; n <= 10; n++)
			{
				if(14*(10 - n)/10 <= data->getTTI() && data->getTTI() < 14*(10 - (n - 1))/10)
					rectangle(V2f(54/2 - 2.5*n, 54/2 - 2.5*n), V2f(n*5,n*5), WHITE);
			}
		}
		else
			temp_TTI = 0;

		SSI.setPosition(V2f(local2globalCoordonates(centreIV, 90 + 144, V2f(111 * RE, graduations[20].teta() - abs(graduations[0].teta() - graduations[1].teta()) / 2.0)).x - 6 * RE, local2globalCoordonates(centreIV, 90 + 144, V2f(111 * RE, graduations[20].teta() - abs(graduations[0].teta() - graduations[1].teta()) / 2.0)).y - 6 * RE));
		fenetre.draw(SSI);
	}
	if(version == "3.4.0")		//Voir avec benoit
	{
		LS_01.afficher(V2f(54 / 2.0, 54 / 2.0));	//A1
		creation_texte(to_string(LSSMA), GREY, 16, 0, V2f(54 / 2.0, 54 / 2.0), 1); //400km/h
	}*/

	if(data->getLevel() == "Level 0")
        LE_01.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 + 25 / 2.0));
    else if(data->getLevel()  == "Level 1")
        LE_03.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 + 25 / 2.0));
    else if(data->getLevel()  == "Level 2")
        LE_04.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 + 25 / 2.0));
    else if(data->getLevel()  == "Level 3")
        LE_05.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 + 25 / 2.0));

	//if((data->getGeneralMode() == "FS" && (data->getMode() == "PIM" || data->getMode() == "TSM" || data->getMode() == "RSM")) || data->getGeneralMode() == "RV")
	//	targetDistance(data->getDEOA());

	//TexteMessages();//special class texte

	SE_04.afficher(V2f(64 * 4 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0));			//F5
	DR_01.afficher(V2f(64 * 6 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0));			//F7
	NA_13.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 3 + 64 / 2.0));	//H5
	NA_14.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 4 + 64 / 2.0));	//H6
	NA_17.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2 + 64 / 2.0));	//H4
	NA_18.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0));		//H3
	NA_20.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 5 * 64 + 82 / 2.0));	//H7
	DR_04.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 5 * 64 + 82 / 2.0));	//H7

	targetDistance(1000);
	cadran.update();
}