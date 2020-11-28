
#include "SpeedAndDistanceMonitoring.hpp"
#include "TrainRelatedInputs.hpp"
#include "TrackRelatedInputs.hpp"
#include "../Train_dynamique.hpp"

SpeedAndDistanceMonitoring::SpeedAndDistanceMonitoring(Train_dynamique &T_D, TrainRelatedInputs &TrainRI, TrackRelatedInputs &TrackRI, Software &soft, Reseau &Res) : TBS(TrainRI, TrackRI), MRSP(TrackRI), DODC(TrackRI,TrainRI, T_D, TBS), SL(T_D, TrainRI, TrackRI, MRSP, DODC), SADMC(T_D, MRSP, SL, TrackRI, soft)
{
	this->T_D = &T_D;
	this->TrainRI = &TrainRI;
	this->TrackRI = &TrackRI;
	this->Res = &Res;
	//cout << "SADM" << endl;
}

void SpeedAndDistanceMonitoring::SDM_Update_FS()
{
	
	//diftimeSDM = chronoSDM.getElapsedTime();
	//deltatsSDM = diftimeSDM.asSeconds();
	MRSP.function_MRSP();
	if (TrackRI->SADL.getTarget_update()) // si MAJ de la target (nouvelle MA)
	{
		//TBS.TBS_Update();
		DODC.calculEBD();
		SL.Curves();
	}
	SL.Supervision_limits();
	SADMC.SpeedAndDistanceMonitoringCommands_update();
}

void SpeedAndDistanceMonitoring::SDM_Update_SR()
{

}

Traction_Braking_system::Traction_Braking_system(TrainRelatedInputs &TrainRI, TrackRelatedInputs &TrackRI)
{
	this->TrackRI = &TrackRI;
	this->TrainRI = &TrainRI;
	calculA_gradient();
	calculA_brake_safe();
	//cout << "tbs" << endl;cout << n_A_gradient << endl;
}

void Traction_Braking_system::calculA_brake_safe()
{
	double deceleration;
	A_brake_safe.clear();
	//conversion de A_brake_emergency en A_brake_safe à la construction de l'objet Traction_Braking_System
	for (size_t i = 0; i < A_brake_emergency.size(); i++)
	{
		//cout << "vitesse : " << A_brake_emergency[i][1];
		deceleration = TrainRI->OBCF.getK_dry() * (TrainRI->OBCF.getK_wet() + TrackRI->NVD.getM_NVAVADH() * (1 - TrainRI->OBCF.getK_wet())) * A_brake_emergency[i][2];
		step(A_brake_safe, A_brake_emergency[i][0], A_brake_emergency[i][1], deceleration);
		//cout << "A " << A_brake_safe[i][2]<< "entre la vitesse : " << A_brake_safe[i][0] << "et :" << A_brake_safe[i][1] << endl;
	}
}

void Traction_Braking_system::calculA_gradient()
{
	A_gradient.clear();
	for (size_t i = 0; i < TrackRI->gradient_ligne.getTab_Gradient().size(); i++)
	{
		step(A_gradient, TrackRI->gradient_ligne.getTab_Gradient()[i][0], TrackRI->gradient_ligne.getTab_Gradient()[i][1], Constant_G*TrackRI->gradient_ligne.getTab_Gradient()[i][2]/(1000+10*TrainRI->T_data.getM_rotating_nom()));
		//cout << "A " << A_gradient[i][2]<< "entre la distance : " << A_gradient[i][0] << "et :" << A_gradient[i][1] << endl;
	}
}
vector<vector<double>> Traction_Braking_system::getA_brake_safe(){return A_brake_safe;}
vector<vector<double>> Traction_Braking_system::getA_gradient(){return A_gradient;}

void Traction_Braking_system::TBS_Update()
{
	if(TrackRI->SADL.getTargetDistance() > 0)
		calculA_gradient();
		//calculA_brake_safe();
}

//std::vector<vector<double>> Traction_Braking_system::getA_safe(){return A_safe;}

