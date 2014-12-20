#ifndef IMAGE_H
#define IMAGE_H

#include "samples.h"

struct image {
    int w;
    int h;
    struct samples *samples;
};

struct image *image_new(const int w, const int h);

char *image_to_ppm(const struct image image);

#endif
