#ifndef CADRAN
#define CADRAN

#include "../Tools.hpp"
#include "../define.hpp"
#include "../Bord/ETCS_Bord.hpp"

class DonneesAfficheurVitesse
{
    public:
		DonneesAfficheurVitesse(V2f & centre, float & teta_origine);
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
		double x();
		double y();
		double r();
		double teta();
		int vitesse();

    private:
		V2f *centre;
		float *teta_origine;
		V2f m_cartesiens;
		V2f m_polaire;
    	int m_vitesse;
};


class Cadran : public Tools
{
	private :
		double Vred = 0;
		double Vorange = 0;
		double Vyellow = 0;
		double Vwhite = 0;
		double VmediumGrey = 0;
		double VdarkGrey = 0;
		sf::Color aiguilleColor = GREY;
		ETCS_Bord *bord;
		Train_dynamique *T_D;
		sf::ConvexShape aiguille;
		std::vector<DonneesAfficheurVitesse> graduations;
		V2f centre;
		sf::CircleShape Centre;
		float teta0;
		float kmh2degVfaible;
		float kmh2degVeleve = kmh2degVfaible;
		float teta_origine;
		sf::VertexArray Shape(DonneesAfficheurVitesse grad, V2f a, V2f b, V2f c, V2f d);
		V2f local2globalCoordonates(V2f CoordonneesPolaires);
	public :
		Cadran(Software &soft, Train_dynamique &T_D, ETCS_Bord &bord);
		Cadran(Software &soft, Train_dynamique &T_D);
		void creation();
		void update();
		void convertisseurVitesses();
		void actualisationVitesse(double red, double orange, double yellow, double white, double mediumGrey, double darkGrey);
};

#endif