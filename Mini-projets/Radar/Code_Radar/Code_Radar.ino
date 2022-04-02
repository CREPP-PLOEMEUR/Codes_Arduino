/*
 * *********************************************************************************
 * le servo moteur tourne de degré en degré permettant au capteur ultrason de ...
 * mesurer la disatnce au plu sproche obstacle.
 * le programme envoie sur le terminal un flux de "degré,distance."
 * *********************************************************************************
 */
// ajout bibliothèque du servo moteur
#include <Servo.h>. 

// Definition Trig and Echo pins pour le capteur Ultrasonic
const int trigPin  = 10; // fil blanc
const int echoPin  = 11; // fil gris
const int servoPin = 12; // fil servomoteur

// Variables pour la durée et la distance
long duree;
int distance;
float VitesseSon = 0.034; // vitesse du son= 340m/s

// creation objet myServo pour controler le servo-moteur
Servo myServo;
/*
 * *********************************************************************************
 */
void setup() {
  pinMode(trigPin, OUTPUT); // trigPin en sortie
  pinMode(echoPin, INPUT);  // echoPin en entrée
  Serial.begin(9600);
  myServo.attach(servoPin); // servoPin en 12
}
/*
 * *********************************************************************************
 */
void loop() {
  // rotation du servo moteur de 15 à 165 degré
  for(int i=15;i<=165;i++){  
     myServo.write(i);
     delay(30);
     // appel de la fonction pour calcule la distance 
     // mesurée par le capteur  Ultrasonic pour chaque degré
     distance = calculDistance();
     Serial.print(i); // angle en degré vers port série
     Serial.print(","); // caractère , utilisé plus tard comme séparateur dans Processing 
     Serial.print(distance); // distance vers port série
     Serial.print("."); // caractère ,. utilisé plus tard comme index de fin dans Processing 
  } 
  // idem pour la rotation retour de  165 à 15 degré
  for(int i=165;i>15;i--){  
     myServo.write(i);
     delay(30);
     // appel de la fonction pour calcule la distance 
     // mesurée par le capteur  Ultrasonic pour chaque degré
     distance = calculDistance();
     Serial.print(i);
     Serial.print(",");
     Serial.print(distance);
     Serial.print(".");
  }
}
/*
 * *********************************************************************************
 */
// Fonction calculant la distance mesurée par ultrason
int calculDistance(){
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    //  trigPin à HIGH state pour 10 micro-secondes
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duree = pulseIn(echoPin, HIGH); // lit echoPin, retour du trajet du son en microsecondes
    distance= duree*VitesseSon/2;
    return distance;
}
