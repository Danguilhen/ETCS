
#include "SpeedAndDistanceMonitoring.hpp"
#include "TrainRelatedInputs.hpp"
#include "TrackRelatedInputs.hpp"
#include "../Train_dynamique.hpp"

SpeedAndDistanceMonitoring::SpeedAndDistanceMonitoring(Train_dynamique &T_D, TrainRelatedInputs &TrainRI, TrackRelatedInputs &TrackRI) : TBS(TrainRI, TrackRI)
{
	this->T_D = &T_D;
	this->TrainRI = &TrainRI;
	this->TrackRI = &TrackRI;
}

void SpeedAndDistanceMonitoring::MSRP()
{

	V_MRSP = TrackRI->TSR.getVitesseTableau()[0][2];

}

void SpeedAndDistanceMonitoring::SDM_Update()
{
	MSRP();
	Supervision_limits();
	SpeedAndDistanceMonitoringCommands();
	TBS.TBS_Update();
}

void SpeedAndDistanceMonitoring::Supervision_limits()
{
	float Cebi = (TrainRI->FVD.getdV_ebi_max() - TrainRI->FVD.getdV_ebi_min()) / (TrainRI->FVD.getV_ebi_max() - TrainRI->FVD.getV_ebi_min() );
	float Csbi = (TrainRI->FVD.getdV_sbi_max() - TrainRI->FVD.getdV_sbi_min()) / (TrainRI->FVD.getV_sbi_max() - TrainRI->FVD.getV_sbi_min() );
	float Cwarning = (TrainRI->FVD.getdV_warning_max() - TrainRI->FVD.getdV_warning_min()) / (TrainRI->FVD.getV_warning_max() - TrainRI->FVD.getV_warning_min() );
	float DV_ebi;
	float DV_sbi;
	float DV_warning;

	if(V_MRSP > TrainRI->FVD.getV_ebi_min())
	{
		DV_ebi = min(TrainRI->FVD.getdV_ebi_min() + Cebi*(V_MRSP - TrainRI->FVD.getV_ebi_min()), TrainRI->FVD.getdV_ebi_max());
	}
	else
	DV_ebi = TrainRI->FVD.getdV_ebi_min();
	if(V_MRSP > TrainRI->FVD.getV_sbi_min())
	{
		DV_sbi = min(TrainRI->FVD.getdV_sbi_min() + Csbi*(V_MRSP - TrainRI->FVD.getV_sbi_min()), TrainRI->FVD.getdV_sbi_max());
	}
	else
	DV_sbi = TrainRI->FVD.getdV_sbi_min();
	if(V_MRSP > TrainRI->FVD.getV_warning_min())
	{
		DV_warning = min(TrainRI->FVD.getdV_warning_min() + Cwarning*(V_MRSP - TrainRI->FVD.getV_warning_min()), TrainRI->FVD.getdV_warning_max());
	}
	else
	DV_warning = TrainRI->FVD.getdV_warning_min();

	V_ebi = V_MRSP + DV_ebi;
	V_sbi =	V_MRSP + DV_sbi;
	V_warning = V_MRSP + DV_warning;

	//if(V_MRSP <= TrainRI->FVD.getdV_ebi_min())
	//	V_ebi = V_MRSP+TrainRI->FVD.getdV_ebi_min();
	//else if(V_MRSP <= TrainRI->FVD.getV_ebi_max())
	//	V_ebi = V_MRSP+TrainRI->FVD.getdV_ebi_min()+((TrainRI->FVD.getdV_ebi_max()-TrainRI->FVD.getdV_ebi_min())/(TrainRI->FVD.getV_ebi_max()-TrainRI->FVD.getV_ebi_min()))*(V_MRSP-TrainRI->FVD.getV_ebi_min());
	//else
	//	V_ebi =V_MRSP+TrainRI->FVD.getdV_ebi_max();
	//if(V_MRSP <= TrainRI->FVD.getV_sbi_min())
	//	V_sbi = V_MRSP + TrainRI->FVD.getdV_sbi_min();
	//else if(V_MRSP <= TrainRI->FVD.getV_sbi_max())
	//	V_sbi = V_MRSP+TrainRI->FVD.getdV_sbi_min()+((TrainRI->FVD.getdV_sbi_max()-TrainRI->FVD.getdV_sbi_min()) / (TrainRI->FVD.getV_sbi_max() - TrainRI->FVD.getV_sbi_min())) * (V_MRSP - TrainRI->FVD.getV_sbi_min());
	//else
	//	V_sbi = V_MRSP + TrainRI->FVD.getdV_sbi_max();
	//if(V_MRSP <= TrainRI->FVD.getV_warning_min())
	//	V_warning = V_MRSP+TrainRI->FVD.getdV_warning_min();
	//else if(V_MRSP <= TrainRI->FVD.getV_warning_max())
	//	V_warning = V_MRSP + TrainRI->FVD.getdV_warning_min() + ((TrainRI->FVD.getdV_warning_max() - TrainRI->FVD.getdV_warning_min()) / (TrainRI->FVD.getV_warning_max() - TrainRI->FVD.getV_warning_min())) * (V_MRSP - TrainRI->FVD.getV_warning_min());
	//else
	//	V_warning = V_MRSP + TrainRI->FVD.getdV_warning_max();
//
	//cout << " MSRP " << V_MRSP << " EBI  " << V_ebi << " SBI " << V_sbi << " WARNING " << V_warning /*<< " VTRAIN " << T_D.getV_train() */<< endl ;
}

