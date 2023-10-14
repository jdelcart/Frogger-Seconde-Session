//
//  objets.h
//  Frogger
//
//  Created by Julien Delcarte on 19/09/2023.
//

#ifndef objets_h
#define objets_h

#include <stdio.h>
#include <GLUT/GLUT.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct objet        //Pour la place occupée par un objet, ainsi que son espace d'affichage.
{
    GLfloat xpos;
    GLfloat ypos;
    GLfloat hauteur;
    GLfloat largeur;
} Objet;

typedef struct quadrillage  //Le quadrillage permet de calculer plus aisément les collisions. Cocher "occupé" pour un obstacle fixe.
{
    Objet extension;
    bool libre;
    bool eau;
} Case;

typedef struct obstacle     //Pour distinguer un obstacle d'une case libre facilement.
{
    Case * position;
} Obstacle;

typedef struct arrivee      //Pour distinguer une case d'arrivée d'une case libre facilement.
{
    Case * position;
} Arrivee;
 
typedef struct mobile{      //Base pour l'ensemble des éléments suivants: plate-formes, voitures, avatar.
    Case * position;
    GLfloat vitesse;
} Mobile;

typedef struct plateforme{  //Permet essentiellement de différencier la plateforme de la rivière pour éviter la noyade. A mobiliser avec les impacts.
    Mobile profil;
} Plateforme;

typedef struct agent {      //Pour les entités destructibles
    Mobile profil;
    int vie;
} Agent;

typedef struct vehicule {
    Agent profil;
    bool acceleration;      //Provisoire, pour gérer plus tard l'accélération des véhicules.
    int fact_acc;
    int munition;           //Provisoire, pour gérer plus tard les tirs.
} Vehicule;

typedef struct avatar {
    Agent profil;
    int essais_restants;
} Joueur;


#endif /* objets_h */
