#include "Sound.hpp"

Son::Son()
{
 //
}

void Son::playfunction(int choice)
{
	if(choice == 4)
		music.openFromFile("ressources/sounds/S2_warning.wav");
	if(choice == 3)
		music.openFromFile("ressources/sounds/S1_toofast.wav");
	if(choice == 2)
		music.openFromFile("ressources/sounds/S_info.wav");
	if(choice == 1)
		music.openFromFile("ressources/sounds/click.wav");
	if(music.getStatus() != music.Playing)
	{
		music.play();
		if(choice == 3 || choice == 4)
			music.setLoop(true);
	}
	music.setVolume(50);
}

void Son::stopfunction()
{
	music.stop();
}
