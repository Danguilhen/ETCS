#ifndef ERTMS
#define ERTMS

class ETCS
{
	private :
		RenderWindow *fenetre;
		Data *data;
		vector <Symbol> symbol;
		vector <Button> button;
		Event event;
		Default def{*fenetre, *data, symbol, button};
		Special special{*fenetre, *data};
		Settings settings{*fenetre, *data};
		SRspeed srSpeed{*fenetre, *data};
		DataView dataView{*fenetre, *data};
		SystemVersion systemVersion{*fenetre, *data};
		void action();
	public :
		ETCS(RenderWindow &fenetre, Data &data);
		void update();
};

#endif