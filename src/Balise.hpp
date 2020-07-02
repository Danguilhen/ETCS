/*#ifndef Balhpp
#define Balhpp

#include "define.hpp"

class Information_balise
{
private:
	float type_information; // 1 = vitesse ; 2 = infra
	float PK_information;
	float valeur_information;
public:
	Information_balise(float type, float PK, float valeur);
	float getType_information();
	void setType_information(float P);
	float getPK();
	void setPK(float P);
	float getValeur();
	void setValeur(float P);
};

class Balise
{
private:
	float numero_identifiant;
	float PK_balise;
	int voie; // pair vers Paris
	std::vector<Information_balise> v_information;

public:
	Balise(float numero, float PK, int num_voie, std::vector<Information_balise> v_info);
	float getNumero_identifiant();
	void setNumero_identifiant(float P);
	float getPK();
	void setPK(float P);
	float getVoie();
	void setVoie(float P);
	std::vector<Information_balise> getV_information();
	void setV_information(std::vector<Information_balise> P);
};




#endif
*/