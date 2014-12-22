#ifndef IMAGE_H
#define IMAGE_H

#include "samples.h"

struct image {
    int w;
    int h;
    struct samples *samples;
};

struct image *image_new(const int w, const int h);

struct samples *image_get_samples(const struct image *im, const int x, const int y);

void image_to_ppm(const struct image *im, FILE *fp);

#endif
