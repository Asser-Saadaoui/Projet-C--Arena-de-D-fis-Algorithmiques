# 🎮 Arena de Défis Algorithmiques

## 📋 Vue d'ensemble

**Arena de Défis Algorithmiques** est une plateforme interactive de programmation développée en C. Ce projet vise à faire apprendre la programmation et l'algorithmique de manière logique, interactive et compétitive.

La plateforme propose 5 défis algorithmiques stimulants, un système de scoring  et un classement des meilleurs programmeurs.

## 🚀 Les 5 Défis Proposés

### 1️⃣ **Le Compte est Bon** (100 points)
**Objectif**: Trouver une combinaison d'opérations mathématiques pour atteindre un nombre cible.

- **Entrée**: 6 nombres et un nombre cible
- **Sortie**: Une séquence d'opérations valide
- **Exemple**: Avec [2, 3, 5, 7, 10, 25] et cible 133 → "25*5=125, 125+10=135, 135-2=133"
- **Difficulté**: Moyen
- **Concepts**: Programmation dynamique, recherche, optimisation

### 2️⃣ **Mastermind Algorithmique** (75 points)
**Objectif**: Deviner une séquence secrète de nombres en un nombre minimum d'essais.

- **Mécanique**: À chaque essai, le système donne le nombre de:
  - ✓ Chiffres bien placés
  - ○ Chiffres corrects mais mal placés
- **Longueur**: 4 chiffres (0-9)
- **Difficulté**: Facile à Moyen
- **Concepts**: Heuristiques, feedback system, algorithmes de devinette

### 3️⃣ **Course de Robots** (150 points) ⭐
**Objectif**: Trouver le chemin le plus court dans un labyrinthe.

- **Entrée**: Une grille avec murs, départ et arrivée
- **Sortie**: La séquence de mouvements (N, S, E, O)
- **Algorithme**: BFS (Breadth-First Search)
- **Visualisation**: Affichage du parcours solution
- **Difficulté**: Facile, Moyen, Difficile
- **Concepts**: Pathfinding, BFS, représentation de graphes, files d'attente

### 4️⃣ **Tri Ultime** (80 points)
**Objectif**: Trier un tableau avec des contraintes spécifiques et minimiser les opérations.

- **Variantes**: Tri à bulles vs Tri rapide
- **Mesure**: Comptage du nombre de comparaisons et échanges
- **Difficulté**: Facile, Moyen, Difficile
- **Concepts**: Complexité algorithmique, analyse d'algorithmes, optimisation

### 5️⃣ **Générateur de Code** (120 points) 🎁
**Objectif**: Générer du code C efficace pour reproduire des patterns spécifiques.

- **Patterns**: Séquences répétitives, Fibonacci, nombres premiers, palindromes
- **Évaluation**: Efficacité du code, longueur minimale
- **Difficulté**: Facile, Moyen, Difficile
- **Concepts**: Programmation créative, optimisation de code, structures de données


## 🏆 Système de Score et Classement

### Calcul du Score
Les points sont attribués selon plusieurs critères:

Score = Base_Score - (Tentatives - 1) × 5 - (Temps / 10) + (Efficacité / 20)

**Où**:
- **Base_Score**: Points fixes selon la difficulté du défi
  - Défi 1: 100 points
  - Défi 2: 75 points
  - Défi 3: 150 points ⭐ (Défi le plus complexe)
  - Défi 4: 80 points
  - Défi 5: 120 points

- **Tentatives**: Nombre d'essais pour résoudre le défi
- **Temps**: Temps écoulé en secondes (pénalité 1 pt par 10 sec)
- **Efficacité**: Qualité de la solution (optimisation, approche)

### Sauvegarde et Leaderboard

Format de sauvegarde (leaderboard.txt):
Joueur;Score;D1;D2;D3;D4;D5;Date

Les scores sont:
- ✅ Sauvegardés automatiquement après chaque défi résolu
- ✅ Classés par ordre décroissant
- ✅ Affichés avec le top 20 des meilleurs programmeurs
- ✅ Disponibles par joueur avec statistiques détaillées

---

## 📁 Structure du Projet


