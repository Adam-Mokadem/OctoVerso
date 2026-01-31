#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "jeu.h"

#define TAILLE_MAIN 12  
#define TAILLE_MAIN_MAX 16
#define TAILLE_RAIL 8  
#define TAILLE_MAX_MOT 15  // Le mot le plus grand du dictionnaire "ABANDONNASSIONS"
#define NOMBRE_LETTRES 88  
#define JOUEUR_1 1  
#define JOUEUR_2 2
#define MAX_MOTS_UTILISES 100  // Nombre maximum de mots utilisés


int main() {
    // Déclaration des mains des joueurs  
    char main1[TAILLE_MAIN_MAX], main2[TAILLE_MAIN_MAX], rail_recto[TAILLE_RAIL + 1], rail_verso[TAILLE_RAIL + 1];
    int tour_compteur = 0;
    // Distribuer les chevalets et trier les mains  
    distribuer_chevalets(main1, main2);

    // Afficher les mains des joueurs  
    afficher_main(main1, main2);

    // Déclarer les mots des joueurs  
    char mot1[TAILLE_MAX_MOT + 1], mot2[TAILLE_MAX_MOT + 1]; // TAILLE_MAX_MOT pour le mot + '\0'

    // Demander aux joueurs de saisir des mots  
    saisir_mot(mot1, main1, JOUEUR_1, tour_compteur);
    saisir_mot(mot2, main2, JOUEUR_2, tour_compteur);

    // Supprimer les lettres utilisées  
    supprimer_lettres_utilisees(mot1, main1);
    supprimer_lettres_utilisees(mot2, main2);

    // Afficher les mains mises à jour des joueurs  
    afficher_main(main1, main2);

    // Créer et afficher les rails  
    creer_rails(mot1, mot2, rail_recto, rail_verso);

    while (1 == 1) {
        // Gérer le passage de tour  
        tour_compteur = tour(mot1, mot2, tour_compteur);

        if (tour_compteur == 1) {
            jeu(rail_recto, rail_verso, main1, main2, tour_compteur);
            if (fin_de_jeu(main1) == 1) {
                printf("Bravo, le joueur 1 a gagne !");
                return 0;
            }
        }
        else if (tour_compteur == 2) {
            jeu(rail_recto, rail_verso, main2, main1, tour_compteur);
            if (fin_de_jeu(main2) == 1) {
                printf("Bravo, le joueur 2 a gagne !");
                return 0;
            }
        }


    }
}