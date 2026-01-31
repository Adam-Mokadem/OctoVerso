#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define TAILLE_MAIN_MAX 16
#define TAILLE_MAIN 12  
#define TAILLE_PREMIER_MOT 4
#define TAILLE_MAX_MOT 15  // Le mot le plus grand du dictionnaire "ABANDONNASSIONS"  
#define MAX_MOTS_UTILISES 100  // Nombre maximum de mots utilisés


// Fonction pour vérifier si un mot est valide  
int est_valide(const char mot[], int tour_compteur) {
    int longueur_mot = strlen(mot);
    if (tour_compteur == 0 && longueur_mot != TAILLE_PREMIER_MOT) {
        return 0;  // Le mot n'est pas valide si la longueur n'est pas 4  
    }

    // Vérifier que le mot ne contient que des lettres majuscules  
    for (int i = 0; i < longueur_mot; i++) {
        if (!isalpha(mot[i]) || !isupper(mot[i])) {
            return 0;  // Le mot n'est pas valide s'il contient des caractères non alphabétiques ou des minuscules  
        }
    }

    return 1;  // Le mot est valide  
}

// Fonction pour vérifier si un mot existe dans le dictionnaire et le marquer comme utilisé s'il est trouvé  
int existe_dans_dictionnaire(const char* mot) {

    FILE* fichier = fopen("ods4.txt", "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier dictionnaire.\n");
        return 0; // Erreur d'ouverture  
    }

    char mot_dictionnaire[TAILLE_MAX_MOT + 1];  // Pour stocker chaque mot du dictionnaire  
    int trouve = 0; // Variable pour indiquer si le mot a été trouvé

    // Lire chaque mot du dictionnaire  
    while (fscanf_s(fichier, "%15s", mot_dictionnaire, (unsigned int)sizeof(mot_dictionnaire)) == 1) {
        // Si le mot du dictionnaire est identique au mot de l'utilisateur  
        if (strcmp(mot, mot_dictionnaire) == 0) {
            trouve = 1; // Marquer que le mot a été trouvé  
            break; // Sortir de la boucle si le mot est trouvé
        }
    }
    if (trouve == 0) {
        printf("Le mot ne se trouve pas dans le dictionnaire \n");
    }

    fclose(fichier); // Fermer le fichier d'origine 
    
    /*
    // Tableau pour stocker les mots déjà utilisés
    char mots_utilises[MAX_MOTS_UTILISES][TAILLE_MAX_MOT + 1];
    int compteur_mots_utilises = 0;

    // Vérifier si le mot a déjà été utilisé
    for (int i = 0; i < compteur_mots_utilises; i++) {
        if (strcmp(mot, mots_utilises[i]) == 0) {
            printf("Le mot '%s' n'existe pas dans le dictionnaire ou a deja ete utilise.\n", mot);
            return 0; // Le mot a déjà été utilisé
        }
    }

    // Ajouter le mot à la liste des mots utilisés
    if (trouve==1) {
        if (compteur_mots_utilises < MAX_MOTS_UTILISES) {
            strcpy_s(mots_utilises[compteur_mots_utilises], sizeof(mots_utilises[compteur_mots_utilises]), mot);
            compteur_mots_utilises++;
        }
    }
    */

    return trouve; // Retourner 1 si le mot a été trouvé, 0 sinon  
}

// Vérifier si le mot peut être formé avec les lettres de la main  
int mot_faisable(const char mot[], const char main[], int tour_compteur) {
    unsigned int compteur = 0;
    char copie_main[TAILLE_MAIN + 1];
    strncpy_s(copie_main, sizeof(copie_main), main, TAILLE_MAIN);
    copie_main[TAILLE_MAIN] = '\0';  // Assurez-vous que c'est bien une chaîne

    for (int i = 0; mot[i] != '\0'; i++) {
        for (int j = 0; copie_main[j] != '\0'; j++) {
            if (isalpha(mot[i]) && mot[i] == copie_main[j]) {
                compteur++;
                copie_main[j] = ' ';  // Marquer la lettre comme utilisée  
                break;
            }
        }
    }

    if (tour_compteur == 0) {
        return compteur == TAILLE_PREMIER_MOT;
    }
    else {
        return compteur == strlen(mot);
    }
}

int fin_de_jeu(char main[]) {
    for (int i = 0; i < TAILLE_MAIN_MAX; i++) {
        if (isalpha(main[i])) {
            return 0;
        }
    }
    return 1;
}