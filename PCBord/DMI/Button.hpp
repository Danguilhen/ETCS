#ifndef BUTTON
#define BUTTON

#include "../define.hpp"
#include "../Software.hpp"

class Button
{
	private :
		Software *soft;
		std::string type;
		int driver_action;//press� ou non
		int button_activation = 0;//nombre de fois activ�
		bool button_state;//enabled ou non
		sf::Clock chrono;
		sf::Time t_actif;
		int n; // variable utilis�e pour le down_type

	public :
		Button(Software &soft);
		std::string gettype();
		void settype(std::string P);
		int getdriver_action();
		void setdriver_action(int P);
		void action_type();
		int getactivation();
};

#endif