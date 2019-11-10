#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "TrackRelatedInputs.hpp"

using namespace std;

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
M_NVAVADH = 0;
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
float National_Value_Data::getD_NVROLL()
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
float National_Value_Data::getT_NVOVTRP()
{return T_NVOVTRP;}
bool National_Value_Data::getM_NVDERUN()
{return M_NVDERUN;}
bool National_Value_Data::getM_NVCONTACT()
{return M_NVCONTACT;}
float National_Value_Data::getT_NVCONTAC()
{return T_NVCONTAC;}
float National_Value_Data::getD_NVPOTRP()
{return D_NVPOTRP;}
float National_Value_Data::getD_NVSTFF()
{return D_NVSTFF;}
float National_Value_Data::getQ_NVLOCACC()
{return Q_NVLOCACC;}
float National_Value_Data::getM_NVAVADH()
{return M_NVAVADH;}
float National_Value_Data::getM_NVEBCL()
{return M_NVEBCL;}
float National_Value_Data::getL_NVKRINT()
{return L_NVKRINT;}
float National_Value_Data::getM_NVKRINT()
{return M_NVKRINT;}
float National_Value_Data::getV_NVKVINT()
{return V_NVKVINT;}
float National_Value_Data::getM_NVKVINT()
{return M_NVKVINT;}
float National_Value_Data::getM_NVKTINT()
{return M_NVKTINT;}
float National_Value_Data::getA_NVMAXREDADH1()
{return A_NVMAXREDADH1;}
float National_Value_Data::getA_NVMAXREDADH2()
{return A_NVMAXREDADH2;}
float National_Value_Data::getA_NVMAXREDADH3()
{return A_NVMAXREDADH3;}
float National_Value_Data::getA_NVP12()
{return A_NVP12;}
float National_Value_Data::getA_NVP23()
{return A_NVP23;}

