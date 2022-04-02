
/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour le contrôle d'un feu tricolore avec la gestion d'un bouton
 * par Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 


voiture:
* Une LED rouge sur la broche 12 
* Une LED orange sur la broche 11 
* Une LED verte sur la broche 10 

piéton:
* Une LED rouge sur la broche 9 
* Une LED verte sur la broche 8 

* Bouton poussoir branché sur la broche 2 depuis +5V
* Une résistance de 1KΩ branché sur la broche 2 depuis GND

 */
 
// Initialisation des constantes pour les LED
const int rougeVoiture = 12;
const int orangeVoiture = 11;
const int verteVoiture = 10;

const int rougePieton = 9;
const int vertePieton = 8;

// Numéro broche du bouton poussoir
const int bouton = 2;

// Déclaration des variables :
int etatBouton = 0;

// execution unique
void setup() {
// broches des LED en sorties :
pinMode(rougeVoiture, OUTPUT);
pinMode(orangeVoiture, OUTPUT);
pinMode(verteVoiture, OUTPUT);

pinMode(rougePieton, OUTPUT);
pinMode(vertePieton, OUTPUT);

// broche bouton en entrée :
pinMode(bouton, INPUT);
}

// boucle infinie
void loop() {
// normallement le feu piéton est toujours rouge
digitalWrite(rougePieton, HIGH);

// feu voiture Vert allumé 3s 
digitalWrite(verteVoiture, HIGH);
delay(3000);
digitalWrite(verteVoiture, LOW); 

// l'état du bouton stocké dans etatBouton :
etatBouton = digitalRead(bouton);

// le bouton est appuyé si etatBouton = HIGH
if (etatBouton == HIGH) {
digitalWrite(orangeVoiture, HIGH);
delay(1000);
digitalWrite(orangeVoiture, LOW);

digitalWrite(rougeVoiture, HIGH);

// feu piéton passe au vert pendant 5s
digitalWrite(rougePieton, LOW);
digitalWrite(vertePieton, HIGH);

delay(5000);

// feu piéton redevient rouge
digitalWrite(rougePieton, HIGH);
digitalWrite(vertePieton, LOW);

// feu voiture Rouge est éteint
// avant retour au déroulement normal
digitalWrite(rougeVoiture, LOW);
}
else {
// Fonctionnement normal du feu voiture:
// orange 1s, rouge 3s
digitalWrite(orangeVoiture, HIGH);
delay(1000);
digitalWrite(orangeVoiture, LOW);

digitalWrite(rougeVoiture, HIGH);
delay(3000);
digitalWrite(rougeVoiture, LOW);
}
}
