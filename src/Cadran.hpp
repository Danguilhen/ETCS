#ifndef CADRAN
#define CADRAN

#include "Tools.hpp"

using namespace std;
using namespace sf;

#define V2f Vector2f
#define PI 3.14159265
#define BLACK Color(0,0,0)
#define WHITE Color(255,255,255)
#define RED Color(191,0,2)
#define ORANGE Color(234,145,0)
#define YELLOW Color(223,223,0)
#define GREY Color(195,195,195)
#define DARK_GREY Color(85,85,85)

class DonneesAfficheurVitesse
{
    public:
		DonneesAfficheurVitesse();
		DonneesAfficheurVitesse(V2f cartesiens, V2f polaire, int vitesse);

		//definition des get
		void cartesiens(V2f cartesiens);
		void polaire(V2f polaire);
		void x(int x);
		void y(int y);
		void r(int r);
		void teta(int teta);
		void vitesse(int vitesse);

		//definition des set
		V2f cartesien();
		V2f polaire();
		float x();
		float y();
		float r();
		float teta();
		int vitesse();

    private:
		V2f *centre;
		float *teta_origine;
		V2f m_cartesiens;
		V2f m_polaire;
    	float m_vitesse;
};

class Cadran : public Tools
{
	private :
		int Vmax;
		ConvexShape aiguille;
		DonneesAfficheurVitesse graduations[401];
		V2f centre;
		CircleShape Centre;
		float teta0;
		float kmh2degVfaible;
		float kmh2degVeleve = kmh2degVfaible;
		float teta_origine;
		VertexArray Shape(DonneesAfficheurVitesse grad, V2f a, V2f b, V2f c, V2f d);
		V2f local2globalCoordonates(V2f CoordonneesPolaires);
	public :
		Cadran(int Vmax);
		void update();
};

#endif