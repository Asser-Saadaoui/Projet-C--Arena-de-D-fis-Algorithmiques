#include "projet.h"

int main() {
    srand(time(NULL));
    nettoyerEcran();

    // Chargement de l'ABR des scores au demarrage
    NoeudJoueur* classement_racine = chargerClassement();

    char nomJoueur[MAX_NOM];
    int scoreTotal = 0;
    int choix;

    printf("Entrez votre pseudo : ");
    // scanf("%s") lit uniquement les caracteres jusqu'au premier espace (ou saut de ligne),
    // ce qui assure que l'entree est simple et non accentuee.
    if (scanf("%s", nomJoueur) != 1) {
        strcpy(nomJoueur, "Invite");
    }
    viderBuffer();

    do {
        banniere("ARENA DE DEFIS ALGORITHMIQUES");
        printf(KGRN "Joueur: %s" KNRM " | Score total: %d pts\n\n", nomJoueur, scoreTotal);
        printf("1. Defi 1 : Le Compte est Bon \n");
        printf("2. Defi 2 : Mastermind\n");
        printf("3. Defi 3 : Course de Robot\n");
        printf("4. Defi 4 : Tri Ultime\n");
        printf("5. Defi 5 : Voyageur de Commerce\n");
        printf("6. Afficher le Classement\n");
        printf("0. Quitter le jeu\n\n");

        printf("Votre choix : ");
        // On utilise une methode robuste pour lire l'entier et vider le buffer
        if (scanf("%d", &choix) != 1) {
            // Si scanf ne lit pas un nombre (echec), on vide le buffer et on force un choix invalide
            viderBuffer();
            choix = -1;
        } else {
            // Si scanf lit un nombre, il faut vider le reste du buffer (le '\n')
            viderBuffer();
        }

        int pointsGagnes = 0;

        switch(choix) {
            case 1: pointsGagnes = defi_LeCompteEstBon_Interactif(); break;
            case 2: pointsGagnes = defi_Mastermind(); break;
            case 3: pointsGagnes = defi_Labyrinthe(); break;
            case 4: pointsGagnes = defi_TriUltime(); break;
            case 5: pointsGagnes = defi_VoyageurDeCommerce(); break;

            case 6:
                banniere("CLASSEMENT GENERAL");
                printf(KCYN "%-20s | %s\n", "JOUEUR", "SCORE");
                printf("---------------------------\n" KNRM);
                if (classement_racine == NULL) {
                    printf(KYEL "Aucun score enregistre pour le moment.\n" KNRM);
                } else {
                    afficherClassementTrie(classement_racine);
                }
                pause();
                break;

            case 0: break;
            default: printf(KRED "Choix invalide.\n" KNRM); pause(); break;
        }

        if (pointsGagnes > 0) {
            printf(KGRN "\nVous gagnez %d points !\n" KNRM, pointsGagnes);
            scoreTotal += pointsGagnes;
            pause();
        }

    } while (choix != 0);

    // Sauvegarde et Nettoyage Final de l'ABR
    if (scoreTotal > 0) {
        printf("\nAjout du score de %s (%d) au classement.\n", nomJoueur, scoreTotal);

        classement_racine = insererJoueur(classement_racine, nomJoueur, scoreTotal);

        sauvegarderClassement(classement_racine);
    }

    printf(KBLU "\nMerci d'avoir joue ! Au revoir.\n" KNRM);

    libererABR(classement_racine);

    return 0;
}
