#include "Train_dynamique.hpp"

float Train_dynamique::getV_train(){return V_train;}
void Train_dynamique::setV_train(float V){V_train = V;}

void Train_dynamique::update()
{
	mouvementTrain();
}

void Train_dynamique::mouvementTrain()
{
	diftime = chrono.getElapsedTime();
	deltats = diftime.asSeconds();
	if(traction > 100)
		traction = 100;
	if(traction < - 100)
		traction = -100;
	V_train = 3.6*(1.2*traction/100*deltats + V_train/3.6); // A TITRE D EXEMPLE ATTENTION
	distance_update = deltats*V_train/3.6;
	chrono.restart();
	//cout << traction << endl;
}


float Train_dynamique::getDistance_Uptdate(){return distance_update;}
float Train_dynamique::getTraction(){return traction;}
void Train_dynamique::setTraction(float A){traction = A;}

