![42-lyon](https://user-images.githubusercontent.com/45235527/106354618-6ec65a00-62f3-11eb-8688-ba9e0f4e77de.jpg)

# cub3d

<img alt="Note" src="https://user-images.githubusercontent.com/45235527/104627073-dc894980-5696-11eb-999d-e53798ea9ae4.png" width="250" height="200" />

<strong>Description</strong>

Ce projet est inspiré du jeu éponyme mondialement connu, considéré comme le premier FPS jamais développé. Il vous permettra d'explorer la technique du ray-casting. Votre objectif est de faire une vue dynamique au sein d'un labyrinthe, dans lequel vous devrez trouver votre chemin.

> *Project en collaboration avec <a href="https://github.com/nemu69">Nemuel Page Léonie</a> (<a href="https://profile.intra.42.fr/users/nepage-l">nepage-l</a>).*

![Cub3D game](https://user-images.githubusercontent.com/45235527/104591011-67088380-566c-11eb-8374-ba15225da9f5.gif)

# Partie Obligatoire - Cub3D

![sujet](https://user-images.githubusercontent.com/45235527/97051624-c419ff00-157f-11eb-9e39-bf54a70006c7.PNG)

Les contraintes sont les suivantes :
- Vous devez utiliser la minilibX. Soit dans la version disponible sur votre OS, ou
depuis ses sources. Si vous décidez de travailler avec les sources, les mêmes règles
que la libft s’appliquent.
- La gestion des fenêtres doit être parfaite : gestion de la minimalisation, du passage
d’une autre fenetre, etc
- Vous devez afficher des textures différentes (vous avez le choix) selon si les murs
sont face nord, sud, est, ouest.
- Votre programme doit être capable d’afficher un objet (sprite) au lieu d’un mur.
- Votre programme doit être capable d’avoir des couleurs différentes pour le sol et
le plafond
- En prévision du jour où deepthought aura des yeux pour évaluer votre projet,
votre programme doit pouvoir sauver la première image rendue au format bmp
lorsque le second argument est "–save".
- Si il n’y a pas de second argument, le programme affiche l’image dans une fenêtre,
tout en respectant les règles suivantes :
  - Les touches flèches du gauche et droite du clavier doivent permettre de faire
une rotation de la caméra (regarder a gauche et a droite)
  - Les touches W, A, S et D doivent permettre de déplacer la caméra (déplacement
du personnage)
  - Appuyer sur la touche ESC doit fermer la fenêtre et quitter le programme
proprement
  - Cliquer sur la croix rouge de la fenêtre doit fermer la fenêtre et quitter le
programme proprement
  - Si la taille de fenêtre demandée dans la map est plus grande que celle de l’écran,
la taille de fenêtre doit être celle de l’écran.
  - L’utilisation d’images de la minilibX est fortement recommandée.
- Votre programme doit prendre en premier argument un fichier de description de
scène avec pour extension .cub
  - La map doit être composée d’uniquement ces 4 caractères : <strong>0</strong> pour les espaces
vides, <strong>1</strong> pour les murs, <strong>2</strong> pour un objet, <strong>N</strong>,<strong>S</strong>,<strong>E</strong> ou <strong>W</strong> qui représentent la
position de départ du joueur et son orientation.
Cette simple map doit être valide :
  ```
  111111
  100101
  102001
  1100N1
  111111
  ```
  - La map doit être fermée/entourée de murs, sinon le programme doit renvoyer
une erreur.
  - Mis à part la description de la map, chaque type d’élément peut être séparée
par une ou plusieurs lignes vides.
  - La description de la carte sera toujours en dernier dans le fichier, le reste des
éléments peut être dans n’importe quel ordre.
  - Les informations de chaque élément peuvent être séparées par un ou plusieurs
espace(s).
  - Pour chaque élement, le premier caractère est l’identifiant (un ou deux caractères), suivi de toutes les informations spécifiques à l’élément dans un ordre
strict tel que :
    - Resolution :
        ```
        R 1920 1080
        ```
      - identifiant : <strong>R</strong>
      - taille de rendu axe x
      - taille de rendu axe y
    - texture nord :
      ```
      NO ./path_to_the_north_texture
      ```
      - identifiant : <strong>NO</strong>
      - chemin vers la texture nord
    - South texture :
      ```
      SO ./path_to_the_south_texture
      ```
      - identifiant : <strong>SO</strong>
      - chemin vers la texture sud
    - West texture :
      ```
      WE ./path_to_the_west_texture
      ```
      - identifiant : <strong>WE</strong>
      - chemin vers la texture ouest
    - East texture :
      ```
      EA ./path_to_the_east_texture
      ```
      - identifiant : <strong>EA</strong>
      - chemin vers la texture est
    - Sprite texture :
      ```
      S ./path_to_the_sprite_texture
      ```
      - identifiant : <strong>S</strong>
      - chemin vers la texture sprite
    - Couleur du sol :
      ```
      F 220,100,0
      ```
      - identifiant : <strong>F</strong>
      - couleurs R,G,B range [0,255] : <strong>0, 255, 255</strong>
    - Couleur du plafond :
      ```
      C 225,30,0
      ```
      - identifiant : <strong>C</strong>
      - couleurs R,G,B range [0,255] : <strong>0, 255, 255</strong>
  - Exemple minimaliste de scène de la partie obligatoire <strong>.cub</strong> :
  ```
  R 1920 1080
  NO ./path_to_the_north_texture
  SO ./path_to_the_south_texture
  WE ./path_to_the_west_texture
  EA ./path_to_the_east_texture
  S ./path_to_the_sprite_texture
  F 220,100,0
  C 225,30,0
  1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
  1 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
  1 0 1 1 0 0 0 0 0 1 1 1 0 0 0 0 0 0 2 0 0 0 0 0 1 0 0 0 1
  1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1
  1 0 1 1 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1
  1 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 1 1 1 0 1 1 1 1 0 0 0 1
  1 1 1 1 0 1 1 1 1 1 1 1 1 1 0 1 1 1 0 0 0 0 0 0 1 0 0 0 1
  1 1 1 1 0 1 1 1 1 1 1 1 1 1 0 1 1 1 0 1 0 1 0 0 1 0 0 0 1
  1 1 0 0 0 0 0 0 1 1 0 1 0 1 0 1 1 1 0 0 0 0 0 0 1 0 0 0 1
  1 0 0 0 2 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 1
  1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 1 0 1 0 0 1 0 0 0 1
  1 1 0 0 0 0 0 0 1 1 0 1 0 1 0 1 1 1 1 1 0 1 1 1 1 0 N 0 1
  1 1 1 1 0 1 1 1 1 1 1 1 0 1 0 1 1 1 1 1 0 1 1 1 1 0 0 0 1
  1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
  ```
  - Si un problème de configuration de n’importe quel type est rencontré dans
le fichier, le programme doit quitter et renvoyer "Error\n" suivi d’un message
d’erreur explicite de votre choix.


# Bonus part

Liste des bonus :
- Collision contre les murs
- Un HUD.
- Une barre de vie.
- Plus d’objets dans le labyrinthe.
- Gain ou perte de points/de vie en prenant des objets/pièges.
- Portes secrètes.
- Son et musique.


# Resultat

<img width="1612" alt="map3.cub" src="https://user-images.githubusercontent.com/45235527/104811439-ba5d0c00-57fb-11eb-86ce-305d1f7c65a0.png">

<img width="1612" alt="map.cub" src="https://user-images.githubusercontent.com/45235527/104811336-f2b01a80-57fa-11eb-9866-985ac5ca8f3a.png">

