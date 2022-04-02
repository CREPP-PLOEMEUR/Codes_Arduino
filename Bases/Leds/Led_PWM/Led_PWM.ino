/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour le contrôle d'une led avec Arduino en PWM
 * par Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 

 */

const int pin_led = 11; //Selection d'une broche PWM

float duty_cyle[11] = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};//Création d'un tableau avec les différents rapports cycliques
  
void setup() 
{
  
    pinMode(pin_led, OUTPUT);  //Mise en sortie de la broche LED
  
}//Fin setup
  
void loop() {
  
    for(int i=0;i<11;i++) 
    {
        int value_r = duty_cyle[i]*255.0; //Conversion d'une valeur entre 0 et 1 en une valeur entre 0 et 255
        analogWrite(pin_led, value_r); //Change le rapport cyclique pendant 3 s
        delay(600);        //Attend 1s
    }
      
}//Fin loop
