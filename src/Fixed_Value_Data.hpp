#ifndef Fixed_Value_Data
#define Fixed_Value_Data

class Fixed_Value_Data
{
private:

float dV_ebi_min; //Speed difference between Permitted speed and Emergency Brake Intervention supervision limits, minimum value
int dV_ebi_max; //Speed difference between Permitted speed and Emergency Brake Intervention supervision limits, maximum value
int V_ebi_min; // Value of MRSP where dV_ebi starts to increase to dV_ebi_max
int V_ebi_max; // Value of MRSP where dV_ebi stops to increase to dV_ebi_max

// Valeurs definissant V_sbi

int dV_sbi_min; // Speed difference between Permitted speed and Service Brake Intervention supervision limits, minimum value
int dV_sbi_max;// Speed difference between Permitted speed and Service Brake Intervention supervision limits, maximum value
int V_sbi_min;  // Value of MRSP where dV_sbi starts to increase to dV_sbi_max
int V_sbi_max; // Value of MRSP where dV_sbi stops to increase to dV_sbi_max

// Valeurs definissant V_warning

int dV_warning_min; // Speed difference between Permitted speed and Warning supervision limits, minimum value
int dV_warning_max; // Speed difference between Permitted speed and Warning supervision limits, maximum value
int V_warning_min;  // Value of MRSP where dV_warning starts to increase to dV_warning_max
int V_warning_max;  // Value of MRSP where dV_warning stops to increase

// Autres valeurs

int T_dispTTI; // Time before the first Indication to display the TTI
int T_warning; // Time between Warning supervision limit and SBI
int T_driver; // Driver reaction time between Permitted speed supervision limit and SBI
float M_rotating_min; // Maximum possible rotating mass as a percentage of the total weight of the train
float M_rotating_max; // Minimum possible rotating mass as a percentage of the total weight of the train

public:

Fixed_Value_Data(); // Le constructeur
void Afficher_Fixed_value_data();
float getdV_ebi_min();
int getdV_ebi_max();
int getV_ebi_min();
int getV_ebi_max();
int getdV_sbi_min();
int getdV_sbi_max();
int getV_sbi_min();
int getV_sbi_max();
int getdV_warning_min();
int getdV_warning_max();
int getV_warning_min();
int getV_warning_max();
int getT_dispTTI();
int getT_warning();
int getT_driver();
float getM_rotating_min();
float getM_rotating_max();

};
#endif