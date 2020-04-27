
#include "Virtual_train.hpp"
#include "PCC.hpp"


int main()
{
	sf::Context cont;
	Software soft;
	Virtual_train virtual_train(soft);
	//PCC pcc(soft, virtual_train.train_dynamique);
	do
	{
		soft.software_update();
		virtual_train.update();
		//pcc.update();
	}while(soft.getEtat() == true);

	cout << "end" ;
	return 0;
}
