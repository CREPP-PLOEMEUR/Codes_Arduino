/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour le TP Feux tricolores
 * par Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 

 */

// définition des 3 variables entières LedXyz
int LedRouge  = 2;
int LedOrange = 3;
int LedVerte  = 4;

// le code dans cette fonction est exécuté une fois au début 
void setup() {

// indique que les broches 2,3,4 des Led sont en sortie :  
pinMode(LedRouge, OUTPUT);
pinMode(LedOrange, OUTPUT);
pinMode(LedVerte, OUTPUT);
} 

//  boucle infinie 
void loop() {  
digitalWrite(LedVerte, HIGH);   // allumer la LED (tension 5V sur la broche)  
delay(3000);                       // attendre 3000ms = 3s  
digitalWrite(LedVerte, LOW);    // éteindre la LED (tension 0V sur la broche)  

digitalWrite(LedOrange, HIGH);   // allumer la LED (tension 5V sur la broche)  
delay(1000);                      // attendre 1000ms = 1s  
digitalWrite(LedOrange, LOW);    // éteindre la LED (tension 0V sur la broche)  

digitalWrite(LedRouge, HIGH);   // allumer la LED (tension 5V sur la broche)  
delay(9000);                       // attendre 3000ms = 3s  
digitalWrite(LedRouge, LOW);    // éteindre la LED (tension 0V sur la broche)  

  
  
//  delay(1000);                       // attendre à nouveau 1 seconde 
}
