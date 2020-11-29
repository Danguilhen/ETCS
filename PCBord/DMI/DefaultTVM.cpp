#include "DefaultTVM.hpp"

DefaultTVM::DefaultTVM(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, string & ecran, TVM_Bord &TVM): left(symbol, soft, bord, T_D), planning(symbol, soft, bord, T_D)
{
	//cout<< "DEF" <<endl;
	this->soft = &soft;
	this->symbol = &symbol;
	this->buttons = &buttons;
	this->bord = &bord;
	this->ecran = &ecran;
	this->TVM = &TVM;

}

void DefaultTVM::update()
{
	left.update();

	NA_13.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 3 + 64 / 2.0));	//H5
	NA_14.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 4 + 64 / 2.0));	//H6
	NA_17.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2 + 64 / 2.0));	//H4
	NA_18.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0));		//H3
	SE_04.afficher(V2f(64 * 4 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0));			//F5

	creation_rectangle(V2f((54 + 234 + 46), (54 + 30 + 191 + 25 + 50 + 50)), V2f(63, 30), 1);			//G11
	creation_rectangle(V2f((54 + 234 + 46 + 63), (54 + 30 + 191 + 25 + 50 + 50)), V2f(120, 30), 1);		//G12
	creation_rectangle(V2f((54 + 234 + 46 + 63 + 120), (54 + 30 + 191 + 25 + 2 * 50)), V2f(63, 30), 1);	//G13

	/*time_t rawtime = time(0);
	struct tm timeinfo;
	char buffer[80];

	localtime_s(&timeinfo, &rawtime);

	strftime(buffer, 80, "%H:%M:%S", &timeinfo);
	string date(buffer);
	std::puts(buffer);*/
	time_t curtime;
	time(&curtime);
	char buffer[80];
	ctime_s(buffer, 80, &curtime);
	string date(buffer);
	creation_texte(date.substr(10,9), GREY, 10, 0, V2f(54 + 280 + 63 + 120 + 63 / 2.0, 300 + 50 + 50 + 30 / 2.0), 1);
	creation_texte("Main", GREY, 16, 0, V2f(64 / 2.0, 300 + 4 * 25 + 30 + 50 / 2.0), 1);
	creation_texte("Over-", DARK_GREY, 16, 0, V2f(64 + 64 / 2.0, 300 + 4 * 25 + 30 + 50 / 2.0 - 10), 1);
	creation_texte("ride", DARK_GREY, 16, 0, V2f(64 + 64 / 2.0, 300 + 4 * 25 + 30 + 50 / 2.0 + 10), 1);
	creation_texte("Data", GREY, 16, 0, V2f(64 * 2 + 64 / 2.0, 300 + 4 * 25 + 30 + 50 / 2.0 - 10), 1);
	creation_texte("view", GREY, 16, 0, V2f(64 * 2 + 64 / 2.0, 300 + 4 * 25 + 30 + 50 / 2.0 + 10), 1);
	creation_texte("Spec", DARK_GREY, 16, 0, V2f(64 * 3 + 64 / 2.0, 300 + 4 * 25 + 30 + 50 / 2.0), 1);

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
	else if((*buttons)[2].getactivation() == 1)
	{
		*ecran = "dataView";
		for(int i = 0; i <= 15; i++)
			(*buttons)[i].settype("disabled");
	}
	else if((*buttons)[4].getactivation() == 1)
		*ecran = "Settings";
	/*else if ((*buttons)[5].getactivation() == 1)
    {
        if(bord->TrackRI.getTunnelStoppingArea() == "TunnelStoppingArea" || bord->TrackRI.getTunnelStoppingArea() == "TunnelStoppingAreaAnnouncement")
            bord->TrackRI.setTunnelStoppingArea(bord->TrackRI.getTunnelStoppingArea() + "-");
        else if (bord->TrackRI.getTunnelStoppingArea() == "TunnelStoppingArea-" || bord->TrackRI.getTunnelStoppingArea() == "TunnelStoppingAreaAnnouncement-")
            bord->TrackRI.setTunnelStoppingArea(bord->TrackRI.getTunnelStoppingArea().substr(0, bord->TrackRI.getTunnelStoppingArea().size() - 1));
    }*/
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
		planning.setScale(planning.getScale() * 2);
	}
	else if((*buttons)[9].getactivation() == 1)
	{
		if(planning.getScale() > 1000)
			planning.setScale(static_cast<int>(planning.getScale() / 2));
		//Scale int avec un float ?
	}
	else if ((*buttons)[10].getactivation() == 1 && bord->getVersion() == "3.4.0")
	{
		if(planningAffichage == "show planning information")
			planningAffichage = "Off";
		else if(planningAffichage == "Off")
			planningAffichage = "show planning information";
	}
	/*if(bord->TrackRI.getTunnelStoppingArea() != "TunnelStoppingAreaUnknown")
    {
        if(bord->TrackRI.getTunnelStoppingArea() == "TunnelStoppingArea")
        {
            (*symbol)[152].afficher(V2f(54 + 37 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));  //C2 - TC36
            creation_texte(to_string(bord->TrackRI.getRemainingDistanceTunnel()), GREY, 12, 0, V2f(54 + 3 * 37 - 10, 54 + 30 + 191 + 25 + 50 / 2.0), 2);
        }
        else if(bord->TrackRI.getTunnelStoppingArea() == "TunnelStoppingAreaAnnouncement")
        {
            (*symbol)[153].afficher(V2f(54 + 37 / 2.0, 54 + 30 + 191 + 25 + 50 / 2.0));  //C2 - TC37
            creation_texte(to_string(bord->TrackRI.getRemainingDistanceTunnel()), GREY, 12, 0, V2f(54 + 3 * 37 - 10, 54 + 30 + 191 + 25 + 50 / 2.0), 2);
        }
        (*symbol)[4].afficher(V2f(64 * 5 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0)); //F6 - DR05
    }*/
	if(geographicalPosition != "Unknown") //Geographical position
	{
		if(geographicalPosition == "On") //toggled on
		{
			rectangle(V2f(54 + 234 + 46 + 63, 54 + 30 + 191 + 25 + 50 + 50), V2f(120, 30), GREY);//G12
			creation_texte(to_string(bord->TrackRI.getPointKilometrique()), BLACK, 12, 0, V2f(54 + 234 + 46 + 63 + 120 / 2.0, 54 + 30 + 191 + 25 + 50 + 50 + 30 / 2.0), 3);
		}
		(*symbol)[2].afficher(V2f(64 * 7 + 64 / 2.0, 54 + 30 + 191 + 5 * 25 + 30 + 50 / 2.0));	//F8 - DR03
	}
	if(planningAffichage != "Unknown")
	{
		if(bord->getVersion() == "3.4.0")
		{
			(*symbol)[48].afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 / 2.0));		//H2 - NA02
			if(planningAffichage == "show planning information" && bord->getGeneralMode() == "FS")
				planning.planningInformation();
		}
		if(bord->getVersion() == "3.6.0" && (bord->getGeneralMode() == "FS" || (bord->getGeneralMode() == "OS" && S_D_monitoring == "On")))
		{
			planning.planningInformation();
		}
	}

	// affichage TVM

	indication = TVM->getIndication();
	if (indication.at(3) == 'R') {
		creation_rectangle(V2f((54 + 3 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 5);
		creation_rectangle(V2f((54 + 1 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 5);
		creation_rectangle(V2f((54 + 5 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 5);
	}

	else if (indication.at(3) == 'V') {
		creation_rectangle(V2f((54 + 3 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 6);
		creation_rectangle(V2f((54 + 1 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 6);
		creation_rectangle(V2f((54 + 5 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 6);
	}

	else if (indication.at(3) == 'C' && clockTVM.getElapsedTime()>periodeClignotement/floatdeux) {
		creation_rectangle(V2f((54 + 3 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 6);
		creation_rectangle(V2f((54 + 1 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 6);
		creation_rectangle(V2f((54 + 5 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 6);
	}

	else if (indication.at(3) == 'E') {
		creation_rectangle(V2f((54 + 3 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 7);
		creation_rectangle(V2f((54 + 1 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 7);
		creation_rectangle(V2f((54 + 5 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 7);
	}

	else if (indication.at(3) == 'A') {
		creation_rectangle(V2f((54 + 3 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 8);
		creation_rectangle(V2f((54 + 1 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 8);
		creation_rectangle(V2f((54 + 5 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 8);
	}

	
	if (indication.at(0) == '3' && indication.at(1) == '0' && indication.at(2) == '0' && indication.at(3) == 'V') {
		creation_texte("3", WHITE, 48, 6, V2f(54 + 1 * 37+29, 54 + 30 + 191 + 25+25), 1);
		creation_texte("0", WHITE, 48, 6, V2f(54 + 3 * 37+29, 54 + 30 + 191 + 25+25), 1);
		creation_texte("0", WHITE, 48, 6, V2f(54 + 5 * 37+29, 54 + 30 + 191 + 25+25), 1);
	}
	else if (indication.at(0) == '3' && indication.at(1) == '0' && indication.at(2) == '0' && indication.at(3) == 'C' && clockTVM.getElapsedTime() > periodeClignotement / floatdeux) {
		creation_texte("3", WHITE, 48, 6, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("0", WHITE, 48, 6, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("0", WHITE, 48, 6, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
	}
	else if (indication.at(0) == '2' && indication.at(1) == '7' && indication.at(2) == '0' && indication.at(3) == 'V') {
		creation_texte("2", WHITE, 48, 6, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("7", WHITE, 48, 6, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("0", WHITE, 48, 6, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
	}
	else if (indication.at(0) == '2' && indication.at(1) == '7' && indication.at(2) == '0' && indication.at(3) == 'C' && clockTVM.getElapsedTime() > periodeClignotement / floatdeux) {
		creation_texte("2", WHITE, 48, 6, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("7", WHITE, 48, 6, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("0", WHITE, 48, 6, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
	}
	else if (indication.at(0) == '2' && indication.at(1) == '7' && indication.at(2) == '0' && indication.at(3) == 'A') {
		creation_texte("2", BLACK, 48, 6, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("7", BLACK, 48, 6, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("0", BLACK, 48, 6, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
	}
	else if (indication.at(0) == '2' && indication.at(1) == '2' && indication.at(2) == '0' && indication.at(3) == 'E') {
		creation_texte("2", WHITE, 48, 6, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("2", WHITE, 48, 6, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("0", WHITE, 48, 6, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
	}
	else if (indication.at(0) == '2' && indication.at(1) == '2' && indication.at(2) == '0' && indication.at(3) == 'A') {
		creation_texte("2", BLACK, 48, 6, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("2", BLACK, 48, 6, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("0", BLACK, 48, 6, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
	}
	else if (indication.at(0) == '1' && indication.at(1) == '6' && indication.at(2) == '0' && indication.at(3) == 'E') {
		creation_texte("1", WHITE, 48, 6, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("6", WHITE, 48, 6, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("0", WHITE, 48, 6, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
	}
	else if (indication.at(0) == '1' && indication.at(1) == '6' && indication.at(2) == '0' && indication.at(3) == 'A') {
		creation_texte("1", BLACK, 48, 6, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("6", BLACK, 48, 6, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("0", BLACK, 48, 6, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
	}
	else if (indication.at(0) == '0' && indication.at(1) == '8' && indication.at(2) == '0' && indication.at(3) == 'E') {
		creation_texte("0", WHITE, 48, 6, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("8", WHITE, 48, 6, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("0", WHITE, 48, 6, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
	}
	else if (indication.at(0) == '0' && indication.at(1) == '8' && indication.at(2) == '0' && indication.at(3) == 'A') {
		creation_texte("0", BLACK, 48, 6, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("8", BLACK, 48, 6, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("0", BLACK, 48, 6, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
	}
	else if (indication.at(0) == '0' && indication.at(1) == '0' && indication.at(2) == '0') {
		creation_texte("0", WHITE, 48, 6, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("0", WHITE, 48, 6, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
		creation_texte("0", WHITE, 48, 6, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
	}

	if (clockTVM.getElapsedTime() > periodeClignotement)
		clockTVM.restart();

	sect = TVM->getSect();
	if (sect == 1)
		Sect.afficher(V2f(54 + 140 + 36, 274));			//F5
	bp = TVM->getBp();
	if (bp == 1)
		BP.afficher(V2f(54 + 140 - 36, 274));			//F5
}