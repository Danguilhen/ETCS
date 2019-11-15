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
	if(TrackRI.TSR.getVitesseTableau()[0][1] + TrainRI.T_data.getTrain_length() == 0)
		cout<<"ok";
	else
		cout<<TrackRI.TSR.getVitesseTableau()[0][1] + TrainRI.T_data.getTrain_length();
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

	std::cout << V_MRSP << " " << V_ebi << " " << V_sbi << " " << V_warning;
}

