#include "Tools.hpp"

Tools::Tools()
{
	if(!arial.loadFromFile("ressources/fonts/arial.ttf")) //recuperation de la police
		cout << "ERREUR chargement police !" << endl;
}

void Tools::creation_texte(string message, Color couleur, int taille, float OutlineThickness, V2f pos, int mode) //mode 1 : centrer / mode 2 : aligner droite / mode 3 : Geographical position / mode 4 : aligner gauche
{
	texte.setString(message);
	texte.setFont(arial);
	texte.setOutlineThickness(OutlineThickness);
	texte.setOutlineColor(couleur);
	texte.setCharacterSize(static_cast<unsigned int>(taille * soft->getRE()));
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
			texte.setOrigin(texte.getLocalBounds().left, (pos.y + soft->getEcartY()) * soft->getRE());
		}
	}
	else if(mode == 3 && message.size() > 3)
	{
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
		metre.setFont(arial);
		metre.setOutlineThickness(OutlineThickness);
		metre.setOutlineColor(couleur);
		metre.setCharacterSize(static_cast<unsigned int>(10 * soft->getRE()));
		metre.setFillColor(couleur);
		texte.setOrigin(texte.getLocalBounds().left + (texte.getLocalBounds().width + metre.getLocalBounds().width) / 2.0f, texte.getLocalBounds().top + texte.getLocalBounds().height / 2.0f);
		metre.setOrigin(metre.getLocalBounds().left - (texte.getLocalBounds().width - metre.getLocalBounds().width) / 2.0f, metre.getLocalBounds().top - texte.getLocalBounds().height / 2.0f + metre.getLocalBounds().height * 1.0f);
		metre.setPosition((pos.x + soft->getEcartX()) * soft->getRE() * 1.0f, (pos.y + soft->getEcartY()) * soft->getRE() * 1.0f);
		soft->getFenetre()->draw(metre);
	}
	else if(mode == 1 || mode == 3)
	{
		if(mode == 3)
			texte.setCharacterSize(static_cast<unsigned int>(10 * soft->getRE()));
		texte.setOrigin(texte.getLocalBounds().left + texte.getLocalBounds().width / 2.0f, texte.getLocalBounds().top + texte.getLocalBounds().height / 2.0f);
	}
	texte.setPosition((pos.x + soft->getEcartX()) * soft->getRE() * 1.0f, (pos.y + soft->getEcartY()) * soft->getRE() * 1.0f);
	soft->getFenetre()->draw(texte);
}

void Tools::rectangle(V2f pos, V2f taille, Color col)
{
	RectangleShape barre(V2f(taille.x * soft->getRE(), taille.y * soft->getRE()));
	barre.setPosition((pos.x + soft->getEcartX()) * soft->getRE(), (pos.y + soft->getEcartY()) * soft->getRE());
	barre.setFillColor(col);
	soft->getFenetre()->draw(barre);
}

void Tools::couleurForme(VertexArray &bande,Color col, int n)
{
	for(int i = 0; i < n; i++)
	{
		bande[i].color= col;
	}
}

