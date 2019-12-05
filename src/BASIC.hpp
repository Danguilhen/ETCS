#ifndef Basic
#define Basic

#include "Data.hpp"
#include "Cadran.hpp"

using namespace sf;

class BASIC
{
	private :
		RenderWindow *fenetre;
		Data *data;
		Cadran cadran;
	public :
		BASIC(RenderWindow &fenetre, Data &data);
		void update();
};

#endif