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
void first_pixel()
{
    int read_image_data(const char *filename, unsigned char **data, int *width, int *height, int *channel_count);
    if (strncmp(read_image_data, "first_pixel", 11) == 0)
    { /* first_pixel() function is defined in feature.h and implemented in feature.c */

        printf("first_pixel :");
        first_pixel();
    }
}

/* feature 3 tenth_pixel */

void tenth_pixel(char *source_path)
{
}

/* feature 4 second_line */

second_line(char *source_path);
{
}

/* feature 5 print_pixel */

void print_pixel( char *filename, int x, int y );
{
}