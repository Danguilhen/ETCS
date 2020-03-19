#ifndef sw
#define sw

#include "define.hpp"

class Software
{
	private :
		std::string type_signalisation = "ETCS"; //ETCS OU A_VIDE
		sf::RenderWindow fenetre;
		sf::ContextSettings settings;
		sf::Event event;
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
		bool s_Finished = false; //Utiliser pour faire fonctionner le multithreading affichage calcul
		int Vligne = 150;

	public :
		Software();
		void software_update();
		double getRE();
		int getEcartX();
		int getEcartY();
		void setSon(int a);
		bool getEtat();
		void setEtat(bool stop);
		sf::RenderWindow *getFenetre();
		int getVmax();
		void setVmax(int V);
		std::string getType_signalisation();
		void setType_signalisation(std::string T);
		int getVligne();
		void setVligne(int V);
		bool getS_Finished();
		void setS_Finished(bool S);

};

#endif