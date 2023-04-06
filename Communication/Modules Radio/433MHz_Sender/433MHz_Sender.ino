/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour l'envoi de donnée avec un module 433 MHz
 * par le Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 

 */
//Inclusion de la bibliothèque RCSwitch
#include "RCSwitch.h"

RCSwitch deviceSender = RCSwitch(); //Création de l'objet

#define SENDER_PIN 10 //Broche d'envoi
#define FREQUENCY 433 //Fréquence en MHz

#define MAX_MESSAGE_SIZE 8 //Taille maximale du message en bit - 1 octets

void setup() {
  
  deviceSender.enableTransmit(SENDER_PIN); 
  deviceSender.setPulseLength(FREQUENCY);  //Détermine la fréquence
  deviceSender.setRepeatTransmit(10);     //Nombre maximal d'envois

  pinMode(13, OUTPUT); //Pour faire clignoter la LED interne toutes les secondes

}

void loop() {
  
  deviceSender.send(0xFF, MAX_MESSAGE_SIZE); //Envoi
  //0xFF en hexadécimal = 1111 1111 en binaire  = 255 en binaire
  delay(970);

  //Clignotement
  digitalWrite(13, HIGH);
  delay(30);
  digitalWrite(13, LOW);

}
