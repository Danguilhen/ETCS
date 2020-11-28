#include "PCC.hpp"
/*
PCC::PCC(Software &softw, Train_dynamique &T_D)
{
	this->soft = &softw;
	this->temp_T_D = &T_D;
	echelle = double(soft->getFenPcc()->getSize().x - 2*marge) / distance_max_affichable;
	std::ifstream ig("C:/Users/nicol/OneDrive/Bureau/ETCS/src/canton.json");
	ig >> liste_canton;

}

void PCC::update()
{
	soft->getFenPcc()->clear();
	//cout << echelle << endl;
	RectangleShape fond;
	fond.setSize(V2f(soft->getFenPcc()->getSize().x, soft->getFenPcc()->getSize().y));
	fond.setFillColor(GREY);
	soft->getFenPcc()->draw(fond);
	rail(40500);
	train();
	soft->getFenPcc()->display();
}

void PCC::rail(double grandeur_longitudinale)
{
	RectangleShape rail;
	double iteration = 1;
	int distance_affichee = 0;
	while(distance_affichee + iteration*distance_max_affichable <= grandeur_longitudinale)
	{
		rail.setFillColor(BLACK);
		rail.setSize(V2f(distance_max_affichable * echelle, largeur_rail));
		rail.setPosition(marge, ecart_entre_rangee*iteration);
		//cout << " x " << rail.getPosition().x << " y " << rail.getPosition().y << endl;
		soft->getFenPcc()->draw(rail);
		iteration++;
	}
	rail.setFillColor(BLACK);
	rail.setSize(V2f((grandeur_longitudinale - (iteration-1)*distance_max_affichable) * echelle, largeur_rail));
	rail.setPosition(marge, ecart_entre_rangee*iteration);
	//cout << grandeur_longitudinale - iteration*distance_max_affichable << endl;
	//cout << " x " << rail.getPosition().x << " y " << rail.getPosition().y << endl;
	soft->getFenPcc()->draw(rail);
}

void PCC::train()
{
	RectangleShape train;
	double iteration = 1;
	while (temp_position_train > iteration*distance_max_affichable)
	{
		iteration ++;
	}
	train.setFillColor(RED);
	train.setSize(V2f(200 * echelle, largeur_rail)); // ici renseigné grandeur du train
	train.setPosition(marge + (temp_position_train - (iteration-1)*distance_max_affichable) * echelle, 100*iteration);
	temp_position_train = temp_position_train + temp_T_D->getDistance_Uptdate();
	//cout << " x " << rail.getPosition().x << " y " << rail.getPosition().y << endl;
	//cout << "distance parcourue : " << temp_position_train << endl;
	soft->getFenPcc()->draw(train);

}
*/