#include <string>
#include <cstdlib>
#include <vector>
#include <unistd.h>
#include <iostream>

using namespace std;

class Step_fonction
{
    private :

	vector < vector < float > > step_tab;


    public:

    Step_fonction(vector<vector<float>> vect)
    {
        step_tab = vect;
    }
	float Attribution_fonction_vitesse(int V_train);

    //////////////////////////////////
    /*A_brake(int nombre_deceleration)
    {
        for (int i = 0; i < nombre_deceleration; i++)
        {
            vector < float > ligne;
            int v;
            int d;
            cout << "vitesse max" << endl;
            cin >> v;
            cout << "deceleration" << endl;
            cin >> d;
            ligne.push_back(v);
            ligne.push_back(d);
            tab_A_brake.push_back(ligne);
        }
    }*/ //utile si besoin de créer en direct une step_function

};

class Braking_model : public Step_fonction
{
    Braking_model(vector<vector<float>> vect)
    {
        Step_fonction(vector<vector<float>> vect);
    }


};

class Correcteur : public Step_fonction
{

};

class Gradient : public Step_fonction
{

};

class MSRP : public Step_fonction
{

};



int main()
{

    Braking_model(vector <vector <int>> test{{1, 2, 3},{1, 2},{1, 2, 3}});

    for(size_t i=0; i< test.size(); i++)
    {
        for(size_t j=0; j< test[i].size(); j++)
        {
            
        }

    }
    return 0;
}