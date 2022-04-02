/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour l'utilisation des interruptions externes
 * par Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 

 */

int ledPin = 13;    //Led interne
int button = 2;  	//Bouton relié à la broche 2 avec une résistance de charge interne
	
volatile int state = LOW;  //Etat courant de la LED
	
void setup() {
	  
	Serial.begin(9600); //Vitesse de communication à 9600 bit/s
	  
	pinMode(ledPin, OUTPUT);                //Led mise en sortie
	pinMode(button, INPUT_PULLUP);    //Bouton mis en entrée
	  
	attachInterrupt(digitalPinToInterrupt(button), onEvent, CHANGE);  //Appel de la fonction onEvent à chaque changement de front du bouton
	Serial.println("Init");
}
	
void loop() {
	  
	delay(5000); //Pause du programme principal
	  
}
	
void onEvent() {
	  
	state = !state; //Inverse l'état de la LED
	  
	if(state)
	{
		Serial.println("ON");
	}else
	{
		Serial.println("OFF");
	}s
	digitalWrite(ledPin, state); //Met à jour l'état de la LED
}
	