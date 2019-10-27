#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
//#include "Fenetres.hpp"

using namespace sf;
using namespace std;


//define ---------------------------------------------------------------------------------------------------------------------------------
#define V2f Vector2f

//Data -----------------------------------------------------------------------------------------------------------------------------------
/*class Data
{
	private :
		int Vtrain;
		string generalMode = "FS";
		string mode = "CSM";
		string status = "NoS";
		string level = "Level 1";
		double RE;
		Font arial;
		int son;
		//Son :
		//	Num�ro 1 : click
		//	Num�ro 2 : S-info
		//	Num�ro 3 : S1_toofast
		//	Num�ro 4 : S2_warning
		//	Mode 1 : Jouer UNE fois
		//	Mode 2 : Jouer en boucle
		//	Mode 3 : Stopper la boucle, le son s'arr�te


	public :
		Data();
		void update();
		int getVtrain();
		string getGeneralMode();
		string getMode();
		string getStatus();
		string getLevel();
		double getRE();
		void setSon(int a);
};

Data::Data()
{
	if(VideoMode::getDesktopMode().width / 640.0 < VideoMode::getDesktopMode().height / 480.0)
		RE = VideoMode::getDesktopMode().width / 640.0;	//rapport Ecran
	else
		RE = VideoMode::getDesktopMode().height / 480.0; //rapport Ecran
	arial.loadFromFile("ressources/fonts/arial.ttf"); //recuperation de la police
}

void Data::update()
{

}

int Data::getVtrain(){return Vtrain;}
string Data::getGeneralMode(){return generalMode;}
string Data::getMode(){return mode;}
string Data::getStatus(){return status;}
string Data::getLevel(){return level;}
double Data::getRE(){return RE;}
void Data::setSon(int a){son = a;}

//Button -----------------------------------------------------------------------------------------------------------------------------------
class Button
{
	private :
		Data *data;
		string type;
		int driver_action;//press� ou non
		int button_activation = 0;//nombre de fois activ�
		bool button_state;//enabled ou non
		Clock chrono;
		Time t_actif;
		int n; // variable utilis�e pour le down_type

	public :
		Button(Data &data);
		string gettype();
		void settype(string P);
		int getdriver_action();
		void setdriver_action(int P);
		void action_type();
		int getactivation();
};

Button::Button(Data &data)
{
	this->data = &data;
}

string Button::gettype() {return type;}
void Button::settype(string P) {type = P;}
int Button::getdriver_action(){return driver_action;}
void Button::setdriver_action(int P){driver_action = P;}
int Button::getactivation(){return button_activation;}

void Button::action_type()
{
	t_actif = chrono.getElapsedTime();
	float delta_ts=t_actif.asSeconds();
	button_activation = 0;
	if(type == "up_type")
	{
		if(driver_action == 1)
		{
			data->setSon(11);
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
			data->setSon(11);
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
			data->setSon(11);
			chrono.restart();
		}
		if(driver_action == 3 && delta_ts > 2)
		{
			button_activation = 1;
		}
	}
}

//ETCS -----------------------------------------------------------------------------------------------------------------------------------
class ETCS
{
	private :
		RenderWindow *fenetre;
		Data *data;
		vector <Button> button;
		Event event;
	public :
		ETCS(RenderWindow &fenetre, Data &data);
		void update();
		void action();
};

ETCS::ETCS(RenderWindow &fenetre, Data& data): button(16, data)
{
	this->fenetre = &fenetre;
	this->data = &data;
	for(int i = 0; i <= 15; i++)
		button[i].settype("up_type");
}

void ETCS::update()
{

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
}*/

//DMI ------------------------------------------------------------------------------------------------------------------------------------

class DMI
{
	private :
		RenderWindow fenetre;
		//ContextSettings settings;
		int signalisation;
		//Data data;
		//ETCS etcs{fenetre, data};
	public :
		DMI();
		void start();
};

DMI::DMI()
{
	//creation et affichage de la fenetre
	//fenetre.create(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height),"Ecran central", Style::Default, settings);
	//fenetre.setFramerateLimit(60);
	//settings.antialiasingLevel = 8;
}

void DMI::start()
{
	while(true)//fenetre.isOpen())
	{
		//data.update();
		switch(signalisation)
		{
			case 0: ;//etcs.update();
			case 1: ;
			case 2: ;
			default: ;
		}
	};
}

//Main -----------------------------------------------------------------------------------------------------------------------------------
int main()
{
	DMI app;
	app.start();
}