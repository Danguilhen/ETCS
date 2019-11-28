#ifndef SYMBOL
#define SYMBOL

#include "Data.hpp"
#include "define.hpp"

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

	public :
		Symbol(RenderWindow &fenetre, Data &data);
		void loadSymbol(string chemin_dacces);
		void afficher(V2f position);
		void effacer();
};

#endif