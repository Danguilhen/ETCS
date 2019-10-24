#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
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
#include "donnees.hpp"

using namespace sf;
using namespace std;


donnees::donnees(float vitesse_EOA, float vitesse_train, float distance_but, float vitesse_ligne, float acceleration) //CONSTRUCTEUR
{
	V_ligne = vitesse_ligne;//Vitesse ligne avant d�c�l�ration
	V_but = vitesse_EOA;//vitesse BUT � la EOA
	Vf_ISL = 0;//Indication speed
	Vf_PSL = 0;//Permited speed
	Vf_FLOISL = 0;//Intervention speed
	V_train = vitesse_train;
	V_init = vitesse_train;//Vitesse mise � jour du train
	d_parcourue = 0; // distance parcourue en entrant dans la TSM
	d_train_EOA = distance_but;//distance avant but d�croit vers 0
	a_train = acceleration ;//acc�l�ration du train
}
donnees::donnees(){}

int donnees::getVtrain(){return Vtrain;}
string donnees::getGeneralMode(){return generalMode;};
string donnees::getMode(){return mode;};
string donnees::getStatus(){return status;};
string donnees::getLevel(){return level;};