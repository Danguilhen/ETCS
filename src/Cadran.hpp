#ifndef CADRAN
#define CADRAN

#include "Tools.hpp"
#include "define.hpp"

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
		vector<DonneesAfficheurVitesse> graduations;
		V2f centre;
		CircleShape Centre;
		float teta0;
		float kmh2degVfaible;
		float kmh2degVeleve = kmh2degVfaible;
		float teta_origine;
		VertexArray Shape(DonneesAfficheurVitesse grad, V2f a, V2f b, V2f c, V2f d);
		V2f local2globalCoordonates(V2f CoordonneesPolaires);
	public :
		Cadran(int Vmax, Data &data, RenderWindow &fenetre);
		void update();
};

#endif