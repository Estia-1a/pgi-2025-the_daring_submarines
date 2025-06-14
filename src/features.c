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
        printf("print_pixel (%d,%d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);
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

/*feature 7 min_pixel*/
void min_pixel(char *source_path) {
    unsigned char *donnees;
    int largeur, hauteur, nb_canaux;
    read_image_data(source_path, &donnees, &largeur, &hauteur, &nb_canaux);

    int min_somme = 256 * 3 + 1; // Max possible + 1
    int min_x = 0;
    int min_y = 0;
    pixelRGB *min_pixel = NULL;

    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            pixelRGB *pixel = get_pixel(donnees, largeur, hauteur, nb_canaux, x, y);
            if (pixel == NULL) continue;

            int somme = pixel->R + pixel->G + pixel->B;
            if (somme < min_somme) {
                min_somme = somme;
                min_x = x;
                min_y = y;

                if (min_pixel == NULL) {
                    min_pixel = malloc(sizeof(pixelRGB));
                }
                *min_pixel = *pixel;
            }

            free(pixel);
        }
    }

    if (min_pixel != NULL) {
        printf("min_pixel (%d, %d): %d, %d, %d\n", min_x, min_y, min_pixel->R, min_pixel->G, min_pixel->B);
        free(min_pixel);
    }
}

/*feature 8 max_component*/
void max_component(char *source_path, char composante)
{
    unsigned char *donnees;
    int largeur, hauteur, nb_canaux;
    read_image_data(source_path,&donnees,&largeur,&hauteur,&nb_canaux);

    int max_val = -1;
    int max_x = 0;
    int max_y = 0;

    for (int y = 0; y < hauteur; y++){
        for (int x = 0; x < largeur; x++){
            pixelRGB *pixel = get_pixel(donnees, largeur, hauteur, nb_canaux, x, y);
            if (pixel == NULL) continue;

            int val;
            if (composante == 'R') val = pixel->R;
            else if (composante == 'G') val = pixel->G;
            else val = pixel->B;

            if (val > max_val){
                max_val = val;
                max_x = x;
                max_y = y;
            } 
            free (pixel);
        }
    }
    printf("max_component %c (%d, %d): %d\n", composante, max_x, max_y, max_val);
}

/*feature 9 min_component*/
void min_component(char *source_path, char composante)
{
    unsigned char *donnees;
    int largeur, hauteur, nb_canaux;
    read_image_data(source_path,&donnees,&largeur,&hauteur,&nb_canaux);

    int min_val = 256;
    int min_x = 0;
    int min_y = 0;

    for (int y = 0; y < hauteur; y++){
        for (int x = 0; x < largeur; x++){
            pixelRGB *pixel = get_pixel(donnees, largeur, hauteur, nb_canaux, x, y);
            if (pixel == NULL) continue;

            int val;
            if (composante == 'R') val = pixel->R;
            else if (composante == 'G') val = pixel->G;
            else val = pixel->B;

            if (val < min_val){
                min_val = val;
                min_x = x;
                min_y = y;
            } 
            free (pixel);
        }
    }
    printf("min_component %c (%d, %d): %d\n", composante, min_x, min_y, min_val);
}

