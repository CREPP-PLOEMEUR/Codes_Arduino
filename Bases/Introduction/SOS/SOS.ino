/*
  SOS: 
  https://www.youtube.com/watch?v=k8m8R4x0Mgk
  https://www.museedelaguerre.ca/cwm/exhibitions/navy/pdf/5-b-7_messageenmorse-f.pdf
  3 points/ 3 traits/ 3 points  pause 1s
  la led interne doit clignoter:
  3x rapidement, 3x lentement, 3x rapidement

  Esp3286 LOW/HIGH 
  
*/
 
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.

  pinMode(LED_BUILTIN, OUTPUT);
  //  digitalWrite(LED_BUILTIN, LOW); // ESP12 allume led
}

// the loop function runs over and over again forever
void loop() {
   delay(2000); 

  // S 
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (LOW is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);    // turn the LED off by making the voltage HIGH
  delay(200);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (LOW is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);    // turn the LED off by making the voltage HIGH
  delay(200);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (LOW is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);    // turn the LED off by making the voltage HIGH
  delay(200);                       // wait for a second

  delay(800); // pour 1s
  
  // O
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (LOW is the voltage level)
  delay(400);                       // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);    // turn the LED off by making the voltage HIGH
  delay(400);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (LOW is the voltage level)
  delay(400);                       // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);    // turn the LED off by making the voltage HIGH
  delay(400);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (LOW is the voltage level)
  delay(400);                       // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);    // turn the LED off by making the voltage HIGH
  delay(400);                       // wait for a second

  delay(600); // pour 1s
  // S
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (LOW is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);    // turn the LED off by making the voltage HIGH
  delay(200);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (LOW is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);    // turn the LED off by making the voltage HIGH
  delay(200);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (LOW is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);    // turn the LED off by making the voltage HIGH
  delay(200);                       // wait for a second
 
  delay(800); // pour 1s


}
