#ifndef ES
#define ES

#include "Software.hpp"
#include "Bord/ETCS_Bord.hpp"
#include "DMI/ETCS_DMI.hpp"

class ETCS
{
	private :
		ETCS_Bord bord;
		ETCS_DMI EDMI;

	public :

		ETCS(Software &soft, Train_dynamique &T_D);
		void ETCS_uptade();
};


#endif