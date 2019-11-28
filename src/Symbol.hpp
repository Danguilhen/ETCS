#ifndef SYMBOL
#define SYMBOL

#include "Data.hpp"

#define V2f Vector2f

using namespace std;

class Symbol
{
	private :
		RenderWindow *fenetre;
		Data *data;
		Image image;
		Texture texture;
		Color m_color;
		vector<Sprite> sprite;
		void loadSymbol(string chemin_dacces);
	public :
		void afficher(V2f position);
		void effacer();
		void init(RenderWindow &fenetre, Data &data);
};

#endif