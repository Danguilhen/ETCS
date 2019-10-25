
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <math.h>
#include <string>
#include <ctime>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include "Buttons.hpp"

string Buttons::gettype() {return type;}
void Buttons::settype(string P) {type = P;}
int Buttons::getdriver_action(){return driver_action;}
void Buttons::setdriver_action(int P){driver_action = P;}
int Buttons::getactivation(){return button_activation;}

void Buttons::action_type(Son & son)
{
	t_actif = chrono.getElapsedTime();
	float delta_ts=t_actif.asSeconds();
	button_activation = 0;
	if(type == "up_type")
	{
		if(driver_action == 1)
		{
			son.jouer_alarmes(1, 1);
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
			son.jouer_alarmes(1, 1);
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
			son.jouer_alarmes(1, 1);
			chrono.restart();
		}
		if(driver_action == 3 && delta_ts > 2)
		{
			button_activation = 1;
		}
	}
}