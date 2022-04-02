/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour les tests des modules Bluetooth de type HC-0X, Crius et Xbee
 * par Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 

 */

#include <SoftwareSerial.h>     // Utilisation de la librairie "SoftwareSerial"
const int RX = 3;            // Broche Rx du module reliée à la broche 3 de la carte
const int TX =             // Broche Tx du module reliée à la broche 2 de la carte

SoftwareSerial moduleBluetooth(RX,TX);     // Déclaration du module 
String message;                 // Chaîne de caractère qui contiendra les données du module
char c;

void setup() 
{
  Serial.begin(9600);         
  moduleBluetooth.begin(9600);             // Début de la communication (9600
  pinMode(LED, OUTPUT);         // Led configurée en sortie
}
     
void loop()
{                  
  while (Serial.available()) 
  {  // lit les données du module 
    c = Serial.read();
    message += c;
    if (message.length()>0) {Serial.println(message);} // Si le message contient des données, affiche le message
  } //fin while
} //fin loop

