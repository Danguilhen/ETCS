#ifndef TRI
#define TRI

class Train_Categories
{
    private :
        std::string label;
        int cant_deficiency_train_category_value;
        std::string other_international_train_category_value;

    public:
        Train_Categories(std::string L, int C, std::string O)
        {
            label = L;
            cant_deficiency_train_category_value = C;
            other_international_train_category_value = O;
        }
        Train_Categories(){}

    //friend class Train_Data;

};
class Loading_gauge
{
    private :
        std::string Loading_gauge_label;
        //int Loading_gauge_value;

    public :
        Loading_gauge(std::string LGL)
        {
            Loading_gauge_label = LGL;
            //Loading_gauge_value = LGV; n'a pas d'importance dans la suite
        }
        Loading_gauge(){}
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
        public :

        //création des TC grâce au constructeur de la classe TC et ajout dans le vector
        std::vector<Train_Categories> tab_TC_list;//création des listes de Train categories
        Train_Categories train_categories;//La valeur stockée

        int train_length;

        int maximum_train_speed;

        std::vector<Loading_gauge> tab_LG_list;//création des listes de Loading gauge
        Loading_gauge loading_gauge;//la valeur stockée

        std::vector <std::string> axle_load_categories{"A", "B", "C", "D", "E", "F", "G"};//création des listes de Axle_load_category
        std::string axle_load_category;//la valeur stockée

        size_t traction_system; //ATTENTION donnée inconnue //DONNEE NON MODIFIABLE

        bool train_fitted_with_airtight_system;

        std::vector<std::string> list_of_national_systems_available_on_board{"TVM", "FR", "EN"};//DONNEE NON MODIFIABLE

        int axle_number;//DONNEE NON MODIFIABLE

    Train_Data()
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
    }
    int Vtrain;

	//GET ET SET A FAIRE SI NECESSAIRE
};

class TrainRelatedInputs
{
    public :

    Train_Data T_data;
    Fixed_Value_Data FVD;

};

#endif
