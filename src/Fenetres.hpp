#ifndef fen
#define fen



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





#endif