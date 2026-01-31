#pragma once
#ifndef MAINS_H

#define MAINS_H

/**
* @brief Trie la main du joueur concerné .
*
* @param[out] main La main du joueur auquel ont veut faire le tri.
*/
void tri_main(char main[]);


/**
* @brief Distribue 12 lettres (chevalets) aux 2 joueurs.
*
* @param[out] main1 La main du joueur1.
* @param[out] main2 La main du joueur2.
*/
void distribuer_chevalets(char main1[], char main2[]);


/**
* @brief Supprime unitairement les lettres que le joueur a utilisé de sa main. 
*
* @param[in] lettres_utilisees Les lettres que le joueur a utilisées de sa main dans le mot.
* @param[out] main La main de laquelle on supprime les lettres utilisées.
*/
void supprimer_lettres_utilisees(const char lettres_utilisees[], char main[]);


/**
* @brief Affiche la main des 2 joueurs.
*
* @param[in] main1 La main du joueur1.
* @param[in] main2 La main du joueur2.
*/
void afficher_main(char main1[], char main2[]);


/**
* @brief Echange la lettre choisi par le joueur par une lettre differente de la pioche.
*
* @param[in] lettre_de_main La lettre que le joueur veut echanger.
* @param[out] main_joueur Les lettres que possède le joueurs dans sa main .
*/
int echange(char* lettre_de_main, char* main_joueur);


/**
* @brief Donne au joueur adverse les lettres qui sortent du rail.
*
* @param[out] main_adversaire Les lettres que possède l'adversaire dans sa main.
* @param[in] lettre_a_donner Lettres qui sortent du rail et qui vont dans la main de l'adversaire.
*/
void lettres_sortantes_vers_adversaire(char* main_adversaire, char* lettre_a_donner);

#endif // MAINS_H
       