void SpeedAndDistanceMonitoring::SpeedAndDistanceMonitoringCommands()
{
	//Triggering Conditions
	if(T_D->getV_train() <= V_MRSP && supervision_status == "Normal")
		supervision_status = "Normal";
	if(T_D->getV_train() > V_MRSP && supervision_status == "Normal")
		supervision_status = "Overspeed";
	if(T_D->getV_train() > V_warning && supervision_status == "Overspeed")
		supervision_status = "Warning";
	/*if(T_D->getV_train() > V_sbi)//à voir avec Benoit
	{
		supervision_status = "Intervention";
		command_triggered = "SB";
	}*/
	if(T_D->getV_train() > V_ebi && supervision_status == "Warning")
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
	if(T_D->getV_train() <= V_MRSP && supervision_status != "Intervention")
	{
		supervision_status = "Normal";
		if (command_triggered == "SB")
		{
			command_triggered = "";
		}
	}
	//cout << supervision_status << " " << command_triggered << endl;
}

float SpeedAndDistanceMonitoring::getV_MRSP(){return V_MRSP;}
float SpeedAndDistanceMonitoring::getV_ebi(){return V_ebi;}
float SpeedAndDistanceMonitoring::getV_sbi(){return V_sbi;}
float SpeedAndDistanceMonitoring::getV_warning(){return V_warning;}
string SpeedAndDistanceMonitoring::getStatus(){return status;}
string SpeedAndDistanceMonitoring::getSupervision_status(){return supervision_status;}
string SpeedAndDistanceMonitoring::getCommand_triggered(){return command_triggered;}

Traction_Braking_system::Traction_Braking_system(TrainRelatedInputs &TrainRI, TrackRelatedInputs &TrackRI)
{
	this->TrackRI = &TrackRI;
	this->TrainRI = &TrainRI;
}

void Traction_Braking_system::TBS_Update()
{
	//vector<float> temp;
	////gradient
	//for(size_t i = 0; i < (TrackRI->gradient_ligne.getTab_Gradient().size()); i++)
	//{
	//	if(TrainRI->T_data.getM_rotating_nom())//dans le cas ou la valeur nom est connue
	//	{
	//		float calcul = Constant_G*TrackRI->gradient_ligne.getTab_Gradient()[i][0]/(1000+10*TrainRI->T_data.getM_rotating_nom());
	//		cout << "A_grad : " << calcul << endl;
	//		step(A_gradient, TrackRI->gradient_ligne.getTab_Gradient()[i][0], TrackRI->gradient_ligne.getTab_Gradient()[i][1], calcul);
	//	}
	//}
	////else cas où il n'y a pas TrainRI->T_data.getM_rotating_nom() page 104 subset 26 chap 3
	////A_safe
	//if(TrackRI->getTargetDistance() > 0)
	//	for(int distance = 0; distance <= 10000; distance++)
	//	{
	//		size_t j = -1;
	//		size_t k = -1;
	//		do
	//		{
	//			j++;
	//			if(j > A_brake_emergency.size() - 1)
	//				cout<<"probleme avec A_brake_emergency";
	//		} while (distance > A_brake_emergency[j][1]);//On détermine quelle décélération utiliser pour la distance concernée
	//		do
	//		{
	//			k++;
	//			if(k > A_gradient.size() - 1)
	//				cout<<"probleme avec A_gradient";
	//			cout<<k<<">"<<A_gradient[k][1]<<endl;
	//		} while (distance > A_gradient[k][1]);//On détermine quelle décélération utiliser pour la distance concernée
	//		temp.push_back(distance + 1);
	//		temp.push_back(A_brake_emergency[j][2] + A_gradient[k][2]);
	//		A_safe.push_back(temp);
	//	}
	//cout<<A_safe[5000][2]<<endl;

}