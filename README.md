
# Projet de Chiffrement de Texte en C

Ce projet est une application écrite en C, permettant de chiffrer et déchiffrer des messages texte à l’aide de deux algorithmes classiques : César et Vigenère.
## Fonctionnalités

- **Entrée utilisateur** : Permet à l'utilisateur de saisir un message à chiffrer.
- **Conversion des caractères accentués** : Les caractères accentués sont automatiquement convertis pour éviter les problèmes liés à l'encodage.
- **Validation du texte** : Le texte est vérifié pour s'assurer qu'il contient uniquement des lettres et des espaces.
- **Chiffrement et déchiffrement** avec deux algorithmes :
  - **César** : Chiffrement par décalage des lettres.
  - **Vigenère** : Chiffrement polyalphabétique basé sur une clé de longueur variable.
- **Affichage clair** des textes chiffré et déchiffré pour une meilleure lisibilité.

## Compilation

### Prérequis
Assurez-vous d’avoir **`gcc`** installé sur votre machine. Si ce n'est pas le cas, vous pouvez l'installer via votre gestionnaire de paquets.

### Compilation du projet
Pour compiler le projet, exécutez la commande suivante dans le terminal :
```bash
make
```
Cela générera un exécutable nommé `main` dans le répertoire courant.

### Nettoyage du projet
Pour supprimer les fichiers objets et l'exécutable générés, utilisez la commande suivante :
```bash
make clean
```

## Exécution

Après avoir compilé le projet, vous pouvez exécuter l’application avec la commande suivante :
```bash
./main
```
Lancez le programme et suivez les instructions affichées dans le terminal pour saisir un message et choisir l'algorithme de chiffrement souhaité.

## Structure du projet

Voici un aperçu des principaux fichiers du projet :

- **`chiffrer.c`** : Contient le code source du programme avec les fonctions de chiffrement (César et Vigenère) et la gestion des caractères accentués.
- **`Makefile`** : Script de compilation automatique, permettant de créer facilement l'exécutable.
- **`README.md`** : Documentation du projet, contenant les informations sur la compilation, l'exécution et l'organisation du code.

## Auteur

- **CORBILLÉ Iris**
- **MUNKH-ERDENE Dulguun**

## Dépôt Git

Le code source complet du projet est disponible sur [GitHub](https://github.com/tonpseudo/ton-projet).
