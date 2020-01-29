#include "Symbol.hpp"


Symbol::Symbol(Software &soft)
{
	//cout<< "SYMBOL" <<endl;
	this->soft = &soft;
}

void Symbol::loadSymbol(string chemin_dacces)
{
	if(!image.loadFromFile(chemin_dacces)) // Si le chargement du fichier a �chou�
	{
	    cout << "Erreur durant le chargement de l'image" << endl;
	}
	else // Si le chargement de l'image a r�ussi
	{
		texture.loadFromImage(image);
	}
}

void Symbol::afficher(V2f position)
{
	Sprite spr;
	sprite.push_back(spr);
	int m = sprite.size() - 1;
	sprite[m].setTexture(texture);
	sprite[m].setScale(soft->getRE(), soft->getRE());
	position.x = position.x * soft->getRE() - sprite[m].getGlobalBounds().width / 2 + soft->getEcartX() * soft->getRE();
	position.y = position.y * soft->getRE() - sprite[m].getGlobalBounds().height / 2 + soft->getEcartY() * soft->getRE();
	sprite[m].setPosition(position);
	m_color = sprite[m].getColor();
	m_color.a = 255;
	sprite[m].setColor(m_color);
	soft->getFenetre()->draw(sprite[m]);
}

void Symbol::effacer()
{
	int m = sprite.size();
	for(int i = 0; i < m; i++)
	{
		sprite.erase(sprite.begin());
	}
	//m_color = sprite[0].getColor();
	//m_color.a = 0;
	//sprite[0].setColor(m_color);
}