# Notions avancées

## Principe

Les interruptions sont des fonctionnalitées avancées des microcontrôleurs : elles permettent de réagir à des évènements même lorsque le programme principale est occupé dans une tâche.

## Interêt

Dans certains cas, il est souhaitable de récuperer la valeur d'une broche à tout moment du programme, même quand celui ci est occupé dans une tâche et même dans une fonction de temporisation.

Pour remédier à ce problème, on peut utiliser les *broches d'interruption* qui permettent de récuperer la main sur l'ensemble du programme lorsque'un évènement survient sur une broche.

Concrètement, lorsque un évènement  ```e``` survient sur la broche ```b```, la fonction ```f``` est appelée, quelque soit l'état du programme principal. 

## Branchement

![Interruptions](Interruption.png)