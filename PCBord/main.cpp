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
/*
	cout << "start" << endl;
	SocketSendInit();
	cout << "then" << endl;
	while (true)
	{
		update();
	}*/
    return 0;
}

/*
void SocketSendInit()
{
	cout << "debut" << endl;
	if (sock.connect("192.168.0.105", 52001) != sf::Socket::Done)
	{
	    cout << "error_connection" << endl;
	}
	cout << "connecte" << endl;
	const 
	sendbuf = "a";
	char recvbuf[4096];
	if (sock.send(sendbuf, strlen(sendbuf)) != sf::Socket::Done)
	{
		cout << "error_send_a" << endl;
	}
	if (sock.receive(recvbuf, 4096, received) != sf::Socket::Done)
	{
	    cout << "error_receive_a" << endl;
	}
	string sent1 = "?0 0 0 0 0 0 0 0 0 0 0 0 ";
	if (sock.send(sent1.c_str(), strlen(sent1.c_str())) != sf::Socket::Done)
	{
	    cout << "error_send_init" << endl;
	}
}

void SocketUpdate()
{
	cout << "next" << endl;
	char bf[1024];
	memset(bf, 0, sizeof(bf));
	int zero = 0;
	if (sock.receive(bf, sizeof(bf), received) != sf::Socket::Done)
	{
	    cout << "error_receive" << endl;
	}
	string string_sent = "?" + to_string(zero) + " " + to_string(zero) + " " + to_string(zero) + " "  + to_string(zero) + " " + to_string(zero) + " " + to_string(zero) + " "+ to_string(zero) + " " + to_string(zero) + " "  + to_string(zero) + " "  + to_string(zero) + " "  + to_string(zero) + " " + to_string(zero) + " " + to_string(zero) + " " + to_string(zero) + " ";
	if (sock.send(string_sent.c_str(), strlen(string_sent.c_str())) != sf::Socket::Done)
	{
	    cout << "error_send" << endl;
	}
}*/