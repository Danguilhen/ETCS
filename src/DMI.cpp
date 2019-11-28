#include "DMI.hpp"

DMI::DMI(Data &data, ETCS_Bord &bord) : etcs(fenetre, data), basic(fenetre, data)
{
	this->bord = &bord;
	this->data = &data;
	//creation et affichage de la fenetre
	fenetre.create(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height),"Ecran central", Style::Default, settings);
	fenetre.setFramerateLimit(60);
	settings.antialiasingLevel = 8;
}

void DMI::update()
{
	switch(signalisation)
	{
		case 0: ;
		case 1: basic.update();
		case 2: etcs.update();
		default: ;
	}
}