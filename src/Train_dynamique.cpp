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
	float coefManip = 0.95; // coef multiplicateur de la puissance envoyé par le conducteur avec le manip
	float Rav;			// resistance avancement
	float Rp;  // resistance profil
	float Rd=0;
	float gamma;

	traction = 800;
	valeurManip = traction;
/*
	if (valeurManip >= 512 && valeurManip <540)
	{
		coefManip = 0;
	}
	else coefManip = (valeurManip - 511)/512;
*/
	///////// calcul de RAV
	Rav = A + B*V_train + C*(V_train*V_train);
	Rp = masse*9.81*i;

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

	//// on calcule gamma
	diftime = chrono.getElapsedTime();
	deltats = diftime.asSeconds();
	gamma = (V_train/3.6)/deltats;
	chrono.restart();

	/// on calcul Ft
	if (V_train == 0)
	{
		Ft = Rd*coefManip;
	}
	else if (V_train != 0)
	{
		Ft = (Rav + Rp)*coefManip;
	}

	puissance = Ft*V_train;
	cout << "Ft = " << Ft << endl;
	cout << "Rav = " << Rav << endl;
	cout << "gamma = " << gamma << endl;
	//cout << "coefmanip = " << coefManip << endl;
	//cout << "Rp = " << Rp << endl;
	//cout << "delata = " << deltats << endl;
	//cout << "valeurmanip = " << valeurManip << endl;
	cout << "PUISSANCE =" << puissance << endl;
}


void Train_dynamique::calculVitesse()
{
	float NVitesse;      // nouvelle vitesse tampon
	float gamma2;         // nouvelle valeur de gamma dont on vas déduire la vitesse final

	if (puissance < Ptraction)
	{
	gamma2 = Ft / masse;
	diftime = chrono.getElapsedTime();
	deltats = diftime.asSeconds();
	NVitesse = gamma2*deltats*3.6;
	chrono.restart();
	V_train = NVitesse + V_train;

	}
	cout << "v train =" << V_train << endl << endl;
	cout << "nv train =" << NVitesse << endl << endl;



}

