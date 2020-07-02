#ifndef sw
#define sw

#include "define.hpp"

class Software
{
	private :
		sf::RenderWindow fenetre;
		sf::ContextSettings settings;
		sf::Event event;
		sf::RenderWindow fenPcc;
		sf::ContextSettings settingsPcc;
		sf::Event evevntPcc;
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
		//sf::RenderWindow *getFenPcc();
		int getVmax();
		void setVmax(int V);
		bool getS_Finished();
		void setS_Finished(bool S);

};

#endif