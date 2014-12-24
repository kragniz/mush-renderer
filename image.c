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

struct samples *image_set_samples(struct image *im, struct samples *s, const int x, const int y) {
    im->samples[y*im->w + x] = *s;
}

void image_to_ppm(const struct image *im, FILE *fp) {
    fprintf(fp, "P6\n%i %i\n", im->w, im->h);

    int x, y;
    for (y=0; y < im->h; y++) {
        for (x=0; x < im->w; x++) {
            struct samples *s = image_get_samples(im, x, y);
            fprintf(fp, "%1.f %1.f %1.f  ", s->color.r, s->color.g, s->color.b);
        }
        fprintf(fp, "\n");
    }
}
