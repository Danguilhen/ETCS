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
#include "symbol.hpp"
#include "donnees.hpp"
#include "Texte.hpp"

int Texte_DMI::getPosition(){return position;}
void Texte_DMI::setPosition(int P){position = P;}
int Texte_DMI::getHeure(){return heure;}
void Texte_DMI::setHeure(int H){heure = H;}
string Texte_DMI::getMessage(){return message;}
void Texte_DMI::setMessage(string M){message = M;}
int Texte_DMI::getAcknowledgement(){return acknowledgement;}
void Texte_DMI::setAcknowledgement(int A){acknowledgement = A;}

void TexteMessages(RenderWindow & fenetre, double RE, Font & arial, int * ecart)
{
	for (int n = 0; n < 4; n++)
	{
		creation_texte(RE, "10H30", arial, WHITE, 10, 0, V2f(54 + 3, (350 + 7) + n*20), fenetre, 4, ecart);//+3 déplacement sur x par rapport à la norme
		creation_texte(RE, "Route unsuitable loading gauge", arial, WHITE, 12, 0, V2f(54 + 3 + 37, (350 + 8) + n*20), fenetre, 4, ecart);//Police 12 et décallage de 3 par rapport à l'heure
	}


}

