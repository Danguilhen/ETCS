#include "ETCS.hpp"

ETCS::ETCS(RenderWindow &fenetre, Data &data, ETCS_Bord &bord): def(fenetre, data, symbol, button, bord)/*, special(fenetre, data), settings(fenetre, data), srSpeed(fenetre, data), dataView(fenetre, data), systemVersion(fenetre, data)*/
{
	vector<string> nom{"DR_01", "DR_02", "DR_03", "DR_04", "DR_05", "LE_01", "LE_02", "LE_02a", "LE_03", "LE_04", "LE_05", "LE_06", "LE_07", "LE_08", "LE_08a", "LE_09", "LE_09a", "LE_10", "LE_11", "LE_12",
	"LE_13", "LE_14", "LE_15", "LS_01", "LX_01", "MO_01", "MO_02", "MO_03", "MO_04", "MO_05", "MO_06", "MO_07", "MO_08", "MO_09", "MO_10", "MO_11", "MO_12", "MO_13", "MO_14", "MO_15", "MO_16", "MO_17",
	"MO_18", "MO_19", "MO_20", "MO_21", "MO_22", "NA_01", "NA_02", "NA_03", "NA_04", "NA_05", "NA_06", "NA_07", "NA_08", "NA_09", "NA_10", "NA_11", "NA_12", "NA_13", "NA_14", "NA_15", "NA_16", "NA_17",
	"NA_18", "NA_18_2", "NA_19", "NA_20", "NA_21", "NA_22", "NA_23", "PL_01", "PL_02", "PL_03", "PL_04", "PL_05", "PL_06", "PL_07", "PL_08", "PL_09", "PL_10", "PL_11", "PL_12", "PL_13", "PL_14", "PL_15",
	"PL_16", "PL_17", "PL_18", "PL_19", "PL_20", "PL_21", "PL_22", "PL_23", "PL_24", "PL_25", "PL_26", "PL_27", "PL_28", "PL_29", "PL_30", "PL_31", "PL_32", "PL_33", "PL_34", "PL_35", "PL_36", "SE_01",
	"SE_02", "SE_03", "SE_04", "ST_01", "ST_02", "ST_03", "ST_04", "ST_05", "ST_06", "TC_01", "TC_02", "TC_03", "TC_04", "TC_05", "TC_06", "TC_07", "TC_08", "TC_09", "TC_10", "TC_11", "TC_12", "TC_13",
	"TC_14", "TC_15", "TC_16", "TC_17", "TC_18", "TC_19", "TC_20", "TC_21", "TC_22", "TC_23", "TC_24", "TC_25", "TC_26", "TC_27", "TC_28", "TC_29", "TC_30", "TC_31", "TC_32", "TC_33", "TC_34", "TC_35",
	"TC_36", "TC_37"};
	for(int i = 0; i < int(nom.size()); i++)
	{
		symbol.push_back(Symbol(fenetre, data));
		symbol[i].loadSymbol("ressources/symbols/" + nom[i] + ".bmp");
	}
	this->fenetre = &fenetre;
	this->data = &data;
	this->bord = &bord;
	for(int i = 0; i <= 15; i++)
	{
		button.push_back(data);
		button[i].settype("up_type");
	}
}

void ETCS::update()
{
	action();

	fond[0].position = V2f(data->getEcartX() * data->getRE(), data->getEcartY() * data->getRE());
	fond[1].position = V2f((640 + data->getEcartX()) * data->getRE(), data->getEcartY() * data->getRE());
	fond[2].position = V2f((640 + data->getEcartX()) * data->getRE(), (480 + data->getEcartY()) * data->getRE());
	fond[3].position = V2f(data->getEcartX() * data->getRE(), (480 + data->getEcartY()) * data->getRE());
	couleurForme(fond, DARK_BLUE, 4);
	fenetre->draw(fond);
	affichageBoutons();
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
            int x = event.mouseButton.x;
            int y = event.mouseButton.y;
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
            	if((x > (640 - 40 + data->getEcartX()) * data->getRE()) && (x < (640 + data->getEcartX()) * data->getRE()) && y > ((28 + 64 * (i - 10) + data->getEcartY()) * data->getRE()) && y < ((28 + 64 * (i - 9) + data->getEcartY()) * data->getRE()))
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