//
//  impact.c
//  Frogger
//
//  Created by Julien Delcarte on 19/09/2023.
//

#include "impact.h"

extern Joueur avatar;
extern Case ** quadrillage;

GLfloat x_suivante;
GLfloat y_suivante;

bool verification_colision (void){
    
    int i, j;
    bool champLibre = true;
    bool caseTrouvee = false;
    
    printf("Vérifions la possibilité du déplacement...\n");
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) { 
                if (quadrillage[i][j].extension.xpos == x_suivante && quadrillage[i][j].extension.ypos == y_suivante) {
                    printf("Contrôle de la case visée...\n");
                    printf("Vous cherchez à atteindre la case %i.\n", (i * 10) + j);
                    if(!(quadrillage[i][j].libre)){
                        printf("La case %i est une case blocante!\n", (i*10) + j );
                        champLibre = false; // Set the flag to true if a collision is detected
                        caseTrouvee = true;
                        break;
                    }else{
                        printf("La case %i est une case libre!\n", (i*10) + j );
                        champLibre = true;
                        caseTrouvee = true;
                        break;
                    }
                }else{
                    printf("recherche en cours... Case %i inadéquate.\n", (i*10)+j);
                }
            }
            if(caseTrouvee){
                break;
            }
        }

    return champLibre;
}
