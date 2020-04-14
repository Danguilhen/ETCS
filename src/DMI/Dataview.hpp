/*#ifndef DATW
#define DATW

#include "define.hpp"
#include "Fenetre.hpp"
#include "Symbol.hpp"
#include "LeftSide.hpp"
#include "Button.hpp"

class Dataview : public Fenetre
{
	private :
	LeftSide left;

public:
	Dataview(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, string &ecran);
	void update(std::string title);

};


#endif*/