//RESUME DE LA FONCTION
//Besoin de la position de point en haut � gauche et de la dimension du quadrilat�re
//RE permet de modifier l'�paisseur en fct du rapport d'�cran
//mode 1=case mode 2=bouton mode 3=rappelle de la fonction pour cr�ation du carr� int�rieur
void Tools::creation_rectangle(V2f pos, V2f dim, int mode)
{
	if(mode == 1)
	{
		rectangle(pos, dim, SHADOW);
		rectangle(pos, V2f(dim.x - 1, dim.y - 1), BLACK);
		rectangle(V2f(pos.x + 1, pos.y + 1), V2f(dim.x - 2, dim.y - 2), DARK_BLUE);
	}
	if(mode == 2)
	{
		rectangle(pos, dim, SHADOW);
		rectangle(pos, V2f(dim.x - 1, dim.y - 1), BLACK);
		rectangle(V2f(pos.x + 1, pos.y + 1), V2f(dim.x - 3, dim.y - 3), SHADOW);
		rectangle(V2f(pos.x + 2, pos.y + 2), V2f(dim.x - 4, dim.y - 4), DARK_BLUE);
	}
	if (mode == 5)
	{
	    rectangle(V2f(pos.x + 0, pos.y + 0), V2f(dim.x - 0, dim.y - 0), WHITE);
		rectangle(V2f(pos.x + 1, pos.y + 1), V2f(dim.x - 2, dim.y - 2), RED);
	}
	if (mode == 6)
	{
		rectangle(V2f(pos.x + 0, pos.y + 0), V2f(dim.x - 0, dim.y - 0), WHITE);
		rectangle(V2f(pos.x + 1, pos.y + 1), V2f(dim.x - 2, dim.y - 2), GREEN);
	}
	if (mode == 7)
	{
		rectangle(V2f(pos.x + 0, pos.y + 0), V2f(dim.x - 0, dim.y - 0), WHITE);
		rectangle(V2f(pos.x + 1, pos.y + 1), V2f(dim.x - 2, dim.y - 2), BLACK);
	}
	if (mode == 8)
	{
		rectangle(V2f(pos.x + 0, pos.y + 0), V2f(dim.x - 0, dim.y - 0), BLACK);
		rectangle(V2f(pos.x + 1, pos.y + 1), V2f(dim.x - 2, dim.y - 2), WHITE);
	}
	/*
	int epaisseur = RE;
	VertexArray bande(Quads,4);
	pos.x = pos.x * RE;
	pos.y = pos.y * RE;
	dim.x = dim.x * RE;
	dim.y = dim.y * RE;

	//Creation 1 ere bande
	bande[0].position=pos;
	bande[1].position=V2f(pos.x + dim.x - epaisseur, pos.y);
	bande[2].position=V2f(pos.x + dim.x - epaisseur, pos.y + epaisseur);
	bande[3].position=V2f(pos.x, pos.y + epaisseur);

	if(mode == 3)
	{
		couleurForme(bande, SHADOW, 4);
	}
	else
	{
		couleurForme(bande, BLACK, 4);
	}
	fenetre.draw(bande);

	//Creation 2eme bande
	bande[0].position= pos;
	bande[1].position=V2f(pos.x + epaisseur, pos.y);
	bande[2].position=V2f(pos.x + epaisseur, pos.y + dim.y - epaisseur);
	bande[3].position=V2f(pos.x, pos.y + dim.y - epaisseur);

	if(mode == 3)
	{
		couleurForme(bande, SHADOW, 4);
	}
	else
	{
		couleurForme(bande, BLACK, 4);
	}
	fenetre.draw(bande);

	//Creation 3eme bande
	bande[0].position= V2f(pos.x, pos.y + dim.y - epaisseur);
	bande[1].position=V2f(pos.x + dim.x, pos.y + dim.y - epaisseur);
	bande[2].position=V2f(pos.x + dim.x, pos.y + dim.y);
	bande[3].position=V2f(pos.x, pos.y + dim.y);

	if(mode == 3)
	{
		couleurForme(bande, BLACK, 4);
	}
	else
	{
		couleurForme(bande, SHADOW, 4);
	}

	fenetre.draw(bande);

	//Creation 4eme bande
	bande[0].position= V2f(pos.x+ dim.x - epaisseur, pos.y);
	bande[1].position=V2f(pos.x + dim.x, pos.y);
	bande[2].position=V2f(pos.x + dim.x, pos.y + dim.y);
	bande[3].position=V2f(pos.x+ dim.x - epaisseur, pos.y + dim.y);

	if(mode == 3)
	{
		couleurForme(bande, BLACK, 4);
	}
	else
	{
		couleurForme(bande, SHADOW, 4);
	}
	fenetre.draw(bande);

	if(mode == 2)		//CREER LE CARRE INTERIEUR POUR UN BOUTON
	{
		pos.x = pos.x + epaisseur;
		pos.y = pos.y + epaisseur;
		dim.x = dim.x - 2 * epaisseur;
		dim.y = dim.y - 2 * epaisseur;

		creation_rectangle(pos, dim,3, 3, fenetre, ecart);
	}
	*/
}

void Tools::step(vector<vector<double>> &tab, double valeur_debut, double valeur_fin, double valeur)
//1 renseigner le vector à 2 dimensions
//2 renseigner la valeur du début (plus petit)
//3 renseigner la valeur de la fin (plus grand)
//4 renseigner la valeur (acceleration, vitesse, ...)
{
	vector<double> ligne {valeur_debut, valeur_fin, valeur};
	tab.push_back(ligne);
}