#include <stdio.h>
#include <stdlib.h>

#include "image.h"

struct image *image_new(const int w, const int h) {
    struct image *image = malloc(sizeof(*image));

    image->w = w;
    image->h = h;
    image->samples = calloc(w*h, sizeof(image->samples));

    return image;
}

struct samples *image_get_samples(const struct image *im, const int x, const int y) {
    return &(im->samples[y*im->w + x]);
}

void image_to_ppm(const struct image *im, FILE *fp) {
    fprintf(fp, "P6\n%i %i\n", im->w, im->h);
}
