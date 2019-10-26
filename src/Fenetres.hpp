/*#ifndef fen
#define fen

#define DARK_BLUE Color(3,17,34)
#define SHADOW Color(8,24,57)
#define BLACK Color(0,0,0)
#define WHITE Color(255,255,255)
#define RED Color(191,0,2)
#define ORANGE Color(234,145,0)
#define YELLOW Color(223,223,0)
#define PASP_DARK Color(33,49,74)
#define PASP_LIGHT Color(41,74,107)
#define GREY Color(195,195,195)
#define MEDIUM_GREY Color(150,150,150)
#define DARK_GREY Color(85,85,85)

void MainWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string version, donnees & train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void specialWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void settingsWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<VBC> & vbc, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void SRspeedWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void dataViewWindows(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string title, int & numero, vector<Buttons> & boutons, string & ecran, vector<vector<string>> item, int * ecart);
void RBCdataWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void dataViewWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void systemVersionWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void dataEntryWindows(vector<vector<string>> input_field, RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, int complete, string title, vector<string> selection, int & sel, string keyboard, vector<Buttons> & boutons, string & ecran, donnees & train, int * ecart);
void menuWindows(vector <string> selection, vector <int>& enable, RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string title, int * ecart);
void overrideWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string version, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void adhesionWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void RBCcontactWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void ERTMS_ETCSlevelWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void trainRunningNumberWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void radionetworkIDWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void trainDataWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void brightnessWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void volumeWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void languageWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);
void windows(string & ecran, RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, string version, donnees &train, vector<VBC> vbc, vector<Buttons> & boutons, int & numero, int * ecart);
void close(string & ecran, vector<Buttons> & boutons, int & numero);
void driverIDWindow(RenderWindow & fenetre, double RE, vector<Symbol> & symbol, Font & arial, donnees &train, vector<Buttons> & boutons, string & ecran, int & numero, int * ecart);


class LeftSide
{
	protected :
		void targetDistance(int distance, RenderWindow & fenetre, double RE, Font & arial, int * ecart);
};


class Fenetre
{
	protected :
		Font arial;
		void creation_texte(double RE, string message, Font police, Color couleur, int taille, double OutlineThickness, V2f pos, RenderWindow & fenetre, int mode, int * ecart);
		void rectangle(V2f pos, V2f taille, Color col, double RE, RenderWindow & fenetre, int * ecart);
		void creation_rectangle(V2f pos, V2f dim, double RE, int mode, RenderWindow & fenetre, int * ecart);
		void couleurForme(VertexArray & bande,Color col, int n);
		void affichageBoutons(double RE, RenderWindow & fenetre, int * ecart);
};


class Main : public Fenetre, public LeftSide
{

};


class Menu : public Fenetre
{

};


class DataEntry : public Fenetre
{

};


class Special : public Menu
{

};


class Settings : public Menu
{

};


class SRspeed : public Menu
{

};


class DataView : public Menu
{

};


class SystemVersion : public Menu
{

};


#endif*/