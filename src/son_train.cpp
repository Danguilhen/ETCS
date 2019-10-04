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
//initilisations
void Son::init_buffer_click()
{
	buffer_click.loadFromFile("ressources/sounds/click.wav");

}
void Son::init_buffer_S_info()
{
	buffer_S_info.loadFromFile("ressources/sounds/S_info.wav");

}
void Son::init_buffer_S1_toofast()
{
	buffer_S1_toofast.loadFromFile("ressources/sounds/S1_toofast.wav");

}
void Son::init_buffer_S2_warning()
{
	buffer_S2_warning.loadFromFile("ressources/sounds/S2_warning.wav");

}
//getter
SoundBuffer& Son::get_buffer_click(){return buffer_click;}
SoundBuffer& Son::get_buffer_S_info(){return  buffer_S_info;}
SoundBuffer& Son::get_buffer_S1_toofast(){return buffer_S1_toofast;}
SoundBuffer& Son::get_buffer_S2_warning(){return buffer_S2_warning;}
Sound& Son::get_sound(){return sound;}
void Son::set_mode(int M){mode = M;}
int Son::get_mode(){return mode;}
//Fonctions appel�es dans le main
void Son::init_alarmes()//au d�but
{
	init_buffer_click();
	init_buffer_S_info();
	init_buffer_S1_toofast();
	init_buffer_S2_warning();
}
//Lorsqu'un son doit �tre jou�
void Son::jouer_alarmes(int numero, int mode)
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
	set_mode(mode);
	if(numero == 1 && get_mode() != 4)
		get_sound().setBuffer(get_buffer_click());
	if(numero == 2 && get_mode() != 4)
		get_sound().setBuffer(get_buffer_S_info());
	if(numero == 3 && get_mode() != 4)
		get_sound().setBuffer(get_buffer_S1_toofast());
	if(numero == 4 && get_mode() != 4)
		get_sound().setBuffer(get_buffer_S2_warning());

	if(get_mode() == 1)
	{
		get_sound().play();
		set_mode(4);
	}
	if(get_mode() == 2)
	{
		get_sound().play();
		get_sound().setLoop(true);
		set_mode(4);
	}
	if(get_mode() == 3)
	{
		get_sound().play();
		get_sound().stop();
		set_mode(4);
	}
}

