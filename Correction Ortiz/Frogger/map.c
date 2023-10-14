//
//  map.c
//  Frogger
//
//  Created by Julien Delcarte on 18/09/2023.
//

#include "map.h"

#include <GLUT/glut.h>

extern Case ** quadrillage;

void drawMap(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1, 1, 1);         // Ecran de score blanc
    glRectf(-1.0, 0.8, 1.0, 1.0);  //glRecti(GLint x1, GLint y1, GLint x2, GLint y2)
    
    
    //glColor3ub(139, 69, 19);  // Arrivée brun
    glColor3ub(181, 101, 29);
    glRectf(-1.0, 0.6, 1.0, 0.8);
    
    glColor3ub(100, 50, 25);            // Obstacles
    glRectf(-1.0, 0.6,-0.8, 0.8);
    glRectf(-0.6, 0.6,-0.4, 0.8);
    glRectf(-0.2, 0.6, 0.0, 0.8);
    glRectf( 0.2, 0.6, 0.4, 0.8);
    glRectf( 0.6, 0.6, 0.8, 0.8);
    //ATTENTION: penser à les coder comme contraignants.
    
    glColor3ub( 0, 191, 255);           // Rivière bleue
    glRectf(-1.0, 0.0, 1.0, 0.6);
    
    glColor3f( 0, 0, 0);                // Bande centrale noire
    glRectf(-1.0, -0.2, 1.0, 0.0);
    
    glColor3ub( 128, 128, 128);         // Route Gris moyen (0-255)
    glRectf(-1.0,-0.8, 1.0,-0.2);
    
    glColor3ub( 0, 100, 0);             // Zone de départ
    glRectf(-1.0,-1.0, 1.0,-0.8);
    
    glFlush();
}

void creation_quadrillage(void)
{
    int i,j;                            //Pour les marqueurs de quadrillage.
    
    quadrillage = (Case **)malloc(10 * sizeof(Case *));
    for (i = 0; i < 10; i++) {
        quadrillage[i] = (Case *)malloc(10 * sizeof(Case));
    }
    
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j ++){
            quadrillage[i][j].extension.xpos = (0.9 - 0.2 * j);
            quadrillage[i][j].extension.ypos = (0.9 - 0.2 * i);
            quadrillage[i][j].extension.hauteur = 0.2;
            quadrillage[i][j].extension.largeur = 0.2;
            quadrillage[i][j].eau = 0;
            quadrillage[i][j].libre = 1;
            printf("Case %i initialisée. Prête au remplissage.\n Ses coordonées sont %f d'abscisse et %f d'ordonnée.\n", ((i* 10) + j), quadrillage[i][j].extension.xpos, quadrillage[i][j].extension.ypos);
        }
    }
    
    printf("Préparation des cases blocantes supérieures.\n\n");
    for(i = 0; i < 1; i++){
        for(j = 0 ; j < 10; j++){
            quadrillage[i][j].libre = 0;
            printf("Case %i initialisée comme case blocante.\n", ((i * 10) + j));
        }
    }
    printf("\n");
    
    printf("Préparation des cases blocantes inférieures.\n\n");
    for(i = 9; i < 10; i++){
        for(j = 0 ; j < 10; j++){
            quadrillage[i][j].libre = 0;
            printf("Case %i initialisée comme case blocante.\n", ((i * 10) + j));
        }
    }
    printf("\n");
    
    printf("Préparation des cases blocantes de gauche.\n\n");
    for(i = 0; i < 10; i++){
        for(j = 9 ; j < 10; j++){
            quadrillage[i][j].libre = 0;
            printf("Case %i initialisée comme case blocante.\n", ((i * 10) + j));
        }
    }
    printf("\n");
    
    printf("Préparation des cases blocantes de droite.\n\n");
    for(i = 0; i < 10; i++){
        for(j = 0 ; j < 1; j++){
            quadrillage[i][j].libre = 0;
            printf("Case %i initialisée comme case blocante.\n", ((i * 10) + j));
        }
    }
    printf("\n");
    printf("Affichage de la matrice:\n\n");
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j ++){
            printf("Case %i, position %f en x, %f en y, disponibilité %i.\n", ((i*10)+j), quadrillage[i][j].extension.xpos, quadrillage[i][j].extension.ypos, quadrillage[i][j].libre);
        }
    }
    
    printf("\nInitialisation des cases de bordure terminée\n");
}
