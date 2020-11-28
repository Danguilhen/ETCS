#include "TrainRelatedInputs.hpp"


Fixed_Value_Data::Fixed_Value_Data()
{
	dV_ebi_min = 7.5;
	dV_ebi_max = 15;
	V_ebi_min = 110;
	V_ebi_max = 210;
	dV_sbi_min = 5.5;
	dV_sbi_max = 10;
	V_sbi_min = 110;
	V_sbi_max = 210;
	dV_warning_min = 4;
	dV_warning_max = 5;
	V_warning_min = 110;
	V_warning_max = 140;
	T_dispTTI = 14;
	T_warning = 2;
	T_driver = 4;
	M_rotating_min =  0.2;
	M_rotating_max = 0.15;
    //cout << "FV" << endl;
}

void Fixed_Value_Data::Afficher_Fixed_value_data()
{
    cout<< "vous trouverez ci-dessous les fixed_value_data" << endl << endl;
    cout << "dV_ebi_min = " <<  dV_ebi_min << " km/h" << endl;
    cout << "dV_ebi_max = " << dV_ebi_max << " km/h" << endl;
    cout << "V_ebi_min = " << V_ebi_min <<  " km/h" << endl;
    cout << "V_ebi_max = " << V_ebi_max <<" km/h" << endl;
    cout << "dV_sbi_min = " << dV_sbi_min <<" km/h" << endl;
    cout << "dV_sbi_max = " << dV_sbi_max <<" km/h" << endl;
    cout << "V_sbi_min = " << V_sbi_min <<" km/h" << endl;
    cout << "V_sbi_max = " << V_sbi_max <<" km/h" << endl;
    cout << "dV_warning_min = " << dV_warning_min << " km/h" << endl;
    cout << "dV_warning_max = " << dV_warning_max << " km/h" << endl;
    cout << "V_warning_min = " << V_warning_min << " km/h" << endl;
    cout << "V_warning_max = " << V_warning_max << " km/h" << endl;
    cout << "T_dispTTI = " << T_dispTTI << " s" << endl;
    cout << "T_warning = " << T_warning << " s" << endl;
    cout << "T_driver = " << T_driver << " s" << endl;
    cout << "M_rotating_min = " << M_rotating_min << " % de masse" << endl;
    cout << "M_rotating_max = " << M_rotating_max << " % de masse" << endl;
    cout<<endl<< "fin fixed_value_data" << endl << endl;
}

double Fixed_Value_Data::getdV_ebi_min()
{return dV_ebi_min;}
double Fixed_Value_Data::getdV_ebi_max()
{return dV_ebi_max;}
double Fixed_Value_Data::getV_ebi_min()
{return V_ebi_min;}
double Fixed_Value_Data::getV_ebi_max()
{return V_ebi_max;}
double Fixed_Value_Data::getdV_sbi_min()
{return dV_sbi_min;}
double Fixed_Value_Data::getdV_sbi_max()
{return dV_sbi_max;}
double Fixed_Value_Data::getV_sbi_min()
{return V_sbi_min;}
double Fixed_Value_Data::getV_sbi_max()
{return V_sbi_max;}
double Fixed_Value_Data::getdV_warning_min()
{return dV_warning_min;}
double Fixed_Value_Data::getdV_warning_max()
{return dV_warning_max;}
double Fixed_Value_Data::getV_warning_min()
{return V_warning_min;}
double Fixed_Value_Data::getV_warning_max()
{return V_warning_max;}
double Fixed_Value_Data::getT_dispTTI()
{return T_dispTTI;}
double Fixed_Value_Data::getT_warning()
{return T_warning;}
double Fixed_Value_Data::getT_driver()
{return T_driver;}
double Fixed_Value_Data::getM_rotating_min()
{return M_rotating_min;}
double Fixed_Value_Data::getM_rotating_max()
{return M_rotating_max;}

Loading_gauge::Loading_gauge(){}
Loading_gauge::Loading_gauge(string LGL)
{
    Loading_gauge_label = LGL;
    //Loading_gauge_value = LGV; n'a pas d'importance dans la suite
}
Train_Categories::Train_Categories(){ /*cout << "TC" << endl;*/}
Train_Categories::Train_Categories(string L, int C, string O)
{
    label = L;
    cant_deficiency_train_category_value = C;
    other_international_train_category_value = O;
}

