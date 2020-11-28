#include "Train_dynamique.hpp"

Train_dynamique::Train_dynamique(Reseau &res, Train_statique &stat)
{
	this->res = &res;
	this->stat = &stat;
}

double Train_dynamique::getV_train(){return V_train;}
void Train_dynamique::setV_train(double V){V_train = V;}
double Train_dynamique::getDistance_Uptdate(){return distance_update;}
int Train_dynamique::getTraction(){return traction;}
void Train_dynamique::setTraction(int A){traction = A;}



void Train_dynamique::update()
{
	//cout << V_train << endl;
	if(!res->getPupitre_entrant().pupitre.empty()) // TEMPORAIRE
		traction = stoi(res->getPupitre_entrant().pupitre); // TEMPORAIRE
	//cout << traction << endl; // TEMPORAIRE
	effortResultant();
	if(!freinage_urgence)
		determinationValeurManip();
	if(coefManip >= 0)
		effortTraction();
	else
		effortFreinageTemp();
	//effortFreinage();
	//cout << gamma << endl;
	calculVitesse();
	calculDistance();
	partage_reseau();
}

void Train_dynamique::partage_reseau()
{
	res->setRes_vitesse(V_train);
}

void Train_dynamique::effortResultant()
{
	///////// calcul de RAV
	Rav = A + B*V_train + C*(V_train*V_train);
	Rp = masse*9.81*(i/1000);

	if (V_train == 0)
	{
		if (typeTrain == 0)
		{
			if (i <= 18)
			{
				Rd = (masse/100)*(i*0.981 + 6.8);
				Rd0 = (masse/100)*6.8;
			}
			else if (i > 17)
			{
				Rd = (masse/100)*(1.25*i*0.981 + 2.75);
				Rd0 = (masse/100)*2.75;
			}
		}
		else if (typeTrain == 1)									/// FAIRE ATTENTION UNITE DE i
		{
			if (i <= 7)
			{
				Rd = (masse/100)*(i*0.981 + 4.5);
				Rd0 = (masse/100)*4.5;
			}
			else if (i > 7)
			{
				Rd = (masse/100)*(1.25*i*0.981 + 2.75);
				Rd0 = (masse/100)*2.75;
			}
		}
	}
	else if (V_train != 0)
	{
		Rd = 0;
	}
	//cout << Rd << endl;
	Fres = Rav + Rd + Rp;
}

void Train_dynamique::determinationValeurManip()
{
	valeurManip = traction;
	//cout << valeurManip << endl;

	if (valeurManip > 484 && valeurManip < 540)
	{
		coefManip = 0;
	}
	else if (valeurManip >= 540)
	{
		coefManip = (valeurManip - 540.0);
		coefManip = coefManip/483.0;
		coefManip = - coefManip;
	}
	else if (valeurManip < 470)
	{
		coefManip = (valeurManip - 470.0) /470.0;
		coefManip = - coefManip;
	}
	//cout << coefManip << endl;
}

void Train_dynamique::effortTraction()
{
	gamma = 0;
	if (V_train == 0.0)
	{
		Rp =  Rd - Rd0;
		if (abs(Ftraction*coefManip - Rp) > Rd0)
		{
		Ft = (Ftraction*coefManip - Rd - Rp);
		gamma = Ft / (masse*k);
		}
		else if (abs(Ftraction*coefManip - Rp) <= Rd0)
		{
			V_train = 0;
		}
	}
	else
	{
		if (coefManip == 0)
		{
			Ft = -Fres;
			gamma = Ft / (masse*k);
		}
		else if (abs(Ptraction*coefManip) / (abs(V_train/3.6)) >= abs(Ftraction*coefManip))                     // le train travail à sa force de trction max pour des vitesses relativement faible.
		{
			//cout << "1 er cas" << endl;
		Ft = (Ftraction*coefManip - Fres); // ne patine pas
		gamma = Ft / (masse*k);
		}
		else if (abs(Ptraction*coefManip) / (V_train/3.6) < abs(Ftraction*coefManip))          // le train travail au max de sa puissance.
		{
			//cout << "2eme cas" << endl;
		F = Ptraction*coefManip / (V_train/3.6);
		Ft = (F - Fres);
		gamma = Ft / (masse*k);
		}
	}
	adherence();
	//cout << "gamma = " << gamma << endl;
}

void Train_dynamique::adherence()
{

	mudyn = mumax / (1 + glissement);
	Q = nbEssieuMoteur*masseEssieu*9.81;  // en kN

	if ( FtractionAdher > mudyn*Q )
	{
		Freac = mudyn*Q;
		Fessieu = FtractionAdher - Freac;

		if (FtractionAdher > Freac)
		{
			Ftransmis = Freac;
		}
		else if (FtractionAdher < Freac)
		{
			Ftransmis = FtractionAdher;
		}

		gamma = (Ftransmis - Fres) / (k*masse);
		gammaEssieu = Fessieu / (nbEssieuMoteur*(masseEssieuMoteur + mTournanteEssieuMoteur)) + gamma;
	}

	else if ( FtractionAdher <= mudyn*Q && glissement != 0 )
	{
		Freac = mudyn*Q;
		Fessieu = FtractionAdher - Freac;

		if (FtractionAdher > Freac)
		{
			Ftransmis = Freac;
		}
		else if (FtractionAdher < Freac)
		{
			Ftransmis = FtractionAdher;
		}

		gamma = (Ftransmis - Fres) / (k*masse);
		gammaEssieu = Fessieu / (nbEssieuMoteur*(masseEssieuMoteur + mTournanteEssieuMoteur)) + gamma;

	//	cout << "test" << endl;
		//cout << "mudyn" << mudyn << endl;
	}
	else gammaEssieu = gamma;
}

