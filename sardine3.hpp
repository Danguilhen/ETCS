#ifndef sardine3
#define sardine3

class DonneesAfficheurVitesse
{
    public:

	DonneesAfficheurVitesse();
	DonneesAfficheurVitesse(Vector2f cartesiens, Vector2f polaire, int vitesse);

	/////////////////////////////////////////////////////////////
	//definition des methodes
	Vector2f local2globalCoordonates(Vector2f localOrigin, float teta_origine);
	/////////////////////////////////////////////////////////////

	//definition des get
	void cartesiens(Vector2f cartesiens);
	void polaire(Vector2f polaire);
	void x(int x);
	void y(int y);
	void r(int r);
	void teta(int teta);
	void vitesse(int vitesse);

	/////////////////////////////////////////////////////////////
	//definition des set

	Vector2f cartesien();
	Vector2f polaire();
	float x();
	float y();
	float r();
	float teta();
	int vitesse();

    private:

	Vector2f m_cartesiens;
	Vector2f m_polaire;
    float m_vitesse;
};

void sardine(double RE, RenderWindow & fenetre);

#endif