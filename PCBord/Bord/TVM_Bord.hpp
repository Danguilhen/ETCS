#ifndef TV
#define TV
#include "../Reseau.hpp"
#include "../define.hpp"

class TVM_Bord
{
	protected:
		Reseau *Res;
		double mainFrequency;
		double secondaryFrequency;
		double selfTimer;
		double punctualEmitterFrequency;
		string indication;
		int side;
		bool sect = 0;
		bool sortieTunnel = 0;
		bool commutation = 0;
		bool carre = 0;
		bool armdv2 = 0;
		bool armdv1 = 0;
		bool desv2 = 0;
		bool desv1 = 0;
		bool testAD = 0;
		bool armv2 = 0;
		bool armv1 = 0;
		bool kv65 = 0;
		bool bp = 0;
		bool entree = 0;

	public:
		TVM_Bord(Reseau &Res);
		void update();
		string getIndication();
		bool getSect();
		bool getBp();
};

#endif