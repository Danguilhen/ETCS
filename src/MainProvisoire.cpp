#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Fenetres.hpp"

using namespace sf;
using namespace std;


//define ---------------------------------------------------------------------------------------------------------------------------------
#define V2f Vector2f

//DMI ------------------------------------------------------------------------------------------------------------------------------------

class DMI
{
	private :
		RenderWindow fenetre;
		ContextSettings settings;
		int signalisation;
		Data data;
		ETCS ETCS;
	public :
		DMI();
		void update();
};

DMI::DMI()
{
	//creation et affichage de la fenetre
	fenetre.create(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height),"Ecran central", Style::Default, settings);
	fenetre.setFramerateLimit(60);
	settings.antialiasingLevel = 8;
}

void DMI::update()
{
	data.update();
	switch(signalisation)
	{
		case 0: ETCS.update();
		case 1: ;
		case 2: ;
	}
}

//Main -----------------------------------------------------------------------------------------------------------------------------------
int main()
{
	DMI app;
	while(true)
	{
		app.update();
	};
}

//Data -----------------------------------------------------------------------------------------------------------------------------------
class Data
{
	private :
		int Vtrain;
		string generalMode = "FS";
		string mode = "CSM";
		string status = "NoS";
		string level = "Level 1";
		double RE;
		Font arial;

	public :
		Data();
		int getVtrain();
		string getGeneralMode();
		string getMode();
		string getStatus();
		string getLevel();
		double getRE();
};

Data::Data()
{
	if(VideoMode::getDesktopMode().width / 640.0 < VideoMode::getDesktopMode().height / 480.0)
		RE = VideoMode::getDesktopMode().width / 640.0;	//rapport Ecran
	else
		RE = VideoMode::getDesktopMode().height / 480.0; //rapport Ecran
	arial.loadFromFile("ressources/fonts/arial.ttf"); //recuperation de la police
}

int Data::getVtrain(){return Vtrain;}
string Data::getGeneralMode(){return generalMode;};
string Data::getMode(){return mode;};
string Data::getStatus(){return status;};
string Data::getLevel(){return level;};
double Data::getRE(){return RE;};

//ETCS -----------------------------------------------------------------------------------------------------------------------------------
class ETCS
{

};