#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define TAILLE_MAIN 12  
#define TAILLE_MAIN_MAX 16
#define NOMBRE_LETTRES 88  

// Structure pour représenter un chevalet  
typedef struct {
    char lettre;
    int quantite;
} Chevalet;

// Tableau des lettres et de leurs quantités  
Chevalet chevalets[] = {
    {'A', 9}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 14}, {'F', 1}, {'G', 1}, {'H', 1},
    {'I', 7}, {'J', 1}, {'L', 5}, {'M', 3}, {'N', 6}, {'O', 5}, {'P', 2}, {'Q', 1},
    {'R', 6}, {'S', 7}, {'T', 6}, {'U', 5}, {'V', 2}
};

void tri_main(char main[]) {
    // Trier les lettres dans chaque main  
    for (int i = 0; i < TAILLE_MAIN - 1; i++) {
        for (int j = i + 1; j < TAILLE_MAIN; j++) {
            if (main[j] != ' ' && main[j] != '\0') {
                if (main[i] > main[j]) {
                    char temp = main[i];
                    main[i] = main[j];
                    main[j] = temp;
                }
            }
        }
    }
}

// Fonction pour distribuer les lettres de manière aléatoire  
void distribuer_chevalets(char main1[], char main2[]) {
    char lettres_disponibles[NOMBRE_LETTRES];
    int index = 0;

    // Remplir le tableau avec les lettres en fonction de leur quantité  
    for (int i = 0; i < sizeof(chevalets) / sizeof(chevalets[0]); i++) {
        for (int j = 0; j < chevalets[i].quantite; j++) {
            lettres_disponibles[index++] = chevalets[i].lettre;
        }
    }

    // Mélanger les lettres  
    srand((unsigned int)time(NULL));
    for (int i = 0; i < NOMBRE_LETTRES; i++) {
        int j = rand() % NOMBRE_LETTRES;
        char temp = lettres_disponibles[i];
        lettres_disponibles[i] = lettres_disponibles[j];
        lettres_disponibles[j] = temp;
    }

    for (int i = 0; i < TAILLE_MAIN_MAX; i++) {
        main1[i] = ' ';
        main2[i] = ' ';
    }
    // Distribuer 12 lettres à chaque joueur  
    for (int i = 0; i < TAILLE_MAIN; i++) {
        main1[i] = lettres_disponibles[i];
        main2[i] = lettres_disponibles[i + TAILLE_MAIN];
    }

    tri_main(main1);
    tri_main(main2);

    main1[TAILLE_MAIN_MAX - 1] = '\0';
    main2[TAILLE_MAIN_MAX - 1] = '\0';
}

// Supprimer les lettres utilisées de la main  
void supprimer_lettres_utilisees(const char lettres_utilisees[], char main[]) {
    for (int i = 0; lettres_utilisees[i] != '\0'; i++) {
        for (int j = 0; j < TAILLE_MAIN; j++) {
            if (lettres_utilisees[i] == main[j]) {
                main[j] = ' ';  // Remplacer la lettre par un espace pour indiquer qu'elle est utilisée  
                break;
            }
        }
    }

    // Réorganiser la main pour enlever les espaces  
    int index = 0;
    for (int i = 0; i < TAILLE_MAIN; i++) {
        if (main[i] != ' ') {
            main[index++] = main[i];
        }
    }

    // Compléter le reste de la main par des espaces  
    for (int i = index; i < TAILLE_MAIN; i++) {
        main[i] = ' ';
    }
}


// Fonction pour afficher la main d'un joueur  
void afficher_main(char main1[], char main2[]) {
    printf("1 : ");
    for (int i = 0; main1[i] != '\0' && main1 != ' '; i++) {
        printf("%c", main1[i]);
    }
    printf("\n");
    printf("2 : ");
    for (int i = 0; main2[i] != '\0' && main2[i] != ' '; i++) {
        printf("%c", main2[i]);
    }
    printf("\n");
}

int echange(char* lettre_de_main, char* main_joueur) {
    char lettre_a_echanger = lettre_de_main[0];
    char lettre_echangee = ' ';
    int trouve = 0;
    do {
        if (trouve == 1) {
            for (int i = 0; i < TAILLE_MAIN; i++) {
                if (main_joueur[i] == ' ') {
                    main_joueur[i] = lettre_a_echanger;  // Remettre la lettre à sa place
                    trouve = 0;
                    break;
                }
            }
        }
        
        // Vérifier si la lettre est dans la main
        for (int i = 0; i < TAILLE_MAIN; i++) {
            if (main_joueur[i] == lettre_a_echanger) {
                main_joueur[i] = ' ';  // Marquer la lettre comme utilisée
                trouve = 1;
                break;
            }
        }
        if (!trouve) {
            printf("Erreur : la lettre '%c' n'est pas presente dans votre main.\n", lettre_a_echanger);
            return 0;  // Redemander un mot
        }
        int index = rand() % (sizeof(chevalets) / sizeof(chevalets[0])); // Choisir un index aléatoire
        // Trouver une lettre disponible dans le stock
        while (chevalets[index].quantite <= 0) {
            index = (index + 1) % (sizeof(chevalets) / sizeof(chevalets[0])); // Passer à la lettre suivante
        }
        lettre_echangee = chevalets[index].lettre; // Prendre la lettre disponible
        chevalets[index].quantite--; // Réduire la quantité de cette lettre
    } while (lettre_a_echanger == lettre_echangee);
    

    // Ajouter la lettre échangée à la main
    for (int i = 0; i < TAILLE_MAIN_MAX; i++) {
        if (main_joueur[i] == ' ') { // Trouver un espace pour ajouter la nouvelle lettre
            main_joueur[i] = lettre_echangee;
            break;
        }
    }
    return 1;
}

void lettres_sortantes_vers_adversaire(char* main_adversaire, char* lettre_a_donner) {
    for (int i = 0, j = 0; i < strlen(main_adversaire); i++) {
        if (!isalpha(main_adversaire[i])) {
            main_adversaire[i] = lettre_a_donner[j];
            j++;
        }
    }
}