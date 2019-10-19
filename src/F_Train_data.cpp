#include "F_Train_data.hpp"

#include <string>
#include <cstdlib>
#include <vector>
#include <unistd.h>
#include <iostream>

using namespace std;

float Train_data::A_Brake(int v)
{
    int i = 0;
	if(v > tab_A_brake[tab_A_break.end()][0])
		return int(tab_A_brake[i][0]);
    else while(v > int(tab_A_brake[i][0]))
        i++;
	return int(tab_A_brake[i][0]);
}




//SUBSET 026

#include <algorithm>    // std::min
#include <iostream>
using namespace std;

float A_gradient(int d)
{
	int g = 9.81;
	if(M_rotating_nom > 0) // On considère la masse en rotation connu
		return (g * grad) / (1000 + 10 * M_rotating_nom);
	else if(grad >= 0)
		return (g * grad) / (1000 + 10 * M_rotating_max);
	else
		return (g * grad) / (1000 + 10 * M_rotating_min);
}

int Kv_int(int speed)
{
	if(speed >= 0 && speed <= V1) //Kv_int_0
		return Kv_int_x(0);
	else if(speed >= V1 && speed <= V2) //Kv_int_1
		return Kv_int_x(1);
	else if(speed >= V2 && speed <= V3) //Kv_int_2
		return Kv_int_x(2);
	else if(speed >= V3) //Kv_int_3
		return Kv_int_x(3);
}

int Kv_int_x(int x)
{
	if(A_ebmax <= A_P12)
		return Kv_int_x_a(x);
	else if(A_ebmax >= A_P23)
		return Kv_int_x_b(x);
	else
		return Kv_int_x_a(x) + (A_ebmax - A_P12) / (A_P23 - A_P12) * (Kv_int_x_b(x) - Kv_int_x_a(x));
}

int A_brake_safe(int speed, int d)
{
	if() //part of Train Data
		return Kdry_rst(speed, M_NVEBCL) * (Kwet_rst(speed) + M_NVAVADH * (1 - Kwet_rst(V))) * A_brake_emergency(speed, d);
	else //conversion model used
		return Kv_int(speed) * Kr_int(L_train) * A_brake_emergency(speed, d);
}

int A_brake_emergency(int speed, int d)
{
	if(d <= d1 && d >= destfront)
		return A_brake_emergency1(speed);
	else if(d <= d2 && d>= d1)
		return A_brake_emergency2(speed);
	else if(d <= d3 && d>= d2)
		return A_brake_emergency3(speed);
	//?????????????
}

int A_safe(int speed, int d)
{
	if() //?????????
		return A_brake_safe(speed, d) + A_gradient(d);
	else //?????????
		return min(A_brake_safe(speed, d), A_MAXREDADH) + A_gradient(d);
}

int A_expected(int speed, int d)
{
	return A_brake_service(speed, d) + A_gradient(d);
}

int A_normal_service(int speed, int d)
{
	// grad = gradient values in ‰ (positive = uphill)
	if() //positive gradient values (uphill)
		return A_brake_normal_service(speed, d) + A_gradient(d) - KnPlus(speed) * grad / 1000;
	else //negative gradient values (downhill)
		return A_brake_normal_service(speed, d) + A_gradient(d) - KnMoins(speed) * grad / 1000;
}

int A_brake_normal_service(int speed, int d)
{
	if(d <= d1 && d >= destfront)
		return A_brake_normal_service1(speed);
	else if(d <= d2 && d >= d1)
		return A_brake_normal_service2(speed);
	else if(d <= d3 && d >= d2)
		return A_brake_normal_service3(speed);
	// ... condinuer avec d4 d5 ... ???????????????? voir ci-dessous
	"""d 1 , d 2 , d 3 ,... are the locations with change of special brake(s) contribution
	A_brake_normal_service x (V) is equal to the normal service brake model applicable for
	the concerned combination of brake position and of the value of A_brake_service(V=0)
	between d x-1 and d x (see 3.13.2.2.3.1.9 and 3.13.2.2.3.1.10)."""
}

int A_brake_service(int speed, int d)
{
	if(d <= d1 && d >= destfront)
		return A_brake_service1(speed);
	else if(d <= d2 && d >= d1)
		return A_brake_service2(speed);
	else if(d <= d3 && d >= d2)
		return A_brake_service3(speed);
	// ... condinuer avec d4 d5 ... ???????????????? voir ci-dessous
	"""d 1 , d 2 , d 3 ,... are the locations with change of special brake(s) contribution
	A_brake_service x (V) is equal to the full service brake model, A_brake_service,
	applicable for the concerned combination of brake."""
}

//information sur A_gradient dans dans 3.13.4 <---













//A partir d'ici c'est Benoît <--------------------------------------------------------------------------------------------------------------------------------------------

//****************************************************************************************************

