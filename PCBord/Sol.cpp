#include "Sol.hpp"
/*
Sol::Sol(Virtual_train &v_train)
{
	this->v_train = &v_train;
	derniere_position_connu = v_train.etcs.Bord.TrackRI.getPointKilometrique();
	lecture_JSON();
}

void Sol::update()
{
	gestion_CDV();
	RBC();
}

void Sol::gestion_CDV()
{
	//cout << v_train->etcs.Bord.TrackRI.getPointKilometrique()/1000 - double(v_train->etcs.Bord.TrainRI.T_data.getTrain_length()/1000.0) << endl;
	size_t i = 0;
	for (i = 0; i < liste_canton.size(); i++)
	{
		if((v_train->etcs.Bord.TrackRI.getPointKilometrique()/1000 >= liste_canton[i]["PK_debut"] && v_train->etcs.Bord.TrackRI.getPointKilometrique()/1000 < liste_canton[i]["PK_fin"])
		|| (v_train->etcs.Bord.TrackRI.getPointKilometrique()/1000 - double(v_train->etcs.Bord.TrainRI.T_data.getTrain_length()/1000.0) >= liste_canton[i]["PK_debut"] && v_train->etcs.Bord.TrackRI.getPointKilometrique()/1000 - double(v_train->etcs.Bord.TrainRI.T_data.getTrain_length()/1000.0) < liste_canton[i]["PK_fin"] ))
		{
			liste_canton[i]["occupation"] = 1;
		}
		else
		{
			liste_canton[i]["occupation"] = 0;
		}
		//cout << i << " " << liste_canton[i]["occupation"] << endl;
	}
	derniere_position_connu = v_train->etcs.Bord.TrackRI.getPointKilometrique();
}

void Sol::RBC()
{
	//Relire les JSON si procède à une modification

	if(event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
	{
		cout << "MAJ" << endl;
		lecture_JSON();
	}

	//Déterminer MA



	//Mettre à jour tableau Vitesse

	//Mettre à jour tableau Gradient

	//Mettre à jour tableau Annoucements


}

void Sol::lecture_JSON()
{
	//std::ifstream ig("C:/Users/nicol/OneDrive/Bureau/ETCS/src/canton.json");
	//ig >> liste_canton;
}

/*void Sol::determination_MA()
{
	size_t i = 0;
	vector <double> MA;
	while (liste_canton[i]["PK_fin"] > v_train->etcs.Bord.TrackRI.getPointKilometrique())
	{
		i++;
	}

	for (size_t ite = i; ite < liste_canton.size(); ite++)
	{
		if (liste_canton[i]["occupation"] == 1)
		{
			break;
		}
	}
	if (ite == liste_canton.size())
	{
		MA = {}
	}
	v_train->etcs.Bord.TrackRI.TSR.getVitesseTableau().push_back()


	
}*/
