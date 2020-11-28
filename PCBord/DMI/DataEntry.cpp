#include "DataEntry.hpp"

DataEntry::DataEntry(vector<Symbol> &symbol, vector<Button> &buttons, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D, string &ecran): left(symbol, soft, bord, T_D)
{
	this->soft = &soft;
	this->bord = &bord;
	this->symbol = &symbol;
	this->buttons = &buttons;
	this->T_D = &T_D;
	this->ecran = &ecran;
}

void DataEntry::dataEntry(vector<vector<string>> input_field, int complete, string title, vector<string> selection, string keyboard)
{
	left.update();
	for(int i = 0; i <= 9; i++)
		(*buttons)[i].settype("up_type");
	if(keyboard == "numeric")
	{
		NA_21.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 / 2.0));			//H2
		(*buttons)[10].settype("up_type");
		for(int i = 1; i <= 10; i++)
			creation_texte(to_string(i % 10), GREY, 16, 0, V2f(- (float)64 / 2.0f + i * 64, 430 + (float)50 / 2.0f), 1);
	}
	else if(keyboard == "enhanced numeric")
	{
		NA_21.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 / 2.0));			//H2
		creation_texte("1.  ", GREY, 16, 0, V2f(- 64 / 2.0 + 1 * 64, 430 + 50 / 2.0), 3);
		for(int i = 2; i <= 10; i++)
			creation_texte(to_string(i % 10), GREY, 16, 0, V2f(- (float)64 / 2.0f + i * 64, 430 + (float)50 / 2.0f), 1);
	}
	else if(keyboard == "alphanumeric")
	{
		NA_21.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 / 2.0));			//H2
		creation_texte("1", GREY, 16, 0, V2f(- 64 / 2.0 + 1 * 64, 430 + 50 / 2.0), 1);
		creation_texte("2abc", GREY, 16, 0, V2f(- 64 / 2.0 + 2 * 64, 430 + 50 / 2.0), 3);
		creation_texte("3def", GREY, 16, 0, V2f(- 64 / 2.0 + 3 * 64, 430 + 50 / 2.0), 3);
		creation_texte("4hij", GREY, 16, 0, V2f(- 64 / 2.0 + 4 * 64, 430 + 50 / 2.0), 3);
		creation_texte("5klm", GREY, 16, 0, V2f(- 64 / 2.0 + 5 * 64, 430 + 50 / 2.0), 3);
		creation_texte("6nop", GREY, 16, 0, V2f(- 64 / 2.0 + 6 * 64, 430 + 50 / 2.0), 3);
		creation_texte("7qrs", GREY, 16, 0, V2f(- 64 / 2.0 + 7 * 64, 430 + 50 / 2.0), 3);
		creation_texte("8tuv", GREY, 16, 0, V2f(- 64 / 2.0 + 8 * 64, 430 + 50 / 2.0), 3);
		creation_texte("9wxyz", GREY, 16, 0, V2f(- 64 / 2.0 + 9 * 64, 430 + 50 / 2.0), 3);
		creation_texte("0", GREY, 16, 0, V2f(- 64 / 2.0 + 10 * 64, 430 + 50 / 2.0), 1);
	}
	else if(keyboard == "dedicated keyboard")
    {
        for(int i = 1; i <= (int)selection.size(); i++)
            creation_texte(to_string(i % 10), GREY, 16, 0, V2f(- (float)64 / 2.0f + i * 64, 430 + (float)50 / 2.0f), 1);
        if(selection.size() >= 10)
            (*buttons)[9].settype("up_type");
    }
	if((*buttons)[14].getactivation())
		sel = sel % input_field.size() + 1;
	else if((*buttons)[13].getactivation())
	{
		if(sel != 1)
			sel--;
		else
			sel = input_field.size();
	}
	int numero = sel;
	string sequenceNumber;
	Color color;
	if(complete == 1 && input_field.size() > 4)
		sequenceNumber = string(" (") + to_string((int)ceil(numero / 4.0)) + "/" + to_string((int)ceil(input_field.size() / 4.0)) + ")";
	else if(complete == 0 && input_field.size() > 3)
		sequenceNumber = string(" (") + to_string((int)ceil(numero / 3.0)) + "/" + to_string((int)ceil(input_field.size() / 3.0)) + ")";
	if(((int)ceil(numero / 4.0) < 2 && complete == 1) || ((int)ceil(numero / 3.0) < 2 && complete == 0))
	{
		NA_11.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0));		//H3
		(*buttons)[11].settype("up_type");
	}
	else
	{
		NA_18.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 + 64 / 2.0));		//H3
		(*buttons)[11].settype("up_type");
		if((*buttons)[11].getactivation())
		{
			while(sel % 4 != 0)
				sel--;
			sel = sel - 3;
		}
	}
	if((((complete == 1 && input_field.size() > 4 && (int)ceil(numero / 4.0) == (int)ceil(input_field.size() / 4.0)) || (complete == 0 && input_field.size() > 3 &&
		(int)ceil(numero / 3.0) == (int)ceil(input_field.size() / 3.0)))))
	{
		NA_18_2.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2+ 64 / 2.0));	//H4
		(*buttons)[12].settype("disabled");
	}
	else if((complete == 1 && input_field.size() > 4) || (complete == 0 && input_field.size() > 3))
	{
		(*buttons)[12].settype("up_type");
		NA_17.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 2+ 64 / 2.0));	//H4
		if((*buttons)[12].getactivation())
		{
			while(sel % 4 != 0)
				sel++;
			sel++;
		}
	}
	if(input_field.size() > 1)
	{
		NA_14.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 4 + 64 / 2.0));	//H6
		NA_13.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 3 + 64 / 2.0));	//H5
	}
	NA_20.afficher(V2f(54 + 280 + 40 + 166 + 40 + 20 + 40 / 2.0, 28 + 64 * 5 + 41));			//H7
	if(complete)
	{
		rectangle(V2f(0, 380), V2f(334, 50), DARK_GREY);
		rectangle(V2f(0, 380), V2f(334 - 1, 50 - 1), WHITE);
		rectangle(V2f(0 + 1, 380 + 1), V2f(334 - 2, 50 - 2), MEDIUM_GREY);
		creation_texte("Yes", BLACK, 12, 0, V2f(334 / 2.0, 380 + 25), 1);
		creation_texte(title + " entry complete ?", GREY, 12, 0, V2f(334 / 2.0, 330 + 25), 1);
		rectangle(V2f(0, 0), V2f(334, 24), BLACK);
		creation_texte(title + sequenceNumber, GREY, 12, 0, V2f(54 + 280 - 3, 12), 2);
	}
	else
	{
		rectangle(V2f(54 + 280, 0), V2f(266, 24), BLACK);
		creation_texte(title, GREY, 12, 0, V2f(54 + 280 + 3, 12), 4);
	}
	if(input_field.size() == 1)
	{
		rectangle(V2f(54 + 280, 50), V2f(266, 50), DARK_GREY);
		rectangle(V2f(54 + 280, 50), V2f(266 - 1, 50 - 1), WHITE);
		rectangle(V2f(54 + 280 + 1, 50 + 1), V2f(266 - 2, 50 - 2), MEDIUM_GREY);
		if (input_field[0][1]!="")
		  creation_texte(input_field[0][1], BLACK, 12, 0, V2f(54 + 280 + 10, 25 + 50), 4);
	}
	else
	{
		if(complete)
		{
			if(numero % 4)
				numero = numero - numero % 4;
			else
				numero = numero - 4;
		}
		else
			numero = numero - numero % 3;
		for(int i = numero; i <= min((int)input_field.size() - 1, 3 + numero); i++)
		{
			rectangle(V2f(static_cast<float>(54 + 280), static_cast<float>(50 * (i - numero) + 50 * (1 - complete))), V2f((float)164, (float)50), MEDIUM_GREY);
			rectangle(V2f(static_cast<float>(54 + 280 + 1), static_cast<float>(50 * (i - numero) + 1 + 50 * (1 - complete))), V2f(static_cast<float>(164 - 2), static_cast<float>(50 - 2)), BLACK);
			rectangle(V2f(static_cast<float>(54 + 280 + 1), static_cast<float>(1 + 50 * (i - numero) + 50 * (1 - complete))), V2f(static_cast<float>(164 - 2), static_cast<float>(50 - 2)), DARK_GREY);
			if(i == sel - 1)
			{
				rectangle(V2f(static_cast<float>(54 + 280 + 164), static_cast<float>(50 * (i - numero) + 50 * (1 - complete))), V2f((float)102, (float)50), DARK_GREY);
				rectangle(V2f(static_cast<float>(54 + 280 + 164), static_cast<float>(50 * (i - numero) + 50 * (1 - complete))), V2f(static_cast<float>(102 - 1), static_cast<float>(50 - 1)), WHITE);
				rectangle(V2f(static_cast<float>(54 + 280 + 164 + 1), static_cast<float>(50 * (i - numero) + 1 + 50 * (1 - complete))), V2f(static_cast<float>(102 - 2), static_cast<float>(50 - 2)), MEDIUM_GREY);
			}
			else
			{
				rectangle(V2f(static_cast<float>(54 + 280 + 164), static_cast<float>(50 * (i - numero) + 50 * (1 - complete))), V2f((float)102, (float)50), MEDIUM_GREY);
				rectangle(V2f(static_cast<float>(54 + 280 + 164 + 1), static_cast<float>(50 * (i - numero) + 1 + 50 * (1 - complete))), V2f(static_cast<float>(102 - 2), static_cast<float>(50 - 2)), BLACK);
				rectangle(V2f(static_cast<float>(54 + 280 + 164 + 1), static_cast<float>(1 + 50 * (i - numero) + 50 * (1 - complete))), V2f(static_cast<float>(102 - 2), static_cast<float>(50 - 2)), DARK_GREY);
			}
			creation_texte(input_field[i][0], GREY, 12, 0.0f, V2f(static_cast<float>(54 + 280 + 10), static_cast<float>(50 * (i - numero) + 25 + 50 * (1 - complete))), 4);
			if(i == sel - 1)
			{
				cout << clignotement << endl;
				if(clignotement / 30 <= 1.0)
				{
					creation_texte(input_field[i][1], BLACK, 12, 0.0f, V2f(static_cast<float>(54 + 280 + 164 + 10), static_cast<float>(50 * (i - numero) + 25 + 50 * (1 - complete))), 4);
					clignotement++;
				}
				else if (clignotement/30 <= 2.0)
				{
					creation_texte(input_field[i][1] + "_", BLACK, 12, 0.0f, V2f(static_cast<float>(54 + 280 + 164 + 10), static_cast<float>(50 * (i - numero) + 25 + 50 * (1 - complete))), 4);
					clignotement++;
				}
				else
					clignotement = 0.0;
			}
			else if(input_field[i][2] == "1")
				creation_texte(input_field[i][1], WHITE, 12, 0.0f, V2f(static_cast<float>(54 + 280 + 164 + 10), static_cast<float>(50 * (i - numero) + 25 + 50 * (1 - complete))), 4);
			else
				creation_texte(input_field[i][1], GREY, 12, 0.0f, V2f(static_cast<float>(54 + 280 + 164 + 10), static_cast<float>(50 * (i - numero) + 25 + 50 * (1 - complete))), 4);
		}
	}
	for(int i = 0; i < (int)selection.size(); i++)
		creation_texte(to_string(i + 1) + " - " + selection[i], GREY, 12, 0.0f, V2f(static_cast<float>(54 + 280 + 15), static_cast<float>(200 + 15 + 6 + i * 20)), 4);

}