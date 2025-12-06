#ifndef PROJET_H
#define PROJET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define MAX_NOM 50
#define FICHIER_SCORE "scores.txt"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KCYN  "\x1B[36m"


typedef struct NoeudNombre {
    int valeur;
    struct NoeudNombre *suivant;
} NoeudNombre;

typedef struct NoeudJoueur {
    char nom[MAX_NOM];
    int score;
    struct NoeudJoueur *gauche;
    struct NoeudJoueur *droite;
} NoeudJoueur;

void nettoyerEcran();
void banniere(const char* titre);
void viderBuffer();
int lireEntier(const char* message);
void pause();

NoeudJoueur* chargerClassement();
NoeudJoueur* insererJoueur(NoeudJoueur* racine, const char* nom, int score);
void afficherClassementTrie(NoeudJoueur* racine); 
void sauvegarderClassement(NoeudJoueur* racine);
void sauvegarderJoueur(NoeudJoueur* noeud, FILE* f);
void libererABR(NoeudJoueur* racine); 

int defi_LeCompteEstBon_Interactif(); 
int defi_Mastermind();
int defi_Labyrinthe();
int defi_TriUltime();
int defi_VoyageurDeCommerce();

NoeudNombre* ajouterNoeud(NoeudNombre* tete, int valeur);
NoeudNombre* supprimerNoeud(NoeudNombre* tete, int valeur_a_supprimer, bool* trouve);
void libererListe(NoeudNombre* tete);

#endif 
