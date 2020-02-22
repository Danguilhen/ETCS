
#include "SpeedAndDistanceMonitoring.hpp"
#include "TrainRelatedInputs.hpp"
#include "TrackRelatedInputs.hpp"
#include "../Train_dynamique.hpp"

SpeedAndDistanceMonitoring::SpeedAndDistanceMonitoring(Train_dynamique &T_D, TrainRelatedInputs &TrainRI, TrackRelatedInputs &TrackRI) : TBS(TrainRI, TrackRI), MRSP(TrackRI), DODC(TrackRI, T_D, TBS), SL(T_D, TrainRI, TrackRI, MRSP, DODC), SADMC(T_D, MRSP, SL)
{
	this->T_D = &T_D;
	this->TrainRI = &TrainRI;
	this->TrackRI = &TrackRI;
	//cout << "SADM" << endl;
}

void SpeedAndDistanceMonitoring::SDM_Update()
{
	diftimeSDM = chronoSDM.getElapsedTime();
	deltatsSDM = diftimeSDM.asSeconds();
	MRSP.function_MRSP();
	SL.Supervision_limits();
	SADMC.SpeedAndDistanceMonitoringCommands_update();
	if (deltatsSDM >= TMAJ)
	{
		//cout << "start" << endl;
		//chronoSDM.restart();
		TBS.TBS_Update();
		DODC.calculEBD();
		//diftimeSDM = chronoSDM.getElapsedTime();
		//deltatsSDM = diftimeSDM.asSeconds();
		//cout << "fait en : " << deltatsSDM << endl;
		chronoSDM.restart();
	}
}

Traction_Braking_system::Traction_Braking_system(TrainRelatedInputs &TrainRI, TrackRelatedInputs &TrackRI)
{
	this->TrackRI = &TrackRI;
	this->TrainRI = &TrainRI;
	calculA_gradient();
	calculA_brake_safe();
	//cout << "tbs" << endl;
}

