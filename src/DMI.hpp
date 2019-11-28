#ifndef DM
#define DM

#include "ETCS.hpp"
#include "ETCS_Bord.hpp"
#include "BASIC.hpp"
#include "Data.hpp"

class DMI
{
	private :
		ETCS_Bord *bord;
		RenderWindow fenetre;
		ContextSettings settings;
		int signalisation = 0;
		Data *data;
		ETCS etcs;
		BASIC basic;
	public :
		DMI(Data &data, ETCS_Bord &bord);
		void update();
};

#endif