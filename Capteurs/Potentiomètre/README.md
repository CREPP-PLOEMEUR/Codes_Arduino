# Potentiomètre

## Principe

Le curseur du potentiomètre fait varier la tension lue sur la broche Arduino.
Pour lire cette tension, il faut utiliser une des 6 broches analogiques (notée de A0 à A5).


Dans le programme Arduino, on utilise la fonction ```analogRead(Broche)``` qui va retourner un nombre compris entre 0 et 1023.


### Pourquoi 1023 ? 

Le composant utilisé par la carte Arduino est un Convertisseur Analogique Numérique (CAN) et convertie une tension en un nombre exprimé sur des puissances de 2 (2,4,8,16,32…)

- Un CAN est définie par sa résolution, c’est-à dire le nombre de bits sur lequel la tension est codée. 

- Dans le cas de l’Arduino, le CAN est sur 10 bits et 2^10 = 1024 or le 0 est inclus donc la valeur maximale est 1023.

Prenons un exemple : Le CAN est alimenté en 5V et possède une résolution de 10 bits.

- Si nous injectons une tension de 2.5V, le CAN va sortie la valeur 1023/2 = 512 (valeur retournée par la fonction ```analogRead```
- Si nous mettons 1 V en entrée d’une broche analogique, le CAN va sortie la valeur 1023/5 = 205

## Branchement

![Potentiomètre](pot.png)