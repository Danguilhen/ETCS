/*#ifndef Balhpp
#define Balhpp

#include "define.hpp"

class Information_balise
{
private:
	double type_information; // 1 = vitesse ; 2 = infra
	double PK_information;
	double valeur_information;
public:
	Information_balise(double type, double PK, double valeur);
	double getType_information();
	void setType_information(double P);
	double getPK();
	void setPK(double P);
	double getValeur();
	void setValeur(double P);
};

class Balise
{
private:
	double numero_identifiant;
	double PK_balise;
	int voie; // pair vers Paris
	std::vector<Information_balise> v_information;

public:
	Balise(double numero, double PK, int num_voie, std::vector<Information_balise> v_info);
	double getNumero_identifiant();
	void setNumero_identifiant(double P);
	double getPK();
	void setPK(double P);
	double getVoie();
	void setVoie(double P);
	std::vector<Information_balise> getV_information();
	void setV_information(std::vector<Information_balise> P);
};




#endif
*/