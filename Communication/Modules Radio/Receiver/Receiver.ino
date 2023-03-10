// receiver.pde
//
// Simple example of how to use VirtualWire to receive messages
// Implements a simplex (one-way) receiver with an Rx-B1 module
//
// See VirtualWire.h for detailed API docs
// Author: Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2008 Mike McCauley
// $Id: receiver.pde,v 1.3 2009/03/30 00:07:24 mikem Exp $

#define RX_PIN 10

#include <VirtualWire.h>

void setup()
{
    Serial.begin(9600);	
 
    Serial.println("INIT : OK ");
    vw_set_ptt_inverted(true); 
    vw_set_ptt_pin(RX_PIN);
    vw_setup(2000);	//Vitesse en bauds

    vw_rx_start();       //Init
}

void loop()
{
  
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

   // Serial.println("AA");

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
	int i;

       // digitalWrite(13, true); // Flash a light to show received good message
	// Message with a good checksum received, dump it.
	Serial.print("Got: ");
	
	for (i = 0; i < buflen; i++)
	{
	    Serial.print(buf[i], HEX);
	    Serial.print(" ");
	}
	Serial.println("");
        digitalWrite(13, false);
    }
}
