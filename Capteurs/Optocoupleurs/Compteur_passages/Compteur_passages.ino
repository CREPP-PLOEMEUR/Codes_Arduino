/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour la gestion d'un optocoupleur à fourche
 * par Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 

 */

//Entête déclarative = déclarer ici les variables et constantes globales
const int OPTO=2; // broche de l'optocoupleur
const int PRESENCE=1; // constante valeur broche lors de la présence d'un objet

int nombrePassage=0; // variable de comptage du nombre de passages
boolean temoinPassage=false; // variable temoin présence objet


void setup() 
{
  Serial.begin(115200); // vitesse de communication série
  pinMode(OPTO, INPUT); // broche en entrée

} // fin de la fonction setup()

//La fonction loop() : exécutée ensuite en boucle sans fin
void loop() 
{
  if (digitalRead(OPTO)==PRESENCE) 
  { // si la présence d'un objet
    if (temoinPassage==false) 
    { // si dernier état = absence d'objet
    
      temoinPassage=true; // mémorise présence d'objet
      nombrePassage=nombrePassage+1; // ajoute 1 passage
    
      Serial.println("Nombre de passage d'un objet dans la fente de l'optocoupleur = "); // message
      Serial.println(nombrePassage);
      delay(500);  // pause entre 2 prises en compte
  
    }  // fin de if témoin passage
  } // fin de if
  
  else { // si pas d'objet
  
    temoinPassage=false; // mémorise absence d'objet
    
  } // fin de else
  
} // fin de la fonction loop()
