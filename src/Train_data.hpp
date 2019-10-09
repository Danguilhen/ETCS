#ifndef DEF_TRAIN
#define DEF_TRAIN

#include <string>

class Train_data

{
    private:
		string category;
    	int length;
		int maxSpeed;
		int loadingGauge;
		string axleLoadCategory;
		string nationalSystems[];
		int axleNumber;

    	float T_traction_cut_off;
    	vector<vector<float>> & ADN;

    public:
    	Train_data();
    	float A_Brake(int V);
};

#endif