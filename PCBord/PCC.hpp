/*#ifndef IPC
#define IPC

#include "define.hpp"
#include "Software.hpp"
#include "Train_dynamique.hpp"

class PCC
{
private:

	Software *soft;
	Train_dynamique *temp_T_D;
	double marge = 100; // marge de 100 pixels
	double echelle; // donne le nombre de mètre pour un pixel
	double distance_max_affichable = 20000; // en mètres
	double largeur_rail = 5; // 50 pixels
	double temp_position_train = 0;
	double ecart_entre_rangee =100;
	json liste_canton;

public:
	PCC(Software &softw, Train_dynamique &T_D);
	void update();
	void rail(double grandeur_longitudinale);
	void train();
	void canton();
};



#endif*/