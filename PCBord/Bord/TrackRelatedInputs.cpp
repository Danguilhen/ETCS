
#include "TrackRelatedInputs.hpp"

National_Value_Data::National_Value_Data()
{
Q_NVDRIVER_ADHES = 0;
V_NVSHUNT = 30;
V_NVSTFF = 40;
V_NVONSIGHT = 30;
V_NVLIMSUPERV = 100;
V_NVUNFIT = 100;
V_NVREL = 40;
D_NVROLL = 2;
Q_NVSBTSMPERM = 1;
Q_NVEMRRLS = 0;
Q_NVGUIPERM = 0;
Q_NVSBFBPERM = 0;
Q_NVINHSMICPERM = 0;
V_NVALLOWOVTRP = 0;
V_NVSUPOVTRP = 30;
D_NVOVTRP = 200;
T_NVOVTRP = 60;
M_NVDERUN = 1;
M_NVCONTACT = 0;
T_NVCONTAC = INFINITY;
D_NVPOTRP = 200;
D_NVSTFF = INFINITY;
Q_NVLOCACC = 12;
M_NVAVADH = 1;
M_NVEBCL = 0.999999999;
L_NVKRINT = 0;
M_NVKRINT = 0.9;
V_NVKVINT = 0;
M_NVKVINT = 0.7;
M_NVKTINT = 1.1;
A_NVMAXREDADH1 = 1;
A_NVMAXREDADH2 = 0.7;
A_NVMAXREDADH3 = 0.7;
A_NVP12 = 0;
A_NVP23 = 0;
}

void National_Value_Data::Afficher_National_value_data()
{
cout<< "vous trouverez ci-dessous les National_value_data" << endl << endl;
cout << "Q_NVDRIVER_ADHES = " <<  Q_NVDRIVER_ADHES << " allow" << endl;
cout << "V_NVSHUNT = " << V_NVSHUNT << " km/h" << endl;
cout << "V_NVSTFF = " << V_NVSTFF <<  " km/h" << endl;
cout << "V_NVONSIGHT = " << V_NVONSIGHT <<" km/h" << endl;
cout << "V_NVLIMSUPERV = " << V_NVLIMSUPERV <<" km/h" << endl;
cout << "V_NVUNFIT = " << V_NVUNFIT <<" km/h" << endl;
cout << "D_NVROLL = " << D_NVROLL <<" m" << endl;
cout << "Q_NVSBTSMPERM = " << Q_NVSBTSMPERM <<" yes/no" << endl;
cout << "Q_NVEMRRLS = " << Q_NVEMRRLS << " yes/no" << endl;
cout << "Q_NVGUIPERM = " << Q_NVGUIPERM << " yes/no" << endl;
cout << "Q_NVSBFBPERM = " << Q_NVSBFBPERM << " yes/no" << endl;
cout << "Q_NVINHSMICPERM = " << Q_NVINHSMICPERM << " yes/no" << endl;
cout << "V_NVALLOWOVTRP = " <<V_NVALLOWOVTRP << " km/h" << endl;
cout << "V_NVSUPOVTRP = " << V_NVSUPOVTRP << " km/h" << endl;
cout << "D_NVOVTRP = " << D_NVOVTRP << " m" << endl;
cout << "T_NVOVTRP = " << T_NVOVTRP << " s" << endl;
cout << "M_NVDERUN = " << M_NVDERUN << " yes/no" << endl;
cout << "M_NVCONTACT = " << M_NVCONTACT << " U" << endl;
cout << "T_NVCONTAC = " << T_NVCONTAC << " s" << endl;
cout << "D_NVPOTRP = " << D_NVPOTRP << " m" << endl;
cout << "D_NVSTFF = " << D_NVSTFF << " m" << endl;
cout << "Q_NVLOCACC = " << Q_NVLOCACC << " m" << endl;
cout << "M_NVAVADH = " << M_NVAVADH << " U" << endl;
cout << "M_NVEBCL = " << M_NVEBCL << " U" << endl;
cout << "L_NVKRINT = " << L_NVKRINT << " correction factor" << endl;
cout << "M_NVKRINT = " << M_NVKRINT << " correction factor" << endl;
cout << "V_NVKVINT = " << V_NVKVINT << " km/h" << endl;
cout << "M_NVKVINT = " << M_NVKVINT << " U" << endl;
cout << "M_NVKTINT = " << M_NVKTINT << " U" << endl;
cout << "A_NVMAXREDADH1 = " << A_NVMAXREDADH1 << " m/s²" << endl;
cout << "A_NVMAXREDADH2 = " << A_NVMAXREDADH2 << "m/s²" << endl;
cout << "A_NVMAXREDADH3 = " << A_NVMAXREDADH2 << "m/s²" << endl;
cout << "A_NVP12 = " << A_NVP12 << "m/s²" << endl;
cout << "A_NVP23 = " << A_NVP23 << "m/s²" << endl;
cout<<endl<< "National_value_data" << endl << endl;

}