SupervisionLimits::SupervisionLimits(Train_dynamique &T_D, TrainRelatedInputs &TrainRI, TrackRelatedInputs &TrackRI, MostRestrictiveSpeedLimit &MRSP, DeterminationOfDecelerationCurves &DODC)
{
	this->T_D = &T_D;
	this->TrainRI = &TrainRI;
	this->TrackRI = &TrackRI;
	this->MRSP = &MRSP;
	this->DODC = &DODC;
	//cout << "SL" << endl;
}
double SupervisionLimits::getV_ebi(){return V_ebi;}
double SupervisionLimits::getV_sbi(){return V_sbi;}
double SupervisionLimits::getV_warning(){return V_warning;}
double SupervisionLimits::getV_permitted(){return V_permited;}
double SupervisionLimits::getV_indication(){return V_indication;}
string SupervisionLimits::getStatus(){return status;}
double SupervisionLimits::getd_indication(){return d_indication;}
double SupervisionLimits::getd_permitted(){return d_permitted;}
double SupervisionLimits::getd_ebi(){return d_ebi;}
double SupervisionLimits::getd_warning(){return d_warning;}
double SupervisionLimits::getReleaseSpeed(){return releaseSpeed;}
void SupervisionLimits::Curves()
{
	vector<double> ligne;
	curvestab.clear();
	double EBDresult = DODC->getEBD()[DODC->getEBD().size() - 1][1];

	for(double vitesse = TrackRI->SADL.getSpeedTarget(); vitesse < EBDresult; vitesse++)
	{
		Vbec = 3.6*(max((vitesse/3.6 + V_delta0 + V_delta1), TrackRI->SADL.getSpeedTarget()/3.6) + V_delta2);
		Dbec = max((vitesse/3.6 + V_delta0 + V_delta1/2), TrackRI->SADL.getSpeedTarget()/3.6)*T_traction + (max((vitesse/3.6 + V_delta0 + V_delta1), TrackRI->SADL.getSpeedTarget()/3.6) + V_delta2/2)*T_berem;
		//cout << Vbec << " " << Dbec << " " << DODC->getDistanceEBD(Vbec) << endl;
		if(DODC->getDistanceEBD(Vbec) + Dbec > 0)
			d_ebi = DODC->getDistanceEBD(Vbec) + Dbec;
		else
			d_ebi = 0;
		if(d_ebi + TrainRI->FVD.getT_warning()*vitesse/3.6 > 0)
			d_warning = d_ebi + TrainRI->FVD.getT_warning()*vitesse/3.6;
		else
			d_warning = 0;
		if(d_ebi + TrainRI->FVD.getT_driver()*vitesse/3.6 > 0)
			d_permitted = d_ebi + TrainRI->FVD.getT_driver()*vitesse/3.6;
		else
			d_permitted = 0;
		if(d_permitted + T_indication*vitesse/3.6 > 0)
			d_indication = d_permitted + T_indication*vitesse/3.6;
		else
			d_indication = 0;
		ligne = {double(vitesse), d_ebi, d_warning, d_permitted, d_indication};
		curvestab.push_back(ligne);
	}
}

double SupervisionLimits::getV_ebi_CSM(double vitesse) // utiliser pour comparer V_ebi but et calculée avec la TSM
{
	double DV_ebi;
	double Cebi = (TrainRI->FVD.getdV_ebi_max() - TrainRI->FVD.getdV_ebi_min()) / (TrainRI->FVD.getV_ebi_max() - TrainRI->FVD.getV_ebi_min() );
	if(vitesse > TrainRI->FVD.getV_ebi_min())
	{
		DV_ebi = min(TrainRI->FVD.getdV_ebi_min() + Cebi*(vitesse  - TrainRI->FVD.getV_ebi_min()), TrainRI->FVD.getdV_ebi_max());
	}
	else
		DV_ebi = TrainRI->FVD.getdV_ebi_min();
	return vitesse + DV_ebi;
}

double SupervisionLimits::getV_warning_CSM(double vitesse)
{
		double Cwarning = (TrainRI->FVD.getdV_warning_max() - TrainRI->FVD.getdV_warning_min()) / (TrainRI->FVD.getV_warning_max() - TrainRI->FVD.getV_warning_min() );
		double DV_warning;
		if(vitesse  > TrainRI->FVD.getV_warning_min())
		{
			DV_warning = min(TrainRI->FVD.getdV_warning_min() + Cwarning*(vitesse - TrainRI->FVD.getV_warning_min()), TrainRI->FVD.getdV_warning_max());
		}
		else
		DV_warning = TrainRI->FVD.getdV_warning_min();
		return vitesse  + DV_warning;
}

