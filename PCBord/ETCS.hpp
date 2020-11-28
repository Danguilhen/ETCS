#ifndef ES
#define ES

#include "Software.hpp"
#include "Bord/ETCS_Bord.hpp"
#include "Bord/TVM_Bord.hpp"
#include "DMI/ETCS_DMI.hpp"


class ETCS
{
	private :
		Software *soft;
		Reseau *Res;
		TVM_Bord *TVM;

	public :

		ETCS_Bord Bord;
		ETCS_DMI EDMI;
		ETCS(Software &soft, Train_dynamique &T_D, Reseau &Res, TVM_Bord &TVM);
		void ETCS_uptade();
};


#endif