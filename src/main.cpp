#include "Data.hpp"
#include "Virtual_train.hpp"


int main()
{
	Data data;
	Virtual_train virtual_train(data);
	while(!data.getEteindre())
	{
		data.update();
		if(data.getAllumage())
			virtual_train.update();
	}
	return 0;
}
