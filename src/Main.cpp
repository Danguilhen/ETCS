#include <string>
#include <cstdlib>
#include <vector>
#include <unistd.h>
#include <iostream>

using namespace std;

class A_brake

{
    public :

	vector < vector < float > > tab_A_brake;//tableau avec 2 colonnes la vitesse max où la décélération est admise, premiere colonne vitesse et deuxieme deceleration
	float A_brake;
	float Brake_percentage;
    A_brake(int nombre_deceleration)
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
    }
	float A_Brake(int V);

};

float A_brake::Attribution_deceleration(int V)
{
    size_t i = 0;
    while(V > int(tab_A_brake[i][0]) && i < tab_A_brake.size() - 1)
    {
        i++;
    }
    return int(tab_A_brake[i][1]);
}
