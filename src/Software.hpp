#ifndef sw
#define sw

#include "define.hpp"

class Software
{
	private :
		string type_signalisation = "ETCS"; //ETCS OU A VIDE
		RenderWindow fenetre;
		ContextSettings settings;
		Event event;
		double RE ;
		int ecartX = 0;
		int ecartY = 0;
		int son;
		//Son :
		//	Num�ro 1 : click
		//	Num�ro 2 : S-info
		//	Num�ro 3 : S1_toofast
		//	Num�ro 4 : S2_warning
		//	Mode 1 : Jouer UNE fois
		//	Mode 2 : Jouer en boucle
		//	Mode 3 : Stopper la boucle, le son s'arr�te
		int Vmax = 400;//vmax affichée sur le compteur (ici 400)
		bool en_marche = true;

		int Vligne = 50; // reçoit informations de la ligne


	public :
		Software();
		void software_update();
		double getRE();
		int getEcartX();
		int getEcartY();
		void setSon(int a);
		bool getEtat();
		void setEtat(bool stop);
		RenderWindow *getFenetre();
		int getVmax();
		void setVmax(int V);
		string getType_signalisation();
		void setType_signalisation(string T);
		int getVligne();
		void setVligne(int V);

};

#endif