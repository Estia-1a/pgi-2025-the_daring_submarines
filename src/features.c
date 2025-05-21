#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"


/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension(char *chemin) {
    unsigned char *donnees;
    int largeur;
    int hauteur;
    int nb_canaux;
    
    read_image_data(chemin, &donnees, &largeur, &hauteur, &nb_canaux);
    
    printf("dimension: %d, %d\n", largeur, hauteur);
    
    free(donnees);
}