/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour le contrôle d'une led avec Arduino
 * par Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 

 */

const int led = 11; //Broche de la led
const int ledDelay = 200;   //délai de clignotement de la led (durée état haut = durée état bas)

void setup() {
  
    pinMode(led, OUTPUT);  //Mise en sortie de la broche LED
  
}//End setup
  
void loop() {
  
    digitalWrite(led, HIGH);
    delay(ledDelay);
    digitalWrite(led, LOW);
    delay(ledDelay); 
      
}//End loop