//PROGRAMME DEFINE: regroupe toutes les variables utilisées par les sous-sous-sous programme. J'actualise au cours de mon travail. On pourrait tout consiger ici d'ailleurs si vous voulez

// Define des valeurs de la SRS 360 (subset 026)

// Valeurs definissant V_ebi

#define dV_ebi_min 7.5 //Speed difference between Permitted speed and Emergency Brake Intervention supervision limits, minimum value
#define dV_ebi_max 15 //Speed difference between Permitted speed and Emergency Brake Intervention supervision limits, maximum value
#define V_ebi_min 110 // Value of MRSP where dV_ebi starts to increase to dV_ebi_max
#define V_ebi_max 210 // Value of MRSP where dV_ebi stops to increase to dV_ebi_max

// Valeurs definissant V_sbi

#define dV_sbi_min 5.5 // Speed difference between Permitted speed and Service Brake Intervention supervision limits, minimum value
#define dV_sbi_max 10 // Speed difference between Permitted speed and Service Brake Intervention supervision limits, maximum value
#define V_sbi_min 110 // Value of MRSP where dV_sbi starts to increase to dV_sbi_max
#define V_sbi_max 210 // Value of MRSP where dV_sbi stops to increase to dV_sbi_max

// Valeurs definissant V_warning

#define dV_warning_min 4 // Speed difference between Permitted speed and Warning supervision limits, minimum value
#define dV_warning_max 5 // Speed difference between Permitted speed and Warning supervision limits, maximum value
#define V_warning_min 110 // Value of MRSP where dV_warning starts to increase to dV_warning_max
#define V_warning_max 140 // Value of MRSP where dV_warning stops to increase

// Valeurs definissant les masses rotatives

#define M_rotating_max 0.15 // Maximum possible rotating mass as a percentage of the total weight of the train

#define M_rotating_min 0.02 // Minimum possible rotating mass as a percentage of the total weight of the train


//****************************************************************************************************



//?: pourcentage de freinage



//NATIONAL VALUE/DEFAULT VALUE



//FIXED VALUE

//Cf A31 de la Subset 026

//***************************************************************************************************

//PROGRAMME GET VITESSE

//Get_V Fait partie de l'EVC

//lundi 10 juin 2019
//13:44

float V_ebi(float V_MRSP)
{
	if(V_MRSP <= V_ebi_min)
		return (V_MRSP+dV_ebi_min);
	else if(V_MRSP <= V_ebi_max)
		return (V_MRSP+dV_ebi_min+((dV_ebi_max-dV_ebi_min)/(V_ebi_max-V_ebi_min))*(V_MRSP-V_ebi_min));
	else
		return (V_MRSP+dV_ebi_max);
}

float V_sbi(float V_MRSP)
{
	if(V_MRSP <= V_sbi_min)
		return (V_MRSP + dV_sbi_min);
	else if(V_MRSP <= V_sbi_max)
		return (V_MRSP+dV_sbi_min+((dV_sbi_max-dV_sbi_min) / (V_sbi_max - V_sbi_min)) * (V_MRSP - V_sbi_min));
	else
		return (V_MRSP + dV_sbi_max);
}

float V_warning(float V_MRSP)
{
	if(V_MRSP <= V_warning_min)
		return V_MRSP+dV_warning_min;
	else if(V_MRSP <= V_warning_max)
		return V_MRSP + dV_warning_min + ((dV_warning_max - dV_warning_min) / (V_warning_max - V_warning_min)) * (V_MRSP - V_warning_min);
	else
		return V_MRSP + dV_warning_max;
}

//***************************************************************************************************************************************************

//Get A_basis(V)

//lundi 10 juin 2019
//13:53

//POUR LE SERVICE BRAKE

float A_basic(int V, ?)
{
/* mettre en paramètre:
? en cas de A_brake_emergency
MIN(135,?) en cas de A_brake_service
*/

// Calcul de la limite du premier échelon. Valeurs empiriques de la 026.
//V_lim=16.85*?^0.428;

// Calcul de l'accélération basic en fonction de la vitesse du train. Valeurs empiriques de la 026.

	if(V < V_lim)
		return 0.075 * V ^ 0.076;
	else if(V_lim < 100 && V <= 100) //n1
		return (-6.30*10^(-7))*(?^3) + (6.10*10^(-5))*(?^2) + (4.72^(-3))*? + 0.0663;
	else if((V <= 120 && V_lim < 120 && V_lim > 100) || (V_lim  <= 100 && V <= 120 && V > 100)) //n2
		return (2.73*10^(-7))*(?^3) + (-4.54*10^(-6))*(?^2) + (5.14*10^(-3))*?+ 0.1300;
	else if((V <= 150 && V_lim < 150 && V_lim > 120) || (V_lim  <= 120 && V <= 150 && V > 120)) //n3
		return ((5.58 * 10 ^ (-8)) * (? ^ 3) + (-6.76*10^(-6)) * (?^2) + (5.81 * 10 ^ (-3)) * ? + 0.0479);
	else if((V <= 180 && V_lim < 180 && V_lim > 150) || (V_lim <= 150 && V <= 180 && V > 150)) //n4
		return (3.00*10^(-8))*(?^3) + (-3.85*10^(-6))*(?^2) + (5.52*10^(-3))*? + 0.0480;
	else if((V>180 && V_lim <=180) || V_lim > 180 ) //n5
		return (3.23*10^(-9))*(?^3) + (1.66*10^(-6))*(?^2) + (5.06*10^(-3))*? + 0.0559;
	else
	{
		Cout << "erreur condition calcul A_basic (bon courage)" << endl;
		return 0;
	}
}


