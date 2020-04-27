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
	float marge = 100; // marge de 100 pixels
	float echelle; // donne le nombre de mètre pour un pixel
	float distance_max_affichable = 20000; // en mètres
	float largeur_rail = 5; // 50 pixels
	float temp_position_train = 0;
	float ecart_entre_rangee =100;

public:
	PCC(Software &soft, Train_dynamique &T_D);
	void update();
	void rail(float grandeur_longitudinale);
	void train();
};



#endif*/