void SupervisionLimits::Supervision_limits()
{


	if(status == "CSM")
	{
		//double Csbi = (TrainRI->FVD.getdV_sbi_max() - TrainRI->FVD.getdV_sbi_min()) / (TrainRI->FVD.getV_sbi_max() - TrainRI->FVD.getV_sbi_min() );
		//double DV_sbi;
		int n_ligne = 0;

		//if(MRSP->getV_MRSP()  > TrainRI->FVD.getV_sbi_min())
		//{
		//	DV_sbi = min(TrainRI->FVD.getdV_sbi_min() + Csbi*(MRSP->getV_MRSP()  - TrainRI->FVD.getV_sbi_min()), TrainRI->FVD.getdV_sbi_max());
		//}
		//else
		//DV_sbi = TrainRI->FVD.getdV_sbi_min();

		V_ebi = getV_ebi_CSM(MRSP->getV_MRSP());
		//V_sbi =	MRSP->getV_MRSP()  + DV_sbi;
		V_warning = getV_warning_CSM(MRSP->getV_MRSP());

		while(TrackRI->SADL.getTargetDistance() > curvestab[n_ligne][4])
		{
			n_ligne ++;
		}
		V_indication = curvestab[n_ligne][0];
	}

	if(status == "TSM")
	{
		int n_ligne = 0;
		while(TrackRI->SADL.getTargetDistance() > curvestab[n_ligne][1])
		{
			n_ligne ++;
		}
		V_ebi = max(min(curvestab[n_ligne][0], getV_ebi_CSM(MRSP->getV_MRSP())), getV_ebi_CSM(TrackRI->SADL.getSpeedTarget()));
		d_ebi = curvestab[n_ligne][1];
		n_ligne = 0;
		while(TrackRI->SADL.getTargetDistance() > curvestab[n_ligne][2])
		{
			n_ligne ++;
		}
		V_warning = max(min(curvestab[n_ligne][0], getV_warning_CSM(MRSP->getV_MRSP())), getV_warning_CSM(TrackRI->SADL.getSpeedTarget()));
		d_warning = curvestab[n_ligne][2];
		n_ligne = 0;
		while(TrackRI->SADL.getTargetDistance() > curvestab[n_ligne][3])
		{
			n_ligne ++;
		}
		V_permited = max(min(curvestab[n_ligne][0], MRSP->getV_MRSP()), TrackRI->SADL.getSpeedTarget());
		d_permitted = curvestab[n_ligne][3];
		n_ligne = 0;
		while(TrackRI->SADL.getTargetDistance() > curvestab[n_ligne][4])
		{
			n_ligne ++;
		}
		V_indication = max(curvestab[n_ligne][0], TrackRI->SADL.getSpeedTarget());
		d_indication = curvestab[n_ligne][4];

	}

	if(status == "RSM")
	{
		int n_ligne = 0;
		while(TrackRI->SADL.getTargetDistance() > curvestab[n_ligne][3])
		{
			n_ligne ++;
		}
		V_permited = max(min(curvestab[n_ligne][0], MRSP->getV_MRSP()), TrackRI->SADL.getSpeedTarget());
		d_permitted = curvestab[n_ligne][3];
		n_ligne = 0;
		while(TrackRI->SADL.getTargetDistance() > curvestab[n_ligne][4])
		{
			n_ligne ++;
		}
		V_indication = max(curvestab[n_ligne][0], TrackRI->SADL.getSpeedTarget());
		d_indication = curvestab[n_ligne][4];
	}
	Changement_status();
	cout <<"status :" << status << endl;
}