/*feature 10 stat_report*/
void stat_report(char *source_path) {
    unsigned char *donnees;
    int largeur, hauteur, nb_canaux;
    read_image_data(source_path, &donnees, &largeur, &hauteur, &nb_canaux);

    FILE *fichier = fopen("stat_report.txt", "w");
    if (fichier == NULL) {
        printf("Erreur : impossible de créer stat_report.txt\n");
        return;
    }

    /*max_pixel/min_pixel*/
    int max_somme = -1, min_somme = 256*3+1;
    int max_x = 0, max_y = 0, min_x = 0, min_y = 0;
    pixelRGB *pixel = NULL;
    pixelRGB max_pixel, min_pixel;

    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            pixel = get_pixel(donnees, largeur, hauteur, nb_canaux, x, y);
            if (!pixel) continue;

            int somme = pixel->R + pixel->G + pixel->B;

            if (somme > max_somme) {
                max_somme = somme;
                max_x = x;
                max_y = y;
                max_pixel = *pixel;
            }

            if (somme < min_somme) {
                min_somme = somme;
                min_x = x;
                min_y = y;
                min_pixel = *pixel;
            }
            free(pixel);
        }
    }
    fprintf(fichier, "max_pixel (%d, %d): %d, %d, %d\n\n", max_x, max_y, max_pixel.R, max_pixel.G, max_pixel.B);
    fprintf(fichier, "min_pixel (%d, %d): %d, %d, %d\n\n", min_x, min_y, min_pixel.R, min_pixel.G, min_pixel.B);

    /*max_component/min_component*/
    char comps[] = {'R', 'G', 'B'};
    for (int c = 0; c < 3; c++) {
        char comp = comps[c];
        int max_val = -1, min_val = 256;
        int max_cx = 0, max_cy = 0, min_cx = 0, min_cy = 0;

        for (int y = 0; y < hauteur; y++) {
            for (int x = 0; x < largeur; x++) {
                pixel = get_pixel(donnees, largeur, hauteur, nb_canaux, x, y);
                if (!pixel) continue;

                int val = (comp == 'R') ? pixel->R : (comp == 'G') ? pixel->G : pixel->B;

                if (val > max_val) {
                    max_val = val;
                    max_cx = x;
                    max_cy = y;
                }

                if (val < min_val) {
                    min_val = val;
                    min_cx = x;
                    min_cy = y;
                }
                free(pixel);
            }
        }
        fprintf(fichier, "max_component %c (%d, %d): %d\n\n", comp, max_cx, max_cy, max_val);
        fprintf(fichier, "min_component %c (%d, %d): %d\n\n", comp, min_cx, min_cy, min_val);
    }
    fclose(fichier);
}

/*feature 11 color_red*/
void color_red (char *source_path)
{
    unsigned char *donnees;
    int largeur, hauteur, nb_canaux;

    read_image_data(source_path, &donnees, &largeur, &hauteur, &nb_canaux);

    int taille = largeur * hauteur * nb_canaux;
    for (int i = 0; i < taille; i += nb_canaux){
        donnees [i + 1] = 0;
        donnees [i + 2] = 0;
    }
    write_image_data("image_out.bmp", donnees, largeur, hauteur);
}

/*feature 12 color_green*/
void color_green (char *source_path)
{
    unsigned char *donnees;
    int largeur, hauteur, nb_canaux;

    read_image_data(source_path, &donnees, &largeur, &hauteur, &nb_canaux);

    int taille = largeur * hauteur * nb_canaux;
    for (int i = 0; i < taille; i += nb_canaux){
        donnees [i] = 0;
        donnees [i + 2] = 0;
    }
    write_image_data("image_out.bmp", donnees, largeur, hauteur);
}

/*feature 13 color_blue*/
void color_blue (char *source_path)
{
    unsigned char *donnees;
    int largeur, hauteur, nb_canaux;

    read_image_data(source_path, &donnees, &largeur, &hauteur, &nb_canaux);

    int taille = largeur * hauteur * nb_canaux;
    for (int i = 0; i < taille; i += nb_canaux){
        donnees [i + 1] = 0;
        donnees [i] = 0;
    }
    write_image_data("image_out.bmp", donnees, largeur, hauteur);
}

/*feature 14 color_gray*/
void color_gray (char *source_path)
{
    unsigned char *donnees;
    int largeur, hauteur, nb_canaux;

    read_image_data(source_path, &donnees, &largeur, &hauteur, &nb_canaux);

    int taille = largeur * hauteur * nb_canaux;
    for (int i = 0; i < taille; i += nb_canaux){
        unsigned char R = donnees [i];
        unsigned char G = donnees [i + 1];
        unsigned char B = donnees [i + 2];

        unsigned char gris = (R + G + B) / 3;

        donnees [i] = gris;
        donnees [i + 1] = gris;
        donnees [i + 2] = gris;
    }
    write_image_data("image_out.bmp", donnees, largeur, hauteur);
}

/*feature 15 color_invert*/
void color_invert (char *source_path)
{
    unsigned char *donnees;
    int largeur, hauteur, nb_canaux;

    read_image_data(source_path, &donnees, &largeur, &hauteur, &nb_canaux);

    int taille = largeur * hauteur * nb_canaux;
    for (int i = 0; i < taille; i += nb_canaux){
        unsigned char R = donnees [i];
        unsigned char G = donnees [i + 1];
        unsigned char B = donnees [i + 2];

        donnees [i] = 255 - R;
        donnees [i + 1] = 255 - G;
        donnees [i + 2] = 255 - B;
    }
    write_image_data("image_out.bmp", donnees, largeur, hauteur);
}

