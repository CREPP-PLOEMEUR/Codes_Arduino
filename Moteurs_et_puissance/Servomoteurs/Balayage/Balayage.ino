/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour la gestion d'un servomoteur
 * par Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 

 */
  #include <Servo.h>      //Inclusion de la bibliothèque Servo
  Servo myservo;  // Création d'un objet Servo
  int pos = 0;    //Angle du servomoteur
  
  void setup() {

    myservo.attach(11);  //Choix de la broche du servo moteur

  }
  
  void loop() {

    for (pos = 0; pos <= 180; pos += 1) { //Parcours la plage angulaire [0-180] degré par degré

      myservo.write(pos);              //Actualise la position 
      delay(15);                       //Attend 15 ms avant l'actualisation

    }//Fin for

    for (pos = 180; pos >= 0; pos -= 1) {     //Parcours la plage angulaire [0-180] degré par degré

      myservo.write(pos);              //Actualise la position 
      delay(15);                       //Attend 15 ms avant l'actualisation

    }//Fin for
  }//Fin loop