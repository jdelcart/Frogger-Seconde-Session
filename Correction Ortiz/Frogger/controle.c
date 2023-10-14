//
//  controle.c
//  Frogger
//
//  Created by Julien Delcarte on 18/09/2023.
//

#include "controle.h"

#include <stdio.h>
#include <stdlib.h>
#include <GLUT/GLUT.h>

extern GLfloat xpos;    //Voir joueur.c. Remarque: ici, pour l'avatar. Devra changer quand les objets seront implémentés.
extern GLfloat ypos;

extern GLfloat x_suivante;
extern GLfloat y_suivante;

extern Joueur avatar;

#define ESCAPE 27

void keyboard (unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'z':
            if (ypos < 0.8)
            {
                printf("Pression!\n");
                y_suivante = ypos + 0.2;    //Attention: au sein de la fenêtre, les coordonées suivent le standard cartésien
                x_suivante = xpos;
                printf("Déplacement vers le haut...\n");
                if (verification_colision())
                {
                    ypos = y_suivante;
                    avatar.profil.profil.position->extension.ypos = ypos;
                    glutPostRedisplay();
                    printf("Déplacement confirmé!\n");
                }
            }
            break;
        case 's':
            if (ypos >-0.8)
            {
                printf("Pression!\n");
                y_suivante = ypos - 0.2;
                x_suivante = xpos;
                printf("Déplacement vers le bas...\n");
                if(verification_colision()){
                    ypos = y_suivante;
                    avatar.profil.profil.position->extension.ypos = ypos;
                    glutPostRedisplay();
                    printf("Déplacement confirmé!\n");
                }
            }
            break;
        case 'q':
            if (xpos >-0.8)
            {
                printf("Pression!\n");
                y_suivante = ypos;
                x_suivante = xpos - 0.2;
                printf("Déplacement vers la gauche...\n");
                if(verification_colision()){
                    xpos = x_suivante;
                    avatar.profil.profil.position->extension.xpos = xpos;
                    glutPostRedisplay();
                    printf("Déplacement confirmé!\n");
                }
            }
            break;
        case 'd':
            if (xpos < 0.8)
            {
                printf("Pression!\n");
                y_suivante = ypos;
                x_suivante = xpos + 0.2;
                printf("Déplacement vers la droite...\n");
                if(verification_colision()){
                    xpos = x_suivante;
                    avatar.profil.profil.position->extension.xpos = xpos;
                    glutPostRedisplay();
                    printf("Déplacement confirmé!\n");
                }
            }
            break;
    }
    if (key == ESCAPE){
        exit (0);
    }
}
