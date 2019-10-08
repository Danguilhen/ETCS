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
#include "donnees.hpp"
#include "son_train.hpp"

using namespace sf;

//Fonctions appel�es dans le main
Son::Son() //au d�but
{
	buffer_click.loadFromFile("ressources/sounds/click.wav");
	buffer_S_info.loadFromFile("ressources/sounds/S_info.wav");
	buffer_S1_toofast.loadFromFile("ressources/sounds/S1_toofast.wav");
	buffer_S2_warning.loadFromFile("ressources/sounds/S2_warning.wav");
}

//Lorsqu'un son doit �tre jou�
void Son::jouer_alarmes(int numero, int Mode)
{
	/*
		Num�ro 1 : click
		Num�ro 2 : S-info
		Num�ro 3 : S1_toofast
		Num�ro 4 : S2_warning

		Mode 1 : Jouer UNE fois
		Mode 2 : Jouer en boucle
		Mode 3 : Stopper la boucle, le son s'arr�te
		Mode 4 : La fonction est appel�e mais ne modifie rien.

		Il ne faut appeler le son qu'une seule fois
	*/
	if(mode == 4)
		sound.setLoop(false);
	mode = Mode;
	if(numero == 1 && mode != 4)
		sound.setBuffer(buffer_click);
	if(numero == 2 && mode != 4)
		sound.setBuffer(buffer_S_info);
	if(numero == 3 && mode != 4)
		sound.setBuffer(buffer_S1_toofast);
	if(numero == 4 && mode != 4)
		sound.setBuffer(buffer_S2_warning);

	if(mode == 1)
	{
		sound.play();
		mode = 4;
	}
	if(mode == 2)
	{
		sound.play();
		sound.setLoop(true);
		mode = 4;
	}
	if(mode == 3)
	{
		sound.setLoop(false);
		mode = 4;
	}
}