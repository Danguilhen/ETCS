#include "Fixed_Value_Data.hpp"
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

using namespace std;

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

}

void Fixed_Value_Data::Afficher_Fixed_value_data()
{

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

}

float Fixed_Value_Data::getdV_ebi_min()
{return dV_ebi_min;}
int Fixed_Value_Data::getdV_ebi_max()
{return dV_ebi_max;}
int Fixed_Value_Data::getV_ebi_min()
{return V_ebi_min;}
int Fixed_Value_Data::getV_ebi_max()
{return V_ebi_max;}
int Fixed_Value_Data::getdV_sbi_min()
{return dV_sbi_min;}
int Fixed_Value_Data::getdV_sbi_max()
{return dV_sbi_max;}
int Fixed_Value_Data::getV_sbi_min()
{return V_sbi_min;}
int Fixed_Value_Data::getV_sbi_max()
{return V_sbi_max;}
int Fixed_Value_Data::getdV_warning_min()
{return dV_warning_min;}
int Fixed_Value_Data::getdV_warning_max()
{return dV_warning_max;}
int Fixed_Value_Data::getV_warning_min()
{return V_warning_min;}
int Fixed_Value_Data::getV_warning_max()
{return V_warning_max;}
int Fixed_Value_Data::getT_dispTTI()
{return T_dispTTI;}
int Fixed_Value_Data::getT_warning()
{return T_warning;}
int Fixed_Value_Data::getT_driver()
{return T_driver;}
float Fixed_Value_Data::getM_rotating_min()
{return M_rotating_min;}
float Fixed_Value_Data::getM_rotating_max()
{return M_rotating_max;}