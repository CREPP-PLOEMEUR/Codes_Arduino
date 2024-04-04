/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour la gestion d'un servomoteur
 * par Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 

 */
  #include <Servo.h>

#define SERVO_PIN 11 //broche de commande

//Inclusion de la bibliothèque Servo
Servo myServo; // Création d'un objet Servo


void setup() 
{
  myServo.attach(SERVO_PIN);    //Choix de la broche du servo moteur
}
void loop() 
{
  for (int pos = 0; pos <= 180; pos += 1) 
  { 
    myServo.write(pos);  //Actualise la position
    delay(15);

  }//Fin for


  for (int pos = 180; pos >= 0; pos -= 1) 
  {
    myServo.write(pos);  //Actualise la position
    delay(15);

  }//Fin for
}//Fin loop