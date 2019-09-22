<h1 align="center">Fdf</h1>

Le projet Fdf pour 'fils de fer' est un projet d'introduction aux possibilités d'une librairie graphique (gestion d'une fenêtre, dessin...). L'objectif ici est de créer une présentation d'un terrain en 3D en maillage fils de fer.

## Installation

```sh
https://github.com/brpinto/fdf.git
make fdf
```

## Usage

Les cartes (.fdf) sont à aller chercher dans le répertoire maps.
  
```sh
./fdf [map]
```
## Makefile

```sh
make clean
```
Supprime les dossiers obj contenant les fichiers .o nécessaires à la compilation

```sh
make fclean
```
Supprime le dossier obj ainsi que l'executable du projet

```sh
make re
```
Exécute les règles clean et fclean et recompile le projet (make)

## Controles

ESC : Fermer la fenêtre <br />
Z: Déplacer le maillage vers le haut <br />
Q: Déplacer le maillage vers la gauche <br />
S: Déplacer le maillage vers le bas <br />
D: Déplacer le maillage vers la Droite <br />
R: Réinitialiser le maillage <br />
A: Réduire le maillage <br />
E: Agrandir le maillage <br />
Flêches (haut / bas / gauche droite) : rotation sur l'axe X (haut / bas) ou Y (gauche / droite) <br />
I: Vue isométrique <br />
C: Changer la couleur
