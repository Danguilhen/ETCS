
#include "SpeedAndDistanceMonitoring.hpp"
#include "TrainRelatedInputs.hpp"
#include "TrackRelatedInputs.hpp"
#include "../Train_dynamique.hpp"

SpeedAndDistanceMonitoring::SpeedAndDistanceMonitoring(Train_dynamique &T_D)
{
	this->T_D = &T_D;
}

void SpeedAndDistanceMonitoring::MSRP(TrackRelatedInputs TrackRI)
{
	V_MRSP = TrackRI.TSR.getVitesseTableau()[0][2];
}

void SpeedAndDistanceMonitoring::Supervision_limits(TrainRelatedInputs TrainRI)
{
	if(V_MRSP <= TrainRI.FVD.getdV_ebi_min())
		V_ebi = V_MRSP+TrainRI.FVD.getdV_ebi_min();
	else if(V_MRSP <= TrainRI.FVD.getV_ebi_max())
		V_ebi = V_MRSP+TrainRI.FVD.getdV_ebi_min()+((TrainRI.FVD.getdV_ebi_max()-TrainRI.FVD.getdV_ebi_min())/(TrainRI.FVD.getV_ebi_max()-TrainRI.FVD.getV_ebi_min()))*(V_MRSP-TrainRI.FVD.getV_ebi_min());
	else
		V_ebi =V_MRSP+TrainRI.FVD.getdV_ebi_max();
	if(V_MRSP <= TrainRI.FVD.getV_sbi_min())
		V_sbi = V_MRSP + TrainRI.FVD.getdV_sbi_min();
	else if(V_MRSP <= TrainRI.FVD.getV_sbi_max())
		V_sbi = V_MRSP+TrainRI.FVD.getdV_sbi_min()+((TrainRI.FVD.getdV_sbi_max()-TrainRI.FVD.getdV_sbi_min()) / (TrainRI.FVD.getV_sbi_max() - TrainRI.FVD.getV_sbi_min())) * (V_MRSP - TrainRI.FVD.getV_sbi_min());
	else
		V_sbi = V_MRSP + TrainRI.FVD.getdV_sbi_max();
	if(V_MRSP <= TrainRI.FVD.getV_warning_min())
		V_warning = V_MRSP+TrainRI.FVD.getdV_warning_min();
	else if(V_MRSP <= TrainRI.FVD.getV_warning_max())
		V_warning = V_MRSP + TrainRI.FVD.getdV_warning_min() + ((TrainRI.FVD.getdV_warning_max() - TrainRI.FVD.getdV_warning_min()) / (TrainRI.FVD.getV_warning_max() - TrainRI.FVD.getV_warning_min())) * (V_MRSP - TrainRI.FVD.getV_warning_min());
	else
		V_warning = V_MRSP + TrainRI.FVD.getdV_warning_max();

	//cout << " MSRP " << V_MRSP << " EBI  " << V_ebi << " SBI " << V_sbi << " WARNING " << V_warning << " VTRAIN " << T_D.getV_train() << endl ;
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

int SpeedAndDistanceMonitoring::getV_MRSP(){return V_MRSP;}
int SpeedAndDistanceMonitoring::getV_ebi(){return V_ebi;}
int SpeedAndDistanceMonitoring::getV_sbi(){return V_sbi;}
int SpeedAndDistanceMonitoring::getV_warning(){return V_warning;}
string SpeedAndDistanceMonitoring::getStatus(){return status;}
string SpeedAndDistanceMonitoring::getSupervision_status(){return supervision_status;}
string SpeedAndDistanceMonitoring::getCommand_triggered(){return command_triggered;}
