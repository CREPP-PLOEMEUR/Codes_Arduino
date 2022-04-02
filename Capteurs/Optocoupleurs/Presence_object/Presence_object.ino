/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour la détection d'un objet
 * par Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 

 */

//Entête déclarative = déclarer ici les constantes et variables globales

const int OPTO=3; // broche de l'optocoupleur
const int PRESENCE=1; // constante valeur broche lors de la présence objet
const int LED=13; // broche de la LED

//La fonction setup() // exécutée au début et en une seule fois
void setup() {
  
  pinMode(OPTO, INPUT); // broche en entrée
  pinMode(LED, OUTPUT); // broche en sortie

} // fin de la fonction setup()

//La fonction loop() exécutée ensuite en boucle sans fin
void loop() {
  
  if (digitalRead(OPTO)==PRESENCE) { // si présence d'un objet
   digitalWrite(LED, HIGH); // allume la LED
  } // fin de if
  
  else { // si non
   digitalWrite(LED, LOW); // éteint la LED
  } // fin de else

} // fin de la fonction loop()