//**********************************************************************************************************************************************
//emergency brake equivalent time

//vendredi 5 juillet 2019
//14:44

float T_brake_emergency(Train_type, Train_lenght, Braking_position, V_target)
{
	/* mettre en paramètre:
	Train_type freight/passenger
	Train_length
	Brake_position
	*/
	int T_brake_basic_eb = 0;

	if(Train_type == passenger && Brake_position == P)
		T_brake_basic_eb = 2.30 + 0.17 * ((Max(400, Train_lenght)) / 100) ^ 2;
	else if(Train_type == freight && Brake_position == P)
	{
		if(Train_lenght <= 900)
			T_brake_basic_eb = 2.30 + 0.17 * ((Max(400, Train_lenght)) / 100) ^ 2;
		else if(900 < Train_lenght <= 1500)
			T_brake_basic_eb = -0.40 + 1.60 * ((Max(400, Train_lenght)) / 100) + 0.03 * ((Max(400, Train_lenght)) / 100) ^ 2;
	}
	else if(Train_type == freight && Brake_position == G)
	{
		if(Train_lenght <= 900)
			T_brake_basic_eb = 12.00 + 0.05 * (Train_lenght / 100) ^ 2;
		else if(900 < Train_lenght <= 1500)
			T_brake_basic_eb = -0.40 + 1.60 * (Train_lenght / 100) + 0.03 * (Train_lenght / 100) ^ 2;
	}
	else
	{
		Cout << "erreur condition calcul emergency_brake_equivalent_time" << endl;
		return 0;
	}
	if(V_target == 0)
		return T_brake_basic_eb;
	else if((Train_type == passenger) || (Train_type == freight && Braking_position == P))
		return (1 + 0.20) * T_brake_basic_eb;
	else if (Train_type == freight && Braking_position == G)
		return (1 + 0.16) * T_brake_basic_eb;
	else
	{
		cout << "probleme de condition pour le T_brake_emergency" << endl;
		return 0;
	}
}

//********************************************************************************************************************************************************

//Calculation of the full service brake equivalent time

//vendredi 5 juillet 2019
//15:45

float T_brake_basic_sb(Train_type, Train_lenght, Braking_position, V_target)
{
	/* mettre en paramètre:
	Train_type freight/passenger
	Train_length
	Brake_position
	*/
	int T_brake_basic_sb = 0;

	if(Train_type == passenger && Brake_position == P)
		T_brake_basic_sb = 2.30 + 0.17 * ((Max(400, Train_lenght)) / 100) ^ 2;
	else if(Train_type == freight && Brake_position == P )
	{
		if(Train_lenght <= 900)
			T_brake_basic_sb = 2.30 + 0.17 * ((Max(400, Train_lenght)) / 100) ^ 2;
		else if(900 < Train_lenght <= 1500)
			T_brake_basic_sb = -0.40 + 1.60 * ((Max(400, Train_lenght)) / 100) + 0.03 * ((Max(400, Train_lenght)) / 100) ^ 2;
	}
	else if(Train_type == freight && Brake_position == G)
	{
		if(Train_lenght <= 900)
			T_brake_basic_sb = 12.00 + 0.05 * (Train_lenght / 100) ^ 2;
		else if(900 < Train_lenght <= 1500)
			T_brake_basic_sb = -0.40 + 1.60 * (Train_lenght / 100) + 0.03 * (Train_lenght / 100) ^ 2;
	}
	else
	{
		Cout << "erreur condition calcul full_service_brake_equivalent_time"<<;
		return 0;
	}
	if(V_target == 0)
		return T_brake_basic_sb;
	else if((Train_type == passenger) || (Train_type == freight && Braking_position == P))
		return (1 + 0.20) * T_brake_basic_sb;
	else if(Train_type == freight && Braking_position == G)
		return(1 + 0.16) * T_brake_basic_sb;
	else
	{
		cout<<"probleme de condition pour le T_brake_emergency";
		return 0;
	}
}

//******************************************************************************************************************************************
