# 🎮 Arena de Défis Algorithmiques

## 📋 Vue d'ensemble

**Arena de Défis Algorithmiques** est une plateforme interactive en console, développée en C. Le projet a pour but de tester et d'améliorer les compétences en algorithmique et en manipulation de structures de données dynamiques (Listes Chaînées, Arbres Binaires de Recherche).

Le programme propose **cinq défis**, un système de scoring et un classement persistant des joueurs.

---

## 🚀 Les Défis Implémentés

| Choix | Défi | Concepts Clés |
| :---: | :--- | :--- |
| **1** | Le Compte est Bon | **Listes Chaînées** (Gestion dynamique des nombres), Parsing d'expression. |
| **2** | Mastermind Algorithmique | Logique de comparaison, Validation stricte de la saisie (Max 4 chiffres). |
| **3** | Course de Robots | Parcours de matrice, Simulation de mouvement. |
| **4** | Tri Ultime | Algorithmes de tri interactifs . |
| **5** | Voyageur de Commerce (Bonus) | Optimisation, Calcul de distance . |

### Fonctionnalités de Jeu

* **Quitter un Défi :** Dans les défis 1 et 2, tapez **`quit`** ou **`quitter`** à tout moment pour abandonner et revenir au menu principal.
* **Contrainte de Saisie :** Le pseudo du joueur doit être en caractères **ASCII simples** (sans accent ni espace) pour garantir la compatibilité lors de la sauvegarde du classement.

---

## 🏆 Classement et Scores

### Gestion des Scores

Le classement est géré en mémoire via un **Arbre Binaire de Recherche (ABR)**, ce qui permet de trier efficacement les joueurs par score décroissant.

| Fonctionnalité | Implémentation |
| :--- | :--- |
| **Structure** | `NoeudJoueur` dans un ABR (trie par `score`). |
| **Persistance** | Chargement et sauvegarde dans le fichier `scores.txt`. |
| **Affichage** | Parcours In-Order inversé de l'ABR pour afficher le classement du meilleur au moins bon score. |

### Calcul du Score

Le score est accumulé sur l'ensemble des défis réussis. La note obtenue pour chaque défi dépend du résultat final et du nombre de coups ou d'étapes réalisés.

---

## 🛠️ Compilation et Exécution

### Prérequis

* Un compilateur C (GCC recommandé).

### Étapes

1.  **Compiler le projet :**
    Utilisez la commande suivante pour compiler les deux fichiers source (`main.c` et `fonctions.c`) et lier la librairie mathématique (`-lm`).
    ```bash
    gcc main.c fonctions.c -o arena -lm
    ```

2.  **Exécuter :**
    ```bash
    ./arena
    ```

---

## 📁 Structure des Fichiers

| Fichier | Rôle |
| :--- | :--- |
| `main.c` | Point d'entrée, gestion du menu principal, affichage des scores totaux, et intégration de la logique de l'ABR (`chargerClassement`, `sauvegarderClassement`). |
| `fonctions.c` | Contient l'implémentation de **tous les défis (1 à 5)**, les fonctions utilitaires (e.g., `viderBuffer`), la logique de la Liste Chaînée, et l'implémentation complète de l'ABR. |
| `projet.h` | Fichier d'en-tête, définissant les structures dynamiques (`NoeudNombre`, `NoeudJoueur`) et tous les prototypes de fonctions. |
| `scores.txt` | Fichier de données texte pour le stockage persistant du classement. |

---

## 👨‍💻 Auteurs

* **Développeurs :** Mouheb Hajjej / Ahmed Boufrikha / Asser Saadaoui
* **École :** ENSI (École Nationale des Science Informatique)
* **Année :** 2025
