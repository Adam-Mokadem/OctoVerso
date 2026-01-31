#pragma once
#ifndef VERIF_H

#define VERIF_H

/**
* @brief Vérifie si le mot qu'entre le joueur n'est composé que de lettres majuscule et aussi si il a 4 lettre au tour 0.
*
* @param[in] mot Le mot que le joueur a entré.
* @return 1 si le mot du joueur n'est composé que de lettres majusucule sinon 0.
*/
int est_valide(const char mot[], int tour_compteur);


/**
* @brief Vérifie si le mot qu'entre le joueur est dans le dictionnaire.
*
* @param[in] mot Le mot que le joueur a entré.
* @return 1 si le mot est dans le dictionnaire sinon 0.
* @pre le fichier "dictionnaire" doit être dans le même fichier que le fichier.c .
*/
int existe_dans_dictionnaire(const char* mot);

/**
* @brief Vérifie si le mot qu'entre le joueur est faisable avec les lettres de sa main.
*
* @param[in] mot Le mot que le joueur a entré.
* @param[in] main Les lettres que le joueur a en sa disposition.
* @param[in] tour_compteur Le compteur de tour permetant de se situer si on est au tour 0 ou dans la partie.
* @return 1 si le mot est faisable sinon 0.
*/
int mot_faisable(const char mot[], const char main[], int tour_compteur);


/**
* @brief Vérifie si il reste des lettres dans la main du joueur
*
* @param[in] main La main du joueur auquel ont veut faire la vérification.
* @return 1 si il ne reste plus de lettres sinon 0.
*/
int fin_de_jeu(char main[]);

#endif // VERIF_H