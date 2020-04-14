/*#include "Dataview.hpp"

Dataview::Dataview(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, string &ecran) : left(symbol, soft, bord, T_D)
{
	this->soft = &soft;
	this->bord = &bord;
	this->symbol = &symbol;
	this->buttons = &buttons;
	this->ecran = &ecran;
}

void Dataview::update(std::string title)
{
	vector<vector<string>> item;
	left.update();
	if (title == "DataViewWindow")
	{
    if(page == 1)
    	item = {{"Driver ID", to_string(bord->TrainRI.T_data.getDriverID())}, {"", ""},{"Train running number", to_string(bord->TrainRI.T_data.getTrainRunningNumber()) },
			{"", ""}, {"Train type", bord->TrainRI.T_data.getTrain_type()}, {"Train category", bord->TrainRI.T_data.getTrain_category()}, {"Length (m)", to_string(bord->TrainRI.T_data.getTrain_length())},
			{"Brake percentage", to_string(bord->TrainRI.T_data.getbreaking_percetage())}, {"Max speed (km/h)", to_string(bord->TrainRI.T_data.getmaximum_train_speed())},
			{"Axle load category", bord->TrainRI.T_data.getaxle_load_category()}, {"Airtight", bord->TrainRI.T_data.getAirtight()}, {"Loading gauge", bord->TrainRI.T_data.getloading_gauge()}};
    else
    	item = {{"Radio network ID", bord->TrainRI.T_data.getRadioNetworkID()}, {"RBC ID", to_string(bord->TrainRI.T_data.getRBCID())}, {"RBC phone number", to_string(bord->TrainRI.T_data.getRBCphoneNumber())}, {"", ""},
		{"VBC #1 set code", "d"}, {"VBC #2 set code", "e"}};
	}
	if(title == "systemVersionWindow")
	{
		item = {{"Operated system version", ""}};
	}

	rectangle(V2f(54 + 280, 0), V2f(266, 24), BLACK);
	if(title == "Data View")
		title += " (" + to_string(page) + "/2)";
	creation_texte(title, GREY, 17, 0, V2f(54 + 280 + 3, 12), 4);
	for(int i = 0; i <= int(item.size()) - 1; i++)
	{
		creation_texte(item[i][0], GREY, 17, 0, V2f(280 + 54 + 176 - 5, 60 + 17 / 2.0 + i * 22), 2);
		creation_texte(item[i][1], GREY, 17, 0, V2f(280 + 54 + 176 + 5, 60 + 17 / 2.0 + i * 22), 4);
	}
	if(page == 1)
	{
		NA_11.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0));		//H3
		*(buttons)[11].settype("up_type");
		close();
	}
	else if(page == 2)
	{
		NA_18.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0));		//H3
		*(buttons)[11].settype("up_type");
		if(*(buttons)[11].getactivation())
			page--;
	}
	if(page == 2)
	{
		NA_18_2.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2+ 64 / 2.0));	//H4
		*(buttons)[12].settype("disabled");
	}
	else if(page == 1)
	{
		*(buttons)[12].settype("up_type");
		NA_17.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2+ 64 / 2.0));	//H4
		if(*(buttons)[12].getactivation())
			page++;
	}
}*/