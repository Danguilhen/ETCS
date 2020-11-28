#include "Button.hpp"

Button::Button(Software &soft)
{
	this->soft = &soft;
}

string Button::gettype() {return type;}
void Button::settype(string P) {type = P;}
int Button::getdriver_action(){return driver_action;}
void Button::setdriver_action(int P){driver_action = P;}
int Button::getactivation(){return button_activation;}

void Button::action_type()
{
	t_actif = chrono.getElapsedTime();
	double delta_ts=t_actif.asSeconds();
	button_activation = 0;
	if(type == "up_type")
	{
		if(driver_action == 1)
		{
			//soft->setSon(11);
		}
		if(driver_action == 3)
		{
			button_activation = 1;
		}
	}
	if(type == "down_type")
	{
		if(driver_action == 1)
		{
			//soft->setSon(11);
			chrono.restart();
			button_activation = 1;
			n = 0;
		}
		else if(driver_action == 2)
		{
			if(delta_ts <= 1.5 && n == 0)
			{
				button_activation = 0;
			}
			if (delta_ts > 1.5)
			{
				n = 1;
				chrono.restart();
			}
			if(n == 1)
			{
				if(round(delta_ts*10) == 0.3*10)
				{
					button_activation = 1;
					chrono.restart();
				}
				else
					button_activation = 0;
			}
		}
	}
	if (type == "delay_type")
	{
		if(driver_action == 1)
		{
			//soft->setSon(11);
			chrono.restart();
		}
		if(driver_action == 3 && delta_ts > 2)
		{
			button_activation = 1;
		}
	}
}
