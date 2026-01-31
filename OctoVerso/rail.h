#pragma once
#ifndef RAIL_H

#define RAIL_H

/**
* @brief Créer les rails (recto et verso) avec le premier mot des 2 joueurs .
*
* @param[in] mot1 Le premier mot du joueur1 .
* @param[in] mot2 Le premier mot du joueur2 .
* @param[out] rail_recto Le coté recto du rail .
* @param[out] rail_verso Le coté verso du rail .
* @pre <code>mot1</code> et <code>mot2</code> doivent faire 4 lettres .
*/
void creer_rails(const char mot1[], const char mot2[], char rail_recto[], char rail_verso[]);


/**
* @brief Décompose l'entrée du joueur en 2 parties quand le mot est construit pour rentrer dans le rail par sa droite (du mot) .
*
* @param[in] tmp L'entrée du joueur contenant les parenthèses .
* @param[out] extremite La partie du mot censé deja être sur le rail .
* @param[out] reste_du_mot La partie du mot fait avec les lettres du joueur .
* @return 1 si le mot est bien construit sinon 0 .
* @pre <code>tmp</code> doit être inférieur ou égal à 10 et supérieur ou égal à 5 .
*/
int entree_mot_droite(char* tmp, char* extremite, char* reste_mot);


/**
* @brief Décompose l'entrée du joueur en 2 parties quand le mot est construit pour rentrer dans le rail par sa gauche (du mot) .
*
* @param[in] tmp L'entrée du joueur contenant les parenthèses .
* @param[out] reste_du_mot La partie du mot fait avec les lettres du joueur .
* @param[out] extremite La partie du mot censé deja être sur le rail .
* @return 1 si le mot est bien construit sinon 0 .
* @pre <code>tmp</code> doit être inférieur ou égal à 10 et supérieur ou égal à 5 .
*/
int entree_mot_gauche(char* tmp, char* reste_mot, char* extremite);


/**
* @brief Vérifie si la partie "extremite" de l'entrée du joueur est compatible avec le rail .
*
* @param[in] situation La situation du tour, si le mot est à insérer à droite du rail(situation 1) ou à gauche (situation 2) .
* @param[in] taille_extremite La taille de la partie du mot censé deja être sur le rail.
* @param[in] rail Le rail utilisé (recto ou verso).
* @param[in] extremite La partie du mot censé deja être sur le rail .
* @param[out] compteur Le compteur qui compte le nombre de fois où la lettre du rail correspond à celle de l'extremite.
* @return Le compteur de correspondance.
*/
int verif_rail(int situation, int taille_extremite, char* rail, char* extremite, int compteur);


/**
* @brief Fais coulisser le rail vers la gauche en insérant le mot du joueur .
*
* @param[in] taille_reste_mot La taille de la partie du mot fait avec les lettres du joueur.
* @param[out] lettre_a_donner Les lettres qui sortent du rail(et qu'il faudra donner à l'adversaire).
* @param[out] rail_cote_joueur Le côté du rail qui est face au joueur, le côté qu'il utilise (recto ou verso).
* @param[out] rail_cote_adversaire Le côté du rail qui est face à l'adversaire, le côté que le joueur n'utilise pas (recto ou verso).
* @param[in] nouveau_mot Le mot créé par le joueur, qui va rentrer sur le rail .
* @param[in] taille_nouveau_mot La taille du mot créé par le joueur.
* @param[out] stock La partie du rail qui va se déplacer mais rester sur le rail.
*/
void decalage_rail_vers_gauche(int taille_reste_mot, char* lettre_a_donner, char* rail_cote_joueur, char* rail_cote_adversaire, char* nouveau_mot, int taille_nouveau_mot, char* stock);


/**
* @brief Fais coulisser le rail vers la droite en insérant le mot du joueur .
*
* @param[in] taille_reste_mot La taille de la partie du mot fait avec les lettres du joueur.
* @param[out] lettre_a_donner Les lettres qui sortent du rail(et qu'il faudra donner à l'adversaire).
* @param[out] rail_cote_joueur Le côté du rail qui est face au joueur, le côté qu'il utilise (recto ou verso).
* @param[out] rail_cote_adversaire Le côté du rail qui est face à l'adversaire, le côté que le joueur n'utilise pas (recto ou verso).
* @param[in] taille_nouveau_mot La taille du mot créé par le joueur.
* @param[out] stock La partie du rail qui va se déplacer mais rester sur le rail.
* @param[in] taille_extemite La taille de la partie du mot censé deja être sur le rail.
* @param[in] nouveau_mot Le mot créé par le joueur, qui va rentrer sur le rail .
*/
void decalage_rail_vers_droite(int taille_reste_mot, char* lettre_a_donner, char* rail_cote_joueur, char* rail_cote_adversaire, int taille_nouveau_mot, char* stock, int taille_extremite, char* nouveau_mot);


#endif // RAIL_H