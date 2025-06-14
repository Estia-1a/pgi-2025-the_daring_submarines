#include <estia-image.h>
#include <stdlib.h>
#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */


pixelRGB * get_pixel(unsigned char* donnees, const unsigned int largeur, const unsigned int hauteur, const unsigned int nb_canaux, const unsigned int x, const unsigned int y) {
    if (donnees == NULL || x >= largeur || y >= hauteur) {
        return NULL;
    }

    int index = (y * largeur + x) * nb_canaux;

    pixelRGB* pixel = malloc(sizeof(pixelRGB));
    if (pixel == NULL) return NULL;

    pixel->R = donnees[index];
    pixel->G = donnees[index + 1];
    pixel->B = donnees[index + 2];

    return pixel;
}
