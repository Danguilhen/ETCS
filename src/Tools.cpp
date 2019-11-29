#include "Tools.hpp"

void Tools::creation_texte(string message, Color couleur, int taille, double OutlineThickness, V2f pos, int mode) //mode 1 : centrer / mode 2 : aligner droite / mode 3 : Geographical position / mode 4 : aligner gauche
{
	Text texte;
	texte.setString(message);
	texte.setFont(data->getFont());
	texte.setOutlineThickness(OutlineThickness);
	texte.setOutlineColor(couleur);
	texte.setCharacterSize(taille * data->getRE());
	texte.setFillColor(couleur);
	if(mode == 2)
		texte.setOrigin(texte.getLocalBounds().left + texte.getLocalBounds().width * 1.0f, texte.getLocalBounds().top + texte.getLocalBounds().height / 2.0f);
	else if(mode == 4)
	{
		if(message[message.size() - 1] == '_')
		{
			message = message.substr(0, message.size() - 1);
		}

		texte.setOrigin(texte.getLocalBounds().left, texte.getLocalBounds().top + texte.getLocalBounds().height / 2.0f);
		if(message[message.size() - 1] == '_')
		{
			message += "_";
			texte.setOrigin(texte.getLocalBounds().left, (pos.y + data->getEcartY()) * data->getRE());
		}
	}
	else if(mode == 3 && message.size() > 3)
	{
		Text metre;
		if(couleur == BLACK)
			metre.setString(message.substr(message.size() - 3, 3));
		else
			metre.setString(message.substr(1, message.size() - 1));
		if(message.size() > 6)
			message = message.substr(0, message.size() - 6) + " " + message.substr(message.size() - 6, 6);
		if(couleur == BLACK)
			message = message.substr(0, message.size() - 3) + " ";
		else
			message = message.substr(0, 1) + " ";
		texte.setString(message);
		metre.setFont(data->getFont());
		metre.setOutlineThickness(OutlineThickness);
		metre.setOutlineColor(couleur);
		metre.setCharacterSize(10 * data->getRE());
		metre.setFillColor(couleur);
		texte.setOrigin(texte.getLocalBounds().left + (texte.getLocalBounds().width + metre.getLocalBounds().width) / 2.0f, texte.getLocalBounds().top + texte.getLocalBounds().height / 2.0f);
		metre.setOrigin(metre.getLocalBounds().left - (texte.getLocalBounds().width - metre.getLocalBounds().width) / 2.0f, metre.getLocalBounds().top - texte.getLocalBounds().height / 2.0f + metre.getLocalBounds().height * 1.0f);
		metre.setPosition((pos.x + data->getEcartX()) * data->getRE() * 1.0f, (pos.y + data->getEcartY()) * data->getRE() * 1.0f);
		fenetre->draw(metre);
	}
	else if(mode == 1 || mode == 3)
	{
		if(mode == 3)
			texte.setCharacterSize(10 * data->getRE());
		texte.setOrigin(texte.getLocalBounds().left + texte.getLocalBounds().width / 2.0f, texte.getLocalBounds().top + texte.getLocalBounds().height / 2.0f);
	}
	texte.setPosition((pos.x + data->getEcartX()) * data->getRE() * 1.0f, (pos.y + data->getEcartY()) * data->getRE() * 1.0f);
	fenetre->draw(texte);
}

void Tools::rectangle(V2f pos, V2f taille, Color col)
{
	RectangleShape barre(V2f(taille.x * data->getRE(), taille.y * data->getRE()));
	barre.setPosition((pos.x + data->getEcartX()) * data->getRE(), (pos.y + data->getEcartY()) * data->getRE());
	barre.setFillColor(col);
	fenetre->draw(barre);
}

void Tools::couleurForme(VertexArray &bande,Color col, int n)
{
	for(int i = 0; i < n; i++)
	{
		bande[i].color= col;
	}
}