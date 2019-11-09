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

    public:
    
    A_brake(vector<vector<float>> vect)
    {
        step_tab = vect;
    }

	float Attribution(int V_train);

};

float A_brake::Attribution(int V_train)
{
    size_t i = 0;
    while(V_train > int(tab_A_brake[i][0]) && i < tab_A_brake.size() - 1)
    {
        i++;
    }
    return int(tab_A_brake[i][1]);
}


int main()
{

    vector <vector <int>> test{{1, 2, 3},
    {1, 2},
    {1, 2, 3}};

    for(size_t i=0; i< test.size(); i++)
    {
        for(size_t j=0; j< test[i].size(); j++)
        {
            cout << test[i][j];
        }
        cout << endl;
    }
    return 0;
}