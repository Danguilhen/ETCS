#include "BASIC.hpp"

BASIC::BASIC(RenderWindow &fenetre, Data &data, ETCS_Bord &bord) : cadran(400, data, fenetre, bord)
{
	this->fenetre = &fenetre;
	this->data = &data;
}

void BASIC::update()
{
	action();
	cadran.update();
}

void BASIC::action()
{
    while(fenetre->pollEvent(event))
    {
	    if(event.type == Event::Closed)
        {
			fenetre->close();
			data->setEteindre(true);
		}
		if(event.type == Event::KeyPressed)
		{
		    if(event.key.code == Keyboard::Escape)
			{
				fenetre->close();
				data->setEteindre(true);
			}
		}
    }
}