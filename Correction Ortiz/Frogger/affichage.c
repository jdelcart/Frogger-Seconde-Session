//
//  affichage.c
//  Frogger
//
//  Created by Julien Delcarte on 18/09/2023.
//

#include "affichage.h"
#include <stdio.h>
#include <GLUT/GLUT.h>

int screen_width = 800;
int screen_height = 800;

void reshape (int width, int height) //Modifiée vis à vis du modèle
{
    screen_width = width;
    screen_height = height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0,-2.0, 2.0,-1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}
