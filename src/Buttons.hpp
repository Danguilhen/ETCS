#ifndef button
#define button

#include "symbol.hpp"

class Buttons
{
	private :

	string type;
	int driver_action;//press� ou non
	int button_activation = 0;//nombre de fois activ�
	bool button_state;//enabled ou non
	Clock chrono;
	Time t_actif;
	int n; // variable utilis�e pour le down_type

	public :

	string gettype();
	void settype(string P);
	int getdriver_action();
	void setdriver_action(int P);
	void action_type(Son & son);
	int getactivation();
};

#endif