#ifndef TD
#define TD

#include "define.hpp"

class Train_dynamique
{
	private :
	float V_train = 80;
	sf::Clock chrono;//créer le chrono
	sf::Time diftime;//créer la varaible qui stocke le temps écoulé
	float deltats;//créer la variable qui stocke le temps écoulé en seconde
	float distance_update; // distance parcourue entre chaque mise à jour
	float acceleration;
	int traction;

	int masse; // masse à récupérer dans la class réseau
	float A;
	float B;
	float C;    // les valeurs A B C seront à récupéré dans la class réseau 




	public :

	void update();
	float getV_train();
	void setV_train(float V);
	void mouvementTrain();
	float getDistance_Uptdate();
	float getTraction();
	void setTraction(float A);

	void effortTraction();
	void effortFreinage();
};

#endif