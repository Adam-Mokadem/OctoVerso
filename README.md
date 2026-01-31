# Octoverso

## 📌 Présentation

**Octoverso** est un projet développé dans le cadre de la **SAÉ S1.02 (BUT Informatique – Semestre 1)**. Il s’agit d’une application en **langage C** permettant à **deux joueurs** de disputer une partie complète du jeu de lettres **Octo-Verso**, en respectant strictement ses règles.

Le programme gère l’intégralité du déroulement d’une partie : distribution des lettres, validation des coups, gestion du rail rotatif (recto/verso), application des règles spéciales et détection automatique de la fin de partie.

---

## 🎯 Objectifs du projet

* Implémenter les règles complètes du jeu **Octo-Verso**
* Comparer et structurer différentes **approches algorithmiques**
* Produire un code **clair, modulaire et structuré**
* Manipuler des structures de données en C
* Travailler la gestion des entrées/sorties textuelles

---

## 🕹️ Règles du jeu (résumé)

* 2 joueurs
* 88 chevalets de lettres (distribution selon les fréquences officielles)
* Un rail rotatif de **8 lettres** (recto / verso)
* Chaque joueur commence avec **12 lettres**
* Le but est d’être le **premier à se débarrasser de toutes ses lettres**

### Déroulement

* Les joueurs proposent chacun un mot de **4 lettres** pour initialiser le rail
* À chaque tour, un joueur peut :

  * Former un mot en utilisant ses lettres + au moins 2 lettres du rail
  * Échanger une lettre avec la pioche
* Le rail est **rotatif** : les mots peuvent être formés sur le recto ou le verso
* Les lettres expulsées du rail sont récupérées par l’adversaire

### Règles spéciales

* Un mot ne peut être joué **qu’une seule fois** par partie
* Les mots doivent appartenir au **dictionnaire fourni**
* Un mot de **8 lettres** donne droit à une défausse
* Possibilité de **signaler** un mot de 8 lettres non joué par l’adversaire

---

## ⌨️ Utilisation du programme

### Compilation

```bash
gcc -Wall -Wextra -o octoverso src/*.c
```

### Exécution

```bash
./octoverso
```

⚠️ Le fichier du dictionnaire doit être présent dans le **répertoire courant** lors de l’exécution.

---

## 🧾 Format des commandes

### Former un mot

* `R MOT(AI)` → insertion côté **Recto**
* `V (LE)MOT` → insertion côté **Verso**

### Échanger une lettre

* `- A`

### Signaler un mot de 8 lettres

* `r MOT(AI)` ou `v (LE)MOT`

### Aide (optionnel / bonus)

* `H` → affiche les meilleurs coups possibles

---

## 📂 Structure du projet

```
Octoverso/
├── src/
│   ├── main.c
│   ├── jeu.c
│   ├── joueur.c
│   ├── rail.c
│   ├── dictionnaire.c
│   └── *.h
├── dictionnaire.txt
└── README.md
```

---

## ✅ Fonctionnalités implémentées

* Gestion complète des règles du jeu
* Validation stricte des coups
* Affichage recto / verso du rail
* Gestion de la pioche
* Détection automatique de fin de partie

---

## 🚧 Améliorations possibles

* Interface graphique
* Mode joueur contre IA
* Optimisation de la recherche dans le dictionnaire
* Sauvegarde / reprise de partie

---

## 👥 Auteurs

Projet réalisé seul dans le cadre du **BUT Informatique – IUT Paris Cité**.

---

## 📜 Licence

Projet académique – usage pédagogique uniquement.
