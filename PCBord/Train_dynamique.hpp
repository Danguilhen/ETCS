#ifndef TD
#define TD

#include "define.hpp"
#include "Reseau.hpp"
#include "Train_statique.hpp"

class Train_dynamique
{
	private :
	double V_train = 0.0;
	sf::Clock chrono;//créer le chrono
	sf::Time diftime;//créer la varaible qui stocke le temps écoulé
	double deltats;//créer la variable qui stocke le temps écoulé en seconde
	double distance_update; // distance parcourue entre chaque mise à jour
	int traction=510;
	int masse=425; // masse à récupérer dans la class réseau
	double A=2.7;
	double B=0.032;
	double C=0.00053;    // les valeurs A B C seront à récupéré dans la class réseau
	double Ptraction=9280;   // en kW
	double Ftraction=222; // en kN
	double Pfreinage=5;     // idem
	int valeurManip;
	double i=0;          // en pour mille
	double typeTrain=0;   // pour la formule résistance au décollage =0 -> voyageur        =1 -> fret
	double k=1.03;
	double gamma;
	double coefManip=0; // coef multiplicateur de la puissance envoyé par le conducteur avec le manip
	double Rav;			// resistance avancement
	double Rp;  // resistance profil
	double Rd=0;
	double Fres;
	double F;
	double Ft;
	double Rd0=0;
//	double Rp0;      // rp corrigé
	double Q=0;
	double gammaEssieu;
	double mumax = 0.35; // donnée à récupérer
	double masseEssieuMoteur = 1.5;   // en tonnes
	double Vessieu = 0;      // voir si je la declare dans la fonction calculvitesse
	double newGlissement=0;
	double glissement=0;
	double mTournanteEssieuMoteur = 0.9;
	double nbEssieuMoteur = 8;
	double masseEssieu = 17;
	double FtractionAdher=0;
	double Vessieuprece;
	double Vtrainprece;
	double Freac=0;     // force de réaction du rail
	double Ftransmis=0;
	double Fessieu=0;
	double mudyn=0;

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
	double getV_train();
	void setV_train(double V);
	double getDistance_Uptdate();
	int getTraction();
	void setTraction(int A);
	double getPK();
	void calculVitesse();
	void calculDistance();
	void determinationValeurManip();
	void effortTraction();
	void effortResultant();
	void effortFreinage();
	void effortFreinageTemp();
	void adherence();
	double freinagePneumatiqueRemorque();
	double freinagePneumatiqueMotrice();
	void freinageUrgence();
};

#endif