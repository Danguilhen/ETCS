#ifndef TD
#define TD

#include "define.hpp"

class Train_dynamique
{
	private :
	float V_train = 80;
	sf::Clock chrono;//créer le chrono
	sf::Time diftime;//créer la varaible qui stocke le temps écoulé
	float deltats;//créer la variable qui stocke le temps écoulé en seconde
	float distance_update; // distance parcourue entre chaque mise à jour
	float acceleration;
	int traction;


	public :

	void update();
	float getV_train();
	void setV_train(float V);
	void mouvementTrain();
	float getDistance_Uptdate();
	float getTraction();
	void setTraction(float A);
};

/*
class Train_dynamique {

	private :


	public:
	float tracvalue = data.pupitre_entrant.getManiptraction();  // Valeur du manipulateur de traction
    float ig = 0;                                               // ???
    float gradient = 0;                                         // pente de la voie
    float frein_elec = 0;
	float frein_elecTrac = 0;
    float freinDirect=0;
    float effortchoisi=0;
    float freinDirectPBL=0;
    float effortchoisiFrein=0;
    float absspeed=0;
    float newSpeed=0;
    float acc=0;
    float speed = data.pupitre_entrant.getSpeed();



    void Traction() {                                           // Calcul traction et freinage motrice
        float absspeed = 0;                                     // Initialisation valeurs
        float abstrac = 0;
        float pass = 0;
        float a = abs(acc)

        if (speed < 0)                                          // Définition d'une valeure absolue de la vitesse
		    absspeed = -speed;
	    else if (speed >= 0)
		    absspeed = speed;

	    if (tracvalue >= 0)                                     // Définition d'une valeure absolue de la commande de traction
		    abstrac = tracvalue;
	    else if (tracvalue < 0)
		    abstrac = -tracvalue;

        if (tracvalue == 0) {   //pas d'effort de traction si manip TF à 0
		    effortchoisi = 0;
            pass=1;
        }

        else if (absspeed == 0 && tracvalue > 0) {   //effort au démarrage
		    effortchoisi = effortdem * abstrac;
            pass=2;
        }

        else if (absspeed < 6.94 && tracvalue < 0)   {  //frein pneumatique en dessous de 25 km/h
		    freinDirect = 19.737*cfPressureMotriceTrac;
            pass=3;
        }

        else if (((effortdem - 0.22*absspeed)*abstrac) < ((power / absspeed)*abstrac) && tracvalue > 0) {  //Courbe de limite d'adhérence Dasye
		    effortchoisi = (effortdem - 0.22*3.6*absspeed)*abstrac;
            pass=4;
        }

        else if (tracvalue > 0)    {  //équipuissance
		    effortchoisi = (power / absspeed)*abstrac;
            pass=5;
        }

        else if (tracvalue < 0)
	    {
		    if (absspeed >= 6.94 && absspeed < 13.89) {   //frein électrique entre 25 et 50 km/h
			    frein_elecTrac = abstrac * (18 * absspeed - 50);
                pass=6;
                }
		    else if (200 < 7560 / absspeed) { //frein électrique entre 50 km/h et l'équipuissance
			    frein_elecTrac = abstrac * abstrac * 200;
                pass=7;
                }
		    else {
			    frein_elecTrac = 7560 / absspeed;
                pass=8;
                }
	    }

        value1=effortchoisi*speed;
        envoiEffort=effortchoisi;

		// calcul de la RAV

        if (absspeed == 0)   //A l'arrêt, on ne prend pas en compte le terme A dans la Rav (effort déterminé par la résistance au décollage)
		    rav = rav_B * 3.6*absspeed + rav_C * absspeed*absspeed*3.6*3.6;
	    else     //quand on est pas à l'arrêt
		    rav = rav_A + rav_B * 3.6*absspeed + rav_C * absspeed*absspeed*3.6*3.6;

        ravAff=to_string(rav);// ?

        if (cgPressure < 5.09) {
		    if (absspeed < 6.94){ //en dessous de 25 km/h
			    effortchoisiFrein = -(100 * cfPressure + 19.737*cfPressure); //effort de freinage total
			    freinDirectPBL = 19.737*cfPressure;    //effort de freinage remorque
            }

            else if (absspeed >= 6.94) //au dessus de 25 km/h  // PAS PLUTOT 50 km/h ?
			    if (absspeed >= 13.89 && cgPressure > 4.4) { //au dessus de 50 km/h, CG entre 5,1 et 4,5 bar
				    if ((5.1 - cgPressure) * 200 / 0.6 < (5.1 - cgPressure) * 7560 / (0.6*absspeed)) { //200kN de freinage max
					    frein_elec = (5.1 - cgPressure) * 200 / 0.6; // 0,6=5,1-4,5
				    }
				    else {
					    frein_elec = (5.1 - cgPressure) * 7560 / (0.6*absspeed); //equipuissance freinage électrique
				    }
			    }
			    else if (absspeed >= 13.89 && cgPressure <= 4.4) { //au dessus de 50 km/h, CG à 4,4 bar ou moins
				    if (200 < 7560 / absspeed) { //200kN
					    frein_elec = 200;
				    }
				    else {
					    frein_elec = 7560 / absspeed; //equipuissance
				    }
			    }
			else //entre 25 et 50 km/h
				frein_elec = 18 * absspeed - 50;
		}
    	// on compare la commande au manip traction/freinage et la commande au manip freinage
		//celle dont la pression est la plus élevée est retenue

	    if (absspeed < 6.94) { //en dessous de 25 km/h
		    if (cfPressureMotriceTrac > cfPressureMotrice)
			    effortchoisiFrein = -(100 * cfPressure + freinDirect); //remorque+frein pneu manip traction freinage
		    if (cfPressureMotriceTrac <= cfPressureMotrice)
			    effortchoisiFrein = -(100 * cfPressure + freinDirectPBL); //remorque + frein pneu manip freinage
	    }
	    else { //au dessus de 25 km/h
		    if (frein_elecTrac > frein_elec)
			    effortchoisiFrein = -(100 * cfPressure + frein_elecTrac); //remorque+frein elec manip traction freinage
		    if (frein_elecTrac <= frein_elec)
			    effortchoisiFrein = -(100 * cfPressure + frein_elec); //remorque + frein elec manip freinage
	    }

		//calcul effort total (trac+frein : les deux manips peuvent fonctionner en meme temps)


		effortchoisi = effortchoisi + effortchoisiFrein;
		acc = effortchoisi - rav - m * 9.81*gradient;      //Calcul de l'accélération de la rame (multipliée par k*M)
		acc = acc / mk;      //Calcul de la vraie accélération
        value2=frein_elec;

		timer2 = timer2_clock.getElapsedTime();  //définition d'un delta T utile pour intégrer l'accélération
		deltaT = timer2.asSeconds() - timer.asSeconds();


		if (absspeed == 0){      //Calcul de la résistance au démarrage (valable uniquement à l'arrêt)
			if (gradient == 0){
				if (effortchoisi <= rav_A)   //En palier, si l'effort de traction est inférieur à la Rav A, la rame ne bouge pas
					newSpeed = 0;
				else      //Sinon elle décolle
					newSpeed = speed + acc * deltaT;
			}
			else if (gradient != 0){ //VOIR COURS PIERRE CHAPAS/MARC CIAIS. FOrmule du petit RT
				if (effortchoisi > (rav_A + (m / 100)*(gradient * 981 + 6.8)) && ((gradient > 0 && gradient <= 1.8) || (gradient < 0 && gradient >= -1.8)))
					newSpeed = speed + acc * deltaT;
				else if (effortchoisi > (rav_A + (m / 100)*(1.25*gradient * 981 + 2.75)) && (gradient > 1.8 || gradient < -1.8))
					newSpeed = speed + acc * deltaT;
				else if (effortchoisi == (rav_A + (m / 100)*(gradient * 981 + 6.8)) && ((gradient > 0 && gradient <= 1.8) || (gradient < 0 && gradient >= -1.8)))
				newSpeed = 0;
				else if (effortchoisi == (rav_A + (m / 100)*(1.25*gradient * 981 + 2.75)) && (gradient > 1.8 || gradient < -1.8))
				newSpeed = 0;

				else if (gradient < 0 && gradient > -1.8) {
					if (effortchoisi < 0 && effortchoisi - rav_A - (m / 100)*(gradient * 981 + 6.8) <= 0)
						newSpeed = 0;
					else if (effortchoisi >= 0 && effortchoisi - rav_A - (m / 100)*(gradient * 981 + 6.8) <= 0)
						newSpeed = 0;
					else if (effortchoisi > 0 && effortchoisi - rav_A - (m / 100)*(gradient * 981 + 6.8) > 0) {
						acc = effortchoisi - rav_A - (m / 100)*(gradient * 981 + 6.8);
						acc = acc / mk;
						newSpeed = speed + acc * deltaT;
					}
					else if (effortchoisi < 0 && effortchoisi - rav_A - (m / 100)*(gradient * 981 + 6.8) > 0) {
						acc = effortchoisi - rav_A - (m / 100)*(gradient * 981 + 6.8);
						acc = acc / mk;
						newSpeed = speed + acc * deltaT;
					}
				}

				else if (gradient < -1.8) {
					if (effortchoisi < 0 && effortchoisi - rav_A - (m / 100)*(1.25*gradient * 981 + 2.75) <= 0)
						newSpeed = 0;
					else if (effortchoisi >= 0 && effortchoisi - rav_A - (m / 100)*(1.25*gradient * 981 + 2.75) <= 0)
						newSpeed = 0;
					else if (effortchoisi >= 0 && effortchoisi - rav_A - (m / 100)*(1.25*gradient * 981 + 2.75) > 0) {
						acc = effortchoisi - rav_A - (m / 100)*(1.25*gradient * 981 + 2.75);
						acc = acc / mk;
						newSpeed = speed + acc * deltaT;
					}
					else if (effortchoisi < 0 && effortchoisi - rav_A - (m / 100)*(1.25*gradient * 981 + 2.75) > 0) {
						acc = effortchoisi - rav_A - (m / 100)*(1.25*gradient * 981 + 2.75);
						acc = acc / mk;
						newSpeed = speed + acc * deltaT;
					}
				}
				else if (gradient > 0 && gradient < 1.8) {
					if (effortchoisi < 0 && effortchoisi - rav_A + (m / 100)*(gradient * 981 + 6.8) <= 0)
						newSpeed = 0;
					else if (effortchoisi >= 0 && effortchoisi - rav_A + (m / 100)*(gradient * 981 + 6.8) <= 0)
						newSpeed = 0;
					else if (effortchoisi >= 0 && effortchoisi - rav_A + (m / 100)*(gradient * 981 + 6.8) >= 0) {
						acc = effortchoisi - rav_A + (m / 100)*(gradient * 981 + 6.8);
						acc = -acc / mk;
						newSpeed = speed + acc * deltaT;
					}
					else if (effortchoisi < 0 && effortchoisi - rav_A + (m / 100)*(gradient * 981 + 6.8) >= 0) {
						acc = effortchoisi - rav_A + (m / 100)*(gradient * 981 + 6.8);
						acc = -acc / mk;
						newSpeed = speed + acc * deltaT;
					}
				}
				else if (gradient > 1.8) {
					if (effortchoisi < 0 && effortchoisi - rav_A + (m / 100)*(1.25*gradient * 981 + 2.75) <= 0)
						newSpeed = 0;
					else if (effortchoisi >= 0 && effortchoisi - rav_A + (m / 100)*(1.25*gradient * 981 + 2.75) <= 0)
						newSpeed = 0;
					else if (effortchoisi >= 0 && effortchoisi - rav_A + (m / 100)*(1.25*gradient * 981 + 2.75) >= 0) {
						acc = effortchoisi - rav_A + (m / 100)*(1.25*gradient * 981 + 2.75);
						acc = -acc / mk;
						newSpeed = speed + acc * deltaT;
					}
					else if (effortchoisi < 0 && effortchoisi - rav_A + (m / 100)*(1.25*gradient * 981 + 2.75) >= 0) {
						acc = effortchoisi - rav_A + (m / 100)*(1.25*gradient * 981 + 2.75);
						acc = -acc / mk;
						newSpeed = speed + acc * deltaT;
					}
				}
			}	// Fin grad != 0
		}	// Fin absspeed == 0

		//si on est pas à l'arret, pas de résistance au decollage
		//distinction cas vitesse positive/vitesse negative
		else if (speed > 0)
			newSpeed = speed + acc * deltaT;
		else if (speed < 0)
			newSpeed = speed - acc * deltaT;

		//la vitesse passe obligatoirement par 0 lors d'un changement de signe
		//pour prendre en compte la résistance au décollage
		if (newSpeed > 0 && speed < 0)
			newSpeed = 0;
		else if (newSpeed < 0 && speed > 0)
			newSpeed = 0;

		//fixe la vitesse du train
		//actor.setVelocity()
		speed = newSpeed;
		timer = timer2;
    } // Fin Traction



	void setFrein(){
    	while(true){
			if (manipFreinageSerrage == "false" && manipFreinageDesserrage == "true") //manip frein Desserrage
				consigneFrein = 2;
			else if (manipFreinageSerrage == "true" && manipFreinageDesserrage == "false")//manip frein Serrage
				consigneFrein = 0;
			else if (manipFreinageSerrage == "false" && manipFreinageDesserrage == "false") //manip frein Neutre
				consigneFrein = 1;
			// Faire un cas true true ?

			timer2F = timer2F_clock.getElapsedTime();
			deltaTF = timer2F.asSeconds() - timerF.asSeconds();
			lastCgPressure = cgPressure;

			//On fait tomber la CG à l'atmosphère lors d'un FU
			if (lastConsigneFrein == 3 && cgPressure > 0) {
				consigneFrein = 3;
				cgPressure = cgPressure - deltaTF * 1;
			}
			//desserrage
			else if (consigneFrein == 2) {
				if (cgPressure >= 5.1) //blocage CG à 5.1 (l'aiguille du mano en Dasye est à 5.1)
					cgPressure = 5.1;
				else
					cgPressure = cgPressure + deltaTF * 1;
			}
			//serrage
			else if (consigneFrein == 0) { //blocage CG à 0
				if (cgPressure <= 0)
					cgPressure = 0;
				else
					cgPressure = cgPressure - deltaTF * 1;	//Patm = 1 bar
			}
			timerF = timer2F;
			lastConsigneFrein = consigneFrein;
		}  // Fin While
	} // Fin setFrein



	void calculCylindre() {
		while(true) {
			timer2CF = timer2CF_clock.getElapsedTime();
			deltaCF = timer2CF.asSeconds() - timerCF.asSeconds();

			//calcul des pressions consigne à atteindre dans les CF en fonction de la CG

			float cfConsigneMotriceTrac = 0;
			if (absspeed < 59.7) //inférieur à 220 km/h
				cfConsigne = -6.333*cgPressure + 32.2983;
			else  //supérieur à 220 km/h
				cfConsigne = -4.333*cgPressure + 22.0988;
			if (absspeed < 6.94) { //inférieur à 25 km/h, utilisation du manip pneumatique
				cfConsigneMotrice = -6.333*cgPressure + 32.2983;
				if (tracvalue < 0) //utilisation du manip traction/freinage
					cfConsigneMotriceTrac = 3.8 * (-tracvalue);
			}//supérieur à 25 km/h, pas de pression dans les cylindres de frein de motrice
			else {
				cfConsigneMotrice = 0;
				cfConsigneMotriceTrac = 0;
			}
			//bridage pression max à 3,8 bar en dessous de 220 km/h
			if (cgPressure <= 4.5 && absspeed < 59.7)
				cfConsigne = 3.8;
			//bridage pression max à 2,6 bar au dela de 220 km/h
			else if (cgPressure <= 4.5 && absspeed >= 59.7)
				cfConsigne = 2.6;
			//bridage pression max en motrice à 3,8 bar en dessous de 25 km/h
			if (cgPressure <= 4.5 && absspeed < 6.94)
				cfConsigneMotrice = 3.8;
			//on fait en sorte que la pression ne descende pas sous 0 bar
			if (cgPressure >= 5.1) {
				cfConsigne = 0;
				cfConsigneMotrice = 0;
			}

			//si la différence entre la pression actuelle et la pression consigne est de moins de 0,1 bar
			//alors cfPressure = cfConsigne
			//depend de la reactivité du systeme et cette valeur pourra etre abaissée
			if (cfPressure - cfConsigne > -0.02 &&  cfPressure - cfConsigne < 0.02)
				cfPressure = cfConsigne;
			//sinon on fait tendre la pression vers la pression consigne
			else if (cfPressure < cfConsigne)
				cfPressure = cfPressure + 2.64*deltaCF;
			else if (cfPressure > cfConsigne)
				cfPressure = cfPressure - 2.64*deltaCF;

			//on fait pareil pour la pression des cylindres en motrice
			//le cas suivant est celui d'un freinage au manip frein
			if (cfConsigneMotrice >= cfConsigneMotriceTrac) {
				if (cfPressureMotrice - cfConsigneMotrice > -0.02 &&  cfPressureMotrice - cfConsigneMotrice < 0.02) // PAS PLUTOT DES || ??
					cfPressureMotrice = cfConsigneMotrice;
				else if (cfPressureMotrice < cfConsigneMotrice)
					cfPressureMotrice = cfPressureMotrice + 2.64*deltaCF;
				else if (cfPressureMotrice > cfConsigneMotrice)
					cfPressureMotrice = cfPressureMotrice - 2.64*deltaCF;

				//cfPressureAff = pression affichée
				cfPressureAff = cfPressureMotrice;
			}
			//ici, au manip traction freinage
			if (cfConsigneMotrice < cfConsigneMotriceTrac) {
				if (cfPressureMotriceTrac - cfConsigneMotriceTrac > -0.02 &&  cfPressureMotriceTrac - cfConsigneMotriceTrac < 0.02)
					cfPressureMotriceTrac = cfConsigneMotriceTrac;
				else if (cfPressureMotriceTrac < cfConsigneMotriceTrac)
					cfPressureMotriceTrac = cfPressureMotriceTrac + 2.64*deltaCF;
				else if (cfPressureMotriceTrac > cfConsigneMotriceTrac)
					cfPressureMotriceTrac = cfPressureMotriceTrac - 2.64*deltaCF;
				cfPressureAff = cfPressureMotriceTrac;
			}
			timerCF = timer2CF;
		} // Fin While
	} // Fin calculCylindre
};

*/

#endif