void SupervisionLimits::Changement_status()
{
	//CONDITION A RETROUVER PAGE 149 DE LA SUBSET 026-3

	//CONDITION 1 // condition pour passer de CSM à TSM
	if(status == "CSM" && V_indication <= MRSP->getV_MRSP() && T_D->getV_train() >= releaseSpeed)
	{
		status = "TSM";
		playfunction(2);
	}
	//CONDITION 2 //CSM & TSM --> RSM
	if((status == "CSM" || status == "TSM") && V_ebi <= releaseSpeed)
	{
		status = "RSM";
	}
	//CONDITION 3 // RSM & TSM --> CSM
	if((status == "RSM" || status == "TSM") && TrackRI->SADL.getTarget_update() == true && !(V_indication <= MRSP->getV_MRSP() && T_D->getV_train() >= releaseSpeed) && !(V_ebi <= releaseSpeed))
	{
		status = "CSM";
		playfunction(2);
		//cout << "changement" << endl;
	}
	//CONDITION 4 // RSM & CSM --> TSM
	if( (status == "RSM" || status == "TSM") && TrackRI->SADL.getTarget_update() == true && (V_indication <= MRSP->getV_MRSP() && T_D->getV_train() >= releaseSpeed) && !(V_ebi <= releaseSpeed))
	{
		status = "TSM";
		playfunction(2);
	}
	//CONDITION 5 // CSM & TSM --> RSM
	if ((status == "CSM" || status == "TSM") && TrackRI->SADL.getTarget_update() == true &&((status == "CSM" || status == "TSM") && V_ebi <= releaseSpeed))
	{
		status = "RSM";
	}
}

MostRestrictiveSpeedLimit::MostRestrictiveSpeedLimit(TrackRelatedInputs &TrackRI)
{
	this->TrackRI = &TrackRI;
	//cout << "MRSL" << endl;
}
void MostRestrictiveSpeedLimit::function_MRSP()
{
	//cette fonction devra évoluer afin de répondre à la vraie définition de la MRSP, mais, dans le but
	//de simplifier l'execution, on appliquera la vitesse [0]
	V_MRSP = TrackRI->TSR.getVitesseTableau()[0][2];
	distance = TrackRI->TSR.getVitesseTableau()[0][1];
}
double MostRestrictiveSpeedLimit::getV_MRSP(){return V_MRSP;}
double MostRestrictiveSpeedLimit::getDistance(){return distance;}


DeterminationOfDecelerationCurves::DeterminationOfDecelerationCurves(TrackRelatedInputs &TrackRI, TrainRelatedInputs &TrainRI, Train_dynamique &T_D, Traction_Braking_system &TBS)
{
	this->TrackRI = &TrackRI;
	this->T_D = &T_D;
	this->TBS = &TBS;
	this->TrainRI = &TrainRI;
	//cout << "DODC" << endl;
}

void DeterminationOfDecelerationCurves::calculEBD()
{
	size_t distance;
	double vitesse;
	size_t n_A_brake_safe = 0;
	size_t n_A_gradient = 0;
	vector<double> init;
	//bool stop_for = false;
	EBD.clear();
	init.push_back(0);
	//init.push_back(getV_start());
	init.push_back(TrackRI->SADL.getSpeedTarget());
	init.push_back(0);
	EBD.push_back(init);//initialisation de la première ligne de EBD

	while(TrackRI->SADL.getSpeedTarget() >= TBS->getA_brake_safe()[n_A_brake_safe][1])
	{
		n_A_brake_safe++;
	}
	while(TrackRI->SADL.getTargetDistance() >= TBS->getA_gradient()[n_A_gradient][1])
	{
		n_A_gradient++;
	}
	vitesse = TrackRI->SADL.getSpeedTarget();
	distance = 0;
	double targetDistanceSadl = TrackRI->SADL.getTargetDistance();
	double gradientSize = TBS -> getA_gradient().size();
	double brakeSize = TBS->getA_brake_safe().size();
	size_t n_A_brake_safeTemp = n_A_brake_safe;
	size_t n_A_gradientTemp = n_A_gradient;
	double A_brake_safeTemp = TBS->getA_brake_safe()[n_A_brake_safe][2];
	double A_gradientTemp = TBS->getA_gradient()[n_A_gradient][2];
	double A_gradientTemp0 = TBS->getA_gradient()[n_A_gradient][0];
	double A_brake_safeTemp1 = TBS->getA_brake_safe()[n_A_brake_safe][1];

	while (distance < targetDistanceSadl)
	{
	
		if (n_A_gradient == gradientSize || n_A_brake_safe == brakeSize)//on vérifie qu'on à pas atteint la limite des vector freinage et gradient
			break;

		vitesse = 3.6*(sqrt(2*(A_brake_safeTemp + A_gradientTemp) + pow(EBD[EBD.size() - 1][1]/3.6, 2)));//calcul de la vitesse entre les deux distance par rapport à la décélération à la distance D
		step(EBD, distance, vitesse, A_brake_safeTemp + A_gradientTemp);//rajout de cette vitesse à la distance d

	    if(targetDistanceSadl - distance < A_gradientTemp0)
		{
			//cout << n_A_gradient << endl;
			n_A_gradient--; // si on a atteint la distance à laquelle le gradient change, alors nous prendrons la nouvelle valeur de A_gradient
	//		cout << n_A_gradient << endl;
		}

		if(vitesse >= A_brake_safeTemp1)
			n_A_brake_safe++;// si on a atteint la vitesse à laquelle la valeur de décélération du train change, alors nous prendrons une nouvelle valeur de A_brake_safe

    	
		distance = distance + 1;

		if (n_A_brake_safeTemp != n_A_brake_safe) {
			A_brake_safeTemp = TBS->getA_brake_safe()[n_A_brake_safe][2];
			A_brake_safeTemp1 = TBS->getA_brake_safe()[n_A_brake_safe][1];
		}
		if (n_A_gradientTemp != n_A_gradient) {
			A_gradientTemp = TBS->getA_gradient()[n_A_gradient][2];
			A_gradientTemp0 = TBS->getA_gradient()[n_A_gradient][0];
		}

	    n_A_brake_safeTemp = n_A_brake_safe;
	    n_A_gradientTemp = n_A_gradient;
	}
}

