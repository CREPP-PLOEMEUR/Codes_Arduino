// -----Positionner 1 servomoteur via le Terminal série-----

//---- inclusion de librairie
#include <Servo.h> // inclut la librairie Servo

//--- entete déclarative = variables et constantes globales
int octetReception=0; // variable de réception octet
long nombreReception=0; // déclare variable long stocker nombre recu
const int brocheServo=2; // broche du servomoteur
Servo servo; // déclaration d'un objet servomoteur

void setup() 
{
    Serial.begin(115200); // initialise la vitesse de la connexion série
    //-- utilise la meme vitesse dans le Terminal Série
    servo.attach(brocheServo); // attache le servomoteur à la broche

} // fin de la fonction setup()



void loop() 
{ 

    while (Serial.available()>0) 
    { // si un caractère en réception
        
        octetReception=Serial.read(); // lit le premier octet de la file d'attente
        
        if (octetReception==10) 
        { // si Octet reçu est le saut de ligne
        
            Serial.print ("Saut de ligne recu : ");
            Serial.print ("Nombre recu = "); // affiche la le nombre reçu
            Serial.println (nombreReception);
            servo.writeMicroseconds(nombreReception);
            Serial.print ("Largeur impulsion servomoteur = ");
            Serial.print (nombreReception);
            Serial.println (" microsecondes");
            nombreReception=0; //RAZ le String de réception
            delay(10); // pause
            break; // sort de la boucle while
        } // fin if
        else 
        { // si le caractère reçu n'est pas un saut de ligne
            octetReception=octetReception-48; // transfo valeur ASCII en valeur décimale
            // calcul du nombre à partir des valeurs reçues
            if ((octetReception>=0)&&(octetReception<=9)) 
            {
                nombreReception = (nombreReception*10)+octetReception;
            }
            else 
            {
                Serial.println("La chaine n'est pas un nombre valide !");
            }
 
        } // fin else
    } // fin while - fin de réception de la chaine
} // fin de la fonction loop()