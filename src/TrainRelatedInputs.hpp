#ifndef AA
#define AA

class Train_Categories
{
    private :
        std::string label;
        int cant_deficiency_train_category_value;
        std::string other_international_train_category_value;

    public:
        Train_Categories(std::string L, int C, std::string O);
        Train_Categories();

    //friend class Train_Data;

};
class Loading_gauge
{
    private :
        std::string Loading_gauge_label;
        //int Loading_gauge_value;

    public :
        Loading_gauge(std::string LGL);
        Loading_gauge();
    friend class Train_Data;
};

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


class Train_Data
{
    private :

        //création des TC grâce au constructeur de la classe TC et ajout dans le vector
        std::vector<Train_Categories> tab_TC_list;//création des listes de Train categories
        Train_Categories train_categories;//La valeur stockée
        int train_length = 100;
        int maximum_train_speed;
        std::vector<Loading_gauge> tab_LG_list;//création des listes de Loading gauge
        Loading_gauge loading_gauge;//la valeur stockée
        std::vector <std::string> axle_load_categories{"A", "B", "C", "D", "E", "F", "G"};//création des listes de Axle_load_category
        std::string axle_load_category;//la valeur stockée
        size_t traction_system; //ATTENTION donnée inconnue //DONNEE NON MODIFIABLE
        bool train_fitted_with_airtight_system;
        std::vector<std::string> list_of_national_systems_available_on_board{"TVM", "FR", "EN"};//DONNEE NON MODIFIABLE
        int axle_number;//DONNEE NON MODIFIABLE
        int Vtrain;

    public :
        Train_Data();
        int getTrain_length();

	    //GET ET SET A FAIRE SI NECESSAIRE
};

class TrainRelatedInputs
{
    public :

    Train_Data T_data;
    Fixed_Value_Data FVD;

};

#endif
