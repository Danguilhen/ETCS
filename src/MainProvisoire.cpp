#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Fenetres.hpp"

//define ---------------------------------------------------------------------------------------------------------------------------------
#define V2f Vector2f




//Prototypes -----------------------------------------------------------------------------------------------------------------------------
void affichageRectangle(double RE, RenderWindow & fenetre, string ecran, int * ecart);


//Main -----------------------------------------------------------------------------------------------------------------------------------

void affichageRectangle(double RE, RenderWindow & fenetre, string ecran, int * ecart)		//Affiche toutes les cases sur l'\E9cran
{
	if(ecran == "defaultWindow")
	{
		creation_rectangle(V2f((54 + 234 + 46), (54 + 30 + 191 + 25 + 50 + 50)), V2f(63, 30), RE, 1, fenetre, ecart);			//G11
		creation_rectangle(V2f((54 + 234 + 46 + 63), (54 + 30 + 191 + 25 + 50 + 50)), V2f(120, 30), RE, 1, fenetre, ecart);		//G12
		creation_rectangle(V2f((54 + 234 + 46 + 63 + 120), (54 + 30 + 191 + 25 + 2 * 50)), V2f(63, 30), RE, 1, fenetre, ecart);	//G13
	}
	creation_rectangle(V2f(0, 0), V2f(54, 54), RE, 1, fenetre, ecart);															//A1
	creation_rectangle(V2f(0, 54), V2f(54, (191 + 30)), RE, 1, fenetre, ecart);													//A2-3
	creation_rectangle(V2f(0, (54 +30 + 191)), V2f(54, 25), RE, 1, fenetre, ecart);												//A4
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25)), V2f(54, 25), RE, 1, fenetre, ecart);										//C8
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 2)), V2f(54, 25), RE, 1, fenetre, ecart);									//C9
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 3)), V2f(54, 25), RE, 1, fenetre, ecart);									//E1
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 4)), V2f(54, 25), RE, 1, fenetre, ecart);									//E2
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 5)), V2f(54, 25), RE, 1, fenetre, ecart);									//E3
	creation_rectangle(V2f((54 + 26 - 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), RE, 1, fenetre, ecart);						//B6
	creation_rectangle(V2f((54 + 140 + 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), RE, 1, fenetre, ecart);						//B5
	creation_rectangle(V2f((54 + 140 - 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), RE, 1, fenetre, ecart);						//B4
	creation_rectangle(V2f((54 + 140 - 36 * 3 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), RE, 1, fenetre, ecart);					//B3
	creation_rectangle(V2f((54 + 254 - 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), RE, 1, fenetre, ecart);						//B7
	creation_rectangle(V2f((54 + 3 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), RE, 1, fenetre, ecart);							//C1
	creation_rectangle(V2f(54, 0), V2f(280, 300), RE, 1, fenetre, ecart);														//B
	creation_rectangle(V2f(54, (54 + 30 + 191 + 25 + 50)), V2f(234, 4 * 20), RE, 1, fenetre, ecart);							//E5-6-7-8
	creation_rectangle(V2f((54 + 234), (54 + 30 + 191 + 25 + 50)), V2f(46, 40), RE, 2, fenetre, ecart);							//E10
	creation_rectangle(V2f((54 + 234), (54 + 30 + 191 + 25 + 50 + 40)), V2f(46, 40), RE, 2, fenetre, ecart);					//E11
	creation_rectangle(V2f(62, 257), V2f(36, 36), RE, 1, fenetre, ecart); //B6
	creation_rectangle(V2f(140, 257), V2f(36, 36), RE, 1, fenetre, ecart); //B3
	creation_rectangle(V2f(177, 257), V2f(36, 36), RE, 1, fenetre, ecart); //B4
	creation_rectangle(V2f(212, 257), V2f(36, 36), RE, 1, fenetre, ecart); //B5
	creation_rectangle(V2f(289, 257), V2f(36, 36), RE, 1, fenetre, ecart); //B7
}