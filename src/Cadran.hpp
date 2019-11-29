#ifndef CADRAN
#define CADRAN

#include "Tools.hpp"
#include "define.hpp"
#include "ETCS_Bord.hpp"

class DonneesAfficheurVitesse
{
    public:
		DonneesAfficheurVitesse(V2f & centre);
		DonneesAfficheurVitesse(V2f cartesiens, V2f polaire, int vitesse, V2f & centre);

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
		float Vred;
		float Vorange;
		float Vyellow;
		float Vwhite;
		float VmediumGrey;
		float VdarkGrey;
		Color aiguille;
		ETCS_Bord *bord;
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
		Cadran(int Vmax, Data &data, RenderWindow &fenetre, ETCS_Bord &bord);
		void update();
		void convertisseurVitesses()
};

#endif