/*feature 16 color_gray_luminance*/
void color_gray_luminance (char *source_path)
{
    unsigned char *donnees;
    int largeur, hauteur, nb_canaux;

    read_image_data(source_path, &donnees, &largeur, &hauteur, &nb_canaux);

    int taille = largeur * hauteur * nb_canaux;
    for (int i = 0; i < taille; i += nb_canaux){
        unsigned char R = donnees [i];
        unsigned char G = donnees [i + 1];
        unsigned char B = donnees [i + 2];

        unsigned char gris = (R * 0.21 + G * 0.72 + B * 0.07);

        donnees [i] = gris;
        donnees [i + 1] = gris;
        donnees [i + 2] = gris;
    }
    write_image_data("image_out.bmp", donnees, largeur, hauteur);
}

/*feature 17 color_desaturate*/
void color_desaturate(char *source_path) {
    unsigned char *donnees;
    int largeur, hauteur, nb_canaux;

    read_image_data(source_path, &donnees, &largeur, &hauteur, &nb_canaux);

    int taille = largeur * hauteur * nb_canaux;

    for (int i = 0; i < taille; i += nb_canaux) {
        unsigned char R = donnees[i];
        unsigned char G = donnees[i + 1];
        unsigned char B = donnees[i + 2];

        unsigned char min_val = R;
        if (G < min_val) min_val = G;
        if (B < min_val) min_val = B;

        unsigned char max_val = R;
        if (G > max_val) max_val = G;
        if (B > max_val) max_val = B;

        unsigned char new_val = (min_val + max_val) / 2;

        donnees[i]     = new_val; 
        donnees[i + 1] = new_val; 
        donnees[i + 2] = new_val; 
    }
    write_image_data("image_out.bmp", donnees, largeur, hauteur);
}

/*feature 18 rotate_cw*/
void rotate_cw (char *source_path) {
    unsigned char *donnees;
    int largeur, hauteur, nb_canaux;

    read_image_data(source_path, &donnees, &largeur, &hauteur, &nb_canaux);

    int new_largeur = hauteur;
    int new_hauteur = largeur;

    int taille = hauteur * largeur * nb_canaux;
    unsigned char *nouvelle_image = malloc (taille);

    for (int y = 0; y < hauteur; y++){
        for (int x = 0; x < largeur; x++){
            int src_index = (y * largeur + x) * nb_canaux;

            int x_new = hauteur - 1 - y;
            int y_new = x;

            int dest_index = (y_new * new_largeur + x_new) * nb_canaux;

            for (int c = 0; c < nb_canaux; c++){
                nouvelle_image[dest_index + c] = donnees[src_index + c];
            }
        }
    }
    write_image_data("image_out.bmp", nouvelle_image, new_largeur, new_hauteur);
    free(nouvelle_image);
}

/*feature 19 rotate_acw*/
void rotate_acw (char *source_path) {
    unsigned char *donnees;
    int largeur, hauteur, nb_canaux;

    read_image_data(source_path, &donnees, &largeur, &hauteur, &nb_canaux);

    int new_largeur = hauteur;
    int new_hauteur = largeur;

    int taille = hauteur * largeur * nb_canaux;
    unsigned char *nouvelle_image = malloc (taille);

    for (int y = 0; y < hauteur; y++){
        for (int x = 0; x < largeur; x++){
            int src_index = (y * largeur + x) * nb_canaux;

            int x_new = y;
            int y_new = hauteur - 1 - x;

            int dest_index = (y_new * new_largeur + x_new) * nb_canaux;

            for (int c = 0; c < nb_canaux; c++){
                nouvelle_image[dest_index + c] = donnees[src_index + c];
            }
        }
    }
    write_image_data("image_out.bmp", nouvelle_image, new_largeur, new_hauteur);
    free(nouvelle_image);
}

/*feature 20 mirror_horizontal*/
void mirror_horizontal (char *source_path) {
    unsigned char *donnees;
    int largeur, hauteur, nb_canaux;

    read_image_data(source_path, &donnees, &largeur, &hauteur, &nb_canaux);

    int taille = hauteur * largeur * nb_canaux;
    unsigned char *nouvelle_image = malloc (taille);

    for (int y = 0; y < hauteur; y++){
        for (int x = 0; x < largeur; x++){
            int src_index = (y * largeur + x) * nb_canaux;
            int dest_index = (y * largeur + (largeur -1 -x)) * nb_canaux;

            for (int c = 0; c < nb_canaux; c++){
                nouvelle_image[dest_index + c] = donnees[src_index + c];
            }
        }
    }
    write_image_data("image_out.bmp", nouvelle_image, largeur, hauteur);
    free(nouvelle_image);
}