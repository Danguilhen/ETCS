#ifndef DM
#define DM

#include "ETCS.hpp"
#include "BASIC.hpp"

class DMI
{
	private :
		ETCS_Bord *bord;
		RenderWindow fenetre;
		ContextSettings settings;
		int signalisation = 0;
		Data *data;
		ETCS etcs{fenetre, data};
		BASIC basic{fenetre, data};
	public :
		DMI(Data &data, ETCS_Bord &bord);
		void update();
};

#endif