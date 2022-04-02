
/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour allumer une LED branchée sur la broche 13 lorsque le bouton sur la broche 2 est pressé
 * par Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 

 */
 
// Initialisation des constantes :
const int buttonPin = 2;     // Numéro de la broche à laquelle est connecté le bouton poussoir
const int ledPin =  13;      // Numéro de la broche à laquelle est connectée la LED

// Déclaration des variables :
int buttonState = 0;         // variable qui sera utilisée pour stocker l'état du bouton

// le code dans cette fonction est exécuté une fois au début
void setup() {
  // indique que la broche ledPin est une sortie :
  pinMode(ledPin, OUTPUT);      
  // indique que la broche buttonPin est une entrée :
  pinMode(buttonPin, INPUT);     
}

// le code dans cette fonction est exécuté en boucle
void loop(){
  // lit l'état du bouton et stocke le résultat
  // dans buttonState :
  buttonState = digitalRead(buttonPin);

  // Si buttonState est à 5V (HIGH→bouton appuyé)
  if (buttonState == HIGH) {     
    // on allume la LED
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    // sinon on éteint
    digitalWrite(ledPin, LOW); 
  }
}