bool National_Value_Data::getQ_NVDRIVER_ADHES()
{return Q_NVDRIVER_ADHES;}
int National_Value_Data::getV_NVSHUNT()
{return V_NVSHUNT;}
int National_Value_Data::getV_NVSTFF()
{return V_NVSTFF;}
int National_Value_Data::getV_NVONSIGHT()
{return V_NVONSIGHT;}
int National_Value_Data::getV_NVLIMSUPERV()
{return V_NVLIMSUPERV;}
int National_Value_Data::getV_NVUNFIT()
{return V_NVUNFIT;}
int National_Value_Data::getV_NVREL()
{return V_NVREL;}
double National_Value_Data::getD_NVROLL()
{return D_NVROLL;}
bool National_Value_Data::getQ_NVSBTSMPERM()
{return Q_NVSBTSMPERM;}
bool National_Value_Data::getQ_NVEMRRLS()
{return Q_NVEMRRLS;}
bool National_Value_Data::getQ_NVGUIPERM()
{return Q_NVGUIPERM;}
bool National_Value_Data::getQ_NVSBFBPERM()
{return Q_NVSBFBPERM;}
bool National_Value_Data::getQ_NVINHSMICPERM()
{return Q_NVINHSMICPERM;}
int National_Value_Data::getV_NVALLOWOVTRP()
{return V_NVALLOWOVTRP;}
int National_Value_Data::getV_NVSUPOVTRP()
{return V_NVSUPOVTRP;}
int National_Value_Data::getD_NVOVTRP()
{return D_NVOVTRP;}
double National_Value_Data::getT_NVOVTRP()
{return T_NVOVTRP;}
bool National_Value_Data::getM_NVDERUN()
{return M_NVDERUN;}
bool National_Value_Data::getM_NVCONTACT()
{return M_NVCONTACT;}
double National_Value_Data::getT_NVCONTAC()
{return T_NVCONTAC;}
double National_Value_Data::getD_NVPOTRP()
{return D_NVPOTRP;}
double National_Value_Data::getD_NVSTFF()
{return D_NVSTFF;}
double National_Value_Data::getQ_NVLOCACC()
{return Q_NVLOCACC;}
double National_Value_Data::getM_NVAVADH()
{return M_NVAVADH;}
double National_Value_Data::getM_NVEBCL()
{return M_NVEBCL;}
double National_Value_Data::getL_NVKRINT()
{return L_NVKRINT;}
double National_Value_Data::getM_NVKRINT()
{return M_NVKRINT;}
double National_Value_Data::getV_NVKVINT()
{return V_NVKVINT;}
double National_Value_Data::getM_NVKVINT()
{return M_NVKVINT;}
double National_Value_Data::getM_NVKTINT()
{return M_NVKTINT;}
double National_Value_Data::getA_NVMAXREDADH1()
{return A_NVMAXREDADH1;}
double National_Value_Data::getA_NVMAXREDADH2()
{return A_NVMAXREDADH2;}
double National_Value_Data::getA_NVMAXREDADH3()
{return A_NVMAXREDADH3;}
double National_Value_Data::getA_NVP12()
{return A_NVP12;}
double National_Value_Data::getA_NVP23()
{return A_NVP23;}

