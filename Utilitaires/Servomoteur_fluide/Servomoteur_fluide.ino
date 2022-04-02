// Programme Arduino : Rendre fluide le mouvement d'un servomoteur
//---- par X. HINAULT - 2012 - licence GPL v3 - www.mon-club-elec.fr
 //---- inclusion de librairie
#include <Servo.h> // inclut la librairie Servo

//--- entete déclarative = variables et constantes globales
int octetReception=0; // variable de réception octet
long nombreReception=0; // déclare variable long stocker nombre recu
//----- constantes de paramétrage du servomoteur ----
const int posMin=550; // largeur impulsion en μs correspondant à la
//position 0° du servomoteur
const int posMax=2350; // largeur impulsion en μs correspondant à la
//position 180° du servomoteur
const int brocheServo=2; // broche du servomoteur
Servo servo; // déclaration d'un objet servomoteur
int angleServo=0; // variable de position du servomoteur
int angleServo0=0; // variable pour mémoriser la dernière position du
//servomoteur
int vitesse=50; // vitesse de positionnement entre 2 pas - en ms - entre
//5 et 100ms

void setup() {//--- la fonction setup() : exécutée au début et 1 seule
//fois
Serial.begin(115200); // initialise la vitesse de la connexion série
//-- utilise la meme vitesse dans le Terminal Série
servo.attach(brocheServo, posMin, posMax); // attache le servomoteur
//à la broche
servo.write(angleServo); // positionne le servomoteur à l'angle voulu
// initial =0°
angleServo0=angleServo; // mémorise la position courante du
//servomoteur
} // fin de la fonction setup()

void loop() { //--- la fonction loop() : exécutée en boucle sans fin
while (Serial.available()>0) { // si un caractère en réception
octetReception=Serial.read(); // lit le 1er octet de la file
//d'attente
if (octetReception==10) { // si Octet reçu est le saut de ligne
Serial.print ("Saut de ligne recu : ");
Serial.print ("Nombre recu = "); // affiche la le nombre reçu
Serial.println (nombreReception);
angleServo=nombreReception;
// servo.write(angleServo); // positionne le servomoteur à
//l'angle voulu
servoTo(servo, angleServo0, angleServo, vitesse);//--- fonction de positionnement progressif du servomoteur par pas fixe
de n degrés-----
angleServo0=angleServo; // mémorise la nouvelle position
Serial.print ("Angle = ");
Serial.print (angleServo); // --- affiche la valeur de l'angle
//utilisé
Serial.println (" degres");
nombreReception=0; //RAZ le String de réception
delay(10); // pause
break; // sort de la boucle while
} // fin if
else { // si le caractère reçu n'est pas un saut de ligne
octetReception=octetReception-48; // transfo valeur ASCII en
//valeur décimale
// calcul du nombre à partir des valeurs reçues
if ((octetReception>=0)&&(octetReception<=9)) nombreReception
= (nombreReception*10)+octetReception;
else Serial.println("La chaine n'est pas un nombre valide !");
delay(1); // laisse le temps au caractères d'arriver
} // fin else
} // fin while - fin de réception de la chaine
} // fin de la fonction loop()

void servoTo( Servo toServo, int fromAngle, int toAngle, int
toVitesse ) {
int delta=toAngle-fromAngle; // variation d'angle
Serial.print(F("delta = ")), Serial.println(delta);
if (delta>=0) { // si variation positive
for (int i=0; i<delta; i++) { // defile n positions pour atteindre
angle final dans sens positif
fromAngle=fromAngle+1; // ajoute cran
toServo.write(fromAngle); // crée impulsion à partir valeur
angle - plus précis que write()
Serial.print("angle courant servo = "),
Serial.println(fromAngle);
delay(toVitesse); // pause entre chaque positionnement
} // fin for
} // fin if
else { // si variation négative
for (int i=-delta; i>0; i--) { // defile n positions pour
atteindre angle final dans sens négatif
fromAngle=fromAngle-1; // ajoute cran
toServo.write(fromAngle); // crée impulsion à partir valeur
angle - plus précis que write()
Serial.print("angle courant servo = "),
Serial.println(fromAngle);
delay(toVitesse); // pause entre chaque positionnement
} // fin for
} // fin else
} // fin fonction servoTo