Train_Data::Train_Data()
{
    Loading_gauge LG1("G1");
    Loading_gauge LGA("GA");
    Loading_gauge LGB("GB");
    Loading_gauge LGC("GC");
    Loading_gauge LGOUT_OF_C("GOUT_OF_C");
    tab_LG_list.push_back(LG1);
    tab_LG_list.push_back(LGA);
    tab_LG_list.push_back(LGB);
    tab_LG_list.push_back(LGC);
    tab_LG_list.push_back(LGOUT_OF_C);
    Train_Categories PASS1("PASS 1", 80, "PASSENGER TRAIN IN P");
    Train_Categories PASS2("PASS 2", 130, "PASSENGER TRAIN IN P");
    Train_Categories PASS3("PASS 3", 150, "PASSENGER TRAIN IN P");
    Train_Categories TILT1("TILT 1", 165, "PASSENGER TRAIN IN P");
    Train_Categories TILT2("TILT 2", 180, "PASSENGER TRAIN IN P");
    Train_Categories TILT3("TILT 3", 210, "PASSENGER TRAIN IN P");
    Train_Categories TILT4("TILT 4", 225, "PASSENGER TRAIN IN P");
    Train_Categories TILT5("TILT 5", 245, "PASSENGER TRAIN IN P");
    Train_Categories TILT6("TILT 6", 275, "PASSENGER TRAIN IN P");
    Train_Categories TILT7("TILT 7", 300, "PASSENGER TRAIN IN P");
    Train_Categories FP1("FP 1", 80, "Freight train in P");
    Train_Categories FP2("FP 2", 100, "Freight train in P");
    Train_Categories FP3("FP 3", 130, "Freight train in P");
    Train_Categories FP4("FP 4", 150, "Freight train in P");
    Train_Categories FG1("FG 1", 80, "Freight train in G");
    Train_Categories FG2("FG 2", 100, "Freight train in G");
    Train_Categories FG3("FG 3", 130, "Freight train in G");
    Train_Categories FG4("FG 4", 150, "Freight train in G");
    tab_TC_list.push_back(PASS1);
    tab_TC_list.push_back(PASS2);
    tab_TC_list.push_back(PASS3);
    tab_TC_list.push_back(TILT1);
    tab_TC_list.push_back(TILT2);
    tab_TC_list.push_back(TILT3);
    tab_TC_list.push_back(TILT4);
    tab_TC_list.push_back(TILT5);
    tab_TC_list.push_back(TILT6);
    tab_TC_list.push_back(TILT7);
    tab_TC_list.push_back(FP1);
    tab_TC_list.push_back(FP2);
    tab_TC_list.push_back(FP3);
    tab_TC_list.push_back(FP4);
    tab_TC_list.push_back(FG1);
    tab_TC_list.push_back(FG2);
    tab_TC_list.push_back(FG3);
    tab_TC_list.push_back(FG4);
    //cout << "TrainData"<< endl;
}
int Train_Data::getTrain_length(){return train_length;}

int Train_Data::getM_rotating_nom(){return M_rotating_nom;}
int Train_Data::getDriverID(){return DriverID;}
void Train_Data::setDriverID(int D){DriverID = D;}
int Train_Data::getTrainRunningNumber(){return TrainRunningNumber;}
void Train_Data::setTrainRunningNumber(int T){TrainRunningNumber = T;}
std::string Train_Data::getLevel(){return level;}
void Train_Data::setLevel(std::string L){level = L;}
std::vector<std::string> Train_Data::getlist_of_national_systems_available_on_board(){return list_of_national_systems_available_on_board;}


OnBoardCorrectionFactors::OnBoardCorrectionFactors()
{
    //cout << "OBCF" << endl;
}

double OnBoardCorrectionFactors::getK_dry()
{
    return K_dry;
}
void OnBoardCorrectionFactors::setK_dry(double K){K_dry = K;}
double OnBoardCorrectionFactors::getK_wet()
{
    if(!dry)
        return K_wet;
    else
        return 0;
}
void OnBoardCorrectionFactors::setK_wet(double K){K_wet = K;}
bool OnBoardCorrectionFactors::getDry(){return dry;}
void OnBoardCorrectionFactors::setDry(bool D){dry = D;}