TracksideSpeedRestriction::TracksideSpeedRestriction(Reseau &Res)
{
	this->Res = &Res;
}

vector<vector<double>> TracksideSpeedRestriction::getVitesseTableau()
{
	return tableau_vitesse_ligne;
}


void TracksideSpeedRestriction::TSR_Update(double distance_update)
{
	//MAJ vitesse (communication)
/*
	if(Res->getEurobalise().MAJ_eurobalise)
	{
		vector<double> temp;
		temp.push_back(tableau_vitesse_ligne[tableau_vitesse_ligne.size() - 1][1]);
		temp.push_back(tableau_vitesse_ligne[tableau_vitesse_ligne.size() - 1][1] + double(Res->getEurobalise().longueur));
		temp.push_back(double(Res->getEurobalise().vitesse));
		tableau_vitesse_ligne.erase(tableau_vitesse_ligne.end());
		tableau_vitesse_ligne.push_back(temp);
		tableau_vitesse_ligne.push_back({tableau_vitesse_ligne[tableau_vitesse_ligne.size() - 1][1], tableau_vitesse_ligne[tableau_vitesse_ligne.size() - 1][1], 0});
		speed_change = true;
	}*/

	//MAJ vitesse (distances)
	for(size_t i = 0; i < tableau_vitesse_ligne.size(); i++)
	{
		if(tableau_vitesse_ligne[i][0] != -1)
			tableau_vitesse_ligne[i][0] -= distance_update;
		tableau_vitesse_ligne[i][1] -= distance_update;
		if(int(tableau_vitesse_ligne[i][0]) < 0)
			tableau_vitesse_ligne[i][0] = -1;
		if(tableau_vitesse_ligne[i][1] <= 0)
		{
			tableau_vitesse_ligne.erase(tableau_vitesse_ligne.begin());
			//cout << "passs" << endl;
			speed_change = true;
		}
	}
}
bool TracksideSpeedRestriction::getSpeed_change(){return speed_change;}
void TracksideSpeedRestriction::setSpeed_change(bool S){speed_change = S;}

Gradient::Gradient(TrainRelatedInputs &TrainRI)
{
	this->TrainRI = &TrainRI;
	for(size_t i = 0; i < tableau_gradient.size() -  1; i++)
	{
		//cout << "ici" << endl;
		if(tableau_gradient[i][2] < tableau_gradient[i+1][2])
		{
			tableau_gradient[i][1] = tableau_gradient[i][1] + TrainRI.T_data.getTrain_length(); // Le gradient le plus critique sera allongé jusqu'au moment où le train dégagera la zone avec se gradient
			if(tableau_gradient[i+1][0] + TrainRI.T_data.getTrain_length() > tableau_gradient[i+1][1] + TrainRI.T_data.getTrain_length())
				tableau_gradient.erase(tableau_gradient.begin() + i + 1 ); //on supprime ce gradient si le décalage est plus grand que la logueur de la zone du gradient lui-même
			else
				tableau_gradient[i+1][0] = tableau_gradient[i+1][0] + TrainRI.T_data.getTrain_length();//SI le cas précédent n"est pas rencontré, on réduit la zone de ce gradient de la taille du train en décallant son début.
		}
	}
	//cout << "gradient" << endl;
}

vector<vector<double>> Gradient::getTab_Gradient()
{
	return tableau_gradient;
}

