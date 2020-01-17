#include "Data.hpp"
#include "Virtual_train.hpp"


int main()
{
	Virtual_train virtual_train;
	do
	{
		virtual_train.update();
	}while(virtual_train.soft.getEtat() == true);

	return 0;
}
