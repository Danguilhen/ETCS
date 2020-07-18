
#include "Virtual_train.hpp"
#include "PCC.hpp"
#include "Sol.hpp"

int main()
{
	sf::Context cont;
	Software soft;
	Virtual_train virtual_train(soft);
	//Sol sol(virtual_train);
	//PCC pcc(soft, virtual_train.train_dynamique);
	do
	{
		soft.software_update();
		virtual_train.update();
		//sol.gestion_CDV();
		//pcc.update();
	}while(soft.getEtat() == true);

	cout << "end" ;
	return 0;
}
