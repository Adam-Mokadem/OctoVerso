#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define TAILLE_RAIL 8  

void afficher_rails(char* rail_recto, char* rail_verso) {
    printf("R : %s\n", rail_recto);
    printf("V : %s\n", rail_verso);
}

// Fonction pour créer et afficher les rails  
void creer_rails(const char mot1[], const char mot2[], char rail_recto[], char rail_verso[]) {

    rail_recto[0] = '\0';  

    if (strcmp(mot1, mot2) < 0) {
        strcpy_s(rail_recto, TAILLE_RAIL + 1, mot1);
        strcat_s(rail_recto, TAILLE_RAIL + 1, mot2);
    }
    else {
        strcpy_s(rail_recto, TAILLE_RAIL + 1, mot2);
        strcat_s(rail_recto, TAILLE_RAIL + 1, mot1);
    }

    // Créer le verso (inverser le rail)
    int len = strlen(rail_recto);
    for (int i = 0; i < len; i++) {
        rail_verso[i] = rail_recto[len - i - 1];
    }
    rail_verso[len] = '\0'; // Terminer la chaîne

    // Afficher les résultats  
    afficher_rails(rail_recto, rail_verso);
}

int entree_mot_droite(char* tmp, char* extremite, char* reste_mot) {
    int i = 0;
    for (; tmp[i + 1] != ')'; i++) {
        if (tmp[i + 1] == '\0' || i == TAILLE_RAIL - 1) {
            printf("erreur");
            return 0;
        }
        extremite[i] = tmp[i + 1];
    }
    if (i < 2) { // Quand seulement moins de 2 lettres déjà posées sont utilisées
        printf("erreur");
        return 0;
    }
    extremite[i] = '\0';

    int j = i + 2;
    for (; tmp[j] != '\0'; j++) {
        if ((j - (i + 2)) == (TAILLE_RAIL - 2)) {
            printf("erreur");
            return 0;
        }
        reste_mot[j - (i + 2)] = tmp[j];
    }
    reste_mot[j - (i + 2)] = '\0';
    return 1;
}

int entree_mot_gauche(char* tmp, char* reste_mot, char* extremite) {
    int i = 0;
    for (; tmp[i] != '('; i++) {
        if (tmp[i] == '\0' || i == TAILLE_RAIL - 2) {
            printf("erreur");
            return 0;
        }
        reste_mot[i] = tmp[i];
    }
    reste_mot[i] = '\0';

    int j = i + 1;
    for (; tmp[j] != ')'; j++) {
        if (tmp[j] == '\0' || j - (i + 1) == TAILLE_RAIL - 1) {
            printf("erreur");
            return 0;
        }
        extremite[j - (i + 1)] = tmp[j];
    }
    if (j < i + 3) { // Quand seulement moins de 2 lettres déjà posées sont utilisées
        printf("erreur");
        return 0;
    }
    extremite[j - (i + 1)] = '\0';
    return 1;
}

int verif_rail(int situation, int taille_extremite, char* rail, char* extremite, int compteur) {

    if (situation == 1) {
        for (int k = taille_extremite; rail[TAILLE_RAIL - k] != '\0'; k--) {
            if (rail[TAILLE_RAIL - k] == extremite[taille_extremite - k]) {
                compteur++;
            }
        }
    }

    if (situation == 2) {
        for (int k = 0; rail[k] != '\0'; k++) {
            if (rail[k] == extremite[k]) {
                compteur++;
            }
        }
    }
    return compteur;
}

void decalage_rail_vers_gauche(int taille_reste_mot, char* lettre_a_donner, char* rail_cote_joueur,char* rail_cote_adversaire, char* nouveau_mot, int taille_nouveau_mot, char* stock) {
    int i = 0;
    for (; i != taille_reste_mot; i++) {
        lettre_a_donner[i] = rail_cote_joueur[i];
    }
    lettre_a_donner[i] = '\0';
    int j = 0;
    for (; j != TAILLE_RAIL - taille_nouveau_mot; j++) {
        stock[j] = rail_cote_joueur[j + taille_reste_mot];
    }
    stock[j] = '\0';
    i = 0;
    for (; stock[i] != '\0'; i++) {
        rail_cote_joueur[i] = stock[i];
    }
    j = 0;
    for (j = 0; nouveau_mot[j] != '\0'; j++) {
        rail_cote_joueur[i + j] = nouveau_mot[j];
    }
    rail_cote_joueur[i + j] = '\0';
    for (int k = 0; k < TAILLE_RAIL; k++) {
        rail_cote_adversaire[k] = rail_cote_joueur[TAILLE_RAIL - 1 - k];
    }
}

void decalage_rail_vers_droite(int taille_reste_mot, char* lettre_a_donner, char* rail_cote_joueur, char* rail_cote_adversaire, int taille_nouveau_mot, char* stock, int taille_extremite, char* nouveau_mot) {
    int i = 0;
    for (; i != taille_reste_mot; i++) {
        lettre_a_donner[i] = rail_cote_joueur[TAILLE_RAIL - 1 - i];
    }
    lettre_a_donner[i] = '\0';

    int j = 0;
    for (; j != TAILLE_RAIL - taille_nouveau_mot; j++) {
        stock[j] = rail_cote_joueur[j + taille_extremite];
    }
    stock[j] = '\0';

    i = 0;
    for (; nouveau_mot[i] != '\0'; i++) {
        rail_cote_joueur[i] = nouveau_mot[i];
    }
    j = 0;
    for (j = 0; stock[j] != '\0'; j++) {
        rail_cote_joueur[i + j] = stock[j];
    }
    rail_cote_joueur[i + j] = '\0';
    for (int k = 0; k < TAILLE_RAIL; k++) {
        rail_cote_adversaire[k] = rail_cote_joueur[TAILLE_RAIL - 1 - k];
    }
}
