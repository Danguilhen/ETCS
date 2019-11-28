#ifndef Basic
#define Basic

#include "Data.hpp"

using namespace sf;

class BASIC
{
	private :
		RenderWindow *fenetre;
		Data *data;
	public :
		BASIC(RenderWindow &fenetre, Data &data);
		void update();
};

#endif