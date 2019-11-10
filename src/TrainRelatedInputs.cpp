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
#include "TrainRelatedInputs.hpp"

using namespace std;

class TrainRelatedInputs
{
private:
    class Train_Data
    {
        private :

        class Train_Categories
        {
            private :
            string label;
            int cant_deficiency_train_category_value;
            int other_international_train_category_value;

            public:
            Train_Categories(string L, int C, int O)
            {
                label = L;
                cant_deficiency_train_category_value = C;
                other_international_train_category_value = O;
            }

        };
        vector<Train_Categories> tab_TC_list;//création des listes de Train categories
        //création des TC grâce au constructeur de la classe TC et ajout dans le vector
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
        Train_Categories train_categories;//La valeur stockée

        int train_length;

        int maximum_train_speed;

        class Loading_gauge
        {
            private :
            string Loading_gauge_label;
            //int Loading_gauge_value;

            public :
            Loading_gauge(string LGL)
            {
                Loading_gauge_label = LGL;
                //Loading_gauge_value = LGV; n'a pas d'importance dans la suite
            }
        };
        vector<Loading_gauge> tab_LG_list;//création des listes de Loading gauge
        //création des LG grâce au constructeur de la classe LG et ajout dans le vector
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
        Loading_gauge loading_gauge;//la valeur stockée

        vector <string> axle_load_categories;//création des listes de Axle_load_category
        //Création et insertions grâce aux Push_Back
        axle_load_categories.push_back("A");
        axle_load_categories.push_back("B");
        axle_load_categories.push_back("C");
        axle_load_categories.push_back("D");
        axle_load_categories.push_back("E");
        axle_load_categories.push_back("F");
        axle_load_categories.push_back("G");
        string axle_load_category;//la valeur stockée

        size_t traction_system; //ATTENTION donnée inconnue //DONNEE NON MODIFIABLE

        bool train_fitted_with_airtight_system;

        vector<string> list_of_national_systems_available_on_board;//DONNEE NON MODIFIABLE
        list_of_national_systems_available_on_board.push_back("TVM");
        list_of_national_systems_available_on_board.push_back("FR");
        list_of_national_systems_available_on_board.push_back("EN");

        int axle_number;//DONNEE NON MODIFIABLE

        A_brake A_brake_emergency();
        A_brake A_brake_service();
        A_brake A_brake_normal_service();
        float Brake_percentage;

	public :

	//GET ET SET A FAIRE SI NECESSAIRE
    };

    


public:
    TrainRelatedInputs()
    {

    }
};



