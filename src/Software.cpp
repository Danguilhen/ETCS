#include "Software.hpp"

Software::Software()
{
	if(VideoMode::getDesktopMode().width / 640.0 < VideoMode::getDesktopMode().height / 480.0)
	RE = VideoMode::getDesktopMode().width / 640.0;	//rapport Ecran
	else
		RE = VideoMode::getDesktopMode().height / 480.0; //rapport Ecran
	//creation et affichage de la fenetre
	fenetre.create(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height),"Ecran central", Style::Fullscreen, settings);
	fenetre.setFramerateLimit(60);
	settings.antialiasingLevel = 8;
}//constructeur
void Software::software_update()
{

}

double Software::getRE(){return RE;}
int Software::getEcartX(){return ecartX;}
int Software::getEcartY(){return ecartY;}
void Software::setSon(int a){son = a;}
bool Software::getEtat(){return en_marche;}
void Software::setEtat(bool stop){en_marche = stop;}
RenderWindow *Software::getFenetre(){return &fenetre;}
int Software::getVmax(){return Vmax;}
void Software::setVmax(int V){Vmax = V;}
string Software::getType_signalisation(){return type_signalisation;}
void Software::setType_signalisation(string T){type_signalisation = T;}
int Software::getVligne(){return Vligne;}
void Software::setVligne(int V){Vligne = V;}
