#ifndef beno
#define beno

#include "define.hpp"
#include "Reseau.hpp"

struct Chrono

{

    sf::Clock chrono;

    sf::Time time;

    double time_second;
    short int etatChrono;

};

class Train_statique
{
    private :
        Reseau *res;
        int etat_projecteurs;
        int etat_disj;
        bool etat_sablage;
        struct Chrono chrono_sablage;
        bool etat_acquitt;
        int etat_essui_glace;
        bool etat_lave_glace;
        int etat_light_cabine;
        int etat_light_pupitre;
        int etat_sifflet;
        bool etat_LS_SF;
        bool etat_BP_SF;
        int signalisation;
        double etat_VI;
        int direction;
        int etat_conduct_mod;
        double etat_tract_frein;
        int etat_porte;
        bool etat_panto;
        struct Chrono chrono_panto;
        bool etat_VA;
        bool etat_cle_BL;
        bool etat_ventilation;
        int etat_GROG;
        struct Chrono chrono_GROG;
        bool etat_TVM_V1;
        bool etat_TVM_V2;
        bool etat_alarme;

    public :
        Train_statique(Reseau &res);
        void update();
        void set_projecteurs();
        void set_disj();
        void set_sablage();
        void set_acquitt();
        //void set_essui_glace();
        //void set_lave_glace();
        //void set_light_cabine();
        //void set_light_pupitre();
        void set_sifflet();
        //void set_LS_SF();
        //void set_BP_SF();
        void set_signalisation();
       //void set_VI();
        //void set_direction();
        //void set_conduct_mod();
        void set_tract_frein();
        //void setPorte();
        void set_panto();
        //void set_VA();
        //void set_cle_BL();
        //void set_ventilation();
        void set_GROG();
        //void set_TVM_V1();
        //void set_TVM_V2();
        //void set_alarme();
//      int getPanto();
//      bool getDisj();
//      int getSifflet();
//      void update();
};

#endif