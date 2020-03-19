#include "define.hpp"
#include "BASIC.hpp"

class Auxiliaire : public BASIC
{

	private :

	Software *soft;
	Train_dynamique *T_D;
	
	public :

	update();
	traction();
	freinage();
	tension();
};
