#include "TVM_Bord.hpp"

TVM_Bord::TVM_Bord(Reseau &Res)
{
	this->Res = &Res;
}

void TVM_Bord::update() {
	mainFrequency = Res->getMainFrequency();
	secondaryFrequency = Res->getSecondFrequency();
	selfTimer = Res->getSelfTimer();
	side = Res->getSideFrequency();

	mainFrequency = 13.6;

	if (mainFrequency == 11.4)
		indication = "300V";
	else if (mainFrequency == 13.6)
		indication = "300C";
	else if (mainFrequency == 10.3)
		indication = "270V";
	else if (mainFrequency == 12.5)
		indication = "270C";
	else if (mainFrequency == 16.9)
		indication = "270A";
	else if (mainFrequency == 14.7)
		indication = "220A";
	else if (mainFrequency == 15.8)
		indication = "220E";
	else if (mainFrequency == 18)
		indication = "160A";
	else if (mainFrequency == 19.1)
		indication = "160E";
	else if (mainFrequency == 20.2)
		indication = "080A";
	else if (mainFrequency == 22.4)
		indication = "220E";
	else if (mainFrequency == 24.6)
		indication = "000R";
	else if (mainFrequency == 29)
		indication = "RRRR";

	secondaryFrequency = 1318;
	//cout << indication << endl;
	if (side == 1700 || side == 2300)
		side = 1;
	else if (side == 2000 || side == 2600)
		side = 2;
	else
		side = 0;

	if (secondaryFrequency == 1318)
		sect = 1;
	else if (secondaryFrequency == 1319)
		sect = 0;
		
	if (secondaryFrequency == 1459)
		sortieTunnel = 1;
	else if (secondaryFrequency == 1460)
		sortieTunnel = 0;

	if (secondaryFrequency == 1600)
		commutation = 1;
	else if (secondaryFrequency == 1601)
		commutation = 0;

	if (secondaryFrequency == 1882)
		carre = 1;
	else if (secondaryFrequency == 1883)
		carre = 0;

	if (secondaryFrequency == 2163)
		armdv2 = 1;
	else if (secondaryFrequency == 2164)
		armdv2 = 0;

	if (secondaryFrequency == 2726)
		armdv1 = 1;
	else if (secondaryFrequency == 2727)
		armdv1 = 0;

	if (secondaryFrequency == 2867)
		desv2 = 1;
	else if (secondaryFrequency == 2868)
		desv2 = 0;

	if (secondaryFrequency == 3008)
		desv1 = 1;
	else if (secondaryFrequency == 3009)
		desv1 = 0;

	if (secondaryFrequency == 3148)
		testAD = 1;
	else if (secondaryFrequency == 3149)
		testAD = 0;

	if (secondaryFrequency == 3290)
		armv2 = 1;
	else if (secondaryFrequency == 3291)
		armv2 = 0;

	if (secondaryFrequency == 3430)
		armv1 = 1;
	else if (secondaryFrequency == 3431)
		armv1 = 0;

	if (secondaryFrequency == 3571)
		kv65 = 1;
	else if (secondaryFrequency == 3572)
		kv65 = 0;

	if (secondaryFrequency == 3725)
		bp = 1;
	else if (secondaryFrequency == 3726)
		bp = 0;

	if (secondaryFrequency == 3840)
		entree = 1;
	else if (secondaryFrequency == 3841)
		entree = 0;
}

//get indication pour ecran

string TVM_Bord::getIndication() { 
	return indication;  
}
bool TVM_Bord::getSect() {
	return sect;
}
bool TVM_Bord::getBp() {
	return bp;
}