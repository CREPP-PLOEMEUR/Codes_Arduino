/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour la gestion d'un moteur avec un L293
 * par Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 

 */

int motor1_enablePin = 11; //pwm 
int motor1_in1Pin = 13; 
int motor1_in2Pin = 12; 
 
 
void setup() 
{ 
  //on initialise les pins du moteur 1 
  pinMode(motor1_in1Pin, OUTPUT); 
  pinMode(motor1_in2Pin, OUTPUT); 
  pinMode(motor1_enablePin, OUTPUT); 
 
 
} 
 
void loop() 
{ 
 
   SetMotor1(255, false); 
 
} 
 
//Fonction qui set le moteur
void SetMotor1(int speed, boolean reverse) 
{ 
  analogWrite(motor1_enablePin, speed); 
  digitalWrite(motor1_in1Pin, ! reverse); 
  digitalWrite(motor1_in2Pin, reverse); 
} 
 