├── main.c                 # Interface utilisateur principale
├── common.h/c             # Fonctions utilitaires partagées
├── defi_1.h/c             # Le Compte est Bon
├── defi_2.h/c             # Mastermind Algorithmique
├── defi_3.h/c             # Course de Robots
├── defi_4.h/c             # Tri Ultime
├── defi_5.h/c             # Générateur de Code
├── scoring.h/c            # Système de scoring et leaderboard
├── compile.bat            # Script compilation Windows
├── Makefile               # Configuration Make
├── leaderboard.txt        # Base de données des scores
└── README.md              # Cette documentation

### Fichiers Header (Interfaces)

| Fichier | Responsabilité |
|---------|-----------------|
| `common.h` | Structures de base, macros, utilitaires |
| `defi_1.h` | Interface du Défi 1 |
| `defi_2.h` | Interface du Défi 2 |
| `defi_3.h` | Interface du Défi 3 |
| `defi_4.h` | Interface du Défi 4 |
| `defi_5.h` | Interface du Défi 5 |
| `scoring.h` | Gestion des scores et classement |


## 📚 Architecture et Conception

### Modularité
Le projet est organisé en modules indépendants:
- Chaque défi a ses propres fichiers .h et .c
- Interfaces bien définies et réutilisables
- Code facile à maintenir et étendre

### Structures de Données Principales


//Joueur et résultats
typedef struct {
    char username[50];
    int score;
    int defi_1_score, defi_2_score, defi_3_score, defi_4_score, defi_5_score;
    time_t date;
} Player;

// Résultat d'un défi
typedef struct {
    int solved;              // Défi résolu ?
    int attempts;            // Nombre de tentatives
    int time_taken;          // Temps en secondes
    int efficiency_score;    // Score d'efficacité (0-100)
    char solution[200];      // Chaîne de la solution
} ChallengeResult;^


## 🎮 Guide d'Utilisation

### 1️⃣ Lancer l'Application
```bash
arena.exe        # Windows
```

### 2️⃣ Enregistrement
- Entrez votre nom d'utilisateur
- Ce nom sera utilisé pour tous vos scores

### 3️⃣ Menu Principal

1. Le Compte est Bon
2. Mastermind Algorithmique
3. Course de Robots
4. Tri Ultime
5. Générateur de Code
6. Afficher le Classement
7. Mes Statistiques
8. À propos
0. Quitter

### 4️⃣ Résoudre un Défi
- Lisez les instructions attentivement
- Proposez votre solution
- Le système évalue automatiquement
- Les points sont enregistrés

### 5️⃣ Consulter le Classement
- Voir le top 20 des meilleurs programmeurs
- Vérifier votre rang
- Analyser vos statistiques par défi

## 📈 Métriques et Statistiques

### Suivi des Performances
- ✅ Nombre de fois réussi par défi
- ✅ Meilleur temps
- ✅ Efficacité moyenne
- ✅ Progression dans le classement
- ✅ Score total

### Analyse de Performance

// Affichage des statistiques du joueur
display_player_statistics("Ahmed");

// Récupération du rang
int rank = get_player_rank("Ahmed");

## 🎓 Concepts Éducatifs

### Programmation C Avancée
- ✅ Structures et pointeurs
- ✅ Gestion mémoire dynamique
- ✅ Fichiers et sérialisation
- ✅ Algorithmes optimisés
- ✅ Conception modulaire


## 👨‍💻 Auteurs

**Développeur**: Mouheb Hajjej /Ahmed Boufrikha /Asser Saadaoui
**École**: ENSI (École Nationale des Science Informatique)
**Année**: 2025
**Niveau**: 1ere année Ingénieur Informatique
---

## 🎉 Conclusion

**Arena de Défis Algorithmiques** est une plateforme complète et professionnelle pour l'apprentissage pratique de la programmation. Elle combine l'éducation, la gamification et la compétition pour créer une expérience d'apprentissage motivante et engageante.

Que vous soyez étudiant cherchant à améliorer vos compétences en programmation ou passionné d'algorithmique, cette plateforme vous offre les outils et défis nécessaires pour exceller.

**Prêt à relever le défi?** 🚀

---

