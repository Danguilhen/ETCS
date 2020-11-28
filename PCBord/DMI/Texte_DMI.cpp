#include "Texte_DMI.hpp"

Texte_DMI::Texte_DMI(int h, string m, int a, Software &soft)
{
	heure = h;
	message = m;
	acknowledgement = a;
	this->soft = &soft;
}

void Texte_DMI::TexteMessages()
{
		creation_texte("10H30", WHITE, 10, 0, V2f(54 + 3, 350 + 7 + 1 * 20), 4);//+3 déplacement sur x par rapport à la norme
		creation_texte("Route unsuitable loading gauge", WHITE, 12, 0, V2f(54 + 3 + 37, 350 + 8 + 1 * 20), 4);//Police 12 et décallage de 3 par rapport à l'heure

}

int Texte_DMI::getHeure(){return heure;}
void Texte_DMI::setHeure(int H){heure = H;}
string Texte_DMI::getMessage(){return message;}
void Texte_DMI::setMessage(string M){message = M;}
int Texte_DMI::getAcknowledgement(){return acknowledgement;}
void Texte_DMI::setAcknowledgement(int A){acknowledgement = A;}
