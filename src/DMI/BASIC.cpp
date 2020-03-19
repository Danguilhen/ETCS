#include "BASIC.hpp"

BASIC::BASIC(Train_dynamique &T_D, Software &soft) : cadran(soft, T_D)
{
	this->soft = &soft;
}

void BASIC::update()
{
	Basic_action();
	fond_ecran();
	cadran.update();
	affichageBoutons();

}

void BASIC::Basic_action()
{
    while(soft->getFenetre()->pollEvent(event))
    {
	    if(event.type == Event::Closed)
        {
			soft->getFenetre()->close();
			soft->setEtat(false);
		}
		if(event.type == Event::KeyPressed)
		{
		    if(event.key.code == Keyboard::Escape)
			{
				soft->getFenetre()->close();
				soft->setEtat(false);
			}
		}
    }
}

void BASIC::fond_ecran()
{

	fond[0].position = V2f(soft->getEcartX() * soft->getRE(), soft->getEcartY() * soft->getRE());
	fond[1].position = V2f((640 + soft->getEcartX()) * soft->getRE(), soft->getEcartY() * soft->getRE());
	fond[2].position = V2f((640 + soft->getEcartX()) * soft->getRE(), (480 + soft->getEcartY()) * soft->getRE());
	fond[3].position = V2f(soft->getEcartX() * soft->getRE(), (480 + soft->getEcartY()) * soft->getRE());
	couleurForme(fond, DARK_BLUE, 4);
	soft->getFenetre()->draw(fond);
}

void BASIC::affichageBoutons()
{
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);			//F1
	creation_rectangle(V2f(64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);			//F2
	creation_rectangle(V2f(2 *64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F3
	creation_rectangle(V2f(3 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F4
	creation_rectangle(V2f(4 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F5
	creation_rectangle(V2f(5 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F6
	creation_rectangle(V2f(6 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F7
	creation_rectangle(V2f(7 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F8
	creation_rectangle(V2f(8 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F9
	creation_rectangle(V2f(9 * 64, (54 + 30 + 191 + 25 * 5 + 30)), V2f(64, 50), 2);		//F10
	creation_rectangle(V2f((640 - 40), 28), V2f(40, 64), 2);							//H2
	creation_rectangle(V2f((640 - 40), (28 + 64)), V2f(40, 64), 2);						//H3
	creation_rectangle(V2f((640 - 40), (28 + 2 * 64)), V2f(40, 64), 2);					//H4
	creation_rectangle(V2f((640 - 40), (28 + 3 * 64)), V2f(40, 64), 2);					//H5
	creation_rectangle(V2f((640 - 40), (28 + 4 * 64)), V2f(40, 64), 2);					//H6
	creation_rectangle(V2f((640 - 40), (28 + 5 * 64)), V2f(40, 82), 2);					//H7
	creation_rectangle(V2f(0, 0), V2f(54, (54 + 30 + 191 + 25)), 1);
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25)), V2f(54, 25), 1);
}

void BASIC::affichageFreinage()
{
	creation_rectangle(V2f((54 + 280 + 40 + 166 + 40 + 20 + 40), 0), V2f(440, (54 + 30 + 191 + 25 + 25 + 25  + 25 + 25 + 25 + 30 + 50)), 1);
}