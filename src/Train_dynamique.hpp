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
	int traction;

	int masse=425; // masse à récupérer dans la class réseau
	float A=2.7;
	float B=0.032;
	float C=0.00053;    // les valeurs A B C seront à récupéré dans la class réseau
	float Ptraction=9280;   // en kW
	float Ftraction=222; // en kN
	float Pfreinage=5;     // idem
	int valeurManip;
	float i=0;          // en pour mille
	float typeTrain=0;   // pour la formule résistance au décollage =0 -> voyageur        =1 -> fret
	float k=1.03;
	float gamma;

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
	void calculVitesse();

};

#endif