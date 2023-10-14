//
//  main.c
//  Frogger
//
//  Created by Julien Delcarte on 18/09/2023.
//

#include <GLUT/glut.h>

#include "affichage.h"

extern GLfloat xpos;            //Voir joueur.c. Remarque: ici, pour l'avatar. Devra changer quand les objets seront implémentés.
extern GLfloat ypos;

extern Case ** quadrillage;
extern Joueur avatar;

extern int screen_width;        //Voir affichage.c
extern int screen_height;

// Coordonnées initiales du rectangle. A reprendre pour les voitures.
float rectangleX = -0.8;
float rectangleY = -0.7;

// Taille relative du rectangle
float rectangleWidth = 0.4;
float rectangleHeight = 0.2;

// Temps écoulé pour le mouvement
float elapsedTime = 0.0;
float animationDuration = 5.0; // 5 secondes

void display (void)
{
    drawMap(); // Appel de la fonction drawMap de map.c
    
    // Dessine le rectangle rouge animé
    glColor3f(1.0, 0.0, 0.0); // Couleur rouge
    glRectf(rectangleX - (rectangleWidth/2),rectangleY - (rectangleHeight/2), rectangleX + (rectangleWidth/2), rectangleY + (rectangleHeight/2));
        
    //Dessine le point du joueur
    drawPlayer();
    glutSwapBuffers();
    // au lieu de glFlush();
}

void update(int value) {
    // Met à jour la position du rectangle en fonction du temps écoulé
    elapsedTime += 0.01; // Incrément de temps (en secondes)
    if (elapsedTime <= animationDuration) {
        rectangleX = -0.8 + (elapsedTime / animationDuration) * 2.0;
    }
    glutPostRedisplay(); // Demande une redessin de la fenêtre
    glutTimerFunc(10, update, 0); // Appel de la mise à jour après 10 millisecondes
}

 void init (void)  // zoom inutile pour l'instant
{
     //glClearColor(0.0, 0.0, 0.0, 0.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main (int argc, char *argv[])
{
    creation_quadrillage();
    initialisation_joueur();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);  //utiliser la double mise en mémoire tampon pour réduire le scintillement
    glutInitWindowSize(screen_width, screen_height);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("Frogger");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutTimerFunc(10, update, 0); // Démarrer la mise à jour après 10 millisecondes
    glutMainLoop();
    return 0;
}