//double DeterminationOfDecelerationCurves::getV_start()
//{
//	//if(TrackRI->SADL.getSpeedTarget() == 0)
//	//	return 0;
//	//else
//	//{
//	//	double DV_ebi;
//	//	double Cebi = (TrainRI->FVD.getdV_ebi_max() - TrainRI->FVD.getdV_ebi_min()) / (TrainRI->FVD.getV_ebi_max() - TrainRI->FVD.getV_ebi_min() );
//	//	if(TrackRI->SADL.getSpeedTarget() > TrainRI->FVD.getV_ebi_min())
//	//	{
//	//		DV_ebi = min(TrainRI->FVD.getdV_ebi_min() + Cebi*(TrackRI->SADL.getSpeedTarget()  - TrainRI->FVD.getV_ebi_min()), TrainRI->FVD.getdV_ebi_max());
//	//	}*
//	//	else
//	//		DV_ebi = TrainRI->FVD.getdV_ebi_min();
//	//	return TrackRI->SADL.getSpeedTarget() + DV_ebi;
//	//}
//
//}

vector<vector<double>> DeterminationOfDecelerationCurves::getEBD()
{
	return EBD;
}

double DeterminationOfDecelerationCurves::getDistanceEBD(double vitesse)
{
	size_t i = 0;
	while (vitesse > EBD[i][1])
	{
		if(i == EBD.size())
		{
			cout << "erreur dans getDistanceEBD" << endl;
			break;
		}
		i++;
	}
	return EBD[i][0];
}

double DeterminationOfDecelerationCurves::getVitesseEBD(double distance)
{
	size_t i = 0;
	while (distance > EBD[i][0])
	{
		i++;
		if(i == EBD.size())
		{
			cout << "erreur dans getVitesseEBD, distance = "<< distance << endl;
			break;
		}
	}
	return EBD[i][1];
}

double DeterminationOfDecelerationCurves::getAccEBD(double distance)
{
	size_t i = 0;
	while (distance > EBD[i][0])
	{
		i++;
		if(i == EBD.size())
		{
			cout << "erreur dans getVitesseEBD" << endl;
			break;
		}
	}
	return EBD[i][2];
}

SpeedAndDistanceMonitoringCommands::SpeedAndDistanceMonitoringCommands(Train_dynamique &T_D, MostRestrictiveSpeedLimit &MRSP, SupervisionLimits &SL, TrackRelatedInputs &TrackRI, Software &soft)
{
	this->T_D = &T_D;
	this->TrackRI = &TrackRI;
	this->MRSP = &MRSP;
	this->SL = &SL;
	this->soft = &soft;
	//cout << "SADMC" << endl;
}

