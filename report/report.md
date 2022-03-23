# Labo 2 HPC

Florian Gazzetta

Pour tester les différentes améliorations apportée au programme, j'ai utilisé un graphique ou j'ai fait la moyenne de plusieurs essai pour chaque taille de fichier. Après avoir fait plusieurs essais, je n'ai pas remarqué de différences entre la première éxécution et les suivantes sur un fichier. Une solution pour améliorer les performances mais qui n'a pas été mise en place serait de supprimer les test d'erreurs et les messages d'informantion mais cette solution n'as pas été utilisée car elle rendrait l'application extremement instable et ce ne serait plus possible d'identifier la cause des erreurs.

## Stratégie 1 : Augmenter la taille des buffers

La première stratégie qui a été mise en place est d'utiliser des buffers plus grands pour les appels système dans le but d'éviter de multiplier les appels système. Actuellement les buffer ne peuvent contenir qu'un élément mais on va les augmenter a une taille de 1024.

## Stratégie 2 : Utilisation de fread, fclose, fopen et fwrite

Une autre alternative serait d'utiliser la fonction fread pour lire le fichier, car elle peut etre plus rapide. De la même maniere, on utilise fclose, fopen et fwrite. Après avoir fait des tests, on ne remarque pas de changements significatifs avec cette méthode.

## Stratégie 3 : Utiliser des pipes plutot que des sockets

Une autre stratégie serait d'utiliser des pipe plutot que des sockets pour la communication entre les processus. Après avoir fait des tests, on ne remarque pas de changements significatifs avec cette méthode.

## Conclusion

On remarque que la principale méthode pour gagner des performances est d'augmenter la taille du buffer de lecture et que les autres méthode n'apportent pas de changement significatifs

## Annexe : Résultat des mesures

Le tableau suivant récapitule le temps d'éxécution moyen des différentes stratégie sur des fichiers de taille différentes. Le temps d'éxécution est en secondes.

| Taille du fichier | 1024  | 8192  | 32 768 |
|-------------------|-------|-------|--------|
| Etat initial      | 0,22  | 1,89  | 7,3    |
| Stratégie 1       | 0,005 | 0,009 | 0,019  |
| Stratégie 2       | 0,006 | 0,008 | 0,020  |
| Stratégie 3       | 0,005 | 0,009 | 0,020  |
