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
	void init_buffer_click();
	void init_buffer_S_info();
	void init_buffer_S1_toofast();
	void init_buffer_S2_warning();
	SoundBuffer& get_buffer_click();
	SoundBuffer& get_buffer_S_info();
	SoundBuffer& get_buffer_S1_toofast();
	SoundBuffer& get_buffer_S2_warning();
	void set_mode(int M);
	int get_mode();
	Sound& get_sound();
};
void jouer_alarmes(Son &son, int numero, int mode);
void init_alarmes(Son &son);

#endif