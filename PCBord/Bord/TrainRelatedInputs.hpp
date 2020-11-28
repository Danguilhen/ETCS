#ifndef AA
#define AA

#include "../define.hpp"
#include "../Tools.hpp"

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

double dV_ebi_min; //Speed difference between Permitted speed and Emergency Brake Intervention supervision limits, minimum value
double dV_ebi_max; //Speed difference between Permitted speed and Emergency Brake Intervention supervision limits, maximum value
double V_ebi_min; // Value of MRSP where dV_ebi starts to increase to dV_ebi_max
double V_ebi_max; // Value of MRSP where dV_ebi stops to increase to dV_ebi_max

// Valeurs definissant V_sbi

double dV_sbi_min; // Speed difference between Permitted speed and Service Brake Intervention supervision limits, minimum value
double dV_sbi_max;// Speed difference between Permitted speed and Service Brake Intervention supervision limits, maximum value
double V_sbi_min;  // Value of MRSP where dV_sbi starts to increase to dV_sbi_max
double V_sbi_max; // Value of MRSP where dV_sbi stops to increase to dV_sbi_max

// Valeurs definissant V_warning

double dV_warning_min; // Speed difference between Permitted speed and Warning supervision limits, minimum value
double dV_warning_max; // Speed difference between Permitted speed and Warning supervision limits, maximum value
double V_warning_min;  // Value of MRSP where dV_warning starts to increase to dV_warning_max
double V_warning_max;  // Value of MRSP where dV_warning stops to increase

// Autres valeurs

double T_dispTTI; // Time before the first Indication to display the TTI
double T_warning; // Time between Warning supervision limit and SBI
double T_driver; // Driver reaction time between Permitted speed supervision limit and SBI
double M_rotating_min; // Maximum possible rotating mass as a percentage of the total weight of the train
double M_rotating_max; // Minimum possible rotating mass as a percentage of the total weight of the train

public:

Fixed_Value_Data(); // Le constructeur
void Afficher_Fixed_value_data();
double getdV_ebi_min();
double getdV_ebi_max();
double getV_ebi_min();
double getV_ebi_max();
double getdV_sbi_min();
double getdV_sbi_max();
double getV_sbi_min();
double getV_sbi_max();
double getdV_warning_min();
double getdV_warning_max();
double getV_warning_min();
double getV_warning_max();
double getT_dispTTI();
double getT_warning();
double getT_driver();
double getM_rotating_min();
double getM_rotating_max();
};


class Train_Data : public Tools
{
    private :

        //création des TC grâce au constructeur de la classe TC et ajout dans le vector
        std::vector<Train_Categories> tab_TC_list;//création des listes de Train categories
        Train_Categories train_categories;//La valeur stockée
        int train_length = 200;
        int maximum_train_speed;
        std::vector<Loading_gauge> tab_LG_list;//création des listes de Loading gauge
        Loading_gauge loading_gauge;//la valeur stockée
        std::vector <std::string> axle_load_categories{"A", "B", "C", "D", "E", "F", "G"};//création des listes de Axle_load_category
        std::string axle_load_category;//la valeur stockée
        size_t traction_system; //ATTENTION donnée inconnue //DONNEE NON MODIFIABLE
        bool train_fitted_with_airtight_system;
        std::vector<std::string> list_of_national_systems_available_on_board{"Level 1", "Level 2", "Level 3", "TVM", "KVB", "TPWS/AWS"};//DONNEE NON MODIFIABLE
        int axle_number;//DONNEE NON MODIFIABLE
        int M_rotating_nom = 11;
        int DriverID = 0;
        int TrainRunningNumber = 0;
        std::string level;

    public :
        Train_Data();
        int getTrain_length();
        int getM_rotating_nom();
        int getDriverID();
        void setDriverID(int D);
        void setTrainRunningNumber(int T);
        int getTrainRunningNumber();
		std::string getLevel();
        void setLevel(std::string L);
        std::vector<std::string> getlist_of_national_systems_available_on_board();

	    //GET ET SET A FAIRE SI NECESSAIRE
};


class OnBoardCorrectionFactors
{
    private :
    	double K_dry = 0.75f; //valeur provenant de la doc ERA COURBES
		double K_wet = 0.95f;
        bool dry = 1; // le rail est sec -> 1 sinon -> 0
    public:
        OnBoardCorrectionFactors();
        double getK_dry();
        void setK_dry(double K);
        double getK_wet();
        void setK_wet(double K);
        bool getDry();
        void setDry(bool D);

};


class TrainRelatedInputs
{
    public :

    Train_Data T_data;
    Fixed_Value_Data FVD;
    OnBoardCorrectionFactors OBCF;

};

#endif
