#ifndef TOOLS
#define TOOLS

#include "Software.hpp"

class Tools
{
	protected :
		Software *soft;
		Font arial;
		Text texte;
		Text metre;
		Tools();
	public :
		virtual void creation_texte(string message, Color couleur, int taille, double OutlineThickness, V2f pos, int mode);
		virtual void rectangle(V2f pos, V2f taille, Color col);
		virtual void couleurForme(VertexArray & bande,Color col, int n);
		virtual void creation_rectangle(V2f pos, V2f dim, int mode);
		virtual void step(vector<vector<float>> &tab, float valeur_debut, float valeur_fin, float valeur);
};

#endif