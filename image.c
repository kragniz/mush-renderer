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

void image_to_ppm(const struct image *image, FILE *fp) {

}
