#pragma once
#ifndef JEU_H

#define JEU_H

/**
* @brief Fais la saisis et la vérification du mot de début de partie .
* 
* @param[out] mot Le mot entré par le joueur .
* @param[in] main La main pour vérifier si le mot est faisable .
* @param[in] numero_joueur Pour indiquer à quel joueur jouer .
* @param[in] tour_compteur Nécessaire dans les fonction est_valide et mot_faisable .
* @pre <code>tour_compteur</code> doit être à 0 .
*/
void saisir_mot(char mot[], char main[], int numero_joueur, int* tour_compteur);


/**
* @brief Fais la gestion des tours tout au long de la partie (Mise à part le tour 0) .
*
* @param[in] mot1 Le premier mot entré par le joueur1 .
* @param[in] mot2 Le premier mot entré par le joueur2 .
* @param[in, out] tour_compteur Le compteur de tour permetant de se situer avant le changement de tour.
* @return Le numéro du joueur auquel c'est le tour (1 pour Joueur1 et 2 pour Joueur2) .
*/
int tour(const char mot1[], const char mot2[], int tour_compteur);


/**
* @brief Gère la partie lors d'un tour (Mise à part le tour 0) .
*
* @param[in, out] rail_recto Le coté recto du rail .
* @param[in, out] rail_verso Le coté verso du rail .
* @param[in, out] main_joueur La main du joueur auquel c'est le tour.
* @param[in, out] main_adversaire La main du joueur auquel ce n'est pas le tour.
* @param[in] tour_compteur Le compteur de tour permetant de savoir qui joue .
* @pre <code>tour_compteur</code> ne doit pas être à 0 .
*/
void jeu(char rail_recto[], char rail_verso[], char main_joueur[], char main_adversaire[], int tour_compteur);

#endif // JEU_H