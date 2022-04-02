/*

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.

 * Programme pour la récupération de la température et de l'humidité avec un capteur DHT
 * par Club de Robotique et d'Electronique Programmable de Ploemeur
 * Autorisation de redistribuer et modifier le code sous les termes de la Licence GNU-GPL 

 */

#include "DHT.h"

#define DHTPIN 10     // Digital pin connected to the DHT sensor

//#define DHTTYPE DHT11   
#define DHTTYPE DHT22     
//#define DHTTYPE DHT21 

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
}

void loop() 
{

  //Le capteur est lent en lecture
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) //isnan = is not a number
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.println("");
  //Serial.println(f);

  delay(500);
}
