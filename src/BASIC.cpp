#include "BASIC.hpp"

BASIC::BASIC(RenderWindow &fenetre, Data &data) : cadran(400, data, fenetre)
{
	this->fenetre = &fenetre;
	this->data = &data;
}

void BASIC::update()
{
	cadran.update();
}