#include "BASIC.hpp"

BASIC::BASIC(RenderWindow &fenetre, Data &data) : cadran(400, data, fenetre)
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
			if(event.key.code == Keyboard::Up)
				data->setVtrain(data->getVtrain() + 1);
			if(event.key.code == Keyboard::Down)
				data->setVtrain(data->getVtrain() - 1);
		}
    }
}