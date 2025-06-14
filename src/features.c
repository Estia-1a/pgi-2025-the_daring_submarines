#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld()
{
    printf("Hello World !");
}

/* feature 1 dimension */
void dimension(char *chemin)
{
    unsigned char *donnees;
    int largeur;
    int hauteur;
    int nb_canaux;

    read_image_data(chemin, &donnees, &largeur, &hauteur, &nb_canaux);

    printf("dimension: %d, %d\n", largeur, hauteur);
}

/* feature 2 fisrt_pixel */
void first_pixel(char *source_path)
{

    unsigned char *donnees;
    int largeur;
    int hauteur;
    int nb_canaux;

    read_image_data(source_path, &donnees, &largeur, &hauteur, &nb_canaux);
    
    unsigned char R = donnees[0];
    unsigned char G = donnees[1];
    unsigned char B = donnees[2];

    printf("first_pixel: %d, %d, %d\n", R, G, B);
}

/*feature 3 tenth_pixel */ 
void tenth_pixel(char *source_path)
{
    unsigned char *donnees;
    int largeur;
    int hauteur;
    int nb_canaux;

    read_image_data(source_path, &donnees, &largeur, &hauteur, &nb_canaux);
    
    unsigned char R = donnees[27];
    unsigned char G = donnees[28];
    unsigned char B = donnees[29];

    printf("tenth_pixel: %d, %d, %d\n", R, G, B);
}

/*feature 4 second_line*/
void second_line(char *source_path)
{
    unsigned char *donnees;
    int largeur;
    int hauteur;
    int nb_canaux;

    read_image_data(source_path, &donnees, &largeur, &hauteur, &nb_canaux);
    
    unsigned char R = donnees[(largeur*nb_canaux)];
    unsigned char G = donnees[(largeur*nb_canaux)+1];
    unsigned char B = donnees[(largeur*nb_canaux)+2];

    printf("second_line: %d, %d, %d\n", R, G, B);
}

/*feature 5 print_pixel*/
void print_pixel(char *source_path, int x, int y) 
{
    unsigned char *donnees;
    int largeur;
    int hauteur;
    int nb_canaux;

    read_image_data(source_path, &donnees, &largeur, &hauteur, &nb_canaux);

    pixelRGB *pixel = get_pixel(donnees, largeur, hauteur, nb_canaux, x, y);

    if (pixel == NULL) {
        printf("Erreur : coordonnées (%d, %d) hors limites\n", x, y);
    } else {
        printf("Print Pixel (%d,%d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);
        free(pixel);
    }
}

/*feature 6 max_pixel*/
void max_pixel(char *source_path) 
{
    unsigned char *donnees;
    int largeur, hauteur, nb_canaux;
    read_image_data(source_path, &donnees, &largeur, &hauteur, &nb_canaux);

    int max_somme = -1;
    int max_x = 0;
    int max_y = 0;
    pixelRGB *max_pixel = NULL;

    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            pixelRGB *pixel = get_pixel(donnees, largeur, hauteur, nb_canaux, x, y);
            if (pixel == NULL) continue;

            int somme = pixel->R + pixel->G + pixel->B;
            if (somme > max_somme) {
                max_somme = somme;
                max_x = x;
                max_y = y;

                if (max_pixel == NULL) {
                    max_pixel = malloc(sizeof(pixelRGB));
                }
                *max_pixel = *pixel; 
            }

            free(pixel);
        }
    }

    if (max_pixel != NULL) {
        printf("max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, max_pixel->R, max_pixel->G, max_pixel->B);
        free(max_pixel);
    }
}
