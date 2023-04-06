
//--- Programme pour le controle de 2 servomoteurs à rotation continue
// par le Terminal Serie
// par X. HINAULT - Tous droits réservés - licence GPL v3 - www.mon-club-elec.fr

//--- entete déclarative = variables et constantes globales 

//---- inclusion des librairies
#include <Servo.h> // inclut la librairie Servo

#include <RunF.h> // inclusion de la librairie
// disponible ici : http://code.google.com/p/arduino-runf-library/downloads/list 
// article ici : http://makerspace56.org/WordPress3/communication-du-pc-vers-arduino/

//---- déclaration obligatoire des fonctions à recevoir sur le port Série 
typedef void (*typeF)(long*, int); // déclaration de type nécessaire pour la fonction
char *listFname[] = {"stop", "avantD", "avantG", "arriereD", "arriereG", "enAvant", "enArriere", "tourneD", "tourneG", "testServoD", "testServoG" }; 
// liste des nom de fonctions reçues sur le port série nomFonction(param1, param2, ., paramN)
typeF listF[] = {codeStop, codeAvantD, codeAvantG, codeArriereD, codeArriereG, codeEnAvant, codeEnArriere, codeTourneD, codeTourneG, testServoD, testServoG}; 
// liste du nom des fonctions du code correspondantes

RunF receptionSerie(listF, listFname); // déclaration de l'objet racine RunF utilisé par le programme 

//--- variables et constantes pour les servomoteurs
const int Droit=0; // servo Droit a l'indice 0
const int Gauche=1; // servo Droit a l'indice 1

/* futaba RC 
const int neutre=1480; // largeur impulsion arret 
const int maxAV[2]={1230,1730}; // largeur impulsion vitesse max en avant
const int maxAR[2]={1730,1230}; // largeur impulsion vitesse max en arriere
*/

 
const int neutre=1430; // largeur impulsion arret 
const int maxAV[2]={1130,1730}; // largeur impulsion vitesse max en avant
const int maxAR[2]={1730,1130}; // largeur impulsion vitesse max en arriere


//const int brocheServo[2]={2,3}; // broches des servomoteur 
const int brocheServo[2]={14,15}; // broches des servomoteur - CD Simple Bot

//int impulsServo=0; // largeur impulsion servomteur en µsecondes

Servo servo[2]; // déclaration d'un objet servomoteur



//--- la fonction setup() : exécutée au début et 1 seule fois
void setup() {

   Serial.begin(115200); // initialise la vitesse de la connexion série
   //-- utilise la meme vitesse dans le Terminal Série
   // IMPORTANT : sélectionner l'option "No Line Ending" dans le Terminal Serie !

  
   Serial.println("--- Instructions reconnues: ---"); 
   Serial.println("stop()");  
   Serial.println("avantD() | avantD(vitesse%)");  
   Serial.println("avantG() | avantG(vitesse%)");  
   Serial.println("arriereD() | arriereD(vitesse%)");  
   Serial.println("arriereG() | arriereG(vitesse%)");  
   Serial.println("enAvant() | enAvant(vitesse%)");  
   Serial.println("enArriere() | enArriere(vitesse%)");  
   Serial.println("tourneD() | tourneD(vitesse%)");  
   Serial.println("tourneG() | tourneG(vitesse%)"); 
   Serial.println("testServoD(largeurmicros)");  
   Serial.println("testServoG(largeurmicros)");  
   Serial.println("-------------------------------");  

  
} // fin de la fonction setup()


//--- la fonction loop() : exécutée en boucle sans fin 
void loop() {

  receptionSerie.waiting(); // lecture des caractères en réception sur le port série 


} // fin de la fonction loop()


//============== fonctions des mouvements de base des servomoteurs ================

//----- fonction de controle de la vitesse avant d'un servomoteur
void servoAvant(int indiceServo, int vitesseIn) {
// -- vitesse entre 10 et 100% --  
 
     int impulsServo; // variable locale 
     
     servo[indiceServo].attach(brocheServo[indiceServo]); // attache le servomoteur à la broche
     
     impulsServo=map(vitesseIn, 0, 100, neutre, maxAV[indiceServo]); // calcul largeur impulsion AV correspondante
     servo[indiceServo].writeMicroseconds(impulsServo); 
     delay(10); // pause 

  
} // fin servoAvant 


