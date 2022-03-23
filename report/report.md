# Labo 2 HPC

Florian Gazzetta

Pour tester les différentes améliorations apportée au programme, j'ai utilisé un graphique ou j'ai fait la moyenne de plusieurs essai pour chaque taille de fichier. Après avoir fait plusieurs essais, je n'ai pas remarqué de différences entre la première éxécution et les suivantes sur un fichier. Une solution pour améliorer les performances mais qui n'a pas été mise en place serait de supprimer les test d'erreurs et les messages d'informantion mais cette solution n'as pas été utilisée car elle rendrait l'application extremement instable et ce ne serait plus possible d'identifier la cause des erreurs.

## Stratégie 1 : Augmenter la taille des buffers

La première stratégie qui a été mise en place est d'utiliser des buffers plus grands pour les appels système dans le but d'éviter de multiplier les appels système. Actuellement les buffer ne peuvent contenir qu'un élément mais on va les augmenter a une taille de 1024.
