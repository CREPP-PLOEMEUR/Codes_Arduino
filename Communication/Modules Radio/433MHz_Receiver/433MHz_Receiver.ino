/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour la réception de donnée avec un module 433 MHz
 * par le Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 

 */
//Inclusion de la bibliothèque RCSwitch
#include "RCSwitch.h"

RCSwitch deviceReceiver = RCSwitch(); //Création de l'objet

#define RECEIVER_PIN 0 //Broche de réception [Broche d'interruption -> D2]

void setup() {
  
  deviceReceiver.enableReceive(RECEIVER_PIN);
  Serial.begin(115200); //Communication série
  Serial.println("Start...");

}

void loop() {
  
  //Si des données sont disponibles...
  if(deviceReceiver.available()>0)
  {
    uint8_t data = deviceReceiver.getReceivedValue(); //Récupère les données
    Serial.println("Value = "+String(data));
    deviceReceiver.resetAvailable();     //Vide le buffer
    delay(100);
  }

}