void Gradient::Gradient_Update(double distance_update)
{
	//RECEPTION DES NOUVEAUX GRADIENTS
	//
	/*for(size_t i; i < tableau_gradient.size() ; i++)
	{
		if(tableau_gradient[i][2] < tableau_gradient[i+1][2])
		{
			tableau_gradient[i][1] = tableau_gradient[i][1] + TrainRI->T_data.getTrain_length(); // Le gradient le plus critique sera allongé jusqu'au moment où le train dégagera la zone avec se gradient
			if(tableau_gradient[i+1][0] + TrainRI->T_data.getTrain_length() > tableau_gradient[i+1][1] + TrainRI->T_data.getTrain_length())
				tableau_gradient.erase(tableau_gradient.begin() + i + 1 ); //on supprime ce gradient si le décalage est plus grand que la logueur de la zone du gradient lui-même
			else
				tableau_gradient[i+1][0] = tableau_gradient[i+1][0] + TrainRI->T_data.getTrain_length();//SI le cas précédent n"est pas rencontré, on réduit la zone de ce gradient de la taille du train en décallant son début.
		}
	}*/

	//ATTENTION LA PARTIE PRECEDENTE SE TROUVE DANS LE CONSTRUCTEUR DE GARDIENT ET DEVRA ETRE POSITIONNEE ICI LORSQUE IL Y AURA COMMUNICATION

	//DETERMINATION DU GRADIENT LE PLUS CRITIQUE
	for(size_t i = 0; i < tableau_gradient.size(); i++)//pour éviter de comparer avec une case non existante
	{
		if(tableau_gradient[i][0] != -1)
			tableau_gradient[i][0] -= distance_update;
		tableau_gradient[i][1] -= distance_update;
		if(tableau_gradient[i][0] < 0)
			tableau_gradient[i][0] = -1;
		if(tableau_gradient[i][1] < 0)
			tableau_gradient.erase(tableau_gradient.begin());
	}
}
SpeedAndDistanceLimits::SpeedAndDistanceLimits(TracksideSpeedRestriction &TSR)
{
	this->TSR = &TSR;
	//target_determination();
	//cout << "SADL" << endl;
}

void SpeedAndDistanceLimits::target_determination()
{
	target_distance = TSR->getVitesseTableau()[0][1]; // on obtient la prochaine target distance
	speed_target = TSR->getVitesseTableau()[1][2]; // on obtient la prochaine vitesse à respecter
}
void SpeedAndDistanceLimits::Target_update()
{
	target_update = false;
	if(TSR->getSpeed_change()) // AJOUTER TOUTES CONDITIONS QUI FONT CHANGER LA EOA (VITESSE, SIGNALISATION, ...) EN METTANT || + LA NOUVELLE CONDITION
	{
		target_update = true;
		//cout << "passs" << endl;
		TSR->setSpeed_change(false);
	}
}
void SpeedAndDistanceLimits::SADL_update()
{
	target_determination();
	Target_update();
}
double SpeedAndDistanceLimits::getTargetDistance(){return target_distance;}
void SpeedAndDistanceLimits::SetTargetDistance(double D){target_distance = D;}
double SpeedAndDistanceLimits::getSpeedTarget(){return speed_target;}
void SpeedAndDistanceLimits::setSpeedTarget(double S){speed_target = S;}
bool SpeedAndDistanceLimits::getTarget_update(){return target_update;}
void SpeedAndDistanceLimits::setTarget_update(bool B){target_update = B;}

TrackRelatedInputs::TrackRelatedInputs(TrainRelatedInputs &TrainRI, Train_dynamique &T_D, Reseau &Res) : TSR(Res), gradient_ligne(TrainRI), SADL(TSR)
{
	this->T_D = &T_D;
	this->Res = &Res;
}

void TrackRelatedInputs::TrackRI_Update()
{
	pointKilometrique = pointKilometrique + T_D->getDistance_Uptdate();
	cout << pointKilometrique << endl;
	TSR.TSR_Update(T_D->getDistance_Uptdate());
	gradient_ligne.Gradient_Update(T_D->getDistance_Uptdate());
	SADL.SADL_update();

}

double TrackRelatedInputs::getPointKilometrique(){return pointKilometrique;}
void TrackRelatedInputs::setPointKilometrique(double P){pointKilometrique = P;}
double TrackRelatedInputs::getRemainingDistanceTunnel(){return remainingDistanceTunnel;}
string TrackRelatedInputs::getTunnelStoppingArea(){return tunnelStoppingArea;}
void TrackRelatedInputs::setTunnelStoppingArea(string TSA){tunnelStoppingArea = TSA;}
