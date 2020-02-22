#ifndef ES
#define ES

#include "Software.hpp"
#include "Bord/ETCS_Bord.hpp"
#include "DMI/ETCS_DMI.hpp"

class ETCS
{
	private :
		ETCS_Bord Bord;
		ETCS_DMI EDMI;
		Software *soft;

	public :

		ETCS(Software &soft, Train_dynamique &T_D);
		void ETCS_uptade();
};


#endif