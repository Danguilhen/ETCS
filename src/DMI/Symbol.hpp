#ifndef SYMBOL
#define SYMBOL

#include "Software.hpp"


class Symbol
{
	private :
		Software *soft;
		Image image;
		Texture texture;
		Color m_color;
		vector<Sprite> sprite;

	public :
		Symbol(Software &soft);
		void loadSymbol(string chemin_dacces);
		void afficher(V2f position);
		void effacer();
};

#endif