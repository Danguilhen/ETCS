#include "Statique.hpp"
#include "Dynamique.hpp"
#include "ETCS_bord.hpp"
#include "KVB.hpp"
#include "TVM.hpp"

class Data
{
	private :
	public :
		void update();
};

//DMI ------------------------------------------------------------------------------------------------------------------------------------

class Train
{
	private :
		Data *data;
		ETCS_bord bord{data};
		Dynamique dynamique;
		Statique statique;
		KVB kvb;
		TVM tvm;
	public :
		Train(Data &data);
		void update();
};

Train::Train(Data &data)
{
	this->data = &data;
}

void Train::update()
{
	data->update();
	bord.update();
	dynamique.update();
	statique.update();
}

//Main -----------------------------------------------------------------------------------------------------------------------------------
int main()
{
	Data data;
	Train virtuel{data};
	virtuel.update();
	return 0;
}