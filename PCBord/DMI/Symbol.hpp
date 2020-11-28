#ifndef SYMBOL
#define SYMBOL

#include "../Software.hpp"


class Symbol
{
	private :
		Software *soft;
		sf::Image image;
		sf::Texture texture;
		sf::Color m_color;
		std::vector<sf::Sprite> sprite;

	public :
		Symbol(Software &soft);
		void loadSymbol(std::string chemin_dacces);
		void afficher(V2f position);
		void effacer();
};

#endif