void SpeedAndDistanceMonitoringCommands::SpeedAndDistanceMonitoringCommands_update()
{
	if(SL->getStatus() == "CSM")
	{
		//Triggering Conditions
		if(T_D->getV_train() <= MRSP->getV_MRSP() && supervision_status == "Normal")
		{
			supervision_status = "Normal";
			stopfunction();
		}
		if(T_D->getV_train() > MRSP->getV_MRSP() && supervision_status == "Normal")
		{
			supervision_status = "Overspeed";
			playfunction(3); // on démarre le son du dépassement de vitesse
		}
		if(T_D->getV_train() > SL->getV_warning() && supervision_status == "Overspeed")
		{
			supervision_status = "Warning";
			stopfunction(); // on arrête le son de la vitesse dépassée
			playfunction(4); // on démarre le warning son
		}
		/*if(T_D->getV_train() > V_sbi)//à voir avec Benoit
		{
			supervision_status = "Intervention";
			command_triggered = "SB";
		}*/
		if(T_D->getV_train() > SL->getV_ebi() && supervision_status == "Warning")
		{
			supervision_status = "Intervention";
			command_triggered = "EB";
		}

		//Revocation conditions
		if(T_D->getV_train() == 0 && supervision_status == "Intervention")
		{
			supervision_status = "Normal";
			command_triggered = "";
			stopfunction();
		}
		if(T_D->getV_train() <= MRSP->getV_MRSP() && supervision_status != "Intervention")
		{
			supervision_status = "Normal";
			stopfunction();
			if (command_triggered == "SB")
			{
				command_triggered = "";
			}
		}
	}	//cout << supervision_status << " " << command_triggered << endl;
	if(SL->getStatus() == "TSM")
	{
		if(T_D->getV_train() < SL->getV_indication()  && supervision_status != "Intervention")
			supervision_status = "Normal";
		if(T_D->getV_train() >= int(SL->getV_indication()) && supervision_status == "Normal")
			supervision_status = "Indication";
		if(T_D->getV_train() >= int(SL->getV_permitted()) && supervision_status == "Indication")
		{
			supervision_status = "Overspeed";
			playfunction(3); // on démarre le son du dépassement de vitesse
		}
		if(T_D->getV_train() >= int(SL->getV_warning()) && supervision_status == "Overspeed")
		{
			supervision_status = "Warning";
			stopfunction(); // on arrête le son de la vitesse dépassée
			playfunction(4); // on démarre le warning son
		}
		if(T_D->getV_train() >= int(SL->getV_ebi()))
		{
			supervision_status = "Intervention";
			command_triggered = "EB";
		}
		//Revocation conditions
		//if((int)T_D->getV_train() == 0)
		//{
		//	supervision_status = "Normal";
		//	command_triggered = "";
		//	stopfunction();
		//}
		if(supervision_status != "Intervention")
		{
			if(T_D->getV_train() < SL->getV_indication())
			{
				supervision_status = "Normal";
				stopfunction();
			}
			else
			if(T_D->getV_train() <= SL->getV_permitted())
			{
				supervision_status = "Indication";
				stopfunction();
			}
			if(command_triggered == "SB")
			{
				command_triggered = "";
			}
		}
	}
	if(SL->getStatus() == "RSM")
	{
		stopfunction();
		if(T_D->getV_train() <= SL->getReleaseSpeed())
		{
			supervision_status = "Indication";
		}
		if(T_D->getV_train() > SL->getReleaseSpeed())
		{
			supervision_status = "Intervention";
			command_triggered = "EB";
		}
		//Revocation conditions
		if((int)T_D->getV_train() == 0)
		{
			supervision_status = "Indication";
			command_triggered = "";
			stopfunction();
		}
		if (supervision_status == "Overspeed" || supervision_status == "Warning")
		{
			supervision_status = "Indication";
		}
	}
	//cout << supervision_status << " ";
	//cout << T_D->getV_train() << " " << SL->getV_indication()<< " " << SL->getV_permitted()<< " " << SL->getV_warning() << " " << SL->getV_ebi();
}

string SpeedAndDistanceMonitoringCommands::getSupervision_status(){return supervision_status;}
string SpeedAndDistanceMonitoringCommands::getCommand_triggered(){return command_triggered;}
