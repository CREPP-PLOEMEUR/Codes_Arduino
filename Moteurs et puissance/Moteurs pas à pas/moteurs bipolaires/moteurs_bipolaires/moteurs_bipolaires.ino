  #include <Stepper.h> //Inclusion de la bibliothèque Stepper
  
  int nbPas = 2048; //Nombre de pas pour le moteur 28BYJ-48
  
  #define IN1 8  //Broche IN1
  #define IN2 9  //Broche IN2
  #define IN3 10  //Broche IN3
  #define IN4 11  //Broche IN4

  //int IN1 = 8;
  
  Stepper moteur(nbPas, IN1, IN3, IN2, IN4); //Création de l'objet moteur
     
    void setup() {
  
      moteur.setSpeed(5); //On définit la vitesse à 10 tr/min
  
    }//Fin setup
     
    void loop() {
  
      moteur.step(nbPas);   //On avance de nbPas pas, c'est à dire un tour complet (sens horaire)
      delay(2000);          //pause de 2s
      moteur.step(-nbPas);  //On avance de -nbPas pas, c'est à dire un tour complet (sens anti-horaire)
      delay(2000);          //pause de 2s
  
    }//Fin loop
