#ifndef PROJET_H
#define PROJET_H

// Librairies standard
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

// Constantes
#define MAX_NOM 50
#define FICHIER_SCORE "scores.txt"
#define TAILLE_LABY 10

// Codes couleurs ANSI
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KCYN  "\x1B[36m"

// --- STRUCTURES DYNAMIQUES ---

// 1. Noeud pour le Defi 1 (Liste chainee)
typedef struct NoeudNombre {
    int valeur;
    struct NoeudNombre *suivant;
} NoeudNombre;

// 2. Noeud pour la Tache Classement (Arbre Binaire de Recherche - ABR)
typedef struct NoeudJoueur {
    char nom[MAX_NOM];
    int score;
    struct NoeudJoueur *gauche;
    struct NoeudJoueur *droite;
} NoeudJoueur;

// --- PROTOTYPES UTILITAIRES ---
void nettoyerEcran();
void banniere(const char* titre);
void viderBuffer();
int lireEntier(const char* message);
void pause();

// --- PROTOTYPES GESTION SCORES (Utilisation de l'ABR) ---
NoeudJoueur* chargerClassement();
NoeudJoueur* insererJoueur(NoeudJoueur* racine, const char* nom, int score);
void afficherClassementTrie(NoeudJoueur* racine); // Affichage in-order (ABR trie)
void sauvegarderClassement(NoeudJoueur* racine);
void sauvegarderJoueur(NoeudJoueur* noeud, FILE* f);
void libererABR(NoeudJoueur* racine); // Nettoyage de la memoire

// --- PROTOTYPES DEFIS ---
int defi_LeCompteEstBon_Interactif(); // Utilise la Liste chainee
int defi_Mastermind();
int defi_Labyrinthe();
int defi_TriUltime();
int defi_VoyageurDeCommerce();

// --- PROTOTYPES LISTE CHAINEE (Compte est Bon) ---
NoeudNombre* ajouterNoeud(NoeudNombre* tete, int valeur);
NoeudNombre* supprimerNoeud(NoeudNombre* tete, int valeur_a_supprimer, bool* trouve);
void libererListe(NoeudNombre* tete);
// =========================================================
// FICHIER : projet.h
// =========================================================

// ... Vos autres prototypes ...

// Pour le Défi 3 (Labyrinthe Aléatoire)
#define TAILLE_LABY 10
void genererLabyrinthe(int map[TAILLE_LABY][TAILLE_LABY]); // NOUVEAU PROTOTYPE
int defi_Labyrinthe(); // Mise à jour pour la version aléatoire



#endif // PROJET_H
