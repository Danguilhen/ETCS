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
void init_alarmes(Son &son)//au d�but
{
	son.init_buffer_click();
	son.init_buffer_S_info();
	son.init_buffer_S1_toofast();
	son.init_buffer_S2_warning();
}
//Lorsqu'un son doit �tre jou�
void jouer_alarmes(Son &son, int numero, int mode)
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
	son.set_mode(mode);
	if(numero == 1 && son.get_mode() != 4)
	son.get_sound().setBuffer(son.get_buffer_click());
	if(numero == 2 && son.get_mode() != 4)
	son.get_sound().setBuffer(son.get_buffer_S_info());
	if(numero == 3 && son.get_mode() != 4)
	son.get_sound().setBuffer(son.get_buffer_S1_toofast());
	if(numero == 4 && son.get_mode() != 4)
	son.get_sound().setBuffer(son.get_buffer_S2_warning());

	if(son.get_mode() == 1)
	{	son.get_sound().play();
		son.set_mode(4);
	}
	if(son.get_mode() == 2)
	{	son.get_sound().play();
		son.get_sound().setLoop(true);
		son.set_mode(4);
	}
	if(son.get_mode() == 3)
	{	son.get_sound().play();
		son.get_sound().stop();
		son.set_mode(4);
	}
}

