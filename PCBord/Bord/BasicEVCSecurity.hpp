#ifndef BEVCS
#define BEVCS

#include "../Train_dynamique.hpp"

class BasicEVCSecurity
{
	private:
		Train_dynamique *T_D;
		double V_SR = 30;
		double V_SB = 0;
	public:
		BasicEVCSecurity(Train_dynamique &T_D);
		//void respect_vitesse(std::string general_mode);
		//void respect_signalisation(); // A FAIRE AVEC LE SOL
};


#endif
