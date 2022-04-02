
/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour la lecture d'un potentiomètre
 * par Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 

 */
 
 int potentiometre = A0; //Broche du potentiomètre

void setup() 
{

	Serial.begin(9600); //Communication série à 9600 bauds

}//Fin setup

void loop() 
{

	int value  = analogRead(potentiometre); //lecture du potentiomètre
	Serial.println(value); //Affiche la valeur lue
	delay(200); //Pause de 200 ms

}//Fin loop