void Train_dynamique::effortFreinage()
{
	/*
		if (Ptraction*coefManip / (abs(V_train/3.6)) >= Ftraction*coefManip)                     // le train travail à sa force de trction max pour des vitesses relativement faible.
		{
		Ft = (Ftraction*coefManip - Fres); // ne patine pas
		gamma = Ft / (masse*k);
		}
		else if (Ptraction*coefManip / (V_train/3.6) < Ftraction*coefManip)          // le train travail au max de sa puissance.
		{
		F = Ptraction*coefManip / (V_train/3.6);
		Ft = (F - Fres);
		gamma = Ft / (masse*k);
		}*/
		//cout << "freinage" << endl;
		if(V_train > 50.0)
		{
			if(valeurManip > F1)
			{
				//En freinage par récupération
				double temp_coef;
				temp_coef = (470.0 - valeurManip) /(470.0 - 286.0);
				if (abs(Ptraction*temp_coef) / (abs(V_train/3.6)) >= abs(Ftraction*temp_coef))                     // le train travail à sa force de trction max pour des vitesses relativement faible.
				{
					//cout << "1 er cas" << endl;
					Ft = - (Ftraction*temp_coef + Fres); // ne patine pas
					gamma = Ft / (masse*k);
				}
				else if (abs(Ptraction*temp_coef) / (V_train/3.6) < abs(Ftraction*temp_coef))          // le train travail au max de sa puissance.
				{
				//	cout << "2eme cas" << endl;
					F = Ptraction*temp_coef / (V_train/3.6);
					Ft = - (F + Fres);
					gamma = Ft / (masse*k);
				}
				/*double temp_coef;
				temp_coef = (470.0 - valeurManip) /(470.0 - 286.0);
				Ft = - (Ptraction*temp_coef / (V_train/3.6) + Fres);
				cout << Ft << endl;
				gamma = Ft / (masse*k);*/
			}
			else if(valeurManip < F1 && valeurManip > F2)
			{
				if (abs(Ptraction) / (abs(V_train/3.6)) >= abs(Ftraction))                     // le train travail à sa force de trction max pour des vitesses relativement faible.
				{
					Ft = - Ftraction; // ne patine pas
				}
				else if (abs(Ptraction) / (V_train/3.6) < abs(Ftraction))          // le train travail au max de sa puissance.
				{
					F = Ptraction / (V_train/3.6);
					Ft = - F;
				}
				//produit en croix pour déterminer l'application des freins pneumatiques des bogies porteurs
				Ft = Ft - freinagePneumatiqueRemorque() - Fres;
				gamma = Ft / (masse*k);
			}
		}
}

void Train_dynamique::freinageUrgence()
{
	if (freinage_urgence)
	{
		coefManip = -1;
	}
	if ((int)V_train == 0)
	{
		freinage_urgence = false;
	}
}

void Train_dynamique::effortFreinageTemp()
{
	freinageUrgence();
	if(V_train > 300.0)
	{
		gamma = 0.675 * coefManip;
	}
	else if(V_train > 230.0)
	{
		gamma = 0.65 * coefManip;
	}
	else if(V_train > 170.0)
	{
		gamma = 0.79 * coefManip;
	}
	else if(V_train > 0.0)
	{
		gamma = 0.86 * coefManip;
	}
}

double Train_dynamique::freinagePneumatiqueRemorque()
{
	if(V_train > 220.0)
		return (F1 - valeurManip) * (40.0 - (0.5*40)/1.5) / (F1 - F2); // 13.3 correspond la dépression de 4.5 bars dès le passage de F1 40 KN
	else if (V_train < 200)
		return (F1 - valeurManip) * (60.0 - (0.5*60)/1.5) / (F1 - F2); // 20.0 correspond la dépression de 4.5 bars dès le passage de F1 60 KN
	else
	{
		// si entre les max et mins
		double resultat_produit_en_croix = -(220 - V_train);
		return (F1 - valeurManip) * (60.0 - resultat_produit_en_croix - (0.5*(60 - resultat_produit_en_croix))/1.5) / (F1 - F2); // 20.0 correspond la dépression de 4.5 bars dès le passage de F1 60 KN
	}
}
/*double Train_dynamique::freinagePneumatiqueMotrice()
{

}*/


void Train_dynamique::calculVitesse()
{
	double NVitesse;      // nouvelle vitesse tampon
	NVitesse = gamma*deltats*3.6;
	V_train = NVitesse + V_train;

}

void Train_dynamique::calculDistance()
{
	diftime = chrono.getElapsedTime();
	deltats = diftime.asSeconds();
	distance_update = deltats*V_train/3.6; // mise à  jour distance parcourue
	chrono.restart();
}