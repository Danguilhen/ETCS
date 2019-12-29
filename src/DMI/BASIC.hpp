#ifndef Basic
#define Basic

#include "Data.hpp"
#include "Cadran.hpp"
#include "define.hpp"

class BASIC
{
	private :
		RenderWindow *fenetre;
		Data *data;
		Cadran cadran;
		Event event;
	public :
		BASIC(RenderWindow &fenetre, Data &data, ETCS_Bord &bord);
		void update();
		void action();
};

#endif