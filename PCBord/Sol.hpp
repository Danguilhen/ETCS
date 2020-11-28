/*#ifndef SSSOL
#define SSSOL

#include "define.hpp"
#include "Virtual_train.hpp"
#include "Balise.hpp"
#include "json.hpp"

class Sol
{
private:

	Virtual_train *v_train;
	double derniere_position_connu;
	json liste_canton;
	sf::Event event; // pour permettre la MAJ des JSON en appuyant sur le clavier ENTER

public:
	Sol(Virtual_train &v_train);
	void update();
	void gestion_CDV();
	void RBC();
	void lecture_JSON();
	//void determination_MA();
};


#endif*/