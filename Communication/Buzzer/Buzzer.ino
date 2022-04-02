/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour le test d'un buzzer
 * par Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 

 */

// Initialisation des constantes :
const int analogInPin = A2; // Numéro de la broche à laquelle est connecté la photorésistance
const int analogOutPin = 8; // Numéro de la broche à laquelle est connectée le buzzer

int sensorValue = 0; // Valeur lue sur la photorésistance
int outputValue = 0; // Valeur envoyée à la LED

void setup() 
{
// Initialise la communication avec l'ordinateur
    Serial.begin(9600);

    // Indique que la broche analogOutPin est une sortie :
    pinMode(analogOutPin, OUTPUT); 
    // Indique que la broche analogInPin est une entrée :
    pinMode(analogInPin, INPUT); 
}

void loop() 
{
    // lit la valeur de la photorésistance et
    // stocke le résultat dans sensorValue :
    sensorValue = analogRead(analogInPin); 
    // change sensorValue vers une intervalle de 0 à 255
    // et stocke le résultat dans outputValue :
    outputValue = map(sensorValue, 0, 1023, 50, 30000); 
    // envoie de cette nouvelle valeur sur la LED
    analogWrite(analogOutPin, outputValue);

    Serial.print("sensor = " ); 
    Serial.print(sensorValue); 
    Serial.print("\t output = "); 
    Serial.println(outputValue); 

    //note sur piezzo sur broche 8
    tone(analogOutPin, outputValue);
    delay(50);

    // envoie tout ça vers l'ordinateur
    Serial.print("sensor = " ); 
    Serial.print(sensorValue); 
    Serial.print("\t output = "); 
    Serial.println(outputValue);

}
