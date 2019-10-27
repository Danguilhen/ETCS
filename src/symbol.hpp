#ifndef photo
#define photo



#define PI 3.14159265
#define V2i Vector2i

using namespace sf;
using namespace std;

class DonneesAfficheurVitesse
{
    public:

	DonneesAfficheurVitesse();
	DonneesAfficheurVitesse(Vector2f cartesiens, Vector2f polaire, int vitesse);

	/////////////////////////////////////////////////////////////
	//definition des methodes
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





class Cadran
{
	private :
		ConvexShape aiguille;
		V2f centre;
		V2f local2globalCoordonates(V2f localOrigin, float teta_origine, V2f CoordonneesPolaires);
	public :
		void arcVitesse(V2f centre, float V_red, float V_orange, float V_yellow, float V_white, float V_medium_grey, float V_dark_grey, double RE, RenderWindow & fenetre, Font & arial, DonneesAfficheurVitesse graduations[], int * ecart);
		Cadran(double RE, int Vmax, DonneesAfficheurVitesse graduations[], int * ecart);
};


#endif