//----- fonction de controle de la vitesse arriere d'un servomoteur
void servoArriere(int indiceServo, int vitesseIn) {
// -- vitesse entre 10 et 100% --  
 
     int impulsServo; // variable locale 
     
     servo[indiceServo].attach(brocheServo[indiceServo]); // attache le servomoteur à la broche
     
     impulsServo=map(vitesseIn, 0, 100, neutre, maxAR[indiceServo]); // calcul largeur impulsion AV correspondante
     servo[indiceServo].writeMicroseconds(impulsServo); 
     delay(10); // pause 

  
} // fin servoArriere

//============= fonctions de mouvements synchrones des 2 moteurs ===================

void enAvant(int vitesseIn) { // met les 2 moteurs en avant
// vitesse entre 10 et 100%
  
  servoAvant(Droit, vitesseIn); // moteur Droit
  servoAvant(Gauche, vitesseIn); // moteur Gauche
  
} // fin en avant 

void enArriere(int vitesseIn) { // met les 2 moteurs en arriere
// vitesse entre 10 et 100%
  
  servoArriere(Droit, vitesseIn); // moteur Droit
  servoArriere(Gauche, vitesseIn); // moteur Gauche
  
} // fin en arriere

void tourneDroite(int vitesseIn) { // tourne à droite
// vitesse entre 10 et 100%
  
  servoArriere(Droit, vitesseIn); // moteur Droit
  servoAvant(Gauche, vitesseIn); // moteur Gauche
  
} // fin en tourne droite

void tourneGauche(int vitesseIn) { // tourne à gauche
// vitesse entre 10 et 100%
  
  servoAvant(Droit, vitesseIn); // moteur Droit
  servoArriere(Gauche, vitesseIn); // moteur Gauche
  
} // fin tourne gauche

void servosStop() { // arret des 2 moteurs 
   servo[Droit].detach(); // met le servomoteur à l'arret
   servo[Gauche].detach(); // met le servomoteur à l'arret 
}

//============= code des fonctions de controle recues sur le port Série ===============


//---- fonction codeStop
void codeStop(long *vars, int qt) { // vars est le tableau de paramètres et qt leur nombre
  
  if (qt==0) { // si aucun paramètre recu
    Serial.println("Arret moteurs"); 
    servosStop(); 
  }
  else Serial.println("Fonction non valide ! "); 

} // --- fin codeStop

//---- fonction codeAvantD
void codeAvantD(long *vars, int qt) { // vars est le tableau de paramètres et qt leur nombre

  if (qt==0) { // si aucun paramètre recu
    Serial.println("Moteur D en Avant a la vitesse 100 "); 
    servoAvant(Droit, 100);
  }
  else  if (qt==1) { // si 1 paramètre recu
    Serial.print("Moteur D en Avant a la vitesse : "); 
    Serial.println(constrain(vars[0],0,100)); // 1er paramètre - oblige valeur 0-100
    servoAvant(Droit,constrain(vars[0],0,100));
  }
  else Serial.println("Fonction non valide ! "); 
  

} // --- fin codeAvantD

//---- fonction codeAvantG
void codeAvantG(long *vars, int qt) { // vars est le tableau de paramètres et qt leur nombre

  if (qt==0) { // si aucun paramètre recu
    Serial.println("Moteur G en Avant a la vitesse 100 "); 
    servoAvant(Gauche, 100);
  }
  else  if (qt==1) { // si 1 paramètre recu
    Serial.print("Moteur G en Avant a la vitesse : "); 
    Serial.println(constrain(vars[0],0,100)); // 1er paramètre - oblige valeur 0-100
    servoAvant(Gauche,constrain(vars[0],0,100));
  }
  else Serial.println("Fonction non valide ! "); 
  

} // --- fin codeAvantG 

//---- fonction  codeArriereD
void  codeArriereD(long *vars, int qt) { // vars est le tableau de paramètres et qt leur nombre
  
    if (qt==0) { // si aucun paramètre recu
    Serial.println("Moteur D en Arriere a la vitesse 100 "); 
    servoArriere(Droit, 100);
  }
  else  if (qt==1) { // si 1 paramètre recu
    Serial.print("Moteur D en Arriere a la vitesse : "); 
    Serial.println(constrain(vars[0],0,100)); // 1er paramètre - oblige valeur 0-100
    servoArriere(Droit,constrain(vars[0],0,100));
  }
  else Serial.println("Fonction non valide ! "); 



} // --- fin  codeArriereD

