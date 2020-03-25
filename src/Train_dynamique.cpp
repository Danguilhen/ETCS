#include "Train_dynamique.hpp"

float Train_dynamique::getV_train(){return V_train;}
void Train_dynamique::setV_train(float V){V_train = V;}
float Train_dynamique::getDistance_Uptdate(){return distance_update;}
float Train_dynamique::getTraction(){return traction;}
void Train_dynamique::setTraction(float A){traction = A;}



void Train_dynamique::update()
{
	effortTraction();
	calculVitesse();
}

/*
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
*/


void Train_dynamique::effortTraction()
{
	float coefManip=0; // coef multiplicateur de la puissance envoyé par le conducteur avec le manip
	float Rav;			// resistance avancement
	float Rp;  // resistance profil
	float Rd=0;
	float Fres;
	float F;
	float Ft;

	valeurManip = traction;

	if (valeurManip > 512 && valeurManip < 540)
	{
		coefManip = 0;
	}
	else if (valeurManip >= 540)
	{
		coefManip = (valeurManip - 511);
		coefManip = coefManip/512;
		//int test1 = 6;
		//cout << test1 << endl;
	}
	else if (valeurManip < 512)
	{
		coefManip = 0;
		//int test = 5;
		//cout << test << endl;
	}

	cout << "coefmanip = " << coefManip << endl;
	cout << "valeurmanip = " << valeurManip << endl;
	//cout << "trac = " << traction << endl;

	///////// calcul de RAV
	Rav = A + B*V_train + C*(V_train*V_train);
	Rp = masse*9.81*i;

	if (V_train == 0)
	{
		if (typeTrain == 0)
		{
			if (i <= 18)
			{
				Rd = (masse/100)*(i*981 + 6.8);
			}
			else if (i > 17)
			{
				Rd = (masse/100)*(1.25*i*981 + 2.75);
			}
		}
		else if (typeTrain == 1)									/// FAIRE ATTENTION UNITE DE i
		{
			if (i <= 7)
			{
				Rd = (masse/100)*(i*981 + 4.5);
			}
			else if (i > 7)
			{
				Rd = (masse/100)*(1.25*i*981 + 2.75);
			}
		}
	}
	else if (V_train != 0)
	{
		Rd = 0;
	}

	Fres = Rav + Rd + Rp;
	F = Ptraction / (V_train/3.6);   // en kN
	if (F > Ftraction)
	{
		Ft = (Ftraction - Fres)*coefManip;
		gamma = Ft / (masse*k);
		int passe=1;
		cout << passe << endl;
	}
	else if (F < Ftraction)
	{
		Ft = (F - Fres)*coefManip;
		gamma = Ft / (masse*k);
		int passe=2;
		cout << passe << endl;
	}
	//cout << "gamma = " << gamma << endl;
}


void Train_dynamique::calculVitesse()
{
	float NVitesse;      // nouvelle vitesse tampon
	diftime = chrono.getElapsedTime();
	deltats = diftime.asSeconds();
	NVitesse = gamma*deltats*3.6;
	chrono.restart();
	V_train = NVitesse + V_train;


	//cout << "v train =" << V_train << endl << endl;



}

