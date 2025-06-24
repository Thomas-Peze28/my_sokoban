![Logo](https://upload.wikimedia.org/wikipedia/commons/f/fe/Epitech_Official_Logo.png)

# My Sokoban

## Description

**My Sokoban** est une ré-implémentation du célèbre jeu Sokoban en C, jouable en mode texte (ncurses) ou en mode graphique (CSFML).  
Le but du jeu est de pousser toutes les caisses (`X`) sur les emplacements de stockage (`O`) en un minimum de coups et de temps.

## Fonctionnalités

- Mode terminal (ncurses) et mode graphique (CSFML)
- Génération de cartes aléatoires avec `-r`
- Sons (déplacement, collision, victoire)
- Chronomètre et compteur de mouvements
- Affichage du nombre de déplacements
- Prise en charge des grandes cartes (adaptation de la taille des cellules)
- Gestion des collisions et des règles classiques du Sokoban

## Compilation

```sh
make
```

Le binaire sera généré sous le nom `my_sokoban`.

## Dépendances

- [ncurses](https://invisible-island.net/ncurses/)
- [CSFML](https://www.sfml-dev.org/download/csfml/)

## Utilisation

```sh
./my_sokoban <map_file> [options]
```

### Options

- `-h` : Affiche l’aide et quitte.
- `-csfml` : Lance le jeu en mode graphique CSFML.
- `-r` : Génère une carte aléatoire.

### Exemples

- Jouer une carte en mode ncurses :
  ```sh
  ./my_sokoban map.txt
  ```
- Jouer une carte en mode CSFML :
  ```sh
  ./my_sokoban map.txt -csfml
  ```
- Générer une carte aléatoire en mode CSFML :
  ```sh
  ./my_sokoban -r -csfml
  ```

## Commandes en jeu

- **Flèches directionnelles** : déplacer le joueur
- **Espace** : réinitialiser la carte
- **q** : quitter la partie

## Structure d’une carte

- `#` : Mur
- `P` : Joueur
- `X` : Caisse
- `O` : Emplacement de stockage
- ` ` : Sol

Exemple :
```
############
#      X O #
#   P   ####
#          #
#######    #
#    ##    #
#    ##    #
#    X     #
#          #
# O     #  #
############
```

## Capture d'écran

![Screenshot from 2025-06-24 15-08-34](https://github.com/user-attachments/assets/e4194157-bd5e-45da-bb55-31d0e8bc7c89)

![Screenshot from 2025-06-24 15-07-47](https://github.com/user-attachments/assets/72d845f0-33be-4807-96dd-08023157e757)

## Auteurs

- [@Thomas-Peze](https://github.com/Thomas-Peze28)

---
