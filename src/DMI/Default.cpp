#include "Default.hpp"

Default::Default(RenderWindow &fenetre, Data &data, vector<Symbol> &symbol, vector<Button> &buttons, ETCS_Bord &bord, string & ecran): left(data, fenetre, bord, symbol), planning(symbol, data, fenetre, bord)
{
	this->fenetre = &fenetre;
	this->data = &data;
	this->symbol = &symbol;
	this->buttons = &buttons;
	this->bord = &bord;
	this->ecran = &ecran;
}

void Default::update()
{
	left.update();

	SE_04.afficher(V2f(64 * 4 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0));			//F5
	DR_01.afficher(V2f(64 * 6 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0));			//F7
	NA_13.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 3 + 64 / 2.0));	//H5
	NA_14.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 4 + 64 / 2.0));	//H6
	NA_17.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2 + 64 / 2.0));	//H4
	NA_18.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0));		//H3
	NA_20.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 5 * 64 + 82 / 2.0));	//H7
	DR_04.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 5 * 64 + 82 / 2.0));	//H7

	creation_rectangle(V2f((54 + 234 + 46), (54 + 30 + 191 + 25 + 50 + 50)), V2f(63, 30), 1);			//G11
	creation_rectangle(V2f((54 + 234 + 46 + 63), (54 + 30 + 191 + 25 + 50 + 50)), V2f(120, 30), 1);		//G12
	creation_rectangle(V2f((54 + 234 + 46 + 63 + 120), (54 + 30 + 191 + 25 + 2 * 50)), V2f(63, 30), 1);	//G13

	time_t curtime;
	time(&curtime);
	string date = ctime(&curtime);
	creation_texte(date.substr(10,9), GREY, 10, 0, V2f(54 + 280 + 63 + 120 + 63 / 2.0, 300 + 50 + 50 + 30 / 2.0), 1);
	creation_texte("Main", GREY, 16, 0, V2f(64 / 2.0, 300 + 4 * 25 + 30 + 50 / 2.0), 1);
	creation_texte("Over-", GREY, 16, 0, V2f(64 + 64 / 2.0, 300 + 4 * 25 + 30 + 50 / 2.0 - 10), 1);
	creation_texte("ride", GREY, 16, 0, V2f(64 + 64 / 2.0, 300 + 4 * 25 + 30 + 50 / 2.0 + 10), 1);
	creation_texte("Data", GREY, 16, 0, V2f(64 * 2 + 64 / 2.0, 300 + 4 * 25 + 30 + 50 / 2.0 - 10), 1);
	creation_texte("view", GREY, 16, 0, V2f(64 * 2 + 64 / 2.0, 300 + 4 * 25 + 30 + 50 / 2.0 + 10), 1);
	creation_texte("Spec", GREY, 16, 0, V2f(64 * 3 + 64 / 2.0, 300 + 4 * 25 + 30 + 50 / 2.0), 1);

	for(int i = 0; i <= 15; i++)
		(*buttons)[i].settype("up_type");
	if((*buttons)[0].getactivation() == 1)
	{
		(*buttons)[3].settype("disabled");
		(*buttons)[10].settype("disabled");
		(*buttons)[12].settype("disabled");
		(*buttons)[13].settype("disabled");
		(*buttons)[14].settype("disabled");
		(*buttons)[15].settype("disabled");
        *ecran = "Main";
	}
	else if((*buttons)[1].getactivation() == 1)
	{
		*ecran = "override";
		for(int i = 0; i <= 15; i++)
			(*buttons)[i].settype("disabled");
		(*buttons)[0].settype("up_type");
		(*buttons)[11].settype("up_type");
	}
	else if((*buttons)[2].getactivation() == 1)
	{
		*ecran = "dataView";
		for(int i = 0; i <= 15; i++)
			(*buttons)[i].settype("disabled");
	}
	else if((*buttons)[3].getactivation() == 1)
		*ecran = "special";
	else if((*buttons)[4].getactivation() == 1)
		*ecran = "settings";
	else if ((*buttons)[5].getactivation() == 1)
    {
        if(data->getTunnelStoppingArea() == "TunnelStoppingArea" || data->getTunnelStoppingArea() == "TunnelStoppingAreaAnnouncement")
            data->setTunnelStoppingArea(data->getTunnelStoppingArea() + "-");
        else if (data->getTunnelStoppingArea() == "TunnelStoppingArea-" || data->getTunnelStoppingArea() == "TunnelStoppingAreaAnnouncement-")
            data->setTunnelStoppingArea(data->getTunnelStoppingArea().substr(0, data->getTunnelStoppingArea().size() - 1));
    }
	else if ((*buttons)[6].getactivation() == 1)
	{
		if(S_D_monitoring == "On")
			S_D_monitoring = "Off";
		else if (S_D_monitoring == "Off")
			S_D_monitoring = "On";
	}
	else if ((*buttons)[7].getactivation() == 1)
	{
		if(geographicalPosition == "On")
			geographicalPosition = "Off";
		else if (geographicalPosition == "Off")
			geographicalPosition = "On";
	}
	else if((*buttons)[8].getactivation() == 1)
	{
		if(planning.getScale() < 32000)
		planning.setScale(planning.getScale() * 2.0);
	}
	else if((*buttons)[9].getactivation() == 1)
	{
		if(planning.getScale() > 1000)
			planning.setScale(planning.getScale() / 2.0);
	}
	else if ((*buttons)[10].getactivation() == 1 && data->getVersion() == "3.4.0")
	{
		if(planningAffichage == "show planning information")
			planningAffichage = "Off";
		else if(planningAffichage == "Off")
			planningAffichage = "show planning information";
	}
	if(data->getTunnelStoppingArea() != "TunnelStoppingAreaUnknown")
    {
        if(data->getTunnelStoppingArea() == "TunnelStoppingArea")
        {
            (*symbol)[152].afficher(V2f(54 + 37 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));  //C2 - TC36
            creation_texte(to_string(data->getRemainingDistanceTunnel()), GREY, 12, 0, V2f(54 + 3 * 37 - 10, 54 + 30 + 191 + 25 + 50 / 2.0), 2);
        }
        else if(data->getTunnelStoppingArea() == "TunnelStoppingAreaAnnouncement")
        {
            (*symbol)[153].afficher(V2f(54 + 37 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));  //C2 - TC37
            creation_texte(to_string(data->getRemainingDistanceTunnel()), GREY, 12, 0, V2f(54 + 3 * 37 - 10, 54 + 30 + 191 + 25 + 50 / 2.0), 2);
        }
        (*symbol)[4].afficher(V2f(64 * 5 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0)); //F6 - DR05
    }
	if(geographicalPosition != "Unknown") //Geographical position
	{
		if(geographicalPosition == "On") //toggled on
		{
			rectangle(V2f(54 + 234 + 46 + 63, 54 + 30 + 191 + 25 + 50 + 50), V2f(120, 30), GREY);//G12
			creation_texte(to_string(data->getPointKilometrique()), BLACK, 12, 0, V2f(54 + 234 + 46 + 63 + 120 / 2.0, 54 + 30 + 191 + 25 + 50 + 50 + 30 / 2.0), 3);
		}
		(*symbol)[2].afficher(V2f(64 * 7 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0));	//F8 - DR03
	}
	if(planningAffichage != "Unknown")
	{
		if(data->getVersion() == "3.4.0")
		{
			(*symbol)[48].afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 / 2.0));		//H2 - NA02
			if(planningAffichage == "show planning information" && data->getGeneralMode() == "FS")
				planning.planningInformation(0);
		}
		if(data->getVersion() == "3.6.0" && (data->getGeneralMode() == "FS" || (data->getGeneralMode() == "OS" && S_D_monitoring == "On")))
		{
			planning.planningInformation(0);
		}
	}
}