void Traction_Braking_system::calculA_brake_safe()
{
	float deceleration;
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
vector<vector<float>> Traction_Braking_system::getA_brake_safe(){return A_brake_safe;}
vector<vector<float>> Traction_Braking_system::getA_gradient(){return A_gradient;}

void Traction_Braking_system::TBS_Update()
{
	if(TrackRI->SADL.getTargetDistance() > 0)
		calculA_gradient();
		//calculA_brake_safe();
}

//std::vector<vector<float>> Traction_Braking_system::getA_safe(){return A_safe;}

SupervisionLimits::SupervisionLimits(Train_dynamique &T_D, TrainRelatedInputs &TrainRI, TrackRelatedInputs &TrackRI, MostRestrictiveSpeedLimit &MRSP, DeterminationOfDecelerationCurves &DODC)
{
	this->T_D = &T_D;
	this->TrainRI = &TrainRI;
	this->TrackRI = &TrackRI;
	this->MRSP = &MRSP;
	this->DODC = &DODC;
	//cout << "SL" << endl;
}
float SupervisionLimits::getV_ebi(){return V_ebi;}
float SupervisionLimits::getV_sbi(){return V_sbi;}
float SupervisionLimits::getV_indication(){return V_indication;}
float SupervisionLimits::getV_permitted(){return V_permited;}
float SupervisionLimits::getV_warning(){return V_warning;}
string SupervisionLimits::getStatus(){return status;}
void SupervisionLimits::Supervision_limits()
{
	if(status == "CSM")
	{
		float Cebi = (TrainRI->FVD.getdV_ebi_max() - TrainRI->FVD.getdV_ebi_min()) / (TrainRI->FVD.getV_ebi_max() - TrainRI->FVD.getV_ebi_min() );
		float Csbi = (TrainRI->FVD.getdV_sbi_max() - TrainRI->FVD.getdV_sbi_min()) / (TrainRI->FVD.getV_sbi_max() - TrainRI->FVD.getV_sbi_min() );
		float Cwarning = (TrainRI->FVD.getdV_warning_max() - TrainRI->FVD.getdV_warning_min()) / (TrainRI->FVD.getV_warning_max() - TrainRI->FVD.getV_warning_min() );
		float DV_ebi;
		float DV_sbi;
		float DV_warning;

		if(MRSP->getV_MRSP() > TrainRI->FVD.getV_ebi_min())
		{
			DV_ebi = min(TrainRI->FVD.getdV_ebi_min() + Cebi*(MRSP->getV_MRSP()  - TrainRI->FVD.getV_ebi_min()), TrainRI->FVD.getdV_ebi_max());
		}
		else
		DV_ebi = TrainRI->FVD.getdV_ebi_min();
		if(MRSP->getV_MRSP()  > TrainRI->FVD.getV_sbi_min())
		{
			DV_sbi = min(TrainRI->FVD.getdV_sbi_min() + Csbi*(MRSP->getV_MRSP()  - TrainRI->FVD.getV_sbi_min()), TrainRI->FVD.getdV_sbi_max());
		}
		else
		DV_sbi = TrainRI->FVD.getdV_sbi_min();
		if(MRSP->getV_MRSP()  > TrainRI->FVD.getV_warning_min())
		{
			DV_warning = min(TrainRI->FVD.getdV_warning_min() + Cwarning*(MRSP->getV_MRSP()  - TrainRI->FVD.getV_warning_min()), TrainRI->FVD.getdV_warning_max());
		}
		else
		DV_warning = TrainRI->FVD.getdV_warning_min();

		V_ebi = MRSP->getV_MRSP()  + DV_ebi;
		V_sbi =	MRSP->getV_MRSP()  + DV_sbi;
		V_warning = MRSP->getV_MRSP()  + DV_warning;
	}
	if(status == "TSM")
	{
		bool V_i_ok = false;
		bool V_p_ok = false;
		bool V_w_ok = false;
		bool V_ebi_ok = false;
		T_be = T_brake_emergency; // seulement dans le cas où le freinage n'est pas fait avec le conversion model
		T_berem = max(T_be - T_traction, float(0));
		float distance = TrackRI->SADL.getTargetDistance();
		for(float vitesse = 0; vitesse < DODC->getEBD()[DODC->getEBD().size() - 1][1]; vitesse ++)
		{
			Vbec = 3.6*(max((vitesse/3.6 + V_delta0 + V_delta1), TrackRI->SADL.getSpeedTarget()/3.6) + V_delta2);
			Dbec = max((vitesse/3.6 + V_delta0 + V_delta1/2), TrackRI->SADL.getSpeedTarget()/3.6)*T_traction + (max((vitesse/3.6 + V_delta0 + V_delta1), TrackRI->SADL.getSpeedTarget()/3.6) + V_delta2/2)*T_berem;
			//cout << Vbec << " " << Dbec << " " << DODC->getDistanceEBD(Vbec) << endl;
			d_ebi = DODC->getDistanceEBD(Vbec) + Dbec;
			d_warning = d_ebi + TrainRI->FVD.getT_warning()*vitesse/3.6;
			d_permitted = d_ebi + TrainRI->FVD.getT_driver()*vitesse/3.6;
			d_indication = d_permitted + T_indication*vitesse/3.6;
			//cout<< d_ebi << " " << d_permitted << " " << d_indication << endl;
			if(distance <= d_indication && V_i_ok == false)
			{
				V_indication = vitesse;
				V_i_ok = true;
			}
			if (distance <= d_permitted && V_p_ok == false)
			{
				V_permited = vitesse;
				V_p_ok = true;
			}
			if (distance <= d_warning && V_w_ok == false)
			{
				V_warning = vitesse;
				V_w_ok = true;
			}
			if (distance <= d_ebi && V_ebi_ok == false)
			{
				V_ebi = vitesse;
				V_ebi_ok = true;
			}
		}
		//cout << V_ebi << " " << V_permited << " " << V_indication << endl;
	}
}

MostRestrictiveSpeedLimit::MostRestrictiveSpeedLimit(TrackRelatedInputs &TrackRI)
{
	this->TrackRI = &TrackRI;
	//cout << "MRSL" << endl;
}
void MostRestrictiveSpeedLimit::function_MRSP()
{
	V_MRSP = TrackRI->TSR.getVitesseTableau()[0][2];
}
float MostRestrictiveSpeedLimit::getV_MRSP(){return V_MRSP;}


DeterminationOfDecelerationCurves::DeterminationOfDecelerationCurves(TrackRelatedInputs &TrackRI, Train_dynamique &T_D, Traction_Braking_system &TBS)
{
	this->TrackRI = &TrackRI;
	this->T_D = &T_D;
	this->TBS = &TBS;
	calculEBD();
	//cout << "DODC" << endl;
}

void DeterminationOfDecelerationCurves::calculEBD()
{
	size_t distance;
	float vitesse;
	size_t n_A_brake_safe = 0;
	size_t n_A_gradient = 0;
	vector<float> init;
	//bool stop_for = false;
	EBD.clear();
	init.push_back(0);
	init.push_back(0);
	init.push_back(0);
	EBD.push_back(init);//initialisation de la première ligne de EBD
	for(distance = 0; distance < TrackRI->SADL.getTargetDistance(); distance++)
	{
		if (n_A_gradient == TBS->getA_gradient().size() || n_A_brake_safe == TBS->getA_brake_safe().size())//on vérifie qu'on à pas atteint la limite des vector freinage et gradient
		{
			break;
		}
		vitesse = 3.6*(sqrtf(2*(TBS->getA_brake_safe()[n_A_brake_safe][2] + TBS->getA_gradient()[n_A_gradient][2]) + pow(EBD[EBD.size() - 1][1]/3.6, 2)));//calcul de la vitesse entre les deux distance par rapport à la décélération à la distance D
		step(EBD, distance, vitesse, TBS->getA_brake_safe()[n_A_brake_safe][2] + TBS->getA_gradient()[n_A_gradient][2]);//rajout de cette vitesse à la distance d
		if(distance == size_t( TBS->getA_gradient()[n_A_gradient][1]))
			n_A_gradient++; // si on a atteint la distance à laquelle le gradient change, alors nous prendrons la nouvelle valeur de A_gradient
		if(vitesse >= TBS->getA_brake_safe()[n_A_brake_safe][1])
			n_A_brake_safe++;// si on a atteint la vitesse à laquelle la valeur de décélération du train change, alors nous prendrons une nouvelle valeur de A_brake_safe
	}
}

vector<vector<float>> DeterminationOfDecelerationCurves::getEBD()
{
	return EBD;
}

float DeterminationOfDecelerationCurves::getDistanceEBD(float vitesse)
{
	size_t i = 0;
	while (vitesse > EBD[i][1])
	{
		i++;
		if(i == EBD.size())
		{
			cout << "erreur dans getDistanceEBD" << endl;
			break;
		}
	}
	return EBD[i][0];
}
float DeterminationOfDecelerationCurves::getVistanceEBD(float distance)
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
	return EBD[i][1];
}

