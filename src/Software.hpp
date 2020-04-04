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
		int Vmax = 400;//vmax affichée sur le compteur (ici 400)
		bool en_marche = true;
		bool s_Finished = false; //Utiliser pour faire fonctionner le multithreading affichage calcul

	public :
		Software();
		void software_update();
		double getRE();
		int getEcartX();
		int getEcartY();
		bool getEtat();
		void setEtat(bool stop);
		sf::RenderWindow *getFenetre();
		int getVmax();
		void setVmax(int V);
		std::string getType_signalisation();
		void setType_signalisation(std::string T);
		bool getS_Finished();
		void setS_Finished(bool S);

};

#endif