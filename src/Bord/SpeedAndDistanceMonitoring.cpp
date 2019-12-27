#include <cstdlib>
#include <iostream>
#include <thread>
#include <math.h>
#include <string>
#include <ctime>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include "TrackRelatedInputs.hpp"
#include "TrainRelatedInputs.hpp"
#include "SpeedAndDistanceMonitoring.hpp"

using namespace std;

void SpeedAndDistanceMonitoring::MSRP(TrackRelatedInputs TrackRI, TrainRelatedInputs TrainRI)
{
	if(TrackRI.TSR.getVitesseTableau()[0][1] + TrainRI.T_data.getTrain_length() < 0)
	{
		//cout << "changement";
		V_MRSP = TrackRI.TSR.getVitesseTableau()[0][0];
		TrackRI.TSR.getVitesseTableau().erase(TrackRI.TSR.getVitesseTableau().begin());
	}
	/*else
		cout << TrackRI.TSR.getVitesseTableau()[0][1] + TrainRI.T_data.getTrain_length() << " " << endl;
		*/
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

	//std::cout << " MSRP " << V_MRSP << " EBI  " << V_ebi << " SBI " << V_sbi << " WARNING " << V_warning << " VTRAIN " << TrainRI.T_data.getVtrain() << endl ;
}

void SpeedAndDistanceMonitoring::SpeedAndDistanceMonitoringCommands(TrainRelatedInputs TrainRI)
{
	//Triggering Conditions
	if(TrainRI.T_data.getVtrain() <= V_MRSP)
		supervision_status = "Normal";
	if(TrainRI.T_data.getVtrain() > V_MRSP)
		supervision_status = "Overspeed";
	if(TrainRI.T_data.getVtrain() > V_warning)
		supervision_status = "Warning";
	/*if(TrainRI.T_data.getVtrain() > V_sbi)//à voir avec Benoit
	{
		supervision_status = "Intervention";
		command_triggered = "SB";
	}*/
	if(TrainRI.T_data.getVtrain() > V_ebi)
	{
		supervision_status = "Intervention";
		command_triggered = "EB";
	}

	//Revocation conditions
	if(TrainRI.T_data.getVtrain() == 0 && supervision_status == "Intervention")
	{
		supervision_status = "Normal";
		command_triggered = "";
	}
	if(TrainRI.T_data.getVtrain() <= V_MRSP && supervision_status != "Intervention")
	{
		supervision_status = "Normal";
		if (command_triggered == "SB")
		{
			command_triggered = "";
		}
	}
	//std::cout << supervision_status << " " << command_triggered << endl;
}

int SpeedAndDistanceMonitoring::getV_MRSP(){return V_MRSP;}
int SpeedAndDistanceMonitoring::getV_ebi(){return V_ebi;}
int SpeedAndDistanceMonitoring::getV_sbi(){return V_sbi;}
int SpeedAndDistanceMonitoring::getV_warning(){return V_warning;}
std::string SpeedAndDistanceMonitoring::getStatus(){return status;}
std::string SpeedAndDistanceMonitoring::getSupervision_status(){return supervision_status;}
std::string SpeedAndDistanceMonitoring::getCommand_triggered(){return command_triggered;}