SpeedAndDistanceMonitoringCommands::SpeedAndDistanceMonitoringCommands(Train_dynamique &T_D, MostRestrictiveSpeedLimit &MRSP, SupervisionLimits &SL)
{
	this->T_D = &T_D;
	this->MRSP = &MRSP;
	this->SL = &SL;
	//cout << "SADMC" << endl;
}

void SpeedAndDistanceMonitoringCommands::SpeedAndDistanceMonitoringCommands_update()
{
	if(SL->getStatus() == "CSM")
	{
		//Triggering Conditions
		if(T_D->getV_train() <= MRSP->getV_MRSP() && supervision_status == "Normal")
			supervision_status = "Normal";
		if(T_D->getV_train() > MRSP->getV_MRSP() && supervision_status == "Normal")
			supervision_status = "Overspeed";
		if(T_D->getV_train() > SL->getV_warning() && supervision_status == "Overspeed")
			supervision_status = "Warning";
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
		}
		if(T_D->getV_train() <= MRSP->getV_MRSP() && supervision_status != "Intervention")
		{
			supervision_status = "Normal";
			if (command_triggered == "SB")
			{
				command_triggered = "";
			}
		}
	}	//cout << supervision_status << " " << command_triggered << endl;
	if(SL->getStatus() == "TSM")
	{
		if(T_D->getV_train() < int(SL->getV_indication()) && supervision_status != "Intervention")
			supervision_status = "Normal";
		if(T_D->getV_train() >= int(SL->getV_indication()) && supervision_status == "Normal")
			supervision_status = "Indication";
		if(T_D->getV_train() >= int(SL->getV_permitted()) && supervision_status == "Indication")
			supervision_status = "Overspeed";
		if(T_D->getV_train() >= int(SL->getV_warning()) && supervision_status == "Overspeed")
			supervision_status = "Warning";
		if(T_D->getV_train() >= int(SL->getV_ebi()))
		{
			supervision_status = "Intervention";
			command_triggered = "EB";
		}
		//Revocation conditions
		if(T_D->getV_train() == 0)
		{
			supervision_status = "Normal";
			command_triggered = "";
		}
		if(supervision_status != "Intervention")
		{
			if(T_D->getV_train() < SL->getV_indication())
				supervision_status = "Normal";
			else
			if(T_D->getV_train() <= SL->getV_permitted())
				supervision_status = "Indication";
			if(command_triggered == "SB")
			{
				command_triggered = "";
			}
		}
	}
	//cout << supervision_status << " ";
	//cout << T_D->getV_train() << " " << SL->getV_indication()<< " " << SL->getV_permitted()<< " " << SL->getV_warning() << " " << SL->getV_ebi();
}

string SpeedAndDistanceMonitoringCommands::getSupervision_status(){return supervision_status;}
string SpeedAndDistanceMonitoringCommands::getCommand_triggered(){return command_triggered;}
