#ifndef TDMI
#define TDMI

#include "../define.hpp"
#include "../Tools.hpp"

class Texte_DMI : public Tools
{
	private :
		int heure;//heure de l'affichage
		string message;//message à diffuser
		int acknowledgement;//si besoin d'acquitter

	public :
		Texte_DMI(int h, string m, int a, Software &soft);
		void TexteMessages();
		int getHeure();
		void setHeure(int H);
		string getMessage();
		void setMessage(string M);
		int getAcknowledgement();
		void setAcknowledgement(int A);
};

#endif