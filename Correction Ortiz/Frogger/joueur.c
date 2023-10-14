//
//  joueur.c
//  Frogger
//
//  Created by Julien Delcarte on 18/09/2023.
//

#include "joueur.h"
#include <GLUT/GLUT.h>
#include <stdio.h>

GLfloat xpos = -0.3;
GLfloat ypos = -0.9;

Joueur avatar;

void drawPlayer(void)
{
    glColor3f( 0.5, 0.5, 0.5); // Set the clear color to white
    
    // Generate and bind a texture
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Set texture parameters and load the image
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, gimp_image.width, gimp_image.height, 0, GL_RGB, GL_UNSIGNED_BYTE, gimp_image.pixel_data);

    glEnable(GL_TEXTURE_2D);

    // Bind the texture to the rectangle vertices
    glBegin(GL_QUADS);
    glTexCoord2f(1.0, 1.0); glVertex2f(xpos - 0.1, ypos - 0.1);
    glTexCoord2f(0.0, 1.0); glVertex2f(xpos + 0.1, ypos - 0.1);
    glTexCoord2f(0.0, 0.0); glVertex2f(xpos + 0.1, ypos + 0.1);
    glTexCoord2f(1.0, 0.0); glVertex2f(xpos - 0.1, ypos + 0.1);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glFlush();
}

void initialisation_joueur(void)
{
    printf("Création du profil du joueur.\n");
    avatar.essais_restants = 3;
    avatar.profil.vie = 2;
    avatar.profil.profil.vitesse = 0.0;                         // A laisser de côté pour le moment
    
    avatar.profil.profil.position = (Case *)malloc(sizeof(Case));
    avatar.profil.profil.position->extension.xpos = xpos;       // Initialisation de la position
    avatar.profil.profil.position->extension.ypos = ypos;
    printf("Profil du joueur créé.\n");
}
