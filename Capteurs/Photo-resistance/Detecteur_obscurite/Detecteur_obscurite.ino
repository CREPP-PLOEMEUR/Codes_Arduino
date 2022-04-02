/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour un détecteur d'obscurité
 * par Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 

 */

//---Entête déclarative---

// --- constantes des broches ---
const int photoR=0; //declaration constante de broche analogique

// --- Déclaration des variables globales ---
int mesureBrute=0;// Variable pour acquisition résultat brut de conversion analogique numérique
int seuil=200; // Variable fixant le seuil de détection de l'obscurité - à adapter

//**************** FONCTION SETUP = Code d'initialisation *****
void setup() { // debut de la fonction setup()

Serial.begin(115200); // initialise connexion série à 115200 bauds

} // fin de la fonction setup()

//***** FONCTION LOOP = Boucle sans fin *****
void loop(){ // debut de la fonction loop()

// acquisition conversion analogique-numerique (CAN) sur la voie analogique
	mesureBrute=analogRead(photoR);

// affiche valeur numerique entière ou à virgule au format décimal
  	Serial.println(mesureBrute);

  if (mesureBrute<seuil) Serial.println("Obscurite detectee"); // message si obscurité détectée
  delay(500);

} // fin de la fonction loop() 