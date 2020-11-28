#include "Software.hpp"

Software::Software()
{
	//fenetre de l'ecran principal
	if(VideoMode::getDesktopMode().width / 640.0f < VideoMode::getDesktopMode().height / 480.0f)
	RE = VideoMode::getDesktopMode().width / 640.0f;	//rapport Ecran
	else
		RE = VideoMode::getDesktopMode().height / 480.0f; //rapport Ecran
	//creation et affichage de la fenetre
	float widthRatio = VideoMode::getDesktopMode().width / 640.0f;
	float heightRatio = VideoMode::getDesktopMode().height / 480.0f;

	if (widthRatio > heightRatio) {
		blackRatio = widthRatio / heightRatio;
		biggestLen = 0;
	}
	if (widthRatio <= heightRatio) {
		blackRatio = heightRatio / widthRatio;
		biggestLen = 1;
	}
	fenetre.create(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height),"Ecran central", Style::Default, settings);
	fenetre.setFramerateLimit(60);
	settings.antialiasingLevel = 8;
	//fenetre du pcc
	//fenPcc.create(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height),"PCC", Style::Default, settingsPcc);
}//constructeur
void Software::software_update()
{

}

float Software::getRE(){return RE;}
float Software::getBlackRatio() { return blackRatio; }
bool Software::getBiggestLen() { return biggestLen; }
int Software::getEcartX(){return ecartX;}
int Software::getEcartY(){return ecartY;}
bool Software::getEtat(){return en_marche;}
void Software::setEtat(bool stop){en_marche = stop;}
RenderWindow *Software::getFenetre(){return &fenetre;}
//RenderWindow *Software::getFenPcc(){return &fenPcc;}
int Software::getVmax(){return Vmax;}
void Software::setVmax(int V){Vmax = V;}
bool Software::getS_Finished(){return s_Finished;}
void Software::setS_Finished(bool S){s_Finished = S;}