//---- fonction codeArriereG 
void codeArriereG(long *vars, int qt) { // vars est le tableau de paramètres et qt leur nombre
  
    if (qt==0) { // si aucun paramètre recu
    Serial.println("Moteur G en Arriere a la vitesse 100 "); 
    servoArriere(Gauche, 100);
  }
  else  if (qt==1) { // si 1 paramètre recu
    Serial.print("Moteur G en Arriere a la vitesse : "); 
    Serial.println(constrain(vars[0],0,100)); // 1er paramètre - oblige valeur 0-100
    servoArriere(Gauche,constrain(vars[0],0,100));
  }
  else Serial.println("Fonction non valide ! "); 



} // --- fin codeArriereG

//---- fonction codeEnAvant
void codeEnAvant(long *vars, int qt) { // vars est le tableau de paramètres et qt leur nombre
  
    if (qt==0) { // si aucun paramètre recu
    Serial.println("Moteur D et G en Avant a la vitesse 100 "); 
    enAvant(100);
  }
  else  if (qt==1) { // si 1 paramètre recu
    Serial.print("Moteur D et G en Avant a la vitesse : "); 
    Serial.println(constrain(vars[0],0,100)); // 1er paramètre - oblige valeur 0-100
    enAvant(constrain(vars[0],0,100));
  }
  else Serial.println("Fonction non valide ! "); 


} // --- fin codeEnAvant

//---- fonction codeEnArriere 
void codeEnArriere(long *vars, int qt) { // vars est le tableau de paramètres et qt leur nombre
  
    if (qt==0) { // si aucun paramètre recu
    Serial.println("Moteur D et G en Arriere a la vitesse 100 "); 
    enArriere(100);
  }
  else  if (qt==1) { // si 1 paramètre recu
    Serial.print("Moteur D et G en Arriere a la vitesse : "); 
    Serial.println(constrain(vars[0],0,100)); // 1er paramètre - oblige valeur 0-100
    enArriere(constrain(vars[0],0,100));
  }
  else Serial.println("Fonction non valide ! "); 


} // --- fin codeEnArriere


//---- fonction codeTourneD
void codeTourneD (long *vars, int qt) { // vars est le tableau de paramètres et qt leur nombre
  
    if (qt==0) { // si aucun paramètre recu
    Serial.println("Tourne vers la Droite a la vitesse 100 "); 
    tourneDroite(100);
  }
  else  if (qt==1) { // si 1 paramètre recu
    Serial.print("Tourne vers la Droite a la vitesse : "); 
    Serial.println(constrain(vars[0],0,100)); // 1er paramètre - oblige valeur 0-100
    tourneDroite(constrain(vars[0],0,100));
  }
  else Serial.println("Fonction non valide ! "); 


} // --- fin codeTourneD

//---- fonction codeTourneG
void codeTourneG(long *vars, int qt) { // vars est le tableau de paramètres et qt leur nombre
  
    if (qt==0) { // si aucun paramètre recu
    Serial.println("Tourne vers la Gauche a la vitesse 100 "); 
    tourneGauche(100);
  }
  else  if (qt==1) { // si 1 paramètre recu
    Serial.print("Tourne vers la Gauche a la vitesse : "); 
    Serial.println(constrain(vars[0],0,100)); // 1er paramètre - oblige valeur 0-100
    tourneGauche(constrain(vars[0],0,100));
  }
  else Serial.println("Fonction non valide ! "); 


} // --- fin codeTourneG


//---- fonction testServoD 
void testServoD(long *vars, int qt) { // vars est le tableau de paramètres et qt leur nombre
  
  if (qt==1) { // si 1 paramètre recu
    Serial.print("Largeur impulsion servo Droit = "); 
    Serial.print(vars[0]); 
    Serial.println(" microsecondes."); 
    
    servo[Droit].attach(brocheServo[Droit]); // attache le servomoteur à la broche
    servo[Droit].writeMicroseconds(vars[0]); 
  }
  else Serial.println("Fonction non valide ! "); 

} // --- fin testServoD


//---- fonction testServoG 
void testServoG(long *vars, int qt) { // vars est le tableau de paramètres et qt leur nombre
  
  if (qt==1) { // si 1 paramètre recu
    Serial.print("Largeur impulsion servo Gauche = "); 
    Serial.print(vars[0]); 
    Serial.println(" microsecondes."); 
    
    servo[Gauche].attach(brocheServo[Gauche]); // attache le servomoteur à la broche
    servo[Gauche].writeMicroseconds(vars[0]); 
  }
  else Serial.println("Fonction non valide ! "); 

} // --- fin testServoG 

// NB : les lignes précédées de // sont des commentaires
