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
		int signalisation;
		Data data;
		ETCS_BORD bord{data};
		Dynamique dynamique;
		Statique statique;
	public :
		Train();
		void update();
};

Train::Train()
{

}

void Train::update()
{
	data.update();
	bord.update();
	dynamique.update();
	statique.update();
}

//Main -----------------------------------------------------------------------------------------------------------------------------------
int main()
{
	Train virtuel;
	virtuel.update();
	return 0;
}