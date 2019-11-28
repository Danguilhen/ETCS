#ifndef Basic
#define Basic

class BASIC
{
	private :
		RenderWindow *fenetre
		Data *data
	public :
		BASIC(RenderWindow &fenetre, Data &data);
		void update();
};

#endif