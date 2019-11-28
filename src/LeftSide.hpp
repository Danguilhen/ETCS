#ifndef LS
#define LS

#include "Cadran.hpp"

class LeftSide : public virtual Tools
{
	protected :
		Cadran speed{400};
		void targetDistance(int distance);
};

#endif