#ifndef son_train
#define son_train

class Son
{
	private :
		sf::SoundBuffer buffer_click;
		sf::SoundBuffer buffer_S_info;
		sf::SoundBuffer buffer_S1_toofast;
		sf::SoundBuffer buffer_S2_warning;
		sf::Sound sound;
		int mode;

	public :
		Son();
		void jouer_alarmes(int numero, int mode);
};

#endif