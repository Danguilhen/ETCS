#ifndef TD
#define TD

#include "define.hpp"
#include "Reseau.hpp"
#include "Train_statique.hpp"

class Train_dynamique
{
	private :
	float V_train = 0.0;
	sf::Clock chrono;//créer le chrono
	sf::Time diftime;//créer la varaible qui stocke le temps écoulé
	float deltats;//créer la variable qui stocke le temps écoulé en seconde
	float distance_update; // distance parcourue entre chaque mise à jour
	int traction=510;
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
	float coefManip=0; // coef multiplicateur de la puissance envoyé par le conducteur avec le manip
	float Rav;			// resistance avancement
	float Rp;  // resistance profil
	float Rd=0;
	float Fres;
	float F;
	float Ft;
	float Rd0=0;
//	float Rp0;      // rp corrigé
	float Q=0;
	float gammaEssieu;
	float mumax = 0.35; // donnée à récupérer
	float masseEssieuMoteur = 1.5;   // en tonnes
	float Vessieu = 0;      // voir si je la declare dans la fonction calculvitesse
	float newGlissement=0;
	float glissement=0;
	float mTournanteEssieuMoteur = 0.9;
	float nbEssieuMoteur = 8;
	float masseEssieu = 17;
	float FtractionAdher=0;
	float Vessieuprece;
	float Vtrainprece;
	float Freac=0;     // force de réaction du rail
	float Ftransmis=0;
	float Fessieu=0;
	float mudyn=0;

	bool freinage_urgence = false;

	int F1 = 287;
	int F2 = 90;
	//std::string F_mode; // quel mode de freinage utilisé
	//std::string V_mode; // quel type de freinage utilisé en fonction de la vitesse

	Reseau *res;
	Train_statique *stat;

	public :

	Train_dynamique(Reseau &res, Train_statique &stat);
	void update();
	void partage_reseau();
	float getV_train();
	void setV_train(float V);
	float getDistance_Uptdate();
	float getTraction();
	void setTraction(float A);
	float getPK();
	void calculVitesse();
	void calculDistance();
	void determinationValeurManip();
	void effortTraction();
	void effortResultant();
	void effortFreinage();
	void effortFreinageTemp();
	void adherence();
	float freinagePneumatiqueRemorque();
	float freinagePneumatiqueMotrice();
	void freinageUrgence();
};

#endif