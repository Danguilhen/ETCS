#include "ETCS.hpp"

ETCS::ETCS(RenderWindow &fenetre, Data &data): button(16, data)
{
	symbol.init(fenetre, data);
	this->fenetre = &fenetre;
	this->data = &data;
	for(int i = 0; i <= 15; i++)
		button[i].settype("up_type");
}

void ETCS::update()
{
	action();
	def.update();
}

void ETCS::action()
{
	for(int i = 0; i <= 15; i++)
	{
		if(button[i].getdriver_action() == 3)
			button[i].setdriver_action(0);
		if(button[i].getdriver_action() == 1)
			button[i].setdriver_action(2);
	}
    while(fenetre->pollEvent(event))
    {
		if (event.type==sf::Event::MouseButtonReleased)
		{
            int x=event.mouseButton.x;
            int y=event.mouseButton.y;
			for(int i = 0; i < 10; i++)
			{
				if(x > ((64 * i + data->getEcartX()) * data->getRE()) && x < ((64 * (i + 1) + data->getEcartX()) * data->getRE()) && y > ((430 + data->getEcartY()) * data->getRE()) && y < ((480 + data->getEcartY()) * data->getRE()))
            	{
					if(button[i].getdriver_action() == 0)
						button[i].setdriver_action(1);
					else
						button[i].setdriver_action(2);
				}
			}
			for(int i = 10; i < 15; i++)
			{
            	if(x > ((54 + 280 + 246 + 20 + data->getEcartX()) * data->getRE()) && x < ((54 + 280 + 246 + 20 + 40 + data->getEcartX()) * data->getRE()) && y > ((28 + 64 * (i - 10) + data->getEcartY()) * data->getRE()) && y < ((28 + 64 * (i - 9) + data->getEcartY()) * data->getRE()))
            	{
					if(button[i].getdriver_action() == 0)
						button[i].setdriver_action(1);
					else
						button[i].setdriver_action(2);
				}
			}
			if(x > ((54 + 280 + 246 + 20 + data->getEcartX()) * data->getRE()) && x < ((54 + 280 + 246 + 20 + 40 + data->getEcartX()) * data->getRE()) && y > ((28 + 64 * 5 + data->getEcartY()) * data->getRE()) && y < ((28 + 64 * 5 + 82 + data->getEcartY()) * data->getRE()))
            {
				if(button[15].getdriver_action() == 0)
					button[15].setdriver_action(1);
				else
					button[15].setdriver_action(2);
			}
        }
	    if(event.type == Event::Closed)
            fenetre->close();
		if(event.type == Event::KeyPressed)
		{
		    if(event.key.code == Keyboard::Escape)
		        fenetre->close();
			else if(event.key.code == Keyboard::A)
			{
		        if(button[0].getdriver_action() == 0)
					button[0].setdriver_action(1);
				else
					button[0].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::Z)
			{
				if(button[1].getdriver_action() == 0)
					button[1].setdriver_action(1);
				else
					button[1].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::E)
			{
		        if(button[2].getdriver_action() == 0)
					button[2].setdriver_action(1);
				else
					button[2].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::R)
			{
		        if(button[3].getdriver_action() == 0)
					button[3].setdriver_action(1);
				else
					button[3].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::T)
			{
		        if(button[4].getdriver_action() == 0)
					button[4].setdriver_action(1);
				else
					button[4].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::Y)
			{
		        if(button[5].getdriver_action() == 0)
					button[5].setdriver_action(1);
				else
					button[5].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::U)
			{
		        if(button[6].getdriver_action() == 0)
					button[6].setdriver_action(1);
				else
					button[6].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::I)
			{
		        if(button[7].getdriver_action() == 0)
					button[7].setdriver_action(1);
				else
					button[7].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::O)
			{
		        if(button[8].getdriver_action() == 0)
					button[8].setdriver_action(1);
				else
					button[8].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::P)
			{
		        if(button[9].getdriver_action() == 0)
					button[9].setdriver_action(1);
				else
					button[9].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::Q)
			{
		        if(button[10].getdriver_action() == 0)
					button[10].setdriver_action(1);
				else
					button[10].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::S)
			{
		        if(button[11].getdriver_action() == 0)
					button[11].setdriver_action(1);
				else
					button[11].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::D)
			{
		        if(button[12].getdriver_action() == 0)
					button[12].setdriver_action(1);
				else
					button[12].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::F)
			{
		        if(button[13].getdriver_action() == 0)
					button[13].setdriver_action(1);
				else
					button[13].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::G)
			{
		        if(button[14].getdriver_action() == 0)
					button[14].setdriver_action(1);
				else
					button[14].setdriver_action(2);
			}
			else if(event.key.code == Keyboard::H)
			{
		        if(button[15].getdriver_action() == 0)
					button[15].setdriver_action(1);
				else
					button[15].setdriver_action(2);
			}
		}
		if(event.type == Event::KeyReleased)
		{
			if(event.key.code == Keyboard::A)
		        button[0].setdriver_action(3);
			else if(event.key.code == Keyboard::Z)
		        button[1].setdriver_action(3);
			else if(event.key.code == Keyboard::E)
		        button[2].setdriver_action(3);
			else if(event.key.code == Keyboard::R)
		        button[3].setdriver_action(3);
			else if(event.key.code == Keyboard::T)
		        button[4].setdriver_action(3);
			else if(event.key.code == Keyboard::Y)
		        button[5].setdriver_action(3);
			else if(event.key.code == Keyboard::U)
		        button[6].setdriver_action(3);
			else if(event.key.code == Keyboard::I)
		        button[7].setdriver_action(3);
			else if(event.key.code == Keyboard::O)
		        button[8].setdriver_action(3);
			else if(event.key.code == Keyboard::P)
		        button[9].setdriver_action(3);
			else if(event.key.code == Keyboard::Q)
		        button[10].setdriver_action(3);
			else if(event.key.code == Keyboard::S)
		        button[11].setdriver_action(3);
			else if(event.key.code == Keyboard::D)
		        button[12].setdriver_action(3);
			else if(event.key.code == Keyboard::F)
		        button[13].setdriver_action(3);
			else if(event.key.code == Keyboard::G)
		        button[14].setdriver_action(3);
			else if(event.key.code == Keyboard::H)
		        button[15].setdriver_action(3);
		}
    }
	for(int i = 0; i <= 15; i++)
		button[i].action_type();
}
