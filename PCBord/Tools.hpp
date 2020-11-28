#ifndef TOOLS
#define TOOLS

#include "Software.hpp"
#include "define.hpp"

class Tools
{
	protected :
		Software *soft;
		sf::Font arial;
		sf::Text texte;
		sf::Text metre;
		Tools();
	public :
		virtual void creation_texte(std::string message, sf::Color couleur, int taille, float OutlineThickness, V2f pos, int mode);
		virtual void rectangle(V2f pos, V2f taille, sf::Color col);
		virtual void couleurForme(sf::VertexArray & bande, sf::Color col, int n);
		virtual void creation_rectangle(V2f pos, V2f dim, int mode);
		virtual void step(std::vector<std::vector<double>> &tab, double valeur_debut, double valeur_fin, double valeur);
};

#endif