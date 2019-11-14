#ifndef DYNAMIQUE
#define DYNAMIQUE

// Fill out your copyright notice in the Description page of Project Settings.

#include <string>

using namespace std;

class Dynamique
{
	public:
		float timer = 0;
		float timer2 = 0;
		float timer2F = 0;
		float timer3 = 0;
		float timerF = 0;
		float timerCF = 0;
		float timer2CF = 0;
		float deltaCF = 0;
		float deltaTF = 0;

		//ATP

		int atpAction = 2;

		//paramètres Dasye

		float m = 425;
		float k = 1.03;
		float mk = m * k;
		float effortdem = 222;
		float power = 9280;
		float masseadh = 136;
		float rav_A = 2.7;
		float rav_B = 0.032;
		float rav_C = 0.000535;

		float speed = 0;
		float absspeed = 0;
		float newSpeed = 0;
		float rav;

		//variables traction
		float acc = 0;
		float deltaT = 0;
		float gradient = 0;
		int i = 0;

		float abstrac;
		float effortres;

		//donneesFrein

		float cgPressure = 3.5;
		float cpPressure = 9;
		float cfPressure = 3.8;
		int consigneFrein;
		float cfConsigne = 3.8;
		float cfConsigneMotrice = 3.8;
		float lastCgPressure;
		float lastConsigneFrein;
		float effortchoisiFreinRemorque = 380;
		float effortchoisiFreinMotrice = 75;
		bool urg = 1;
		float cfPressureMotrice = 3.8;
		float cfPressureMotriceTrac;
		float effortchoisiFrein;
		float effortcombi;
		float tracvalue = 0;
		float cfPressureAff = 3.8;
		int gradTemp = 0;
		string manipSerrageFreinage;
		string manipDesserrageFreinage;
		string bpUrgence;
		string manip_trac_data;

		void receive();
		void setTrac();
		void setFrein();
		void calculCylindre();
		void send();

		Dynamique();
		~Dynamique();
};

#endif