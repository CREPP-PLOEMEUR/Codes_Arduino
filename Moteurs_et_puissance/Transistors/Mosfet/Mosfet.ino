/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour la gestion d'un mosfet.
 * par Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 

 */

  #define PIN 11     //GATE du transistor
 
  void setup() {
  
    pinMode(PIN, OUTPUT); //Mise en sortie de la broche
  
  }//Fin setup
  
  void loop() {
  
    digitalWrite(PIN, HIGH);    //Mise en route du transistor
    delay(5000);               //Délai de 5s
    digitalWrite(PIN, LOW);     //Arret du transistor
    delay(5000);               //Délai de 5s
  
  }//Fin loop