#include "Data.hpp"

Data::Data()
{
	if(VideoMode::getDesktopMode().width / 640.0 < VideoMode::getDesktopMode().height / 480.0)
		RE = VideoMode::getDesktopMode().width / 640.0;	//rapport Ecran
	else
		RE = VideoMode::getDesktopMode().height / 480.0; //rapport Ecran
}

void Data::update()
{
/*	//Création du message envoyé au serveur
    char buf[4096];

	SocketSend(buf);

	int counter = 1;
	string info;
	for(int i = 0; i < 5; i++)
	{
    	while(buf[counter] != '!')
		{
    		info += buf[counter];
    		counter += 1;
    	}
	}
	istringstream iss(info);
	vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());

	Vligne = stoi(results[0]);
	Vtrain = stoi(results[1]);
	V_red = stof(results[2]);
	V_orange = stof(results[3]);
	V_yellow = stof(results[4]);
	V_white = stof(results[5]);
	V_medium_grey = stof(results[6]);
	V_dark_grey = stof(results[7]);
	string generalMode = results[8];
	string mode = results[9];
	string status = results[10];
	string level = results[11];
	Color aiguille;*/
}

// Fonction de connexion du client au serveur
// Serveur : RPI2; Client = RPI1
/*void Data::SocketSend(char buf[])
{
	//Création du socket
  	//Si le socket n'est pas créé, sock=-1, sortie de fonction
  	if(sock == -1)
	{
		sock = socket(AF_INET, SOCK_STREAM,0);
  		return;
	}
    socketValue = 1;

  	//Choix du port et de l'IP
  	int port = 54000;
  	string ipAddress = "192.168.1.90";

  	sockaddr_in hint;
  	hint.sin_family = AF_INET;
  	hint.sin_port = htons(port);
  	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

  	//Début de la connexion au serveur, lorsqu'elle est établie on sort de la boucle
    socketValue = 2;
	int connectRes;
    do
    {
        connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
    } while(connectRes == -1);

  	socketValue = 3;
  	do
	{
    	//send to server
    	int sendRes = send(sock, buf, strlen(buf),0);

    	//on vérifie si le message a été envoyé
    	if(sendRes == -1)
    		continue;

    	socketValue = 4;

    	// On nettoie le tableau envoyé qui va servir maintenant à recevoir la réponse du serveur
    	memset(buf, 0, 4096);
    	int bytesReceived = -1;
    	bytesReceived = recv(sock, buf, 4096, 0);
    	if(bytesReceived == -1 || bytesReceived == NULL)
		{
    	    cout << "";
    	    socketValue = 5;
    	}
    	else //On sort de la boucle : la connexion est établie
		{
    	    socketValue = 6;
    	    break;
    	}
  	} while(true);
}*/

int Data::getVtrain(){return Vtrain;}
string Data::getGeneralMode(){return generalMode;}
string Data::getLevel(){return level;}
double Data::getRE(){return RE;}
int Data::getEcartX(){return ecartX;}
int Data::getEcartY(){return ecartY;}
void Data::setSon(int a){son = a;}
int Data::getVligne(){return Vligne;}
string Data::getVersion(){return version;}
int Data::getPointKilometrique(){return pointKilometrique;}
int Data::getRemainingDistanceTunnel(){return remainingDistanceTunnel;}
string Data::getTunnelStoppingArea(){return tunnelStoppingArea;}
void Data::setTunnelStoppingArea(string TSA){tunnelStoppingArea = TSA;}
int Data::getSignalisation(){return signalisation;}
bool Data::getEteindre(){return eteindre;}
void Data::setEteindre(bool stop){eteindre = stop;}
bool Data::getAllumage(){return allumage;}