#ifndef texte
#define texte

class Texte_DMI
{
	private :

	int position;//position dans le 4 rectangle de E
	int heure;//heure de l'affichage
	string message;//message à diffuser
	int acknowledgement;//si besoin d'acquitter

	public :
	Texte_DMI(int h, string m, int a)
	{
		heure = h;
		message = m;
		acknowledgement = a;
	}

	int getPosition();
	void setPosition(int P);
	int getHeure();
	void setHeure(int H);
	string getMessage();
	void setMessage(string M);
	int getAcknowledgement();
	void setAcknowledgement(int A);
};

void TexteMessages(RenderWindow & fenetre, double RE, Font & arial, int * ecart);

#endif